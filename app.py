from flask import Flask, jsonify, request
from flask_cors import CORS
import pandas as pd
from sklearn.linear_model import LinearRegression

app = Flask(__name__)
CORS(app)

# Sample financial data for ML training
data = {
    "day": [1, 2, 3, 4, 5, 6, 7, 8, 9, 10],
    "expenses": [100, 150, 120, 180, 200, 170, 220, 210, 250, 240]
}

df = pd.DataFrame(data)

X = df[["day"]]
y = df["expenses"]

# Train the model
model = LinearRegression()
model.fit(X, y)


@app.route("/")
def home():
    return jsonify({
        "project": "DhanaDrishti AI",
        "message": "Backend is running successfully!"
    })


@app.route("/predict", methods=["POST"])
def predict():

    data = request.get_json()

    income = float(data.get("income", 0))
    expenses = float(data.get("expenses", 0))

    balance = income - expenses

    return jsonify({
        "income": income,
        "expenses": expenses,
        "balance": balance,
        "message": "Financial data received successfully"
    })


@app.route("/ml-predict", methods=["POST"])
def ml_predict():

    data = request.get_json()

    days = int(data.get("days", 7))

    if days <= 0 or days > 365:
        return jsonify({"error": "Enter days between 1 and 365"}), 400

    future_days = pd.DataFrame({
        "day": list(range(11, 11 + days))
    })

    predictions = model.predict(future_days)

    results = []

    for day, expense in zip(future_days["day"], predictions):
        results.append({
            "day": int(day),
            "predicted_expense": round(float(expense), 2)
        })

    return jsonify({
        "predictions": results,
        "message": "Machine Learning prediction successful"
    })


if __name__ == "__main__":
    app.run(debug=True)
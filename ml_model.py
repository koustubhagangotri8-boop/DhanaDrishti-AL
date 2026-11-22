import pandas as pd
from sklearn.linear_model import LinearRegression

# Sample financial data
data = {
    "day": [1, 2, 3, 4, 5, 6, 7, 8, 9, 10],
    "expenses": [100, 150, 120, 180, 200, 170, 220, 210, 250, 240]
}

# Create a DataFrame
df = pd.DataFrame(data)

# Input and output
X = df[["day"]]
y = df["expenses"]

# Train the Machine Learning model
model = LinearRegression()
model.fit(X, y)

# Predict expenses for the next 7 days
future_days = pd.DataFrame({
    "day": [11, 12, 13, 14, 15, 16, 17]
})

predictions = model.predict(future_days)

print("===== DHANADRISHTI AI =====")
print("Machine Learning Cash Flow Prediction")
print()

for day, expense in zip(future_days["day"], predictions):
    print(f"Day {day}: Predicted Expense: ₹{expense:.2f}")

print()
print("Machine Learning model trained successfully!")
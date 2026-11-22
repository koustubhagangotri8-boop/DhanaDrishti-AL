DhanaDrishti AI 💰

AI-Powered Financial Management and Cash Flow Prediction System

1. About the Project

DhanaDrishti AI is a financial management prototype designed to help users track income and expenses, monitor their spending habits, manage budgets, and understand their financial position.

It combines a C-based transaction management program with a web dashboard and a Python-based machine learning model for expense prediction.

2. Key Features

- Financial Summary: Displays total income, expenses, and remaining balance.
- Transaction Management: Add, view, edit, and delete transactions.
- Expense Analysis: Categorizes expenses and displays spending breakdowns.
- Smart Expense Detection: Identifies expenses that exceed a user-defined threshold.
- Cash Flow Prediction: Predicts future expenses using a Linear Regression model.
- Financial Insights: Provides basic insights based on recorded income and expenses.
- Budget Management: Helps users monitor their monthly budget.
- Savings Goal Tracker: Tracks savings progress towards a target.

3. Technologies Used

Technology| Purpose
C| Transaction management and file handling
HTML| Web dashboard structure
CSS| Dashboard styling
JavaScript| Dashboard functionality
Python| Backend and machine learning
Flask| Backend API
Pandas| Preparing sample data
Scikit-learn| Linear Regression model
Chart.js| Expense visualization

4. Machine Learning Model

DhanaDrishti AI uses a Linear Regression model from Scikit-learn to predict future expenses.

The model is trained using 10 sample daily expense records and predicts expenses for future days.

Note: This is a prototype demonstration using sample data. Its predictions are not guaranteed to represent actual future spending.

5. How to Run the Project

Requirements

- Python
- GCC compiler
- Visual Studio Code
- Google Chrome or another web browser

Step 1: Install Python Libraries

Open the VS Code terminal and run:

python -m pip install flask flask-cors pandas scikit-learn

Step 2: Run the Python Backend

Run:

python app.py

The backend runs at:

"http://127.0.0.1:5000"

Keep the backend terminal running.

Step 3: Open the Web Dashboard

Open "index.html" in Google Chrome.

The dashboard can be used to manage transactions, view financial summaries, monitor budgets, and test expense predictions.

Step 4: Run the C Program

Compile the C program:

gcc transaction.c -o transaction.exe

Run it in PowerShell:

.\transaction.exe

The C program uses "transactions.txt" for transaction data.

6. Project Structure

DhanaDrishti-AI/
│
├── app.py
├── index.html
├── ml_model.py
├── transaction.c
├── transactions.txt
├── .gitignore
└── README.md

7. Important Notes and Limitations

- The machine learning model currently uses sample expense data.
- The dashboard stores its transactions in browser local storage.
- The C application stores transactions separately in "transactions.txt".
- The C application and web dashboard are currently separate modules and do not synchronize their data.

8. Future Enhancements

- Integrate the C transaction system with the web dashboard.
- Train the prediction model using actual user transaction history.
- Improve prediction accuracy using more financial data.
- Add secure user authentication.
- Provide personalized financial recommendations.

9. Project Name

DhanaDrishti AI – Smarter Financial Management Through Technology

Developed for Arthaton Hackathon 2026.
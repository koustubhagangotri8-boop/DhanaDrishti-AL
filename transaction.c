#include <stdio.h>

struct Transaction
{
    int id;
    char description[50];
    char category[30];
    float amount;
    char type[10];
};

/* Load previously saved transactions */

void loadTransactions(struct Transaction t[], int *n,
                      float *income, float *expense,
                      int *expenseCount)
{
    FILE *fp;

    fp = fopen("transactions.txt", "r");

     if (fp == NULL)
{
    printf("\nERROR: Cannot open transactions.txt\n");
    return;
}


    while (*n < 100 &&
           fscanf(fp, "%d %49s %29s %f %9s",
                  &t[*n].id,
                  t[*n].description,
                  t[*n].category,
                  &t[*n].amount,
                  t[*n].type) == 5)
    {
        if (t[*n].type[0] == 'I' ||
            t[*n].type[0] == 'i')
        {
            *income += t[*n].amount;
        }
        else if (t[*n].type[0] == 'E' ||
                 t[*n].type[0] == 'e')
        {
            *expense += t[*n].amount;
            (*expenseCount)++;
        }

        (*n)++;
    }

    fclose(fp);
}

/* Add a new transaction */

void addTransaction(struct Transaction t[], int *n,
                    float *income, float *expense,
                    int *expenseCount)
{
    FILE *fp;

    if (*n >= 100)
    {
        printf("\nTransaction limit reached!\n");
        return;
    }

    printf("\n===== ADD TRANSACTION =====\n");

    printf("Enter ID: ");
    scanf("%d", &t[*n].id);

    printf("Enter Description: ");
    scanf("%49s", t[*n].description);

    printf("Enter Category: ");
    scanf("%29s", t[*n].category);

    printf("Enter Amount: ");
    scanf("%f", &t[*n].amount);

    if (t[*n].amount < 0)
    {
        printf("Invalid amount!\n");
        return;
    }

    printf("Enter Type (Income/Expense): ");
    scanf("%9s", t[*n].type);

    if (t[*n].type[0] == 'I' ||
        t[*n].type[0] == 'i')
    {
        *income += t[*n].amount;
    }
    else if (t[*n].type[0] == 'E' ||
             t[*n].type[0] == 'e')
    {
        *expense += t[*n].amount;
        (*expenseCount)++;
    }
    else
    {
        printf("Invalid transaction type!\n");
        return;
    }

    fp = fopen("transactions.txt", "a");

    if (fp == NULL)
    {
        printf("Unable to open file!\n");
        return;
    }

    fprintf(fp, "%d %s %s %.2f %s\n",
            t[*n].id,
            t[*n].description,
            t[*n].category,
            t[*n].amount,
            t[*n].type);

    fclose(fp);

    (*n)++;

    printf("\nTransaction added successfully!\n");
}

/* Display all saved transactions */

void viewTransactions()
{
    struct Transaction temp;
    FILE *fp;

    fp = fopen("transactions.txt", "r");

    if (fp == NULL)
    {
        printf("\nNo saved transactions found!\n");
        return;
    }

    printf("\n===== ALL SAVED TRANSACTIONS =====\n");

    while (fscanf(fp, "%d %49s %29s %f %9s",
                  &temp.id,
                  temp.description,
                  temp.category,
                  &temp.amount,
                  temp.type) == 5)
    {
        printf("\nID: %d\n", temp.id);
        printf("Description: %s\n", temp.description);
        printf("Category: %s\n", temp.category);
        printf("Amount: %.2f\n", temp.amount);
        printf("Type: %s\n", temp.type);
    }

    fclose(fp);
}

/* Smart expense detection */

void smartExpenseDetection(struct Transaction t[],
                           int n, float totalExpense,
                           int expenseCount)
{
    int i;
    float averageExpense, threshold;

    printf("\n===== SMART EXPENSE DETECTION =====\n");

    if (expenseCount < 2)
    {
        printf("Not enough expenses for comparison.\n");
        return;
    }

    averageExpense = totalExpense / expenseCount;
    threshold = averageExpense * 1.5;

    printf("Average Expense: %.2f\n", averageExpense);
    printf("Warning Threshold: %.2f\n", threshold);

    for (i = 0; i < n; i++)
    {
        if ((t[i].type[0] == 'E' ||
             t[i].type[0] == 'e') &&
            t[i].amount > threshold)
        {
            printf("\nWARNING: Unusual Expense Detected!\n");
            printf("Description: %s\n", t[i].description);
            printf("Amount: %.2f\n", t[i].amount);
            printf("Please review this transaction.\n");
        }
    }
}

/* Financial summary */

void financialSummary(float income, float expense)
{
    printf("\n===== FINANCIAL SUMMARY =====\n");

    printf("Total Income: %.2f\n", income);
    printf("Total Expenses: %.2f\n", expense);
    printf("Remaining Balance: %.2f\n", income - expense);
}

/* Cash flow prediction */

void cashFlowPrediction(float income, float expense)
{
    int observedDays, forecastDays;

    float balance;
    float dailyCashFlow;
    float predictedCashFlow;

    printf("\n===== CASH FLOW PREDICTION =====\n");

    printf("Enter number of days represented by these transactions: ");
    scanf("%d", &observedDays);

    if (observedDays <= 0)
    {
        printf("Invalid number of days!\n");
        return;
    }

    printf("Enter number of days to predict: ");
    scanf("%d", &forecastDays);

    if (forecastDays <= 0)
    {
        printf("Invalid forecast period!\n");
        return;
    }

    balance = income - expense;

    dailyCashFlow = balance / observedDays;

    predictedCashFlow = dailyCashFlow * forecastDays;

    printf("\nAverage Daily Net Cash Flow: %.2f\n",
           dailyCashFlow);

    printf("Predicted Net Cash Flow for %d days: %.2f\n",
           forecastDays, predictedCashFlow);

    if (predictedCashFlow < 0)
    {
        printf("\nWARNING: Possible negative cash flow!\n");
        printf("Review your business expenses.\n");
    }
    else
    {
        printf("\nYour estimated cash flow is positive.\n");
    }
}

/* Main function */

int main()
{
    struct Transaction t[100];

    int n = 0;
    int choice;
    int expenseCount = 0;

    float totalIncome = 0;
    float totalExpense = 0;

    /* Load saved transactions once */

    loadTransactions(t, &n, &totalIncome,
                     &totalExpense, &expenseCount);

    printf("\n====================================\n");
    printf("          DHANADRISHTI AI\n");
    printf("====================================\n");

    printf("\nSaved Transactions Loaded: %d\n", n);

    do
    {
        printf("\n========== MAIN MENU ==========\n");

        printf("1. Add Transaction\n");
        printf("2. View All Transactions\n");
        printf("3. Smart Expense Detection\n");
        printf("4. Financial Summary\n");
        printf("5. Cash Flow Prediction\n");
        printf("6. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                addTransaction(t, &n, &totalIncome,
                               &totalExpense, &expenseCount);
                break;

            case 2:
                viewTransactions();
                break;

            case 3:
                smartExpenseDetection(t, n,
                                      totalExpense, expenseCount);
                break;

            case 4:
                financialSummary(totalIncome, totalExpense);
                break;

            case 5:
                cashFlowPrediction(totalIncome, totalExpense);
                break;

            case 6:
                printf("\nThank you for using DhanaDrishti AI!\n");
                break;

            default:
                printf("\nInvalid choice! Please try again.\n");
        }

    } while (choice != 6);

    return 0;
}
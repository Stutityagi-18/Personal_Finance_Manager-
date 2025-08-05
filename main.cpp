#include "ExpenseManager.h"

int main()
{
    ExpenseManager manager;
    string filename = "expense_data.txt";

    manager.loadFromFile(filename);

    int choice;
    do
    {
        cout << "\n====== Personal Finance Manager ======\n";
        cout << "1. Add Expense\n";
        cout << "2. Show All Expenses\n";
        cout << "3. Show Total Spent\n";
        cout << "4. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            double amount;
            string category, note;
            cout << "Enter amount: Rs.";
            cin >> amount;
            cin.ignore();
            cout << "Enter category: ";
            getline(cin, category);
            cout << "Enter note: ";
            getline(cin, note);
            manager.addExpense(amount, category, note);
            manager.saveToFile(filename);
            break;
        }
        case 2:
            manager.showAllExpenses();
            break;
        case 3:
            manager.showTotalSpent();
            break;
        case 4:
            cout << "Goodbye!\n";
            break;
        default:
            cout << "Invalid option.\n";
        }
    } while (choice != 4);

    return 0;
}

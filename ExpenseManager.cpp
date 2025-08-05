#include "ExpenseManager.h"

// Get current date in YYYY-MM-DD format
string ExpenseManager::getCurrentDate() {
    time_t now = time(0);
    tm* ltm = localtime(&now);

    char date[11];
    strftime(date, sizeof(date), "%Y-%m-%d", ltm);

    return string(date);
}

// Load expenses from file
void ExpenseManager::loadFromFile(string filename) {
    ifstream inFile(filename);
    if (!inFile) return;

    Expense e;
    while (inFile >> e.date >> e.amount >> ws) {
        getline(inFile, e.category);
        getline(inFile, e.note);
        expenses.push_back(e);
    }

    inFile.close();
}

// Save expenses to file
void ExpenseManager::saveToFile(string filename) {
    ofstream outFile(filename);
    for (const Expense& e : expenses) {
        outFile << e.date << " " << e.amount << "\n";
        outFile << e.category << "\n";
        outFile << e.note << "\n";
    }
    outFile.close();
}

// Add a new expense
void ExpenseManager::addExpense(double amount, string category, string note) {
    Expense e;
    e.amount = amount;
    e.category = category;
    e.note = note;
    e.date = getCurrentDate();
    expenses.push_back(e);
    cout << "✅ Expense added!\n";
}

// Show all expenses
void ExpenseManager::showAllExpenses() const {
    if (expenses.empty()) {
        cout << "No expenses found.\n";
        return;
    }

    cout << "\n--- All Expenses ---\n";
    for (const Expense& e : expenses) {
        e.print();
    }
}

// Show total amount spent
void ExpenseManager::showTotalSpent() const {
    double total = 0;
    for (const Expense& e : expenses) {
        total += e.amount;
    }
    cout << fixed << setprecision(2);
    cout << "\nTotal Spent: ₹" << total << "\n";
}

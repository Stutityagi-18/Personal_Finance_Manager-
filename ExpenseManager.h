#ifndef EXPENSEMANAGER_H
#define EXPENSEMANAGER_H

#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include <ctime>
using namespace std;

// Struct to hold data about a single expense
struct Expense {
    double amount;
    string category;
    string note;
    string date; // Format: YYYY-MM-DD

    // Function to print a single expense entry
    void print() const {
        cout << fixed << setprecision(2);
        cout << "Date: " << date
             << " | Amount: Rs." << amount
             << " | Category: " << category
             << " | Note: " << note << "\n";
    }
};

// ExpenseManager class handles all logic of the app
class ExpenseManager {
private:
    vector<Expense> expenses;

    // Helper function to get the current date in YYYY-MM-DD format
    string getCurrentDate();

public:
    void loadFromFile(string filename);
    void saveToFile(string filename);
    void addExpense(double amount, string category, string note);
    void showAllExpenses() const;
    void showTotalSpent() const;
};

#endif

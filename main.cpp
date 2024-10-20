#include <iostream>
#include <iomanip>
#include <vector>
#include <limits>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Class that simulates the Food Court's ordering and billing system
class FoodCourt {
private:
    // Menu items, their prices, and quantities (initially set to zero for all items)
    vector<string> menuItems = {"Cheeseburger", "Veggie Burger", "Bacon Cheeseburger", "Mushroom Burger", "Bean Burger"};
    vector<float> prices = {8.25, 9.75, 9.25, 8.99, 9.95};
    vector<int> quantities = {0, 0, 0, 0, 0};  // Holds quantities of each menu item ordered

    // Log file to store activity and errors
    string logFileName = "activity_log.txt";
    string billFileName = "bill.txt";  // File to store the bill

    // Function to log activity or errors
    void logActivity(string message) {
        ofstream logFile(logFileName, ios::app);  // Open the log file in append mode
        if (logFile.is_open()) {
            logFile << message << endl;  // Write message to the log file
            logFile.close();  // Close the file after writing
        } else {
            cout << "Error opening log file!" << endl;  // If file can't be opened
        }
    }

public:
    // Function to display the food court menu with item numbers, names, and prices
    void displayMenu() {
        logActivity("Displayed the menu.");  // Log the activity of displaying the menu

        cout << "\n=====================================================" << endl;
        cout << "        Welcome to Ohlone College Food Court";
        cout << "\n=====================================================\n" << endl;
        cout << left << setw(35) << "Address: 43600 Mission Blvd, Fremont, CA 94539" 
             << right << setw(25) << "\nPhone: (510) 659-6000" << endl;
        cout << "\n======================= Menu ========================\n" << endl;

        // Display column headers for menu table
        cout << left << setw(4) << "No" 
             << setw(25) << "Item"     
             << right << setw(24) << "Price" << endl;
        cout << "-----------------------------------------------------" << endl;

        // Loop through the menu items and display them with pricing
        for (int i = 0; i < menuItems.size(); ++i) {
            cout << left << setw(4) << i + 1      // Item number
                 << left << setw(24) << menuItems[i]  // Item name
                 << right << setw(21) << fixed << setprecision(2) << "$" << prices[i] << endl; 
        }
        cout << "-----------------------------------------------------" << endl;
    }

    // Function to get the user's menu choices and their respective quantities
    void getInputs() {
        logActivity("Started taking user input for menu choices.");  // Log when user input starts

        int choice, quantity;
        while (true) {
            // Prompt user for menu choice or 0 to finish
            cout << "\nEnter your choice (1-5) or 0 to finish: ";
            cin >> choice;

            // Input validation: Ensure the choice is within valid range (0-5)
            if (cin.fail() || choice < 0 || choice > 5) {
                cin.clear();  // Clear input error flag
                cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Discard invalid input
                cout << "Invalid choice! Please choose a number between 1 and 5." << endl;
                logActivity("User entered an invalid choice.");  // Log invalid choice
            } 
            else if (choice == 0) {
                break;  // Exit input loop if user selects 0 (finish)
            } 
            else {
                // Prompt user for quantity for the selected item
                cout << "How many " << menuItems[choice - 1] << " do you want? ";
                cin >> quantity;

                // Input validation: Ensure quantity is a non-negative number
                if (cin.fail() || quantity < 0) {
                    cin.clear();  // Clear input error flag
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Discard invalid input
                    cout << "Invalid quantity! Please enter a non-negative number." << endl;
                    logActivity("User entered an invalid quantity.");  // Log invalid quantity
                } 
                else {
                    // Update the quantity of the selected item
                    quantities[choice - 1] += quantity;
                    logActivity("User ordered " + to_string(quantity) + " of " + menuItems[choice - 1] + ".");  // Log order
                }
            }
        }

        logActivity("Finished taking user input for menu choices.");  // Log when input ends
    }

    // Function to calculate the total cost of items ordered (without tax)
    float calculateBill() {
        logActivity("Calculating total bill before tax.");  // Log when bill calculation starts

        float totalCost = 0.0;
        // Sum up the total cost based on quantities and prices
        for (int i = 0; i < menuItems.size(); ++i) {
            totalCost += prices[i] * quantities[i];
        }
        return totalCost;  // Return the total before tax
    }

    // Function to calculate tax based on whether the user is a student or not
    float calculateTax(float totalCost, bool isStudent) {
        logActivity("Calculating tax based on user status.");  // Log tax calculation

        if (isStudent) {
            return 0;  // No tax for students
        } else {
            return totalCost * 0.09;  // Apply 9% tax for non-students
        }
    }

    // Function to print the detailed bill including items, taxes, and optional tips
    void printBill(bool isStudent) {
        logActivity("Printing bill.");  // Log the printing of the bill

        float totalCost = calculateBill();  // Get the total bill before tax
        float tax = calculateTax(totalCost, isStudent);  // Calculate tax based on student status
        float totalCostAfterTax = totalCost + tax;  // Total cost including tax

        // Ask user if they wish to add a tip
        float tip = 0;
        char addTip;
        cout << "\nWould you like to add a tip? (y/n): ";
        cin >> addTip;

        // If the user wants to add a tip, prompt for the tip amount
        if (addTip == 'y' || addTip == 'Y') {
            cout << "Enter the tip amount: $";
            cin >> tip;

            // Input validation: Ensure the tip is non-negative
            if (cin.fail() || tip < 0) {
                cin.clear();  // Clear input error flag
                cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Discard invalid input
                cout << "Invalid tip amount! Setting tip to $0." << endl;
                tip = 0;  // Default to no tip if invalid input is provided
                logActivity("User entered an invalid tip amount.");  // Log invalid tip
            }
        }

        // Calculate final total after tip
        float finalTotal = totalCostAfterTax + tip;

        // Generate a random bill number for this transaction
        srand(time(0));  // Seed random number generator
        int billNumber = rand() % 1001 + 1000;  // Generate a random number between 1000 and 2000

        // Print bill details to the console
        cout << "\n=====================================================" << endl;
        cout << "                         BILL";
        cout << "\n=====================================================\n" << endl;
        cout << "Bill Number: " << billNumber << endl;
        cout << "\nOhlone College Food Court" << endl;
        cout << "Address: 43600 Mission Blvd, Fremont, CA 94539" << endl;
        cout << "Phone: (510) 659-6000" << endl;
        cout << "-----------------------------------------------------" << endl; 

        // Print itemized bill with quantities and individual prices
        cout << left << setw(25) << "Item"
             << left << setw(8) << "Quantity"
             << right << setw(20) << "Price" << endl;
        cout << "-----------------------------------------------------" << endl; 

        // Loop through the ordered items and display them on the bill
        for (int i = 0; i < menuItems.size(); ++i) {
            if (quantities[i] > 0) {
                cout << left << setw(25) << menuItems[i]
                     << left << setw(8) << quantities[i]
                     << right << setw(16) << fixed << setprecision(2) << "$" << prices[i] * quantities[i] << endl;
            }
        }

        // Print totals, tax, and tip
        cout << "-----------------------------------------------------" << endl;
        cout << right << setw(40) << "Subtotal: $" << fixed << setprecision(2) << totalCost << endl;
        cout << right << setw(40) << "Tax: $" << fixed << setprecision(2) << tax << endl;
        cout << right << setw(40) << "Tip: $" << fixed << setprecision(2) << tip << endl;
        cout << right << setw(40) << "Total: $" << fixed << setprecision(2) << finalTotal << endl;
        cout << "\n=====================================================" << endl;

        // Save bill to a file (bill.txt)
        ofstream billFile(billFileName);  // Open bill file
        if (billFile.is_open()) {
            billFile << "Bill Number: " << billNumber << endl;
            billFile << "\nOhlone College Food Court\n";
            billFile << "Address: 43600 Mission Blvd, Fremont, CA 94539\n";
            billFile << "Phone: (510) 659-6000\n";
            billFile << "-----------------------------------------------------\n";
            billFile << left << setw(25) << "Item"
                     << left << setw(8) << "Quantity"
                     << right << setw(20) << "Price" << endl;
            billFile << "-----------------------------------------------------\n";

            // Write ordered items to the bill file
            for (int i = 0; i < menuItems.size(); ++i) {
                if (quantities[i] > 0) {
                    billFile << left << setw(25) << menuItems[i]
                             << left << setw(8) << quantities[i]
                             << right << setw(16) << "$" << fixed << setprecision(2) << prices[i] * quantities[i] << endl;
                }
            }

            // Write totals to the bill file
            billFile << "-----------------------------------------------------\n";
            billFile << right << setw(40) << "Subtotal: $" << fixed << setprecision(2) << totalCost << endl;
            billFile << right << setw(40) << "Tax: $" << fixed << setprecision(2) << tax << endl;
            billFile << right << setw(40) << "Tip: $" << fixed << setprecision(2) << tip << endl;
            billFile << right << setw(40) << "Total: $" << fixed << setprecision(2) << finalTotal << endl;
            billFile << "\n=====================================================\n";
            billFile.close();  // Close bill file
        } else {
            cout << "Error writing to the bill file!" << endl;  // Log error if file can't be written
            logActivity("Error writing to the bill file.");  // Log the error
        }
    }
};

// Main function to control the flow of the program
int main() {
    FoodCourt foodCourt;

    foodCourt.displayMenu();  // Display the menu to the user
    foodCourt.getInputs();   // Get user's menu choices and quantities

    // Ask if the user is a student to determine tax
    char isStudentChar;
    cout << "\nAre you a student? (y/n): ";
    cin >> isStudentChar;
    bool isStudent = (isStudentChar == 'y' || isStudentChar == 'Y');

    // Print the bill and save it to a file
    foodCourt.printBill(isStudent);

    return 0;
}

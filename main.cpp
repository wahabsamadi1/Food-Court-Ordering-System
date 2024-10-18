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

public:
    // Display the food court menu with item numbers, names, and prices
    void displayMenu() {
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
                } 
                else {
                    // Update the quantity of the selected item
                    quantities[choice - 1] += quantity;
                }
            }
        }
    }

    // Calculate the total cost of items ordered (without tax)
    float calculateBill() {
        float totalCost = 0.0;
        // Sum up the total cost based on quantities and prices
        for (int i = 0; i < menuItems.size(); ++i) {
            totalCost += prices[i] * quantities[i];
        }
        return totalCost;  // Return the total before tax
    }

    // Calculate tax based on whether the user is a student or not
    float calculateTax(float totalCost, bool isStudent) {
        if (isStudent) {
            return 0;  // No tax for students
        } else {
            return totalCost * 0.09;  // Apply 9% tax for non-students
        }
    }

    // Print the detailed bill including items, taxes, and optional tips
    void printBill(bool isStudent) {
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
            }
        }

        // Calculate final total after tip
        float finalTotal = totalCostAfterTax + tip;

        // Generate a random bill number for this transaction
        srand(time(0));  // Seed random number generator
        int billNumber = rand() % 1001 + 1000;  // Generate a random number between 1000 and 2000

        // Print bill details
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
                cout << left << setw(25) << menuItems[i]  // Item name
                     << left << setw(8) << quantities[i]  // Quantity ordered
                     << right << setw(15) << fixed << setprecision(2) << "$" << prices[i] * quantities[i] << endl;  // Price for that item
            }
        }

        // Print summary of bill including total, tax, and tip
        cout << "-----------------------------------------------------" << endl; 
        cout << "\nTotal before tax: $" << fixed << setprecision(2) << totalCost << endl;
        cout << "Tax Amount: $" << fixed << setprecision(2) << tax << endl;
        cout << "Total price after tax: $" << fixed << setprecision(2) << totalCostAfterTax << endl;

        // Print tip section if applicable
        if (tip > 0) {
            cout << "Tip Amount: $" << fixed << setprecision(2) << tip << endl;
        }

        cout << "-----------------------------------------------------" << endl; 
        cout << "Total after tip: $" << fixed << setprecision(2) << finalTotal << endl;

        cout << "\nThank you for dining with us!" << endl;
        cout << "Please come again soon!" << endl;

        // Save the bill to a text file for record-keeping
        string fileName = to_string(billNumber) + ".txt";  // Generate filename using the bill number
        ofstream outFile(fileName);  // Open file for writing

        // Write bill details to file
        outFile << "\nOhlone College Food Court" << endl;
        outFile << "Address: 43600 Mission Blvd, Fremont, CA 94539" << endl;
        outFile << "Phone: (510) 659-6000" << endl;
        outFile << "-----------------------------------------------------" << endl;
        outFile << "Bill Number: " << billNumber << endl;
        outFile << "-----------------------------------------------------" << endl;

        // Loop through items again to save details to the file
        for (int i = 0; i < menuItems.size(); ++i) {
            if (quantities[i] > 0) {
                outFile << menuItems[i] << " x" << quantities[i] << " - $" << prices[i] * quantities[i] << endl;
            }
        }

        outFile << "-----------------------------------------------------" << endl;
        outFile << "Total before tax: $" << totalCost << endl;
        outFile << "Tax: $" << tax << endl;
        outFile << "Total after tax: $" << totalCostAfterTax << endl;

        // Save tip details if applicable
        if (tip > 0) {
            outFile << "Tip: $" << tip << endl;
        }

        outFile << "Total after tip: $" << finalTotal << endl;
        outFile.close();  // Close the file
    }
};

int main() {
    FoodCourt foodCourt;  // Create an instance of the FoodCourt class

    foodCourt.displayMenu();  // Display the menu

    bool isStudent;
    char studentChoice;
    cout << "\nAre you a student? (y/n): ";
    cin >> studentChoice;

    // Input validation: Ensure the user input is 'y' or 'n'
    while (studentChoice != 'y' && studentChoice != 'n') {
        cout << "Invalid input. Please enter 'y' or 'n': ";
        cin >> studentChoice;
    }

    isStudent = (studentChoice == 'y');  // Determine if the user is a student

    foodCourt.getInputs();  // Get the user's input for the order
    foodCourt.printBill(isStudent);  // Print the detailed bill

    return 0;
}

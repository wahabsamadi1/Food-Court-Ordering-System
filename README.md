## Food Court Ordering and Billing System

### Overview
This project simulates an ordering and billing system for the Ohlone College Food Court. The program allows users to:
+ View a menu of food items.
+ Select items from the menu, specifying the quantity.
+ Generate a detailed bill, including tax calculations and optional tips.
+ The bill is saved as a text file for record-keeping.
+ A logging system is included to log important events and errors during the program's execution.  

### Features
+ **Menu Display:** The program shows a menu with available food items, including their prices.  
+ **User Input:** Users can select items and specify the quantity of each.
+ **Billing:** The system calculates the total cost before and after tax. If the user is a student, tax is waived.  
+ **Optional Tip:** The user can choose to add a tip to the final bill.  
+ **Bill Storage:** A detailed bill is saved as a text file for reference, including a randomly generated bill number.  
+ **Logging System:** A logging system is added using the log() function to track program events and errors, helping to monitor the system's behavior and troubleshoot issues.  

### Technologies Used
+ C++ Standard Libraries:  
  + iostream for input/output operations.  
  + iomanip for formatting the output (such as prices and bill totals).
  + vector for managing menu items, prices, and quantities.
  + fstream for file handling (saving the bill and logging events).
  + cstdlib and ctime for generating random bill numbers.
  + limits for input validation.  

### Prerequisites
To compile and run this program, you will need:  
+ A C++ compiler (e.g., GCC or Clang)  
+ A terminal or an IDE with C++ support (e.g., Visual Studio Code, Code::Blocks)

### How to Run the Program
1. Clone the Repository:  
   git clone https://github.com/wahabsamadi1/food-court-ordering-system.git  
2. Navigate to the Project Directory:  
   cd food-court-ordering-system  
3. Compile the Program: If you are using g++, run:  
   g++ foodcourt.cpp -o foodcourt  
4. Run the Program:  
   ./foodcourt

### Program Flow
1. Menu Display:
   + The program will display a menu with five items: Cheeseburger, Veggie Burger, Bacon Cheeseburger, Mushroom Burger, and Bean Burger. Prices are shown next to each item.
2. Order Selection:  
   + The user will be prompted to choose a menu item by its number (1-5) and then specify the quantity. The user can make multiple selections.  
   + Input 0 to finish ordering.  
3. Student Status:  
   + The user will be asked whether they are a student. Students are exempt from tax.  
4. Tip:
   + The user can choose whether to add a tip and specify the amount.  
5. Final Bill:  
   + A detailed bill will be displayed, showing the total before and after tax, and including the tip.
   + A copy of the bill is saved as a text file with a randomly generated bill number (e.g., 1502.txt).  
6. Logging System:
   + Program events, such as item selection, tip addition, and errors (like invalid input), are logged using the log() function. The log records are stored in a separate log file (program.log) to help track program behavior and troubleshoot any issues.

### Example Output
    =====================================================
           Welcome to Ohlone College Food Court
    =====================================================

    Address: 43600 Mission Blvd, Fremont, CA 94539   
    Phone: (510) 659-6000

    ======================= Menu ========================

    No  Item                                        Price
    -----------------------------------------------------
    1   Cheeseburger                                $8.25
    2   Veggie Burger                               $9.75
    3   Bacon Cheeseburger                          $9.25
    4   Mushroom Burger                             $8.99
    5   Bean Burger                                 $9.95
    -----------------------------------------------------

    Enter your choice (1-5) or 0 to finish: 1
    How many Cheeseburger do you want? 2

    Enter your choice (1-5) or 0 to finish: 3
    How many Bacon Cheeseburger do you want? 1

    Enter your choice (1-5) or 0 to finish: 4
    How many Mushroom Burger do you want? 1

    Enter your choice (1-5) or 0 to finish: 5
    How many Bean Burger do you want? 2

    Enter your choice (1-5) or 0 to finish: 0

    Are you a student? (y/n): y

    Would you like to add a tip? (y/n): y
    Enter the tip amount: $5

    =====================================================
                            BILL
    =====================================================

    Bill Number: 1659

    Ohlone College Food Court
    Address: 43600 Mission Blvd, Fremont, CA 94539
    Phone: (510) 659-6000
    -----------------------------------------------------
    Item                     Quantity               Price
    -----------------------------------------------------
    Cheeseburger             2                     $16.50
    Bacon Cheeseburger       1                     $9.25
    Mushroom Burger          1                     $8.99
    Bean Burger              2                     $19.90
    -----------------------------------------------------

    Total before tax: $54.64
    Tax Amount: $0.00
    Total price after tax: $54.64
    Tip Amount: $5.00
    -----------------------------------------------------
    Total after tip: $59.64

    Thank you for dining with us!
    Please come again soon!


### Logging Example  
    [Sun Oct 13 18:25:52 2024] Program started.
    [Sun Oct 13 18:25:53 2024] User selected Cheeseburger: 2 quantity.
    [Sun Oct 13 18:25:53 2024] User selected Bacon Cheeseburger: 1 quantity.
    [Sun Oct 13 18:25:53 2024] User selected Mushroom Burger: 1 quantity.
    [Sun Oct 13 18:25:53 2024] User selected Bean Burger: 2 quantity.
    [Sun Oct 13 18:25:53 2024] User finished making food choices.
    [Sun Oct 13 18:25:54 2024] User entered student choice: y
    [Sun Oct 13 18:25:54 2024] User is a student: yes
    [Sun Oct 13 18:25:54 2024] User finished making food choices.
    [Sun Oct 13 18:25:55 2024] User entered 'y' for adding a tip.
    [Sun Oct 13 18:25:55 2024] User entered a tip amount: $AAA
    [Sun Oct 13 18:25:56 2024] Invalid input for tip amount.
    [Sun Oct 13 18:25:56 2024] User entered a tip amount: $5
    [Sun Oct 13 18:25:57 2024] Bill generated: bill number 1659.
    [Sun Oct 13 18:25:58 2024] Program ended.

### Project Structure
     food-court-ordering-system/
     │
     ├── main.cpp            # Main source code for the food court system
     ├── README.md           # This README file
     ├── Activity_log.txt    # Log file for tracking events and errors
     └── <bill-number>.txt   # A bill file generated after each run


### Future Enhancements
+ Menu Customization: Adding the ability to update or expand the menu.
+ Discounts: Incorporating discount codes or promotions.
+ Multiple Payment Options: Adding support for various payment methods, like credit cards or digital wallets.
+ GUI Version: Converting the text-based program into a graphical user interface (GUI) for easier use.
+ Enhanced Logging: Implementing more detailed error handling and logging mechanisms.
+ Unit Testing: Implementing unit tests to validate the functionality of the system (e.g., GoogleTest for verifying correct bill calculation, input handling, and logging).
  
### Author
Wahab Samadi

### License
This project is licensed under the MIT License - see the LICENSE file for details.



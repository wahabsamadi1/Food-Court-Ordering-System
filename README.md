# Food Court Ordering and Billing System

### Overview
This project is a C++ program that simulates the ordering and billing system of a food court at Ohlone College. It allows users to select items from a menu of burgers, specify quantities, calculate the total price (including tax and optional tips), and generate a detailed bill. The bill is printed to the console and also saved as a text file for record-keeping.

### Features
+ **Menu Display:** A menu with a variety of burger options is presented to the user.  
+ **Order Input:** Users can input their order by selecting items from the menu and specifying quantities.  
+ **Tax Calculation:** Tax is calculated based on the user's student status. Students are exempt from taxes.  
+ **Tip Option:** Users have the option to add a custom tip amount.  
+ **Detailed Billing:** A detailed bill is generated, showing the itemized cost, tax, tip, and the final total. The bill is saved as a text file with a unique bill number.  

### Menu Items and Prices
| No.     | Item                   | Price |
| ------- | ---------------------- | ----- |
| 1       | Cheeseburger           | $8.25 |
| 2       | Veggie Burger          | $9.75 |
| 3       | Bacon Cheeseburger     | $9.25 |
| 4       | Mushroom Burger	       | $8.99 |
| 5       | Bean Burger            | $9.95 |

### How It Works
1. The program displays a menu with various burger options.  
2. The user selects items and specifies the quantities.  
3. The program calculates the total before tax.  
4. If the user is not a student, a 9% tax is applied. Students are tax-exempt.  
5. The user is given an option to add a tip.  
6. A detailed bill is printed on the console, and the same bill is saved as a text file for future reference.

### Program Structure
+ FoodCourt Class: This class contains all the methods required to manage the menu, take user input, calculate the total price, and generate the bill.  
+ displayMenu(): Displays the menu with item numbers and prices.  
+ getInputs(): Takes input from the user for their order and the quantities.  
+ calculateBill(): Calculates the total price based on the order.  
+ calculateTax(): Applies tax if the user is not a student.  
+ printBill(): Generates the bill, both on the console and in a text file.

### How to Run

1. Clone the repository from GitHub.  
2. Compile the program using a C++ compiler. Example command:  
   g++ -o foodcourt FoodCourt.cpp  
3. Run the executable:  
   ./foodcourt  
4. Follow the on-screen prompts to place your order and receive the bill.  

### Files
+ Main.cpp: The main program file that contains the code for the ordering and billing system.
+ README.md: This file, providing an overview of the project, how it works, and how to run it.

### Future Enhancements
+ Add more items to the menu.
+ Implement a graphical user interface (GUI).
+ Store transaction history in a database.
+ Allow users to modify or cancel an order before finalizing the bill.
  
### License
This project is licensed under the MIT License. Feel free to use, modify, and distribute this code.



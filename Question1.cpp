/*
FileName: Question1.cpp
Programmer:Zwelibanzi Charles Diale Sekano, EDUV4789671
Description: This program Displays the gadget catalogue and prices, calcalculates the subtotal, discount, and final amount, and displays the results.
*/
#include <iostream> //for input and output
#include <string> //for string handling
#include <iomanip> // for formattinf the output

int main() {
    //1. the user should enter their first and last name
    std::string firstName, lastName;
    std::cout << "Enter your first name:";
    std::cin >> firstName;
    std::cout << "Enter your last name:";
    std::cin >> lastName;

    //2. Displaying all available gadgets with their prices
    std::cout << "\nTech Store Catalogue:" << std::endl;
    std::cout << "1. Wireless Mouse - R150.00" << std::endl;
    std::cout << "2. Bluetooth Speaker - R250.00" << std::endl;
    std::cout << "3. USB Flash Drive - R100.00" << std::endl;
    std::cout << "4. Gaming Keyboard - R500.00" << std::endl;
    std::cout << "5. Noise-Canceling Headphones - R750.00" << std::endl;
    std::cout << "6. Smartwatch - R1,500.00" << std::endl;
    std::cout << "7. External Hard Drive - R1,000.00" << std::endl;
    std::cout << "8. Portable Charger - R300.00" << std::endl;

    //Array to store the gadget prices
    double prices[8] = {150.00, 250.00, 100.00, 500.00, 750.00, 1200.00, 1000.00, 300.00};
    double subtotal = 0.0; //this variable stores the subtotal
    // int selections = 0; //counter for 10 selections

    // item selection
    int numItems;
    std::cout << "\nHow many items would you like to purchase (up to 10)?"<< std::endl;
    std::cin >> numItems;
    if (numItems <1 || numItems > 10){
        std::cout << "Invalid number of items. program exiting." << std::endl;
       
    }
    
    //3. Allow the user to select up to 10 items with an input validation
    for(int i =0; i <numItems; i++){
        int itemNumber, quantity;

        std::cout << "Enter item number (1-8): ";
        std::cin >> itemNumber;

        if (itemNumber == 0) {
            break;  // Exit the loop if the user wants to finish
        }
        if (itemNumber < 1 || itemNumber > 8) {
            std::cout << "Invalid item number. Please enter a number between 1 and 8." << std::endl;
            continue;  // Skip to the next iteration without counting as a selection
        }
        std::cout << "Enter quantity: ";
        std::cin >> quantity;

        if (quantity < 1) {
            std::cout << "Invalid quantity. Quantity must be at least 1." << std::endl;
            continue;  // Skip to the next iteration without counting as a selection
        }

        //4. Calculate the total cost 
        // Add the cost of the selected items to the subtotal
        subtotal += prices[itemNumber - 1] * quantity;
    }
    //5. Applying the 15% discount(if any) to the subtotal
    double discount = 0.0;
    if (subtotal > 2000.0){
        discount = subtotal * 0.15; // 15% discount
    } 
    double finalTotal = subtotal - discount;

    // 6. Display the subtotal, discount applied, and the final total in a formatted manner
    std::cout << "\nSubtotal: R" << std::fixed << std::setprecision(2) << subtotal << std::endl;
    if (discount > 0){
        std::cout << "Discount: R" << std::fixed << std::setprecision(2) << discount << std::endl;
    }
    std::cout << "Final Total: R" << std::fixed << std::setprecision(2) << finalTotal << std::endl;

    return 0; // end of the program
}
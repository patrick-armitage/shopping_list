/*******************************************************************************
** Author: Patrick Armitage
** Date: 01/26/2016
** Description: Display fucntions file which defines the functions that were
** prototyped within the Display header file
*******************************************************************************/

#include <sstream>
#include <string>
#include <iomanip>
#include "NcursesTools.hpp"
#include "List.hpp"
#include "Display.hpp"

using std::string;
using std::to_string;
using std::stoi;
using std::stod;
using std::stringstream;
using std::fixed;
using std::setprecision;

/*----------------------------------------------------------------------------*/
/*
    Function Name: displayList
    Function Parameters: List object pointer
    What the function does: accesses the list pointer's item list, size, and
                            total cost, then calls the displayHeaderRow(),
                            displayItemRow() and displayFooterRow() functions
                            with necessary arguments.  For displayItemRow(),
                            iterates over the item list's items, calling the
                            function with each item in the list
*/
void displayList(List *list) {
    Item **itemList = list->getItemList();
    int size = list->getListSize();
    double totalListCost = list->calculateListTotal();

    displayHeaderRow();

    Item *item;
    for (int i = 0; i < size; i++) {
        item = *(itemList + i);
        displayItemRow(item);
    }

    displayFooterRow(totalListCost);
}

/*----------------------------------------------------------------------------*/
/*
    Function Name: displayHeaderRow
    Function Parameters: N/A
    What the function does: prints two rows of the shopping list, one row of
                            solid dashes, and a second of column headers of the
                            appropriate length for the items' name, quantity
                            and price
*/
void displayHeaderRow() {
    printw("----------------------------------------\n");
    printw("Item Name          | Quantity | Price   \n");
}

/*----------------------------------------------------------------------------*/
/*
    Function Name: displayItemRow
    Function Parameters: item object pointer
    What the function does: finds the name, quantity of price of the item, then
                            calls the appropriate format() function with each
                            value, which returns a formatted string.  Finally,
                            combines these formatted strings together and
                            prints them as one line
*/
void displayItemRow(Item *item) {
    string name = item->getItemName();
    int quantity = item->getQuantity();
    double price = item->getPrice();

    string row = formatName(name);
    row += "|" + formatQuantity(quantity);
    row += "|" + formatPrice(price) + "\n";
    printw(row.c_str());
}

/*----------------------------------------------------------------------------*/
/*
    Function Name: displayFooterRow
    Function Parameters: total list cost double
    What the function does: concatenates a formatted string of the total list
                            cost argument and a front-spaced column title,
                            then prints this string, and finally prints a row
                            of dashes at the bottom which mirror that of the
                            printHeaderRow section
*/
void displayFooterRow(double totalListCost) {
    string title = "                   Total Price:";
    string price = formatPrice(totalListCost);
    string row = title + price + "\n";

    printw(row.c_str());
    printw("----------------------------------------\n");
}

/*----------------------------------------------------------------------------*/
/*
    Function Name: formatName
    Function Parameters: item name string
    What the function does: Finds the length of provided name argument.  If
                            length is > 19, truncate name down to 15 chars with
                            trailing dots at end of name signifying truncation;
                            otherwise return name with correct amount of
                            whitespace at the end to appropriately space columns
*/
string formatName(string name) {
    int length = name.length();

    if (length > 19) {
        string truncated = "";

        // since the allotted space for item name is 19 chars, we only get the first 15 chars
        // of an overlong name, then add "... " to the end, filling 19 char spots
        for (int i = 0; i < 15; i++) {
            truncated += name[i];
        }

        truncated += "... ";
        return truncated;
    } else if (length < 19) {
        int difference = 19 - length;

        // for each iteration up to difference, add another space to name
        for (int i = 0; i < difference; i++) {
            name += " ";
        }

        return name;
    } else {
        return name;
    }
}

/*----------------------------------------------------------------------------*/
/*
    Function Name: formatQuantity
    Function Parameters: item quantity integer
    What the function does: Similar to formatName above, with the exception that
                            it first converts the integer to a string using
                            to_string string lib function, then appropriately
                            fills in any missing whitespace for column spacing.
                            Only allows integers of 8 digits (should be plenty!)
*/
string formatQuantity(int quantity) {
    // use a static cast from integer to long long so that to_string method call will
    // compile using -std=c++x0 flag on flip server (before c++11)
    string q = to_string(static_cast<long long>(quantity));
    int length = q.length();
    string formatted;

    if (length < 8) {
        int difference = 8 - length;

        for (int i = 0; i < difference; i++) {
            q += " ";
        }

        q += " ";
    } else {
        q += " ";
    }

    formatted = " " + q;
    return formatted;
}

/*----------------------------------------------------------------------------*/
/*
    Function Name: formatPrice
    Function Parameters: item quantity integer
    What the function does: Similar to formatName above, with the exception that
                            it first converts the double to a string by reading
                            the double into a stringstream and calling str() on
                            the stream.  Once converted, performs the same
                            whitespacing adjustment as the formatQuantity
                            function and returns a string
*/
string formatPrice(double price) {
    // we use a stringstream to read the double sized at precision(2) into the string
    // which is similar to reading the double to the std::cout function, except the
    // stringstream buffer is stored in memory and can be converted to a string
    stringstream stream;
    stream << fixed << setprecision(2) << price;
    string p = stream.str();
    int length = p.length();
    string formatted;

    if (length < 8) {
        int difference = 8 - length;

        for (int i = 0; i < difference; i++) {
            p += " ";
        }
    }

    formatted = " " + p;
    return formatted;
}

/*----------------------------------------------------------------------------*/
/*
    Function Name: addItemScreen
    Function Parameters: list object pointer
    What the function does: using provided list argument, prompts the user to
                            enter the name of the item they wish to add to the
                            list.  If item is not already in the list, prompts
                            user for quantity and price of item, and calls the
                            list's addItem() function with these arguments;
                            otherwise reports to user that item is already in
                            the list
*/
void addItemScreen(List *list) {
    string itemName, quantity, price, message;

    printw("Please insert the item name: ");
    itemName = getString();
    bool itemFound = list->itemExists(itemName);
    if (itemFound) {
        message = "'" + itemName + "' is already in your list!";
        printw(message.c_str());
    } else {
        printw("Please insert the quantity you plan to purchase: ");
        quantity = getString();
        printw("Please insert the item's price: ");
        price = getString();

        // convert quantity and price strings to integer and double, respectively
        int quantInt = stoi(quantity);
        double priceDouble = stod(price);
        list->addItem(itemName, quantInt, priceDouble);
        message = "'" + itemName + "' has been added to your list!";
        printw(message.c_str());
    }
}

/*----------------------------------------------------------------------------*/
/*
    Function Name: removeItemScreen
    Function Parameters: list object pointer
    What the function does: using provided list argument, prompts the user to
                            enter the name of the item they wish to remove from
                            their list.  If item is in the list, calls the
                            list's removeItem() method with the name of the
                            item; otherwise reports to user that item could not
                            be found in the list
*/
void removeItemScreen(List *list) {
    string itemName;

    printw("Please insert the item's name you wish to remove: ");
    itemName = getString();
    string message;
    bool itemFound = list->itemExists(itemName);
    if (itemFound) {
        message = "'" + itemName + "' was removed from your list!";
        list->removeItem(itemName);
        printw(message.c_str());
    } else {
        message = "'" + itemName + "' could not be found in your list!";
        printw(message.c_str());
    }
}

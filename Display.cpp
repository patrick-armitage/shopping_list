/*******************************************************************************
** Author: Patrick Armitage
** Date: 01/19/2016
** Description: Item methods file which defines the methods of the
** Item class that were prototyped within the GameBoard header file
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
    Function Name: Item
    Function Parameters: integer number of sides
    What the function does: initializes a new instance of the Item class,
                            setting number of sides to the provided sides arg
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

void displayHeaderRow() {
    printw("----------------------------------------\n");
    printw("Item Name          | Quantity | Price   \n");
}

void displayItemRow(Item *item) {
    string name = item->getItemName();
    int quantity = item->getQuantity();
    double price = item->getPrice();

    string row = formatName(name);
    row += "|" + formatQuantity(quantity);
    row += "|" + formatPrice(price) + "\n";
    printw(row.c_str());
}

void displayFooterRow(double totalListCost) {
    string title = "                   Total Price:";
    string price = formatPrice(totalListCost);
    string row = title + price + "\n";

    printw(row.c_str());
    printw("----------------------------------------\n");
}

string formatName(string name) {
    int length = name.length();

    if (length > 19) {
        string truncated = "";

        for (int i = 0; i < 16; i++) {
            truncated += name[i];
        }

        truncated += "... ";
        return truncated;
    } else if (length < 19) {
        int difference = 19 - length;

        for (int i = 0; i < difference; i++) {
            name += " ";
        }

        return name;
    } else {
        return name;
    }
}

string formatQuantity(int quantity) {
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

string formatPrice(double price) {
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

        int quantInt = stoi(quantity);
        double priceDouble = stod(price);
        list->addItem(itemName, quantInt, priceDouble);
        message = "'" + itemName + "' has been added to your list!";
        printw(message.c_str());
    }
}

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

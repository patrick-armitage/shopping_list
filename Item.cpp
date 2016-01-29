/*******************************************************************************
** Author: Patrick Armitage
** Date: 01/26/2016
** Description: Item methods file which defines the methods of the
** Item class that were prototyped within the GameBoard header file
*******************************************************************************/

#include <string>
#include "Item.hpp"

using std::string;

/*----------------------------------------------------------------------------*/
/*
    Function Name: Item
    Function Parameters: item's name string, quantity integer and price double
    What the function does: initializes a new instance of the Item class,
                            setting the item name, quantity, and price to the
                            provided args' values
*/
Item::Item(string name, string unitType, int quantity, double price) {
    setItemName(name);
    setUnitType(unitType);
    setQuantity(quantity);
    setPrice(price);
}

/*----------------------------------------------------------------------------*/
/*
    Function Names: setItemName, setQuantity, setPrice, getItemName,
                    getQuantity, getPrice
    Functions' Parameters: setters use corresponding values of data members
    What the functions do: getters and setters which act as public options to
                           read/write the Item class's private attribute methods
*/

void Item::setItemName(string name) {
    itemName = name;
}

void Item::setUnitType(string type) {
    unitType = type;
}

void Item::setQuantity(int q) {
    quantity = q;
}

void Item::setPrice(double p) {
    price = p;
}

string Item::getItemName() {
    return itemName;
}

string Item::getUnitType() {
    return unitType;
}

int Item::getQuantity() {
    return quantity;
}

double Item::getPrice() {
    return price;
}

/*----------------------------------------------------------------------------*/
/*
    Function Name: operator==
    Function Parameters: Item object and item pointer to compare to each other
    What the function does: using the friend keyword within the Item class
                            prototypes, compares an Item object with an item
                            pointer by comparing the two item's string names,
                            and returns true if they are equal, else returns
                            false
*/
bool operator==(Item item1, Item *item2) {
    if (item1.getItemName() == item2->getItemName()) {
        return true;
    } else {
        return false;
    }
}

/*----------------------------------------------------------------------------*/
/*
    Function Name: calculateExtended
    Function Parameters: N/A
    What the function does: calculates the "extended cost" of the Item object
                            by accessing the item's quantity and price, and
                            multiplying the two together, returning the result
*/
double Item::calculateExtended() {
    double extendedPrice;
    int quantity = getQuantity();
    double price = getPrice();

    extendedPrice = quantity * price;
    return extendedPrice;
}

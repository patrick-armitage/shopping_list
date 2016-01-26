/*******************************************************************************
** Author: Patrick Armitage
** Date: 01/19/2016
** Description: Item methods file which defines the methods of the
** Item class that were prototyped within the GameBoard header file
*******************************************************************************/

#include <string>
#include "Item.hpp"

using std::string;

/*----------------------------------------------------------------------------*/
/*
    Function Name: Item
    Function Parameters: integer number of sides
    What the function does: initializes a new instance of the Item class,
                            setting number of sides to the provided sides arg
*/
Item::Item(string name, int quantity, double price) {
    setItemName(name);
    setQuantity(quantity);
    setPrice(price);
}


/*----------------------------------------------------------------------------*/
/*
    Function Names: getSides, setSides
    Functions' Parameters: setSides has an integer sides parameter
    What the functions do: getters and setters which act as public options to
                           read/write the Item class's private attribute methods
*/

void Item::setItemName(string name) {
    itemName = name;
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

int Item::getQuantity() {
    return quantity;
}

double Item::getPrice() {
    return price;
}

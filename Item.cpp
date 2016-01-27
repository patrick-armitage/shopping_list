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
Item::Item(string name, int quantity, double price) {
    setItemName(name);
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

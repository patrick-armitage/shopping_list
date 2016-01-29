/*******************************************************************************
** Author: Patrick Armitage
** Date: 01/26/2016
** Description: Item class prototypes, which amount to several private data
** members and their getters and setters, but do not contain any of the
** business logic related to using the class, but rather act as a data
** container for shopping list items.
*******************************************************************************/

#include <string>

#ifndef ITEM_HPP
#define ITEM_HPP

using std::string;

class Item {
 private:
    string itemName;
    string unitType;
    int quantity;
    double price;
 public:
    Item(string itemName, string unitType, int quantity, double price);
    void setItemName(string itemName);
    void setUnitType(string unitType);
    void setQuantity(int quantity);
    void setPrice(double price);
    string getItemName();
    string getUnitType();
    int getQuantity();
    double getPrice();
    double calculateExtended();
    friend bool operator==(Item item1, Item *item2);
};

#endif

/*******************************************************************************
** Author: Patrick Armitage
** Date: 01/19/2016
** Description: Die class prototypes, which include one private data member,
** getters and setters, and a virtual method roll() which calculates dice roll
** and is overwritten by the child class.
*******************************************************************************/

#include <string>

#ifndef ITEM_HPP
#define ITEM_HPP

using std::string;

class Item {
 private:
    string itemName;
    int quantity;
    double price;
 public:
    Item(string itemName, int quantity, double price);
    void setItemName(string itemName);
    void setQuantity(int quantity);
    void setPrice(double price);
    string getItemName();
    int getQuantity();
    double getPrice();
};

#endif

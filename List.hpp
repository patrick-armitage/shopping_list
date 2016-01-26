/*******************************************************************************
** Author: Patrick Armitage
** Date: 01/19/2016
** Description: Die class prototypes, which include one private data member,
** getters and setters, and a virtual method roll() which calculates dice roll
** and is overwritten by the child class.
*******************************************************************************/

#include <string>
#include "Item.hpp"

#ifndef LIST_HPP
#define LIST_HPP

using std::string;

class List {
 private:
    Item **itemList;
    int listSize;
    int listMax;
 public:
    List();
    void setItemList(Item **itemList);
    void setListSize(int size);
    void incListSize();
    void decListSize();
    void setListMax(int listMax);
    Item **getItemList();
    int getListSize();
    int getListMax();
    Item **createListWithMax();
    double calculateExtended(Item *item);
    double calculateListTotal();
    void addItem(string name, int quantity, double price);
    void removeItem(string name);
    bool itemExists(string name);
};

#endif

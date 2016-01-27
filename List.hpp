/*******************************************************************************
** Author: Patrick Armitage
** Date: 01/26/2016
** Description: List class prototypes, which several private data members and
** a host of methods that enable manipulating and recreating an item list
** and finding calculations based on items within the list.
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

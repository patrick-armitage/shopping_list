/*******************************************************************************
** Author: Patrick Armitage
** Date: 01/19/2016
** Description: List methods file which defines the methods of the
** List class that were prototyped within the GameBoard header file
*******************************************************************************/

#include <typeinfo>
#include <string>
#include <iostream>
#include "NcursesTools.hpp"
#include "List.hpp"

using std::string;
using std::to_string;
using std::cout;
using std::endl;

/*----------------------------------------------------------------------------*/
/*
    Function Name: List
    Function Parameters: integer number of sides
    What the function does: initializes a new instance of the List class,
                            setting number of sides to the provided sides arg
*/
List::List() {
    Item **list = new Item*[10];

    setItemList(list);
    setListSize(0);
    setListMax(10);
}

/*----------------------------------------------------------------------------*/
/*
    Function Names: getSides, setSides
    Functions' Parameters: setSides has an integer sides parameter
    What the functions do: getters and setters which act as public options to
                           read/write the List  class's private attribute methods
*/
void List::setItemList(Item **list) {
    itemList = list;
}

void List::setListSize(int size) {
    listSize = size;
}

void List::incListSize() {
    listSize++;
}

void List::decListSize() {
    listSize--;
}

void List::setListMax(int max) {
    listMax = max;
}

Item **List::getItemList() {
    return itemList;
}

int List::getListSize() {
    return listSize;
}

int List::getListMax() {
    return listMax;
}

/*----------------------------------------------------------------------------*/
/*
    Function Name: roll
    Function Parameters: N/A
    What the function does: calculates a random rolled integer between 1 and the
                            number of sides of the dice being rolled
*/

Item **List::createListWithMax() {
    Item **newList = new Item*[10];
    int size = getListSize();
    int max = getListMax();
    bool keepSameSize = false;
    if (size < (max - 1)) {
        keepSameSize = true;
    }

    switch (max) {
    case 10 :
        if (keepSameSize) {
            newList = new Item*[10];
            setListMax(10);
        } else {
            newList = new Item*[20];
            setListMax(20);
        }
    case 20 :
        if (keepSameSize) {
            newList = new Item*[20];
            setListMax(20);
        } else {
            newList = new Item*[30];
            setListMax(30);
        }
    case 30 :
        if (keepSameSize) {
            newList = new Item*[30];
            setListMax(30);
        } else {
            newList = new Item*[40];
            setListMax(40);
        }
    case 40 :
        if (keepSameSize) {
            newList = new Item*[40];
            setListMax(40);
        } else {
            newList = new Item*[50];
            setListMax(50);
        }
    case 50 :
        if (keepSameSize) {
            newList = new Item*[50];
            setListMax(50);
        } else {
            newList = new Item*[60];
            setListMax(60);
        }
    }

    return newList;
}

double List::calculateExtended(Item *item) {
    double extendedPrice;
    int quantity = item->getQuantity();
    double price = item->getPrice();

    extendedPrice = quantity * price;
    return extendedPrice;
}

double List::calculateListTotal() {
    Item **list = getItemList();
    int size = getListSize();

    double totalCost = 0;
    Item *item;
    for (int i = 0; i < size; i++) {
        item = *(list + i);
        totalCost += calculateExtended(item);
    }

    return totalCost;
}

void List::addItem(string name, int quantity, double price) {
    Item **list = getItemList();
    int size = getListSize();

    Item *item = new Item(name, quantity, price);
    Item **newList = createListWithMax();
    if (size > 0) {
        for (int i = 0; i < size; i++) {
            *(newList + i) = *(list + i);
        }

        *(newList + size) = item;
    } else {
        *(newList + 0) = item;
    }

    setItemList(newList);
    delete[] list;
    incListSize();
}

void List::removeItem(string name) {
    Item **list = getItemList();
    int size = getListSize();
    Item **newList = new Item*[10];

    int counter = 0;
    for (int i = 0; i < size; i++) {
        Item *item = *(list + i);

        if (item->getItemName() == name) {
            counter -= 1;
        } else {
            newList[counter] = item;
        }

        counter++;
    }

    setItemList(newList);
    delete[] list;
    decListSize();
}

bool List::itemExists(string name) {
    Item **list = getItemList();
    int size = getListSize();

    for (int i = 0; i < size; i++) {
        Item *item = *(list + i);
        string itemName = item->getItemName();

        if (itemName == name) {
            return true;
        }
    }

    return false;
}

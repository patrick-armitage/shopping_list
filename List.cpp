/*******************************************************************************
** Author: Patrick Armitage
** Date: 01/26/2016
** Description: List methods file which defines the methods of the
** List class that were prototyped within the List header file
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
    Function Parameters: N/A
    What the function does: initializes a new instance of the List class,
                            creating a new Item pointer array with default
                            size of 10, and setting it as the class's list,
                            setting list size to 0, and setting list max to 10
*/
List::List() {
    Item **list = new Item*[10];

    setItemList(list);
    setListSize(0);
    setListMax(10);
}

/*----------------------------------------------------------------------------*/
/*
    Function Names: setItemList, setListSize, incListSize, decListSize,
                    setListMax, getItemList, getListSize, getListMax
    Functions' Parameters: setSides has an integer sides parameter
    What the functions do: getters and setters which act as public options to
                           read/write the List class's private attribute methods
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
    Function Name: createListWithMax
    Function Parameters: N/A
    What the function does: used to create a new list in "addItem" and
                            "removeItem" functions.  First, it creates a new
                            list to be returned if the current listMax is 10
                            and listSize is < 9.  If not, case statement finds
                            which size list should be returned based upon
                            the size of listMax, and whether or not listSize is
                            > (listMax - 2)
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

/*----------------------------------------------------------------------------*/
/*
    Function Name: calculateListTotal
    Function Parameters: Item object pointer
    What the function does: calculates the total cost of all the items in the
                            shopping list, by accessing the list, iterating
                            over each item, finding its extended cost, then
                            calculating the sum of all the extended costs,
                            returning their value
*/
double List::calculateListTotal() {
    Item **list = getItemList();
    int size = getListSize();

    double totalCost = 0;
    Item *item;
    for (int i = 0; i < size; i++) {
        item = *(list + i);
        totalCost += item->calculateExtended();
    }

    return totalCost;
}

/*----------------------------------------------------------------------------*/
/*
    Function Name: addItem
    Function Parameters: item's name string, quantity integer and price double
    What the function does: Adds another item to the item list's array of item
                            pointers.  First, a new list is created using the
                            createListWithMax function, which will extend its
                            max value if necessary.  Then, the current list is
                            iterated over and all its items are added in to
                            the new list.  Afterward, the new item which was
                            created is added to the latest empty index of the
                            new list.  The new list is then set as the List
                            class's list, the old list deleted, and the List
                            class's list size incremented
*/
void List::addItem(string name, string unitType, int quantity, double price) {
    Item **list = getItemList();
    int size = getListSize();

    Item *item = new Item(name, unitType, quantity, price);
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

/*----------------------------------------------------------------------------*/
/*
    Function Name: removeItem
    Function Parameters: item's name string
    What the function does: accesses the List class's list, creating a new list
                            which will omit the original list's item to be
                            removed, and then iterates over the original list,
                            using a counter var to account for the missing
                            index of the removed item's index number.  Finally,
                            set's the new list as the class's list, deletes the
                            old list, and decrements the class's list size
*/
void List::removeItem(string name) {
    Item **list = getItemList();
    int size = getListSize();
    Item **newList = new Item*[10];
    Item item1(name, "  ", 0, 0.0);
    Item *item2;

    int counter = 0;
    for (int i = 0; i < size; i++) {
        item2 = *(list + i);

        if (item1 == item2) {
            counter -= 1;
        } else {
            newList[counter] = item2;
        }

        counter++;
    }

    setItemList(newList);
    delete[] list;
    decListSize();
}

/*----------------------------------------------------------------------------*/
/*
    Function Name: itemExists
    Function Parameters: item's name string
    What the function does: accesses the class's item list and iterates over
                            it, comparing the name of each item in the list to
                            the provided name argument.  If there is a match,
                            the function returns true (as in, item does exist),
                            but if the loop finishes and no match is found,
                            item returns false.
*/
bool List::itemExists(string name) {
    Item **list = getItemList();
    int size = getListSize();

    Item item1(name, "  ", 0, 0.0);
    Item *item2;
    for (int i = 0; i < size; i++) {
        item2 = *(list + i);

        if (item1 == item2) {
            return true;
        }
    }

    return false;
}

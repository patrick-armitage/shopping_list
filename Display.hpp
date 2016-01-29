/*******************************************************************************
** Author: Patrick Armitage
** Date: 01/26/2016
** Description: Display function prototypes, which leverage the Ncurses lib
** functionality to access data (via a provided List class), and handle the
** input/output to and from the program's user.  These functions include
** display functions to display the shopping list, string formatting functions,
** and separate "screen" functions that enable the user to add and remove items
*******************************************************************************/

#include <string>
#include "Item.hpp"
#include "List.hpp"

#ifndef DISPLAY_HPP
#define DISPLAY_HPP

using std::string;

void displayList(List *list);
void displayHeaderRow();
void displayItemRow(Item *item);
void displayFooterRow(double totalListCost);
string formatName(string name);
string formatQuantity(int quantity, string unitType);
string formatPrice(double price);
string formatExtendedPrice(Item *item);
string formatTotal(double totalCost);
void addItemScreen(List *list);
void removeItemScreen(List *list);

#endif

/*******************************************************************************
** Author: Patrick Armitage
** Date: 01/19/2016
** Description: Die class prototypes, which include one private data member,
** getters and setters, and a virtual method roll() which calculates dice roll
** and is overwritten by the child class.
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
string formatQuantity(int quantity);
string formatPrice(double price);
void addItemScreen(List *list);
void removeItemScreen(List *list);

#endif

/*******************************************************************************
** Author: Patrick Armitage
** Date: 01/17/2016
** Description: Code file defining the functions that are declared as
** prototypes within the NcursesTools header file
*******************************************************************************/

#include <string>
#include "NcursesTools.hpp"

using std::string;

/*----------------------------------------------------------------------------*/
/*
    Function Name: initCurses
    Function Parameters: N/A
    What the function does: initializes Ncurses session in a basic state,
                            setting such commands as getch() to blocking mode
                            which enables user to input GoL configuration
                            before the start of the game
*/
void initCurses() {
    setlocale(LC_ALL, "");
    initscr();
    nocbreak();
    echo();
    nonl();
    intrflush(stdscr, FALSE);
    keypad(stdscr, TRUE);
}

/*----------------------------------------------------------------------------*/
/*
    Function Name: initCurses
    Function Parameters: N/A
    What the function does:
*/
string getString() {
    string input;
    int ch = getch();

    while (ch != '\n') {
        input.push_back(ch);
        ch = getch();
    }

    return input;
}

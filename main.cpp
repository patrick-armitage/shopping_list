#include <string>

#include "NcursesTools.hpp"
#include "List.hpp"
#include "Item.hpp"
#include "Display.hpp"

using std::string;

int main(int argc, char *argv[]) {
    initCurses();

    List *list = new List();
    int pressed_key;
    printw("Welcome to Shopping List!  Press q to quit anytime\n\n");
    printw("To get started, please add an item to your shopping list!\n");
    addItemScreen(list);

    cbreak();
    pressed_key = getch();
    while (pressed_key != 'q') {
        clear();
        printw("Press q to quit\n");
        printw("Press a to add an item and r to remove one\n\n");
        displayList(list);
        refresh();

        if (pressed_key == 'a') {
            clear();
            nocbreak();
            addItemScreen(list);
            printw("\nPress return to continue...");
        } else if (pressed_key == 'r') {
            clear();
            nocbreak();
            removeItemScreen(list);
            printw("\nPress return to continue...");
        }

        cbreak();
        pressed_key = getch();
    }

    endwin();
    return 0;
}

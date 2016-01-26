/*******************************************************************************
** Author: Patrick Armitage
** Date: 01/17/2016
** Description: A collection of utility methods that use the Ncurses unix
** library.  The purpose of this toolset is to be able to configure and
** initialize an Ncurses session for the Game of Life.  These methods abstract
** out some of the complexity involved that would otherwise clutter up the
** main.cpp file, increasing organization.

*******************************************************************************/

#include <ncurses.h>
#include <unistd.h>  // adds functions such as usleep()
#include <locale.h>  // allows us to setlocale()
#include <string>

#ifndef NCURSESTOOLS_HPP
#define NCURSESTOOLS_HPP

void initCurses();
std::string getString();

#endif

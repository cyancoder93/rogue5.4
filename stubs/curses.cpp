#include "curses.h"

// Global variables that need to be defined somewhere
WINDOW* stdscr = nullptr;
WINDOW* curscr = nullptr;
int LINES = 24;
int COLS = 80;

// Terminal capability variables
char* CE = (char*)"";  // Clear to end of line capability - empty string means capability exists
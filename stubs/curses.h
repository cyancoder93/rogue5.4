#pragma once

// define stubs for curses functions

#include <new>

// Basic type definitions
typedef int chtype;
typedef struct WINDOW
{
	int w;
	int y;
} WINDOW;

// Constants
#define A_CHARTEXT 0xFF

// Terminal capability constants
extern char* CE;  // Clear to end of line capability

// Error return value
#define ERR (-1)

// Key constants - using const int for C++ compatibility
const int KEY_LEFT = 260;
const int KEY_RIGHT = 261;
const int KEY_UP = 259;
const int KEY_DOWN = 258;
const int KEY_HOME = 262;
const int KEY_END = 269;
const int KEY_PPAGE = 339;  // Page Up
const int KEY_NPAGE = 338;  // Page Down
const int KEY_A1 = 332;     // Upper left of keypad
const int KEY_A3 = 334;     // Upper right of keypad
const int KEY_B2 = 335;     // Center of keypad
const int KEY_C1 = 336;     // Lower left of keypad
const int KEY_C3 = 337;     // Lower right of keypad

// Global variables
extern WINDOW *stdscr, *curscr;
extern int LINES, COLS;

inline void wclear(WINDOW* win)
{
	(void)win;
}
inline void wstandout(WINDOW* win)
{
	(void)win;
}
inline void wmove(WINDOW* win, int y, int x)
{
	(void)win;
	(void)y;
	(void)x;
}
inline void waddch(WINDOW* win, int ch)
{
	(void)win;
	(void)ch;
}
inline void wstandend(WINDOW* win)
{
	(void)win;
}
inline void wrefresh(WINDOW* win)
{
	(void)win;
}
inline void mvwin(WINDOW* win, int y, int x)
{
	(void)win;
	(void)y;
	(void)x;
}
inline int mvwinch(WINDOW* wim, int y, int x)
{
	(void)wim;
	(void)y;
	(void)x;
	return ' ';
}
inline void touchwin(WINDOW* win)
{
	(void)win;
}
inline void mvaddch(int y, int x, int ch)
{
	(void)y;
	(void)x;
	(void)ch;
}
inline void werase(WINDOW* win)
{
	(void)win;
}
inline void leaveok(WINDOW* win, int flag)
{
	(void)win;
	(void)flag;
}
inline WINDOW *newwin(int h, int w, int y, int x)
{
	(void)h;
	(void)w;
	(void)y;
	(void)x;
	return new WINDOW();
}
inline void endwin()
{
}
inline void clearok(WINDOW* win, int flag)
{
	(void)win;
	(void)flag;
}
inline void addstr(const char* str)
{
	(void)str;
}
inline void refresh()
{
}
inline void initscr()
{
}
inline void keypad(WINDOW* win, int flag)
{
	(void)win;
	(void)flag;
}
inline char* unctrl(int ch)
{
	(void)ch;
	static char result[2] = {' ', '\0'};
	return result;
}
inline void waddstr(WINDOW* win, const char* str)
{
	(void)win;
	(void)str;
}
inline void mvwprintw(WINDOW* win, int y, int x, const char* fmt, ...)
{
	(void)win;
	(void)y;
	(void)x;
	(void)fmt;
}
inline WINDOW *subwin(WINDOW* win, int h, int w, int y, int x)
{
	(void)win;
	(void)h;
	(void)w;
	(void)y;
	(void)x;
	return new WINDOW();
}
inline void getyx(WINDOW* win, int& y, int& x)
{
	(void)win;
	y = 0;
	x = 0;
}
inline int getmaxy(WINDOW* win)
{
	(void)win;
	return 24;
}
inline int getmaxx(WINDOW* win)
{
	(void)win;
	return 80;
}
inline void addch(int ch)
{
	(void)ch;
}
inline void move(int y, int x)
{
	(void)y;
	(void)x;
}
inline void mvwaddch(WINDOW* win, int y, int x, int ch)
{
	(void)win;
	(void)y;
	(void)x;
	(void)ch;
}
inline void standout()
{
}
inline void standend()
{
}
inline void mvaddstr(int y, int x, const char* str)
{
	(void)y;
	(void)x;
	(void)str;
}
inline void delwin(WINDOW *win)
{
	delete win;
}
inline void clear()
{
}

// Missing functions from compilation errors
inline int mvinch(int y, int x)
{
	(void)y;
	(void)x;
	return ' ';
}
inline int inch()
{
	return ' ';
}
inline void clrtoeol()
{
}
inline void printw(const char* fmt, ...)
{
	(void)fmt;
}
inline void mvprintw(int y, int x, const char* fmt, ...)
{
	(void)y;
	(void)x;
	(void)fmt;
}
inline void wprintw(WINDOW* win, const char* fmt, ...)
{
	(void)win;
	(void)fmt;
}
inline void wclrtoeol(WINDOW* win)
{
	(void)win;
}
inline int erasechar()
{
	return 8; // backspace
}
inline int killchar()
{
	return 21; // ctrl-U
}
inline void wgetnstr(WINDOW* win, char* str, int n)
{
	(void)win;
	(void)str;
	(void)n;
}
inline void raw()
{
}
inline void noecho()
{
}
inline void flushinp()
{
}
inline void idlok(WINDOW* win, int flag)
{
	(void)win;
	(void)flag;
}
inline void mvcur(int oldrow, int oldcol, int newrow, int newcol)
{
	(void)oldrow;
	(void)oldcol;
	(void)newrow;
	(void)newcol;
}
inline int baudrate()
{
	return 9600;
}
inline int isendwin()
{
	return 0; // FALSE equivalent
}

// Additional functions needed by mdport.cpp
inline int wgetch(WINDOW* win)
{
	(void)win;
	return 'a'; // Return a dummy character
}

inline void nodelay(WINDOW* win, int flag)
{
	(void)win;
	(void)flag;
}

// Global variables (declare in source file)
extern WINDOW *stdscr, *curscr;
extern int LINES, COLS;
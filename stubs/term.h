#pragma once

// Stub for term.h - terminal capability definitions
// This provides minimal definitions for Windows compatibility

// Terminal capability structures and definitions
typedef struct {
    char *name;
    char *value;
} TERMCAP_ENTRY;

// Common terminal capability constants
#define TERM_OK 1
#define TERM_ERR 0

// Function stubs for terminal capabilities
inline int tgetent(char *bp, const char *name)
{
    (void)bp;
    (void)name;
    return TERM_OK;
}

inline int tgetflag(const char *id)
{
    (void)id;
    return 0;
}

inline int tgetnum(const char *id)
{
    (void)id;
    return -1;
}

inline char *tgetstr(const char *id, char **area)
{
    (void)id;
    (void)area;
    return nullptr;
}

inline char *tgoto(const char *cap, int col, int row)
{
    (void)cap;
    (void)col;
    (void)row;
    return nullptr;
}

inline int tputs(const char *str, int affcnt, int (*putc)(int))
{
    (void)str;
    (void)affcnt;
    (void)putc;
    return TERM_OK;
}

// Terminal speed and control
inline void ospeed_set(int speed)
{
    (void)speed;
}

// Global variables that might be expected
extern char PC;
extern char *BC;
extern char *UP;
extern short ospeed;
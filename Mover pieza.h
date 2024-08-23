#include <ncurses.h>

void MP(int &i, char pieza, int tecla)
{
    keypad(stdscr, TRUE);

    switch (tecla)
    {
    case KEY_LEFT:
        if (i > 1)
        {
            i -= 2;
        }
        break;
    case KEY_RIGHT:
        if (i < 11)
        {
            i += 2;
        }
        break;
    }
    
    mvaddch(0,i,pieza);

}
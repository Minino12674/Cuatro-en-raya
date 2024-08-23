#include <ncurses.h>

void IMPmapa(char mapa[7][17])
{
    for (int i = 0; i < 7; i++)
            {
                for (int j = 0; j < 14; j++)
                {
                    mvaddch(i + 1, j, mapa[i][j]);
                }
            }
}
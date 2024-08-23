#include <ncurses.h>
#include "Comprobacion.h"

void acomodarP(int *pos, char &p, char tablero[7][17])
{
    for (int i = 0; i < 7; i++)
    {
        if (tablero[i][pos[1]] == ' ')
        {
            pos[0] = i;
        }
        else
        {
            break;
        }
    }

    if (tablero[0][pos[1]] == ' ')
    {
        tablero[pos[0]][pos[1]] = p; // Inserta la pieza en la posición calculada
        mvaddch(pos[0] + 1, pos[1], p);
    }
}

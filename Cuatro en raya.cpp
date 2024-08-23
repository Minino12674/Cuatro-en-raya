#include <iostream>
#include <ncurses.h>
#include <string>
#include "Mover pieza.h"
#include "Insertar pieza.h"
#include "Comprobacion.h"
#include "Limpiar tablero.h"
#include "Imprimir tablero.h"
#include "Menu.h"
#include "Alternar pieza.h"

using namespace std;

int main()
{
    initscr(); // iniciando ncurses
    noecho();  // Evita que se ponga la tecla ingresado en pantalla
    cbreak();  // Desactiva el buffering de línea para que getch() funcione en tiempo real
    curs_set(0);
    keypad(stdscr, TRUE);

    char mapa[7][17] = {
        {'|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|'},
        {'|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|'},
        {'|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|'},
        {'|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|'},
        {'|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|'},
        {'|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|'},
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', ' ', '|'}};

    int a, lP = 1;
    int ultimaPOS[2] = {0, 0};
    char pieza = 'x';
    int x = 2;
    char menu[4][19] = {{".:  4 en raya :."},
                        {"                "},
                        {"     Jugar      "},
                        {"     Salir      "}};

    while (true)
    {
        while (true)
        {
            char result = IMPmenu(menu,x);

            if (result == 'a')
            {
                break;
            }
            else if(result == 'f')
            {
                endwin();
                return 0;
            }

            refresh();
        }

        clear(mapa);

        while (true)
        {
            a = getch();
            clear();

            IMPmapa(mapa);

            if (a == 10)
            {
                ultimaPOS[1] = lP;
                acomodarP(ultimaPOS, pieza, mapa);
                move(4, 20); // Mover el cursor para imprimir el ganador :D
                if (lleno(mapa) == true)
                {
                    printw("No gano nadie XD");
                    getch();
                    break;
                }
                if (vertical(ultimaPOS, pieza, mapa) || horizontal(ultimaPOS, pieza, mapa) || diagonal(ultimaPOS, pieza, mapa) || diagonalINV(ultimaPOS, pieza, mapa))
                {
                    printw("Felicidades jugador \"%c\"", pieza);
                    getch();
                    break;
                }
                altPieza(ultimaPOS, pieza, mapa);
            }

            MP(lP, pieza, a);

            refresh();
        }
    }

    move(9, 0);
    printw("Presione cualquier tecla para terminar...");
    getch();
    endwin(); // Finalizando ncurses
    return 0;
}
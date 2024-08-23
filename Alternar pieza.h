void altPieza(int *pos, char &pieza, char tablero[7][17])
{
    if (tablero[0][pos[1]] == ' ')
    {
        if (pieza == 'x')
        {
            pieza = '0';
        }
        else
        {
            pieza = 'x';
        }
    }
}
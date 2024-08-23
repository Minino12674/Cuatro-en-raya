void clear(char mapa[7][17])
{
    for (int i = 0; i < 6; i++)
    {
        for (int j = 1; j < 15; j += 2)
        {
            mapa[i][j] = ' ';
        }
    }
}
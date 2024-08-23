#pragma once

bool lleno(char map[7][17])
{
    for (int i = 0; i < 6; i++)
    {
        for (int j = 1; j < 14; j += 2)
        {
            if (map[i][j] == ' ')
            {
                return false;
            }
        }
    }
    return true;
}

bool vertical(int *ultimaPOS, char pieza, char mapa[7][17])
{
    int allados = 1;
    int posY = ultimaPOS[1];
    int posX = ultimaPOS[0];
    int pos = 1;

    if (posY == 0)
    {
        return false;
    }
    
    while (true)
    {
        if (allados == 4)
        {
            return true;
        }
        if (mapa[posX + pos][posY] == pieza)
        {
            allados ++;
            pos ++; 
        }
        else
        {
            break;
        }
    }  

    return false;
}

bool horizontal(int *ultimaPOS, char pieza, char mapa[7][17])
{
    int allados = 1;
    int posY = ultimaPOS[1];
    int posX = ultimaPOS[0];
    int pos = 2;

    if (posY == 0)
    {
        return false;
    }
    
    while (true)
    {
        if (allados == 4)
        {
            return true;
        }
        if (mapa[posX][posY + pos] == pieza)
        {
            allados++;
            pos += 2; 
        }
        else
        {
            break;
        }
    }  

    pos = 2;
    
    while (true)
    {
        if (allados == 4)
        {
            return true;
        }
        if (mapa[posX][posY - pos] == pieza)
        {
            allados ++;
            pos += 2; 
        }
        else
        {
            break;
        }
    }

    return false;
}

bool diagonal(int *ultimaPOS, char pieza, char mapa[7][17])
{
    int allados = 1;
    int posY = ultimaPOS[1];
    int posX = ultimaPOS[0];
    int posx = 1;
    int posy = 2;

    if (posY == 0)
    {
        return false;
    }
    
    while (true)
    {
        if (allados == 4)
        {
            return true;
        }
        if (mapa[posX - posx][posY + posy] == pieza)
        {
            allados++;
            posx ++;
            posy += 2; 
        }
        else
        {
            break;
        }
    }  

    posx = 1;
    posy = 2;
    
    while (true)
    {
        if (allados == 4)
        {
            return true;
        }
        if (mapa[posX + posx][posY - posy] == pieza)
        {
            allados ++;
            posx ++;
            posy += 2; 
        }
        else
        {
            break;
        }
    }

    return false;
}

bool diagonalINV(int *ultimaPOS, char pieza, char mapa[7][17])
{
    int allados = 1;
    int posY = ultimaPOS[1];
    int posX = ultimaPOS[0];
    int posx = 1;
    int posy = 2;

    if (posY == 0)
    {
        return false;
    }
    
    while (true)
    {
        if (allados == 4)
        {
            return true;
        }
        if (mapa[posX - posx][posY - posy] == pieza)
        {
            allados++;
            posx ++;
            posy += 2; 
        }
        else
        {
            break;
        }
    }  

    posx = 1;
    posy = 2;
    
    while (true)
    {
        if (allados == 4)
        {
            return true;
        }
        if (mapa[posX + posx][posY + posy] == pieza)
        {
            allados ++;
            posx ++;
            posy += 2; 
        }
        else
        {
            break;
        }
    }

    return false;
}

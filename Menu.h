char IMPmenu(char menu[4][19],int &x)
{
    clear();
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 16; j++)
        {
            mvaddch(i, j, menu[i][j]);
        }
    }

    move(x, 11);
    printw("<--");

    int a = getch();

    switch (a)
    {
    case KEY_UP:
        if (x == 3)
        {
            x--;
        }
        break;
    case KEY_DOWN:
        if (x == 2)
        {
            x++;
        }
        break;
    }
    if (a == 10)
    {
        if (x == 2)
        {
            return 'a';
        }
        else
        {
            endwin();
            return 'f';
        }
    }

    return 'n';
}
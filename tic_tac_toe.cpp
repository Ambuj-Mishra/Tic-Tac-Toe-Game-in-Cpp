#include <iostream>
#include <cstdlib>
#include <time.h>
#include <stdlib.h>
using namespace std;

int a[3][3], option;
string name;
bool flag = 0;
int cch;

void block()
{
    system("cls");
    int x = 0, y = 0;
    cout << "\n\n\n\n\n\n";
    for (int i = 5; i <= 15; i++)
    {
        cout << "                     ";
        if (i % 4 != 0)
        {
            //cout<<"   ";
            for (int j = 6; j < 19; j++)
            {
                if (j % 5 != 0)
                {
                    if ((j == 8 || j == 13 || j == 17) && (i == 14 || i == 10 || i == 6))
                    {
                        cout << a[y][x] << " ";
                        if (x == 2)
                        {
                            x = 0;
                            y++;
                        }
                        else
                        {
                            x++;
                        }
                    }
                    else
                        cout << "  ";
                }
                else if (j % 5 == 0)
                    cout << "|";
            }
        }
        else if (i % 4 == 0)
        {
            for (int j = 6; j < 19; j++)
            {
                if (j % 5 != 0)
                    cout << "--";
                else if (j % 5 == 0)
                    cout << " ";
            }
        }
        cout << endl;
    }
}

void game()
{
    int x, y;
    cout << "        \n\n\nEnter row no. where you want to insert :: ";
    cin >> x;
    cout << "        \n\nEnter row no. where you want to insert :: ";
    cin >> y;

    a[x][y] = option;
p:
    srand(time(0));
    x = rand() % 3;
    y = rand() % 3;
    if (a[x][y] != 0)
        goto p;
    else
        a[x][y] = cch;
}

void check()
{
    for (int i = 0; i < 3; i++)
    {
        if (a[i][0] == option && a[i][1] == option && a[i][2] == option)
        {
            system("cls");
            cout << "\n\n\n\n          Wow !!! You won the match ";
            flag = 1;
            break;
        }
        else if (a[0][i] == option && a[1][i] == option && a[2][i] == option)
        {
            system("cls");
            cout << "\n\n\n\n          Wow !!! You won the match ";
            flag = 1;
            break;
        }
    }

    for (int i = 0; i <= 0; i++)
    {
        if (a[i][i] == a[i + 1][i + 1] == a[i + 2][i + 2] == option)
        {
            system("cls");
            cout << "\n\n\n\n          Wow !!! You won the match ";
            flag = 1;
            break;
        }
        else if (a[i][i + 2] == option && a[i + 1][i + 1] == option && a[i + 2][i] == option)
        {
            system("cls");
            cout << "\n\n\n\n          Wow !!! You won the match ";
            flag = 1;
            break;
        }
    }
}

void ccheck()
{
    for (int i = 0; i < 3; i++)
    {
        if (a[i][0] == cch && a[i][1] == cch && a[i][2] == cch)
        {
            system("cls");
            cout << "\n\n\n\n           Computer won the match ";
            flag = 1;
            break;
        }
        else if (a[0][i] == cch && a[1][i] == cch && a[2][i] == cch)
        {
            system("cls");
            cout << "\n\n\n\n           Computer won the match ";
            flag = 1;
            break;
        }
    }

    for (int i = 0; i <= 0; i++)
    {
        if (a[i][i] == cch && a[i + 1][i + 1] == cch && a[i + 2][i + 2] == cch)
        {
            system("cls");
            cout << "\n\n\n\n          Computer won the match ";
            flag = 1;
            break;
        }
        else if (a[i][i + 2] == cch && a[i + 1][i + 1] == cch && a[i + 2][i] == cch)
        {
            system("cls");
            cout << "\n\n\n\n          Computer won the match ";
            flag = 1;
            break;
        }
    }
}
int main()
{
a:
    cout << "\n\n\n\n\n       * * * * * * *  Welcome !!! to TIC - TAC - TOE Game * * * * * * *" << endl;
    cout << "\n\n\n                               Enter your Name :: ";
    cin >> name;
    cout << "\n\n                          What you would like to choose ( 1 or 2 )?  ";
    cin >> option;

    if (option != 1 && option != 2)
    {
        cout << "You have pressed the wrong key " << endl;
        system("cls");
        goto a;
    }

    if (option == 1)
        cch = 2;
    else if (option == 2)
        cch = 1;

    system("cls");

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            a[i][j] = 0;
    bool f2 = 1;
    int loop;
    for(loop = 0; loop<10; loop++)
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (a[i][j] == 0)
                    f2 = 0;
            }
        }
        block();
        game();
        check();
        ccheck();
        if (flag == 1)
            break;
        else if (f2 == 1)
        {
            system("cls");
            cout << "\n\n\n\n\n                     Match gets tied";
            break;
        }
    }
}
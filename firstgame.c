#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int y = 10;
int flag, gameOver;
int preyx, preyy;

void setup()
{
    preyx=2;
label2:
    preyy = rand() % 20 - 1;
    if (preyy == 0 || preyy == 19)
    {
        goto label2;
    }
}

void draw()
{
    system("cls");
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            if ((i == 0 || i == 19) || (j == 0 || j == 19))
            {
                printf("*");
            }
            else if(i==1 && j!=preyy)
            {
                printf("O");
            }
            else if (i == preyx && j == preyy)
            {
                printf("O");
            }
            else if (i == 18 && j == y)
            {
                printf("A");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void input()
{
    if (kbhit())
    {
        switch (getch())
        {
        case 'a':
            flag = 1;
            break;
        case 'd':
            flag = 2;
            break;
        case 'x':
            gameOver = 1;
            break;
        }
    }
}

void makeLogic()
{
    switch (flag)
    {
    case 1:
        if (y > 2)
        {
            y--;
        }
        else
        {
            y = 1;
        }
        break;
    case 2:
        if (y <= 17)
        {
            y++;
        }
        else
        {
            y = 18;
        }
        break;
    }

    if (preyx==18 && preyy==y)
    {
        gameOver=1;
    }
    

}

int main()
{
    while (gameOver != 1)
    {
        setup();
            while (preyx!=20)
            {
                draw();
                input();
                makeLogic();

                for (int i = 0; i < 100; i++)
                {
                    for (int j = 0; j < 100; j++)
                    {
                    }
                }
                preyx++;

            }
            
    }

    printf("Game Over\n");

    return 0;
}
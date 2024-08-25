#include <stdio.h>
#include <conio.h>
#include <windows.h>
char gmain[21][36], p1[20] = {0}, p2[20] = {0}, side = 0;
int p1win = 0, p2win = 0, turn = 0, block = 0;
void instruction();
void enter_name();
void select_turn();
void create();
void display();
void player1();
void player2();
void take_input();
void take_desision_of_block(int *);
void take_desision_of_side(int, int, int, int *);
void process(int, int, int *);
void process_of_a(int, int, int, int *);
void process_of_s(int, int, int, int *);
void process_of_d(int, int, int, int *);
void process_of_w(int, int, int, int *);
void check_corner_side();
void alredy_taken();
void taken_simbol();
void main()
{
    printf("----------------------------------------PREES ANY KEY TO START A GAME----------------------------------------");
    getch();
    instruction();
    enter_name();
    create();
    select_turn();
    turn = -1;
    system("color FA");
    printf("\n\n\n----------------------------------------PREES ANY KEY TO SHOW RESULT OF GAME----------------------------------------");
    display();
    system("color FA");
    if (p1win > p2win)
    {
        printf("\n\n\n\t\t\t\t %s IS WINNER", p1);
    }
    if (p2win > p1win)
    {
        printf("\n\n\n\t\t\t\t %s IS WINNER", p2);
    }
    else
    {
        printf("\n\n\n\t\t\t\t There is tie Between Both Player");
    }
    getch();
}

void instruction()
{
    system("cls");
    printf("------------------------------------instruction-------------------------------------");
    printf("\n-> There is 50 block");
    printf("\n-> Every Block have 4 side");
    printf("\n-> First you have to select any block by thier number");
    printf("\n-> Then After then you can select side out of");
    printf("\n-> There is way to select to side");
    printf("\n-> If you select Top    Side press \"w\"");
    printf("\n-> If you select Bottam Side press \"s\"");
    printf("\n-> If you select Left   Side press \"a\"");
    printf("\n-> If you select Right  Side press \"d\"");
    printf("\n-----------------------------------------------------------------------------------");
    getch();
    system("cls");
}

void enter_name()
{
lable1:
    printf("\nEnter name of player 1:- ");
    scanf("%s", &p1);
    if (p1[0] == 0)
    {
        printf("\nPlz Enter name");
        goto lable1;
    }
lable2:
    printf("\nEnter name of player 2:- ");
    scanf("%s", &p2);
    if (p2[0] == 0)
    {
        printf("\nPlz Enter name");
        goto lable2;
    }
}

void select_turn()
{
    for (int zx = 1; zx < 116; zx++)
    {
        if (turn % 2 == 0)
        {
            turn++;
            player1();
        }
        else
        {
            turn = 0;
            player2();
        }
    }
}

void create()
{
    int user_num = 0, tech_number = 1;
    for (int i = 0; i < 21; i++)
    {
        int c1 = 0, c2 = 0;
        int count = 0;
        for (int j = 0; j < 36; j++)
        {
            if ((j == 0 || count == 6) && i % 2 == 0)
            {
                gmain[i][j] = -7;
                count = 0;
            }
            else
            {
                gmain[i][j] = 32;
                count++;
            }
            if (i % 2 != 0)
            {
                if (j == 3 || c1 == 7)
                {
                    gmain[i][j] = (user_num + 48);
                    c1 = 0;
                }
                if (tech_number % 10 == 0 && tech_number > 0)
                {
                    user_num++;
                    tech_number = 0;
                }
                if (j == 4 || c2 == 8)
                {
                    gmain[i][j] = tech_number + 48;
                    tech_number++;
                    c2 = 1;
                }
            }
            c1++;
            c2++;
        }
    }
}

void display()
{
    system("cls");
    if (turn == 0)
        printf("\t\t\t\t YOUR SIMBOL IS \'%c\'\n", -29);
    else if (turn == 1)
        printf("\t\t\t\t YOUR SIMBOL IS \'%c\'\n", -19);
    for (int i = 0; i < 21; i++)
    {
        for (int j = 0; j < 36; j++)
        {
            printf("%c", gmain[i][j]);
        }
        printf("\n");
    }
}

void player1()
{
    int a = 0;
    system("color 07");
    display();
play1:
    printf("\nnow %s it's your turn", p1);
    take_input();
    take_desision_of_block(&a);
    if (a == 1)
    {
        printf("\nThis is alredy taken please select new");
        a = 0;
        getch();
        goto play1;
    }
}

void player2()
{
    int a = 0;
    display();
    system("color 70");
play2:
    printf("\nnow %s it's your turn", p2);
    take_input();
    take_desision_of_block(&a);
    if (a == 1)
    {
        printf("\nThis is alredy taken please select new");
        a = 0;
        getch();
        goto play2;
    }
}

void take_input()
{
    printf("\nEnter Block Number:- ");
    scanf("%d", &block);
lable3:
    if (block > 50 || block < 1)
    {
        printf("\n Please Enter Valid Input ");
        goto lable3;
    }
lable4:
    printf("\nEnter side:- ");
    fflush(stdin);
    scanf("%c", &side);
    if (side != 'A' && side != 'W' && side != 'S' && side != 'D' && side != 'a' && side != 'w' && side != 's' && side != 'd')
    {
        printf("\n Please Enter Valid Input ");
        goto lable4;
    }
}

void take_desision_of_block(int *a)
{
    int s, b, b1 = 1;
    s = block % 5;
    b = block / 5;
    if (s == 0)
        s = 5;
    else
        b++;
    for (int i = 1; i < b; i++)
        b1 += 2;
    b1--;
    process(b1, s, a);
}

void process(int b1, int s, int *a)
{
    int b2 = 0;
    for (int i = 1; i < s; i++)
    {
        for (int j = 0; j < 7; j++)
            b2++;
    }
    take_desision_of_side(b1, s, b2, a);
}

void take_desision_of_side(int b1, int s, int b2, int *a)
{
    if (side == 'a' || side == 'A')
        process_of_a(b1, s, b2, a);
    else if (side == 's' || side == 'S')
        process_of_s(b1, s, b2, a);
    else if (side == 'd' || side == 'D')
        process_of_d(b1, s, b2, a);
    else
        process_of_w(b1, s, b2, a);
}

void process_of_a(int b1, int s, int b2, int *a)
{
    for (int i = 0; i < 3; i++)
    {
        if (i == 1)
        {
            if (gmain[b1][b2] != 32)
            {
                *a = 1;
                return;
            }
        }
        gmain[b1][b2] = -77;
        b1++;
    }
    check_corner_side();
    taken_simbol();
}

void process_of_s(int b1, int s, int b2, int *a)
{
    for (int j = 0; j < 2; j++)
        b1++;
    for (int i = 0; i < 8; i++)
    {
        if (i == 1)
        {
            if (gmain[b1][b2] != 32)
            {
                *a = 1;
                return;
            }
        }
        gmain[b1][b2] = -60;
        b2++;
    }
    check_corner_side();
    taken_simbol();
}

void process_of_d(int b1, int s, int b2, int *a)
{
    for (int j = 0; j < 7; j++)
        b2++;
    for (int i = 0; i < 3; i++)
    {
        if (i == 1)
        {
            if (gmain[b1][b2] != 32)
            {
                *a = 1;
                return;
            }
        }
        gmain[b1][b2] = -77;
        b1++;
    }
    check_corner_side();
    taken_simbol();
}

void process_of_w(int b1, int s, int b2, int *a)
{
    for (int i = 0; i < 8; i++)
    {
        if (i == 1)
        {
            if (gmain[b1][b2] != 32)
            {
                *a = 1;
                return;
            }
        }
        gmain[b1][b2] = -60;
        b2++;
    }
    check_corner_side();
    taken_simbol();
}

void check_corner_side()
{
    for (int i = 0; i < 21; i++)
    {
        int c1 = 0, c2 = 0;
        int count = 0;
        for (int j = 0; j < 36; j++)
        {
            if ((j == 0 || count == 6) && i % 2 == 0)
            {
                if (i == 0 && j == 0 && gmain[i][j] != -7)
                {
                    gmain[i][j] = -38;
                }
                else if (i == 0 && j == 35 && gmain[i][j] != -7)
                {
                    gmain[i][j] = -65;
                }
                else if (i == 20 && j == 0 && gmain[i][j] != -7)
                {
                    gmain[i][j] = -64;
                }
                else if (i == 20 && j == 35 && gmain[i][j] != -7)
                {
                    gmain[i][j] = -39;
                }
                else if (i == 0 && (j % 7 == 0 && j < 35 && j > 0) && gmain[i][j] != -7)
                {
                    gmain[i][j] = -62;
                }
                else if (i == 20 && (j % 7 == 0 && j < 35 && j > 0) && gmain[i][j] != -7)
                {
                    gmain[i][j] = -63;
                }
                else if ((i % 2 == 0 && i > 0 && i < 20) && j == 0 && gmain[i][j] != -7)
                {
                    gmain[i][j] = -61;
                }
                else if ((i % 2 == 0 && i > 0 && i < 20) && j == 35 && gmain[i][j] != -7)
                {
                    gmain[i][j] = -76;
                }
                else if (gmain[i][j] != -7)
                {
                    gmain[i][j] = -59;
                }
                count = 0;
            }
            else
            {
                count++;
            }
        }
    }
}

void alredy_taken()
{
    int user_num = 0, tech_number = 1;
    for (int i = 0; i < 21; i++)
    {
        int c1 = 0, c2 = 0;
        int count = 0;
        for (int j = 0; j < 36; j++)
        {
            if ((j == 0 || count == 6) && i % 2 == 0)
            {
                gmain[i][j] = -7;
                count = 0;
            }
            else
            {
                gmain[i][j] = 32;
                count++;
            }
            if (i % 2 != 0)
            {
                if (j == 3 || c1 == 7)
                {
                    gmain[i][j] = (user_num + 48);
                    c1 = 0;
                }
                if (tech_number % 10 == 0 && tech_number > 0)
                {
                    user_num++;
                    tech_number = 0;
                }
                if (j == 4 || c2 == 8)
                {
                    gmain[i][j] = tech_number + 48;
                    tech_number++;
                    c2 = 1;
                }
            }
            c1++;
            c2++;
        }
    }
}

void taken_simbol()
{
    for (int i = 0; i < 21; i++)
    {
        int c1 = 0, c2 = 0;
        int count = 0;
        for (int j = 0; j < 36; j++)
        {
            int symbol = 0;
            if ((j == 0 || count == 6) && i % 2 == 0)
            {
                if (gmain[i][j + 1] == -60)
                    symbol++;
                if (gmain[i + 1][j] == -77)
                    symbol++;
                if (gmain[i + 2][j + 1] == -60)
                    symbol++;
                if (gmain[i + 1][j + 7] == -77)
                    symbol++;
                if (symbol == 4)
                {
                    if (turn == 0)
                    {
                        if (gmain[i + 1][j + 3] == -29 || gmain[i + 1][j + 3] == -19)
                            continue;
                        gmain[i + 1][j + 3] = -29;
                        gmain[i + 1][j + 4] = p2[0];
                        turn = 1;
                    }
                    if (turn == 1)
                    {
                        if (gmain[i + 1][j + 3] == -29 || gmain[i + 1][j + 3] == -19)
                            continue;
                        gmain[i + 1][j + 3] = -19;
                        gmain[i + 1][j + 4] = p1[0];
                        turn = 0;
                    }
                }
            }
            else
            {
                count++;
            }
        }
    }
}
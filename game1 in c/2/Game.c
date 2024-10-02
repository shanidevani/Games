#include<stdio.h>
#include<conio.h>
#include<windows.h>

char a[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
char b[30] = {0}, c[30] = {0}, turn;

void p();
void p_1();
void p_2();
int con();
int end();

int main()
{
    system("color 85");
    lable1:
        for (char i = 48; i < 58;i++)
            a[i - 48] = i + 1;
        printf("\n---------------------------- TIK TIK TIO -------------------------\n");
        printf("\n----------- ENTER ANY KEY TO START GAME ------------\n");
        getch();
        lable2:
            printf("\n enter player 1 name :- ");
            scanf("%s", &b);
            if(b[0] == 0)
            {
                printf("\n plz enter player 1 name.");
                goto lable2;
            }
            for (int v = 0; v < 30;v++)
            {
                if((b[v]>=97 && a[v]<=122) || (b[v]>=65 && b[v]<=90) || (b[v]==30) || (b[v]==0))
                {
                    continue;
                }
                else
                {
                    printf("\n plz enter player name in a-z values.");
                    goto lable2;
                }
            }
            lable3:
            printf("\n enter player 2 name :- ");
            scanf("%s", &c);
            if(c[0] == 0)
            {
                printf("\n plz enter player 2 name.");
                goto lable3;
            }
            for (int v = 0; v < 30;v++)
            {
                if((c[v]>=97 && c[v]<=122) || (c[v]>=65 && c[v]<=90) || (c[v]==30) || (c[v]==0))
                {
                    continue;
                }
                else
                {
                    printf("\n plz enter player name in a-z values.");
                    goto lable3;
                }
            }
            if(strcmpi(b,c))
                ;
                else
                {
                    printf("\n this name is allredy exist plz enter diferent name.");
                    goto lable3;
                }
                p();
                for (int i = 1; i < 9;i++)
                {
                    if(i%2==1)
                    {
                        system("color 07");
                        p_1();
                        int n = con();
                        if(n==1)
                        {
                            if(end())
                            {
                                goto lable1;
                            }
                            else
                            {
                                printf("\n\tthanks for playing.");
                                getch();
                                return 0;
                            }
                        }
                    }
                    else
                    {
                        system("color 08");
                        p_2();
                        int n = con();
                        if(n==1)
                        {
                            if(end())
                            {
                                goto lable1;
                            }
                            else
                            {
                                printf("\n\tthanks for playing.");
                                getch();
                                return 0;
                            }
                        }
                    }
                }
                printf("\n\tthe match is going drow bitween %s and %s.", b, c);
                if(end())
                {
                    goto lable1;
                }
                else
                {
                    printf("\n\tthanks for playing.");
                    getch();
                    return 0;
                }
}

void p()
{
    system("cls");
    printf("\n\tsing %s is :- X \n\tsing %s is :- O\n", b, c);
   
    printf("  %c   |  %c   |  %c  \n", a[0], a[1], a[2]);
    printf("______|______|______\n");
    printf("  %c   |  %c   |  %c  \n",a[3],a[4],a[5]);
    printf("______|______|______\n");
    printf("  %c   |  %c   |  %c  \n",a[6],a[7],a[8]);
    printf("      |      |      \n");
}

void p_1()
{
    system("color 09");
    printf("\n\t%s now it's your turn.", b);
    lable4:
        printf("\n\tenter a number bitween 1 to 9 :- ");
        turn = getch();
        if(turn<49 || turn>57)
        {
            p();
            printf("\n\tplz enter a number bitween 1 to 9.");
            goto lable4;
        }
        if(a[turn-49]=='X'||a[turn-49]=='O')
        {
            p();
            printf("\n\tthis number is allredy exist enter new number.");
            goto lable4;
        }
        a[turn - 49] = 'O';
        p();
}

void p_2()
{
    system("color 05");
    printf("\n\t%s npw it's your tune.", c);
    lable5:
        printf("\n\tenter a number bitween 1 to 9 :- ");
        turn = getch();
        if(turn<49 || turn>57)
        {
            p();
            printf("\n\tplz enter a number bitween 1 to 9.");
            goto lable5;
        }
        if(a[turn-49]=='X' || a[turn-49]=='O')
        {
            p();
            printf("\n\tthis number is allredy exist plz enter a new number.");
            goto lable5;
        }
        a[turn - 49] = 'X';
        p();
}

int con()
{
    for (int i = 0; i < 3;i++)
    {
        if(a[i]==a[i+3] && a[i]==a[i+6])
        {
            if(a[i]=='O')
            {
                printf("\n\t%s is won.", b);
                return 1;
            }
            else
            {
                printf("\n\t%s is won.", c);
                return 1;
            }
        }
    }

     for (int i = 0; i < 7;i=i+3)
    {
        if(a[i]==a[i+1] && a[i]==a[i+2])
        {
            if(a[i]=='O')
            {
                printf("\n\t%s is won.", b);
                return 1;
            }
            else
            {
                printf("\n\t%s is won.", c);
                return 1;
            }
        }
    }

     if(a[0]==a[4] && a[0]==a[8])
        {
            if(a[0]=='O')
            {
                printf("\n\t%s is won.", b);
                return 1;
            }
            else
            {
                printf("\n\t%s is won.", c);
                return 1;
            }
        }

         if(a[2]==a[4] && a[2]==a[8])
        {
            if(a[2]=='O')
            {
                printf("\n\t%s is won.", b);
                return 1;
            }
            else
            {
                printf("\n\t%s is won.", c);
                return 1;
            }
        }

        return 0;
}

int end()
{
    printf("\n\t-----------------------------------------------------------------------------------------\n");
    printf("\tENTER SPACE FOR REPLAY GAAME.\n");
    printf("\tENTER ESC FOR ENXIT.\n");
    printf("\n\t-----------------------------------------------------------------------------------------\n");
    lable6:
    printf("\n\tenter your choice :- ");
    char ch = getch();
    if(ch==32 || ch==27)
    {
        if(ch==32)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        system("cls");
        printf("\n\tenter your choice space or esc.");
        goto lable6;
    }
}
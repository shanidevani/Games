#include<conio.h>
#include<stdio.h>
#include<windows.h>
char a[9]={'1','2','3','4','5','6','7','8','9'};
char b[20] ={0}, c[20] = {0},turn;

void print();
void player_1();
void player_2();
int condition();
int end();

int main()
{
    system("color 80"); // this code for add color 
    lable1:  // this code for create a lable for goto statment
        for (char i = 48; i < 58;i++) //this code for start a game
            a[i-48] = i + 1; // this code for cheak 0 to 9 eliments
        printf("\n-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-* TIK TIC TIO *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
        printf("\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- FOR START A GAME PRESS ANY KEY -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
        getch(); // this code for get one element from youger
    lable2:  // this code for create lable for goto startment
        printf("\n enter player 1 name :- "); // this code for getdata from user to user name
        scanf("%s",&b);
        if(b[0]==0) // this code for default user not enter name then what can do user that for him
        {
            printf("\n plz enter player name.");
            goto lable2; // this code for goto statment go bac lable2 
        }
        for (int v = 0; v < 20;v++) // this code for user can enter just a to z values not a number
        {
            if((b[v]>=97 && b[v]<=122) || (b[v]>=65 && b[v]<=90) || (b[v]==32) || (b[v]==0)) // this code for a-z,A-Z values are availabale 
                continue;
            else
            {
                printf("\n plz enter a-z values in your name.");
                goto lable2;
            }
        }
    
    lable3: // this code for create lable3 for goto statment
        printf("\n enter player 2 name :- ");
        scanf("%s", &c);
        if(c[0]==0) // this code for default user not enter name then what can do user that for him
        {
            printf("\n plz enter player name.");
            goto lable3; // this code for goto statment go bac lable2 
        }
        for (int v = 0; v < 20;v++) // this code for user can enter just a to z values not a number
        {
            if((c[v]>=97 && c[v]<=122) || (c[v]>=65 && c[v]<=90) || (c[v]==32) || (c[v]==0)) // this code for a-z,A-Z values are availabale 
            {
                continue;
            }
            else
            {
                printf("\n plz enter a-z values in your name.");
                goto lable3;
            }

        }

        if(strcmpi(b,c))
            ;
            // this code for campar two player name

        else // player name is saim so user havto enter difrent name 
        {
            printf("\nplayer 1 and player 2 name is saim plz enter defrent name.");
            goto lable3; // this code for goto lable3
        }
        print(); // re function call print this funtion is allrady created in out of main function
        for (int i = 1; i < 9;i++) // this loop for result of game
        {
            if(i%2==1)
            {
                system("color 06");
                player_1(); //function call
                int x = condition(); // stor total function return value
                if(x == 1) // cheak function return value is 1 or not
                {
                    if(end()) // this code teak end function return value
                    {
                        goto lable1;    // this code for goto statment
                    }
                    else
                    {
                        printf("\n thanks for playing.");
                        getch();
                        return 0;
                    }
                }
            }
            else
            {
                system("color 09");
                player_2(); // function call
                int x = condition(); // stor  total function return value
                if(x == 1) // cheak function return values is 1 or not
                {
                    if(end()) // this code teak end function return values
                    {
                        goto lable1; // this code for goto statment
                    }
                    else
                    {
                        printf("\n thanks for playing.");
                        getch();
                        return 0;
                    }
                }
            }
        }
        printf("\n match is going drow bitween %S and %s.", b, c);
         if(end()) // this code teak end function return values
        {
            goto lable1;// this code for goto statment
        }
        else
        {
            printf("\n thanks for playing.");
            getch();
            return 0;
        }
}

void print()
{
    system("cls");
    printf("\n\t sing of %s is :- x \n", b);
    printf("\n\t sing of %s is :- o \n",c);
    printf("\n\t color of %s is :- red\n", b);
    printf("\n\t color of %s is :- blue\n\n\n\n", c);
    printf("\n      |       |       \n");
    printf("\n  %c   |  %c   |  %c   \n", a[0], a[1], a[2]);
    
    printf("\n______|______|______\n");
    printf("\n  %c   |  %c   |  %c   \n",a[3],a[4],a[5]);
   
    printf("\n______|______|______\n");
    printf("\n  %c   |  %c   |  %c   \n",a[6],a[7],a[8]);
    printf("\n      |       |       \n");
}

void player_1()
{
    printf("\n\t%s now it is your turn.", b); // this code for remember to user it is your turn
    lable4: // this code for create a lable
        printf("\nenter a number between 1 to 9 :- ");
        turn = getch(); // this code for sai to user enter one number
        if(turn<49 || turn>57) // this code for cheak a number number is bitween 1 to 9
        {
            print(); // this code for function call print
            printf("\nplz enter number bitween 1 to 9.");
            goto lable4; // this code for goto statment
        }
        if (a[turn-49] == 'X' || a[turn-49] == 'O') // this code for campar number with allrady entered number
        {
            print(); // function call
            printf("\n tnis number is allredy exist.");
            goto lable4; // for goto statment
        }
        a[turn-49] = 'O'; // stor value O in a
        print(); // function call
}

void player_2()
{
    printf("\n\t%s now it is your turn.", c); // this code for remember to user it is your turn
    lable5: // this code for create a lable
        printf("\nenter a number between 1 to 9 :- ");
        turn = getch(); // this code for sai to user enter one number
        if(turn<49 || turn>57) // this code for cheak a number number is bitween 1 to 9
        {
            print(); // this code for function call print
            printf("\nplz enter number between 1 to 9.");
            goto lable5; // this code for goto statment
        }
        if (a[turn-49] == 'X' || a[turn-49] == 'O') // this code for campar number with allrady entered number
        {
            print(); // function call
            printf("\n tnis number is allredy exist.");
            goto lable5; // for goto statment
        }
        a[turn-49] = 'X'; // stor value X in a
        print(); // function call
}

int condition()
{
    for (int i = 0; i < 3;i++) // cheak a one result 
    {
        if(a[i] == a[i+3] && a[i] == a[i+6])
        {
            if(a[i] == 'O')
            {
                printf("\n\t %s is won.", b);
                return 1;
            }
            else
            {
                printf("\n\t %s is won.", c);
                return 1;
            }
        }
    }

    for (int i = 0; i < 7;i=i+3) // cheak second resuct
    {
        if(a[i] == a[i+1] && a[i] == a[i+2])
        {
            if(a[i] == 'O')
            {
                printf("\n\t %s is won.", b);
                return 1;
            }
           else
            {
                printf("\n\t %s is won.", c);
                return 1;
            }
        }
    }
    
    if(a[0] == a[4] && a[0] == a[8]) // cheak one result
    {
        if(a[0] == 'O')
        {
            printf("\n\t %s is won.", b);
            return 1;
        }
        else
        {
            printf("\n\t %s is won.", c);
            return 1;
        }
    }
    if(a[2] == a[4] && a[2] == a[6]) // cheak two result
    {
        if(a[2] == 'O')
        {
            printf("\n\t %s is won.", b);
            return 1;
        }
        else
        {
            printf("\n\t %s is won.", c);
            return 1;
        }
    }
    return 0;
}

int end()
{
    printf("\n-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
    printf("\n\n\tFOR PLAY FURTHER HIT 'ENTER' ");
    printf("\n\tFOR EXIT PRESS 'ESC' ");
    printf("\n-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
    lable6:
    printf("\n\t enter your chice :- ");
    char ch=getch();
    if (ch == 13 || ch == 27) // cheak user can enter 'enter' or 'esc'
    {
        if(ch == 13) // cheak enter
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
        printf("\n\tplz hit 'enter' or 'esc'.");
        goto lable6;
    }
}
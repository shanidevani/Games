#include <stdio.h>
#include <conio.h>
#include <windows.h>
char gmain[21][36], p1[20] = {0}, p2[20] = {0}, side = 0;  // gmain for formating
int p1win = 0, p2win = 0, turn = 0, block = 0; // insiazing values
void instruction(); // for intridus to user how to playey this game
void enter_name(); // for enter your ser names
void select_turn(); // for selection of turn
void create(); // for create a formate of game
void display(); // show formate of game
void player1(); // this for player one didatails
void player2(); // this for player two ditaiails
void take_input(); //for get input 
void take_desision_of_block(int *); //for set disision  on blok
void take_desision_of_side(int, int, int, int *); // for set disision on side
void process(int, int, int *); // for process for output
void process_of_a(int, int, int, int *); // for a left said
void process_of_s(int, int, int, int *); // for s botam said
void process_of_d(int, int, int, int *); // for d reigth aid
void process_of_w(int, int, int, int *); // for w up said
void check_corner_side(); // for check condition on side
void alredy_taken(); // if same input values is allredy taken
void taken_simbol(); // for take simboal
void main() // main function
{
    printf("----------------------------------------PREES ANY KEY TO START A GAME----------------------------------------");
    // for start a game
    getch(); // getch function for get one key
    instruction(); // function call
    enter_name(); // function call
    create(); // function call
    select_turn(); // function call
    turn = -1; // insilaize values of turn
    system("color FA"); // set color on screean
    printf("\n\n\n----------------------------------------PREES ANY KEY TO SHOW RESULT OF GAME----------------------------------------");
    // get one key for get your result
    display(); // function call
    system("color FA"); // set color
    if (p1win > p2win) // if p1 is big then p1 is win 
    {
        printf("\n\n\n\t\t\t\t %s IS WINNER", p1);
    }
    if (p2win > p1win) // if p2 is big then p2 is win
    {
        printf("\n\n\n\t\t\t\t %s IS WINNER", p2);
    }
    else // if p2 and p1 is saim then tie
    {
        printf("\n\n\n\t\t\t\t There is tie Between Both Player");
    }
    getch(); // get one key
}

void instruction() // function process
{
    system("cls"); // for clrscr
    printf("------------------------------------instruction-------------------------------------");
    //instruction for user
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
    getch(); //get one key
    system("cls"); // for clrscr
}

void enter_name() // function process
{
lable1: // create a lable1
    printf("\nEnter name of player 1:- ");
    scanf("%s", &p1);// get first user ditails
    if (p1[0] == 0) // for chek p1 is not empty
    {
        printf("\nPlz Enter name");
        goto lable1; // if p1 is empty then goto lable1
    }
lable2: // create a lable2
    printf("\nEnter name of player 2:- ");
    scanf("%s", &p2); // get second user ditails
    if (p2[0] == 0) // for chek p2 is not empty
    {
        printf("\nPlz Enter name");
        goto lable2; // if p2 is empty then goto lable2
    }
}

void select_turn() // function proess
{ 
    for (int zx = 1; zx < 116; zx++) //zx start with 1 and less then 116 and par process +1 inzx
    {
        if (turn % 2 == 0)  //if turn value is even then enter in if loop
        {
            turn++; // +1 in turn
            player1(); // goto player1 function 
        }
        else  // if turn value is not even then enter else part
        {
            turn = 0;  // insilaize turn into 0
            player2(); // then goto player2 function
        }
    }
}

void create() // function process
{
    int user_num = 0, tech_number = 1; // enter sum data
    for (int i = 0; i < 21; i++) // i start with 0 and i less then 21 and par process  incris i to 1
    {
        int c1 = 0, c2 = 0; // get sum data
        int count = 0; // get sum data
        for (int j = 0; j < 36; j++) // j starrt with 0 and less then 36 and par process  incris j to 1  
        {
            if ((j == 0 || count == 6) && i % 2 == 0) // if j in 0 or count is 6 and i is even then enter if loop
            {
                gmain[i][j] = -7; // gmaun is -7
                count = 0; // count insilaize with 0
            }
            else 
            {
                gmain[i][j] = 32; // gmain is 32
                count++; // count +1
            }
            if (i % 2 != 0) // if i is  not even number
            {
                if (j == 3 || c1 == 7) // if j is 3 or c1 is 7 then enter if loop
                {
                    gmain[i][j] = (user_num + 48); // gmain is user_num + 48
                    c1 = 0; // and c1 is 0
                }
                if (tech_number % 10 == 0 && tech_number > 0) // if tech_number is / by 10 then ansver is 0 and tech_number is greter then 0
                {
                    user_num++; // suer_num +1
                    tech_number = 0; // tech_number is 0
                }
                if (j == 4 || c2 == 8) // if j =4 or c2 is 8
                {
                    gmain[i][j] = tech_number + 48; // gmain is tech_number + 48
                    tech_number++; // tech_number +1
                    c2 = 1; // c2 is 1
                }
            }
            c1++; // c1 +1
            c2++; // c2 +1
        }
    }
}

void display() // function process
{
    system("cls"); // for clrscr
    if (turn == 0) // if turn is 0
        printf("\t\t\t\t YOUR SIMBOL IS \'%c\'\n", -29); // your simbol is pai
    else if (turn == 1) // if turn is 1 then
        printf("\t\t\t\t YOUR SIMBOL IS \'%c\'\n", -19); // your simbol is p
    for (int i = 0; i < 21; i++) // i start with 0 and less then 21 and par process i is i+1
    {
        for (int j = 0; j < 36; j++) // j start with 0 and j is less then 36 and par process j is j+1
        {
            printf("%c", gmain[i][j]); 
        }
        printf("\n");
    }
}

void player1() // function process
{
    int a = 0; // new data
    system("color 07"); // set syastem color
    display();// goto display function
play1: // player one
    printf("\nnow %s it's your turn", p1);
    take_input(); // goto take_input function
    take_desision_of_block(&a); // goto take_desision_of_block function with address of a
    if (a == 1) // if a is 1 then
    {
        printf("\nThis is alredy taken please select new");
        a = 0; // a is 0
        getch(); // get one key
        goto play1; // goto player one data
    }
}

void player2() // funcion process
{
    int a = 0; // new  data
    display(); // goto display function
    system("color 70"); // set system color 
play2: // for goto statment
    printf("\nnow %s it's your turn", p2);
    take_input(); // goto take_input function
    take_desision_of_block(&a); // goto take_desision_of_block function with address of a
    if (a == 1) // if a is 1 then
    {
        printf("\nThis is alredy taken please select new");
        a = 0; // a is 0
        getch(); // for get one key
        goto play2; // go bak to player 2
    }
}

void take_input() // function process
{ 
    printf("\nEnter Block Number:- ");
    scanf("%d", &block);
lable3: // create a lable for goto statment
    if (block > 50 || block < 1) //  if block is greter then 50 or block is less then 1 then
    {
        printf("\n Please Enter Valid Input ");
        goto lable3; // go back to lable3
    }
lable4: // create a lable for goto statment
    printf("\nEnter side:- ");
    fflush(stdin); // goto fflush function with stdin value
    scanf("%c", &side); 
    if (side != 'A' && side != 'W' && side != 'S' && side != 'D' && side != 'a' && side != 'w' && side != 's' && side != 'd') // for chek user enter value is w,s,a,d
    {
        printf("\n Please Enter Valid Input ");
        goto lable4; // if not then go back to lable4
    }
}

void take_desision_of_block(int *a) // function process
{
    int s, b, b1 = 1; // get new data
    s = block % 5; // s is equal to block % 5
    b = block / 5; // b is equal to block divaided by 5
    if (s == 0) // if s is equal to 0
        s = 5; // s is equal to 5
    else
        b++; // b is equal to b+1
    for (int i = 1; i < b; i++) // i is start with 1 and i is increis less then b and par process incris i with 1
        b1 += 2; // b1 is + and equal to 2
    b1--; // b1 is equal to b-1
    process(b1, s, a); // goto process function with values of b1,s and a
}

void process(int b1, int s, int *a) // function process
{
    int b2 = 0; // get new data
    for (int i = 1; i < s; i++) // i is start with 1 and i is incris less then s and par process intcris i into 1
    {
        for (int j = 0; j < 7; j++) // j is start with 0 and j is incris less then 7 and par process incris j into 1
            b2++; // b2 is euqal to b1+1
    }
    take_desision_of_side(b1, s, b2, a); // goto take_disision_of_side function with values of b1,s,b2 and a
}

void take_desision_of_side(int b1, int s, int b2, int *a) // function process
{
    if (side == 'a' || side == 'A') // if side is equal a or side is equal to A then
        process_of_a(b1, s, b2, a); // goto process_of_a function with b1,s,b2 and a 
    else if (side == 's' || side == 'S') // if side is equal s or side is equal S then
        process_of_s(b1, s, b2, a); // goto process_of_s function with b1,s,b2 and a 
    else if (side == 'd' || side == 'D') // if side is equal d or side is equal D then
        process_of_d(b1, s, b2, a); // goto process_of_d function with b1,s,b2 and a 
    else
        process_of_w(b1, s, b2, a); // goto process_of_w function with b1,s,b2 and a 
}

void process_of_a(int b1, int s, int b2, int *a) // function process
{
    for (int i = 0; i < 3; i++) // i is start  with 0 and i is incris mor then 3 and par process is is incris by 1
    {
        if (i == 1) // if i is equal to 1
        {
            if (gmain[b1][b2] != 32) // if gmain is not equal to 32
            {
                *a = 1; // address of a is equal to 1
                return;
            }
        }
        gmain[b1][b2] = -77; // gmain is equal to -77
        b1++; // b1 is equal b1+1
    }
    check_corner_side(); // goto check_corner_side function
    taken_simbol(); // goto taken_simbol function
}

void process_of_s(int b1, int s, int b2, int *a) // function process
{
    for (int j = 0; j < 2; j++) // j is start ith 0 and j is incris mor then 2 and par process incris j by 1
        b1++; // b1 is equal to b1+1
    for (int i = 0; i < 8; i++) // i is start with 0 and i is incris moar then 8 and par process incrics i by 1
    {
        if (i == 1) // if i  is equal to 1
        {
            if (gmain[b1][b2] != 32) // if gmain is not equal to 32
            {
                *a = 1; // address of a is equal to 1
                return;
            }
        }
        gmain[b1][b2] = -60; // gmain is equal to -60
        b2++; // b2 is equal to b2+1
    }
    check_corner_side(); // goto check_corner_side function
    taken_simbol(); // goto taken_simbol function
}

void process_of_d(int b1, int s, int b2, int *a) // function process
{
    for (int j = 0; j < 7; j++) // j is start with 0 and j is increas mor then 7 and par process incris j by 1
        b2++; // b2 is equal to b2+1
    for (int i = 0; i < 3; i++) // i is start with 0 and i is incris mor then 3 and par process incris i by 1
    {
        if (i == 1) // if i is equal to 1
        {
            if (gmain[b1][b2] != 32) // gmain in not equal to 32
            {
                *a = 1; // address of a is equal to 
                return;
            }
        }
        gmain[b1][b2] = -77; // gmain is equal to -77
        b1++; // b1 is equal to b1+1
    }
    check_corner_side(); // goto check_corner_side function
    taken_simbol(); // goto taken_simbol function
}

void process_of_w(int b1, int s, int b2, int *a) // function process
{
    for (int i = 0; i < 8; i++) // i is start with 0 and i is incris mor then 8 and par process incris i by 1
    {
        if (i == 1)// if i is equal to 1
        {
            if (gmain[b1][b2] != 32)// if gmain is not equal to 32
            {
                *a = 1; // address of is equal to 1
                return;
            }
        }
        gmain[b1][b2] = -60; // gmain is equal to -60
        b2++; // b2 is equal to b2+1
    }
    check_corner_side(); // goto check_corner_side function
    taken_simbol(); // goto taken_simbol function
}

void check_corner_side() // function process
{
    for (int i = 0; i < 21; i++) // i is start with 0 and i is incris mor then 21 and par process incris i by 1
    {
        int c1 = 0, c2 = 0; // get new data
        int count = 0; // get new data
        for (int j = 0; j < 36; j++) // j is start with 0 and j is incris mor then 36 and par process incris j by 1
        {
            if ((j == 0 || count == 6) && i % 2 == 0) // if j is equal to 0 or count is equal to 6 and  is even number
            {
                if (i == 0 && j == 0 && gmain[i][j] != -7) // if i is equal to 0 and j is equal to 0 and gmain is not equal to -7
                {
                    gmain[i][j] = -38; // gmain is equal to -38
                }
                else if (i == 0 && j == 35 && gmain[i][j] != -7) // if i is equal to 0 and j is equal to 35 and gmain is not equal to -7
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
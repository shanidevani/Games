#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>



int a,b;
int total=0;


char x;

// function prototype declaration
// Function prototype declaration
void addition();
void subtraction();
void multiplication();
void division();

void print(); // for print calculator



// start of main program

int main()
{
    system("color 90");
    
        printf("\n-*-*-*-*-*-*-*-*-*-*-* CALCULATOR -*-*-*-*-*-*-*-*-*-*-*");
        printf("\n-*-*-*-*-*-*-*- START CALCULATOR PRESS ANY KEY -*-*-*-*-*-");
        getch();

    lable1:
        print();
         printf("enter sing :- ");
            
        while(1)
        {
            x = getch();
            switch (x)
            {
            case '+': addition();
            goto lable1;
                        break;

            case '-': subtraction();
            goto lable1;
                        break;

            case '*': multiplication();
            goto lable1;
                        break;

            case '/': division();
            goto lable1;
                        break;

            case 'Q':
            case 'q': exit(0);
                        break;

            case 'c':
            case 'C': system("cls");
                print();
                break;

            default : system("cls");
        }
    }
        
}

void print()
{
    system("cls");
        printf("Enter +  for Addition \n");
        printf("Enter -  for Subtraction \n");
        printf("Enter *  for Multiplication \n");
        printf("Enter /  for Division \n");
        
        
        
        printf("*-*-*-*-* Press 'Q' or 'q' to quit the program *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-");
        printf("\n");
        
        printf("*-*-*-*-* Enter 'C' or 'c' to clear the screen and display available option *-*-*-*-*");
        printf("\n");

        
        printf("\n  1   |   2   |   3   |   *\n");
        printf("\n  4   |   5   |   6   |   -\n");
        printf("\n  7   |   8   |   9   |   +\n");
        printf("\n  C   |   0   |   .   |   /\n");       
        
}

void addition()
{
    printf("\n");
    printf("first value :- ");
    scanf("%d", &a);
    printf("second value :- ");
    scanf("%d", &b);
    total = a + b;
    printf("result :- %d",total);
    getch();   
}

void subtraction()
{ 
    printf("\n");
    printf("first value :- ");
        scanf("%d",&a);
        printf("second value :- ");
        scanf("%d",&b);
    total = a - b;
    printf("result :- %d",total);
    getch();
}

void multiplication()
{
    printf("\n");
    printf("first value :- ");
        scanf("%d",&a);
        printf("second value :- ");
        scanf("%d",&b);
    total = a * b;
    printf("result :- %d",total);
    getch();
}

void division()
{
    printf("\n");
    printf("first value :- ");
        scanf("%d",&a);
        printf("second value :- ");
        scanf("%d",&b);
    total = a / b;
    printf("result :- %d",total);
    getch();
}






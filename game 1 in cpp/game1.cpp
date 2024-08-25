#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<windows.h>
using namespace std;
char a[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
char b[30], c[30], turn;


class p1
{
	public:
		void p();
};

void p1::p()
{
    system("cls");
    system("color 70");
    
    cout << "\tsing of " << b << "is :- X\n\tsing of" << c << "is :- O" << endl;

    cout << "\t   " << a[0] << "  |   " << a[1] << "  |   " << a[2] << "  " << endl;
    cout << "\t______|______|______" << endl;
    cout << "\t   " << a[3] << "  |   " << a[4] << "  |   " << a[5] << "  " << endl;
    cout << "\t______|______|______" << endl;
    cout << "\t   " << a[6] << "  |   " << a[7] << "  |   " << a[8] << "  " << endl;
    cout << "\t      |      |      " << endl;
}

class player1:public p1
{
	public:
		void p_1();
};

void player1::p_1()
{
    system("color 10");
    cout <<"\n\t"<< b<<" it's yours turn."<<endl;

    lable4:
	cout<<"\n\tenter a number bitween 1 to 9 :- "<<endl;
	turn = getch();
	if(turn<49 || turn>57)
	{
	    p1::p();
	    cout<<"\n\tplz enter a number bitween 1 to 9."<<endl;
	    goto lable4;
	}
	if(a[turn-49]=='X'||a[turn-49]=='O')
	{
	    p1::p();
	    cout<<"\n\tthis number is allredy exist enter new number."<<endl;
	    goto lable4;
	}
	a[turn - 49] = 'O';
	p1::p();

}

class player2:public p1
{
	public:
		void p_2();
};

void player2::p_2()
{
    system("color 09");
    cout <<"\n\t"<< c<<" it's yours turn."<<endl;

    lable5:
	cout<<"\n\tenter a number bitween 1 to 9 :- "<<endl;
	turn = getch();
	if(turn<49 || turn>57)
	{
	    p1::p();
	    cout<<"\n\tplz enter a number bitween 1 to 9."<<endl;
	    goto lable5;
	}
	if(a[turn-49]=='X'||a[turn-49]=='O')
	{
	    p1::p();
	    cout<<"\n\tthis number is allredy exist enter new number."<<endl;
	    goto lable5;
	}
	a[turn - 49] = 'x';
	p1::p();

}

class condition
{
	public:
		int con();
};

int condition::con()
{
    for (int i = 0; i < 3;i++)
    {
	if(a[i]==a[i+3] && a[i]==a[i+6])
	{
	    if(a[i]=='O')
	    {
		cout<<"\n\t"<<c<<" is won."<<endl;
		return 1;
	    }
	    else
	    {
		cout<<"\n\t"<<c<<" is won."<<endl;
		return 1;
	    }
	}
    }

     for (int j = 0; j < 7;j=j+3)
    {
	if(a[j]==a[j+1] && a[j]==a[j+2])
	{
	    if(a[j]=='O')
	    {
		cout<<"\n\t"<<c<<" is won."<<endl;
		return 1;
	    }
	    else
	    {
		cout<<"\n\t"<<c<<" is won."<<endl;
		return 1;
	    }
	}
    }

     if(a[0]==a[4] && a[0]==a[8])
	{
	    if(a[0]=='O')
	    {
		cout<<"\n\t"<<c<<" is won."<<endl;
		return 1;
	    }
	    else
	    {
		cout<<"\n\t"<<c<<" is won."<<endl;
		return 1;
	    }
	}

	 if(a[2]==a[4] && a[2]==a[8])
	{
	    if(a[2]=='O')
	    {
		cout<<"\n\t"<<c<<" is won."<<endl;
		return 1;
	    }
	    else
	    {
		cout<<"\n\t"<<c<<" is won."<<endl;
		return 1;
	    }
	}

	return 0;
}

class en
{
	public:
		int end();
};

int en::end()
{
    cout<<"\n\t-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n";
    cout<<"\tENTER SPACE FOR REPLAY GAAME.\n";
    cout<<"\tENTER ESC FOR ENXIT.\n";
    cout<<"\n\t-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n";
    lable6:
    cout<<"\n\tenter your choice :- ";
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
	
	cout<<"\n\tenter your choice space or esc.";
	goto lable6;
    }
}

int main()
{
	p1 q;
    player1 r1;
    player2 r2;
    condition c1;
    en e1;
    system("color 70");
    lable1:
	for (char i = 48; i < 58;i++)
	    a[i - 48] = i + 1;
	cout<<"\n-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-* TIK TIC TIO *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n";
	cout<<"\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- FOR START A GAME PRESS ANY KEY -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n";
	getch();
	lable2:
	    cout<<"\n enter player 1 name :- ";
	    cin>>b;
	    if(b[0] == 0)
	    {
		cout<<"\n plz enter player 1 name.";
		goto lable2;
	    }
	    for (int v = 0; v < 30;v++)
	    {
		if((b[v]>=97 && b[v]<=122) || (b[v]>=65 && b[v]<=90) || (b[v]==30) || (b[v]==0))
		{
		    continue;
		}
		else
		{
		    cout<<"\n plz enter player name in a-z values.";
		    goto lable2;
		}
	    }
	    lable3:
	    cout<<"\n enter player 2 name :- ";
	    cin>>c;
	    if(c[0] == 0)
	    {
		cout<<"\n plz enter player 2 name.";
		goto lable3;
	    }
	    for (int e = 0; e < 30;e++)
	    {
		if((c[e]>=97 && c[e]<=122) || (c[e]>=65 && c[e]<=90) || (c[e]==30) || (c[e]==0))
		{
		    continue;
		}
		else
		{
		    cout<<"\n plz enter player name in a-z values.";
		    goto lable3;
		}
	    }
	    if(strcmpi(b,c));
		else
		{
		    cout<<"\n this name is allredy exist plz enter diferent name.";
		    goto lable3;
		}
		q.p();
		for (int j = 1; j < 9;j++)
		{
		    if(j%2==1)
		    {
			system("color 07");
			r1.p_1();
			int n = c1.con();
			if(n==1)
			{
			    if(e1.end())
			    {
				goto lable1;
			    }
			    else
			    {
				cout<<"\n\tthanks for playing.";
				getch();
				return 0;
			    }
			}
		    }
		    else
		    {
			system("color 08");
			r2.p_2();
			int n = c1.con();
			if(n==1)
			{
			    if(e1.end())
			    {
				goto lable1;
			    }
			    else
			    {
				cout<<"\n\tthanks for playing.";
				getch();
				return 0;
			    }
			}
		    }
		}
		cout<<"\n\tthe match is going drow bitween"<<b<<" and"<<c<<".";
		if(e1.end())
		{
		    goto lable1;
		}
		else
		{
		    cout<<"\n\tthanks for playing.";
		    getch();
		    return 0;
		}
}
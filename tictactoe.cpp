#include<iostream>
#include<stdlib.h>
#include <stdio.h>

using namespace std;

int check();                  //finds the winner
bool checkhor();              //horizontal check
bool check_ver();             //vertical check
bool check_diag();            //diagonal check
bool checkdraw();

void playermove();
void compmove();
void display();


char tictac[3][3];

int main()
{

	for(int i = 0; i < 3; i++)
		for(int j = 0; j < 3; j++)
				tictac[i][j]=' ';

	display();

    //random starting of the game depending on d
    int d = rand() % 2;
	(d==0)? playermove() : compmove();

	system("pause");

	return 0;
}

void display()
{
	for(int r = 0; r < 3; r++) {
		cout<<"		" << tictac[r][0] << " | " << tictac[r][1] << " | " << tictac[r][2] << endl;
        if(r != 2)
	    cout<< "		--|---|--"<< endl;
	}
}

void disp_after_move();

void playermove()
{
    int x;
    int y;
	cout << "Enter the coordinates (x, y) To PUT 'X' where  0 <= (x, y) <= 2  ";
	cin >> x >> y;
	//check for valid co-ordinates
	if((x < 0) || (x > 2 ) && (y < 0) || (y > 2)) {
		cout<<"enter correct coordinates";
		playermove();
	} else	{
		//check for vacant space at entered co-ordinates

		if(tictac[x][y] == ' ')    {
			tictac[x][y] = 'X';  //assigning playermove 'X' to the co-ordinates
			disp_after_move();
		} else {
				cout<<"Choose other coordinates as  current position is filled " << endl;
				playermove();
		}
	}
	int flag = check();
	if(flag == 0)
			compmove();
	else {
		cout<<"	YOU ARE THE WINNER" << endl;
    	system("pause");
		exit(1);
	}
}
//displays new tictactoe after playermove or compmove turn

void disp_after_move()
{
    cout << endl;
	for(int t = 0;t < 3; t++) {
	 	cout<<"		"<<tictac[t][0]<<" | "<<tictac[t][1]<<" | "<<tictac[t][2]<<endl;
		if(t != 2)
			cout<<"		--|---|--"<<endl;
	}
	cout << endl;
}
void compmove()
{
    int x;
    int y;
    cout<<"THIS IS THE COMPUTER'S MOVE " << endl;

    for(int i = 0; i <= 20; i++) {
        x = rand() % 3;
        y = rand() % 3;
        //check for vacant space at entered co-ordinates
        if(tictac[x][y] == ' ')  {
            tictac[x][y]='O';  //assigning compmove 'O' to the co-ordinates
            break;
		} else continue;
	}
    disp_after_move();
    int flag = check();
    if(flag == 0)
        playermove();
    else
	{
        cout<<"I'M THE WINNER" << endl;
        system("pause");
	    exit(1);
	}
}

int check()
{
    bool hor = checkhor();
    bool ver = check_ver();
    bool diag = check_diag();
    bool draw = checkdraw();

    if (draw && (hor == 0 && ver == 0 && diag == 0)) {
        cout << "Its a tie !! No one is a winner " << endl;
        exit(1);
    }

    return (hor || ver || diag);
}
bool checkdraw()
{
    bool ans = 1;
    for (int r = 0; r < 3; r++)
        for (int c = 0; c < 3; c++)
                ans = ans && (tictac[r][c] != ' ');

    return ans;

}
//checks each element of a horizontal line / vertical / diagnal tobe same
//returns 1 if all 3 elements of any horizontal line/vertical/ diagonal are same else returns 0
bool checkhor()
{
    int flag;

	if(((tictac[0][0] == tictac[0][1]) && (tictac[0][1] == tictac[0][2]) && (tictac[0][1] != ' ')) || ((tictac[1][0] == tictac[1][1]) && (tictac[1][1] == tictac[1][2]) && (tictac[1][1] != ' ')) || ((tictac[2][0] == tictac[2][1]) && (tictac[2][1] == tictac[2][2]) && (tictac[2][2] != ' ')))

		flag=1;
	else

		flag=0;

	return flag;
}

bool check_ver()
{
	int flag;
	if(((tictac[0][0] == tictac[1][0]) && (tictac[1][0] == tictac[2][0]) && (tictac[0][0] != ' ')) || ((tictac[0][1] == tictac[1][1]) && (tictac[1][1] == tictac[2][1]) && (tictac[0][1] != ' ')) || ((tictac[0][2] == tictac[1][2]) && (tictac[1][2] == tictac[2][2]) && (tictac[0][2]!=' ')))
		flag = 1;
	else
		flag = 0;

	return flag;
}

bool check_diag()
{
	int flag;
	if(((tictac[0][0] == tictac[1][1])&& (tictac[1][1] == tictac[2][2]) && (tictac[0][0] != ' ')) || ((tictac[0][2] == tictac[1][1]) && (tictac[1][1] == tictac[2][0]) && (tictac[1][1] != ' ')))

		flag = 1;
	else

		flag = 0;

    return flag;
}

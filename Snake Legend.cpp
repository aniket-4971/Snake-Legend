#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <unistd.h>
#include <windows.h>
#include <time.h>
using namespace std;
//Snake Legend
bool gameover;  
const int width = 20;
const int height = 20;

enum Direction{
	Stop =0,
	Left,Right,Up,Down
};
Direction dir;
int x,y,Fruit_x,Fruit_y,score=0;

int tailX[500],tailY[500];
int tailL=0;
void Setup()
{
    gameover = false;
    dir = Stop;
    x = width/2;
    y = height/2;
    Fruit_x = rand()%width;
    Fruit_y = rand()%height;
    
		
}
void Draw()
{
	system("cls");
	for(int i=0; i< width+2; i++)
	{
		cout<<"* ";
	}
	cout<<endl;
	
	for(int j=0; j< height; j++)
	{
		cout<<"* ";
	for(int i=0; i< width; i++)
	{
		
		if(j== y && i == x)
		{
			cout<<"O ";
		}
		else if(j == Fruit_y && i == Fruit_x)
		{
			cout<<"@ ";
		}
		else
		{
			int z = 1;
			for(int k = 0; k< tailL; k++)
			{
				if(tailX[k] == i && tailY[k] == j)
				{
					cout<<"o ";
					z = 0;
				}
			}
			if(z)
			{
				cout<<"  ";	
			}
	
		}
	}
	cout<<"* ";
	cout<<endl;	
	}
		for(int i=0; i< width+2; i++)
	{
		cout<<"* ";
	}
	
}

void Input()
{
	if(_kbhit())
	{
		switch(_getch())
		{
			case 'a':
				dir = Left;
				break;
			case 'w':
			    dir = Up;
				break;
			case 'd':
			    dir = Right;
			    break;
			case 's':
			    dir = Down;
				break;
			case 'x':
			    gameover = true;
				break;				
		}
	}
}
void Logic()
{
	int prevX = tailX[0];
	int prevY = tailY[0];
	int prev2X,prev2Y;
	tailX[0]= x; tailY[0]= y;
	for(int i=1; i< tailL; i++ )
	{
		prev2X = tailX[i];
		prev2Y = tailY[i];
		tailX[i] = prevX;
		tailY[i] = prevY;
		prevX = prev2X;
		prevY = prev2Y;
	}
	switch(dir)
		{
			case Left:
				x--;
				break;
			case Right:
			    x++;
				break;
			case Up:
			    y--;
			    break;
			case Down:
			    y++;
				break;
					
		}	
		int k = tailL-1;
		int temp = 0;
		while(k!= -1)
		{
		   if(tailX[k] == x && tailY[k] == y)
		   {
		   	temp = 1;
		   	break;
			   }
			   k--;	
		}
		if(x> width || x< -1|| y>height || y< -1  || temp == 1)
		{
			
			gameover = true;
			
		}
		else if(x == Fruit_x && y== Fruit_y)
		{
			score += 5;
			 Fruit_x = rand()%width;
              Fruit_y = rand()%height;
              tailL++;
		}
		
}
void Delay(int milli_second)
{
	int start_time = clock();
	while(clock() < start_time+milli_second);
}
int main()
{
	cout<<"          WELCOME TO SNAKE LEGEND"<<endl;
	
	Delay(7000);
	system("cls");
	Setup();
	while(!gameover)
    {
    	Draw();
    		cout<<endl<<"Score: "<<score<<endl;
    	Delay(100);
    	Input();
    	Logic();
    
    	
	}
	system("cls");
	cout<<"Game Over"<<endl<<"Final Score: "<<score<<endl;
}

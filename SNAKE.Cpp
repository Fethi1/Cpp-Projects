#include<iostream>
#include<conio.h>
#include<ctime>
#include<windows.h>

using namespace std;

bool GameOver;
const int width = 20;
const int height = 20;
int x ,y, FruitX, FruitY, Score;
int tailX[100], tailY[100];
int nTail;

enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN};
eDirection dir;
void setUp()
{
  GameOver = 0;
  dir = STOP;
  x = width/2;
  y = height/2;
  FruitX = rand() % width;
  FruitY = rand() % height;
  Score  = 0;
}
void Draw()
{
    // remove the blinking
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {0,0});
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = false;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);

    for(int i = 0; i < width+1; i++)
     cout<< "#";
  cout << endl;

  for(int i = 0; i < height; i++)
  {
   for(int j = 0; j < width; j++)
   {
     if(j == 0 || j == width - 1)
        cout<< "#";
     if(i == y && j == x)
        cout<<"O";
     else if(i == FruitY && j == FruitX)
        cout<<"*";
     else
        {
         bool print = false;
         for(int k = 0; k < nTail; k++)
         {
            if(tailX[k] == j && tailY[k] == i)
                {
                cout <<"o";
                print = true;
                }
         }
             if(!print)
              cout<<" ";

             }

  }
  cout<<endl;
  }
  for(int i = 0; i < width+1; i++)
    cout<< "#";
  cout << endl;
  cout <<"Total Score: "<<Score<<endl;
}
void Input()
{
  if(_kbhit())
  {
      switch(_getch())
      {
      case 'z' :
        dir = UP;
        break;
      case 'q' :
        dir = LEFT;
        break;
      case 'd' :
        dir = RIGHT;
        break;
      case 's' :
        dir = DOWN;
        break;
      case 'x' :
        GameOver = 1;
        break;
      }
  }
}
void Logic()
{
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = x;
    tailY[0] = y;
    for(int i = 1; i < nTail; i++)
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
  case UP :
         y-- ;
        break;
  case LEFT :
          x-- ;
        break;
  case RIGHT :
          x++ ;
        break;
   case DOWN :
          y++ ;
        break;
  }
  /* this end the game when you touch the wall
   if(x > width || x < 0 || y > height || y < 0)
    GameOver = true;*/
    //if you the snake to appear on the other side and not die, use this :
    if (x > width)
        x = x - width;
    if (x < 0)
        x = x + width;
    if (y > height)
        y = y - height;
    if ( y < 0)
        y = y + height;
    for(int i = 0; i < nTail; i++)
    {
        if(tailX[i] == i && tailY[i] == y)
            GameOver = true;
    }
   if(x == FruitX && y == FruitY)
   {
       Score += 10;
       FruitX = rand() % width;
       FruitY = rand() % height;
       nTail++ ;
   }
    /*
    if you the snake to appear on the other side and not die, use this :
    if (x > width)
        x = x - width;
    if (x < 0)
        x = x + width;
    if (y > height)
        y = y - height;
    if ( y < 0)
        y = y + height;*/



}
void speed(int a)
{

    if(a == 0)
  Sleep(50);
  else if (a == 1)
    Sleep(35);
  else
    Sleep(10);

}
int main()
{
    int a;
    cout<<"choose game speed:\n";
    cout<<"[0] for slow \n [1] for medium \n [2] for fast \n";
    do {
            cin>> a;
    }while(a < 0 && a > 2);

    setUp();
    while(!GameOver)
    {
        Draw();

        if (dir == LEFT || dir == RIGHT && a == 0)
 {
    speed(a);
 }

Sleep(100);

if (dir == UP || dir == DOWN)
 {
  speed(a);
 }

        Input();
        Logic();

    }
}

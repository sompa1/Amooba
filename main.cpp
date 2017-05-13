#include "graphics.hpp"
#include "widgets.hpp"
#include "examplecheckbox.hpp"
#include "statictext.hpp"
#include "texteditor.hpp"
#include "window.hpp"
#include "pushbutton.hpp"
#include <vector>
#include <stdlib.h>
#include <iostream>

using namespace std;
using namespace genv;
const int boardSize=20;
const int fieldSize=30;

///////////////////////////////////////////////////
class MyWindow : public Window {
private:
    int board[boardSize][boardSize];
public:
    MyWindow()
    {
        createBoard();
   }

   void createBoard()
   {
       widgets.clear();
       int posx=0;
        int posy=0;
		for (int i=0; i<boardSize; i++)
        {
            for (int j=0; j<boardSize; j++)
            {
                widgets.push_back(new ExampleCheckBox(this,posx,posy,fieldSize,fieldSize,i,j));
                posx=posx+fieldSize;
                board[i][j]=-1;
            }
            posy=posy+fieldSize;
            posx=0;
        }
   }

   void pushButtonCall()
   {
       createBoard();
   }

    void ellenoriz(int x, int y, int s)
    {

        board[x][y]=s;
        int sCount=0;

        // sorok ellenõrzése
        for (int i=0; i<=7; i++)
        {
            sCount = 0;
            for (int j=i; j<=i+4; j++)
            {
                if (board[x][j]==s)
                {
                    sCount ++;
                }
            }
            if (sCount==5)
            {
                widgets.push_back(new PushButton(this, 300, 300, 50,25, "Nyertél", "winButton", s));
                return;
            }
        }

        // oszlopok ellenõrzése
        for (int i=0; i<=7; i++)
        {
            sCount = 0;
            for (int j=i; j<=i+4; j++)
            {
                if (board[j][y]==s)
                {
                    sCount ++;
                }
            }
            if (sCount==5)
            {
               widgets.push_back(new PushButton(this, 300, 300, 50,25, "Nyertél", "winButton", s));
                return;
            }
        }

        // fõátló fölött
        for (int i=0; i<boardSize; i++)
        {
            sCount=0;
            int diagX=i;
            int diagY=0;
            while (diagX>=0 && diagY<boardSize)
            {
                if (board[diagX][diagY]==s)
                {
                    sCount++;
                }
                diagX--;
                diagY++;
            }
             if (sCount==5)
            {
               widgets.push_back(new PushButton(this, 300, 300, 50,25, "Nyertél", "winButton", s));
                return;
            }
        }

        // fõátló alatt
        for (int i=11; i>=0; i--)
        {
            sCount=0;
            int diagX=i;
            int diagY=boardSize-1;
            while (diagX<boardSize && diagY>=0)
            {
                if (board[diagX][diagY]==s)
                {
                    sCount++;
                }
                diagX++;
                diagY--;
            }
             if (sCount==5)
            {
                widgets.push_back(new PushButton(this, 300, 300, 50,25, "Nyertél", "winButton", s));
                return;
            }
        }

        // mellékátló fölött
        for (int i=0; i<=boardSize-1; i++)
        {
            sCount=0;
            int diagX=i;
            int diagY=boardSize-1;
            while (diagX>=0 && diagY>=0)
            {
                if (board[diagX][diagY]==s)
                {
                    sCount++;
                }
                diagX--;
                diagY--;
            }
             if (sCount==5)
            {
                widgets.push_back(new PushButton(this, 300, 300, 50,25, "Nyertél", "winButton", s));
                return;
            }
        }

        // mellékátló alatt
        for (int i=boardSize-1; i>=0; i--)
        {
            sCount=0;
            int diagX=i;
            int diagY=0;
            while (diagX<boardSize && diagY<boardSize)
            {
                if (board[diagX][diagY]==s)
                {
                    sCount++;
                }
                diagX++;
                diagY++;
            }
             if (sCount==5)
            {
                widgets.push_back(new PushButton(this, 300, 300, 50,25, "Nyertél", "winButton", s));
                return;
            }
        }

        bool dontetlen=true;
        // döntetlen
        for (int i=0; i<boardSize; i++)
        {
            for (int j=0; j<boardSize; j++)
            {
                if (board[i][j]==-1)
                {
                    dontetlen=false;
                }
            }
        }

         if (dontetlen)
            {
                widgets.push_back(new PushButton(this, 300, 300, 50,25, "Nyertél", "winButton", -1));
                return;
            }
    }
};

int main()
{
    gout.open(800,600);
    MyWindow *mywindow = new MyWindow;
    mywindow->event_loop();
    return 0;
}

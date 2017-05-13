#include "examplecheckbox.hpp"
#include "graphics.hpp"
#include "window.hpp"
using namespace genv;

ExampleCheckBox::ExampleCheckBox(Window * parent,int x, int y, int sx, int sy, int i, int j)
    : Widget(x,y,sx,sy), _parent(parent)
{
    state=-1;
    pX=i;
    pY=j;
}

void ExampleCheckBox::draw() const
{
    gout  << color(255,255,255);
    gout << move_to(_x, _y) << box(_size_x, _size_y);
    gout << move_to(_x+2, _y+2) << color(0,0,0) << box(_size_x-4, _size_y-4);
    if (state==0)
    {
        gout  << color(0,255,0);
        gout << move_to(_x+4, _y+4) << line(_size_x-8, _size_y-8);
        gout << move_to(_x+5, _y+4) << line(_size_x-8, _size_y-8);
        gout << move_to(_x+_size_x-4, _y+4) << line(-_size_x+8, _size_y-8);
        gout << move_to(_x+_size_x-5, _y+4) << line(-_size_x+8, _size_y-8);
    }
    else if (state==1)
    {
        gout  << color(255,0,0);
        gout << move_to(_x+4, _y+4) << line(_size_x-8, _size_y-8);
        gout << move_to(_x+5, _y+4) << line(_size_x-8, _size_y-8);
        gout << move_to(_x+_size_x-4, _y+4) << line(-_size_x+8, _size_y-8);
        gout << move_to(_x+_size_x-5, _y+4) << line(-_size_x+8, _size_y-8);
    }
}

void ExampleCheckBox::handle(event ev)
{
    static int round = 0;
    if (ev.type == ev_mouse && is_selected(ev.pos_x, ev.pos_y) && ev.button==btn_left)
    {
        if (state==-1)
        {
            state = round % 2;
            round++;
            action();
        }
    }
}
int ExampleCheckBox::getState() const
{
    return state;
}

void ExampleCheckBox::action() {
    _parent->esemeny(pX,pY,state);
}

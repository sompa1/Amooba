#include "pushbutton.hpp"

using namespace std;
using namespace genv;

PushButton::PushButton(Window * parent, int x, int y, int sx, int sy, string s, string azonosito, int st)
    : Widget(x,y,sx,sy),
    _parent(parent),
    _felirat(s),
    _azonosito(azonosito),
    state(st)
{
}

void PushButton::draw() const {
   if (state==0)
   {
    gout << move_to(_x, _y) << color(240,230,140) << box(_size_x, _size_y);
    gout << move_to(_x+_size_x/2-gout.twidth(_felirat)/2, _y+20) << color(0,102,0)
         << text(_felirat);
   }
   else if (state==1)
   {
       gout << move_to(_x, _y) << color(240,230,140) << box(_size_x, _size_y);
    gout << move_to(_x+_size_x/2-gout.twidth(_felirat)/2, _y+20) << color(255,0,0)
         << text(_felirat);
   }
   else
   {
       gout << move_to(_x, _y) <<color(240,230,140)<< box(_size_x, _size_y);
    gout << move_to(_x+_size_x/2-gout.twidth(_felirat)/2, _y+20) << color(255,255,255)
         << text(_felirat);
   }

}
void PushButton::handle(genv::event ev) {
	if (ev.type == ev_key || (ev.type == ev_mouse && ev.button==btn_left)) {
    if (ev.keycode==' ' || is_selected(ev.pos_x, ev.pos_y)) {
        action(); //itt hivom meg az esemenyt!
    }
    }
}
void PushButton::action() {
    _parent->pushButtonCall();
}

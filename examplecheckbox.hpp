#ifndef EXAMPLECHECKBOX_HPP_INCLUDED
#define EXAMPLECHECKBOX_HPP_INCLUDED

#include "graphics.hpp"
#include "widgets.hpp"
#include "window.hpp"

class ExampleCheckBox : public Widget {
protected:
    int state;
    Window* _parent;
    int pX;
    int pY;
public:
    ExampleCheckBox(Window* parent, int x, int y, int sx, int sy, int i, int j);
    virtual void draw() const ;
    virtual void handle(genv::event ev);
    virtual int getState() const ;
    virtual void action();
};


#endif // EXAMPLECHECKBOX_HPP_INCLUDED

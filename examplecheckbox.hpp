#ifndef EXAMPLECHECKBOX_HPP_INCLUDED
#define EXAMPLECHECKBOX_HPP_INCLUDED

#include "graphics.hpp"
#include "widgets.hpp"

class ExampleCheckBox : public Widget {
protected:
    int state;
public:
    ExampleCheckBox(int x, int y, int sx, int sy);
    virtual void draw() const ;
    virtual void handle(genv::event ev);
    virtual int getState() const ;
};


#endif // EXAMPLECHECKBOX_HPP_INCLUDED

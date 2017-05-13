#ifndef WINDOW_HPP_INCLUDED
#define WINDOW_HPP_INCLUDED

#include "widgets.hpp"
#include <vector>


class Window {
protected:
    std::vector<Widget*> widgets;
public:
    virtual void ellenoriz(int i, int j, int state){}
    virtual void pushButtonCall() {}
    void event_loop() ;
};



#endif // WINDOW_HPP_INCLUDED

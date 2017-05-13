#ifndef WINDOW_HPP_INCLUDED
#define WINDOW_HPP_INCLUDED

#include "widgets.hpp"
#include <vector>


class Window {
protected:
    std::vector<Widget*> widgets;
public:
    virtual void esemeny(int i, int j, int state){}

    void event_loop() ;
};



#endif // WINDOW_HPP_INCLUDED

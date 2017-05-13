#include "graphics.hpp"
#include "widgets.hpp"
#include "examplecheckbox.hpp"
#include "statictext.hpp"
#include "texteditor.hpp"
#include "window.hpp"
#include "pushbutton.hpp"
#include <vector>
#include <stdlib.h>

using namespace std;
using namespace genv;


///////////////////////////////////////////////////
class MyWindow : public Window {
public:
//    StaticText *tx1;
//    TextEditor *ed1;
//    PushButton *button;
//    PushButton *button1;
    MyWindow()
    {
//        button = new PushButton(this, 10, 10, 100, 40,"=", "egyenlo");
//         button1 = new PushButton(this, 10, 60, 100, 40,"Start", "start");
//       tx1 = new StaticText(175,20,100,40,"pipa");
//        ed1 = new TextEditor(10,110,100,40,"editor");
//        widgets.push_back(tx1);
//        widgets.push_back(ed1);
//        widgets.push_back(button);
//        widgets.push_back(button1);
        int posx=40;
        int posy=40;
		for (int i=1; i<=12; i++)
        {
            for (int j=1; j<=12; j++)
            {
                widgets.push_back(new ExampleCheckBox(posx,posy,40,40));
                posx=posx+40;
            }
            posy=posy+40;
            posx=40;
        }
   }
    void esemeny(string mitortent)
    { //esemenykezelo fgv.
//        if (mitortent == "egyenlo") {
//            tx1->setText(ed1->value());
//            }
//        if (mitortent == "start") {
//            string ping_cmd;
//            if (!bcbox->is_checked())
//            {
//            ping_cmd = "ping -c 4 " + ed1->value();
//            }
//            else
//            {
//            ping_cmd = "ping " + ed1->value();
//           }
//            system(ping_cmd.c_str());
//        }
    }
};

int main()
{
    gout.open(800,600);
    MyWindow *mywindow = new MyWindow;
    mywindow->event_loop();
    return 0;
}

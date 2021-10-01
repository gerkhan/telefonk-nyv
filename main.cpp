#include <iostream>
#include <cstring>
#include "menu.h"
#include "list.h"
#include "Line.h"
#include "memtrace.h"
int main()
{
    List lt;
    lt.MemLoad();
    //menu
    menu mn;
    try
    {
        mn.MenuWork(lt);
    }
    catch(string msg)
    {
        cout<<msg<<endl;
    }
    lt.clean();

    return 0;
}

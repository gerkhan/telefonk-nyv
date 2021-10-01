#ifndef LINE_H
#define LINE_H
#include <fstream>
#include <string>
#include <iostream>
#include "Phone.h"
#include "memtrace.h"
using namespace std;

class Line:public Phone
{
    string area;

public:
    //Constructor
    Line( string fn = "User_User", string nn = "Resu", string c = "Nether", string s = "Bedrock",int hn = 256,int pc=9999,string pn="06705051289",string wn="none", int ca = 1, int id = 0,string a="Bacs3"):
        Phone(fn,nn,c,s,hn,pc,pn,wn,ca,id),area(a) {}
    //GET,SET functions
    string areaGet()
    {
        return area;
    }
    void areaSet( int a )
    {
        area = a;
    }
    void dataList();
    void filePrint(fstream& os);
};

#endif // LINE_H

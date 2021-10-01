#ifndef FOREGIN_H
#define FOREGIN_H
#include <iostream>
#include <fstream>
#include <string>
#include "Phone.h"
#include "memtrace.h"
using namespace std;

class Foreign:public Phone
{
    string country;
//Constructor
public:
    Foreign( string fn = "User_User", string nn = "Resu", string c = "Nether", string s = "Bedrock",int hn = 256,int pc=9999,string pn="06705051289",string wn="none", int ca = 1, int id = 0,string co="Canada"):
        Phone(fn,nn,c,s,hn,pc,pn,wn,ca,id),country(co) {}

    //GET,SET functions
    string countryGet()
    {
        return country;
    }
    void countrySet( string co )
    {
        country = co;
    }

    void dataList();
    void filePrint(fstream& os);

};

#endif // FOREGIN_H

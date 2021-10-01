#ifndef LIST_H
#define LIST_H
#include <iostream>
#include "Phone.h"
#include "Foreign.h"
#include "Line.h"
#include "memtrace.h"
using namespace std;
class List
{
    Phone* array[50];
    int x = 0;
    static int ID;


public:
    //Constructor
    List() {}
    //GET,SET functions
    int getX()
    {
        return x;
    }
    void setX( int newX )
    {
        x = newX;
    }
    void setFirst( Phone* newFirst )
    {
        *array = newFirst;
    }
    Phone* getFirst()
    {
        return array[0];
    }
    //Functions
    void MemLoad();
    static Phone* NewPhoneGet();
    void push_back(Phone*);
    void PhoneDelete(string number);
    void search();
    void FileAdd();
    void ListAll();
    void clean();
    void tests();

};


#endif

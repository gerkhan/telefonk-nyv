#ifndef PHONE_H
#define PHONE_H
#include <iostream>
#include <string>
#include <fstream>
#include "memtrace.h"
using namespace std;


class Phone
{
protected:
    string fullname;
    string nickname;
    string city;
    string street;
    string privatenumber;
    string worknumber;
    int housenumber;
    int postcode;
    int id;
    int cat;

public:

    //Constructor
    Phone( string fn = "User_User", string nn = "Resu", string c = "Nether", string s = "Bedrock",int hn = 256,int pc=9999,string pn="06705051299",string wn="none", int ca = 1, int id = 0):
        fullname(fn), nickname(nn), city(c), street(s), privatenumber(pn),worknumber(wn),housenumber(hn),postcode(pc),id(id), cat(ca) {}

    //GET functions
    string fullnameGet()
    {
        return fullname;
    }
    string nicknameGet()
    {
        return nickname;
    }
    string cityGet()
    {
        return city;
    }
    string streetGet()
    {
        return street;
    }
    string privatenumberGet()
    {
        return privatenumber;
    }
    string worknumberGet()
    {
        return worknumber;
    }

    int housenumberGet()
    {
        return housenumber;
    }
    int idGet()
    {
        return id;
    }
    int postcodeGet()
    {
        return postcode;
    }
    int categoryGet()
    {
        return cat;
    }

    //SET functions
    void fullnameSet( string fn )
    {
        fullname = fn;
    }
    void nicknameSet( string nn )
    {
        nickname = nn;
    }
    void citySet( string c )
    {
        city = c;
    }
    void streetSet( string s )
    {
        street = s;
    }
    void privatenumberSet( string pn )
    {
        privatenumber = pn;
    }
    void worknumberSet( string wn )
    {
        worknumber = wn;
    }
    void housenumberSet( int hn )
    {
        housenumber = hn;
    }
    void postcodeSet( int pc )
    {
        postcode = pc;
    }
    void categorySet( int ca )
    {
        cat = ca;
    }

    virtual void dataList();
    virtual void filePrint(fstream& os );
    virtual ~Phone() {}
};

#endif

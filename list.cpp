#include "list.h"
int List::ID = 0;

Phone* List::NewPhoneGet()
{
    //Declaration
    string fullnameNew, nicknameNew,cityNew,streetNew,privatenumberNew,worknumberNew;
    int postcodeNew, housenumberNew,catNew;
    List::ID++;
    int id = List::ID;
    char d;
    Phone* onePhone;

    //request data
    cin.ignore(1,'\n');
    cout << "New contact" << endl;

    cout << "Full name: ";
    cin >> fullnameNew;

    cout << "Nickname: ";
    cin >> nicknameNew;

    cout << "Postcode: ";
    cin >> postcodeNew;

    cout << "City: ";
    cin >> cityNew;

    cout << "Street: ";
    cin >> streetNew;

    cout << "House number: ";
    cin >> housenumberNew;

    cout << "Private number: ";
    cin >> privatenumberNew;

    cout << "Work number: ";
    cin >> worknumberNew;

    cout << "Category: \n"
         << "\t[1] Domestic\n"<< "\t[2] Line\n"<< "\t[3] Foreign\n";
    cin >> d;
    //Establish a category, request additional information
    if( d == '2')
    {
        catNew = 2;
        string areaNew;
        cout << "Area: ";
        cin >> areaNew;
        onePhone = new Line(fullnameNew, nicknameNew,cityNew,streetNew,housenumberNew,postcodeNew,privatenumberNew,worknumberNew,catNew,id,areaNew);

    }
    else if( d == '3')
    {
        catNew = 3;
        string countryNew;
        cout << "Country: ";
        cin>>countryNew;
        onePhone = new Foreign(fullnameNew, nicknameNew,cityNew,streetNew,housenumberNew,postcodeNew,privatenumberNew,worknumberNew,catNew,id,countryNew);
    }
    else
    {
        catNew = 1;
        onePhone = new Phone(fullnameNew, nicknameNew,cityNew,streetNew,housenumberNew,postcodeNew,privatenumberNew,worknumberNew,catNew,id);
    }

    return  onePhone;
}
//Attaches the element to the end of the array
void List::push_back(Phone * Phonep)
{
    array[x] = Phonep;
    x++;
}

void List::ListAll() //List stored data ("No data" for empty file)
{
    if( x == 0)
    {
        cout << "No data" << endl;
        return;
    }

    for (int i = 0; i < x; ++i)
    {
        array[i]->dataList();
    }
}
//Read from file and then store by category
void List::MemLoad()
{
    ifstream file("phonebook.txt");
    string line;
    while(getline(file, line))
    {

        int id;
        string fn;
        string nn;
        int pc;
        string c;
        string s;
        int hn;
        string pn;
        string wn;
        int cat;
        string etc;

        file>>id;
        file>>fn;
        file>>nn;
        file>>pc;
        file>>c;
        file>>s;
        file>>hn;
        file>>pn;
        file>>wn;
        file>>cat;
        file>>etc;

        switch(cat)
        {
        case 1:
            this->push_back(new Phone(fn,nn,c,s,hn,pc,pn,wn,cat,id));
            break;
        case 2:
            this->push_back(new Line(fn,nn,c,s,hn,pc,pn,wn,cat,id,etc));
            break;
        case 3:
            this->push_back(new Foreign(fn,nn,c,s,hn,pc,pn,wn,cat,id,etc));
            break;

        }
    }
}

void List::PhoneDelete(string number)//Delete a contact based on a private number
{
    fstream file;

    file.open ("phonebook.txt", ofstream::out | ofstream::trunc);
    int t;
    for (int i = 0; i < x; i++)
    {
        if (array[i]->privatenumberGet() == number)
        {
            cout << "Successfull delete!" << endl;
            t=i;
        }
    }
    for(int i=0; i<x; i++)
    {
        if(i!=t)
        {
            file << '\n';
            array[i]->filePrint(file);
        }
    }

    file.close();

}


void List::FileAdd() //attach to file (with line feed)
{
    fstream file;
    file.open ("phonebook.txt", ofstream::app);

    file << '\n';
    array[ x-1 ]->filePrint( file );

    file.close();
    this->clean();
    this->MemLoad();

}

void List::search()//searches by private phone number
{
    cout << "Private number:" <<endl;
    string pnumber;
    cin>>pnumber;
    int r=0;
    for( int i = 0; i < x; i++)
    {
        if(array[i]->privatenumberGet().find(pnumber) != string::npos)
        {
            array[i]->dataList();
            r++;
        }
    }
    if(r==0)
        cout<<"There are no matching numbers!"<<endl;
}
void List::clean()
{
    for(int i = 0; i < x; i++)
        delete array[i];

    x = 0;
}
void List::tests()
{
    //Test the ListAll function
    ListAll();
    cout<<"Listing is working"<<endl;
    cout<<"##################"<<endl;
    //Add a contact and test the push_back function
    this->push_back( new Phone("Test_User","TUSER","San_Fierro","Grove",66,9999, "06701234567", "06707654321",1,0));
    if( this->getX() != 0 )
    {
        cout<< "Successfull adding" <<endl;
        ListAll();
        cout<<"##################"<<endl;
    }
    else
    {
        cout << "Failed contact adding" << endl;
        cout<<"##################"<<endl;
    }


    //Request different data by category
    Line l =  Line("Test_Line","TLINE","San_Fierro","Grove",66,9999, "06701234567", "06707654321",2,1,"SAN3");
    if( l.areaGet() == "SAN3")
        cout << "Successfull area getting" << endl;
    else
        cout << "Failed area test" << endl;


    Foreign f = Foreign("Test_Country","TCOU","San_Fierro","Grove",66,9999, "06701234567", "06707654321",3,1,"USA");
    if( f.countryGet() == "USA")
        cout << "Successfull country getting" << endl;
    else
        cout << "Failed country test" << endl;

    cout<<"##################"<<endl;

    //Delete
    string tel="06701234567";
    PhoneDelete(tel);
    cout<<"##################"<<endl;

    //
    this->clean();
    if( this->x == 0)
    {
        cout << "Successfull cleaning " <<endl;
    }
    else
    {
        cout << "Failed cleaning" <<endl;
    }
    //Re-listing
    ListAll();

}



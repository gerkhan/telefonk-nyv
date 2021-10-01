#include "menu.h"

int menu::MenuWrite() //Menu write to the console and communicate with the user
{
    cout <<"[1] Listing all data \n"
         <<"[2] Search by private number\n"
         <<"[3] Add contact \n"
         <<"[4] Delete contact \n"
         <<"[5] Exit\n"
         <<"[6] Tests"<<endl;
    int d;
    cin >> d;
    return d;
}

void menu::MenuWork(List& li) //menu working and the functions
{
    cout<<"Press s to start/e to exit"<<endl;
    char s;
    cin>>s;
    if(s=='s')
    {
        int exit=0;
        while(exit==0)
        {
            int d = menu::MenuWrite();
            switch (d)
            {
            case 1:
                li.ListAll();
                break;
            case 2:
                li.search();
                break;
            case 3:
                li.push_back( List::NewPhoneGet() );
                li.FileAdd();
                break;
            case 4:
            {
                cout << "Private number: " <<endl;
                string number;
                cin >> number;
                li.PhoneDelete(number);
                li.clean();
                li.MemLoad();
            }
            break;
            case 5:
                li.clean();
                exit=1;

                break;
            case 6:
                li.tests();
                break;
            default:
                cout<< "Wrong number!Try again!"<<endl;
            }
        }
    }


}

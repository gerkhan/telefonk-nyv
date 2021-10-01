#include "Phone.h"

void Phone::dataList()
{
    cout << "\nFull name: " << fullname
         << "\nNickname: " << nickname
         << "\nLocation: " << postcode <<" "<<city<<" "<<street<<" "<<housenumber
         << "\nPrivate number: " << privatenumber
         << "\nWork number: " << worknumber<<endl;

}
void Phone::filePrint(fstream& os)
{
    os << id << "\t" << fullname << "\t" << nickname << "\t" << postcode << "\t" << city << " " << street << "\t" << housenumber << "\t" << privatenumber << "\t"<< worknumber << "\t" << cat <<"\t0" ;
}


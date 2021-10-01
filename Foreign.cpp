#include "Foreign.h"
void Foreign::dataList()
{
    Phone::dataList();
    cout << "Country: " << country << endl;
}

void Foreign::filePrint(fstream &os)
{
    os << id << "\t" << fullname << "\t" << nickname << "\t" << postcode << "\t" << city << "\t" << street << "\t" << housenumber << "\t" << privatenumber << "\t"<< worknumber << "\t" << cat <<"\t"<<country ;
}

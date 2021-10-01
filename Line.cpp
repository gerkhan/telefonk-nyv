#include "Line.h"

void Line::dataList()
{
    Phone::dataList();
    cout << "Area: " << area << std::endl;
}

void Line::filePrint(fstream &os)
{
    os << id << "\t" << fullname << "\t" << nickname << "\t" << postcode << "\t" << city << "\t" << street << "\t" << housenumber << "\t" << privatenumber << "\t"<< worknumber << "\t" << cat <<"\t"<<area ;
}

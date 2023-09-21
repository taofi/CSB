#include <iostream>

using namespace std;

typedef unsigned char day;
typedef unsigned char month;
typedef unsigned short year;

struct Date {
     day dd;
     month mm;
     year yyyy;
};

bool operator < (Date& d1, Date& d2) {
    bool b = true;
    if (d1.yyyy == d2.yyyy)
    {
        if (d1.mm == d2.mm)
            b = d1.dd < d2.dd;
        else
            b = d1.mm < d2.mm;
    }
    else
        b = d1.yyyy < d2.yyyy;
    return b;
}
bool operator > (Date& date1, Date& date2) {
    return !(date1 < date2);
}
bool operator == (Date& date1, Date& date2) {
    return (date1.dd == date2.dd && date1.mm == date2.mm && date1.yyyy == date2.yyyy);
}



int main()
{
    Date date1 = { 7,1,1980 };
    Date date2 = { 7,2,1993 };
    Date date3 = { 7,1,1980 };
    if (date1 < date2) cout << "true" << endl;
    else  cout << "false" << endl;
    if (date1 > date2) cout << "true" << endl;
    else  cout << "false" << endl;
    if (date1 == date2) cout << "true" << endl;
    else  cout << "false" << endl;
    if (date1 == date3) cout << "true" << endl;
    else  cout << "false" << endl;
}
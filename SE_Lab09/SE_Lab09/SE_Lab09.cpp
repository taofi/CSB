#include "varparm.h"

using namespace std;

int main()
{
    cout << ivarparm(1, 2) << endl;
    cout << ivarparm(2, 2, 3) << endl;
    cout << ivarparm(3, 2, 5, 6) << endl;
    cout << ivarparm(7, 2, 5, 3, 2, 3, 4, 6) << endl;

    cout << "\n" << svarparm(1, 2) << endl;
    cout << svarparm(2, 2, 8) << endl;
    cout << svarparm(3, 5, 3, 4) << endl;
    cout << svarparm(7, 2, 7, 3, 4, 6, 7, 9) << endl;

    cout << "\n" << fvarparm(4.0, FLT_MAX) << endl;
    cout << fvarparm(4.0, 2.0, FLT_MAX) << endl;
    cout << fvarparm(4.0, 3.0, 4.0, FLT_MAX) << endl;
    cout << fvarparm(4.0, 4.0, 5.0, 3.2, 4.5, 1.2, 9.0, FLT_MAX) << endl;
    
    cout << "\n" << dvarparm(4.0, DBL_MAX) << endl;
    cout << dvarparm(4.0, 2,0, DBL_MAX) << endl;
    cout << dvarparm(4.0, 3.0, 4.0, DBL_MAX) << endl;
    cout << dvarparm(4.0, 4.0, 5.0, 3.2, 4.5, 1.2, 9.0, DBL_MAX) << endl;
}
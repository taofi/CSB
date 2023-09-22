#include <iostream>

double defaultparm(int a1, int a2, int a3, int a4, int a5, int a6 = 1, int a7 = 0) {
    return double(a1 + a2 + a3 + a4 + a5 + a6 + a7) / 7;
}

int main()
{
   double d1 = defaultparm(1, 2, 3, 4, 5);
   double d2 = defaultparm(1, 2, 3, 4, 5, 6, 7);
   std::cout << d1 << "\n" << d2;
}



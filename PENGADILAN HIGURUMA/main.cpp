#include <iostream>
#include "interface.h"
#include "dummy.h"

using namespace std;

int main()
/* I.S. program mulai dijalankan
   F.S. data dummy dimuat dan menu utama dijalankan */
{
    ListHakim LH = {};
    ListTerdakwa LT = {};
    BST T = {};

    createListHakim(LH);
    createListTerdakwa(LT);
    createBST(T);

    dummyHakim(LH);
    dummyTerdakwa(LT);
    dummyPerkara(LH, LT);
    dummyPutusan(T);

    menu(LH, LT, T);

    return 0;
}

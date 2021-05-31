#include <iostream>
#include "BSTFCI.h"
using namespace std;

int main()
{
    /*
                10
            5           12
        3                     14    
    1                               15
    */
    BSTFCI <int> b;
    b.insert(1);
    b.insert(5);
    b.insert(0);
    b.insert(4);
    b.insert(3);
    b.insert(2);
    b.printInorder();
    b.printpreorder();
    b.printpostorder();
    b.remove('e');
    b.flipTree();
    cout<<b.isBalance()<<endl;
    b.isEmpty();
    b.largestValues();
    b.printRange('a', 'f');
    b.search('g');
    b.sum();
    b.printInorder();
    b.printpreorder();
    b.printpostorder();
    return 0;
}
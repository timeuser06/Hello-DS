#include <iostream>
#include "Linked_Lists.h"
using namespace std;

int main() {
    Linear_Single_List head_1;
    for (int i=0;i<10;i++) {
        head_1.pushBack(i+1);
    }
    head_1.display();

    return 0;
}

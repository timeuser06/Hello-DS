#include <iostream>
#include "LInked_Lists_Launcher.h"
using namespace std;

int main() {
    Single_LinkedList head_1;
    for (int i=0;i<10;i++) {
        head_1.addEnd(i+1);
    }
    head_1.display();

    return 0;
}

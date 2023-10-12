#include <iostream>
#include <ctime>
#include "rb_tree.hpp"
#include "utility.hpp"
#include "pcb.hpp"

using namespace std;

int main()
{
    int const size = 35;
    PCB array[size];

    Red_Black_Tree redBlackTree;

    for (int i = 0; i < size; i++)
    {
        redBlackTree.Insert(array[i]);
    }

    redBlackTree.Display(2);
    


    return 0;
}

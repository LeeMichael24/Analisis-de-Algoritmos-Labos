#include <iostream>
#include <ctime>
#include "rb_tree.hpp"
#include "utility.hpp"
#include "pcb.hpp"

using namespace std;

int main()
{
    
    /* int deleteN; */
    int const size = 35;
    PCB array[size];

    Red_Black_Tree redBlackTree;
    PCB pcb;
    Red_Black_Tree tree;

    for (int i = 0; i < size; i++)
    {
        redBlackTree.Insert(array[i]);
    }
    
    //mostar el arbol por primera vez
    cout << "-------------------Primer Display--------------------" << endl;
    redBlackTree.Display(1);

    //esto es para recalcular los valores
    while (redBlackTree.GetRoot() != nullptr)
    {
        pcb = redBlackTree.Minimum(redBlackTree.GetRoot())->data;

        pcb.DisplayPCB();

        redBlackTree.Delete(pcb);

        pcb.SetVirtualRuntime(pcb.GetVirtualRuntime() + RandomTimeSlice());
        pcb.SetTimeToComplete(pcb.GetTimeToComplete() - pcb.GetVirtualRuntime());

        //aca se inserta el pcb modificado
        if(pcb.GetTimeToComplete() > 0)
        {
            redBlackTree.Insert(pcb);
        }
        else
        {
            cout << "El proceso " << pcb.GetProcessID() << " ha terminado\n";
        }
        
    }

    //ahora hay que volver a mostrar
    cout << "-------------------Segundo Display Modificado--------------------" << endl;
    cout << "El arbol esta vacio" << endl;
    redBlackTree.Display(1);
    

    return 0;
}

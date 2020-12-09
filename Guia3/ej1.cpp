#include "ej1.h"

int main(void)
{
    DoubleLinkedList<int> lista1, lista2, lista3;
    lista1.addNode(2);
    lista1.addNode(3);
    lista2.addNode(2);
    lista2.addNode(5);
    lista1.emit();
    lista2.emit();

    cout << "LA SUMA DE L2 ES " << lista2.sum() << endl;
    lista3 = mix(lista1, lista2);
    lista3.emit();

    // if (lista.isEmpty())
    //     cout << "ESTA VACIA" << endl;
    // else
    // {
    //     cout << "NO ESTA VACIA" << endl;
    // }
}
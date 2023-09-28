#include <iostream>
#include "reader.hpp"

using namespace std;

// Función para intercambiar dos elementos de un arreglo
void swap(int* array, int i, int j) {
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

// Función para realizar el MaxHeapify, siguiendo la logica del labo, podemos 
//recrear la funcion de los hijos izquierdos y derechos con la formula 2i+1 y 2i+2
// Función para realizar el MinHeapify
void MinHeapify(int* array, int i, int size) {
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int smallest = i;

    if (l < size && array[l] < array[i])
        smallest = l;

    if (r < size && array[r] < array[smallest])
        smallest = r;

    if (smallest != i) {
        swap(array, i, smallest);
        MinHeapify(array, smallest, size);
    }
}

// Función para construir un Min Heap
void BuildMinHeap(int* array, int size) {
    for (int i = size / 2 - 1; i >= 0; i--)
        MinHeapify(array, i, size);
}

// Función de Heap Sort
void Heapsort(int* arr, int n) {
    BuildMinHeap(arr, n);
    for (int i = n - 1; i > 0; i--) {
        swap(arr, 0, i);
        MinHeapify(arr, 0, i);
    }
}

int main() {
    // Aquí creamos el arrelgo del archivo .txt
    const int rows = 1000;
    const int cols = 5;

    SalesData data[rows]; // Declarar el arreglo de objetos SalesData desde reader.hpp
    load_data(data, rows, cols); // Cargar los datos desde "sales.txt" en el arreglo

    // Recorrer el arreglo de objetos y acceder a los campos de cada objeto
    for (int i = 0; i < rows; i++) {
        cout << "Customer ID: " << data[i].customer_id << endl;
        cout << "Product ID: " << data[i].product_id << endl;
        cout << "Quantity: " << data[i].quantity << endl;
        cout << "Purchase Date: " << data[i].purchase_date << endl;
        cout << "Total Price: " << data[i].total_price << endl;

    }

    return 0;
}

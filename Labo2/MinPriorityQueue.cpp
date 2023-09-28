#include <iostream>
#include <vector>
#include "reader.hpp"

using namespace std;

struct Element {
    int key;
    SalesData data;
};

class MinPriorityQueue {
private:
    vector<Element> heap;

    void MinHeapify(int i) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = i;

        if (left < heap.size() && heap[left].key < heap[i].key)
            smallest = left;

        if (right < heap.size() && heap[right].key < heap[smallest].key)
            smallest = right;

        if (smallest != i) {
            swap(heap[i], heap[smallest]);
            MinHeapify(smallest);
        }
    }

public:
    MinPriorityQueue() {}

    void insert(int key, const SalesData &data) {
        Element element;
        element.key = key;
        element.data = data;
        heap.push_back(element);

        int i = heap.size() - 1;
        while (i > 0 && heap[(i - 1) / 2].key > heap[i].key) {
            swap(heap[i], heap[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    const SalesData& min() {
        return heap[0].data;
    }

    void extract_min() {
        swap(heap[0], heap[heap.size() - 1]);
        heap.pop_back();
        MinHeapify(0);
    }

    void reduce_key(int index, int new_key) {
        if (index < heap.size() && new_key < heap[index].key) {
            heap[index].key = new_key;
            while (index > 0 && heap[(index - 1) / 2].key > heap[index].key) {
                swap(heap[index], heap[(index - 1) / 2]);
                index = (index - 1) / 2;
            }
        }
    }
};

int main() {
    // Crear una instancia de la cola de prioridad mínima
    MinPriorityQueue minPriorityQueue;

    const int rows = 1000;
    const int cols = 5;

    SalesData data[rows]; // Declarar el arreglo de objetos SalesData
    load_data(data, rows, cols); // Cargar los datos 

    // Ahora puedes insertar elementos utilizando los datos cargados
    minPriorityQueue.insert(5, data[0]);
    minPriorityQueue.insert(3, data[1]);
    minPriorityQueue.insert(8, data[2]);

    // Ver el elemento con la clave mínima
    const SalesData &minElement = minPriorityQueue.min();
    cout << "Elemento con clave mínima: " << minElement.customer_id << ", " << minElement.total_price << endl;

    // Extraer el elemento con la clave mínima
    minPriorityQueue.extract_min();

    // Reducir la clave de un elemento
    minPriorityQueue.reduce_key(1, 2);

    return 0;
           
}
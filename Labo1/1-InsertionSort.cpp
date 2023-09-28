#include <iostream>

using namespace std;

struct FactoryInfo {
    int ID;
    int numEmployees;
    int profit;
};

void selection_sort_desc(FactoryInfo A[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int maxIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (A[j].numEmployees > A[maxIndex].numEmployees) {
                maxIndex = j;
            }
        }
        swap(A[i], A[maxIndex]);
    }
}

void bubble_sort(FactoryInfo A[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (A[j].profit > A[j + 1].profit) {
                swap(A[j], A[j + 1]);
            }
        }
    }
}

int main(void) {
    int size = 10;
    FactoryInfo factories[10] = {{1, 308, 17430},
                                 {2, 829, 27860},
                                 {3, 615, 41140},
                                 {4, 698, 44770},
                                 {5, 732, 16940},
                                 {6, 549, 42420},
                                 {7, 435, 36740},
                                 {8, 785, 26820},
                                 {9, 294, 12050},
                                 {10, 484, 33440}};

    // Selection Sort in descending order of numEmployees
    FactoryInfo factories_selection[10];
    for (int i = 0; i < size; i++) {
        factories_selection[i] = factories[i];
    }
    selection_sort_desc(factories_selection, size);

    cout << "Valores después de ordenar con Selection Sort (numEmployees en orden descendente):\n";
    for (int i = 0; i < size; i++) {
        cout << "ID: " << factories_selection[i].ID << "\n";
        cout << "numEmployees: " << factories_selection[i].numEmployees << "\n";
        cout << "profit: " << factories_selection[i].profit << "\n";
        cout << "--------------------\n";
    }

    // Bubble Sort
    FactoryInfo factories_bubble[10];
    for (int i = 0; i < size; i++) {
        factories_bubble[i] = factories[i];
    }
    bubble_sort(factories_bubble, size);

    cout << "\nValores después de ordenar con Bubble Sort:\n";
    for (int i = 0; i < size; i++) {
        cout << "ID: " << factories_bubble[i].ID << "\n";
        cout << "numEmployees: " << factories_bubble[i].numEmployees << "\n";
        cout << "profit: " << factories_bubble[i].profit << "\n";
        cout << "--------------------\n";
    }

    return 0;
}

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <algorithm>

using namespace std;

// Função para trocar dois elementos
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Algoritmo Bubble Sort
void bubbleSort(int arr[], int n, long long& comparisons, long long& movements) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            comparisons++;
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                movements++;
            }
        }
    }
}

// Algoritmo Selection Sort
void selectionSort(int arr[], int n, long long& comparisons, long long& movements) {
    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            comparisons++;
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
        movements++;
    }
}

// Algoritmo Insertion Sort
void insertionSort(int arr[], int n, long long& comparisons, long long& movements) {
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            comparisons++;
            arr[j + 1] = arr[j];
            movements++;
            j--;
        }
        arr[j + 1] = key;
        movements++;
    }
}

// Função para preencher um vetor com números aleatórios
void generateRandomArray(int arr[], int n) {
    srand(time(0));
    for (int i = 0; i < n; ++i) {
        arr[i] = rand() % 1000; // Limite máximo de 1000, pode ser ajustado
    }
}

// Função para preencher um vetor ordenado
void generateSortedArray(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        arr[i] = i;
    }
}

// Função para medir o tempo de execução
double measureTime(void (*sortingFunction)(int[], int, long long&, long long&), int arr[], int n, long long& comparisons, long long& movements) {
    clock_t start, end;
    comparisons = 0;
    movements = 0;
    
    start = clock();
    sortingFunction(arr, n, comparisons, movements);
    end = clock();
    
    return double(end - start) / CLOCKS_PER_SEC;
}

int main() {
    int sizes[] = {100, 1000, 10000, 100000};
    string algorithms[] = {"Bubble Sort", "Selection Sort", "Insertion Sort"};
    string types[] = {"Random", "Sorted"};

    for (int size : sizes) {
        for (const string& type : types) {
            int* arr = new int[size];
            long long comparisons, movements;
            double timeTaken;

            if (type == "Random") {
                generateRandomArray(arr, size);
            } else if (type == "Sorted") {
                generateSortedArray(arr, size);
            }

            cout << "Array size: " << size << " - Type: " << type << endl;

            for (const string& algorithm : algorithms) {
                if (algorithm == "Bubble Sort") {
                    timeTaken = measureTime(bubbleSort, arr, size, comparisons, movements);
                } else if (algorithm == "Selection Sort") {
                    timeTaken = measureTime(selectionSort, arr, size, comparisons, movements);
                } else if (algorithm == "Insertion Sort") {
                    timeTaken = measureTime(insertionSort, arr, size, comparisons, movements);
                }

                cout << "Algorithm: " << algorithm << endl;
                cout << "Time taken: " << timeTaken << " seconds" << endl;
                cout << "Comparisons: " << comparisons << endl;
                cout << "Movements: " << movements << endl;

                // Para imprimir o vetor ordenado/desordenado:
                // for (int i = 0; i < size; ++i) {
                //     cout << arr[i] << " ";
                // }
                // cout << endl;
            }

            delete[] arr;
        }
    }

    return 0;
}

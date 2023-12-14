#include <iostream>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <iomanip>

using namespace std;

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Algoritmo Bubble Sort
void bubbleSort(int arr[], int n, long long& comparisons, long long& movements) {
    comparisons = 0;
    movements = 0;
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
    comparisons = 0;
    movements = 0;
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
    comparisons = 0;
    movements = 0;
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

// Algoritmo Shell Sort
void shellSort(int arr[], int n, long long& comparisons, long long& movements) {
    comparisons = 0;
    movements = 0;
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; ++i) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                comparisons++;
                arr[j] = arr[j - gap];
                movements++;
            }
            arr[j] = temp;
            movements++;
        }
    }
}

// Algoritmo Quick Sort
void quickSort(int arr[], int size, long long& comparisons, long long& movements) {
   if (size < 2) {
       return;
   }

   int pivot = arr[size - 1];
   int i = 0;

   for (int j = 0; j < size - 1; j++) {
       comparisons++;
       if (arr[j] < pivot) {
           i++;
           swap(arr[i], arr[j]);
           movements++;
       }
   }
   swap(arr[i + 1], arr[size - 1]);
   movements++;

   int pi = i + 1;

   quickSort(arr, pi, comparisons, movements);
   quickSort(arr + pi + 1, size - pi - 1, comparisons, movements);
}

// Algoritmo Heap Sort
void heapSort(int arr[], int n, long long& comparisons, long long& movements) {
   comparisons = 0;
   movements = 0;
   for (int i = n / 2 - 1; i >= 0; i--) {
       int largest = i;
       int left = 2 * i + 1;
       int right = 2 * i + 2;

       if (left < n && arr[left] > arr[largest]) {
           comparisons++;
           largest = left;
       }

       if (right < n && arr[right] > arr[largest]) {
           comparisons++;
           largest = right;
       }

       if (largest != i) {
           swap(arr[i], arr[largest]);
           movements++;
           i--;
       }
   }

   for (int i = n - 1; i >= 0; i--) {
       swap(arr[0], arr[i]);
       movements++;

       int largest = 0;
       int left = 1;
       int right = 2;

       if (left < i && arr[left] > arr[largest]) {
           comparisons++;
           largest = left;
       }

       if (right < i && arr[right] > arr[largest]) {
           comparisons++;
           largest = right;
       }

       if (largest != 0) {
           swap(arr[0], arr[largest]);
           movements++;
           i--;
       }
   }
}

// Algoritmo Merge Sort
void mergeSort(int arr[], int size, long long& comparisons, long long& movements) {
  if (size < 2) {
      return;
  }

  int mid = size / 2;
  int left[mid], right[size - mid];

  for (int i = 0; i < mid; i++) {
      left[i] = arr[i];
  }
  for (int i = mid; i < size; i++) {
      right[i - mid] = arr[i];
  }

  mergeSort(left, mid, comparisons, movements);
  mergeSort(right, size - mid, comparisons, movements);

  int i = 0, j = 0, k = 0;

  while (i < mid && j < size - mid) {
      comparisons++;
      if (left[i] <= right[j]) {
          arr[k] = left[i];
          movements++;
          i++;
      } else {
          arr[k] = right[j];
          movements++;
          j++;
      }
      k++;
  }

  while (i < mid) {
      arr[k] = left[i];
      movements++;
      i++;
      k++;
  }

  while (j < size - mid) {
      arr[k] = right[j];
      movements++;
      j++;
      k++;
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
    string types[] = {"Random", "Sorted"};

    string algorithms[] = {"Bubble Sort", "Selection Sort", "Insertion Sort", "Shell Sort", "Quick Sort", "Heap Sort", "Merge Sort"};

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

            for (const string& algorithm : algorithms) {
                comparisons = 0;
                movements = 0;

                if (algorithm == "Bubble Sort") {
                    timeTaken = measureTime(bubbleSort, arr, size, comparisons, movements);
                } else if (algorithm == "Selection Sort") {
                    timeTaken = measureTime(selectionSort, arr, size, comparisons, movements);
                } else if (algorithm == "Insertion Sort") {
                    timeTaken = measureTime(insertionSort, arr, size, comparisons, movements);
                } else if (algorithm == "Shell Sort") {
                    timeTaken = measureTime(shellSort, arr, size, comparisons, movements);
                } else if (algorithm == "Quick Sort") {
                    timeTaken = measureTime(quickSort, arr, size, comparisons, movements);
                } else if (algorithm == "Heap Sort") {
                    timeTaken = measureTime(heapSort, arr, size, comparisons, movements);
                } else if (algorithm == "Merge Sort") {
                    timeTaken = measureTime(mergeSort, arr, size, comparisons, movements);

                }

                cout << "Array Size,Type,Algorithm,Time taken,Comparisons,Movements" << endl;
                cout << size << "," << type << "," << algorithm << "," << fixed << setprecision(6) << timeTaken << "," << comparisons << "," << movements << endl;
            }

            delete[] arr;
        }
    }

    return 0;
}

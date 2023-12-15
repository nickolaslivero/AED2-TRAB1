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

    // Loop externo que percorre o array
    for (int i = 0; i < n - 1; ++i) {
        // Loop interno que realiza as comparações e trocas
        for (int j = 0; j < n - i - 1; ++j) {
            comparisons++; 

            // Verifica se o elemento atual é maior que o próximo
            if (arr[j] > arr[j + 1]) {
                // Se for, troca os elementos de posição
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

    // Loop externo que percorre o array até o penúltimo elemento
    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;  // Assume que o índice atual é o mínimo

        // Loop interno para encontrar o índice do menor elemento
        for (int j = i + 1; j < n; ++j) {
            comparisons++;  // Incrementa o contador de comparações

            // Verifica se o elemento atual é menor que o mínimo encontrado até agora
            if (arr[j] < arr[minIndex]) {
                minIndex = j;  // Atualiza o índice do menor elemento
            }
        }

        // Troca o elemento atual (índice i) com o menor elemento encontrado (minIndex)
        swap(arr[i], arr[minIndex]);
        movements++;
    }
}

// Algoritmo Insertion Sort
void insertionSort(int arr[], int n, long long& comparisons, long long& movements) {
    comparisons = 0; 
    movements = 0;   

    // Loop que percorre o array a partir do segundo elemento até o último
    for (int i = 1; i < n; ++i) {
        int key = arr[i];  // Armazena o valor do elemento atual como a chave a ser inserida
        int j = i - 1;     // Inicializa o índice do elemento anterior ao elemento atual

        // Move os elementos maiores que a chave para a frente do array
        while (j >= 0 && arr[j] > key) {
            comparisons++; 
            arr[j + 1] = arr[j];  // Move o elemento maior para frente
            movements++;      // Incrementa o contador de movimentos
            j--;             // Move para o próximo elemento à esquerda
        }
        arr[j + 1] = key;  // Insere a chave na posição correta no array ordenado
        movements++; 
    }
}

// Algoritmo Shell Sort
void shellSort(int arr[], int n, long long& comparisons, long long& movements) {
    comparisons = 0;  
    movements = 0;   
    
    // Loop para reduzir o tamanho do intervalo (gap) a cada iteração
    for (int gap = n / 2; gap > 0; gap /= 2) {
        // Loop para percorrer o array com o intervalo (gap)
        for (int i = gap; i < n; ++i) {
            int temp = arr[i];  // Armazena o valor do elemento atual
            int j;

            // Loop para realizar a inserção por comparação com elementos distantes gap posições
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                comparisons++; 
                arr[j] = arr[j - gap];  // Move os elementos maiores que o valor atual para frente
                movements++;      // Incrementa o contador de movimentos
            }

            arr[j] = temp;  // Insere o valor armazenado na posição correta
            movements++; 
        }
    }
}

// Algoritmo Quick Sort
void quickSort(int arr[], int size, long long& comparisons, long long& movements) {
    if (size < 2) {
        return;  // Condição de saída da recursão quando o tamanho do array é menor que 2
    }

    int pivot = arr[size - 1];  // Escolhe o último elemento do array como pivô
    int i = 0;

    // Particionamento do array ao redor do pivô
    for (int j = 0; j < size - 1; j++) {
        comparisons++;  // Incrementa o contador de comparações
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);  // Troca os elementos menores que o pivô para a esquerda
            movements++; 
        }
    }
    swap(arr[i + 1], arr[size - 1]);  // Coloca o pivô na posição correta
    movements++;

    int pi = i + 1;  // Obtem o índice do pivô após o particionamento

    // Chamadas recursivas para ordenar as partições esquerda e direita do pivô
    quickSort(arr, pi, comparisons, movements);  // Partição esquerda
    quickSort(arr + pi + 1, size - pi - 1, comparisons, movements);  // Partição direita
}

// Algoritmo Heap Sort
void heapSort(int arr[], int n, long long& comparisons, long long& movements) {
    comparisons = 0;  
    movements = 0;   

    // Fase de construção do heap máximo
    for (int i = n / 2 - 1; i >= 0; i--) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        // Verifica se o filho da esquerda é maior que o pai
        if (left < n && arr[left] > arr[largest]) {
            comparisons++;
            largest = left;
        }

        // Verifica se o filho da direita é maior que o pai ou o filho da esquerda
        if (right < n && arr[right] > arr[largest]) {
            comparisons++;
            largest = right;
        }

        // Se o maior elemento não estiver na posição corrente, faz a troca e ajusta o heap
        if (largest != i) {
            swap(arr[i], arr[largest]);
            movements++;
            i--;  // Ajuste do índice após a troca
        }
    }

    // Fase de extração do heap máximo
    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);  // Move o maior elemento para o final
        movements++;

        int largest = 0;
        int left = 1;
        int right = 2;

        // Verifica se o filho da esquerda é maior que o pai
        if (left < i && arr[left] > arr[largest]) {
            comparisons++;
            largest = left;
        }

        // Verifica se o filho da direita é maior que o pai ou o filho da esquerda
        if (right < i && arr[right] > arr[largest]) {
            comparisons++;
            largest = right;
        }

        // Se o maior elemento não estiver na posição corrente, faz a troca e ajusta o heap
        if (largest != 0) {
            swap(arr[0], arr[largest]);
            movements++;
            i--;  // Ajuste do índice após a troca
        }
    }
}

// Algoritmo Merge Sort
void mergeSort(int arr[], int size, long long& comparisons, long long& movements) {
    // Verifica se o tamanho do array é menor que 2, o que significa que está ordenado
    if (size < 2) {
        return;
    }

    // Divide o array ao meio
    int mid = size / 2;
    int left[mid], right[size - mid];

    // Copia os elementos para os arrays esquerdo e direito
    for (int i = 0; i < mid; i++) {
        left[i] = arr[i];
    }
    for (int i = mid; i < size; i++) {
        right[i - mid] = arr[i];
    }

    // Chama recursivamente o mergeSort para os arrays esquerdo e direito
    mergeSort(left, mid, comparisons, movements);
    mergeSort(right, size - mid, comparisons, movements);

    // Inicializa os índices para os arrays esquerdo, direito e original
    int i = 0, j = 0, k = 0;

    // Combina os arrays esquerdo e direito em um único array ordenado
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

    // Copia os elementos restantes do array esquerdo, se houver
    while (i < mid) {
        arr[k] = left[i];
        movements++;
        i++;
        k++;
    }

    // Copia os elementos restantes do array direito, se houver
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
        arr[i] = rand() % 1000;
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


void printArray(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
}

int main() {
    int sizes[] = {100, 1000, 10000, 100000};
    string types[] = {"Random", "Sorted"};

    string algorithms[] = {"Bubble Sort", "Selection Sort", "Insertion Sort", "Shell Sort", "Quick Sort", "Heap Sort", "Merge Sort"};

    cout << "Array Size,Type,Algorithm,Time taken,Comparisons,Movements" << endl;

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
           
            // cout << "Array antes da ordenação (" << type << ", tamanho " << size << "): ";
            // printArray(arr, size);
            // cout << endl;

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

                // cout << "Array após ciclos dos algoritmos (" << type << ", tamanho " << size << "): ";
                // printArray(arr, size);
                // cout << endl;

                cout << size << "," << type << "," << algorithm << "," << fixed << setprecision(6) << timeTaken << "," << comparisons << "," << movements << endl;
            }
            delete[] arr;
        }
    }
    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// ===== СОРТИРОВКА ВЫБОРОМ =====
/**
 * Сортировка выбором - находит минимальный элемент в неотсортированной части
 * и помещает его в начало отсортированной части.
 * Временная сложность: O(n²) - внешний цикл n раз, внутренний в среднем n/2 раз
 */
void selectionSort(vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        int minIndex = i;
        for (int j = i + 1; j < arr.size(); j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

// ===== СОРТИРОВКА ПУЗЫРЬКОМ =====
/**
 * Сортировка пузырьком - многократно проходит по массиву, сравнивая соседние элементы
 * и меняя их местами при неправильном порядке.
 * Временная сложность: O(n²) - в худшем случае n(n-1)/2 сравнений
 */
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

// ===== СОРТИРОВКА ВСТАВКАМИ =====
/**
 * Сортировка вставками - строит отсортированную последовательность,
 * постепенно вставляя элементы на правильные позиции.
 * Временная сложность: O(n²) - в худшем случае n(n-1)/2 операций
 */
void insertionSort(vector<int>& arr) {
    for (int i = 1; i < arr.size(); i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// ===== СОРТИРОВКА СЛИЯНИЕМ =====
/**
 * Сортировка слиянием - алгоритм "разделяй и властвуй", который рекурсивно
 * разделяет массив на две части, сортирует их и объединяет.
 * Временная сложность: O(n log n) - log n уровней рекурсии, на каждом n операций
 */
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    vector<int> L(n1), R(n2);
    
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
        
    int i = 0, j = 0, k = left;
    
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left >= right) return;
    
    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

// ===== СОРТИРОВКА ШЕЛЛА =====
/**
 * Сортировка Шелла - улучшенная версия сортировки вставками, которая сортирует
 * элементы на определенных расстояниях, постепенно уменьшая промежуток до 1.
 * Временная сложность: O(n²) в худшем случае, O(n log² n) в лучшем
 */
void shellSort(vector<int>& arr) {
    int n = arr.size();
    
    for (int gap = n/2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

// ===== БЫСТРАЯ СОРТИРОВКА =====
/**
 * Быстрая сортировка - алгоритм "разделяй и властвуй", который выбирает опорный элемент
 * и разделяет массив на элементы меньше, равные и больше опорного.
 * Временная сложность: O(n log n) в среднем, O(n²) в худшем случае
 */
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// ===== ПИРАМИДАЛЬНАЯ СОРТИРОВКА =====
/**
 * Пирамидальная сортировка - использует структуру данных "куча" для сортировки элементов.
 * Временная сложность: O(n log n) - построение кучи O(n), n извлечений по O(log n)
 */
void heapify(vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    
    if (left < n && arr[left] > arr[largest])
        largest = left;
        
    if (right < n && arr[right] > arr[largest])
        largest = right;
        
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(vector<int>& arr) {
    int n = arr.size();
    
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
        
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

// ===== ПОИСКОВЫЕ АЛГОРИТМЫ =====

/**
 * Линейный поиск - последовательно проверяет каждый элемент массива.
 * Временная сложность: O(n) - в худшем случае проверяет все n элементов
 */
int linearSearch(const vector<int>& arr, int target) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

/**
 * Бинарный поиск - эффективный поиск в отсортированном массиве, 
 * на каждом шаге делит область поиска пополам.
 * Временная сложность: O(log n) - максимальное количество шагов log₂n
 */
int binarySearch(const vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] == target) {
            return mid;
        }
        
        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return -1;
}

// ===== ВСПОМОГАТЕЛЬНЫЕ ФУНКЦИИ =====
void printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

// ===== ОСНОВНАЯ ПРОГРАММА =====
int main() {
    cout << "=== СОРТИРОВКА ВЫБОРОМ ===" << endl;
    vector<int> arr1 = {64, 25, 12, 22, 11};
    cout << "Исходный массив: ";
    printArray(arr1);
    selectionSort(arr1);
    cout << "Отсортированный массив: ";
    printArray(arr1);
    
    cout << "\n=== СОРТИРОВКА ПУЗЫРЬКОМ ===" << endl;
    vector<int> arr2 = {64, 34, 25, 12, 22, 11, 90};
    cout << "Исходный массив: ";
    printArray(arr2);
    bubbleSort(arr2);
    cout << "Отсортированный массив: ";
    printArray(arr2);
    
    cout << "\n=== СОРТИРОВКА ВСТАВКАМИ ===" << endl;
    vector<int> arr3 = {12, 11, 13, 5, 6};
    cout << "Исходный массив: ";
    printArray(arr3);
    insertionSort(arr3);
    cout << "Отсортированный массив: ";
    printArray(arr3);
    
    cout << "\n=== СОРТИРОВКА СЛИЯНИЕМ ===" << endl;
    vector<int> arr4 = {38, 27, 43, 3, 9, 82, 10};
    cout << "Исходный массив: ";
    printArray(arr4);
    mergeSort(arr4, 0, arr4.size()-1);
    cout << "Отсортированный массив: ";
    printArray(arr4);
    
    cout << "\n=== СОРТИРОВКА ШЕЛЛА ===" << endl;
    vector<int> arr5 = {12, 34, 54, 2, 3};
    cout << "Исходный массив: ";
    printArray(arr5);
    shellSort(arr5);
    cout << "Отсортированный массив: ";
    printArray(arr5);
    
    cout << "\n=== БЫСТРАЯ СОРТИРОВКА ===" << endl;
    vector<int> arr6 = {10, 7, 8, 9, 1, 5};
    cout << "Исходный массив: ";
    printArray(arr6);
    quickSort(arr6, 0, arr6.size()-1);
    cout << "Отсортированный массив: ";
    printArray(arr6);
    
    cout << "\n=== ПИРАМИДАЛЬНАЯ СОРТИРОВКА ===" << endl;
    vector<int> arr7 = {12, 11, 13, 5, 6, 7};
    cout << "Исходный массив: ";
    printArray(arr7);
    heapSort(arr7);
    cout << "Отсортированный массив: ";
    printArray(arr7);
    
    cout << "\n=== ПОИСКОВЫЕ АЛГОРИТМЫ ===" << endl;
    vector<int> searchArr = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int target = 7;
    
    cout << "Массив для поиска: ";
    printArray(searchArr);
    cout << "Искомый элемент: " << target << endl;
    
    int linearResult = linearSearch(searchArr, target);
    cout << "Линейный поиск: элемент на позиции " << linearResult << endl;
    
    int binaryResult = binarySearch(searchArr, target);
    cout << "Бинарный поиск: элемент на позиции " << binaryResult << endl;
    
    return 0;
}

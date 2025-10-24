#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// ===== СОРТИРОВКА ВСТАВКАМИ =====
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

// ===== БИНАРНЫЙ ПОИСК =====
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

// ===== ФУНКЦИИ ДЛЯ ВЫВОДА МАССИВА =====
void printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

// ===== ОСНОВНАЯ ПРОГРАММА =====
int main() {
    cout << "=== СОРТИРОВКА ВСТАВКАМИ ===" << endl;
    vector<int> arr1 = {12, 11, 13, 5, 6};
    cout << "Исходный массив: ";
    printArray(arr1);
    
    insertionSort(arr1);
    
    cout << "Отсортированный массив: ";
    printArray(arr1);
    
    cout << "\n=== БИНАРНЫЙ ПОИСК ===" << endl;
    vector<int> sortedArray = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int target = 7;
    
    cout << "Отсортированный массив: ";
    printArray(sortedArray);
    cout << "Искомый элемент: " << target << endl;
    
    int result = binarySearch(sortedArray, target);
    
    if (result != -1) {
        cout << "Элемент найден на позиции: " << result << endl;
    } else {
        cout << "Элемент не найден" << endl;
    }
    
    return 0;
}

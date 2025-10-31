import java.util.Arrays;

/**
 * Класс Algorithms содержит реализации различных алгоритмов сортировки и поиска
 * с объяснением временной сложности каждого алгоритма.
 */
public class Algorithms {
    
    // ===== СОРТИРОВКА ВЫБОРОМ =====
    /**
     * Сортировка выбором - находит минимальный элемент в неотсортированной части
     * и помещает его в начало отсортированной части.
     * Временная сложность: O(n²) - внешний цикл n раз, внутренний в среднем n/2 раз
     */
    public static void selectionSort(int[] arr) {
        for (int i = 0; i < arr.length; i++) {
            int minIndex = i;
            for (int j = i + 1; j < arr.length; j++) {
                if (arr[j] < arr[minIndex]) {
                    minIndex = j;
                }
            }
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
    
    // ===== СОРТИРОВКА ПУЗЫРЬКОМ =====
    /**
     * Сортировка пузырьком - многократно проходит по массиву, сравнивая соседние элементы
     * и меняя их местами при неправильном порядке.
     * Временная сложность: O(n²) - в худшем случае n(n-1)/2 сравнений
     */
    public static void bubbleSort(int[] arr) {
        int n = arr.length;
        for (int i = 0; i < n-1; i++) {
            for (int j = 0; j < n-i-1; j++) {
                if (arr[j] > arr[j+1]) {
                    int temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
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
    public static void insertionSort(int[] arr) {
        for (int i = 1; i < arr.length; i++) {
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
    public static void mergeSort(int[] arr, int left, int right) {
        if (left < right) {
            int mid = left + (right - left) / 2;
            
            mergeSort(arr, left, mid);
            mergeSort(arr, mid + 1, right);
            
            merge(arr, left, mid, right);
        }
    }
    
    private static void merge(int[] arr, int left, int mid, int right) {
        int n1 = mid - left + 1;
        int n2 = right - mid;
        
        int[] L = new int[n1];
        int[] R = new int[n2];
        
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
    
    // ===== БЫСТРАЯ СОРТИРОВКА =====
    /**
     * Быстрая сортировка - алгоритм "разделяй и властвуй", который выбирает опорный элемент
     * и разделяет массив на элементы меньше, равные и больше опорного.
     * Временная сложность: O(n log n) в среднем, O(n²) в худшем случае
     */
    public static void quickSort(int[] arr, int low, int high) {
        if (low < high) {
            int pi = partition(arr, low, high);
            
            quickSort(arr, low, pi - 1);
            quickSort(arr, pi + 1, high);
        }
    }
    
    private static int partition(int[] arr, int low, int high) {
        int pivot = arr[high];
        int i = (low - 1);
        
        for (int j = low; j <= high - 1; j++) {
            if (arr[j] < pivot) {
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        int temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;
        
        return i + 1;
    }
    
    // ===== ПИРАМИДАЛЬНАЯ СОРТИРОВКА =====
    /**
     * Пирамидальная сортировка - использует структуру данных "куча" для сортировки элементов.
     * Временная сложность: O(n log n) - построение кучи O(n), n извлечений по O(log n)
     */
    public static void heapSort(int[] arr) {
        int n = arr.length;
        
        for (int i = n / 2 - 1; i >= 0; i--)
            heapify(arr, n, i);
            
        for (int i = n - 1; i > 0; i--) {
            int temp = arr[0];
            arr[0] = arr[i];
            arr[i] = temp;
            
            heapify(arr, i, 0);
        }
    }
    
    private static void heapify(int[] arr, int n, int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        
        if (left < n && arr[left] > arr[largest])
            largest = left;
            
        if (right < n && arr[right] > arr[largest])
            largest = right;
            
        if (largest != i) {
            int swap = arr[i];
            arr[i] = arr[largest];
            arr[largest] = swap;
            
            heapify(arr, n, largest);
        }
    }
    
    // ===== ПОИСКОВЫЕ АЛГОРИТМЫ =====
    
    /**
     * Линейный поиск - последовательно проверяет каждый элемент массива.
     * Временная сложность: O(n) - в худшем случае проверяет все n элементов
     */
    public static int linearSearch(int[] arr, int target) {
        for (int i = 0; i < arr.length; i++) {
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
    public static int binarySearch(int[] arr, int target) {
        int left = 0;
        int right = arr.length - 1;
        
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
    
    // ===== ВСПОМОГАТЕЛЬНЫЕ МЕТОДЫ =====
    public static void printArray(int[] arr) {
        for (int num : arr) {
            System.out.print(num + " ");
        }
        System.out.println();
    }
    
    // ===== ОСНОВНОЙ МЕТОД =====
    public static void main(String[] args) {
        System.out.println("=== СОРТИРОВКА ВЫБОРОМ ===");
        int[] arr1 = {64, 25, 12, 22, 11};
        System.out.print("Исходный массив: ");
        printArray(arr1);
        selectionSort(arr1);
        System.out.print("Отсортированный массив: ");
        printArray(arr1);
        
        System.out.println("\n=== СОРТИРОВКА ПУЗЫРЬКОМ ===");
        int[] arr2 = {64, 34, 25, 12, 22, 11, 90};
        System.out.print("Исходный массив: ");
        printArray(arr2);
        bubbleSort(arr2);
        System.out.print("Отсортированный массив: ");
        printArray(arr2);
        
        System.out.println("\n=== СОРТИРОВКА ВСТАВКАМИ ===");
        int[] arr3 = {12, 11, 13, 5, 6};
        System.out.print("Исходный массив: ");
        printArray(arr3);
        insertionSort(arr3);
        System.out.print("Отсортированный массив: ");
        printArray(arr3);
        
        System.out.println("\n=== СОРТИРОВКА СЛИЯНИЕМ ===");
        int[] arr4 = {38, 27, 43, 3, 9, 82, 10};
        System.out.print("Исходный массив: ");
        printArray(arr4);
        mergeSort(arr4, 0, arr4.length-1);
        System.out.print("Отсортированный массив: ");
        printArray(arr4);
        
        System.out.println("\n=== БЫСТРАЯ СОРТИРОВКА ===");
        int[] arr5 = {10, 7, 8, 9, 1, 5};
        System.out.print("Исходный массив: ");
        printArray(arr5);
        quickSort(arr5, 0, arr5.length-1);
        System.out.print("Отсортированный массив: ");
        printArray(arr5);
        
        System.out.println("\n=== ПИРАМИДАЛЬНАЯ СОРТИРОВКА ===");
        int[] arr6 = {12, 11, 13, 5, 6, 7};
        System.out.print("Исходный массив: ");
        printArray(arr6);
        heapSort(arr6);
        System.out.print("Отсортированный массив: ");
        printArray(arr6);
        
        System.out.println("\n=== ПОИСКОВЫЕ АЛГОРИТМЫ ===");
        int[] searchArr = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
        int target = 7;
        
        System.out.print("Массив для поиска: ");
        printArray(searchArr);
        System.out.println("Искомый элемент: " + target);
        
        int linearResult = linearSearch(searchArr, target);
        System.out.println("Линейный поиск: элемент на позиции " + linearResult);
        
        int binaryResult = binarySearch(searchArr, target);
        System.out.println("Бинарный поиск: элемент на позиции " + binaryResult);
    }
}
[file content end]

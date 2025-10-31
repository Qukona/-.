def selection_sort(arr):
    """
    Сортировка выбором - находит минимальный элемент в неотсортированной части
    и помещает его в начало отсортированной части.
    Временная сложность: O(n²) - внешний цикл n раз, внутренний в среднем n/2 раз
    """
    for i in range(len(arr)):
        min_index = i
        for j in range(i + 1, len(arr)):
            if arr[j] < arr[min_index]:
                min_index = j
        arr[i], arr[min_index] = arr[min_index], arr[i]

def bubble_sort(arr):
    """
    Сортировка пузырьком - многократно проходит по массиву, сравнивая соседние элементы
    и меняя их местами при неправильном порядке.
    Временная сложность: O(n²) - в худшем случае n(n-1)/2 сравнений
    """
    n = len(arr)
    for i in range(n):
        for j in range(0, n - i - 1):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]

def insertion_sort(arr):
    """
    Сортировка вставками - строит отсортированную последовательность,
    постепенно вставляя элементы на правильные позиции.
    Временная сложность: O(n²) - в худшем случае n(n-1)/2 операций
    """
    for i in range(1, len(arr)):
        key = arr[i]
        j = i - 1
        while j >= 0 and arr[j] > key:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key

def merge_sort(arr):
    """
    Сортировка слиянием - алгоритм "разделяй и властвуй", который рекурсивно
    разделяет массив на две части, сортирует их и объединяет.
    Временная сложность: O(n log n) - log n уровней рекурсии, на каждом n операций
    """
    if len(arr) > 1:
        mid = len(arr) // 2
        left = arr[:mid]
        right = arr[mid:]

        merge_sort(left)
        merge_sort(right)

        i = j = k = 0

        while i < len(left) and j < len(right):
            if left[i] <= right[j]:
                arr[k] = left[i]
                i += 1
            else:
                arr[k] = right[j]
                j += 1
            k += 1

        while i < len(left):
            arr[k] = left[i]
            i += 1
            k += 1

        while j < len(right):
            arr[k] = right[j]
            j += 1
            k += 1

def shell_sort(arr):
    """
    Сортировка Шелла - улучшенная версия сортировки вставками, которая сортирует
    элементы на определенных расстояниях, постепенно уменьшая промежуток до 1.
    Временная сложность: O(n²) в худшем случае, O(n log² n) в лучшем
    """
    n = len(arr)
    gap = n // 2

    while gap > 0:
        for i in range(gap, n):
            temp = arr[i]
            j = i
            while j >= gap and arr[j - gap] > temp:
                arr[j] = arr[j - gap]
                j -= gap
            arr[j] = temp
        gap //= 2

def quick_sort(arr):
    """
    Быстрая сортировка - алгоритм "разделяй и властвуй", который выбирает опорный элемент
    и разделяет массив на элементы меньше, равные и больше опорного.
    Временная сложность: O(n log n) в среднем, O(n²) в худшем случае
    """
    if len(arr) <= 1:
        return arr
    pivot = arr[len(arr) // 2]
    left = [x for x in arr if x < pivot]
    middle = [x for x in arr if x == pivot]
    right = [x for x in arr if x > pivot]
    return quick_sort(left) + middle + quick_sort(right)

def heapify(arr, n, i):
    largest = i
    left = 2 * i + 1
    right = 2 * i + 2

    if left < n and arr[left] > arr[largest]:
        largest = left

    if right < n and arr[right] > arr[largest]:
        largest = right

    if largest != i:
        arr[i], arr[largest] = arr[largest], arr[i]
        heapify(arr, n, largest)

def heap_sort(arr):
    """
    Пирамидальная сортировка - использует структуру данных "куча" для сортировки элементов.
    Временная сложность: O(n log n) - построение кучи O(n), n извлечений по O(log n)
    """
    n = len(arr)

    for i in range(n // 2 - 1, -1, -1):
        heapify(arr, n, i)

    for i in range(n - 1, 0, -1):
        arr[i], arr[0] = arr[0], arr[i]
        heapify(arr, i, 0)

def linear_search(arr, target):
    """
    Линейный поиск - последовательно проверяет каждый элемент массива.
    Временная сложность: O(n) - в худшем случае проверяет все n элементов
    """
    for i in range(len(arr)):
        if arr[i] == target:
            return i
    return -1

def binary_search(arr, target):
    """
    Бинарный поиск - эффективный поиск в отсортированном массиве, 
    на каждом шаге делит область поиска пополам.
    Временная сложность: O(log n) - максимальное количество шагов log₂n
    """
    left = 0
    right = len(arr) - 1

    while left <= right:
        mid = (left + right) // 2

        if arr[mid] == target:
            return mid

        if arr[mid] < target:
            left = mid + 1
        else:
            right = mid - 1

    return -1

# Демонстрация работы алгоритмов
if __name__ == "__main__":
    print("=== СОРТИРОВКА ВЫБОРОМ ===")
    arr1 = [64, 25, 12, 22, 11]
    print("Исходный массив:", arr1)
    selection_sort(arr1)
    print("Отсортированный массив:", arr1)

    print("\n=== СОРТИРОВКА ПУЗЫРЬКОМ ===")
    arr2 = [64, 34, 25, 12, 22, 11, 90]
    print("Исходный массив:", arr2)
    bubble_sort(arr2)
    print("Отсортированный массив:", arr2)

    print("\n=== СОРТИРОВКА ВСТАВКАМИ ===")
    arr3 = [12, 11, 13, 5, 6]
    print("Исходный массив:", arr3)
    insertion_sort(arr3)
    print("Отсортированный массив:", arr3)

    print("\n=== СОРТИРОВКА СЛИЯНИЕМ ===")
    arr4 = [38, 27, 43, 3, 9, 82, 10]
    print("Исходный массив:", arr4)
    merge_sort(arr4)
    print("Отсортированный массив:", arr4)

    print("\n=== СОРТИРОВКА ШЕЛЛА ===")
    arr5 = [12, 34, 54, 2, 3]
    print("Исходный массив:", arr5)
    shell_sort(arr5)
    print("Отсортированный массив:", arr5)

    print("\n=== БЫСТРАЯ СОРТИРОВКА ===")
    arr6 = [10, 7, 8, 9, 1, 5]
    print("Исходный массив:", arr6)
    sorted_arr6 = quick_sort(arr6)
    print("Отсортированный массив:", sorted_arr6)

    print("\n=== ПИРАМИДАЛЬНАЯ СОРТИРОВКА ===")
    arr7 = [12, 11, 13, 5, 6, 7]
    print("Исходный массив:", arr7)
    heap_sort(arr7)
    print("Отсортированный массив:", arr7)

    print("\n=== ПОИСКОВЫЕ АЛГОРИТМЫ ===")
    search_arr = [1, 3, 5, 7, 9, 11, 13, 15, 17, 19]
    target = 7
    
    print("Массив для поиска:", search_arr)
    print("Искомый элемент:", target)
    
    linear_result = linear_search(search_arr, target)
    print("Линейный поиск: элемент на позиции", linear_result)
    
    binary_result = binary_search(search_arr, target)
    print("Бинарный поиск: элемент на позиции", binary_result)

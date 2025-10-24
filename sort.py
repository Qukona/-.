# ===== СОРТИРОВКА ВЫБОРОМ =====
def selection_sort(arr):
    for i in range(len(arr)):
        min_index = i
        for j in range(i + 1, len(arr)):
            if arr[j] < arr[min_index]:
                min_index = j
        arr[i], arr[min_index] = arr[min_index], arr[i]

# ===== СОРТИРОВКА ПУЗЫРЬКОМ =====
def bubble_sort(arr):
    n = len(arr)
    for i in range(n):
        for j in range(0, n - i - 1):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]

# ===== СОРТИРОВКА ВСТАВКАМИ =====
def insertion_sort(arr):
    for i in range(1, len(arr)):
        key = arr[i]
        j = i - 1
        while j >= 0 and arr[j] > key:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key

# ===== СОРТИРОВКА СЛИЯНИЕМ =====
def merge_sort(arr):
    if len(arr) <= 1:
        return arr
    
    mid = len(arr) // 2
    left = arr[:mid]
    right = arr[mid:]
    
    left = merge_sort(left)
    right = merge_sort(right)
    
    return merge(left, right)

def merge(left, right):
    result = []
    i = j = 0
    
    while i < len(left) and j < len(right):
        if left[i] < right[j]:
            result.append(left[i])
            i += 1
        else:
            result.append(right[j])
            j += 1
    
    result.extend(left[i:])
    result.extend(right[j:])
    return result

# ===== СОРТИРОВКА ШЕЛЛА =====
def shell_sort(arr):
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

# ===== БЫСТРАЯ СОРТИРОВКА =====
def quick_sort(arr):
    if len(arr) <= 1:
        return arr
    
    pivot = arr[len(arr) // 2]
    left = [x for x in arr if x < pivot]
    middle = [x for x in arr if x == pivot]
    right = [x for x in arr if x > pivot]
    
    return quick_sort(left) + middle + quick_sort(right)

# ===== ПИРАМИДАЛЬНАЯ СОРТИРОВКА =====
def heapify(arr, n, i):
    largest = i
    left = 2 * i + 1
    right = 2 * i + 2
    
    if left < n and arr[i] < arr[left]:
        largest = left
        
    if right < n and arr[largest] < arr[right]:
        largest = right
        
    if largest != i:
        arr[i], arr[largest] = arr[largest], arr[i]
        heapify(arr, n, largest)

def heap_sort(arr):
    n = len(arr)
    
    for i in range(n // 2 - 1, -1, -1):
        heapify(arr, n, i)
        
    for i in range(n - 1, 0, -1):
        arr[i], arr[0] = arr[0], arr[i]
        heapify(arr, i, 0)

# ===== ПОИСКОВЫЕ АЛГОРИТМЫ =====
def linear_search(arr, target):
    for i in range(len(arr)):
        if arr[i] == target:
            return i
    return -1

def binary_search(arr, target):
    left, right = 0, len(arr) - 1
    
    while left <= right:
        mid = (left + right) // 2
        if arr[mid] == target:
            return mid
        elif arr[mid] < target:
            left = mid + 1
        else:
            right = mid - 1
    return -1

def interpolation_search(arr, lo, hi, x):
    if lo <= hi and arr[lo] <= x <= arr[hi]:
        pos = lo + ((hi - lo) * (x - arr[lo])) // (arr[hi] - arr[lo])
        
        if arr[pos] == x:
            return pos
        elif arr[pos] < x:
            return interpolation_search(arr, pos + 1, hi, x)
        else:
            return interpolation_search(arr, lo, pos - 1, x)
    return -1

# ===== ПРИМЕРЫ ИСПОЛЬЗОВАНИЯ =====
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
    sorted_arr4 = merge_sort(arr4)
    print("Отсортированный массив:", sorted_arr4)
    
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
    print(f"Линейный поиск: элемент на позиции {linear_result}")
    
    binary_result = binary_search(search_arr, target)
    print(f"Бинарный поиск: элемент на позиции {binary_result}")
    
    interp_result = interpolation_search(search_arr, 0, len(search_arr)-1, target)
    print(f"Интерполяционный поиск: элемент на позиции {interp_result}")

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

# ===== ЛИНЕЙНЫЙ ПОИСК =====
def linear_search(arr, target):
    for i in range(len(arr)):
        if arr[i] == target:
            return i
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
    
    print("\n=== СОРТИРОВКА ШЕЛЛА ===")
    arr3 = [12, 34, 54, 2, 3]
    print("Исходный массив:", arr3)
    shell_sort(arr3)
    print("Отсортированный массив:", arr3)
    
    print("\n=== БЫСТРАЯ СОРТИРОВКА ===")
    arr4 = [10, 7, 8, 9, 1, 5]
    print("Исходный массив:", arr4)
    sorted_arr4 = quick_sort(arr4)
    print("Отсортированный массив:", sorted_arr4)
    
    print("\n=== ЛИНЕЙНЫЙ ПОИСК ===")
    arr5 = [3, 5, 2, 7, 9, 1, 4]
    target = 7
    print("Массив:", arr5)
    print("Искомый элемент:", target)
    result = linear_search(arr5, target)
    if result != -1:
        print(f"Элемент найден на позиции: {result}")
    else:
        print("Элемент не найден")

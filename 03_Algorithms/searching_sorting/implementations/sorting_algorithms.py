def bubble_sort(arr):
    """
    Bubble Sort - O(n²)
    Repeatedly swaps adjacent elements if they are in wrong order
    """
    n = len(arr)
    for i in range(n - 1):
        for j in range(n - i - 1):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
    return arr


def selection_sort(arr):
    """
    Selection Sort - O(n²)
    Finds minimum element and places it at beginning
    """
    n = len(arr)
    for i in range(n - 1):
        min_idx = i
        for j in range(i + 1, n):
            if arr[j] < arr[min_idx]:
                min_idx = j
        arr[i], arr[min_idx] = arr[min_idx], arr[i]
    return arr


def insertion_sort(arr):
    """
    Insertion Sort - O(n²)
    Builds sorted array one element at a time
    """
    n = len(arr)
    for i in range(1, n):
        key = arr[i]
        j = i - 1
        
        while j >= 0 and arr[j] > key:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key
    return arr


def merge(arr, left, mid, right):
    """Merge two sorted subarrays"""
    n1 = mid - left + 1
    n2 = right - mid
    
    L = arr[left:mid + 1]
    R = arr[mid + 1:right + 1]
    
    i = j = k = 0
    
    while i < n1 and j < n2:
        if L[i] <= R[j]:
            arr[k] = L[i]
            i += 1
        else:
            arr[k] = R[j]
            j += 1
        k += 1
    
    while i < n1:
        arr[k] = L[i]
        i += 1
        k += 1
    
    while j < n2:
        arr[k] = R[j]
        j += 1
        k += 1


def merge_sort(arr, left=0, right=None):
    """
    Merge Sort - O(n log n)
    Divide and conquer sorting algorithm
    """
    if right is None:
        right = len(arr) - 1
    
    if left < right:
        mid = left + (right - left) // 2
        merge_sort(arr, left, mid)
        merge_sort(arr, mid + 1, right)
        merge(arr, left, mid, right)


def partition(arr, low, high):
    """Partition function for Quick Sort"""
    pivot = arr[high]
    i = low - 1
    
    for j in range(low, high):
        if arr[j] < pivot:
            i += 1
            arr[i], arr[j] = arr[j], arr[i]
    
    arr[i + 1], arr[high] = arr[high], arr[i + 1]
    return i + 1


def quick_sort(arr, low=0, high=None):
    """
    Quick Sort - O(n log n) average, O(n²) worst
    Partition-based sorting algorithm
    """
    if high is None:
        high = len(arr) - 1
    
    if low < high:
        pi = partition(arr, low, high)
        quick_sort(arr, low, pi - 1)
        quick_sort(arr, pi + 1, high)


def heapify(arr, n, i):
    """Heapify a subtree rooted at index i"""
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
    Heap Sort - O(n log n)
    Uses binary heap data structure
    """
    n = len(arr)
    
    # Build max heap
    for i in range(n // 2 - 1, -1, -1):
        heapify(arr, n, i)
    
    # Extract elements from heap
    for i in range(n - 1, 0, -1):
        arr[0], arr[i] = arr[i], arr[0]
        heapify(arr, i, 0)


def test_sorting_algorithms():
    """Test all sorting algorithms"""
    arr = [64, 34, 25, 12, 22, 11, 90]
    
    print("Original array:", arr)
    
    # Test each sorting algorithm
    test_arr = arr.copy()
    print("\nBubble Sort:", bubble_sort(test_arr))
    
    test_arr = arr.copy()
    print("Selection Sort:", selection_sort(test_arr))
    
    test_arr = arr.copy()
    print("Insertion Sort:", insertion_sort(test_arr))
    
    test_arr = arr.copy()
    print("Merge Sort:", merge_sort(test_arr))
    
    test_arr = arr.copy()
    print("Quick Sort:", quick_sort(test_arr))
    
    test_arr = arr.copy()
    print("Heap Sort:", heap_sort(test_arr))


if __name__ == "__main__":
    test_sorting_algorithms()
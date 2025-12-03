def linear_search(arr, target):
    """
    Linear Search - O(n)
    Searches for target by checking each element sequentially
    """
    for i, num in enumerate(arr):
        if num == target:
            return i  # Return index if found
    return -1  # Return -1 if not found


def binary_search(arr, target):
    """
    Binary Search - O(log n)
    Requires sorted array
    Uses divide and conquer approach
    """
    left, right = 0, len(arr) - 1
    
    while left <= right:
        mid = left + (right - left) // 2  # Prevent overflow
        
        if arr[mid] == target:
            return mid  # Found target
        elif arr[mid] < target:
            left = mid + 1  # Search right half
        else:
            right = mid - 1  # Search left half
    
    return -1  # Target not found


def ternary_search(arr, target, left=0, right=None):
    """
    Ternary Search - O(log3 n)
    Requires sorted array
    Divides array into three parts
    """
    if right is None:
        right = len(arr) - 1
    
    if left > right:
        return -1
    
    # Calculate two mid points
    mid1 = left + (right - left) // 3
    mid2 = right - (right - left) // 3
    
    if arr[mid1] == target:
        return mid1
    if arr[mid2] == target:
        return mid2
    
    # Recursively search in the appropriate third
    if target < arr[mid1]:
        return ternary_search(arr, target, left, mid1 - 1)
    elif target > arr[mid2]:
        return ternary_search(arr, target, mid2 + 1, right)
    else:
        return ternary_search(arr, target, mid1 + 1, mid2 - 1)


def jump_search(arr, target):
    """
    Jump Search - O(√n)
    Jumps by block size to find target range
    """
    n = len(arr)
    if n == 0:
        return -1
    
    step = int(n ** 0.5)  # Optimal block size
    prev = 0
    
    # Find block where target might be present
    while arr[min(step, n) - 1] < target:
        prev = step
        step += int(n ** 0.5)
        if prev >= n:
            return -1
    
    # Linear search in found block
    while arr[prev] < target:
        prev += 1
        if prev == min(step, n):
            return -1
    
    return prev if arr[prev] == target else -1


def exponential_search(arr, target):
    """
    Exponential Search - O(log n)
    Useful for unbounded or infinite arrays
    """
    if not arr:
        return -1
    
    # Find range where target might be present
    if arr[0] == target:
        return 0
    
    i = 1
    while i < len(arr) and arr[i] <= target:
        i *= 2
    
    # Perform binary search in found range
    return binary_search(arr[:min(i, len(arr))], target)


def test_search_algorithms():
    """Test all search algorithms"""
    arr = [2, 5, 8, 12, 16, 23, 38, 56, 72, 91]
    target = 23
    
    print("Array:", arr)
    print(f"Target: {target}\n")
    
    print(f"Linear Search: {linear_search(arr, target)}")
    print(f"Binary Search: {binary_search(arr, target)}")
    print(f"Ternary Search: {ternary_search(arr, target)}")
    print(f"Jump Search: {jump_search(arr, target)}")
    print(f"Exponential Search: {exponential_search(arr, target)}")


if __name__ == "__main__":
    test_search_algorithms()
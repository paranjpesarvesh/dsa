#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Binary Search - O(log n)
 * Divide and conquer search algorithm
 */
int binarySearch(vector<int>& arr, int target, int left, int right) {
    if (left > right) return -1;
    
    int mid = left + (right - left) / 2;
    
    if (arr[mid] == target) {
        return mid;
    } else if (arr[mid] < target) {
        return binarySearch(arr, target, mid + 1, right);
    } else {
        return binarySearch(arr, target, left, mid - 1);
    }
}

/**
 * Merge Sort - O(n log n)
 * Divide and conquer sorting algorithm
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
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

/**
 * Quick Sort - O(n log n) average, O(n²) worst
 * Partition-based sorting algorithm
 */
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

/**
 * Closest Pair of Points - O(n log n)
 * Find closest pair of points using divide and conquer
 */
struct Point {
    double x, y;
};

double distance(Point p1, Point p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

double closestPairUtil(vector<Point>& points, int left, int right) {
    if (right - left <= 3) {
        double min_dist = DBL_MAX;
        for (int i = left; i <= right; i++) {
            for (int j = i + 1; j <= right; j++) {
                min_dist = min(min_dist, distance(points[i], points[j]));
            }
        }
        return min_dist;
    }
    
    int mid = left + (right - left) / 2;
    double dl = closestPairUtil(points, left, mid);
    double dr = closestPairUtil(points, mid + 1, right);
    
    // Find closest pair with one point in left and one in right
    double min_dist = DBL_MAX;
    for (int i = left; i <= mid; i++) {
        for (int j = mid + 1; j <= right; j++) {
            min_dist = min(min_dist, distance(points[i], points[j]));
        }
    }
    
    return min(dl, dr, min_dist);
}

// Test function
void testDivideAndConquer() {
    cout << "=== Binary Search ===" << endl;
    vector<int> arr = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25};
    int target = 13;
    cout << "Found at index: " << binarySearch(arr, target, 0, arr.size() - 1) << endl;
    
    cout << "\n=== Merge Sort ===" << endl;
    vector<int> arr2 = {64, 34, 25, 12, 22, 11, 90};
    mergeSort(arr2, 0, arr2.size() - 1);
    cout << "Sorted array: ";
    for (int num : arr2) {
        cout << num << " ";
    }
    cout << endl;
    
    cout << "\n=== Quick Sort ===" << endl;
    vector<int> arr3 = {64, 34, 25, 12, 22, 11, 90};
    quickSort(arr3, 0, arr3.size() - 1);
    cout << "Sorted array: ";
    for (int num : arr3) {
        cout << num << " ";
    }
    cout << endl;
    
    cout << "\n=== Closest Pair of Points ===" << endl;
    vector<Point> points = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};
    double min_dist = closestPairUtil(points, 0, points.size() - 1);
    cout << "Minimum distance: " << min_dist << endl;
}

int main() {
    testDivideAndConquer();
    return 0;
}
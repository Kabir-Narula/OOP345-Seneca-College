#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

void mixedBubbleSort(int* arr, size_t n) {
    for (auto i = 0u; i < n - 1; ++i) {
        // If 'i' is even, sort in descending order; if 'i' is odd, sort in ascending order
        bool descending = (i % 2 == 0);
        
        for (auto j = 0u; j < n - i - 1; ++j) {
            // Compare and swap based on the sorting condition
            if ((descending && arr[j] < arr[j + 1]) || (!descending && arr[j] > arr[j + 1])) {
                // Swap arr[j] and arr[j + 1]
                auto tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90, 50, 75};
    size_t n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original Array: ";
    for (size_t i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    mixedBubbleSort(arr, n);

    cout << "Sorted Array (Mixed Order): ";
    for (size_t i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

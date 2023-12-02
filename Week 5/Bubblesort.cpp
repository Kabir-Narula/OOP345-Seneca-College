#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

void bubbleSort(int* arr, size_t n) {
    for (auto i = 0u; i < n - 1; ++i) {
        for (auto j = 0u; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j + 1]
                auto tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    size_t n = sizeof(arr)/sizeof(arr[0]);

    cout << "Original Array: ";
    for (size_t i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    bubbleSort(arr, n);

    cout << "Sorted Array: ";
    for (size_t i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

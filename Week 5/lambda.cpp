#include <iostream>
#include <vector>
#include <algorithm>

auto ascendingComparator = [](int a, int b) -> bool {
    return a < b;
};

auto descendingComparator = [](int a, int b) -> bool {
    return a > b;
};

int main() {
    std::vector<int> numbers = {5, 2, 8, 1, 3};

    // Sorting in ascending order using lambda function and std::sort
    std::sort(numbers.begin(), numbers.end(), ascendingComparator);
    std::cout << "Sorted numbers in ascending order: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Sorting in descending order using lambda function and std::sort
    std::sort(numbers.begin(), numbers.end(), descendingComparator);
    std::cout << "Sorted numbers in descending order: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Count the number of elements greater than 4 using lambda function and std::count_if
    int count = std::count_if(numbers.begin(), numbers.end(), [](int num) {
        return num > 4;
    });
    std::cout << "Number of elements greater than 4: " << count << std::endl;

    return 0;
}

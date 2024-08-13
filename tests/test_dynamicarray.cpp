#include <iostream>
#include <cassert>
#include "../include/DynamicArray.h" // Include your DynamicArray implementation here

void test_push_back() {
    DynamicArray<int> arr;
    assert(arr.getSize() == 0);
    assert(arr.getCapacity() == 1);

    arr.push_back(10);
    assert(arr.getSize() == 1);
    assert(arr[0] == 10);

    arr.push_back(20);
    assert(arr.getSize() == 2);
    assert(arr[1] == 20);
    assert(arr.getCapacity() >= 2); // Capacity should have increased

    std::cout << "test_push_back passed!" << std::endl;
}

void test_pop_back() {
    DynamicArray<int> arr;
    arr.push_back(10);
    arr.push_back(20);

    arr.pop_back();
    assert(arr.getSize() == 1);
    assert(arr[0] == 10);

    arr.pop_back();
    assert(arr.getSize() == 0);

    // Test popping from an empty array
    try {
        arr.pop_back(); // Should not throw since you handle it quietly
        assert(arr.getSize() == 0);
    } catch (...) {
        assert(false && "Exception thrown on pop_back() with empty array");
    }

    std::cout << "test_pop_back passed!" << std::endl;
}

void test_clear() {
    DynamicArray<int> arr;
    arr.push_back(10);
    arr.push_back(20);
    arr.push_back(30);

    arr.clear();
    assert(arr.getSize() == 0);
    assert(arr.getCapacity() == 1); // Capacity should reset to 1 after clear

    arr.push_back(40);
    assert(arr.getSize() == 1);
    assert(arr[0] == 40);

    std::cout << "test_clear passed!" << std::endl;
}

void test_operator_access() {
    DynamicArray<int> arr;
    arr.push_back(10);
    arr.push_back(20);
    arr.push_back(30);

    assert(arr[0] == 10);
    assert(arr[1] == 20);
    assert(arr[2] == 30);

    arr[1] = 50;
    assert(arr[1] == 50);

    // Test out-of-range access
    try {
        int value = arr[3]; // This should throw an exception
        assert(false && "Exception not thrown on out-of-range access");
    } catch (const std::out_of_range&) {
        // Exception is expected, so this is fine
    }

    std::cout << "test_operator_access passed!" << std::endl;
}

int main() {
    test_push_back();
    test_pop_back();
    test_clear();
    test_operator_access();

    std::cout << "All tests passed!" << std::endl;
    return 0;
}

#include <iostream>
#include "../include/LinkedList.h"

using namespace std;

void testAddFront() {
    LinkedList<int> list;

    // Test 1: Add a single element to the front
    list.addFront(10);
    if (list.front() == 10 && list.getSize() == 1) {
        cout << "Test 1 Passed: addFront with one element" << endl;
    } else {
        cout << "Test 1 Failed: addFront with one element" << endl;
    }

    // Test 2: Add another element to the front
    list.addFront(20);
    if (list.front() == 20 && list.getSize() == 2) {
        cout << "Test 2 Passed: addFront with two elements" << endl;
    } else {
        cout << "Test 2 Failed: addFront with two elements" << endl;
    }
}

void testRemoveFront() {
    LinkedList<int> list;

    // Prepare the list
    list.addFront(10);
    list.addFront(20);

    // Test 1: Remove the front element
    list.removeFront();
    if (list.front() == 10 && list.getSize() == 1) {
        cout << "Test 1 Passed: removeFront with two elements" << endl;
    } else {
        cout << "Test 1 Failed: removeFront with two elements" << endl;
    }

    // Test 2: Remove the last element
    list.removeFront();
    if (list.isEmpty()) {
        cout << "Test 2 Passed: removeFront to empty the list" << endl;
    } else {
        cout << "Test 2 Failed: removeFront to empty the list" << endl;
    }
}

void testAddEnd() {
    LinkedList<int> list;

    // Test 1: Add a single element to the end
    list.addEnd(10);
    if (list.front() == 10 && list.getSize() == 1) {
        cout << "Test 1 Passed: addEnd with one element" << endl;
    } else {
        cout << "Test 1 Failed: addEnd with one element" << endl;
    }

    // Test 2: Add another element to the end
    list.addEnd(20);
    if (list.front() == 10 && list.getSize() == 2 && list.end() == 20) {
        cout << "Test 2 Passed: addEnd with two elements" << endl;
    } else {
        cout << "Test 2 Failed: addEnd with two elements" << endl;
    }
}

void testRemoveEnd() {
    LinkedList<int> list;

    // Prepare the list
    list.addEnd(10);
    list.addEnd(20);

    // Test 1: Remove the end element
    list.removeEnd();
    if (list.front() == 10 && list.getSize() == 1 && list.end() == 10) {
        cout << "Test 1 Passed: removeEnd with two elements" << endl;
    } else {
        cout << "Test 1 Failed: removeEnd with two elements" << endl;
    }

    // Test 2: Remove the last element
    list.removeEnd();
    if (list.isEmpty()) {
        cout << "Test 2 Passed: removeEnd to empty the list" << endl;
    } else {
        cout << "Test 2 Failed: removeEnd to empty the list" << endl;
    }
}

void testFind() {
    LinkedList<int> list;

    // Prepare the list
    list.addEnd(10);
    list.addEnd(20);
    list.addEnd(30);

    // Test 1: Find value that exists (10)
    if (list.find(10) == 0) {
        cout << "Test 1 Passed: find(10)" << endl;
    } else {
        cout << "Test 1 Failed: find(10)" << endl;
    }

    // Test 2: Find value that exists (20)
    if (list.find(20) == 1) {
        cout << "Test 2 Passed: find(20)" << endl;
    } else {
        cout << "Test 2 Failed: find(20)" << endl;
    }

    // Test 3: Find value that exists (30)
    if (list.find(30) == 2) {
        cout << "Test 3 Passed: find(30)" << endl;
    } else {
        cout << "Test 3 Failed: find(30)" << endl;
    }

    // Test 4: Find value that doesn't exist (40)
    if (list.find(40) == -1) {
        cout << "Test 4 Passed: find(40) - not in list" << endl;
    } else {
        cout << "Test 4 Failed: find(40) - not in list" << endl;
    }
}

void testGetAt() {
    LinkedList<int> list;

    // Prepare the list
    list.addEnd(10);
    list.addEnd(20);
    list.addEnd(30);

    // Test 1: Get value at index 0
    if (list.getAt(0) == 10) {
        cout << "Test 1 Passed: getAt(0)" << endl;
    } else {
        cout << "Test 1 Failed: getAt(0)" << endl;
    }

    // Test 2: Get value at index 1
    if (list.getAt(1) == 20) {
        cout << "Test 2 Passed: getAt(1)" << endl;
    } else {
        cout << "Test 2 Failed: getAt(1)" << endl;
    }

    // Test 3: Get value at index 2
    if (list.getAt(2) == 30) {
        cout << "Test 3 Passed: getAt(2)" << endl;
    } else {
        cout << "Test 3 Failed: getAt(2)" << endl;
    }

    // Test 4: Get value at invalid index (e.g., 3)
    try {
        list.getAt(3);
        cout << "Test 4 Failed: getAt(3) - should have thrown an exception" << endl;
    } catch (const std::out_of_range& e) {
        cout << "Test 4 Passed: getAt(3) - exception caught" << endl;
    }
}

void testInsertAt() {
    LinkedList<int> list;

    // Test 1: Insert at the beginning (index 0)
    list.insertAt(0, 10);
    if (list.getAt(0) == 10 && list.getSize() == 1) {
        cout << "Test 1 Passed: insertAt(0, 10)" << endl;
    } else {
        cout << "Test 1 Failed: insertAt(0, 10)" << endl;
    }

    // Test 2: Insert at the end (index 1)
    list.insertAt(1, 20);
    if (list.getAt(1) == 20 && list.getSize() == 2) {
        cout << "Test 2 Passed: insertAt(1, 20)" << endl;
    } else {
        cout << "Test 2 Failed: insertAt(1, 20)" << endl;
    }

    // Test 3: Insert in the middle (index 1)
    list.insertAt(1, 15);
    if (list.getAt(1) == 15 && list.getAt(2) == 20 && list.getSize() == 3) {
        cout << "Test 3 Passed: insertAt(1, 15)" << endl;
    } else {
        cout << "Test 3 Failed: insertAt(1, 15)" << endl;
    }

    // Test 4: Insert at invalid index (e.g., index 4)
    try {
        list.insertAt(4, 25);
        cout << "Test 4 Failed: insertAt(4, 25) - should have thrown an exception" << endl;
    } catch (const std::out_of_range& e) {
        cout << "Test 4 Passed: insertAt(4, 25) - exception caught" << endl;
    }
}

void testRemoveAt() {
    LinkedList<int> list;

    // Prepare the list
    list.addEnd(10);
    list.addEnd(20);
    list.addEnd(30);

    // Test 1: Remove from the beginning (index 0)
    list.removeAt(0);
    if (list.getAt(0) == 20 && list.getSize() == 2) {
        cout << "Test 1 Passed: removeAt(0)" << endl;
    } else {
        cout << "Test 1 Failed: removeAt(0)" << endl;
    }

    // Test 2: Remove from the middle (index 1)
    list.removeAt(1);
    if (list.getAt(0) == 20 && list.getSize() == 1) {
        cout << "Test 2 Passed: removeAt(1)" << endl;
    } else {
        cout << "Test 2 Failed: removeAt(1)" << endl;
    }

    // Test 3: Remove from the end (index 0)
    list.removeAt(0);
    if (list.isEmpty()) {
        cout << "Test 3 Passed: removeAt(0) - list is now empty" << endl;
    } else {
        cout << "Test 3 Failed: removeAt(0) - list is not empty" << endl;
    }

    // Test 4: Remove from invalid index (e.g., index 0 when list is empty)
    try {
        list.removeAt(0);
        cout << "Test 4 Failed: removeAt(0) - should have thrown an exception" << endl;
    } catch (const std::out_of_range& e) {
        cout << "Test 4 Passed: removeAt(0) - exception caught" << endl;
    }
}

void testClear() {
    LinkedList<int> list;

    // Prepare the list
    list.addEnd(10);
    list.addEnd(20);
    list.addEnd(30);

    // Test: Clear the list
    list.clear();
    if (list.isEmpty() && list.getSize() == 0) {
        cout << "Test Passed: clear - list is empty" << endl;
    } else {
        cout << "Test Failed: clear - list is not empty" << endl;
    }
}

void testReverse() {
    LinkedList<int> list;

    // Prepare the list
    list.addEnd(10);
    list.addEnd(20);
    list.addEnd(30);

    // Test: Reverse the list
    list.reverse();
    if (list.getAt(0) == 30 && list.getAt(1) == 20 && list.getAt(2) == 10) {
        cout << "Test Passed: reverse - list is reversed" << endl;
    } else {
        cout << "Test Failed: reverse - list is not reversed correctly" << endl;
    }
}

void testEmptyListOperations() {
    LinkedList<int> list;

    // Test: removeFront on an empty list
    try {
        list.removeFront();
        cout << "Test Failed: removeFront on empty list - should have thrown an exception" << endl;
    } catch (const std::out_of_range& e) {
        cout << "Test Passed: removeFront on empty list - exception caught" << endl;
    }

    // Test: removeEnd on an empty list
    try {
        list.removeEnd();
        cout << "Test Failed: removeEnd on empty list - should have thrown an exception" << endl;
    } catch (const std::out_of_range& e) {
        cout << "Test Passed: removeEnd on empty list - exception caught" << endl;
    }

    // Test: getAt on an empty list
    try {
        list.getAt(0);
        cout << "Test Failed: getAt on empty list - should have thrown an exception" << endl;
    } catch (const std::out_of_range& e) {
        cout << "Test Passed: getAt on empty list - exception caught" << endl;
    }

    // Test: removeAt on an empty list
    try {
        list.removeAt(0);
        cout << "Test Failed: removeAt on empty list - should have thrown an exception" << endl;
    } catch (const std::out_of_range& e) {
        cout << "Test Passed: removeAt on empty list - exception caught" << endl;
    }
}

void testLargeList() {
    LinkedList<int> list;

    // Test: Add a large number of elements
    for (int i = 0; i < 10000; i++) {
        list.addEnd(i);
    }

    // Verify size
    if (list.getSize() == 10000) {
        cout << "Test Passed: Large list creation" << endl;
    } else {
        cout << "Test Failed: Large list creation" << endl;
    }

    // Test: Reverse the large list
    list.reverse();
    if (list.getAt(0) == 9999 && list.getAt(9999) == 0) {
        cout << "Test Passed: Large list reverse" << endl;
    } else {
        cout << "Test Failed: Large list reverse" << endl;
    }

    // Test: Clear the large list
    list.clear();
    if (list.isEmpty() && list.getSize() == 0) {
        cout << "Test Passed: Large list clear" << endl;
    } else {
        cout << "Test Failed: Large list clear" << endl;
    }
}

int main() {
    testAddFront();
    testRemoveFront();
    testAddEnd();
    testRemoveEnd();
    testGetAt();
    testFind();
    testInsertAt();
    testRemoveAt();
    testClear();
    testReverse();
    testEmptyListOperations();
    testLargeList();

    return 0;
}

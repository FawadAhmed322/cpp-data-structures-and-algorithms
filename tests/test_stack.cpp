#include <iostream>
#include "../include/Stack.h"  // Assuming your stack implementation is in stack.h
#include <cassert>

bool test_isEmpty_on_new_stack() {
    Stack<int> stack;
    return stack.isEmpty();
}

bool test_push_and_size() {
    Stack<int> stack;
    stack.push(10);
    if (stack.size() != 1) return false;

    stack.push(20);
    stack.push(30);
    return stack.size() == 3;
}

bool test_peek() {
    Stack<int> stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);
    return stack.peek() == 30;
}

bool test_pop() {
    Stack<int> stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);
    
    if (stack.pop() != 30) return false;
    if (stack.size() != 2) return false;

    if (stack.pop() != 20) return false;
    if (stack.size() != 1) return false;

    if (stack.pop() != 10) return false;
    return stack.size() == 0 && stack.isEmpty();
}

bool test_clear() {
    Stack<int> stack;
    stack.push(40);
    stack.push(50);
    stack.clear();
    return stack.isEmpty() && stack.size() == 0;
}

void run_test(const std::string& test_name, bool (*test_func)()) {
    if (test_func()) {
        std::cout << test_name << ": Passed" << std::endl;
    } else {
        std::cout << test_name << ": Failed" << std::endl;
    }
}

int main() {
    run_test("Test isEmpty() on new stack", test_isEmpty_on_new_stack);
    run_test("Test push() and size()", test_push_and_size);
    run_test("Test peek()", test_peek);
    run_test("Test pop()", test_pop);
    run_test("Test clear()", test_clear);

    return 0;
}


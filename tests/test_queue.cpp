#include <iostream>
#include "../include/Queue.h"  // Assuming your queue implementation is in Queue.h
#include <cassert>

bool test_isEmpty_on_new_queue() {
    Queue<int> queue;
    return queue.isEmpty();
}

bool test_enqueue_and_size() {
    Queue<int> queue;
    queue.enqueue(10);
    if (queue.size() != 1) return false;

    queue.enqueue(20);
    queue.enqueue(30);
    return queue.size() == 3;
}

bool test_peek() {
    Queue<int> queue;
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    return queue.peek() == 10;
}

bool test_dequeue() {
    Queue<int> queue;
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    
    if (queue.dequeue() != 10) return false;
    if (queue.size() != 2) return false;

    if (queue.dequeue() != 20) return false;
    if (queue.size() != 1) return false;

    if (queue.dequeue() != 30) return false;
    return queue.size() == 0 && queue.isEmpty();
}

bool test_clear() {
    Queue<int> queue;
    queue.enqueue(40);
    queue.enqueue(50);
    queue.clear();
    return queue.isEmpty() && queue.size() == 0;
}

void run_test(const std::string& test_name, bool (*test_func)()) {
    if (test_func()) {
        std::cout << test_name << ": Passed" << std::endl;
    } else {
        std::cout << test_name << ": Failed" << std::endl;
    }
}

int main() {
    run_test("Test isEmpty() on new queue", test_isEmpty_on_new_queue);
    run_test("Test enqueue() and size()", test_enqueue_and_size);
    run_test("Test peek()", test_peek);
    run_test("Test dequeue()", test_dequeue);
    run_test("Test clear()", test_clear);

    return 0;
}

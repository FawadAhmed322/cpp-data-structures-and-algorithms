#include "./LinkedList.h"
template <typename T>
class Queue {
    private:
        LinkedList<int> list;

    public:
        void enqueue(T value) {
            list.addFront(value);
            return;
        }
        
        T dequeue() {
            T value = list.end();
            list.removeEnd();
            return value;
        }

        T peek() const {
            return list.end();
        }

        bool isEmpty() const {
            return list.isEmpty();
        }

        int size() const {
            return list.getSize();
        }

        void clear() {
            list.clear();
            return;
        }
};
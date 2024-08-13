#include "./LinkedList.h"
template <typename T>
class Stack {
    private:
        LinkedList<int> list;

    public:
        void push(T value) {
            list.addFront(value);
            return;
        }
        
        T pop() {
            T value = list.front();
            list.removeFront();
            return value;
        }

        T peek() const {
            return list.front();
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
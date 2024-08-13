template <typename T>
class LinkedList {
    private:
        struct Node {
        T data;
        Node* next;
        Node(T value) : data(value), next(nullptr) {}
    };
    Node* head;
    Node* tail;
    int size;

    void reverseUtil(Node* prevNode, Node* currNode) {
        if (currNode == nullptr) {
            head = prevNode;
            return;
        }
        reverseUtil(currNode, currNode -> next);
        currNode -> next = prevNode;
        return;
    }

    public:
        LinkedList() : head(nullptr), tail(nullptr), size(0) {}
        ~LinkedList() {
            clear();
        }


        int getSize() {
            return size;
        }

        bool isEmpty() {
            return size == 0;
        }

        T front() {
            if (isEmpty()) {
                throw std::out_of_range("List is empty");
            }
            return head -> data;
        }

        void addFront(T value) {
            if (isEmpty()) {
                head = new Node(value);
                tail = head;
            } else {
                Node* newNode = new Node(value);
                newNode -> next = head;
                head = newNode; 
            }
            size++;
            return;
        }

        void removeFront() {
            if (!isEmpty()) {
                if (head == tail) {
                    delete tail;
                    tail = nullptr;
                    head = nullptr;
                } else {
                    Node* temp = head -> next;
                    delete head;
                    head = temp;
                }
                size--;
                return;
            }
            throw std::out_of_range("Remove Operation Failed: List is empty");
        }

        T end() {
            return tail -> data;
        }

        void addEnd(T value) {
            if (isEmpty()) {
                head = new Node(value);
                tail = head;
            } else {
                tail -> next = new Node(value);
                tail = tail -> next;
            }
            size++;
            return;
        }

        void removeEnd() {
            if (!isEmpty()) {
                if (head == tail) {
                    delete tail;
                    tail = nullptr;
                    head = nullptr;
                } else {
                    Node* curr = head;
                    while (curr -> next != tail) {
                        curr = curr -> next;
                    }
                    delete tail;
                    tail = curr;
                }
                size--;
                return;
            }
            throw std::out_of_range("Remove Operation Failed: List is empty");
        }

        int find(T value) {
            Node* curr = head;
            int i = 0;
            while (curr) {
                if (curr -> data == value) {
                    return i;
                }
                curr = curr -> next;
                i++;
            }
            return -1;
        }

        T getAt(int index) {
            if (index < 0) {
                throw std::out_of_range("Index must be be >= 0");
            } else if (index >= size) {
                throw std::out_of_range("Index must be < N where N is the size of the linked list");
            } else {
                Node* curr = head;
                for (int i = 0; i < index; i++) {
                    curr = curr -> next;
                }
                return curr -> data;
            }
        }

        void insertAt(int index, T value) {
            if (index < 0) {
                throw std::out_of_range("Index must be be >= 0");
            } else if (index > size) {
                throw std::out_of_range("Index must be < N where N is the size of the linked list");
            } else {
                if (index == 0) {
                    addFront(value);
                } else if (index == size) {
                    addEnd(value);
                } else {
                    Node* curr = head;
                    for (int i = 0; i < index - 1; i++) {
                        curr = curr -> next;
                    }
                    Node* temp = curr -> next;
                    curr -> next = new Node(value);
                    curr -> next -> next = temp;
                    size++;
                }
                return;
            }
        }

        void removeAt(int index) {
            if (index < 0) {
                throw std::out_of_range("Index must be be >= 0");
            } else if (index > size) {
                throw std::out_of_range("Index must be < N where N is the size of the linked list");
            } else {
                if (isEmpty()) {
                    throw std::out_of_range("Remove Operation Failed: List is empty");
                }
                else if (index == 0) {
                    removeFront();
                } else if (index == size) {
                    removeEnd();
                } else {
                    Node* curr = head;
                    for (int i = 0; i < index - 1; i++) {
                        curr = curr -> next;
                    }
                    Node* temp = curr -> next -> next;
                    delete curr -> next;
                    curr -> next = temp;
                    size--;
                }
                return;
            }
        }

        void clear() {
            while (head) {
                removeFront();
            }
            return;
        }

        void reverse() {
            tail = head;
            reverseUtil(nullptr, head);
            return;
        }

};
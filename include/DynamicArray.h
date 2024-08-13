template <typename T>
class DynamicArray {
    private:
        T* arr;
        int size;
        int capacity;

    public:
        DynamicArray() {
            size = 0;
            capacity = 1;
            arr = new T[capacity];
        }
        ~DynamicArray() {
            delete[] arr;
            arr = nullptr;
        }

        // Non-const version of the [] operator
        T& operator[](int index) {
            if (index < 0 || index >= size) {
                throw std::out_of_range("Index out of range");
            }
            return arr[index];
        }

        // Const version of the [] operator
        const T& operator[](int index) const {
            if (index < 0 || index >= size) {
                throw std::out_of_range("Index out of range");
            }
            return arr[index];
        }

        int getSize() const {
            return size;
        }

        int getCapacity() const {
            return capacity;
        }

        void push_back(const T& value) {
            if (size == capacity) {
                T* temp = new T[capacity * 2];
                for (int i = 0; i < size; i++) {
                    temp[i] = arr[i];
                }
                delete[] arr;
                arr = temp;
                capacity = capacity * 2;
            }
            arr[size] = value;
            size++;
        }

        void pop_back() {
            if (size > 0) size--;
        }

        void clear() {
            delete[] arr;
            size = 0;
            capacity = 1;
            arr = new T[capacity];
        }
};
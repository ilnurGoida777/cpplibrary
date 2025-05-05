#include <iostream>

class Array {
private:
    double *arr;
    int size;
public:
    Array(double *a, int s) : size(s), arr(new double[s]) {
        for(int i = 0; i < size; i++) {
            arr[i] = a[i];
        }
    }

    Array(const Array& array) : size(array.size), arr(new double[array.size]) {
        for(int i = 0; i < size; i++) {
            arr[i] = array.arr[i];
        }
    }

    void unshift(double el) {
        size++;
        double *newarr = new double[size];

        newarr[0] = el;

        for (int i = 1; i < size; i++) {
            newarr[i] = arr[i - 1];
        }

        delete[] arr;
        arr = newarr;
        newarr = nullptr;
    }

    double shift() {
        size--;
        double *newarr = new double[size];
        double deletedElement = arr[0];

        for(int i = 1; i < size + 1; i++) {
            newarr[i - 1] = arr[i];
        }

        delete[] arr;
        arr = newarr;
        newarr = nullptr;

        return deletedElement;
    }

    void push(double el) {
        size++;
        double *newarr = new double[size];

        for(int i = 0; i < size - 1; i++) {
            newarr[i] = arr[i];
        }

        newarr[size - 1] = el;
        delete[] arr;
        arr = newarr;
        newarr = nullptr;
    }

    double pop() {
        size--;
        double *newarr = new double[size];
        double deletedElement = arr[size];

        for(int i = 0; i < size; i++) {
            newarr[i] = arr[i];
        }

        delete[] arr;
        arr = newarr;
        newarr = nullptr;

        return deletedElement;
    }

    //logic operators...

    double operator[](int index) const {
        if(index < 0 || index >= size)
            throw std::out_of_range("Inedx out of bound");
        return arr[index];
    }

    bool operator<(Array& array) {
        return size < array.size;
    }

    bool operator<=(Array& array) {
        return size <= array.size;
    }

    bool operator>(Array& array) {
        return size > array.size;
    }

    bool operator>=(Array& array) {
        return size >= array.size;
    }

    bool operator!=(Array& array) {
        return size != array.size;
    }

    bool operator!() {
        return !arr;
    }

    bool operator==(Array& array) {
        if(size != array.size)
            return false;
        
        for(int i = 0; i < size; i++) {
            if(arr[i] != array.arr[i])
                return false;
        }

        return true;
    }

    //arefmetic operators...

    Array& operator=(const Array& array) {
        if(&array == this)
            return *this;

        size = array.size;
        double *newarr = new double[size];

        for(int i = 0; i < size; i++) {
            newarr[i] = array.arr[i];
        }

        delete[] arr;
        arr = newarr;

        return *this;
    }

    Array operator+(const Array& array) const {
        double *newarr = new double[size + array.size];

        for(int i = 0; i < size; i++) {
            newarr[i] = arr[i];
        }
        for(int i = 0; i < array.size; i++) {
            newarr[i + size] = array.arr[i];
        }

        Array temp(newarr, size + array.size);
        delete[] newarr;
        return temp;
    }

    Array& operator+=(const Array& array) {
        if(array.size != 0) {
            double* newarr = new double[size + array.size];

            for(int i = 0; i < size; i++) {
                newarr[i] = arr[i];
            }
            for(int i = 0; i < array.size; i++) {
                newarr[i + size] = array.arr[i];
            }

            delete[] arr;
            arr = newarr;
            size += array.size; 
        }
        
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& os, const Array& array) {
        os << "[";

        for(int i = 0; i < array.size - 1; i++) {
            os << array.arr[i];
            os << ", ";
        }

        os << array.arr[array.size - 1];
        return os << "]";
    }

    ~Array() {
        delete[] arr;
    }
};
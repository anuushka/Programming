#include <iostream>
#include "Subset.h"

using namespace std;

bool Subset::exist(int num) const {
    if(num < minimum || num > capacity) {
        cout << "Value is not in the range of the set!" << endl;
        return false;
    }
    for(int i = 0; i < capacity; i++) {
        if(num == set[i])
            return true;
    }
    return false;
}

Subset::Subset() {
    size = 0;
}

bool Subset::isFull() const {
    return size == capacity;
}

bool Subset::isEmpty() const {
    return size == 0;
}

Subset& Subset::operator+= (int value) {
    if(value < minimum || value > capacity || exist(value)) {
        cout << "Value is out of range or already exists in the set!" << endl;
    }
    else if(!isFull())
        set[size++] = value;
    return *this;
}

Subset& Subset::operator-= (int value) {
    if(value < minimum || value > capacity || !exist(value)) {
        cout << "Value is out of range or doesn't exist in the set!" << endl;
    }
    else if(!isEmpty())
        for(int i = 0; i < size; i++) {
            if(set[i] == value) {
                swap(set[i], set[size - 1]);
                set[size - 1] = 0;
                size--;
                break;
            }
        }
    return *this;
}

Subset& Subset::operator+ (const Subset &other) {
    Subset* addition = new Subset();
    for(int i = 0; i < this->size; i++) {
        *addition += this->set[i];
    }
    for(int i = 0; i < other.size; i++) {
        if (!addition->exist(other.set[i])) {
            *addition += other.set[i];
        }
    }
    return *addition;
}

bool Subset::operator==(const Subset &other) {
    if (this->size != other.size)
        return false;
    for (int i = 0; i < other.size; i++) {
        if (!this->exist(other.set[i]))
            return false;
    }
    return true;
}

bool Subset::operator!=(const Subset &other) {
    return !(*this == other);
}

void Subset::printSet() const {
    for(int i = 0; i < size; i++) {
        cout << set[i] << " ";
    }
    cout << endl;
}


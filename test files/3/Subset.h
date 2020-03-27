#ifndef RABOTA3_SUBSET_H
#define RABOTA3_SUBSET_H


class Subset {
private:
    int set[10] = {0};
    int size;
    static const int capacity = 10;
    static const int minimum = 1;
    bool exist(int num) const;
    bool isFull() const;
    bool isEmpty() const;
public:
    Subset();
    void printSet() const;
    Subset& operator+= (int value);
    Subset& operator-= (int value);
    Subset& operator+ (const Subset &other);
    bool operator== (const Subset &other);
    bool operator!= (const Subset &other);
};


#endif //RABOTA3_SUBSET_H

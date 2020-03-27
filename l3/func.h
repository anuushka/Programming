#include<bits/stdc++.h>
#pragma once

using namespace std;

//Triangle
class Triangle
{
private: 
	double x1, x2, x3, y1, y2, y3;
public:
    Triangle();
    Triangle(double x1_, double y1_, double x2_, double y2_, double x3_, double y3_);
};

	double Area(Triangle t);
	bool operator== (Triangle &t1, Triangle &t2);
	Triangle operator+(Triangle &t1, Triangle &t2);
	std::ostream& operator<<(std::ostream& stream, const Triangle &a);

//Array
class Array
{
	private:
		int size;
		int* array;
	public:
        Array(int*, int);
        void print();
        int operator[](int index);
        int getSize();
        ~Array();
};

Array operator+(Array &a1, Array &a2);
bool operator== (Array &a1, Array &a2); //bool operaror== (Array const &a ) const
bool operator!= (Array &a1, Array &a2);
bool operator> (Array &a1, Array &a2);
bool operator< (Array &a1, Array &a2);


#include<bits/stdc++.h>
#include "func.h"
using namespace std;

//Triangle
Triangle::Triangle()
{
	 x1 = 0, x2 = 0, x3 = 0, y1 = 0, y2 = 0, y3 = 0;
}

Triangle::Triangle(double x1_, double y1_, double x2_, double y2_, double x3_, double y3_)
{
	x1=x1_, y1=y1_, x2=x2_, y2=y2_, x3=x3_, y3=y3_; 
}

double Area(Triangle t)
{
	return abs((t.x1*(t.y2-t.y3) + t.x2*(t.y3-t.y1) + t.x3*(t.y1-t.y2))/2);
}

bool operator== (Triangle &t1, Triangle &t2)
{
	return ( Area(t1) == Area(t2));
}
	
Triangle operator+(Triangle &t1, Triangle &t2)
{
    return Triangle(t1.x1 + t2.x1, t1.y1 + t2.y1, t1.x2 + t2.x2, t1.y2 + t2.y2, t1.x3 + t2.x3, t1.y3 + t2.y3);	
}

std::ostream& operator<<(std::ostream& stream, const Triangle &a)
{
	stream << "A'(" << a.x1 << ";" << a.y1 << "), B'(" << a.x2 << ";" << a.y2 << "), C'(" << a.x3 << ";" << a.y3 << ")";
	return stream;
}

//Array

Array::Array(int* p = NULL, int s = 0)
{            
	size = s;
    array = nullptr; //c++
    if((s!=0)&&(s <= 100))
    {
        array = new int[s]; //delete or free(arr) --> malloc
        for(int i = 0; i < s; i++)
        {
        	array[i] = p[i];
        }
    }
}
Array::~Array()
{
	delete[] array;
}

void Array::print()
{
    for(int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
        cout << '\n';
}

int Array::operator[](int index)
{
    if(index > size)
    {
		cout << "Array index out of bound";
        exit(0);
    }
    	return array[index];
}

int Array::getSize() 
{
    return size;
}

Array operator+(Array &a1, Array &a2)
{
    int size = a1.getSize();
    int size1 = a1.getSize();
    int n = size + size1;
    int arr[n];
    for (int i = 0; i < size; i++)
    {
        arr[i] = a1[i];
    }
    for (int i = 0; i < size1; i++)
    {
        arr[size + i] = a2[i];
    }

    Array arr1(arr, n);
    return arr1;
}

bool operator== (Array &a1, Array &a2) 
{
	return a1.getSize() == a2.getSize();
}

bool operator!= (Array &a1, Array &a2) 
{
	return a1.getSize() != a2.getSize();
}

bool operator> (Array &a1, Array &a2) 
{
	return a1.getSize() > a2.getSize();
}

bool operator< (Array &a1, Array &a2) 
{
	return a1.getSize() < a2.getSize();
}
	

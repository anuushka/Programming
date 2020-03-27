#include<bits/stdc++.h>
using namespace std;

class Array
{
	private:
		int size;
		int* array;

	public:
        Array(int* p = NULL, int s = 0)
        {
            size = s;
            array = NULL;
            if((s!=0)&&(s <= 100))
            {
                array = new int[s];
                for(int i = 0; i < s; i++)
                {
                    array[i] = p[i];
                }
            }
        }
    
        void print() 
        {
            for(int i = 0; i < size; i++)
            {
                cout << array[i] << " ";
            }
                cout << '\n';
        }

        int operator[](int index)
        {
            if(index > size)
            {
                cout << "Array index out of bound";
                exit(0);
            }
            return array[index];
        }

        int getSize()
        {
            return size;
        }
};		

Array operator+(Array &a1, Array &a2)
{
    int size = a1.getSize();
    int size1 = a1.getSize();
    int arr[size + size1];
    for (int i = 0; i < size; i++)
    {
        arr[i] = a1[i];
    }
    for (int i = 0; i < size1; i++)
    {
        arr[size + i] = a2[i];
    }

    Array arr1(arr, size + size1);

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
	
int main()
{
	int a[] = {1, 2, 3, 4, 9};
	int b[] = {2, 6, 7, 8, 9, 10};
	Array arr1(a, 5);
	Array arr2(b, 6);
	
	if(arr1 == arr2)
	{
		cout << "arr1 == arr2?" << '\n';
		cout << "True" << '\n';
	}
	else if (arr1 != arr2)
	{
		if (arr1 > arr2)
		{
			cout << "arr1 > arr2?" << '\n' ;
			cout << "True" << '\n';
		}
		else
		{
			cout << "arr1 < arr2?" << '\n' ;
			cout << "True" << '\n';
		}
	} 
	cout << "arr1 + arr2: ";
	Array result = arr1 + arr2;
	result.print();
	return 0;
}

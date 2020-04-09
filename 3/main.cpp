#include<bits/stdc++.h>
#include "func.h"

using namespace std;

void first_task()
{
	Triangle t1(1,2,3,4,5,6);
    Triangle t2(6,5,4,3,2,1);
	
	if(t1 == t2)
    {
    	cout << "Equal triangles? ";
        cout << "True" << '\n';
    }   
    else 
    {
        cout << "Inequal triangles? ";
        cout << "True" << '\n';
    }
    
    cout << '\n' << "Add vector";
	cout << " A(" << t1.x1 << ";" << t1.y1 << "), B(" << t1.x2 << ";" << t1.y2 << "), C(" << t1.x3 << ";" << t1.y3 << ")" << " to v1(" << t2.x1 << ";" << t2.y1 << "), v2(" << t2.x2 << ";" << t2.y2 << "), v3(" << t2.x3 << ";" << t2.y3 << ")" << '\n';
	cout << "Result: " << t1+t2 << endl;
}

void second_task()
{
	int a[] = {1, 2, 3, 4, 9};
	int b[] = {2, 6, 7, 8, 9, 10};
	Array arr1(a, 5);
	Array arr2(b, 6);
	
	if(arr1 == arr2)
	{
		cout << "arr1 == arr2?" << " ";
		cout << "True" << '\n';
	}
	else if (arr1 != arr2)
	{
		if (arr1 > arr2)
		{
			cout << "arr1 > arr2?" << " ";
			cout << "True" << '\n';
		}
		else
		{
			cout << "arr1 < arr2?" << " " ;
			cout << "True" << '\n';
		}
	} 
	cout << "1st array: " << '\n';
	arr1.print();
	cout << "2nd array: " << '\n';
	arr2.print();
	cout << "Merged array: ";
	Array result = arr1 + arr2;
	result.print();
}

int main()
{
	cout << '\n' << "-----FIRST TASK-----" << '\n';
	first_task();
	cout << '\n';
	cout << "-----SECOND TASK-----" << '\n';
	second_task();
}

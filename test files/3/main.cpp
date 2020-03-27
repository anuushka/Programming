#include <iostream>
#include "Subset.h"
#include "Matrix.h"

using namespace std;

int main() {
    /*//Matrix
    double array1[3][3] = {{1,2,3}, {4,5,6}, {7,8,9}};
    Matrix mat1(array1);
    double array2[3][3] = {{1,2,3}, {2,2,2}, {2,2,2}};
    Matrix mat2(array2);
    Matrix mat3 = mat1 * 2.65;
    cout << endl << "Result of multiplication:" << endl;
    mat3.printMatrix();

    Matrix mat4;
    cout << endl << "Enter the elements of the matrix:" << endl;
    mat4.readMatrix();
    Matrix mat5;
    cout << endl << "Enter the elements of the second matrix:" << endl;
    mat5.readMatrix();
    Matrix mat6;
    mat6 = mat4 * mat5;
    cout << endl << "The result of multiplication of two entered matrices:" << endl;
    mat6.printMatrix();

    mat6 = mat6 - mat4;
    cout << endl << "The result of subtraction:" << endl;
    mat6.printMatrix();

*/
    //Subset
    Subset set1;
    set1 += 5;
    set1 += 4;
    set1 += 3;
    cout << endl << "The set is: ";
    set1.printSet();

    Subset set2;
    set2 += 5;
    set2 += 4;
    set2 += 3;
    cout << endl << "The set is: ";
    set2.printSet();

    if(set1 == set2)
        cout << endl << "The sets are equal" << endl;

    Subset set3;
    set3 += 1;
    set3 += 2;
    set3 += 3;

    Subset set4;
    set4 += 3;
    set4 += 4;
    set4 += 5;

    Subset set5 = set3 + set4;
    cout << endl << "The set after union: ";
    set5.printSet();
}
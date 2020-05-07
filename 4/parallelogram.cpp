#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include "parallelogram.h"
#include "interface.h"

Parallelogram::Parallelogram()
{
	this->Parallelogram::initFromDialog();
}

Parallelogram::~Parallelogram() = default;

void Parallelogram::initFromDialog()
{
	cout << "A(x,y): " << '\n';
	cin >> A;
	cout << "B(x,y): " << '\n';
	cin >> B;
	cout << "C(x,y): " << '\n';
	cin >> C;
	cout << "D(x,y): " << '\n';
	cin >> D;
	cout << "Weight: " << '\n';
	cin >> weight;
}

double Parallelogram::perimeter() 
{
	double edge1 = sqrt(pow((B.x - A.x),2) + pow((B.y-A.y),2));
	double edge2 = sqrt(pow((C.x-B.x),2) + pow((C.y-A.y),2));
	double perimeter = (edge1 + edge2)*2;
	return perimeter; 
}

double Parallelogram::area() 
{
	double height = abs(A.y - B.y);
	double base = sqrt(pow((C.x - B.x),2) + pow((C.y-B.y),2));
	double area = height * base;
	return area; 
}

double Parallelogram::mass() const
{
	return weight;
}

CVector2D Parallelogram::position() const
{
	CVector2D center;
	center.x = (A.x + C.x)/2;
	center.y = (A.y + C.y)/2;
	return center;
}

bool Parallelogram::operator==(const IPhysObject& object) const
{
	return mass() == object.mass();
}

bool Parallelogram::operator<(const IPhysObject& object) const
{
	return mass() < object.mass();	
}

void Parallelogram::draw()
{
	cout << "Figure: " << name << '\n';
	cout << "Position: " << position() << '\n';
	cout << "Weight: " << weight << '\n';
	cout << "Size: " << size() << '\n';
	cout << '\n';
}

const char* Parallelogram::className()
{
	return name;
}

unsigned Parallelogram::size()
{
	return sizeof(*this);
}

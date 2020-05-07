#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include "rectangle.h"
using namespace std;

Rectangle::Rectangle()
{
	this->Rectangle::initFromDialog();
}

Rectangle::~Rectangle() = default;

void Rectangle::initFromDialog()
{
	cout << "A(x,y): ";
	cin >> A;
	cout << "B(x,y): ";
	cin >> B;
	cout << "C(x,y): ";
	cin >> C;
	cout << "Weight: ";
	cin >> weight;
}

double Rectangle::perimeter() 
{
	double edge1 = sqrt(pow((B.x - A.x),2) + pow((B.y-A.y),2));
	double edge2 = sqrt(pow((C.x-B.x),2) + pow((C.y-A.y),2));
	double perimeter = (edge1 + edge2)*2;
	return perimeter; 
}

double Rectangle::area() 
{
	double height = abs(B.y-A.y);
	double base = sqrt(pow((C.x-B.x),2) + pow((C.y-B.y),2));
	double area = height * base;
	return area; 
}

double Rectangle::mass() const
{
	return weight;
}

CVector2D Rectangle::position() const
{
	CVector2D center;
	center.x = (A.x + C.x)/2;
	center.y = (A.y + C.y)/2;
	return center;
}

bool Rectangle::operator==(const IPhysObject& object) const
{
	return mass() == object.mass();
}

bool Rectangle::operator<(const IPhysObject& object) const
{
	return mass() < object.mass();	
}

void Rectangle::draw()
{
	cout << "Figure: " << name << '\n';
	cout << "Position: " << position() << '\n';
	cout << "Weight: " << weight << '\n';
	cout << "Size: " << size() << '\n';
	cout << '\n';
}

const char* Rectangle::className()
{
	return name;
}

unsigned Rectangle::size()
{
	return sizeof(*this);
}

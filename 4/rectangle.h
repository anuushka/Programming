#pragma once
#include "interface.h"
using namespace std;

class Rectangle : public IFigure
{
	private:
		CVector2D A, B, C;
		double weight = 0;
		const char* name = "Rectangle";
	public:
		Rectangle();
		~Rectangle();
		double perimeter() override;
		double area() override;
		double mass() const override;
		CVector2D position() const override;
		bool operator== (const IPhysObject& obj) const override;
		bool operator< (const IPhysObject& obj) const override;
		void draw() override;
		void initFromDialog() override;
		const char* className() override;
		unsigned int size() override;
};

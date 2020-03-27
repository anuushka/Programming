#include<bits/stdc++.h>
#include "rectangle.h"
#include "parallelogram.h"
#include "menu.h"

using namespace std;
int main() {
	vector<IFigure*> system;
	double x, y, sumP, sumArea, Mass;
	CVector2D centerMass;
	int c = 0;
	while(1) {
		write_interface();
		cin >> c;
		switch (c) {
		case 1:
			system.push_back(new Rectangle());
			break;
		case 2:
			system.push_back(new Parallelogram());
			break;
		case 3:
			for (auto& figure : system)
				figure->draw();
			break;
		case 4:
			sumP = 0;
			for (auto& figure : system)
				sumP += figure->perimeter();
			cout << "Perimeter sum: " << sumP << '\n';
			cout << '\n';
			break;
		case 5:
			sumArea = 0;
			for (auto& figure : system)
				sumArea += figure->area();
			cout <<"Area sum: " << sumArea << '\n';
			cout << '\n';
			break;
		case 6:
			Mass = 0;
			x = 0;
			y = 0;
			for (auto& figure : system) {
				x += figure->position().x * figure->mass();
				y += figure->position().y * figure->mass();
				Mass += figure->mass();
			}
			centerMass.x = x / Mass;
			centerMass.y = y / Mass;
			cout << "Center weight: " << centerMass << '\n';
			cout << '\n';
			break; 
		case 7:
			cout << "Figures size: ";
			for (auto& figure : system)
				cout << figure->size() << " ";
			cout << '\n';
			cout << '\n';
			break;
		case 8:
			sort(system.begin(), system.end(), [](IFigure* fig1, IFigure* fig2) {return *fig1 < *fig2; });
			cout << "Sort by weight: ";
			for (auto& figure : system)
				cout << figure->mass() << " ";
			cout << '\n';
			cout << '\n';
			break;
		case 9:
			return 0;
		default:
			cout << "command not found" << '\n';
			cout << '\n';
			break;
		}
	}
}

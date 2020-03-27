#include<bits/stdc++.h>
using namespace std;

class BuckysClass
{
	public:
		string name;
		void coolSaying()
		{
			cout << "preaching to choir" << endl;
		}
	
	
};

int main()
{
	BuckysClass obj;
	obj.coolSaying();
	obj.name = "Bucky";
	cout << obj.name;
	return 0;
}

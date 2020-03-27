#include<bits/stdc++.h>
using namespace std;

class BuckysClass
{
	private:
		string name;
		
	public:
		void setName(string x)
		{
			name = x;
		}
		
		string getName()
		{
			return name;
		}
		
};

int main()
{
	BuckysClass bo; // object is created to access class; classes are differentiated by their object;
	bo.setName("Miss Anuush");
	cout << bo.getName();
	return 0;
}

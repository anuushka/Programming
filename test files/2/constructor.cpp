#include<iostream>
#include <string>
using namespace std;

class BuckysClass
{
	private:
		string name;
	
	public:
		BuckysClass(string z) //constructor name is the same as Class name; constructor is called as soon as object is created;
		{
			setName(z);
		}
		void setName(string x)
		{
			name = x;
		}
		
		string returnName()
		{
			return name;
		}
};

int main()
{
	BuckysClass bo("Lucky Bucky roberts");
	cout << bo.returnName() << '\n';
	
	BuckysClass bo2("Sally mcSalad"); //multiple objects could be created under same class.
	cout << bo2.returnName() << '\n';
	
	return 0;
}







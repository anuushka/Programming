#include<bits/stdc++.h>
using namespace std;

class Triangle
{
    public:
	double x1, x2, x3, y1, y2, y3;
    Triangle()
    {
       x1 = 0, x2 = 0, x3 = 0, y1 = 0, y2 = 0, y3 = 0;
    }

    Triangle(double x1_, double y1_, double x2_, double y2_, double x3_, double y3_)
    {
        x1=x1_, y1=y1_, x2=x2_, y2=y2_, x3=x3_, y3=y3_; 
    }   
            
};

   double Area(Triangle t)
	{
		return abs((t.x1*(t.y2-t.y3) + t.x2*(t.y3-t.y1) + t.x3*(t.y1-t.y2))/2);
	}
	
	bool operator== (Triangle &t1, Triangle &t2)
	{
	    return ( Area(t1) == Area(t2));
	}
	
	   Triangle operator+(Triangle &t1, Triangle &t2)
    {
    	return Triangle(t1.x1 + t2.x1, t1.y1 + t2.y1, t1.x2 + t2.x2, t1.y2 + t2.y2, t1.x3 + t2.x3, t1.y3 + t2.y3);	
	}
	
	
	std::ostream& operator<<(std::ostream& stream, const Triangle &a)
	{
		stream << "(" << a.x1 << ";" << a.y1 << ")\n(" << a.x2 << ";" << a.y2 << ")\n(" << a.x3 << ";" << a.y3 << ")";
		return stream;
	}
	

int main()
{
    Triangle t1(2,3,4,5,6,7);
    Triangle t2(2,3,4,5,6,8);
	
	if(t1 == t2)
    {
        cout << "Both triangles are equal" << '\n';
    }   
    else 
    {
        cout << "Both triangles are not equal" << '\n';
    }
    
    cout << "Add vector t2 to t1" << '\n';
    cout << t1+t2 << endl;
}

#include<iostream>

using namespace std;

class A 
{
	public:
	int x;
	int y;
	int *z;
	
	A()
	{
		z = new int;
		*z=5;
		x = 1;
		y = 2;
	}
	//Step 1 - comment this constructor and observe the output
	//Step 2 - uncomment this constructor and observe the output
	A(const A& a)
	{

		z = new int;
		*z = *a.z;
		x = a.x;
		y = a.y;
	}
	
	set (int a)
	{
		*z = a;
	}
	
	display()
	{
		cout<<*z<<endl;
	}
};

int main()
{
	A a1;
	A a2 = a1;

	cout<<a1.x<<endl;
	cout<<a2.x<<endl;
	
	cout<<a1.z<<endl;
	cout<<a2.z<<endl;
	
	a1.set(3);
	
	a1.display();
	a2.display();
	
	getchar();
	
}

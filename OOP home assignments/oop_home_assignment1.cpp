// Name: Mugdha Malpe

// Home Assignment NO. 1

/*
Write a menu driven program in C++ having a class with member functions for performing each of the arithmetic operations.
Accept input values from user and pass them as parameter to these functions and display the resultant output.
*/

#include <bits/stdc++.h>
using namespace std;

class Operators
{
public:
	inline float add(float a,float b){
		return (a+b);
		}
	inline float sub(float a,float b)
	{
		return (a-b);
	}
	inline float multiply(float a,float b)
	{
		return (a*b);
	}
	inline float divide(float a,float b)
	{
		return (a/b);
	}
};


int main()
{
	int ch;
	float x,y,c;
	Operators obj;
	do
	{
		cout<<"\nMENU DRIVEN CALCI \n";
		cout << "---------------------" <<endl;
		cout << "Enter 1 for Addition" << endl;
		cout << "Enter 2 for Subtraction" << endl;
		cout << "Enter 3 for Multiplication" << endl;
		cout << "Enter 4 for Division" << endl;
		cout << "Enter 5 to EXIT" << endl;
		cout<<"\n\tEnter your choice: ";
		cin>>ch;
		switch(ch)
		{
			//use of switch statement
			case 1:
			cout<<"\nEnter two numbers: ";
			cin>>x>>y;
			c = obj.add(x,y);
			cout<<"Addition "<< x <<" + "<< y <<" = "<< c <<endl;
			break;
			case 2:
			cout<<"\nEnter two number: ";
			cin>>x>>y;
			c = obj.sub(x,y);
			cout<<"Subtraction "<< x <<" - "<< y <<" = "<< c <<endl;
			break;
			case 3:
			cout<<"\nEnter two number: ";
			cin>>x>>y;
			c = obj.multiply(x,y);
			cout<<"\nMultiplication "<< x <<" * "<< y <<" = "<< c <<endl;
			break;
			case 4:
			cout<<"\nEnter two number: ";
			cin>>x>>y;
			c = obj.divide(x,y);
			cout<<"Division "<< x <<" / "<< y <<" = "<< c <<endl;
			break;
			case 5:
			cout<<"Exiting...thank you..."<<endl;
			break;
		}
	}
	while(ch!=5);
	// getchar();
	return 0;
}



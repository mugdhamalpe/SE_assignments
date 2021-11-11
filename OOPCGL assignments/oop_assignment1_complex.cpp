// Subject: OOPCGL   
// Assignment No. 1
// Name: Mugdha Malpe


/*
    Implement a class Complex which represents the Complex Number data type. Implement the following operations:
1.	Constructor (including a default constructor which creates the complex number 0+0i).
2.	Overloaded operator+ to add two complex numbers.
3.	Overloaded operator* to multiply two complex numbers.
4.	Overloaded << and >> to print and read complex Numbers.
*/


#include <bits/stdc++.h>

using namespace std;
class Complex
{
	float real, img;
public:
	//constructor
	Complex()
	{
		real = 0.0;
		img = 0.0;
	}
	Complex(float a,float b)
	{
    real=a;
    img=b;
	}
	//Addition of two complex numbers
	//Operator overloaded is +
	Complex operator + (Complex comp1)
	{
		Complex temp;
		temp.real = real + comp1.real;
		temp.img = img + comp1.img;
		return temp;
	}

	//Subtraction of two complex numbers
	//Operator overloaded is -
	Complex operator - (Complex comp1)
	{
		Complex temp;
		temp.real = real - comp1.real;
		temp.img = img - comp1.img;
		return temp;
	}

	//Multiplication of two complex numbers
	//Operator overloaded is *
	Complex operator * (Complex comp1)
	{
		Complex temp;
		temp.real = (real*comp1.real) - (img*comp1.img);
		temp.img = (img*comp1.real) + (real*comp1.img);
		return temp;
	}

	//Division of two complex numbers
	//Operator overloaded is /
	Complex operator / (Complex comp1)
	{
		Complex temp, comp2;
		comp2.img = -comp1.img;
		float denom;
		temp.real = (real*comp1.real) - (img*(comp2.img));
		temp.img = (real*comp1.real) + (real*(comp2.img));
		denom = (comp1.real) * (comp1.real) + (comp1.img) * (comp1.img);
		temp.real = temp.real/denom;
		temp.img = temp.img/denom;
		return temp;
	}

	// Overloading insertion operator (<<) for class Complex
	friend ostream &operator<<(ostream &output, Complex &comp); 
    //insertion and extraction are not member functions, so they cannot be declared inside the class. define inside class and declare outside the class.
    friend istream &operator>>(istream &input, Complex &comp);

};
//declaring both these functions outside the class
ostream &operator<<(ostream &output, Complex &comp)
    {
		if(comp.img<0){
			output << comp.real << "" << comp.img << "i" << endl;
		}
		else{
			output << comp.real << "+" << comp.img << "i" << endl;
		}
		return output;
	}

istream &operator>>(istream &input, Complex &comp)
    {
		cout << "Real part is: ";
		input >> comp.real;
		cout << "Imaginary part is: ";
		input >> comp.img;
		return input;
	}

int main(){
	int ch;
	bool exit = false;
	// cin >> c1;
	// cin >> c2;
	while(not exit){
		Complex c1,c2,c3;
		cin >> c1;
		cin >> c2;
		cout << "--------MENU--------" << endl;
		cout << "1. Addition" << endl;
		cout << "2. Subtraction" << endl;
		cout << "3. Multiplication" << endl;
		cout << "4. Division" << endl;
		cout << "5. EXIT" << endl;
		cout << "--------------------" << endl;
		cout << "Enter your choice: ";
		cin >> ch;
		switch(ch){
			case 1:
			c3=c1+c2;
			cout<<"Addition of entered complex numbers is: ";
			cout << c3 << endl;
			break;
			case 2:
			c3=c1-c2;
			cout<<"Subtraction of entered complex numbers is: ";
			cout << c3 << endl;
			break;
			case 3:
			c3=c1*c2;
			cout<<"Multiplication of entered complex numbers is: ";
			cout << c3 << endl;
			break;
			case 4:
			c3=c1/c2;
			cout<<"Division of entered complex numbers is: ";
			cout << c3 << endl;
			break;
			case 5:
			cout << "Exitting...Thank you..." << endl;
			exit = true;
		}
	}
	return 0;
}

//============================================================================
// Name        : OOPAssi1.cpp
// Author      : Mugdha Malpe
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

//Subject: OOPCGL   Date: 01/09/21
//Assignment No. 1
//Name: Mugdha Malpe
//Roll No. 21153    Batch: G1

//Program to demonstrate various operations on Complex class

#include <iostream>

using namespace std;
class Complex
{
	float real, img; //data members of complex class
public:
	//constructor-no Parameters
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

	//METHODS TO OVERLOAD
	//DECLARE INSIDE DEFINE OUTSIDE

	//Addition of two complex numbers
	//Operator overloaded is +
	Complex operator + (Complex);

	//Subtraction of two complex numbers
	//Operator overloaded is -
	Complex operator - (Complex);

	//Multiplication of two complex numbers
	//Operator overloaded is *
	Complex operator * (Complex);

	//Division of two complex numbers
	//Operator overloaded is /
	Complex operator / (Complex);

	// Overloading insertion operator (<<) for class Complex
	friend ostream &operator<<(ostream &output, Complex &comp);
    //insertion and extraction are not member functions, so they cannot be declared inside the class. declare inside class and define outside the class.
    friend istream &operator>>(istream &input, Complex &comp);
    //input is object of istream class and object comp of complex class
    //passing address as parameters

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

//first complex is the return type
//second complex is class name
Complex Complex::operator +(Complex comp1){
	Complex temp;
	temp.real = real + comp1.real;
	temp.img = img + comp1.img;
	return temp;
}

Complex Complex::operator -(Complex comp1){
	Complex temp;
	temp.real = real - comp1.real;
	temp.img = img - comp1.img;
	return temp;
}

Complex Complex::operator *(Complex comp1){
	Complex temp;
	temp.real = (real*comp1.real) - (img*comp1.img);
	temp.img = (img*comp1.real) + (real*comp1.img);
	return temp;
}

Complex Complex::operator /(Complex comp1){
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
			cout << "Exiting...Thank you..." << endl;
			exit = true;
		}
	}
	return 0;
}


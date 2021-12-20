//============================================================================
// Name        : OOPAssi2.cpp
// Author      : Mugdha Malpe
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string.h>

using namespace std;

class Student{

	//char * defines a pointer to a string constant with the value name\0(terminated by null char)
	char* name;
	char* roll_no;
	char* cls;
	char* div;
	char* dob;
	char* blood_grp;
	char* address;
	long long int tele_no; //coz tele_no is 10 digit no.
	int license_no;

	static int count;

	public:
	//Constructor Definitions (inside public)
	//Only declaration inside class, definition outside class
	Student();//Default Constructor
	Student(char* , char* ,char* ,char* ,char*,char*,char *,long long int ,int);//Parameterized Constructor
	Student (Student &);//Copy Constructor
	~Student(); //Destructor
	//A copy constructor is a member function which initializes an object using another object of the same class.


	//Overloaded insertion and extraction operators
	friend istream& operator >> (istream& input, Student &S);
	friend ostream& operator << (ostream& output,Student &S);

	// friend void calpercentage(Student &);
	//implementation of friend class
	friend class Result; //friend function

	void get_details();

	static void getcount(); //static member function -> declaration

};

class Result{
	int marks;

	public:
	void calpercentage(Student &O){
		cout<<"Enter marks of student: ";
		cin>>marks;
		int percent = (marks*100)/100;
		cout << "Roll No. " << O.roll_no << " has scored percentage: " << percent <<"%" <<endl;
	}
};

int Student::count = 0;

//definition of static member func
void Student::getcount(){
	cout << "No. of objects are: "<< count << endl;
}


//:: is scope resolution operator
//use of :: -> 1.To define a function outside a class. 2.To access a class’s static variables.

//Parameterized Constructor
Student::Student(  char* name,  char* roll_no, char* cls, char* div, char* dob, char* blood_grp, char*  address,long long int tele_no,int license_no){
	//assigning the exact amount of memory(by finding length of string) required to store the var
	int length;
		length = strlen(name);
		this->name = new char[length];
		this->name = name;

		length = strlen(roll_no);
		this->roll_no = new char[length];
		this->roll_no = roll_no;

		//use of this-> to avoid confusion between class attributes and parameters with the same name

		length = strlen(cls);
		this->cls = new char[length];
		this->cls = cls;

		length = strlen(div);
		this->div = new char[length];
		this->div = div;

		length = strlen(dob);
		this->dob = new char[length];
		this->dob = dob;

		length = strlen(blood_grp);
		this->blood_grp = new char[length];
		this->blood_grp = blood_grp;

		length = strlen(address);
		this->address = new char[length];
		this->address = address;

		this->tele_no = tele_no;

		this->license_no = license_no;
		count++;

}

//new - The new operator denotes a request for memory allocation on the Free Store.
//If sufficient memory is available, new operator initializes the memory and
//returns the address of the newly allocated and initialized memory to the pointer variable.

//Default Constructor
Student::Student(){
	name = new char;
	roll_no = new char;
	cls =new char;
	div = new char;
	dob = new char;
	blood_grp = new char;
	address = new char;
	tele_no = 0;
	license_no = 0;
	count++;
}
//Copy Constructor
Student::Student(Student &S){
	name = S.name;
	roll_no = S.roll_no;
	cls = S.cls;
	div = S.div;
	dob = S.dob;
	blood_grp = S.blood_grp;
	address = S.address;
	tele_no = S.tele_no;
	license_no = S.license_no;
	count++;
}

//Delete is an operator that is used to destroy array and non-array(pointer) objects which are created by new expression.

//Destructor
Student::~Student(){
	delete name;
	delete roll_no;
	delete cls;
	delete blood_grp;
	delete address;
	delete dob;
	delete div;
	count--;
}

ostream& operator << (ostream& output,Student &S){
		cout<<"---------Display of student details--------"<<endl;
		cout<<"Name : "<<S.name<<endl;
		cout<<"Address :"<<S.address<<endl;
		cout<<"Class : "<<S.cls<<endl;
		cout<<"Date of Birth : "<<S.dob<<endl;
		cout<<"Blood Group : "<<S.blood_grp<<endl;
		cout<<"License Number : "<<S.license_no<<endl;
		cout<<"Roll Number : "<<S.roll_no<<endl;
		cout<<"Division : "<<S.div<<endl;
		cout<<"Phone Number : "<<S.tele_no<<endl;
		return output;
}

istream& operator >> (istream& input, Student &S ){
		cout<<"Enter the name of the student : ";
		cin>>S.name;
		cout<<"Enter the address of the student : ";
		cin>>S.address;
		cout<< "Enter the blood group of the student : ";
		try
		{
			cin>>S.blood_grp;
			if(strcmp(S.blood_grp, "A+")==0 || strcmp(S.blood_grp, "A-")==0 || strcmp(S.blood_grp, "B+")==0 || strcmp(S.blood_grp, "B-")==0 || strcmp(S.blood_grp, "AB+")==0 || strcmp(S.blood_grp, "AB-")==0 || strcmp(S.blood_grp, "O+")==0 || strcmp(S.blood_grp, "O-")==0){
				cout<<"Blood group is found valid, please continue..."<<endl;
			}else{
				throw S.blood_grp;
			}
		}
		catch(char* new_blood_grp)
		{
			cout<<"Blood grp is invalid! Please enter blood group from (A+, A-, B+, B-, AB+, AB-, O+, O-) :"<<endl;
			cin>>new_blood_grp;
		}
		cout<<"Enter the Date of Birth(DOB) of the student : ";
		cin>>S.dob;
		cout<<"Enter the roll number of the student : ";
		cin>>S.roll_no;
		cout<<"Enter the class of the student : ";
		cin>>S.cls;
		cout<<"Enter the telephone number of the student : ";
		cin>>S.tele_no;
		cout<<"Enter the driving license number of the student : ";
		cin>>S.license_no;
		cout<<"Enter the division of the student : ";
		cin>>S.div;
		return input;

	}

//using inline keyword - the lines inside inline func will be copied inside the main function

inline void Student::get_details(){
		cout<<"Enter the name of the student : ";
		cin>>this->name;
		cout<<"Enter the address of the student : ";
		cin>>this->address;
		cout<< "Enter the blood group of the student : ";
		try
		{
			cin>>this->blood_grp;
			if(strcmp(this->blood_grp, "A+")==0 || strcmp(this->blood_grp, "A-")==0 || strcmp(this->blood_grp, "B+")==0 || strcmp(this->blood_grp, "B-")==0 || strcmp(this->blood_grp, "AB+")==0 || strcmp(this->blood_grp, "AB-")==0 || strcmp(this->blood_grp, "O+")==0 || strcmp(this->blood_grp, "O-")==0){
				cout<<"Blood group is found valid, please continue..."<<endl;
			}else{
				throw this->blood_grp;
			}
		}
		catch(char* new_blood_grp)
		{
			cout<<"Blood grp is invalid! Please enter blood group from (A+, A-, B+, B-, AB+, AB-, O+, O-) :"<<endl;
			cin>>new_blood_grp;
		}
		cout<<"Enter the Date of Birth(DOB) of the student : ";
		cin>>this->dob;
		cout<<"Enter the roll number of the student : ";
		cin>>this->roll_no;
		cout<<"Enter the class of the student : ";
		cin>>this->cls;
		cout<<"Enter the telephone number of the student : ";
		cin>>this->tele_no;
		cout<<"Enter the driving license number of the student : ";
		cin>>this->license_no;
		cout<<"Enter the division of the student : ";
		cin>>this->div;

}


int main() {
	char* name =new char;
	char* address=new char;
	char* roll_no =new char;
	char* cls =new char;
	char* div = new char;
	char* dob = new char;
	char* blood_grp =new char;
	long long int tele_no;
	int license_no;
		cout<<"Enter the name of the student : ";
		cin>> name;
		cout<<"Enter the address of the student : ";
		cin>>address;
		cout<< "Enter the blood group of the student : ";
		try
		{
			cin>>blood_grp;
			if(strcmp(blood_grp, "A+")==0 || strcmp(blood_grp, "A-")==0 || strcmp(blood_grp, "B+")==0 || strcmp(blood_grp, "B-")==0 || strcmp(blood_grp, "AB+")==0 || strcmp(blood_grp, "AB-")==0 || strcmp(blood_grp, "O+")==0 || strcmp(blood_grp, "O-")==0){
				cout<<"Blood group is found valid, please continue..."<<endl;
			}
			else{
				throw blood_grp;
			}
		}
		catch(char* new_blood_grp)
		{
			cout<<"Blood grp is invalid! Please enter blood group from (A+, A-, B+, B-, AB+, AB-, O+, O-) :"<<endl;
			cin>>new_blood_grp;
		}
		cout<<"Enter the Date of Birth(DOB) of the student : ";
		cin>>dob;
		cout<<"Enter the roll number of the student : ";
		cin>>roll_no;
		cout<<"Enter the class of the student : ";
		cin>>cls;
		cout<<"Enter the telephone number of the student : ";
		cin>>tele_no;
		cout<<"Enter the driving license number of the student : ";
		cin>>license_no;
		cout<<"Enter the division of the student : ";
		cin>>div;
	Student s0(name,roll_no,cls,div,dob,blood_grp,address,tele_no,license_no);
	Result r1;
	Student s1;
	cin>>s1;
	Student s2=s1;
	Student s3;
	s3.get_details();
	cout<<s0;
	cout<<s1;
	cout<<s3;
	r1.calpercentage(s0);
	r1.calpercentage(s1);
	r1.calpercentage(s3);
	Student::getcount();
	return 0;
}


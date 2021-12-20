//============================================================================
// Name        : OOPAssi11.cpp
// Author      : Mugdha Malpe
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

//Name: Mugdha Malpe
//Roll No. 21153
//Batch: G1     Div: SE01

/*
 Write C++ program using STL for Sorting and searching with user-defined records such as
 Person Record (Name, birth date, telephone no), item record (item code, item name, quantity
 and cost)
 */
/*
 #include<iostream>
 #include<vector>
 #include<algorithm>
 using namespace std;

 class Employee {
 string name;
 int id;
 int salary;
 public:
 Employee();
 Employee(string name);
 Employee(string, int, int);
 int operator ==(Employee);
 bool sort_function(Employee&, Employee&);
 bool operator<(const Employee&);
 void edit_employee();
 friend bool remove_emp(Employee&, string);
 void show_details();
 friend void get_details(Employee&);
 string get_name() {
 return this->name;
 }
 ;

 };
 Employee::Employee() {
 name = "";
 id = 0;
 salary = 0;
 }
 Employee::Employee(string name) {
 this->name = name;
 id = 0;
 salary = 0;
 }
 Employee::Employee(string name, int id, int salary) {
 this->name = name;
 this->id = id;
 this->salary = salary;
 }
 void get_details(Employee &E) {
 cout << "Enter the name of the employee : ";
 cin >> E.name;
 cout << "Enter the id of the employee : ";
 cin >> E.id;
 cout << "Enter the salary of the employee : ";
 cin >> E.salary;
 }
 bool Employee::operator<(const Employee &E) {
 return salary > E.salary;
 }

 int Employee::operator ==(Employee E) {
 if (this->name == E.name) {
 return 1;
 }
 return 0;
 }
 bool Employee::sort_function(Employee &E1, Employee &E2) {
 return E1.salary > E2.salary;
 }

 bool remove_emp(Employee &E, string name) {
 if (E.name == name) {
 return 1;
 }
 return 0;
 }

 void Employee::show_details() {
 cout << "Name: " << name;
 cout << "\tID: " << id;
 cout << "\tSalary: " << salary << endl;
 }
 void display(Employee &e) {
 e.show_details();
 }
 int main() {
 string Name;
 vector<Employee> Employees;
 vector<Employee>::iterator it;
 while (1) {
 cout
 << "******Menu*******\n1. Add Employee\n2. Remove Employee\n3. Edit Employee\n4. Display All Employees \n5. Search Employee\n6. Sort Employees\n7.Exit"
 << endl;
 int choice;
 cin >> choice;
 switch (choice) {
 case 1: {
 Employee e;
 get_details(e);
 Employees.push_back(e);
 break;
 }

 case 2:
 cout << "Enter the name of the Employee who is to be removed : ";
 cin >> Name;
 Employees.erase(
 remove_if(Employees.begin(), Employees.end(),
 [Name](Employee E) {
 return (E.get_name() == Name);
 }),Employees.end());
 cout << "Employees with name " << Name << " removed" << endl;
 break;

 case 3: {
 cout << "Enter the Name of the employee to be edited : ";
 cin >> Name;
 Employee to_search_2(Name);
 it = find(Employees.begin(), Employees.end(), to_search_2);
 if (it != Employees.end()) {
 cout << "Employee found" << endl;
 cout << "Re enter the employee details please : " << endl;
 get_details(*it);
 cout << "Employee details edited , New Details are :  " << endl;
 it->show_details();
 cout << "***********************" << endl;
 } else {
 cout << "Employee not found" << endl;
 }
 break;
 }

 case 4:
 for_each(Employees.begin(), Employees.end(), display);
 break;

 case 5: {
 cout << "Enter the name of the employee to be searched : ";
 cin >> Name;
 Employee to_search(Name);
 vector<Employee>::iterator it;
 it = find(Employees.begin(), Employees.end(), to_search);
 if (it != Employees.end()) {
 cout << "Employee found" << endl;
 it->show_details();
 cout << "***********************" << endl;

 } else {
 cout << "Employee not found" << endl;
 }
 break;
 }

 case 6:
 std::sort(Employees.begin(), Employees.end());
 for_each(Employees.begin(), Employees.end(), display);
 break;
 case 7:
 exit(0);
 }

 }

 return 0;
 }*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Item {
public:
	char name[10];
	int quantity;
	int cost;
	int code;

	bool operator==(const Item &i1) //==, < to create more complex conditional statements
			{
		if (code == i1.code) //operator will return 1 if comparison=true, or 0 if the comparison=false
				{
			return 1;
		}
		return 0;
	}

	bool operator<(const Item &i1) {
		if (code < i1.code) //operator will return 1 if the comparison is true, or 0 if the comparison is false
				{
			return 1;
		}
		return 0;
	}

};

vector<Item> o1;
void print(Item &i1);
void display();
void insert_item();
void search_item();
void dlt();

bool compare(const Item &i1, const Item &i2) {
	return i1.cost < i2.cost;
}

void insert_item() {
	Item i1;
	cout << "\nEnter Item Name:";
	cin >> i1.name;
	cout << "\nEnter Item Quantity:";
	cin >> i1.quantity;
	cout << "\nEnter Item Cost:";
	cin >> i1.cost;
	cout << "\nEnter Item Code:";
	cin >> i1.code;
	o1.push_back(i1);
}

void display() {
	for_each(o1.begin(), o1.end(), print);
}

void print(Item &i1) {
	cout << "\n";
	cout << "\nItem Name:" << i1.name;
	cout << "\nItem Quantity:" << i1.quantity;
	cout << "\nItem Cost:" << i1.cost;
	cout << "\nItem Code:" << i1.code;
}

void search_item() {
	vector<Item>::iterator p;
	Item i1;
	cout << "\nEnter Item Code to search:";
	cin >> i1.code;
	p = find(o1.begin(), o1.end(), i1);
	if (p == o1.end()) {
		cout << "\nNot found.\n";
	} else {
		cout << "\nFound.\n";
	}
}

void dlt() {
	vector<Item>::iterator p;
	Item i1;
	cout << "\nEnter Item Code to delete:";
	cin >> i1.code;
	p = find(o1.begin(), o1.end(), i1);
	if (p == o1.end()) {
		cout << "\nNot found.";
	} else {
		o1.erase(p);
		cout << "\nDeleted.\n";
	}
}

int main() {
	int ch;
	do {
		cout << "\n***** MENU *****";
		cout << "\n1.Insert";
		cout << "\n2.Display";
		cout << "\n3.Search";
		cout << "\n4.Sort";
		cout << "\n5.Delete";
		cout << "\n6.Exit";
		cout << "\nEnter your choice:";
		cin >> ch;

		switch (ch) {
		case 1:
			insert_item();
			break;

		case 2:
			display();
			break;

		case 3:
			search_item();
			break;

		case 4:
			sort(o1.begin(), o1.end(), compare);
			cout << "\n After sorting on cost: \n";
			display();
			break;

		case 5:
			dlt();
			break;

		case 6:
			cout << "\n Exiting...Thank you..." << endl;
			exit(0);
		}

	} while (ch != 7);

	return 0;
}


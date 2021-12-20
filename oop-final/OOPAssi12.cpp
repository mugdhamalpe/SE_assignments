//============================================================================
// Name        : OOPAssi12.cpp
// Author      : Mugdha Malpe
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<iostream>
#include<map>
#include<utility>
using namespace std;

int main() {
	int choice;
	string name_of_state;
	long population;
	map<string, int> states; //empty map container
	map<string, int>::iterator itr;

	while (true) {
		cout
				<< "*******Menu**********\n1.Add State\n2.Search State\n3.Update State\n4.Remove State\n5.Display all States\n6.Exit"
				<< endl;
		cout << "Enter desired choice: ";
		cin >> choice;
		switch (choice) {
		case 1:
			cout << "Enter the name of the state : ";
			cin >> name_of_state;
			cout << "Enter the population of the state : ";
			cin >> population;
			states.insert(pair<string, long>(name_of_state, population));
			break;

		case 2:
			cout << "Enter the name of the state to be searched : ";
			cin >> name_of_state;
			itr = states.find(name_of_state);
			cout << "The population of the state " << itr->first << " is "
					<< itr->second << endl;
			break;

		case 3:
			cout << "enter the name of the state to be searched : ";
			cin >> name_of_state;
			itr = states.find(name_of_state);
			cout << "Enter the new population of the state : ";
			cin >> population;
			itr->second = population;
			break;

		case 4:
			cout << "enter the name of the state to be removed : ";
			cin >> name_of_state;
			itr = states.find(name_of_state);
			states.erase(itr);
			break;
		case 5:
			cout << "The states are : " << endl;
			for (itr = states.begin(); itr != states.end(); itr++) {
				cout << itr->first << " " << itr->second << endl;
			}
			break;

		case 6:
			cout << "Exiting...thank you..." << endl;
			exit(0);

		}
	}

	return 0;
}

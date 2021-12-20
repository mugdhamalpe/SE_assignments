//============================================================================
// Name        : OOPAssi3.cpp
// Author      : Mugdha Malpe
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

// Subject: OOPCGL
// Assignment No. 3
// Name: Mugdha Malpe 		Roll No.: 21153
// Div: SE01				Batch: G1

#include <iostream>
#include <string.h>

using namespace std;

class Publication {
protected:
	string title;
	float price;

};

class Book: private Publication { //private is the visibility mode
	int page_count;
public:
	void set_details();
	void get_details();

};
class Tape: private Publication {
	// int playing_time;
	float playing_time;
public:
	void set_details();
	void get_details();

};
void Book::set_details() {
	cout << "Enter the Title of the book: ";
	getline(cin, title);
	try {

		if (title.length() < 3) {
			throw title;

		} else {
			cout << "Title found valid, you may continue..." << endl;
		}

		cout << "Enter the price of the book (in Rs.): ";
		cin >> price;
		if (price <= 0.0) {
			throw price;
		} else {
			cout << "Entered price found valid, you may continue..." << endl;
		}

		cout << "Enter the number of pages of the book: ";
		cin >> page_count;
		if (page_count <= 0) {
			throw page_count;
		} else {
			cout << "Entered page count found valid, you may continue..."
					<< endl;
		}
	}

	catch (int page_count) {
		cout << "Invalid page count" << endl;
		this->title = " ";
		this->price = 0.0;
		this->page_count = 0;
	}

	catch (float price) {
		cout << "Invalid price entered" << endl;
		this->title = " ";
		this->price = 0.0;
		this->page_count = 0;
	}

	catch (string title) {
		cout << "Invalid title entered. Title length should be greater than 3"
				<< endl;
		this->title = " ";
		this->price = 0.0;
		this->page_count = 0;
	}
}

void Book::get_details() {
	cout << "---------Display book details--------" << endl;
	cout << "The title of the book is " << title << endl;
	cout << "The price of the book is " << price << " Rs" << endl;
	cout << "The page count of the book is " << page_count << endl;
}

void Tape::set_details() {
	cout << "Enter the title of tape: ";
	cin.ignore();
	getline(cin, title);
	try {
		if (title.length() > 3) {
			throw title;
		} else {
			cout << "Title found valid, you may continue..." << endl;
		}

		cout << "Enter the price of the tape (in Rs.): ";
		cin >> price;

		if (price <= 0.0) {
			throw price;
		} else {
			cout << "Entered price found valid, you may continue..." << endl;
		}
	}

	catch (float price) {
		cout << "Invalid price entered" << endl;
		this->title = " ";
		this->price = 0.0;
		this->playing_time = 0.0;
	}

	catch (string title) {
		cout << "Invalid title entered. Title length should be less than 3."
				<< endl;
		this->title = " ";
		this->price = 0.0;
		this->playing_time = 0.0;
	}

	cout << "Enter the playing time of the tape (in minutes): " << endl;
	cin >> playing_time;
	try {

		if (playing_time <= 0.0) {
			throw playing_time;
		} else {
			cout << "Entered playing time is found valid, you may continue..."
					<< endl;
		}
	}

	catch (float playing_time) {
		cout << "Invalid playing time" << endl;
		this->title = " ";
		this->price = 0.0;
		this->playing_time = 0.0;
	}
}

void Tape::get_details() {
	cout << "---------Display tape details--------" << endl;
	cout << "The title of the tape is " << title << endl;
	cout << "The price of the tape is " << price << " Rs" << endl;
	cout << "The playing time of the tape is " << playing_time << " minutes"
			<< endl;
}

int main() {
	Book b;
	b.set_details();
	b.get_details();
	Tape t;
	t.set_details();
	t.get_details();
	return 0;
}


//Name: Mugdha Malpe
//  Home  Assignment  6B
//home assignment 2 of file handling

/*
Write a C++ program to create a file “mydata.txt”, accept name and age of 10 persons from the console and add them to the file (each record must be on new line). 
Read the contents of file back in two variables (name and age) and display them on the console.
*/

#include<iostream>
#include<fstream>
#include<conio.h>
#include <cstdlib>
using namespace std;

class Student
{
    private:
        string Name;
        int age;
    public:
        void accept_info()
        {
            fstream fs;
            fs.open("mydata.txt", ios::app);
            if(!fs){
                cout<<"File creation failed..."<<endl;
            }
            else{
                    for(int i; i<11; i++){
                            cout<<"Enter name: "<<endl;
                            cin>>Name;
                            cout<<"Enter age: "<<endl;
                            cin>>age;
                            fs<<Name<<"\n";//write Name to file
                            fs<<age<< "\n";//write roll no to file
                    }

                fs.close();//close file
            }
        }

        void display_info(){
            fstream fs;
            fs.open("mydata.txt", ios::in);
            if(!fs){
                cout<<"No such file exists..."<<endl;
            }else{
                while(!fs.eof()){ //read till end of line
                        for(int i; i<11; i++){
                                fs>>Name;
                                fs>>age;
                                if(!fs.eof()){
                                    cout<<Name<<"\t";
                                    cout<<age<<endl;
                                }
                        }
                }
                fs.close();
            }
        }
};

int main()
{
    int ch;
    Student s;
    fstream fs;

    do{
        cout<<"*****Student Info System*****"<<endl;
        cout<<"***MENU***"<<endl;
        cout<<"1. Enter data"<<endl;
        cout<<"2. Display of entered data"<<endl;
        cout<<"3. EXIT"<<endl;
        cout<<"Enter your choice: "<<endl;
        cin>>ch;

        switch(ch){
        case 1:
            s.accept_info();
            break;
        case 2:
            s.display_info();
            break;
        case 3:
            exit(0);
        }
    }
    while(ch!=3);

    return 0;
}

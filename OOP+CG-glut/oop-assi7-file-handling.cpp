/*Name: Mugdha Malpe
Div: SE01   Roll. No 21153
Batch: G1*/
/*Write a C++ program that creates an output file, writes information to it, closes the file, open
it again as an input file and read the information from the file.*/

#include <iostream>
#include <fstream>
#include <conio.h>
#include <cstdlib>

using namespace std;

class Student
{
    private:
        string Name;
        int roll_no;
    public:
        void accept_info()
        {
            fstream fs; //creating object of fstream
            fs.open("C:\\Users\\mdmal\\Desktop\\Codeblocks opengl\\oopcglassi7\\demo.txt", ios::out);
            if(!fs){
                cout<<"File creation failed..."<<endl;
            }else{
                cout<<"File created successfully..."<<endl;
            }
            fs.close();
            fs.open("C:\\Users\\mdmal\\Desktop\\Codeblocks opengl\\oopcglassi7\\demo.txt", ios::app); //opening file in append mode
                cout<<"Enter name: "<<endl;
                cin>>Name;
                cout<<"Enter roll.no.: "<<endl;
                cin>>roll_no;
                fs<<Name<<"\n";//write Name to file
                fs<<roll_no<< "\n";//write roll no to file
                fs.close();//close file
        }

        void display_info(){
            fstream fs;
            fs.open("C:\\Users\\mdmal\\Desktop\\Codeblocks opengl\\oopcglassi7\\demo.txt", ios::in); //opening file in input mode
            if(!fs){
                cout<<"No such file exists..."<<endl;
            }else{
                while(!fs.eof()){ //read till end of line(eof)
                    fs>>Name; //reading name from file
                    fs>>roll_no; //reading roll no from file
                    if(!fs.eof()){
                        cout<<Name<<"\t";
                        cout<<roll_no<<endl;
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
        cout<<"1. Enter student info"<<endl;
        cout<<"2. Display student info"<<endl;
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
            cout<<"Exiting... thank you..."<<endl;
            exit(0);
        }
    }
    while(ch!=3);

    return 0;
}

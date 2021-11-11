//Name: Mugdha Malpe
//  Home  Assignment  6C
//home assignment 3 of file handling

/*
Write a C++ program to find out and display the size of a given file using the file pointer functions
*/

#include<iostream>
#include<fstream>

using namespace std;
int main(){
    FILE *fp;
    char ch;
    int size=0;

    fp = fopen("filehandling6C.txt", "r");
    if(fp == NULL){
        cout<<"Unable to open the file"<<endl;
    }else{
        cout<<"File opened successfully :)"<<endl;
        fseek(fp, 0, 2);
        size = ftell(fp);
        cout<<"The size of given file is: "<<size<<" bytes."<<endl;
        fclose(fp);

    }
}
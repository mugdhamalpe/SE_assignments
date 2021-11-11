//Name: Mugdha Malpe
//  Home  Assignment  6A
//home assignment 1 of file handling

/*
Write a C++ program to count the number of sentences in a given file.
*/

#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int main()
{
  ifstream file("filehandling6A.txt",ios::in);
  string curr;
  int count=0;
  while(getline(file, curr))
  {
    for(int i=0;i<curr.size();i++)
      if(curr[i]=='.' || curr[i]=='?' || curr[i]=='!')
        count++;
  }
  cout<<"The total number of sentences are: "<<count<<"\n";
  return 0;
}

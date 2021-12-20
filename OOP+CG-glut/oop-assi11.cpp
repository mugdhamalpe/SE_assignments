//Name: Mugdha Malpe
//Roll No. 21153
//Batch: G1     Div: SE01

/*
Write C++ program using STL for Sorting and searching with user-defined records such as
Person Record (Name, birth date, telephone no), item record (item code, item name, quantity
and cost)
*/

#include <bits/stdc++.h>

using namespace std;
class Item
{
      public:
        char name[10];
        int quantity;
        int cost;
        int code;

        bool operator==(const Item& i1)    //==, < to create more complex conditional statements
    {
        if(code==i1.code)    //operator will return 1 if comparison=true, or 0 if the comparison=false
        {
            return 1;
        }
        return 0;
    }

    bool operator<(const Item& i1)
    {
        if(code<i1.code)    //operator will return 1 if the comparison is true, or 0 if the comparison is false
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

bool compare(const Item &i1, const Item &i2)
{
   return i1.cost < i2.cost;
}

void insert_item()
{
    Item i1;
    cout<<"\nEnter Item Name:";
    cin>>i1.name;
    cout<<"\nEnter Item Quantity:";
    cin>>i1.quantity;
    cout<<"\nEnter Item Cost:";
    cin>>i1.cost;
    cout<<"\nEnter Item Code:";
    cin>>i1.code;
    o1.push_back(i1);
}

void display()
{
    for_each(o1.begin(),o1.end(),print);
}

void print(Item &i1)
{
     cout<<"\n";
     cout<<"\nItem Name:"<<i1.name;
     cout<<"\nItem Quantity:"<<i1.quantity;
     cout<<"\nItem Cost:"<<i1.cost;
     cout<<"\nItem Code:"<<i1.code;
}

void search_item()
{
    vector<Item>::iterator p;
    Item i1;
    cout<<"\nEnter Item Code to search:";
    cin>>i1.code;
    p=find(o1.begin(),o1.end(),i1);
    if(p==o1.end())
    {
         cout<<"\nNot found.\n";
    }
    else
    {
         cout<<"\nFound.\n";
    }
}

void dlt()
{
     vector<Item>::iterator p;
    Item i1;
    cout<<"\nEnter Item Code to delete:";
    cin>>i1.code;
    p=find(o1.begin(),o1.end(),i1);
    if(p==o1.end())
    {
         cout<<"\nNot found.";
    }
    else
    {
         o1.erase(p);
         cout<<"\nDeleted.\n";
    }
}

int main(){
    int ch;
      do{
        cout<<"\n***** MENU *****";
        cout<<"\n1.Insert";
        cout<<"\n2.Display";
        cout<<"\n3.Search";
        cout<<"\n4.Sort";
        cout<<"\n5.Delete";
        cout<<"\n6.Exit";
        cout<<"\nEnter your choice:";
        cin>>ch;

        switch(ch){
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
                        sort(o1.begin(),o1.end(),compare);
                        cout<<"\n After sorting on cost: \n";
                        display();
                        break;

               case 5:
                       dlt();
                        break;

               case 6:
                        exit(0);
        }

    }while(ch!=7);

      return 0;
}



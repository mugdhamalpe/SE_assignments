//Name: Mugdha Malpe

//  Home  Assignment  5

/*
Write a C++ program to have a class Inventory1 with members- code, items, prices, show(), getCode(), getItem(), getPrice(). In main(), perform the following :

Inventory1 obj (100, 5, 140.8);  //code,items,price
double total_value;
total_value = obj ;

Create another class Inventory2 with members- code, value, show(). In main(), perform the following :
Inventory1 obj (100, 5, 140.8);  //code,items,price
Inventory2 o;
o = obj ;
o.show();
*/

#include <bits/stdc++.h>

using namespace std;

class Inventory1{
    int code;
    int items;
    double price;

    public:
    void show();
    int getCode();
    int getItem();
    double getPrice();
    operator double();

    Inventory1(){
        int code = 0;
        int items = 0; 
        double price = 0.0; 
    }

    Inventory1(int code,int items,double price){
        this-> code = code;
        this->items = items; 
        this-> price = price;
    }
};

void Inventory1::show(){
    cout<<"-----Inventory1 output-----"<<endl;
    cout<<"Price per item is: "<<price<<endl;
    cout<<"Total items are: "<<items<<endl;
    cout<<"Code is: "<<code<<endl;
}
int Inventory1::getCode(){
   return code;
}
int Inventory1::getItem(){
    return items;
}
double Inventory1::getPrice(){
    return price;
}
Inventory1::operator double(){
    cout<<"Value of price*items is: ";
    return price*items;
}

class Inventory2{
    int code ; double value; 
    public:
    Inventory2(){
        int code =0;
        double value = 0.0; 
    }
    void show();
    
    void operator = (Inventory1 &  obj){
        this->code = obj.getCode();
        this->value  = obj.getItem() * obj.getPrice();
    }

};
void Inventory2::show(){
    cout<<"-----Inventory2 output-----"<<endl;
    cout<<"Value is: "<<value<<endl;
    cout<<"Code is: "<<code<<endl;

}

int main(){
    Inventory1 obj(100, 5, 140.8);
    double total_value;
    obj.show();
    total_value = obj;
    cout<<total_value<<endl;
    Inventory2 O;
    O = obj;
    O.show();
    return 0;
}
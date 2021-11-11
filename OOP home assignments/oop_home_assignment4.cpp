//Name: Mugdha Malpe

//  Home  Assignment  4

/*
Write a C++ program to have a class that represents an integer vector and define following functions to perform vector operations:
1.Initialize the vector with zero
2.Overload the >> operator to accept the element of vector
3.Display the vector elements by overloading the << operator
4.Multiply the vector with an integer (i.e. 2* obj)
5.Implementation any other two operations related to vectors (Eg. Inserting element beyond vector size, etc.)
*/

#include <iostream>
#include <vector>
using namespace std;

class Vector{
    public:
    int *p, size;
    int summation;
    int res;
    Vector(){
        size=0;
        p = new int;
        *p = 0;
    }

    Vector(const Vector& Vec){

            this->p = new int;
            this->size = Vec.size;
           
            for(int i=0;i<size;i++){
            
                *(this->p+i) = *(Vec.p+i);
            }
    }
    Vector(int size){

        this->size = size;
        
        p = new int[size];
        for (int i = 0 ; i<size;i++){
            *(p+i)= 0 ; 
        }
    }

    friend istream& operator >> (istream& input, Vector &V);
	friend ostream& operator << (ostream& output, Vector &V);

    void add_element(int);
    void delete_element(int);
    Vector operator-(Vector &);
};

istream& operator >> (istream& input, Vector &V){
    cout<<"Enter number of elements of vector: "<<endl;
    cin>>V.size;
    cout<<"Enter elements of vector: "<<endl;
    for(int i; i<V.size; i++){
        cin>>V.p[i];
    }
    return input;
}

ostream& operator << (ostream& output,Vector &V){
    cout<<"Elements of vector are: "<<endl;

    output << "[";
    if ( V.size )
    {
        const char* separator = "";
        for ( int i; i<V.size; i++ )
        {
            output << separator;
            output << V.p[i];
            separator = ", ";
        }
    }
    output << "]"<<endl;
    return output;
}

Vector operator *(int multiplier, Vector&V){
        for(int i=0;i<V.size;i++){
            *(V.p+i) = multiplier**(V.p+i);
        }
        return V;
}
void Vector::add_element(int ele){
    *(p+size) = ele;
    size++;
}
void Vector::delete_element(int index){
    int n = size-index;
    for (int i = 0 ; i<n;i++){
        *(p+index+i) = *(p+index+i+1);
    }
    size--;

}

Vector Vector::operator - (Vector & V){
    Vector temp(size);
    if (size==V.size){
        for(int i=0;i<size;i++){
            *(temp.p+i)=*(p+i)-*(V.p+i);
            
           
        }
        return temp; 
    } 
    else{
        cout<<"The sizes of the 2 vectors don't match."<<endl;
       return temp;
    }    
}

int main(){
    Vector V1;
    cin>>V1;
    cout<<V1;

    Vector vec1;
    vec1.add_element(3);
    vec1.add_element(4);
    vec1.add_element(7);
    vec1.add_element(6);
    vec1.delete_element(1);
    Vector vec2(3);
    cin>>vec2;
    
    vec2 = vec2-vec1;
   
    Vector vec3(vec2);
    cout<<vec3<<endl;
   
    Vector vec4 = 5;
   
    cout<<vec4<<endl;
}
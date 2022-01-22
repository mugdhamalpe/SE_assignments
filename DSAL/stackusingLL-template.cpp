//name: mugdha malpe
//roll no. 21153    batch: G1

//stack implementation using linked list with template class

#include <iostream>

using namespace std;

template <typename T>

class stack{
public:
    stack();
    //~stack();
    void push(T);
    void pop(T &);
    int stackTop(void);
    int peek(T);
    bool isEmpty(void);

private:
    class node{
        public:
        T data;
        node* next;
    };
    node *top;
};

template <typename T>
stack<T>::stack(){
    top = NULL;
}

// template <typename T>
// stack<T>::~stack(){
//     node* p = top;
//     while (top){
//         top = top->next;
//         delete p;
//         p = top;
//     }
// }

template <typename T>
void stack<T>::push(T x){
    //(insert at head (top))
    node* newNode = new node;
    //newNode->data = x;
    if(newNode==nullptr){
        cout<<"Stack overflow! Stack is full"<<endl;
    }else{
        newNode->data=x;
        newNode->next=top;
        top=newNode;
    }
}

template <typename T>
void stack<T>::pop(T &x){
    if (isEmpty()){
        //i.e top==NULL
        cout << "Stack Underflow! Stack is empty!" << endl;
    }
    else{
        x = top->data;
        node* temp = top;
        top = top->next;
        delete temp;
        temp = NULL;
    }
}

template <typename T>
bool stack<T>::isEmpty(void){
    return top == NULL;
}

template <typename T>
int stack<T>::stackTop(void){
    if(top){
        return top->data;
    }else{
        return -1;
    }
}

template <typename T>
int stack<T>::peek(T index){
    if(isEmpty()){
        return -1;
    }else{
        node* p=top;
        for(int i=0; p != nullptr && i<index-1; i++){
            p=p->next;
        }
        if (p != nullptr){
            return p->data;
        } else {
            return -1;
        }
    }
}


int main(){
    stack<int> obj1;

    int option, data, x, position;

    do {
        cout << "What operation do you want to perform?" <<
        "Select Option number. Enter 0 to exit." << endl;
        cout << "1. push()" << endl;
        cout << "2. pop()" << endl;
        cout << "3. isEmpty()" << endl;
        cout << "4. stackTop()" << endl;
        cout << "5. peek()" << endl;
        cout<<"Enter the option: ";
        cin >> option;

        switch (option) {
        case 0:
            break;
        case 1:
            cout << "enter data to push into stack"<<endl;
            cin>>data;
            obj1.push(data);
            cout<<"successfully pushed value into stack"<<endl;
            break;
        case 2:
            cout<<"enter value to be pooped: ";
            cin>>x;
            obj1.pop(x);
            cout<<"successfully popped value from stack"<<endl;
            // cout << "poped Value: " << endl;
            // cout<<x<<endl;
            break;
        case 3:
            if (obj1.isEmpty())
                cout << "Stack is Empty" << endl;
            else
                cout << "Stack is not Empty" << endl;
            break;
        case 4:
            cout<<"stack top is: "<<obj1.stackTop()<<endl;
            break;
        case 5:
            cout<<"enter position to peek at: ";
            cin>>position;
            cout<<"stack peek at entered position is: "<<obj1.peek(position)<<endl;
            break;
        default:
            cout<<"invalid selection"<<endl;
            break;
        }
    }while(option!=0);

    return 0;
}
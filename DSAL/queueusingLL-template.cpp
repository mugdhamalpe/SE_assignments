//name: mugdha malpe
//roll no. 21153    batch: G1

//queue implementation using linked list with template class

#include<iostream>
using namespace std;

template<typename T> class Node{
    public:
        T data;
        Node<T>* next;
        template<typename U>friend class Queue;
};

template<typename U> class Queue{
    private:
        Node<U>* front;
        Node<U>* rear;
    public:
    Queue();
    void enqueue(U);
    int dequeue();
    bool isEmpty();
    void display();
};

template <typename U>
Queue<U>::Queue(){
    front=nullptr;
    rear=nullptr;
}

template <typename U>
void Queue<U>::enqueue(U x){
    Node<U>* t=new Node<U>;
    if(t==nullptr){
        cout<<"queue overflow"<<endl;
    }else{
        t->data=x;
        t->next=nullptr;
        if(front==nullptr){
            front=t;
            rear=t;
        }else{
            rear->next=t;
            rear=t;
        }
    }
}

template <typename U>
int Queue<U>::dequeue(){
    int x = -1;
    Node<U>* p;
    if (isEmpty()){
        cout << "queue underflow" << endl;
    } else {
        p = front;
        front = front->next;
        x = p->data;
        delete p;
    }
    return x;
}

template <typename U>
bool Queue<U>::isEmpty(){
    if (front == nullptr){
        return true;
    }
    return false;
}

template <typename U>
void Queue<U>::display() {
    Node<U>* p = front;
    while (p){
        cout << p->data << flush;
        p = p->next;
        if (p != nullptr){
            cout << " <- " << flush;
        }
    }
    cout << endl;
}


int main(){
    bool quit = false;
    Queue<int> queue;
    int temp;
    do{
        cout<<"*****MENU*****"<<endl;
        cout<<"1. for enqueue"<<endl;
        cout<<"2. for dequeue"<<endl;
        cout<<"3. is empty"<<endl;
        cout<<"4. display"<<endl;
        cout<<"5. exit"<<endl;
        cout<<"**************"<<endl;
        int ch;
        cout<<"select option: "<<endl;
        cin>>ch;
        switch (ch)
        {
        case 1:
            cout<<"enter item to enqueue:"<<endl;
            cin>>temp;
            queue.enqueue(temp);
            break;
        case 2:
            queue.dequeue();
            break;
        case 3:
            if(queue.isEmpty()){
                cout<<"queue is empty"<<endl;
            }else{
                cout<<"queue is not empty"<<endl;
            }
            break;
        case 4:
            if(!queue.isEmpty()){
                cout<<"present queue is as follows: "<<endl;
                queue.display();
            }
            else{
                cout<<"queue is empty, so cannot be displayed"<<endl;
            }
            break;
        case 5:
            quit = true;
            break;
        default:
            cout<<"invalid selection"<<endl;
            break;
        }
    }while(!quit);
    return 0;
}
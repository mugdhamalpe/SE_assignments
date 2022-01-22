/*Q1.Write C++ function to create linked list of given number,
if the addition of digits in a number is even it should be added at start,
if addition of digits in a number is odd it should be added at the end. Perform following operations on linked list
1)Insert number
2)Do addition of odd places numbers and display.
3)Do addition of even places numbers and display.
4)Do addition of prime numbers.
5)Delete odd numbers which are prime from the listNote :- Accept input as decimal number.*/

#include<iostream>

using namespace std;

class Node{
    int data;
    Node *next;
    public:
    Node(){
        data=0;
        next=NULL;
    }
    Node(int val){
        data=val;
        next=NULL;
    }

    friend class OperationOnSLL;
};

class OperationOnSLL{
    Node *head;
    Node *del;

    public:
    OperationOnSLL(){
        head=NULL;
        del=NULL;
    }
    void insertAtEnd(int val);
    void insertAtStart(int val);
    void display();
    void evenOddSum();
    bool isPrime(int n);
    void evenOddPrime();
    void deleteNode(int position);
    void deletePrimeNodes();
};

void OperationOnSLL::insertAtEnd(int val){
    Node* n=new Node(val);
    if(head==NULL) //if linkedlist is already empty
    {
        head=n;
        return;
    }
    Node* temp=head; //pointer of Node type
    while(temp->next!=NULL)//till we reach end of linkedlist
    {
        temp=temp->next;//traverse till end
    }
    temp->next=n;//assign value
}

void OperationOnSLL::insertAtStart(int val){
    Node* n=new Node(val);
    n->next=head; //point next of n to head
    head=n; // head=n
}

void OperationOnSLL::display(){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

void OperationOnSLL::evenOddSum(){
    int odd_sum = 0, even_sum = 0;
    Node* temp = head;
    while (temp!=NULL) {
        if (temp->data%2 == 0)
            even_sum += temp->data;
        else
            odd_sum += temp->data;
        temp = temp->next;
    }
    cout << "Sum of even digits= " << even_sum << endl;
    cout << "Sum of odd digits= " << odd_sum << endl;
}

bool OperationOnSLL::isPrime(int n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;

    if (n % 2 == 0 || n % 3 == 0)
        return false;

    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    return true;
}

void OperationOnSLL::evenOddPrime()
{
    int prod = 1;
    int sum = 0;
    Node* temp = head;
    while (temp != NULL) {
        if (isPrime(temp->data)) {
            prod *= temp->data;
            sum += temp->data;
        }
        temp = temp->next;
    }
    cout << "Sum of prime numbers of linkedlist= " << sum << endl;
    cout << "Product of prime numbers of linkedlist= " << prod<<endl;
}

void OperationOnSLL::deletePrimeNodes(){
    if (this->head == nullptr)
    {
        cout << "Empty linked List" << endl;
    }
    else
    {
        int remove = 0;
        Node *temp = this->head;
        Node *hold = nullptr;
        Node *prev = nullptr;
        // Iterating and find prime nodes
        while (temp != nullptr)
        {
            if (this->isPrime(temp->data))
            {
                // Is prime node
                hold = temp;
            }
            else
            {
                prev = temp;
            }
            temp = temp->next;
            if (hold != nullptr)
            {
                if (hold == this->head)
                {
                    // When delete head node
                    this->head = temp;
                    delete hold;
                    hold = nullptr;
                }
                else
                {
                    if (prev != nullptr)
                    {
                        prev->next = temp;
                    }
                    delete hold;
                    hold = nullptr;
                }
            }
        }
    }
}


int main(){
    OperationOnSLL op;
    Node* head=NULL;
    int number, sum=0, m;
    op.insertAtEnd(4);
    op.insertAtEnd(2);
    op.insertAtEnd(5);
    op.insertAtEnd(6);
    op.insertAtEnd(7);
    cout<<"Current linked list is: "<<endl;
    op.display();
    cout<<"Enter number to check: "<<endl;
    cin>>number;
    //part 1
    op.insertAtEnd(number);
    op.display();
    //part - insert at start/end
    while(number>0){
        m=number%10;
        sum+=m;
        number=number/10;
    }
    if(sum%2==0){
        op.insertAtStart(sum);
        op.display();
    }else if(sum%2!=0){
        op.insertAtEnd(sum);
        op.display();
    }
    // insertAtEnd(head, 10);
    // insertAtEnd(head, 11);
    // display(head);
    //part2
    cout<<"Sum of odd and even places of linkedlist: "<<endl;
    op.evenOddSum();
    cout<<"Addition and product of prime nodes: "<<endl;
    op.evenOddPrime();
    op.display();
    cout<<"Deletion of prime nodes: "<<endl;
    op.deletePrimeNodes();
    op.display();
    return 0;
}
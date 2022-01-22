// Write C++ function to create linked list of each character in given string.
// If character is in lower case insert at start, if character is in upper case insert at the end.
// Perform following operations
// 1)Accept string and create list as said above.
// 2)After every vovel enter new node with data “#”
// 3)Delete all consonants in upper case.


#include <bits/stdc++.h>

using namespace std;

class Node{
    char data;
    Node *next;
    public:
    Node(){
        data='\0';
        next=NULL;
    }
    Node(char val){
        this->data=val;
        this->next=NULL;
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

    void insertAtEnd(char val);
    void insertAtStart(char val);
    // void deleteAtHead();
    // void deletion(int val);
    void deleteNode(int position);
    void display();
};

void OperationOnSLL::insertAtEnd(char val){
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

void OperationOnSLL::insertAtStart(char val){
    Node* n=new Node(val);
    n->next=head; //point next of n to head
    head=n; // head=n
}

void OperationOnSLL::deleteNode(int position) {
    if (position == 1 && head != NULL) {
        Node* nodeToDelete = head;
        head = head->next;
        free(nodeToDelete);
    }
    else{
        Node* temp = head;
        for(int i = 1; i < position-1; i++) {
            if(temp != NULL) {
                temp = temp->next;
            }
        }
        if(temp != NULL && temp->next != NULL) {
            Node* nodeToDelete = temp->next;
            temp->next = temp->next->next;
            free(nodeToDelete);
        }
        else {
            cout<<"\nThe node is already null :(";
        }
    }
}

void OperationOnSLL::display(){
    cout<<"current linked list is: "<<endl;
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

int main(){
    OperationOnSLL obj;
    string s;
    bool quit = false;
    int temp;
    cout<<"Enter string: ";
    cin>>s;
    do{
        cout<<"******MENU******"<<endl;
        cout<<"1. Operation A"<<endl;
        cout<<"2. Operation C"<<endl;
        cout<<"3. Operation B"<<endl;
        cout<<"4. EXIT"<<endl;
        int ch;
        cout<<"select option: "<<endl;
        cin>>ch;
        switch (ch)
        {
        case 1:
            for(int i=0; i<s.length(); i++){
                if (s[i] >= 'A' && s[i]<= 'Z'){
                    cout<<"Inserting at end ... "<<s[i]<<endl;
                    obj.insertAtEnd(s[i]);
                }else if((s[i] >= 'a' && s[i] <= 'z')){
                    cout<<"Inserting at start ... "<<s[i]<<endl;
                    obj.insertAtStart(s[i]);
                }
            }
            obj.display();
            break;
        case 2:
            for(int i=0; i<s.length(); i++){
                if((s[i] >= 'A' && s[i]<= 'Z') && (s[i]!='A' || s[i]!='E' || s[i]!='O' || s[i]!='I' || s[i]!='U')){
                    obj.deleteNode(i);
                }
            }
            obj.display();
            break;
        case 3:
            for(int i=0; i<s.length(); i++){
                if(islower(s[i])){
                    string vowel="aeiouAEIOU";
                    size_t found=vowel.find(s[i]);
                    if(found!=string::npos){
                        obj.insertAtStart('#');
                    }
                    obj.insertAtStart(s[i]);
                }
            }
            obj.display();
            break;
        case 4:
            quit = true;
            break;
        default:
            cout<<"invalid selection"<<endl;
            break;
        }
    }while(!quit);

    return 0;
}
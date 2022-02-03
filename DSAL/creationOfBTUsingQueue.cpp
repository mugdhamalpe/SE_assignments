#include <bits/stdc++.h>

using namespace std;

class Node
{
private:
    int data;
    Node *lchild;
    Node *rchild;

public:
    Node(int data, Node *lchild = NULL, Node *rchild = NULL)
    {
        this->data = data;
        this->lchild = lchild;
        this->rchild = rchild;
    }
    friend class Tree;
};

class QueueNode
{
private:
    Node *data;
    QueueNode *next;

public:
    QueueNode(Node *data = NULL, QueueNode *next = NULL)
    {
        this->data = data;
        this->next = next;
    }
    friend class Queue;
};

class Queue
{
private:
    int size;
    Node **Q;
    QueueNode *front;
    QueueNode *rear;

public:
    Queue(QueueNode *front = NULL, QueueNode *rear = NULL)
    {
        this->front = front;
        this->rear = rear;
    }
    bool isEmpty()
    {
        if (front == NULL && rear == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void enqueue(Node *n)
    {
        QueueNode *temp = new QueueNode(n);
        if (isEmpty())
        {
            front = temp;
            rear = temp;
        }
        else
        {
            rear->next = temp;
            rear = temp;
        }
    }

    Node *dequeue()
    {
        QueueNode *temp = NULL;
        if (isEmpty())
        {
            cout << "Queue is Empty" << endl;
            return NULL;
        }
        else
        {
            if (front == rear)
            {
                temp = front;
                front = NULL;
                rear = NULL;
                Node *deTemp = temp->data;
                delete temp;
                return deTemp;
            }
            else
            {
                temp = front;
                front = front->next;
                Node *deTemp = temp->data;
                delete temp;
                return deTemp;
            }
        }
    }

    // void display()
    // {
    //     if (isEmpty())
    //     {
    //         cout << "Queue is Empty" << endl;
    //     }
    //     else
    //     {
    //         cout << "All elements of Queue are :" << endl;
    //         Node *temp = front;
    //         while (temp != NULL)
    //         {
    //             cout << "(" << temp->key << "," << temp->data << ")"
    //                  << " -> ";
    //             temp = temp->next;
    //         }
    //         cout << endl;
    //     }
    // }
};

class Tree
{
    Node *root;

public:
    Tree() { root = NULL; }
    void CreateTree();
    void Preorder() { Preorder(root); }
    void Preorder(Node *p);
    void Postorder() { Postorder(root); }
    void Postorder(Node *p);
    void Inorder() { Inorder(root); }
    void Inorder(Node *p);
    int Height() { return Height(root); }
    int Height(Node *root);
};
void Tree::CreateTree()
{
    Node *p, *t = NULL;
    int x;
    Queue q;
    cout << "Enter root value : ";
    cin >> x;
    root = new Node(x);
    root->data = x;
    root->lchild = root->rchild = NULL;
    q.enqueue(root);
    while (!q.isEmpty())
    {
        p = q.dequeue();
        cout << "Enter left child of " << p->data << ": ";
        cin >> x;
        if (x != -1)
        {
            t = new Node(x);
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            q.enqueue(t);
        }
        cout << "Enter right child of " << p->data << ": ";
        cin >> x;
        if (x != -1)
        {
            t = new Node(x);
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            q.enqueue(t);
        }
    }
}
void Tree::Preorder(Node *p)
{
    if (p)
    {

        cout << p->data << " ";
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}
void Tree::Inorder(Node *p)
{
    if (p)
    {

        Inorder(p->lchild);
        cout << p->data << " ";
        Inorder(p->rchild);
    }
}
void Tree::Postorder(Node *p)
{
    if (p)
    {
        Postorder(p->lchild);
        Postorder(p->rchild);
        cout << p->data << " ";
    }
}

int Tree::Height(Node *root)
{

    int x = 0, y = 0;
    if (root == 0)
        return 0;
    x = Height(root->lchild);
    y = Height(root->rchild);
    if (x > y)
        return x + 1;
    else
        return y + 1;
}
int main()
{
    Tree t;
    t.CreateTree();
    cout << "Height : " << t.Height() << endl;
    cout << "Preorder ";
    t.Preorder();
    cout << endl;
    cout << "Inorder ";
    t.Inorder();
    cout << endl;
    cout << "Postorder ";
    t.Postorder();
    cout << endl;
    return 0;
}
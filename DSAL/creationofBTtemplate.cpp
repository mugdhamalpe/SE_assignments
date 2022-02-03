#include <bits/stdc++.h>

using namespace std;

template <typename T>
class Node
{
private:
    int data;
    Node *lchild;
    Node *rchild;

public:
    Node(T data)
    {
        this->data = data;
        this->lchild = NULL;
        this->rchild = NULL;
    }
    template <typename>
    friend class Tree;
};

template <typename T>
class QueueNode
{
private:
    Node<T> *data;
    QueueNode<T> *next;

public:
    QueueNode(Node<T> *data)
    {
        this->data = data;
        this->next = NULL;
    }
    template <typename>
    friend class Queue;
};

template <typename T>
class Queue
{
private:
    QueueNode<T> *front;
    QueueNode<T> *rear;

public:
    Queue(QueueNode<T> *front = NULL, QueueNode<T> *rear = NULL)
    {
        this->front = NULL;
        this->rear = NULL;
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

    void enqueue(Node<T> *n)
    {
        QueueNode<T> *temp = new QueueNode<T>(n);
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

    Node<T> *dequeue()
    {
        QueueNode<T> *temp = NULL;
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
                Node<T> *deTemp = temp->data;
                delete temp;
                return deTemp;
            }
            else
            {
                temp = front;
                front = front->next;
                Node<T> *deTemp = temp->data;
                delete temp;
                return deTemp;
            }
        }
    }
};

template <typename T>
class Tree
{
    Node<T> *root;

public:
    Tree() { root = NULL; }

    Node<T> *getRoot(){
        return this->root;
    }
    void CreateTree()
    {
        Node<T> *p, *t = NULL;
        T x;
        Queue<T> q;
        cout << "Enter root value : ";
        cin >> x;
        root = new Node<T>(x);
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
                t = new Node<T>(x);
                t->data = x;
                t->lchild = t->rchild = NULL;
                p->lchild = t;
                q.enqueue(t);
            }
            cout << "Enter right child of " << p->data << ": ";
            cin >> x;
            if (x != -1)
            {
                t = new Node<T>(x);
                t->data = x;
                t->lchild = t->rchild = NULL;
                p->rchild = t;
                q.enqueue(t);
            }
        }
    }
    void Preorder(Node<T> *p)
    {
        if (p)
        {

            cout << p->data << " ";
            Preorder(p->lchild);
            Preorder(p->rchild);
        }
    }
    void Inorder(Node<T> *p)
    {
        if (p)
        {

            Inorder(p->lchild);
            cout << p->data << " ";
            Inorder(p->rchild);
        }
    }
    void Postorder(Node<T> *p)
    {
        if (p)
        {
            Postorder(p->lchild);
            Postorder(p->rchild);
            cout << p->data << " ";
        }
    }

    int Height(Node<T> *root)
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
};

int main()
{
    Tree<int> t;
    t.CreateTree();
    Node<int> *root=t.getRoot();
    cout << "Height : " << t.Height(root) << endl;
    cout << "Preorder ";
    t.Preorder(root);
    cout << endl;
    cout << "Inorder ";
    t.Inorder(root);
    cout << endl;
    cout << "Postorder ";
    t.Postorder(root);
    cout << endl;
    return 0;
}
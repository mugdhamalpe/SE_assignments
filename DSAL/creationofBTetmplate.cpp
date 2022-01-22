#include <bits/stdc++.h>
#include "queueusingLL-template.h"

using namespace std;

<template class T>
class Node{
    int data;
    Node<T>*left, *right;
    Node(){
        data=0;
        left=right=NULL;
    }
    Node(int val){
        data=val;
        left=right=NULL;
    }

    template<typename U> friend class binarySearchTree;
};

template<typename U> class binarySearchTree{
    Node<U> *left, *right;

    public:
    binarySearchTree(){
        left=right=NULL;
    }

    //iterative approach
    // Node<U>* newNode(int val){
    //     Node<U> *temp = new Node<U>;
    //     temp->data = val;
    //     temp->left = temp->right = NULL;
    //     return temp;
    // }

    // Node<U>* insertNode(Node<U>* node, int val) {
    //     if (node == NULL) return newNode(val);
    //     if (val < node->data)
    //     node->left = insertNode(node->left, val);
    //     else if (val > node->data)
    //     node->right = insertNode(node->right, val);
    //     return node;
    // }

    void createTree()
    {
        queue<Node<T> *> q;
        cout << "Enter number of nodes: " << endl;
        int nodes;
        cin >> nodes;

        while (nodes--)
        {
            T data;
            Node<T> *temp = new Node(data);
            if (root == nullptr)
            {
                root = temp;
                q.enqueue(root);
            }
            else
            {
                while (!isEmpty())
                {
                    Node<T> *temp2 = q.dequeue();
                    cout << "Enter data of left child: " << endl;
                    cin >> data;
                    temp2->left = new Node(data);
                    q.enqueue(temp2->left);

                    cout << "Enter data of right child: " << endl;
                    cin >> data;
                    temp2->right = new Node(data);
                    q.enqueue(temp2->right);
                }
            }
        }
    }

    // void printBT(Node* root){
    //     if(!root){
    //         return;
    //     }

    //     queue<Node*> q;
    //     q.push(root);

    //     while(!q.empty()){
    //         //no of nodes
    //         int n=q.size();
    //         for(int i=0; i<n; i++){
    //             Node*temp=q.front();
    //             q.pop();
    //             if(i==n){
    //                 cout<<temp->data<<" ";
    //             }
    //             if(temp->left!=NULL){
    //                 q.push(temp->left);
    //             }
    //             if(temp->right!=NULL){
    //                 q.push(temp->right);
    //             }
    //         }
    //     }
    // }

    // void inorder(Node* root){
    //     if(root!=NULL){
    //         inorder(root->left);
    //         cout<<root->data<<" ";
    //         inorder(root->right);
    //     }
    // }

    //recursive approach
    // Node* insertBST(Node* root, int val){
    //     if(root==NULL){
    //         return new Node(val);
    //     }
    //     if(val<(root->data)){
    //         root->left=insertBST(root->left, val);
    //     }else{
    //         root->right=insertBST(root->right, val);
    //     }
    //     return root;
    // }

    // void printTree(Node* root){
    //     if(root=NULL){
    //         return;
    //     }
    //     printTree(root->left);
    //     cout<<root->data<<" ";
    //     printTree(root->right);
    // }

};

int main(){
    binarySearchTree<int> bb;
    //root=bb.insertNode(root, 50);
    // bb.insertNode(root, 20);
    // bb.insertNode(root, 10);
    // bb.insertNode(root, 40);
    // bb.insertNode(root, 30);
    //bb.printBT(root);
    //bb.inorder(root);
    // root=bb.insertBST(root, 5);
    // bb.insertBST(root, 1);
    // bb.insertBST(root, 3);
    // bb.insertBST(root, 4);
    // bb.insertBST(root, 2);
    // bb.insertBST(root, 7);

    // print inorder
    //bb.printTree(root);


    bb.createTree();

    cout<<endl;
    return 0;
}
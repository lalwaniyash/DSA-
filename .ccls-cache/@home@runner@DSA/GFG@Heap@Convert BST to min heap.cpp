// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *left, *right;
};

struct Node* getNode(int data){
    struct Node* newNode= new Node;
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void inorder(Node* root, vector<int>& a){
    if (root == NULL) return;
    
    inorder(root->left, a);
    a.push_back(root->data);
    inorder(root->right, a);
}

void BSTToMinHeap(Node* root, vector<int>a, int& i){
    if (root==NULL) return;
    root->data=a[i++];
    BSTToMinHeap(root->left, a, i);
    BSTToMinHeap(root->right, a, i);
}

void convertToMinHeap(Node* root){
    vector<int>a;
    int i = 0;
    inorder(root, a);
    BSTToMinHeap(root, a, i);
}

void preorderTraversal(Node* root)
{
    if (!root)
        return;
 
    // first print the root's data
    cout << root->data << " ";
 
    // then recur on left subtree
    preorderTraversal(root->left);
 
    // now recur on right subtree
    preorderTraversal(root->right);
}


int main() {
    struct Node* root = getNode(4);
    root->left = getNode(2);
    root->right = getNode(6);
    root->left->left = getNode(1);
    root->left->right = getNode(3);
    root->right->left = getNode(5);
    root->right->right = getNode(7);
    
    convertToMinHeap(root);
    cout<< "Preorder Traversal:" <<endl;
    preorderTraversal(root);
    
    return 0;
}
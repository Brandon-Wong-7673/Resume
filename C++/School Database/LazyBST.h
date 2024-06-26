#ifndef LAZYBST_H
#define LAZYBST_H

#include <algorithm>
#include <iostream>
#include "SingleLinkedList.h"
#include <fstream>
using namespace std;

template <class T>
class TreeNode
{   
public:
    TreeNode();
    TreeNode(T* k);
    ~TreeNode();
    //virtual TreeNode();

    T* key; // key is data
    TreeNode<T> *left;
    TreeNode<T> *right;
};

template <class T>
TreeNode<T>::TreeNode(){
    left = NULL;
    right = NULL;
    key = T();
}

template <class T>
TreeNode<T>::TreeNode(T* k){
    left = NULL;
    right = NULL;
    key = k;
}

template <class T>
TreeNode<T>::~TreeNode(){
    left = NULL;
    right = NULL;
    delete key;
}

template <class T>
class LazyBST
{
public:
    LazyBST();
    virtual ~LazyBST();

    void insert(T* value);
    T* search(T* value);
    bool contains(T* value);
    bool deleteNode(T* k);
    TreeNode<T> *getSuccessor(TreeNode<T> *d);

    bool isEmpty();
    T* getMin();
    T* getMax();
    int findNodeDepth(TreeNode<T> *node);
    int findTreeDepth();

    void printTree();
    void writeTree(ofstream& outputFile);
    void recPrint(TreeNode<T> *node);
    void recWrite(TreeNode<T> *node, ofstream& outputFile);
    bool isBalanced();
    void addMedianNode(T** list, int min, int max);
    void balanceTree();

private:
    TreeNode<T> *root;
    void recDelete(TreeNode<T> *node);
    int count;
    void makeIntoList(T** list, TreeNode<T> *node);
    int size;
    bool balancing;
    
};

template <class T>
LazyBST<T>::LazyBST()
{
    size = 0;
    balancing = false;
    root = NULL;
}

template <class T>
LazyBST<T>::~LazyBST()
{
    recDelete(root);
}

template <class T>
void LazyBST<T>::recPrint(TreeNode<T> *node){
    if(node == NULL)
        return;
    //cout << node->key << endl; // Pre Order
    //node->key->print();
    recPrint(node->left);
    node->key->print(); // In Order
    recPrint(node->right);
    //node->key->print();
    //cout << node->key << endl; // Post Order
}

template <class T>
void LazyBST<T>::recWrite(TreeNode<T> *node, ofstream& outputFile){
    if(node == NULL)
        return;
    recPrint(node->left);
    node->key->write(outputFile); // In Order
    recPrint(node->right);
}

template <class T>
void LazyBST<T>::recDelete(TreeNode<T> *node){
    if(node == NULL){
        return;
    }
    recDelete(node->left);
    recDelete(node->right);
    delete node;
}

template <class T>
void LazyBST<T>::printTree(){
    recPrint(root);
}

template <class T>
void LazyBST<T>::writeTree(ofstream& outputFile){
    recWrite(root, outputFile);
}

template <class T>
bool LazyBST<T>::isEmpty(){
    return (root == NULL);
}

template <class T>
T* LazyBST<T>::getMin(){

    if(isEmpty()){
        return NULL;
    }

    TreeNode<T> *current = root;
    while (current->left != NULL){
        current = current->left;
    }
    return &(current->key);
}

template <class T>
T* LazyBST<T>::getMax(){

    if(isEmpty()){
        return NULL;
    }

    TreeNode<T> *current = root;
    while (current->right != NULL){
        current = current->right;
    }
    return &(current->key);
}

template <class T>
void LazyBST<T>::insert(T* value){
    TreeNode<T> *node = new TreeNode<T>(value);
    if (isEmpty()){
        root = node;
    } else {
        TreeNode<T> *current = root;
        TreeNode<T> *parent = root;
        while (true){
            parent = current;
            if (*value < *current->key){
                current = current->left;
                if(current == NULL){
                    parent->left = node;
                    break;
                }
            } else {
                current = current->right;
                if(current == NULL){
                    parent->right = node;
                    break;
                }
            }
        }
    }
    size++;
    if (!isBalanced() && !balancing)
        balanceTree();
}

template <class T>
bool LazyBST<T>::contains(T* value){
    cout << "a" << endl;
    if (isEmpty() || size == 0){
        root = NULL;
        return false;
    }
    TreeNode<T> *current = root;
    while (!(*current->key == *value)){
        cout << current->key->ID << endl;
        if (*value < *current->key)
            current = current->left;
        else 
            current = current->right;
        
        if (current == NULL)
            return false;
    }
    return true;
}

template <class T>
T* LazyBST<T>::search(T* value){
    if (isEmpty())
        return NULL;
    TreeNode<T> *current = root;
    while (!(*current->key == *value)){
        if (*value < *current->key)
            current = current->left;
        else 
            current = current->right;
        
        if (current == NULL)
            return NULL;
    }
    return current->key;
}

template <class T>
bool LazyBST<T>::deleteNode(T* k){
    if (isEmpty())
        return false;

    TreeNode<T> *current = root;
    TreeNode<T> *parent = root;
    bool isLeft = true;

    while (!(*current->key == *k)){
            parent = current;
            if (*k < *current->key){
                isLeft = true;
                current = current->left;
            } else {
                isLeft = false;
                current = current->right;
            }

            if (current == NULL)
                return NULL;
        }
        
        if (current->left == NULL && current->right == NULL){
            if (current == root)
                root == NULL;
            else if (isLeft)
                parent->left = NULL;
            else
                parent->right = NULL;
        } else if (current->right == NULL){
            if (current == root)
                root == current->left;  
            else if (isLeft)
                parent->left = current->left;
            else
                parent->right = current->left;
        } else if (current->left == NULL){
            if (current == root)
                root == current->right;  
            else if (isLeft)
                parent->left = current->right;
            else
                parent->right = current->right;
        } else {
            TreeNode<T> *successor = getSuccessor(current);

            if (current = root)
                root = successor;
            else if (isLeft)
                parent->left = successor;
            else
                parent->right = successor;

            successor->left = current->left;
        }
    current->left = NULL;
    current->right = NULL;
    delete current;
    size--;
    if (size == 0)
        root = NULL;
    else if (!isBalanced())
        balanceTree();
    return true;
}

template <class T>
TreeNode<T>* LazyBST<T>::getSuccessor(TreeNode<T> *d){
    TreeNode<T> *sp = d;
    TreeNode<T> *successor = d;
    TreeNode<T> *current = d->right;

    while (current != NULL){
        sp = successor;
        successor = current;
        current = current->left;
    }
    if(successor != d->right){
        sp->left = successor->right;
        successor->right = d->right;
    }
    return successor;
}

template <class T>
int LazyBST<T>::findNodeDepth(TreeNode<T> *node){
    if (node == NULL)
        return 0;
    return (max(findNodeDepth(node->left), findNodeDepth(node->right))+1);
}

template <class T>
int LazyBST<T>::findTreeDepth(){
    return findNodeDepth(root);
}

template <class T>
bool LazyBST<T>::isBalanced(){
    return ((abs(findNodeDepth(root->left) - findNodeDepth(root->right)) < 1.5) && !balancing);
}

template <class T>
void LazyBST<T>::balanceTree(){
    
    balancing = true;
    T* list[size];
    int msize = size;
    count = 0;
    makeIntoList(list, root);
    root = NULL;
    addMedianNode(list, 0, msize);
    balancing = false;
}

template <class T>
void LazyBST<T>::makeIntoList(T** list, TreeNode<T> *node){
    if(node == NULL)
        return;
    makeIntoList(list, node->left);
    T* temp = new T(node->key);
    list[count++] = temp;
    makeIntoList(list, node->right);
    size--;
    delete node;
}

template <class T>
void LazyBST<T>::addMedianNode(T** list, int min, int max){
    int median = (max+min)/2;
    if (list[median] != NULL){
        insert(list[median]);
        list[median] = NULL;
        addMedianNode(list, min, median);
        addMedianNode(list, median, max);
    }   
}
#endif
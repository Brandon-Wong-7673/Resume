#include "SingleLinkedList.h"

SingleLinkedList::SingleLinkedList(){
    front = NULL;
    back = NULL;
    size = 0;
}

SingleLinkedList::~SingleLinkedList(){
    cout << "deconstructed SingleLinkedList" << endl;
    while(!isEmpty()){
        removeFront();
    }
} 

void SingleLinkedList::insertFront(int d){
    ListNode *node = new ListNode(d);

    if(isEmpty()){
        back = node;
    } else {
        node->next = front;
    }
    front = node;
    size++;
}

void SingleLinkedList::insertBack(int d){
    ListNode *node = new ListNode(d);

    if (isEmpty()){
        front = node;
    } else {
        back->next = node;
    }
    back = node;
    size++;
}
 
bool SingleLinkedList::isEmpty(){
    return (size == 0);
}

unsigned int SingleLinkedList::getSize(){
    return size;
}

int SingleLinkedList::removeFront(){
    if(isEmpty()){
        cerr << "list is empty" << endl;
        return -1;
    } else if (size = 1){
        back = NULL;
    }

    int temp = front->data;
    ListNode *ft = front;

    front = front->next;
    ft->next = NULL;
    delete ft;

    size--;
    return temp;
}

int SingleLinkedList::removeBack(){
    if(isEmpty()){
        cerr << "list is empty" << endl;
        return -1;
    } else if (size = 1){
        front = NULL;
    }
    ListNode *curr = front;
    ListNode *prev = front;
    while(curr->next != NULL){
        prev = curr;
        curr = curr->next;
    }
}

int SingleLinkedList::find(int value){
    int pos = -1;
    ListNode *curr = front;
    ListNode *prev = front;
    while(curr != NULL){
        ++pos;
        if(curr->data == value){
            return pos;
        }
        curr = curr->next;
    }

    return -1;
}

int SingleLinkedList::removeValue(int value){
    int pos = find(value);
    cout << "size" << size << endl;
    if (size = 1){
        //front = NULL;
        return removeFront();
    }
    if (pos == -1)
        return pos;
    return deleteAtPos(pos);
}

int SingleLinkedList::deleteAtPos(int pos){
    if(isEmpty()){
        cerr << "list is empty" << endl;
        return -1;
    } else if (size-1 < pos){
        cerr << "list is empty" << endl;
    }
    int count = 0;
    ListNode *curr = front;
    ListNode *prev = front;

    while(count != pos){
        prev = curr;
        curr = curr->next;
        count++;
    }

    if(curr == front){
        front = curr->next;
    } else if (curr == back) {
        back = prev;
    } else {
        prev->next = curr->next;
    }

    prev->next = curr->next;
    curr->next = NULL;
    int temp = curr->data;
    size--;

    delete curr;
    return temp;
}

int SingleLinkedList::findAtPos(int pos){
    if(isEmpty()){
        cerr << "list is empty" << endl;
        return -1;
    } else if (size-1 < pos){
        cerr << "list is empty" << endl;
    }
    int count = 0;
    ListNode *curr = front;

    while(count != pos){
        curr = curr->next;
        count++;
    }

    return curr->data;
}

string SingleLinkedList::getStringList(){
    string list = "" + to_string(front->data);
    ListNode* node = front->next;
    if (size > 1){
        for (int i = 1; i < size; ++i){
            list += ", " + to_string(node->data);
            node = node->next;
        }
    }
    return list;
}
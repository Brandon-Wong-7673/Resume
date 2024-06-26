#ifndef SINGLELINKEDLIST_H
#define SINGLELINKEDLIST_H
#include "ListNode.h"

class SingleLinkedList{
    public:
        SingleLinkedList();
        ~SingleLinkedList();
        void insertFront(int d);
        void insertBack(int d);
        int removeFront();
        int removeBack();
        int find(int value);
        int removeValue(int value);
        int deleteAtPos(int pos);
        int findAtPos(int pos);
        bool isEmpty();
        unsigned int getSize();
        string getStringList();

        
    private:
        ListNode *front;
        ListNode *back;
        unsigned int size;
};

#endif
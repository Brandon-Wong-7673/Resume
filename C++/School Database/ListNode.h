#ifndef LISTNODE_H
#define LISTNODE_H

#include <iostream>
using namespace std;
class ListNode{
    public:
        ListNode();
        ListNode(int d);
        ~ListNode();
        int data;
        ListNode *next;
};

#endif
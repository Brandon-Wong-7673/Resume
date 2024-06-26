#include "ListNode.h"

ListNode::ListNode(){}
ListNode::ListNode(int d){
    data = d;
    next = NULL;
}
ListNode::~ListNode(){
    cout << "deconstructed ListNode" << endl;
    next = NULL;
}
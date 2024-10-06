#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node* child;

        Node(int data){
            this->data = data;
            this->next = NULL;
            this->child = NULL;
        }
};

Node* merge(Node* list1, Node* list2){
    // Create a dummy node as a
    // placeholder for the result
    Node* dummyNode = new Node(-1);
    Node* res = dummyNode;

    // Merge the lists based on data values
    while(list1 != NULL && list2 != NULL){
        if(list1->data < list2->data){
            res->child = list1;
            res = list1;
            list1 = list1->child;
        }
        else{
            res->child = list2;
            res = list2;
            list2 = list2->child;
        }
        res->next = NULL;
    }

    // Connect the remaining
    // elements if any
    if(list1){
        res->child = list1;
    } else {
        res->child = list2;
    }

    // Break the last node's
    // link to prevent cycles
    if(dummyNode->child){
        dummyNode->child->next = NULL;
    }

    return dummyNode->child;
}
Node* flattenLinkedList(Node* head) 
{
	if(head == NULL || head->next == NULL) return head;
	Node* mergedNode = flattenLinkedList(head->next);
	head = merge(head, mergedNode);
	return head;
}
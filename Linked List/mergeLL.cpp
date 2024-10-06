#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

        Node(int data){
            this->data = data;
            this->next = NULL;
        }
};

Node* mergeTwoLists(Node* list1, Node* list2) {
        Node *t1 = list1;
        Node *t2 = list2;
        Node *dummyNode = new Node(-1);
        Node *temp = dummyNode;
        while(t1 != NULL && t2 != NULL){
            if(t1->data < t2->data){
                temp->next = t1;
                temp = t1;
                t1 = t1->next;
            }
            else{
                temp->next = t2;
                temp = t2;
                t2 = t2->next;
            }
        }
        if(t1) temp->next = t1;
        if(t2) temp->next = t2;
        return dummyNode->next;
    }
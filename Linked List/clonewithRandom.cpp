#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node* random;

        Node(int data){
            this->data = data;
            this->next = NULL;
            this->random = NULL;
        }
};

Node* copyRandomList(Node* head) {
        Node* temp = head;
        while(temp != NULL){
            Node* copy = new Node(temp->data);
            copy->next = temp->next;
            temp->next = copy;
            temp = temp->next->next;
        }

        temp = head;
        while(temp != NULL){
            Node* copy = temp->next;
            if(temp->random) copy->random = temp->random->next;
            else copy->random = NULL;
            temp = temp->next->next;
        }

        Node* dummyNode = new Node(-1);
        Node* res = dummyNode;
        temp = head;
        while(temp != NULL){
            res->next = temp->next;
            temp->next = temp->next->next;
            res = res->next;
            temp = temp->next;
        }

        return dummyNode->next;
    }
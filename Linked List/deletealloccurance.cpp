#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node* prev;

        Node(int data){
            this->data = data;
            this->next = NULL;
            this->prev = NULL;
        }
};

Node * deleteAllOccurrences(Node* head, int k) {
    Node* temp = head;
    while(temp != NULL){
        if(temp->data == k){
            if(temp == head){
                head = temp->next;
            }
            Node* nextNode = temp->next;
            Node* prevNode = temp->prev;
            if(nextNode) nextNode->prev = prevNode;
            if(prevNode) prevNode->next = nextNode;
            delete temp;
        }
        temp = temp->next;
    }
    return head;
}
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

Node* deleteMiddle(Node* head) {
        if(head == NULL || head->next == NULL) return NULL;
        Node* slow = head;
        Node* fast = head;
        fast = fast->next->next;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        Node* middle = slow->next;
        slow->next = slow->next->next;
        delete middle;
        return head;
    }
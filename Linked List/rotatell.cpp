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

Node* findLastNode(Node* temp, int k){
        int cnt = 1;
        while(temp != NULL){
            if(cnt == k) return temp;
            cnt++;
            temp = temp->next;
        }
        return temp;
    }
    Node* rotateRight(Node* head, int k) {
        if(head == NULL || k == 0) return head;
        int len = 1;
        Node* tail = head;
        while(tail->next != NULL){
            tail = tail->next;
            len++;
            
        }
        if(k % len == 0) return head;
        k = k % len;
        tail->next = head;
        Node* lastNode = findLastNode(head, len-k);
        head = lastNode->next;
        lastNode->next = NULL;
        return head;
    }
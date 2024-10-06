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

Node* findMid(Node* head){
	Node* slow = head;
	Node* fast = head->next;
	while(fast != NULL && fast->next != NULL){
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}
Node* merge(Node* list1, Node* list2) {
        Node *dummyNode = new Node(-1);
        Node *temp = dummyNode;
        while(list1 != NULL && list2 != NULL){
            if(list1->data < list2->data){
                temp->next = list1;
                temp = list1;
                list1 = list1->next;
            }
            else{
                temp->next = list2;
                temp = list2;
                list2 = list2->next;
            }
        }
        if(list1) temp->next = list1;
        if(list2) temp->next = list2;
        return dummyNode->next;
    }
Node *sortLL(Node *head)
{
    if(head == NULL || head->next == NULL) return head;
	Node* middle = findMid(head);
	Node* left = head;
	Node* right = middle->next;
	middle->next = NULL;
	left = sortLL(left);
	right = sortLL(right);
	return merge(left, right);
}
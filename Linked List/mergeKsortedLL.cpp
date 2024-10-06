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

Node* mergeKLists(vector<Node*> &listArray){
    priority_queue<pair<int, Node*>, vector<pair<int, Node*>>, greater<pair<int, Node*>>> pq;

    for(int i=0; i<listArray.size(); i++){
        if(listArray[i]){
            pq.push({listArray[i]->data, listArray[i]});
        }
    }
    Node* dummyNode = new Node(-1);
    Node* temp = dummyNode;
    while(!pq.empty()){
        pair<int, Node*> p = pq.top();
        pq.pop();
        if(p.second->next){
            pq.push({p.second->next->data, p.second->next});
        }
        temp->next = p.second;
        temp = temp->next;
    }
    return dummyNode->next;
}
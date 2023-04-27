// insert at begining of linked list
//the order u give val to linked list it gave reverse of it
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node(int x){
        data = x;
        next = NULL;
    }
};

void print(Node *head){
    Node *curr = head;
    while(curr != NULL){
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}
//T.C = O(1)
Node* insertAtBegining(Node *head,int val){
    Node *temp = new Node(val);
    temp->next = head;
    return temp;
}
int main(){
    
    Node *head = new Node(2);
    head->next = new Node(3);
    head->next->next = new Node(4);
    head->next->next->next = new Node(5);
    head = insertAtBegining(head,1);
    head = insertAtBegining(head,69);
    print(head);

    return 0;
}
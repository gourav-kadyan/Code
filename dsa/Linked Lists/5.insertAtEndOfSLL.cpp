#include<bits/stdc++.h>
using namespace std;
//insert at the end of linked list 

struct Node{
    int data;
    Node *next;
    Node(int val){
        data = val;
        next = NULL;
    }
}*head = NULL;

//T.C. = O(n)
Node* insertAtEnd(Node *head,int val){
    Node *temp = new Node(val);
    if(head == NULL){
        return temp;
    }
    Node *curr = head;
    while(curr->next != NULL){
        curr= curr->next;
    }
    curr->next = temp;
    temp->next = NULL;
    return head;
}

void print(Node *head){
    Node *curr = head;
    if(head == NULL){
        cout << "Bhai Kuch To Daal" << endl;
        return;
    }
    while(curr != NULL){
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main(){
    int val = 69;
    head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head = insertAtEnd(head,val);
    head = insertAtEnd(head,val);
    head = insertAtEnd(head,val);
    print(head);
    return 0;
}
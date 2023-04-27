#include<bits/stdc++.h>
using namespace std;

// deletion at the last node in singly linked list

struct Node{
    int data;
    Node *next;
    Node(int val){
        data = val;
        next = NULL;
    }
}*head = NULL;

//T.C. = O(n)
Node *deleteAtEnd(Node *head){
    if(head == NULL){
        return NULL;
    }
    if(head->next == NULL){
        delete head;
        return NULL;
    }
    Node *prev = head;
    while(prev->next->next != NULL){
        prev = prev->next;
    } 
    delete prev->next;
    prev->next = NULL;
    return head;
}

void print(Node *head){
    if(head == NULL){
        return;
    }
    Node *curr = head;
    while(curr != NULL){
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}
int main(){
    head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    print(head);
    head = deleteAtEnd(head);
    print(head);
    head = deleteAtEnd(head);
    print(head);
    head = deleteAtEnd(head);
    print(head);

    return 0;
}
#include<bits/stdc++.h>
using namespace std;
//insert anywhere u want
struct Node{
    int data;
    Node *next;
    Node(int val){
        data = val;
        next = NULL;
    }
}*head = NULL;

void print(Node *head){
    if(head == NULL){
        return ;
    }
    Node *curr = head;
    while(curr != NULL){
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

Node *del(Node *head,int pos){
    if(head == NULL){
        cout << "bhai kya krr rha hai" << endl;
        return NULL;
    }
    else if(pos == 1){
        head = head->next;
        return head;
    }
    Node *curr = head;
    for(int i=1;i<=pos-2 && curr != NULL;i++){
        curr = curr->next;
    }
    if(curr == NULL){
        return head;
    }
    curr->next =curr->next->next;
    return head;
}
int main(){
    int pos = 1;
    head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    print(head);
    head = del(head,pos);
    print(head);

    return 0;
}
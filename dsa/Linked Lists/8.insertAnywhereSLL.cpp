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

Node *insert(Node *head,int pos,int val){
    Node *temp = new Node(val);
    if(head == NULL && pos == 1){
        return temp;
    }
    else if(pos == 1){
        temp->next = head;
        return temp;
    }
    Node *curr = head;
    for(int i=1;i<=pos-2 && curr != NULL;i++){
        curr = curr->next;
    }
    if(curr == NULL){
        return curr;
    }
    temp->next = curr->next;
    curr->next = temp;
    return head;
}
int main(){
    int pos = 9;
    head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    print(head);
    head = insert(head,pos,69);
    print(head);

    return 0;
}
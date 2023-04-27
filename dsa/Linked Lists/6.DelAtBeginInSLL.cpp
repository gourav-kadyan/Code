#include<bits/stdc++.h>
using namespace std;
//delete at the begining of linked list 

struct Node{
    int data;
    Node *next;
    Node(int val){
        data = val;
        next = NULL;
    }
}*head = NULL;

//T.C. = O(1)
Node *deleteAtbegin(Node *head){
    //meri approach
    // if(head == NULL){
    //     cout << "kuch Nhi hai" << endl;
    //     return NULL;
    // }
    // if(head->next == NULL){
    //     cout << "Bas Karr Bhai" << endl;
    //     return NULL;
    // }
    // Node *temp = head;
    // head = head->next;
    // temp = NULL;
    // delete temp;
    // return head;

    //pro approach
    if(head == NULL){
        return NULL;
    }
    else {
        Node *temp = head->next;
        delete head;
        return temp;
    }
}

void print(Node *head){
    Node *curr = head;
    if(head == NULL){
        return;
    }
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
    print(head);
    head = deleteAtbegin(head);
    print(head);
    head = deleteAtbegin(head);
    print(head);
    head = deleteAtbegin(head);
    print(head);
    head = deleteAtbegin(head);
    print(head);
    return 0;
}
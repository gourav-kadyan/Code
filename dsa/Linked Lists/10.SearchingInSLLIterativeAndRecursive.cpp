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
//iterative approach
//t.c. = O(n) and space O(1)
// int search(Node *head,int val){
//     if(head == NULL){
//         return -1;
//     }
//     int pos = 1;
//     Node *cur = head;
//     while(cur != NULL){
//         if(cur->data == val){
//             return pos;
//         }
//         else{
//             pos++;
//             cur = cur->next;
//         }
//     }
//     if(cur == NULL){
//         return -1;
//     }
//     return pos;
// }

//recursive approach
//t.c = O(n) space O(n)
int search(Node *head,int val){
    if(head == NULL){
        return -1;
    }
    if(head->data == val){
        return 1;
    }
    else{
        int res = search(head->next,val);
        if(res == -1){
            return -1;
        }
        else{
            return (res+1);
        }
    }
}
int main(){
    int val = 699;
    head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(69);
    int pos = search(head,val);
    cout << "position is " << pos << endl;

    return 0;
}
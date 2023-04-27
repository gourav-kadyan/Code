#include<bits/stdc++.h>
using namespace std;
//implementing stack using linked list
//all operation is O(1)
struct Node{
    int data;
    Node *next;
    Node(int val){
        data = val;
        next = NULL;
    }

};

struct mystack{
    Node *head;
    int size;
    mystack(){
        head = NULL;
        size = 0;
    }
    void pussh(int val){
        if(head == NULL){
            head = new Node(val);
            size++;
            return;
        }
        Node *temp = new Node(val);
        temp->next = head;
        head = temp;
        size++;
    }
    int poop(){
        if(head == NULL){
            cout << "bhai kya krr rha hai" << endl;
            return -69;
        }
        size--;
        int lol = head->data;
        Node *temp = head;
        head = head->next;
        delete temp;
        return lol;
    }
    bool isEmpty(){
        return (head == NULL);
    }
    int toop(){
        if(head == NULL){
            return INT_MAX;
        }
        return head->data;
    }
    int sise(){
        return size;
    }


};
int main(){
    mystack s;
    s.pussh(5);
    s.pussh(10);
    s.pussh(15);
    cout << s.poop() << endl;
    cout << s.toop() << endl;
    cout << s.sise() << endl;
    cout << s.isEmpty() << endl;
    cout << s.poop() << endl;
    cout << s.poop() << endl;
    cout << s.poop() << endl;
    cout << s.poop() << endl;

    return 0;
}
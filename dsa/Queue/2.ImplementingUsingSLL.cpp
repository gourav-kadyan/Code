#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node(int val){
        data = val;
        next = NULL;
    }
};

struct Q{
    int size;
    Node *front, *rear;
    Q(){
        size = 0;
        front = rear = NULL;
    }
    void _push(int val){
        Node *temp = new Node(val);
        if(rear == NULL){
            size++;
            front = rear = temp;
            return;
        }
        size++;
        rear->next = temp;
        temp->next = NULL;
        rear = rear->next;
        //rear = temp;
    }
    void _pop(){
        if(front == NULL){
            return;
        }
        size--;
        Node *temp = front;
        front = front->next;
        if(front == NULL){
            rear = NULL;
        }
        delete (temp);
    }
    int _size(){
        return size;
    }
    int _empty(){
        return (size == 0);
    }
    
};

int main(){
    Q q;
    cout << q._size() << endl;
    q._push(5);
    q._push(10);
    q._push(15);
    cout << (q.front)->data << endl;
    cout << (q.rear)->data << endl;
    q._pop();
    cout << (q.front)->data << endl;
    cout << q._size() << endl;
    cout << q._empty() << endl;
    cout << (q.rear)->data << endl;
    q._pop();
    q._pop();
    cout << q._empty() << endl;
    return 0;
}
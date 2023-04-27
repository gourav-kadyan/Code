#include <bits/stdc++.h>
 

#define ll                  long long

#define ci(X)               ll X; cin>>X
#define cii(X, Y)           ll X, Y; cin>>X>>Y
#define ciii(X, Y, Z)       ll X, Y, Z; cin>>X>>Y>>Z
#define ciiii(W, X, Y, Z)   ll W, X, Y, Z; cin>>W>>X>>Y>>Z
 
#define krosuru             ll ___T; cin>>___T; while (___T-- > 0)
#define yehbhitheekhai      ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
 

using namespace std;

struct Node{
    int data; //we can use another but for simplicity
    Node *next;
    Node(int x){
        data = x;
        next = NULL;
    }
}*head=NULL;

void krdiyasuru()
{   
    //1st way
    // Node *head = new Node(10);
    // Node *temp1 = new Node(20);
    // Node *temp2 = new Node(30);
    // head->next = temp1;
    // temp1->next = temp2;

    //2nd way
    head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);

}
 
int main()
{
    yehbhitheekhai;
    //    solve();
    //    krosuru
    {
        krdiyasuru();
    }
}
 
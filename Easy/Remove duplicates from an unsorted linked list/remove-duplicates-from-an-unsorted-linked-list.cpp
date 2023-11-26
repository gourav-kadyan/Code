//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

void print(Node *root)
{
Node *temp = root;
while(temp!=NULL)
{
cout<<temp->data<<" ";
temp=temp->next;
}
}


// } Driver Code Ends
/*
The structure of linked list is the following

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/


class Solution
{
    public:
    //Function to remove duplicates from unsorted linked list.
    Node * removeDuplicates( Node *head) 
    {
     // your code goes here
        unordered_set<int> st;
        Node* curr = head;
        st.insert(head->data);
        while(curr != NULL){
            st.insert(curr->data);
            curr = curr->next;
        }
        Node* newhead = NULL;
        Node* temp = NULL;
        Node* lol = head;
        while(lol != NULL){
            if(temp == NULL || st.find(lol->data) != st.end()){
                Node* newnode = new Node(lol->data);
                if(temp == NULL){
                    newhead = newnode;
                }
                else{
                    temp->next = newnode;
                }
                temp = newnode;
                st.erase(lol->data);
            }
            lol = lol->next;
        }
        return newhead;
    }
};


//{ Driver Code Starts.

int main() {
	// your code goes here
	int T;
	cin>>T;
	
	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;
 
		for(int i=0;i<K;i++){
		int data;
		cin>>data;
			if(head==NULL)
			head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp=temp->next;
			}
		}
		
	    Solution ob;
		Node *result  = ob.removeDuplicates(head);
		print(result);
		cout<<endl;
		
	}
	return 0;
}
// } Driver Code Ends
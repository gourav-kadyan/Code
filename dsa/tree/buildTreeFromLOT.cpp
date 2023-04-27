//1 2 4 -1 -1 5 -1 -1 3 -1 -1

#include<bits/stdc++.h>
using namespace std;

class TreeNode {
    public:
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};


void buildTreeFromLOT(TreeNode* &root){
    int data;
    cout << "Enter data for root node: ";
    cin >> data;
    root = new TreeNode(data);
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        TreeNode* temp = q.front();
        q.pop();
        int leftdata;
        cout << "Enter the data for left of this node : "<< temp->data << endl;
        cin >> leftdata;
        if(leftdata != -1){
            temp->left = new TreeNode(leftdata);
            q.push(temp->left);
        }

        int rightdata;
        cout << "Enter the data for right of this node : "<< temp->data << endl;
        cin >> rightdata;
        if(rightdata != -1){
            temp->right = new TreeNode(rightdata);
            q.push(temp->right);
        }

    }
}

void levelOrderTraversalWithSeperator(TreeNode* root){
    queue<TreeNode*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        TreeNode* node = q.front();
        q.pop();
        if(node == NULL){
            cout << endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout << node->data << " ";
            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
        }
    }

}

int main(){

    TreeNode* root = NULL;
    buildTreeFromLOT(root);
    levelOrderTraversalWithSeperator(root);
    
    return 0;
}
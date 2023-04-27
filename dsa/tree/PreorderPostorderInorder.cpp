// there are 4 types of traversal in Tree

// 1 = levelOrderTraversal
// 2 = Inorder --  L N R
// 3 = Preorder -- N L R
// 4 = PostOrder -- L R N

// treenode val == 1 2 4 -1 -1 5 -1 -1 3 -1 -1

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

TreeNode* buildTree(TreeNode* root){

    int data;
    //cout << "Enter the data : ";
    cin >> data;

    root = new TreeNode(data);
    if(data == -1){
        return NULL;
    }
    
    //cout << "Enter the left of this node : " << root->data << endl;
    root->left = buildTree(root->left);

    //cout << "Enter the right of this node : " << root->data << endl;
    root->right = buildTree(root->right);

    return root;
}


void levelOrderTraversal(TreeNode* root){
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        TreeNode* node = q.front();
        q.pop();
        cout << node->data << " ";
        if(node->left){
            q.push(node->left);
        }
        if(node->right){
            q.push(node->right);
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

void Inorder(TreeNode * root){
    if(!root){
        return;
    }

    Inorder(root->left);
    cout << root->data << " ";
    Inorder(root->right);
}

void Preorder(TreeNode * root){
    if(!root){
        return;
    }
    cout << root->data << " ";
    Preorder(root->left);
    Preorder(root->right);
}

void Postorder(TreeNode * root){
    if(!root){
        return;
    }

    Postorder(root->left);
    Postorder(root->right);
    cout << root->data << " ";
}

int main(){

    TreeNode* root = NULL;
    root = buildTree(root);
    cout << endl;
    cout<< endl;

    // levelOrderTraversal(root); 
    // cout << endl;
    // cout << endl;
    // cout << "another one with separator" << endl;
    // cout << endl;
    levelOrderTraversalWithSeperator(root);

    // Inorder 
    cout << endl << "inOrder traversal ";
    Inorder(root);
    cout << endl;

    cout << endl << "PreOrder traversal ";
    Preorder(root);
    cout << endl;

    cout << endl << "PostOrder traversal ";
    Postorder(root);
    cout << endl;




    
    return 0;
}
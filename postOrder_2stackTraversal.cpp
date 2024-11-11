#include<bits/stdc++.h>
#include<stack>

using namespace std;

class TreeNode{
    public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data1,TreeNode* left1,TreeNode* right1){
        data=data1;
        left=left1;
        right=right1;
    }

    TreeNode(int data1){
        data=data1;
        left=nullptr;
        right=nullptr;
    }


};

vector<int> postorderTraversal(TreeNode* root){
    vector<int>postorder;
    stack<TreeNode*>st1,st2;
    st1.push(root);
    while(!st1.empty()){
        root=st1.top();
        st1.pop();
        st2.push(root);
        if(root->left!=NULL){
            st1.push(root->left);
        }
        if(root->right!=NULL){
            st1.push(root->right);
        }
    }

    while(!st2.empty()){
        postorder.push_back(root->data);
        st2.pop();
    }

    return postorder;
}
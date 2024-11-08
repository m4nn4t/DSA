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

vector<TreeNode*> preorderTraversal(TreeNode* root){
    vector<TreeNode*>ans;

    stack<TreeNode*>st;
    st.push(root);
    while(!st.empty()){
        root=st.top();
        st.pop();
        ans.push_back(root);
        if(root->right!=NULL){
            ans.push_back(root->right);
        }
         if(root->left!=NULL){
            ans.push_back(root->left);

    }

    return ans;
}

}

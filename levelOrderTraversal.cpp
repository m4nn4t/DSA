#include<iostream>
#include<queue>

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

vector<vector<int>> levelorderTraversal(TreeNode* root){
    vector<vector<int>>ans;

    if(root==NULL){
        return ans;
    }

    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()){
        vector<int>level;
        int size=q.size();
        for(int i=0;i<size;i++){
        TreeNode* node=q.front();
        q.pop();
        if(node->left!=NULL){q.push(node->left);}
        if(node->right!=NULL){q.push(node->right);}
        level.push_back(node->data);
        }

        ans.push_back(level);
       
    }

    return ans;

}
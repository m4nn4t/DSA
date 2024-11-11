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

int check(TreeNode* root){
    if(root==NULL){
        return 0;
    }

    int lh=check(root->left);
    int rh=check(root->left);

    if(lh==-1 || rh==-1){
        return -1;
    }

    if(abs(lh-rh)>1){
        return -1;
    }

    return 1+max(lh,rh);
}
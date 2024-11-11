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

int max(int a,int b){
    if(a>b){
        return a;
    }

    else {
        return b;
    }
}

int maxHeight(TreeNode* root){
    if(root==NULL){
        return 0;
    }

    int lh=maxHeight(root->left);
    int rh=maxHeight(root->right);

    return (1+max(lh,rh));
}
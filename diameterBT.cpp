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

int diameter=0;

int diameterBT(TreeNode* root,int diameter){
    if(root==NULL){
        return 0;
    }

    int lh=diameterBT(root->left,diameter);
    int rh=diameterBT(root->right,diameter);

    diameter=max(diameter,lh+rh);

    return 1+max(lh,rh);
}
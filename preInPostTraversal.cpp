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

vector<int> preInPostTraversal(TreeNode* root){
    vector<int>pre,in,post;
    stack<pair<TreeNode*,int>>st;
    st.push({root,1});

    if(root==NULL){
        return;
    }
    while(!st.empty()){
        auto it=st.top();
        st.pop();

        if(it.second==1){
            pre.push_back(it.first->data);
            it.second++;
            st.push(it);

            if(it.first->left!=NULL){
                st.push({it.first->left,1});
            }
        }

        else if(it.second==2){
            in.push_back(it.first->data);
            it.second++;
            st.push(it);

            if(it.first->right!=NULL){
                st.push({it.first->right,1});
            }
        }

        else{
            post.push_back(it.first->data);

        }
    }


}
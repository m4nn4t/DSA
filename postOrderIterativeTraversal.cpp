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

vector<int> postOrderIterativeTraversal(TreeNode* root){
    vector<int>postorder;
    stack<TreeNode*>st;

    TreeNode* curr=root;
    TreeNode* temp=nullptr;
    

    while(curr!=NULL && !st.empty()){
        if(curr!=NULL){
            st.push(curr);
            curr=curr->left;
        }

        else{
            temp=st.top()->right;
        }

        if(temp==NULL){
            temp=st.top();
            st.pop();
            postorder.push_back(temp->data);

            while(!st.empty() && temp==st.top()->right){
                temp=st.top();
                st.pop();
                postorder.push_back(temp->data);

            }
        }

        else{
            curr=temp;
        }

    }
}
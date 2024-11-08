#include<bits/stdc++.h>
#include<stack>

// like recursion---->left print right
                  //    move to the leftest node  print retract and move to right

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

vector<int> inorderIterativeTraversal(TreeNode* root){
    vector<int>inorder;
    stack<TreeNode*>st;
    st.push(root);
    TreeNode* node=root;
    while(true){
        if(node!=NULL){
            st.push(node);
            node=node->left;
        }

        else{
            if(st.empty()==true){
                break;
            }

            else{
                node=st.top();
                st.pop();
                inorder.push_back(node->data);
                node=node->right;
            }
        }
    }

    return inorder;
}
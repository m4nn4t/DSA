#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* back;

    Node(int data1,Node* next1,Node* back1){
        data=data1;
        next=next1;
        back=back1;
    }

    Node(int data1){
        data=data1;
        next=nullptr;
        back=nullptr;
    }
};

Node* Converting_arr_2_dll(int arr[],int n){
    Node* head=new Node(arr[0]);
    Node* mover=head;
    for(int i=1;i<n;i++){
        Node* temp=new Node(arr[i]);
        mover->next=temp;
        mover=temp;
    }

    return head;
}

void display(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

Node* findright(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        temp=temp->next;
    }

    return temp;

}

vector<pair<int,int>> findsumPair(Node* head,int sum){
    vector<pair<int,int>>ans;

    Node* left=head;
    Node* right=findright(head);

    while(left->data<right->data){
        if((left->data+right->data)>sum){
            right=right->back;
        }

        else if((left->data+right->data)<sum){
             left=left->next;
        }

        else if((left->data+right->data)==sum){
            ans.push_back({left->data,right->data});
            left=left->next;
            right=right->back;
        }
    }

    return ans;

}

int main(){
    int n=5;
    int arr[n]={1,2,3,4,9};
    Node* head=Converting_arr_2_dll(arr,n);
    display(head);
    
}
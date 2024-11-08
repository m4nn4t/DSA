#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* child;
    

    Node(int data1,Node* next1,Node* child1){
        data=data1;
        next=next1;
        child=child1;
    
    }

    Node(int data1){
        data=data1;
        next=nullptr;
        child=nullptr;
    
    }
};

Node* Converting_arr_2_ll(int arr[],int n){
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

Node* mergeLLvertically(Node* head1,Node* head2){
    Node* dummynode=new Node(-1);
    Node* temp=dummynode;
    Node* temp1=head1;
    Node* temp2=head2;

    while(temp1!=NULL && temp2!=NULL){
        if(temp1->data<temp2->data){
            temp->child=temp1;
            temp=temp1;
            temp1=temp1->child;
        }

        else{
            temp->child=temp2;
            temp=temp2;
            temp2=temp2->child;
        }
    }

    if(temp1){
        temp->child=temp1;
    }
    else if(temp2){
        temp->child=temp2;
    }

    return dummynode->child;


}


Node* flatteningLL(Node* head){
    Node* temp=head;
    if(temp!=NULL && temp->next!=NULL){
        return head;
    }

    Node* mergedlist=flatteningLL(head->next);
    return mergeLLvertically(temp,mergedlist);
}
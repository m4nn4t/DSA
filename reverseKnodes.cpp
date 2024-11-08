#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    

    Node(int data1,Node* next1){
        data=data1;
        next=next1;
    
    }

    Node(int data1){
        data=data1;
        next=nullptr;
    
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

Node* reverseLL(Node* low,Node* high){
    if(low==high && low->next==high){
        return low;
    }

    Node* newhead=reverseLL(low->next,high);
    Node* front=low->next;
    front->next=low;
    low->next=nullptr;

    return newhead;
}

Node* reverseKnodes(Node* head,int k){
    Node* temp=head;
    Node* low=head;
    int cnt=1;

    while(temp!=NULL){
        if(cnt==k){
            cnt=1;
            reverseLL(low,temp->next);
            low=temp->next;
        }

        cnt++;
        temp=temp->next;
    }

    return head;
}

int main(){
    int n=10;
    int arr[n]={1,2,3,4,5,6,7,8,9,10};
    Node* head=Converting_arr_2_ll(arr,n);
    Node* head1=reverseKnodes(head,3);
    display(head1);

    return 0;
}


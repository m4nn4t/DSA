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

Node* rotatekLL(Node* head,int k){
    Node* tail=head;
    int len=1;
    while(tail->next!=NULL){
       tail=tail->next;
       len++; 
    }

    if(k%len==0){
        return head;
    }

    else{
        k=k%len;
    }

    int cnt=len-k;
    Node* temp=head;
    for(int i=cnt;i>1;i--){
        temp=temp->next;
    }

    Node* newhead=temp->next;
    tail->next=head;
    temp->next=nullptr;


    return newhead;
}

int main(){
    int n=5;
    int arr[n]={1,2,3,4,5};
    Node* head=Converting_arr_2_ll(arr,n);
    Node* head1=rotatekLL(head,3);
    display(head1);

    return 0;

}
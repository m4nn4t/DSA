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

Node* mergeLL(Node* head1,Node* head2){
    Node* dummynode=new Node(-1);
    Node* current=dummynode;
    Node* temp1=head1;
    Node* temp2=head2;
    
    while(temp1!=NULL && temp2!=NULL){
        if(temp1->data<temp2->data){
            
            current->next=temp1;
            current=temp1;
            temp1=temp1->next;
        }

        else if(temp1->data>temp2->data){
            current->next=temp2;
            current=temp1;
            temp2=temp2->next;
            
            }

        

    }

    if(temp1){
        current->next=temp1;
    }

    else if(temp2){
        current->next=temp2;
    }

    return dummynode->next;

}


int main(){
    int n1=4;
    int arr1[n1]={2,4,8,10};
    Node* head1=Converting_arr_2_ll(arr1,n1);
    int n2=6;
    int arr2[n2]={1,3,3,6,11,14};
    Node* head2=Converting_arr_2_ll(arr2,n2);

    Node* head3=mergeLL(head1,head2);
    display(head3);

    return 0;
}
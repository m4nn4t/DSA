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

Node* removeDuplicates(Node* head){
    Node* slow=head;
    while(slow->next!=NULL){
        Node* fast=slow->next;
        if(slow->data==fast->data){
            Node* front=fast->next;
            slow->next=front;
            front->back=slow;
            delete fast;
        }

        else if(slow->data!=fast->data){
            slow=slow->next;
        }
    }

    return head;
}

int main(){
    int n=7;
    int arr[7]={1,1,1,2,3,3,4};
    Node* head=Converting_arr_2_dll(arr,n);
    Node* head1=removeDuplicates(head);
    display(head1);

    return 0;
}
#include<iostream>
using namespace std;


//   reversing a linked list


class Node{
    public:
    int data;
    Node* next;
   

    Node(int data1,Node* next1){
        data=data1;
        next=next1;
       ;
    }

    Node(int data1){
        data=data1;
        next=nullptr;
       
    }
    
};   //REPRESENTATION OF LINKED LIST


Node* Converting_arr_2_ll(int arr[],int n){
    Node* head=new Node(arr[0]);
    Node* mover=head;
    for(int i=1;i<n;i++){
        Node* temp=new Node(arr[i]);
        mover->next=temp;
        mover=temp;
    }

    return head;

} //CONVERTING ARRAY TO LINKED LINKED LIST

void display_ll(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<< " ";
        temp=temp->next;
    }
}  //TRANSVERSAL


int midPointLL(Node* head){
    Node* slow=head;
    Node* fast=head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }

    return slow->data;
}


int main(){
    int n=6;
    int arr1[n]={1,3,4,2,5,6};
   
    Node* head1=Converting_arr_2_ll(arr1,n);
    int a=midPointLL(head1);
    display_ll(head1);
    cout<<a;
     return 0;
    
}
#include<iostream>
using namespace std;


//   removing Nth Node from the end


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

    Node(int data1,Node* back1){
        data=data1;
        next=nullptr;
        back=back1;
    }

    Node(int data1){
        data=data1;
        next=nullptr;
        back=nullptr;
    }
};   //REPRESENTATION OF A DOUBLLY LINKED LIST


Node* Converting_arr_2_dll(int arr[],int n){
    Node* head=new Node(arr[0]);
    Node* mover=head;
    for(int i=1;i<n;i++){
        Node* temp=new Node(arr[i]);
        mover->next=temp;
        temp->back=mover;
        mover=temp;
    }

    return head;

} //CONVERTING ARRAY TO DOUBLLY LINKED LIST

void display_dll(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<< " ";
        temp=temp->next;
    }
}  //TRANSVERSAL

Node* removeNthNode(Node* head,int n){

    Node* fast=head;
    for(int i=0;i<n;i++){
        fast=fast->next;
    }
    if(fast==NULL){
        return head->next;
    }
    Node* slow=head;
    while(fast->next!=NULL){
        fast=fast->next;
        slow=slow->next;
    }

    Node* temp=slow->next;
    slow->next=slow->next->next;
    delete temp;

    return head;



}


int main(){
    int n=6;
    int arr1[n]={1,3,4,2,5,6};
   
    Node* head1=Converting_arr_2_dll(arr1,n);
    Node* head2=removeNthNode(head1,3);
    display_dll(head2);
     return 0;
    
}
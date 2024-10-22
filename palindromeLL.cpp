#include<iostream>
using namespace std;


//   checking id given ll is a palindrome
//SEGMENTATION FAULT


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

// Node* recursiveReverse(Node* head){
//     if(head==NULL || head->next==NULL){
//         return head;
//     }

//     Node* newhead=recursiveReverse(head->next);
//     Node* front=head->next;
//     front->next=head;
//     head=nullptr;

//     return newhead;
// }

Node* recursiveReverse(Node* head){
    if(head==NULL || head->next==NULL){
        return head;
    }

    Node* newhead=recursiveReverse(head->next);
    Node* front=head->next;
    front ->next=head;
    head->next=nullptr;


    return newhead;

}

bool palindromeLL(Node* head){

    Node* slow=head;
    Node* fast=head;
    while(fast->next!=NULL && fast->next->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }

    Node* newhead=recursiveReverse(slow->next);

    Node* first=head;
    Node* last=newhead;
    while(last!=NULL){
        if(first->data!=last->data){
            return false;
        }
        first=first->next;
        last=last->next;

    }

    recursiveReverse(newhead);

    return true;


}

int main(){
    int n=6;
    int arr1[n]={1,3,4,4,9,1};
   
    Node* head1=Converting_arr_2_ll(arr1,n);
    palindromeLL(head1);
    // Node* head2=recursiveReverse(head1);
    // display_ll(head2);
    
     return 0;
    
}
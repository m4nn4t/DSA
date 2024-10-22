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


// Node* reverseLL(Node* head){
//     Node* temp=head->next;
//     Node* front=head;
//     Node* back=head->next->next;

//     while(back!=NULL){
//         temp->next=front;
//         front=temp;
//         temp=back;

//         back=back->next;
//     }

//     back->next=temp;

//     Node* newhead=back;

//     return newhead;
// }

Node* reverseLL(Node* head){
    Node* temp=head;
    Node* prev=nullptr;
    Node* front=nullptr;
    while(temp!=NULL){
        front=temp->next;
        temp->next=prev;

        prev=temp;
        temp=front;
       
    }

    return prev;
}

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
int main(){
    int n=6;
    int arr1[n]={1,3,4,2,5,6};
   
    Node* head1=Converting_arr_2_ll(arr1,n);
    Node* head2=recursiveReverse(head1);
    display_ll(head2);
     return 0;
    
}
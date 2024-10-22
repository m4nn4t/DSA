#include<iostream>
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


// Node* oddevenll(Node* head){
//     Node* temp=head;
//     Node* prev=head;
//     Node* front=nullptr;
//     Node* dummynode=new Node(-1);
//     Node* even=dummynode;
//     int cnt=1;
//     while(temp!=NULL){
//         front=temp->next;

//         if(cnt%2!=0){
//             even=temp;
//             temp=temp->next;
//         }

//         if(cnt%2==0){
//         prev->next=front;
//         front->next=dummynode->next;

//         prev=front;
//         temp=temp->next;

//         }

//     }

//     return head;
// }

Node* oddevenll(Node* head){
    Node* odd=head;
    Node* even=head->next;
    Node* evenhead=head->next;

    while(even!=NULL && even->next!=NULL){
        odd->next=odd->next->next;
        even->next=even->next->next;

        odd=odd->next;
        even=even->next;
    }

    odd->next=evenhead;

    return head;
}

int main(){
    int n=6;
    int arr1[n]={1,3,4,2,5,6};
   
    Node* head1=Converting_arr_2_dll(arr1,n);
    Node* head2=oddevenll(head1);
    display_dll(head2);
     return 0;
    
}
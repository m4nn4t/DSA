#include<iostream>
using namespace std;


//   finding the intersection of a Y linked list
//         3->1->
//               4->6->->2->X
//   1->2->8->5->
// result==4

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

Node* intersectionYll1(Node* head1,Node* head2){
    Node* temp1=head1;
    int cnt1=0;
    while(temp1!=NULL){
        cnt1++;
        temp1=temp1->next;
    }

    Node* temp2=head2;
    int cnt2=0;
    while(temp2!=NULL){
        cnt2++;
        temp2=temp2->next;
    }
    int d;
    
    if(cnt1>cnt2){
        temp1=head1;
        int d=cnt1-cnt2;
        for(int i=0;i<d;i++){
        temp1=temp1->next;
    }
    }
    else{
       temp2=head2;
       int d=cnt2-cnt1;
       for(int i=0;i<d;i++){
        temp2=temp2->next;
    }
    }

    

    while(temp1!=temp2){
        temp1=temp1->next;
        temp2=temp2->next;
    }

    return temp1;


}

Node* intersectionYlloptimised(Node* head1,Node* head2){
    Node* temp1=head1;
    Node* temp2=head2;

    while(temp1!=temp2){
        temp1=temp1->next;
        temp2=temp2->next;

        if(temp1==temp2){
            break;
            return temp1;
        }

        if(temp1==NULL){
            temp1->next=head2;
        }

        if(temp2==NULL){
            temp2->next=head1;
        }
    }

    return temp1;
}

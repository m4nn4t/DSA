#include<iostream>
using namespace std;


//   adding one to a number  represented by a linked list

//   example  1->2->3
// result     1->2->4


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

Node* recursiveReverse(Node* head){
    if(head==NULL || head->next==NULL){
        return head;
    }

    Node* newhead=recursiveReverse(head->next);
    Node* front=head->next;
    front->next=head;
    head->next=nullptr;

    return newhead;
}

Node* add1LL(Node* head){
    Node* reversed=recursiveReverse(head);
    Node* temp=reversed;
    int carry=1;
    int sum;
    Node* dummynode=new Node(-1);
    Node* current=dummynode;
    while(temp!=NULL){
        sum=carry;
        sum=sum+temp->data;
        Node* newnode=new Node(sum%10);
        current->next=newnode;
        carry=sum/10;

        // if(carry==0){
        //     break;
        // }

        temp=temp->next;
    }

    if(carry!=0){
        Node* newnode=new Node(carry);
        current->next=newnode;
    }

    Node* add1LL=recursiveReverse(dummynode->next);

    return add1LL;

}


int main(){
    int n=6;
    int arr1[n]={1,3,4,2,5,6};
   
    Node* head1=Converting_arr_2_ll(arr1,n);
    Node* head2=add1LL(head1);

    display_ll(head2);
     return 0;
    
}

#include <iostream>
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

Node* sumlist(Node* head1,Node* head2){
    Node* temp1=head1;
    Node* temp2=head2;
    Node* dummynode=new Node(-1);
    Node* current=dummynode;
    int sum=0;
    int carry=0;
    while(temp1!=NULL || temp2!=NULL){
        sum=carry;
        if(temp1){
            sum=sum+temp1->data;
        }
        if(temp2){
            sum=sum+temp2->data;
        }

        Node* newnode=new Node(sum%10);
        carry=sum/10;

        current->next=newnode;
        current=newnode;

        if(temp1){
            temp1=temp1->next;
        }

        if(temp2){
            temp2=temp2->next;
        }
        
    }

    if(carry!=0){
        Node* newnode=new Node(carry);
        current->next=newnode;
    }

    return dummynode->next;
}

int main(){
    int n=4;
    int arr1[n]={3,5,1,5};
    int arr2[n]={1,4,0,3};
    Node* head1=Converting_arr_2_dll(arr1,n);
    Node* head2=Converting_arr_2_dll(arr2,n);

    Node* head3=sumlist(head1,head2);
    display_dll(head3);
    
   
    

    return 0;
    
}
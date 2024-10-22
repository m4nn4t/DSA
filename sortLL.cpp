#include<iostream>
using namespace std;


//   1->0->1->2->0->2->1->X

//   0->0->1->1->1->2->2->X


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

Node* sortLL(Node* head){
    Node* temp=head;

    Node* dummynode0=new Node(-1);
    Node* temp0=dummynode0;

    Node* dummynode1=new Node(-1);
    Node* temp1=dummynode1;

    Node* dummynode2=new Node(-1);
    Node* temp2=dummynode2;

    while(temp!=NULL){
        if(temp->data==0){
            temp0->next=temp;
            temp0=temp;
        }

        else if(temp->data==1){
            temp1->next=temp;
            temp1=temp;
        }

        else{
            temp2->next=temp;
            temp2=temp;
        }

        temp=temp->next;
    }

    // Node* newhead=dummynode0->next;
    // temp0->next=dummynode1->next;
    // temp1->next=dummynode2->next;
    // temp2->next=nullptr;

    //IN ORDER TO COVER ALL THE CASES

    temp0->next=(dummynode1->next)?(dummynode1->next):dummynode2->next;
    temp1->next=dummynode2->next;
    temp2->next=NULL;

    Node* newhead=dummynode0->next;

    return newhead;

}


int main(){
    int n=7;
    int arr1[n]={1,0,1,2,0,2,1};
   
    Node* head1=Converting_arr_2_dll(arr1,n);
    Node* head2=sortLL(head1);
    display_dll(head2);
     return 0;
    
}
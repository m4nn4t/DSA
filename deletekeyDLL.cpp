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

Node* deleteKey(Node* head,int key){
    Node* temp=head;
    while(temp!=NULL){
        if(temp->data=key){
            if(temp==head){
                Node* t=head;
                head=head->next;
                delete t;
                temp=head;
                }

            else if(temp->next==nullptr){
                    Node* t=temp;
                    Node* prev=temp->back;
                    prev->next=nullptr;
                    delete t;
                    break;

                }

            else{
                Node* t=temp;
                Node* prev=temp->back;
                Node* front=temp->next;
                prev->next=front;
                front->back=prev;
                delete t;
                temp=front;
            }

            

        }

        else{
            temp=temp->next;
        }
    }

    return head;
}


int main(){
    int n=6;
    int arr[n]={10,4,10,10,6,10};
    Node* head=Converting_arr_2_dll(arr,n);
    // display(head);
    Node* head1=deleteKey(head,10);
    display(head1);

    return 0;

}
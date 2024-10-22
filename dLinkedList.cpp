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

Node* deletion_head(Node* head){

    if(head==NULL || head->next==NULL){
        return NULL;
    } //EDGE CASE

    Node* temp=head;
    head=head->next;
    head->back=nullptr;
    temp->next=nullptr;
    delete temp;

    return head;
}

Node* deletion_tail(Node* head){

    if(head==NULL || head->next==NULL){
        return NULL;
    } //EDGE CASE

    Node* temp=head;
    // Node* prev=nullptr;
    while(temp->next!=NULL){
        // prev=temp;
        temp=temp->next;
        }
    Node* prev=temp->back;  // no need of traversal of prev--advantage of dll
    temp->back=nullptr;
    prev->next=nullptr;
    
    delete  temp;
    return head;
}

Node* deletion_Kth_ele(Node* head,int k){
    Node* temp=head;
    int cnt=1;
    while(temp!=NULL){

        if(k==1){
            deletion_head(head);
        }  //EDGE CASE

        if(cnt==k){
            Node* prev=temp->back;
            Node* front=temp->next;
            if(front==NULL){
                deletion_tail(head);
            } //EDGE CASE

            prev->next=front;
            front->back=prev;
            delete temp;
            break;
            }
        temp=temp->next;
        cnt++;
    }

   
    return head;
}


Node* insertion_head(Node* head,int ele){
    Node* temp=new Node(ele);
    if(head==NULL){
        return temp;
    }
    temp->next=head;
    head->back=temp;

    return temp;

}

Node* insertion_tail(Node* head,int ele){
    if(head==NULL){
        Node* temp=new Node(ele);

        return temp;
    } //EDGE CASE


    else{
    Node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }

    Node* temp1=new Node(ele);
    temp->next=temp1;
    temp1->back=temp;

    return head;
    }

}

Node* insertion_Kth_pos(Node* head,int k,int ele){
    Node* temp=head;
    int cnt=1;
    while(temp!=NULL){
        if(cnt=k){
            Node* prev=temp->back;
            Node* temp1=new Node(ele,temp,prev);
            prev->next=temp1;
            temp->back=temp1;

            break;

        }

        temp=temp->next;
        cnt++;
      
    }

    return head;
}

// Node* reverse_dll(Node* head){
//     Node* temp=head;
//     while(temp->next!=NULL){
//         temp=temp->next;
//     }

//     Node* newhead=temp;
//     while(temp->back!=NULL){
//         Node* front=temp->back;
//         Node* prev=temp->next;
//         temp->next=front;
//         temp->back=prev;
//         front->back=temp;
//         prev->next=temp;

//         temp=front;
//     }

//     return newhead;

// }   ATTEMPT

// Node* reverse_dll(Node* head){
//     Node* prev=head;
//     Node* temp=head->next;
//     while(temp->next!=NULL){
//         temp->next=prev;
//         prev->back=temp;

//         prev=temp;
//         temp=temp->back;
//     }

//     Node* newhead=temp;

//     return newhead;
// }    ATTEMPT

Node* reverse_dll(Node* head){
    Node* temp=head;
    Node* prev=nullptr;
    while(temp!=NULL){
        prev=temp->back;
        temp->back=temp->next;
        temp->next=prev;

        temp=temp->back;
    }

    Node* newhead=temp->back;

    return newhead;
}

int main(){
    int n=5;
    int arr[n]={3,5,1,5,2};
    Node* head=Converting_arr_2_dll(arr,n);
    
    Node* head1=reverse_dll(head);
    display_dll(head1);
    

    return 0;
    
}

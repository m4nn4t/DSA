#include<bits/stdc++.h>
using namespace std;


class Node{
    public:

    int data;
    Node* next;

    public:


    Node(int data1,Node* next1){
        data=data1;
        next=next1;
    }

    Node(int data1){
        data=data1;
        next=nullptr;
    }


};


Node* Converting_arr_to_LL(int arr[],int n){
    Node* mover=new Node(arr[0]);
    Node* head=mover;
    for(int i=0;i<n;i++){
        Node* temp=new Node(arr[i]);
        mover->next=temp;
    }

    return head;

}

int main() {
    int n=5;
    int arr[n]={7,3,4,2,1};

    Converting_arr_to_LL(arr,n);
      cout<<endl<<"blle blle";
    return 0;

}



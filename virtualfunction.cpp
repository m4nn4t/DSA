#include<iostream>
using namespace std;

class Parent{
    public:
    int a;

    Parent(){
      cout<<"executing parent's constructor"<<endl;
    }

    Parent(int n1){
        a=n1;

        cout<<"executing parent's constructor"<<endl;
    }

    ~Parent(){
        cout<<"executing parent's destructor"<<endl;
    }

          //declaration of pure virtual function

    virtual void function(){     //overriding
        cout<<"parent"<<endl;
    }
};

class Child : public Parent{
    public:
    int b;

    Child(){
    cout<<"executing child's contructor"<<endl;
    }

    Child(int n1){
    b=n1;
    cout<<"executing child's contructor"<<endl;
    }

    ~Child(){
        cout<<"executing child's destructor"<<endl;
    }

    void function(){
        cout<<" child"<<endl;
    }
};

int main(){
    Parent p1;
    Child c1;

    Parent* ptr;
    // ptr=&p1;
    ptr=&c1; //wont give error as child object can be declared under parent pointer but the vice vera is not true

             //however the calling a function of child class through parent pointer will give an error
    ptr->function();  

    return 0;       
    
}
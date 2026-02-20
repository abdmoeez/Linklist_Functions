#ifndef BLOCK_H
#define BLOCK_H

#include<iostream>
using namespace std;

class block{
    //Private Members
    int data;
    block* next;

    public:
    //Constructor
    block() 
    {
        data=0;
        next=NULL;
    }

    //Setters
    void setdata(int value)
    {
        data=value;
    }
    void setnext(block* ptr)
    {
        next=ptr;
    }

    //Getters
    int getdata()
    {
        return data;
    }
    block* getnext()
    {
        return next;
    }

};

//Display Function
void display(block* head)
{
    block* temp=head;
    if(temp==NULL)
    {
        cout<<"Linklist Is Empty!"<<endl;
        return;
    }
    while(temp!=NULL)
    {
        cout<<temp->getdata()<<" ";
        temp=temp->getnext();
    }
}

//Insert At Head Function
void insertathead(int value,block*& head)
{
    block* temp= new block();
    temp->setdata(value);
    temp->setnext(head);
    head=temp;
}

//Insert At End Function
void insertatend(int value,block*& head)
{
    block* temp1= new block();
    temp1->setdata(value);
    temp1->setnext(NULL);

    if(head==NULL)
    {
        head=temp1;
        return;
    }
    block* temp2=head;
    while(temp2->getnext()!=NULL)
    {
        temp2=temp2->getnext();
    }
    temp2->setnext(temp1);
}

//Insert In Between After Certain Value Function 
void insertinbetweenafter(int inputvalue,int aftervalue,block*& head)
{
    if(head==NULL)
    {
        cout<<"Linklist is Empty!"<<endl;
        return;
    }
    
    block* temp1=head;
    while(temp1!=NULL)
    {
        if(temp1->getdata()==aftervalue)
        {
            block* temp2= new block();
            temp2->setdata(inputvalue);
            temp2->setnext(temp1->getnext());
            temp1->setnext(temp2);
            return;
        }
        temp1=temp1->getnext();
    }
    cout<<"No "<<aftervalue<<" Found Linklist!";

}

//Make Linklist Circular
void makecircular(block*&head)
{
    if(head==NULL)
    {
        return;
    }

    block* temp=head;
    while(temp->getnext()!=NULL)
    {
        temp=temp->getnext();
    }
    temp->setnext(head);
}

//Delete Duplicates
void deleteduplicates(block*& head)
{
    block* temp1=head;
    while(temp1!=NULL)
    {
        block* temp2= temp1;
        while(temp2->getnext()!=NULL)
        {
            if(temp2->getnext()->getdata()==temp1->getdata())
            {
                block* dup= temp2->getnext();
                temp2->setnext(dup->getnext());
                delete dup;
            }
            else
            {
                temp2=temp2->getnext();
            }
        }
        temp1=temp1->getnext();
    }
}

//Reverse Function
void reverse(block*& head)
{
    block* prev= NULL;
    block* curr=head;
    block* nxt=NULL;

    while(curr!=NULL)
    {
        nxt= curr->getnext();
        curr->setnext(prev);
        prev=curr;
        curr=nxt;
    }
    head=prev;
    cout<<"Reversed Linklist = ";
    display(head);
}

//Sorting Linlist In Ascending Order 
void sort(block*& head)
{
    if(head==NULL)
    {
        cout<<"Linklist Is Empty!"<<endl;
        return;
    }

    bool sorted;
    do
    {
        block* temp=head;
        while(temp!=NULL)
        {
            if(temp->getdata()==temp->getnext()->getdata())
            {
                int hold= temp->getdata();
                temp->setdata(temp->getnext()->getdata());
                temp->getnext()->setdata(hold);
                sorted=true;
            }
            temp=temp->getnext();
        }
    }while(sorted=true);

    cout<<"Sorted Linklist : ";
    display(head);
}

#endif
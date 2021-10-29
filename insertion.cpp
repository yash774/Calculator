#include<iostream>
#include <cstdlib>
using namespace std;
void display();
void insert_begin(int value);
void insert_end(int value);
void insert_mid(int value,int pos);
void delete_begin();
void delete_mid(int pos);
void delete_end();
struct node{
    int data;
    struct node *next;
};
struct node *head = NULL;
int main()
{
    int ch,value,pos;

    do{
    cout<<"please enter your choice:\n\t1. Insert at begin\n\t2. insert at end\n\t3. insert at give position\n\t4. delete beginning node.\n\t5. delete ending node\n\t6. delete node at given position\n\t7. exit\n";
    cin>>ch;
    switch(ch)
        {
        case 1:
            cout<<"please enter the value you want insert at beginning in LL : ";
            cin>>value;
            insert_begin(value);
            display();
            break;
        case 2:
            cout<<"please enter the value you want insert at end in LL : ";
            cin>>value;
            insert_end(value);
            display();
            break;
        case 3:
            cout<<"please enter the value you want insert at end in LL : ";
            cin>>value;
            cout<<"please enter the position : ";
            cin>>pos;
            insert_mid(value,pos);
            display();
            break;
        case 4:
            delete_begin();
            display();
            break;
        case 5:
            delete_end();
            display();
            break;
        case 6:
            cout<<"enter the position\n";
            cin>>pos;
            delete_mid(pos);
            display();
            break;
        }
    }while(ch!=7);

    return 0;
}
void insert_begin(int value)
{
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node*));
    temp->next = head;
    temp->data = value;
    head = temp;

}
void insert_end(int value)
{
    struct node *temp,*p;
    temp = (struct node*)malloc(sizeof(struct node*));
    temp->next = NULL;
    temp->data = value;
    if(head == NULL)
    {
        head=temp;
    }
    else
    {
        p = head;
        while(p->next != NULL)
        {
            p = p->next;
        }
        p->next = temp;
    }
    
}
void insert_mid(int value,int pos)
{
    struct node *temp,*p;
    temp = (struct node*)malloc(sizeof(struct node*));
    temp->next = NULL;
    temp->data = value;  
    p = head;
    for(int i=2;i<pos;i++)
    {
        if(p->next != NULL)
        {
           p = p->next;
        }
    }
    temp->next = p->next;
    p->next = temp;

}
void delete_begin()
{
    head = head->next;
}
void delete_end()
{
    struct node *p = head;
    while(p->next->next != NULL)
    {
        p = p->next;
    }
    p->next = NULL;

}
void delete_mid(int pos)
{
    struct node *p = head;
    for(int i=0;i<pos;i++)
    {
        p->next = p->next->next;
    }

}
void display()
{
    struct node *d;
    d = head;
    cout<<"\nLinked List:\n";
    while(d != NULL)
    {
        cout<<d->data<<"-->";
        d = d->next;

    }
    cout<<"\n";
}



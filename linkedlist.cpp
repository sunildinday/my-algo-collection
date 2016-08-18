/*
Linked List Implementation
(1):Insertion       O(n)
(2):Print List       O(n)
(3):Reverse the List    O(n)
(4):Delete the first occurrence of a number  in list
*/
#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int  ull;
typedef long long int  ll;
#define SETPRES  std::setprecision(6),std::fixed;
#define pb push_back
#define mp make_pair
#define INF 10000000
#define  Help_me  ios_base::sync_with_stdio(false);
struct node
{
    int data;
    struct node *next;
};
//code for deleting the first occurrence of data in list
void delete_item(struct node *head,struct node *prev,int vl)
{
    if(head->data==vl)//item found ...now delete it
    {
        prev->next=head->next;
        delete(head);
    }
    else
        delete_item(head->next,head,vl);

}
//code for reversing the list
struct node * reverse(struct node *current,struct node *prev)
{
    struct node *next=current->next;
    current->next=prev;
    if(next==NULL)
        return current;
   return  reverse(next,current);
}
void print(struct node *head)
{
    if(head==NULL)
        cout<<"List is empty"<<endl;
    else
while(head!=NULL)
{
cout<<head->data<<" ";
head=head->next;
}
cout<<endl;
}
void insert_back(struct node **head_ref,int vl)
{
    struct node *new_node=( node *)malloc(sizeof(node));
    new_node->data=vl;
    new_node->next=NULL;
if(*head_ref==NULL)
{
*head_ref=new_node;
}
else
{
struct node *head;
head=*head_ref;
while(head->next!=NULL)
{
    head=head->next;
}
head->next=new_node;
}
}
int main()
{
Help_me
struct node *head;
head=NULL;
while(1)
{
    cout<<"Enter 1 for insert  : 2 for print :3 for reversing :4 for deleting a node:"<<endl;
    int choice;
    int data;
    cin>>choice;
    bool flag=false;
    switch(choice)
    {
        case 1:
        cin>>data;
        insert_back(&head,data);
        break;
        case 2:
        print(head);
        break;
        case 3:
       head= reverse(head,NULL);
        break;
        case 4:
        cin>>data;
        if(head->data==data)
            head=head->next;
        else
            delete_item(head,NULL,data);
        break;
        default:
        flag=true;
    };
    if(flag)
        break;
}
    return 0;
}

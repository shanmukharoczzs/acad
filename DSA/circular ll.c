#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct node
{
    int data;
    struct node *next;
}node;

node *head=NULL;
node *tail=NULL;

void insertatbeg(int val){
    node *newnode=(node*)malloc(sizeof(node));
    newnode->data=val;
    newnode->next=NULL;
    if(head==NULL){
        head=newnode;
        head->next=head;
    }
    else{
        newnode->next=head;
        node *temp=head;
        while(temp!=NULL){
            temp=temp->next;
        }
        temp->next=head;
    }
}
void insertatend(int val){
    node *newnode=(node*)malloc(sizeof(node));
    newnode->data=val;
    if(head==NULL){
        head=newnode;
        newnode->next=head;
    }
    else{
        node *temp=head;
        while(temp!=NULL){
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->next=head;
    }
}
void display(){
    node *temp=head;
    do{
        printf("%d ",temp->data);
        temp=temp->next;
    }while(temp!=head);
}



int main() {
   int ch;
   while(1){
    scanf("%d",&ch);
    if (ch==1)
    {
        printf("1")
    }
   }
    return 0;
}
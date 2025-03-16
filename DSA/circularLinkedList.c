#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct node{
    int data;
    struct node *next;
}node;

node *head=NULL;
node *tail=NULL;

void insertAtStart(int val){
    node *newnode=(node*)malloc(sizeof(node));
    newnode->data=val;
    newnode->next=NULL;
    if(head==NULL){
        head=newnode;
        newnode->next=head;
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
void insertAtEnd(int val){
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
    printf("1.insert at start\n2.insert at end\n3.delete at head\n4.delete at tail\n");
    scanf("%d",&ch);
    if(ch==1){
        int val;
        scanf("%d",&val);
        insertAtStart(val);
    }
    else if(ch==2){
        int val;
        scanf("%d",&val);
        insertAtEnd(val);
    }
    else if (ch==3)
    {
        //delathead();
    }
    else if (ch==4)
    {
        //delattail();
    }
   }
    return 0;
}
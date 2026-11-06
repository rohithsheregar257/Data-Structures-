#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
}*head=NULL;
int count(){
    struct node *temp;
    int i=1;
    temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
        i++;
    }
    return (i);
}
struct node * create(int value){
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    if (temp==NULL){
        printf("Allocation Failed");
        exit(0);
    }
    temp->data=value;
    temp->next=NULL;
    return temp;
};
void insertBegin(int value){
    struct node *newnode;
    newnode=create(value);
    if (head==NULL){
        head=newnode;
    }else{
        newnode->next=head;
        head=newnode;
    }
}
void insertEnd(int value){
    struct node *newnode ,*temp;
    newnode=create (value);
    if (head==NULL)
        head=newnode;
    else{
        temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
            temp->next=newnode;
        }
    }
}
void insertPos(int value , int pos){
    struct node *newnode,*temp1,*temp2;
    int i,c=1;
    newnode=create(value);
    i=count();
    if (pos==1)
        insertBegin(value);
    else if (pos>i+1){
        printf("Insertion Impossible");
        return;
    } else {
        temp1=head;
        while(c<=pos-1 && temp1!=NULL){
            temp2=temp1;
            temp1=temp1->next;
            c++;
        }
        newnode->next=temp2->next;
        temp2->next=newnode;
    }
}
void display(){
    struct node *temp;
    if (head==NULL)
        printf("List Empty");
    else{
        temp=head;
        while(temp->next!=NULL){
            printf("%d\n",temp->data);
            temp=temp->next;
        }
        printf("%d\n",temp->data);
    }
}
void main(){
    int ch,pos,value;
    while(1){
        printf("\n1. Insert an element Beginning\n");
        printf("2. Insert an element End\n");
        printf("3. Insert an element Position\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
    switch(ch){
        case 1:
            printf("Enter value ");
            scanf("%d",&value);
            insertBegin(value);
            break;
        case 2:
            printf("Enter value ");
            scanf("%d",&value);
            insertEnd(value);
            break;
        case 3:
            printf("Enter value ");
            scanf("%d",&value);
            printf("Enter position ");
            scanf("%d",&pos);
            insertPos(value,pos);
            break;
        case 4:
            display();
            break;
        case 5: break;
        default:
            printf("Invalid Choice..!!");
        }
    }
}

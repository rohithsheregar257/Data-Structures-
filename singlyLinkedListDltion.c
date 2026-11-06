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
void dltEnd(){
    struct node *temp1,*temp2;
    if (head==NULL){
        printf("Deletion not possible.\n");
    }else{
        temp1=head;
        while(temp1->next!=NULL){
            temp2=temp1;
            temp1=temp1->next;
        }
        temp2->next=NULL;
        free(temp1);
    }
}
void dltBegin(){
    struct node *temp;
    if (head==NULL){
        printf("Deletion not possible.\n");
    }else{
        temp=head;
        head = head->next;
        free(temp);
    }
}
void dltPos(int pos){
    struct node *temp1,*temp2;
    int i,c=1;
    if (pos==1){
        dltBegin();
    }else if (pos>i){
        printf("Deletion not possible.\n");
        return;
    } else {
        temp1=head;
        while(c<=pos-1 && temp1->next!=NULL){
            temp2=temp1;
            temp1=temp1->next;
            c++;
        }
        temp2->next=temp1->next;
        free(temp1);
    }
}
void dltNode(int key){
    if(head==NULL){
        printf("List Empty");
        return;
    }
    struct node *temp1=head;
    struct node *temp2=NULL;
    if(temp1!=NULL && temp1->data==key){
        head = temp1->next;
        free(temp1);
        printf("Element %d deleted.",key);
        return;
    }
    while (temp1!=NULL && temp1->data!=key){
        temp2=temp1;
        temp1=temp1->next;
    }
    if (temp1==NULL){
        printf("Element %d not found.",key);
        return;
    }
    temp2->next=temp1->next;
    free(temp1);
    printf("Element %d deleted.",key);
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
    int ch,pos,value,key;
    do{
        printf("\n1. Insert an element Beginning\n");
        printf("2. Delete an element Beginning\n");
        printf("3. Delete an element End\n");
        printf("4. Delete an element Position\n");
        printf("5. Delete a Node\n");
        printf("6. Display\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
    switch(ch){
        case 1:
            printf("Enter value ");
            scanf("%d",&value);
            insertBegin(value);
            break;
        case 2:
            dltBegin();
            break;
        case 3:
            dltEnd();
            break;
        case 4:
            printf(" Enter Position Value to Delete ");
            scanf("%d",&pos);
            dltPos(pos);
            break;
        case 5:
            printf(" Enter Node Value to Delete ");
            scanf("%d",&key);
            dltNode(key);
            break;
        case 6:
            display();
            break;
        case 7: break;
        default:
            printf("Invalid Choice..!!");
        }
    }while(ch!=7);
}

#include<stdio.h>
#define SIZE 5
int item[SIZE];
int front = -1, rear = -1;
int isFull() {
    if ((front == 0 && rear == SIZE - 1) || (front == rear + 1)) {
        return 1;
    }
    return 0;
}
int isEmpty() {
    if (front == -1) {
        return 1;
    }
    return 0;
}
int deQueue() {
    int ele;
    if (isEmpty()) {
        printf("Queue is empty\n");
        return -1;
    }
    else {
        ele = item[front];
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % SIZE;
        }
    printf("Deleted element is: %d\n", ele);
    return ele;
    }
}
void enQueue(int ele) {
    if (isFull()) {
        printf("Queue is full\n");
        return;
    } else {
        if (front == -1) {
            front = 0;
        }
        rear = (rear + 1) % SIZE;
        item[rear] = ele;
        printf("Inserted element is: %d\n", ele);
    }
}
void display() {
    int i;
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    } else { 
    printf("Queue elements are: ");
    for (i = front; i != rear; i = (i + 1) % SIZE) {
        printf("%d ", item[i]);
    }
    printf("%d\n", item[rear]);
    }
}
int main() {
    int choice, ele;
    while (1) {
        printf("\n1. Insert an element\n");
        printf("2. Delete an element\n");
        printf("3. Display the queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &ele);
                enQueue(ele);
                break;
            case 2:
                deQueue();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
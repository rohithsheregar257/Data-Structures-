#include <stdio.h>
#include <stdlib.h>
#define SIZE 50
int queue_array[SIZE];
int rear = -1;
int front = -1;
void insert();
void delete();
void display();
int main() {
    int choice;
    while (1) {
        printf("\n1. Insert an element\n");
        printf("2. Delete an element\n");
        printf("3. Display the queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            insert();
            break;
        case 2:
            delete ();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(1);
        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}
void insert() {
    int add_item;
    if (rear == SIZE - 1)
        printf("Queue Overflow\n");
    else {
        if (front == -1)
            front = 0;
        printf("Insert the element in queue: ");
        scanf("%d", &add_item);
        rear = rear + 1;
        queue_array[rear] = add_item;
    }
}
void delete() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow\n");
        return;
    } else {
        printf("Element deleted from queue is: %d\n", queue_array[front]);
        front = front + 1;
    }
}
void display() {
    int i;
    if (front == -1)
        printf("Queue is empty\n");
    else {
        printf("Queue elements are:\n");
        for (i = front; i <= rear; i++)
            printf("%d ", queue_array[i]);
        printf("\n");
    }
}
#include <stdio.h>
#include <stdlib.h>

// A node used in linked list.
struct Node
{
    int data;
    struct Node *next;
};

// Insert at front of the list
void push(struct Node **head, int data);

// Given a prev node, insert after the given node
void insertAfter(struct Node *prev_node, int data);

// Given a reference to the head, append a new node at the end
void append(struct Node **head, int data);

// Given a reference to the head and a key, delete the first occurence of key in LL.
void deleteNode(struct Node **head, int key);

// Print the content of the linked list starting from the given node
void print(struct Node *start);

int main()
{
    struct Node *head = NULL;
    // create a main function that completes all given functions.
    return 0;
}

void push(struct Node **head, int data)
{
    // complete the function

    /*
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

    new_node->data = data;
    new_node->next = head;
    head = new_node;
    */
}

void insertAfter(struct Node *prev_node, int data)
{
    // complete the function
    /*
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

    if(prev_node == NULL) return;

    new_node->data = data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
    */
}

void append(struct Node **head, int data)
{
    // complete the function
    /*
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;

    struct Node* temp = head;

    if(head == NULL) return;

    while(temp->next != NULL){
        temp = temp->next;
    }

    temp->next = new_node;
    */
}

void deleteNode(struct Node **head, int key)
{
    // complete the function

    /*
    struct Node* temp = head;
    struct Node* prev = head;

    if(head == NULL) return;

    if(temp != NULL && temp->data == key){
        head = temp->next;
        free(temp);
        return;
    }

    while(temp != NULL && temp->data != key){
        prev = temp;
        temp = temp->next;
    }

    if(temp==NULL) return;
    prev->next = temp->next;

    free(temp);
    */
}

void print(struct Node *start)
{ // complete the function

/*
    if(start == NULL){
        printf("Linked List is empty");
        return;
    }

    while(start->next != NULL){
        printf("%d->",start->data);
    }
    printf("end");
    return;
    */
}

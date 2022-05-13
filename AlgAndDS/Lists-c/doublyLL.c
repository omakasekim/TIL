/* ******** Doubly Linked List ********** */

#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
};

void push(struct Node** head_ref, int new_data);
void insertAfter(struct Node* prev_node, int new_data);
void append(struct Node** head_ref, int new_data);
void printList(struct Node* node);
void deleteNode(struct Node** head_ref, struct Node* del);

int main(){
//Driver Code
    struct Node* head = NULL;
    //all functions that accept double pointers should have &head as the parameter


    // Insert 6.  So linked list becomes 6->NULL
    append(&head, 6);
 
    // Insert 7 at the beginning. So linked list becomes
    // 7->6->NULL
    push(&head, 7);
 
    // Insert 1 at the beginning. So linked list becomes
    // 1->7->6->NULL
    push(&head, 1);
 
    // Insert 4 at the end. So linked list becomes
    // 1->7->6->4->NULL
    append(&head, 4);
 
    // Insert 8, after 7. So linked list becomes
    // 1->7->8->6->4->NULL
    insertAfter(head->next, 8);
 
    printf("Created DLL is: ");
    printList(head);

    return 0;
}


/* Given a reference (pointer to pointer) to the head of a
   list and an int, inserts a new node on the front of the
   list. */
void push(struct Node** head_ref, int new_data){
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;

    new_node->next = *(head_ref);
    new_node->prev = NULL;

    if((*head_ref) != NULL)
        (*head_ref)->prev =new_node;

    *(head_ref) = new_node;

    return;
}

/* Given a node as prev_node, insert a new node after the
 * given node */
void insertAfter(struct Node* prev_node, int new_data){

    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    
    new_node->data = new_data;

    new_node->next = prev_node->next;

    new_node->next->prev = new_node;

    new_node->prev = prev_node;

    return;
}

/* Given a reference (pointer to pointer) to the head
   of a DLL and an int, appends a new node at the end  */
void append(struct Node** head_ref, int new_data){

    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = NULL;

    struct Node* temp = *head_ref;

    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = new_node;
    new_node->prev = temp;

    return;
}


// This function prints contents of linked list starting
// from the given node
void printList(struct Node* node){

    struct Node* temp;

    while(node != NULL){
        printf("%d->",node->data);
        temp = node;
        node = node->next;
    }

    //temp is used to traverse backwards
    while(temp != NULL){
        printf("%d->",temp->data);
        temp = temp->prev;
    }
    return;
}

struct Node* find(struct Node** head_ref, int key){

    struct Node* temp = *head_ref;

    while(temp->next != NULL){
        if(temp->next->data == key) return temp->next;
        temp = temp->next;
    }

}

/* Function to delete a node in a Doubly Linked List.
   head_ref --> pointer to head node pointer.
   del  -->  pointer to node to be deleted. */
void deleteNode(struct Node** head_ref, struct Node* del){


    if (*head_ref == NULL || del == NULL)
        return;
 
    if (*head_ref == del)
        *head_ref = del->next;
 
    /* Change next only if node to be deleted is NOT the last node */
    if (del->next != NULL)
        del->next->prev = del->prev;
 
    /* Change prev only if node to be deleted is NOT the first node */
    if (del->prev != NULL)
        del->prev->next = del->next;
 
    free(del);
    return;

}







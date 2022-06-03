#include <bits/stdc++.h>
using namespace std;
//단일 연결리스트
class Node {
public:
	int data;
	Node* next;
};
void push(Node** head_ref, int new_data)
{
    /* 1. allocate node */
    Node* new_node = new Node();
 
    /* 2. put in the data */
    new_node->data = new_data;
 
    /* 3. Make next of new node as head */
    new_node->next = (*head_ref);
 
    /* 4. move the head to point to the new node */
    (*head_ref) = new_node;
}
void insertAfter(Node* prev_node, int new_data)
{
 

    if (prev_node == NULL) {
        cout << "The given previous node cannot be NULL";
        return;
    }
 

    Node* new_node = new Node();
 

    new_node->data = new_data;

    new_node->next = prev_node->next;
 
 
    prev_node->next = new_node;
}
void append(Node** head_ref, int new_data) 
{ 
   
    // 1. allocate node
    Node* new_node = new Node();
   
    // Used in step 5
    Node *last = *head_ref;
   
    // 2. Put in the data
    new_node->data = new_data; 
   
    // 3. This new node is going to be 
    // the last node, so make next of 
    // it as NULL
    new_node->next = NULL; 
   
    // 4. If the Linked List is empty,
    // then make the new node as head
    if (*head_ref == NULL) 
    { 
        *head_ref = new_node; 
        return; 
    } 
   
    // 5. Else traverse till the last node
    while (last->next != NULL)
    {
        last = last->next; 
    }
   
    // 6. Change the next of last node
    last->next = new_node; 
    return; 
} 
void deleteNode(Node** head_ref, int key)
{
     
    // Store head node
    Node* temp = *head_ref;
    Node* prev = NULL;
     
    // If head node itself holds
    // the key to be deleted
    if (temp != NULL && temp->data == key)
    {
        *head_ref = temp->next; // Changed head
        delete temp;            // free old head
        return;
    }
 
    // Else Search for the key to be deleted,
    // keep track of the previous node as we
    // need to change 'prev->next' */
      else
    {
    while (temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }
 
    // If key was not present in linked list
    if (temp == NULL)
        return;
 
    // Unlink the node from linked list
    prev->next = temp->next;
 
    // Free memory
    delete temp;
    }
}
void printList(Node *node)
{
    while (node != NULL)
    {
        cout<<" "<<node->data;
        node = node->next;
    }
}

int main()
{
    /* Start with the empty list */
    Node* head = NULL;
     
    append(&head, 6);
    push(&head, 7);
    push(&head, 1);
    append(&head, 4);
    insertAfter(head->next, 8);
    //h->1->7->8->6->4
    cout<<"Created Linked list is: ";
    printList(head);
     
    return 0;
}
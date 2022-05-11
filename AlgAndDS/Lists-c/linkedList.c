#include <stdio.h>
#include <stdlib.h>


struct Node{
  int data;
  struct Node* next;
}Node;

struct Node* createNode(int data);// done

//add a index parameter to add at certain place
void insertNode(struct Node* HEAD, struct Node* newNode); //done

int deleteNode(struct Node* HEAD, int data); //done?

int deleteNode(struct Node* HEAD, int index); 
//void insertNode(struct Node* HEAD, struct Node* newNode, int index);

int main(){

  struct Node *Head = NULL;
  
  return 0;

}
struct Node* createNode(int data){
  struct Node* temp = malloc(sizeof(struct Node));
  temp->data = 0;
  temp->next = NULL;

  return temp;
}

void insertNode(struct Node* HEAD, struct Node* newNode){

  struct Node* temp = malloc(sizeof(struct Node));
  
  if(HEAD!=NULL){
    temp = HEAD;
  }
  while(temp->next != NULL){
    temp = temp->next;
  }
  temp->next = newNode;
  newNode->next = NULL;

  free(temp);
}

int deleteNode(struct Node* HEAD, int data){
  //struct Node* temp = malloc(sizeof(struct Node));
  //temp = HEAD;

  if(HEAD == NULL) return 1;
  struct Node* temp = HEAD;

    while(temp->next != NULL){
      if(temp->next->data == data){

        struct Node* rmv = temp;
        rmv->next = temp->next;
        rmv = rmv->next;
        
        rmv->data = 0;
        rmv->next = NULL;
        free(rmv);
        temp->next = temp->next->next;
        free(temp);
        return 0;//properly deleted
      }
      temp = temp->next;
    }
  return -1; // does not exist
}

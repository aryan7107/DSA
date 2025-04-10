#include<stdio.h>
#include<stdlib.h>

struct node{
  int data;
  struct node *next;
};

void linkedlisttraversal(struct node *ptr){
  while(ptr != NULL){
    printf("Element: %d\n", ptr->data);
    ptr = ptr->next;
  }
}

struct node* deletionatfirst(struct node *head){
  struct node *ptr = head;
  head = head->next;
  free(ptr);
  return head;
}

struct node* deletionatindex(struct node *head, int index){
  struct node *p = head;
  struct node *q = head->next;
  for(int i = 0; i < index-1; i++){
    p = p->next;
    q = q->next;
  }
  p->next = q->next;
  free(q);
  return head;
}

struct node* deletionatend(struct node *head){
  struct node *p = head;
  struct node *q = head->next;
  while(q->next != NULL){
    p = p->next;
    q = q->next;
  }
  p->next = NULL;
  free(q);
  return head;
}

struct node* deleteavalue(struct node *head, int value){
  struct node *p = head;
  struct node *q = head->next;
  while(q->data != value && q->next != NULL){
    p = p->next;
    q = q->next;
  }
  if(q->data == value){
    p->next = q->next;
    free(q);
  }
  return head;
}


int main(){
  struct node *head;
  struct node *second;
  struct node *third;

  head = (struct node*)malloc(sizeof(struct node));
  second = (struct node*)malloc(sizeof(struct node));
  third = (struct node*)malloc(sizeof(struct node));

  head->data = 1;
  head->next = second;
  second->data = 2;
  second->next = third;
  third->data = 3;
  third->next = NULL;
  printf("Linked List before Deletion:\n");
  linkedlisttraversal(head);
  printf("Linked List after Deletion:\n");
  //head = deletionatfirst(head);
  //head = deletionatindex(head, 2);
  //head = deletionatend(head);
  head = deleteavalue(head, 2);
  linkedlisttraversal(head);
  return 0;
}
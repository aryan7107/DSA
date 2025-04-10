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

struct node* insertatfirst(struct node *head, int data){
  struct node *ptr = (struct node*)malloc(sizeof(struct node));
  ptr->data = data;
  ptr->next = head;
  return ptr;
}

struct node* insertatindex(struct node *head, int data, int index){
  struct node *ptr = (struct node*)malloc(sizeof(struct node));
  struct node *p = head;
  int i = 0;
  while(i != index-1){
    p = p->next;
    i++;
  }
  ptr->data = data;
  ptr->next = p->next;
  p->next = ptr;
  return head;
}

struct node* insertatend(struct node *head, int data){
  struct node *ptr = (struct node*)malloc(sizeof(struct node));
  struct node *p = head;
  ptr->data = data;
  while(p->next != NULL){
    p = p->next;
  }
  p->next = ptr;
  ptr->next = NULL;
  return head;
}

struct node* insertafternode(struct node *head,struct node *prevnode, int data){
  struct node *ptr = (struct node*)malloc(sizeof(struct node));
  ptr->data = data;
  ptr->next = prevnode->next;
  prevnode->next = ptr;
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
  //linkedlisttraversal(head);
  //head=insertatfirst(head, 4);
  //head=insertatindex(head, 4, 2);
  //head=insertatend(head, 4);
  head=insertafternode(head, second, 4);
  linkedlisttraversal(head);
  return 0;
}
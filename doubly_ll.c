#include<stdio.h>
#include<stdlib.h>

struct node{
  int data;
  struct node *next;
  struct node *prev;
};

struct node* traversal(struct node *head){
  struct node *ptr = head;
  do{
    printf("Element: %d\n", ptr->data);
    ptr = ptr->next;
  }while(ptr != head);
  return head;
}
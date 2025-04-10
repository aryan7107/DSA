#include<stdio.h>
#include<stdlib.h>

struct node{
  int data;
  struct node *next;
};

struct node* traversal(struct node *head){
  struct node *ptr = head;
  do{
    printf("Element: %d\n", ptr->data);
    ptr = ptr->next;
  }while(ptr != head);
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
  third->next = head; // Making it circular
  traversal(head);
  return 0;
}
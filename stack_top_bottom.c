#include<stdio.h>
#include<stdlib.h>

struct stack {
    int size;
    int top;
    int *arr;
};

int isFull(struct stack *s) {
    if (s->top == s->size - 1) {
        return 1;
    }
    return 0;
}

int isEmpty(struct stack *s) {
    if (s->top == -1) {
        return 1;
    }
    return 0;
}

void push(struct stack *s, int val) {
  if (isFull(s)) {
      printf("Stack Overflow\nCannot push %d\n", val);
  } else {
      s->top++;
      s->arr[s->top] = val;
  }
}

int stack_top(struct stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return -1; // Return an invalid value
    } else {
        return s->arr[s->top];
    }
}

int stack_bottom(struct stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return -1; // Return an invalid value
    } else {
        return s->arr[0];
    }
}


int main(){
  struct stack *s= (struct stack*)malloc(sizeof(struct stack));
  s->size=10;
  s->top=-1;
  s->arr=(int*)malloc(s->size*sizeof(int));
  push(s, 10);
  printf("%d\n",isEmpty(s));
  printf("%d\n",isFull(s));
  push(s, 20);
  push(s, 30);  
  push(s, 40);

  stack_top(s); // Get the top element of the stack
  printf("Top element: %d\n", stack_top(s)); // Print the top element
  stack_bottom(s); // Get the bottom element of the stack
  printf("Bottom element: %d\n", stack_bottom(s)); // Print the bottom element




   free(s->arr); // Free the allocated memory for the array
   free(s); // Free the allocated memory for the stack structure
  return 0;
}
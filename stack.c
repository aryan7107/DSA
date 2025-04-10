#include<stdio.h>
#include<stdlib.h>

struct stack{
  int size;
  int top;
  int *arr;
};

int isFull(struct stack *s){
  if(s->top == s->size-1){
    return 1;
  }
  return 0;
}

int isEmpty(struct stack *s){
  if(s->top == -1){
    return 1;
  }
  return 0;
}

void push(struct stack *s, int val){
  if(isFull(s)){
    printf("Stack Overflow\n cannot push %d\n", val);
  } else {
    s->top++;
    s->arr[s->top] = val;
  }
}

int pop(struct stack *ptr){
  if(isEmpty(ptr)){
    printf("stack underflow \n cannot pop");
    return -1;
  }
  else{
    int val = ptr->arr[ptr->top];
    ptr->top--;
    return val;
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
}
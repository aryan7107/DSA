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

int peek(struct stack *s, int i) {
    int arrayInd = s->top - i + 1;
    if (arrayInd < 0) {
        printf("Not a valid position\n");
        return -1; // Return an invalid value
    } else {
        return s->arr[arrayInd];
    }
}

void push(struct stack *s, int val) {
    if (isFull(s)) {
        printf("Stack Overflow\nCannot push %d\n", val);
    } else {
        s->top++;
        s->arr[s->top] = val;
    }
}

int main() {
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 10;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));

    printf("%d\n", isEmpty(s));
    printf("%d\n", isFull(s));

    push(s, 10);
    push(s, 20);

    for (int j = 1; j <= s->top + 1; j++) {
        printf("The value at position %d is %d\n", j, peek(s, j));
    }

    // Free allocated memory
    free(s->arr);
    free(s);

    return 0;
}

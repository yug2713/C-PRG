#include <stdio.h>
#include <stdlib.h>

struct Stack {
    int* allStack;
    int* minStack;
    int top;
};

void initializeStack(struct Stack* st, int n) {
    st->top = -1;
    st->allStack = (int*)malloc(sizeof(int) * n);
    st->minStack = (int*)malloc(sizeof(int) * n);
}

int size(struct Stack* st) {
    return st->top + 1;
}

void push(struct Stack* st, int data) {
    st->top++;
    st->allStack[st->top] = data;
    if (st->top == 0 || data <= st->minStack[st->top - 1]) {
        st->minStack[st->top] = data;
    } else {
        st->minStack[st->top] = st->minStack[st->top - 1];
    }
}

int top(struct Stack* st) {
    if (st->top == -1) {
        return -1;
    }
    return st->allStack[st->top];
}

int pop(struct Stack* st) {
    if (st->top == -1) {
        return -1;
    }
    int val = st->allStack[st->top];
    st->top--;
    return val;
}

int getMin(struct Stack* st) {
    if (st->top == -1) {
        return -1;
    }
    return st->minStack[st->top];
}

void run(struct Stack* st) {
    int choice;
    printf("Menu:\n");
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Top\n");
    printf("4. Size\n");
    printf("5. Min Element\n");
    printf("6. Quit\n");

    do {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int val;
                printf("Enter value to push: ");
                scanf("%d", &val);
                push(st, val);
                break;
            }
            case 2: {
                int val = pop(st);
                if (val != -1) {
                    printf("Popped element: %d\n", val);
                } else {
                    printf("Stack is empty.\n");
                }
                break;
            }
            case 3: {
                int val = top(st);
                if (val != -1) {
                    printf("Top element: %d\n", val);
                } else {
                    printf("Stack is empty.\n");
                }
                break;
            }
            case 4:
                printf("Size of the stack: %d\n", size(st));
                break;
            case 5: {
                int minVal = getMin(st);
                if (minVal != -1) {
                    printf("Min element: %d\n", minVal);
                } else {
                    printf("Stack is empty.\n");
                }
                break;
            }
            case 6:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 6);
}

int main() {
    struct Stack st;
    initializeStack(&st, 100);
    run(&st);
    free(st.allStack);
    free(st.minStack);
    return 0;
}
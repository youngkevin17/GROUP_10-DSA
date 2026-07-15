#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct {
    char items[MAX];
    int top;
} Stack;

void initStack(Stack *s);
int isEmpty(Stack *s);
int isFull(Stack *s);
int push(Stack *s, char value);
int pop(Stack *s, char *value);
int peek(Stack *s, char *value);
int isBalanced(const char *expr);

int main(void)
{
    Stack s;
    char value;
    const char *test1 = "{[a+(b*c)]-d}";
    const char *test2 = "([a+b)]";

    initStack(&s);

    printf("Stack demo:\n");
    push(&s, 'A');
    push(&s, 'B');
    push(&s, 'C');
    peek(&s, &value);
    printf("Peek: %c\n", value);
    pop(&s, &value);
    printf("Popped: %c\n", value);
    peek(&s, &value);
    printf("Peek after pop: %c\n", value);

    printf("\nBalanced Brackets Checker:\n");
    printf("\"%s\" -> %s\n", test1, isBalanced(test1) ? "Balanced" : "Not Balanced");
    printf("\"%s\" -> %s\n", test2, isBalanced(test2) ? "Balanced" : "Not Balanced");

    return 0;
}

void initStack(Stack *s)
{
    s->top = -1;
}

int isEmpty(Stack *s)
{
    return s->top == -1;
}

int isFull(Stack *s)
{
    return s->top == MAX - 1;
}

/* Push: O(1) */
int push(Stack *s, char value)
{
    if (isFull(s)) {
        return 0;
    }
    s->top++;
    s->items[s->top] = value;
    return 1;
}

/* Pop: O(1) */
int pop(Stack *s, char *value)
{
    if (isEmpty(s)) {
        return 0;
    }
    *value = s->items[s->top];
    s->top--;
    return 1;
}

/* Peek: O(1) */
int peek(Stack *s, char *value)
{
    if (isEmpty(s)) {
        return 0;
    }
    *value = s->items[s->top];
    return 1;
}

/* Balanced check: O(n) - one pass, each char pushed/popped at most once */
int isBalanced(const char *expr)
{
    Stack s;
    int i;
    int len;
    char c;
    char top;

    initStack(&s);
    len = (int)strlen(expr);

    for (i = 0; i < len; i++) {
        c = expr[i];
        if (c == '(' || c == '[' || c == '{') {
            push(&s, c);
        } else if (c == ')' || c == ']' || c == '}') {
            if (!pop(&s, &top)) {
                return 0;
            }
            if ((c == ')' && top != '(') ||
                (c == ']' && top != '[') ||
                (c == '}' && top != '{')) {
                return 0;
            }
        }
    }
    return isEmpty(&s);
}

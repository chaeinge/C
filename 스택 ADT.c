#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define getnode() (Node*)malloc(sizeof(Node));

typedef struct Node {
	int data;
	struct Node* next;
} Node;

void push(Node** top)
{
	Node* newnode = getnode();

	int input;

	scanf("%d", &input);
	newnode->data = input;
	newnode->next = (*top);

	(*top) = newnode;
}

void pop(Node** top)
{
	Node* tmp = *top;

	if (top == NULL)
	{
		printf("Stack is empty!\n");
		return;
	}

	int ret = (*top)->data;

	(*top) = (*top)->next;

	free(tmp);

	printf("%d\n", ret);
}

void prt(Node* top)
{
	while (top != NULL)
	{
		printf("%d ", top->data);
		top = top->next;
	}
	printf("\n");
}

int main()
{
	Node* top = NULL;

	int n, i;
	char op[10];

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%s", op); getchar();

		if (strcmp(op, "push") == 0)
			push(&top);
		else if (strcmp(op, "pop") == 0)
			pop(&top);
		else if (strcmp(op, "prt") == 0)
			prt(top);
	}
}
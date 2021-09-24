#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define getnode() (Node*)malloc(sizeof(Node))

//큐 ADT

typedef struct Node
{
	int data;
	struct Node* next;
}Node;

void enqueue(Node** front, Node** rear)
{
	Node* newnode = getnode();

	int input;

	scanf("%d", &input);

	newnode->data = input;
	newnode->next = NULL;

	if ((*front) == NULL && (*rear) == NULL) // (*front)==NULL
	{
		(*front) = newnode;
		(*rear) = newnode;
	}
	else
	{
		(*rear)->next = newnode;
		(*rear) = newnode;
	}

}

int dequeue(Node** front, Node** rear)
{
	int output;

	if ((*front) == NULL)
	{
		printf("Queue is empty!\n");
		return 0;
	}

	output = (*front)->data;

	Node* tmp = *front;

	(*front) = (*front)->next;

	free(tmp);

	return output;
}

void prt(Node* front, Node* rear)
{

	while (front != NULL)
	{
		printf("%d ", front->data);
		front = front->next;
	}
	printf("\n");

}

int main()
{

	Node* front = NULL;
	Node* rear = NULL;

	int n, i;

	char op[100];

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%s", op); getchar();

		if (strcmp(op, "enq") == 0)
		{
			enqueue(&front, &rear);
		}
		else if (strcmp(op, "deq") == 0)
		{
			dequeue(&front, &rear);
		}
		else if (strcmp(op, "prt") == 0)
		{
			prt(front, rear); //front, rear의 교체가 이루어질 필요가 없으므로 들어간 주소만 넣어줘도 된다.
		}
	}


}
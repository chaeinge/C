#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define getnode() (Node*)malloc(sizeof(Node))


typedef struct Node {
	int data;
	struct Node* rlink;
	struct Node* llink;
} Node;

void add_front(Node** front, Node** rear)
{
	Node* newnode = getnode();

	scanf("%d", &(newnode->data));
	newnode->llink = NULL;
	newnode->rlink = (*front);

	if ((*front) == NULL) (*rear) = newnode;
	else (*front)->llink = newnode;

	(*front) = newnode;
}

void add_rear(Node * *front, Node * *rear)
{
	Node* newnode = getnode();

	scanf("%d", &(newnode->data));

	newnode->rlink = NULL;
	newnode->llink = (*rear);

	if ((*rear) == NULL) (*front) = newnode;
	else (*rear)->rlink = newnode;

	(*rear) = newnode;
}

void prt(Node * front)
{
	while (front != NULL)
	{
		printf(" %d", front->data);
		front = front->rlink;
	}
	printf("\n");
}

void delete_front(Node * *front, Node * *rear)
{
	if ((*front) == NULL)
	{
		printf("underflow\n");
		exit(1);
	}

	Node* tmp = *front;

	(*front) = (*front)->rlink;
	if ((*front) != NULL) (*front)->llink = NULL;

	free(tmp);

}

void delete_rear(Node * *front, Node * *rear)
{
	if (*rear == NULL)
	{
		printf("underflow\n");
		exit(1);
	}

	Node* tmp = *rear;

	(*rear) = (*rear)->llink;
	if ((*rear) != NULL) (*rear)->rlink = NULL;

	free(tmp);


}

int main()
{
	Node* front = NULL;
	Node* rear = NULL;

	int n, i;
	char op[10];

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%s", op); getchar();

		if (strcmp(op, "AF") == 0) add_front(&front, &rear);
		else if (strcmp(op, "AR") == 0) add_rear(&front, &rear);
		else if (strcmp(op, "DF") == 0) delete_front(&front, &rear);
		else if (strcmp(op, "DR") == 0) delete_rear(&front, &rear);
		else if (strcmp(op, "P") == 0) prt(front);
		else exit(1);
	}
}
#include <stdio.h>
#include <stdlib.h>
#define getNode() (Node*)malloc(sizeof(Node));

typedef struct Node {
	char data;
	struct Node* llink;
	struct Node* rlink;

}Node;

void Edge(char data, Node* curr, Node* left, Node* right)
{
	curr->data = data;
	curr->llink = left;
	curr->rlink = right;
}

void Preorder(Node* Node)
{
	if (Node != NULL)
	{
		printf("%c ", Node->data);
		Preorder(Node->llink);
		Preorder(Node->rlink);
	}
}

void Postorder(Node* Node)
{
	if (Node != NULL)
	{
		Postorder(Node->llink);
		Postorder(Node->rlink);
		printf("%c ", Node->data);
	}
}

void Inorder(Node* Node)
{
	if (Node != NULL)
	{
		Inorder(Node->llink);
		printf("%c ", Node->data);
		Inorder(Node->rlink);
	}
}

void main()
{

	Node* A, * B, * C, * D, * E, * F, * G, * H, * I, * J, * K, * L;

	A = getNode();
	B = getNode();
	C = getNode();
	D = getNode();
	E = getNode();
	F = getNode();
	G = getNode();
	H = getNode();
	I = getNode();
	J = getNode();
	K = getNode();
	L = getNode();

	Edge('A', A, B, C);
	Edge('B', B, D, F);
	Edge('C', C, G, H);
	Edge('D', D, E, NULL);
	Edge('E', E, NULL, NULL);
	Edge('F', F, I, NULL);
	Edge('G', G, NULL, NULL);
	Edge('H', H, NULL, NULL);
	Edge('I', I, K, L);
	Edge('J', J, NULL, NULL);
	Edge('K', K, NULL, NULL);
	Edge('L', L, NULL, NULL);

	printf("Preorder\n");
	Preorder(A);
	printf("\n");

	printf("Postorder\n");
	Postorder(A);
	printf("\n");

	printf("Inorder\n");
	Inorder(A);
	printf("\n");

}
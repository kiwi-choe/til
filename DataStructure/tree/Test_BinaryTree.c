#include "BinaryTree.h"

int main()
{
	Node* A = createNode('A');
	Node* B = createNode('B');
	Node* C = createNode('C');
	Node* D = createNode('D');
	Node* E = createNode('E');
	Node* F = createNode('F');
	Node* G = createNode('G');

	// append node to Tree
	A->Left = B;
	B->Left = C;
	B->Right = D;

	A->Right = E;
	E->Left = F;
	E->Right = G;

	// Print Tree
	printf("Preorder \n");
	preorderPrintTree(A);
	printf("--------Preorder \n");

	printf("Inorder \n");
	inorderPrintTree(A);
	printf("-----------Inorder \n");

	printf("Postorder \n");
	postorderPrintTree(A);
	printf("---------Postorder \n");
	
	destroyTree(A);

	return 0;
}
#include "ExpressionTree.h"

int main()
{
	Node* root = NULL;

	char postfixExpression[20] = "71*52-/";

	buildExpressionTree(postfixExpression, &root);
	
	postorderPrintTree(root);
	printf("\n");

	printf("Evaluation Result: %f \n", evaluate(root));

	destroyTree(root);
	
	return 0;
}
#include "ExpressionTree.h"

Node* createNode(ElementType newData)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->Left = NULL;
	newNode->Right = NULL;
	newNode->Data = newData;

	return newNode;
}

void destroyNode(Node* node)
{
	free(node);
}

void destroyTree(Node* root)
{
	if(root == NULL)
	{
		return;
	}

	destroyTree(root->Left);
	destroyTree(root->Right);
	destroyNode(root);
}

void postorderPrintTree(Node* node)
{
	if(node == NULL)
		return;

	postorderPrintTree(node->Left);
	postorderPrintTree(node->Right);
	printf(" %c", node->Data);
}

void buildExpressionTree(char* postfixExpression, Node** node)
{
	int len = strlen(postfixExpression);
	// initialize token to the last index data
	char token = postfixExpression[len-1];
	postfixExpression[len-1] = '\0';

	switch(token)
	{
		case '+': case '-': case '*': case '/':
			(*node) = createNode(token);
			buildExpressionTree(postfixExpression, &(*node)->Right);
			buildExpressionTree(postfixExpression, &(*node)->Left);
			break;

		default:
			(*node) = createNode(token);
			break;
	}
}

double evaluate(Node* tree)
{
	char temp[2];

	double left = 0;
	double right = 0;
	double result = 0;

	if(tree == NULL)
		return 0;

	switch(tree->Data)
	{
		case '+': case '-': case '*': case '/':
			left = evaluate(tree->Left);
			right = evaluate(tree->Right);

			if(tree->Data == '+')
				result = left + right;
			else if(tree->Data == '-')
				result = left - right;
			else if(tree->Data == '*')
				result = left * right;
			else if(tree->Data == '/') 
			{
				if(left == 0)
				{
					printf("cannot divide with 0 \n");
					return 0;
				}
				else 
					result = left / right;	
			}

			break;

		default:
			memset(temp, 0, sizeof(temp));
			temp[0] = tree->Data;
			result = atof(temp);
			break;
	}

	return result;
}
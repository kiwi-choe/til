#include "RedBlackTree.h"

// logical node; Nil
extern RBTNode* Nil;

void destroyTree(RBTNode* tree)
{
	if(tree->Right != Nil)
		destroyTree(tree->Right);
	if(tree->Left != NULL)
		destroyTree(tree->Left);

	tree->Left = Nil;
	tree->Right = Nil;

	destroyNode(tree);
}

RBTNode* createNode(ElementType newData)
{
	RBTNode* newNode = (RBTNode*)malloc(sizeof(RBTNode));
	newNode->Parent = NULL;
	newNode->Left = NULL;
	newNode->Right = NULL;
	newNode->Data = newData;
	newNode->Color = BLACK;

	return newNode;
}

void destroyNode(RBTNode* node)
{
	free(node);
}

RBTNode* searchNode(RBTNode* tree, ElementType target)
{
	if(tree == Nil)
		return NULL;

	if(tree->Data > target)
		return searchNode(tree->Left, target);
	else if(tree->Data < target)
		return searchNode(tree->Right, target);
	else
		return tree;
}

RBTNode* searchMinNode(RBTNode* tree)
{
	if(tree == Nil)
		return Nil;

	if(tree->Left == Nil)
		return tree;
	else
		return searchMinNode(tree->Left);
}

void insertNode(RBTNode** tree, RBTNode* newNode)
{
	insertNodeHelper(tree, newNode);

	newNode->Color = RED;
	newNode->Left = Nil;
	newNode->Right = Nil;

	rebuildAfterInsert(tree, newNode);
}

void insertNodeHelper(RBTNode** tree, RBTNode* newNode)
{
	if((*tree) == NULL)
		(*tree) = newNode;

	if((*tree)->Data < newNode->Data)
	{
		if((*tree)->Right == Nil)
		{
			(*tree)->Right = newNode;
			newNode->Parent = (*tree);
		}
		else
			insertNodeHelper(&(*tree)->Right, newNode);
	}
	else if((*tree)->Data > newNode->Data)
	{
		if((*tree)->Left == Nil)
		{
			(*tree)->Left = newNode;
			newNode->Parent = (*tree);
		}
		else
			insertNodeHelper(&(*tree)->Left, newNode);
	}
}

void rebuildAfterInsert(RBTNode** root, RBTNode* x)
{
	while(x != (*root) && x->Parent->Color == RED)
	{
		if(x->Parent == x->Parent->Parent->Left)
		{
			RBTNode* uncle = x->Parent->Parent->Right;
			if(uncle->Color == RED)
			{
				x->Parent->Color = BLACK;
				uncle->Color = BLACK;
				x->Parent->Parent->Color = RED;

				x = x->Parent->Parent;
			}
			else
			{
				if(x == x->Parent->Right)
				{
					x = x->Parent;
					rotateLeft(root, x);
				}
				x->Parent->Color = BLACK;
				x->Parent->Parent->Color = RED;

				rotateRight(root, x->Parent->Parent);
			}
		}
		else
		{
			RBTNode* uncle = x->Parent->Parent->Left;
			if(uncle->Color == RED)
			{
				x->Parent->Color = BLACK;
				uncle->Color = BLACK;
				x->Parent->Parent->Color = RED;

				x = x->Parent->Parent;
			}
			else
			{
				if(x == x->Parent->Left)
				{
					x = x->Parent;
					rotateRight(root, x);
				}

				x->Parent->Color = BLACK;
				x->Parent->Parent->Color = RED;
				rotateLeft(root, x->Parent->Parent);
			}
		}
	}
	(*root)->Color = BLACK;
}

RBTNode* removeNode(RBTNode** root, ElementType data)
{
	RBTNode* removed = NULL;
	RBTNode* successor = NULL;
	RBTNode* target = searchNode((*root), data);

	if(target == NULL)
		return NULL;

	if(target->Left == Nil || target->Right == Nil)
		removed = target;
	else
	{
		removed = searchMinNode(target->Right);
		target->Data = removed->Data;
	}

	if(removed->Left != Nil)
		successor = removed->Left;
	else
		successor = removed->Right;

	successor->Parent = removed->Parent;

	if(removed->Parent == NULL)
		(*root) = successor;
	else
	{
		if(removed == removed->Parent->Left)
			removed->Parent->Left = successor;
		else
			removed->Parent->Right = successor;
	}

	if(removed->Color == BLACK)
		rebuildAfterRemove(root, successor);

	return removed;
}

void rebuildAfterRemove(RBTNode** root, RBTNode* successor)
{
	RBTNode* sibling = NULL;

	while(successor->Parent != NULL && successor->Color == BLACK)
	{
		if(successor == successor->Parent->Left)
		{
			sibling = successor->Parent->Right;

			if(sibling->Color == RED)
			{
				sibling->Color = BLACK;
				successor->Parent->Color = RED;
				rotateLeft(root, successor->Parent);
			}
			else
			{
				if(sibling->Left->Color == BLACK &&
					sibling->Right->Color == BLACK)
				{
					sibling->Color = RED;
					successor = successor->Parent;
				}
				else
				{
					if(sibling->Left->Color == RED)
					{
						sibling->Left->Color = BLACK;
						sibling->Color = RED;

						rotateRight(root, sibling);
						sibling = successor->Parent->Right;
					}
					sibling->Color = successor->Parent->Color;
					successor->Parent->Color = BLACK;
					sibling->Right->Color = BLACK;
					rotateLeft(root, successor->Parent);
					successor = (*root);
				}
			}
		}
		else
		{
			sibling = successor->Parent->Left;

			if(sibling->Color == RED)
			{
				sibling->Color = BLACK;
				successor->Parent->Color = RED;
				rotateRight(root, successor->Parent);
			}
			else
			{
				if(sibling->Right->Color == BLACK &&
					sibling->Left->Color == BLACK)
				{
					sibling->Color = RED;
					successor = successor->Parent;
				}
				else
				{
					if(sibling->Right->Color == RED)
					{
						sibling->Right->Color = BLACK;
						sibling->Color = RED;

						rotateLeft(root, sibling);
						sibling = successor->Parent->Left;
					}
					sibling->Color = successor->Parent->Color;
					successor->Parent->Color = BLACK;
					sibling->Left->Color = BLACK;
					rotateRight(root, successor->Parent);
					successor = (*root);
				}
			}
		}
	}
	successor->Color = BLACK;
}

void printTree(RBTNode* node, int depth, int blackCount)
{
	int i =0;
	char c = 'X';
	int v = -1;
	char cnt[100];

	if(node == NULL || node == Nil)
		return;

	if(node->Color == BLACK)
		blackCount++;

	if(node->Parent != NULL)
	{
		v = node->Parent->Data;
		if(node->Parent->Left == node)
			c = 'L';
		else
			c = 'R';
	}

	if(node->Left == Nil && node->Right ==Nil)
		sprintf(cnt, "------- %d", blackCount);
	else
		sprintf(cnt, " ");

	for(i=0;i<depth;i++)
		printf("  ");

	printf("%d %s [%c, %d] %s\n", node->Data, (node->Color == RED)?"RED":"BLACK", c, v, cnt);

	printTree(node->Left, depth+1, blackCount);
	printTree(node->Right, depth+1, blackCount);
}

void rotateLeft(RBTNode** root, RBTNode* parent)
{
	RBTNode* rightChild = parent->Right;
	parent->Right = rightChild->Left;

	if(rightChild->Left != Nil)
		rightChild->Left->Parent = parent;
	
	rightChild->Parent = parent->Parent;

	if(parent->Parent == NULL)
		(*root) = rightChild;
	else
	{
		if(parent == parent->Parent->Left)
			parent->Parent->Left = rightChild;
		else
			parent->Parent->Right = rightChild;
	}

	rightChild->Left = parent;
	parent->Parent = rightChild;
}

void rotateRight(RBTNode** root, RBTNode* parent)
{
	RBTNode* leftChild = parent->Left;

	parent->Left = leftChild->Right;

	if(leftChild->Right != Nil)
		leftChild->Right->Parent = parent;
	leftChild->Parent = parent->Parent;

	if(parent->Parent == NULL)
		(*root) = leftChild;
	else
	{
		if(parent == parent->Parent->Left)
			parent->Parent->Left = leftChild;
		else
			parent->Parent->Right = leftChild;
	}

	leftChild->Right = parent;
	parent->Parent = leftChild;
}

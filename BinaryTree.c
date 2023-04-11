#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Queue.h"
typedef char BTDataType;
BTNode* BuyNode(BTDataType x)
{
	BTNode* node = (BTNode*)malloc(sizeof(BTNode));
	if (node == NULL)
	{
		perror("malloc error");
		return NULL;
	}

	node->data = x;
	node->left = NULL;
	node->right = NULL;

	return node;
}


BTNode* CreateTree()
{
	BTNode* node1 = BuyNode(1);
	BTNode* node2 = BuyNode(2);
	BTNode* node3 = BuyNode(3);
	BTNode* node4 = BuyNode(4);
	BTNode* node5 = BuyNode(5);
	BTNode* node6 = BuyNode(6);

	node1->left = node2;
	node1->right = node4;
	node2->left = node3;
	node4->left = node5;
	node4->right = node6;

	return node1;
}

void PreOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	printf("%d ", root->data);
	PreOrder(root->left);
	PreOrder(root->right);
}

void InOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	InOrder(root->left);
	printf("%d ", root->data);
	InOrder(root->right);
}

void PostOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	InOrder(root->left);
	InOrder(root->right);
	printf("%d ", root->data);
}

int TreeSize(BTNode* root)
{
	return root == NULL ? 0 : TreeSize(root->left)
		+ TreeSize(root->right) + 1;
}

int TreeHeight(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	int left = TreeHeight(root->left);
	int right = TreeHeight(root->right);
	return left > right ? left + 1 : right + 1;
}

int TreeKLevel(BTNode* root, int k)
{
	assert(k > 0);
	if (root == NULL)
	{
		return 0;
	}
	else if(k == 1)
	{
		return 1;
	}
	return TreeKLevel(root->left, k - 1) + TreeKLevel(root->right, k - 1);
}


//自己写的
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL)
	{
		return NULL;
	}
	if (root->data == x)
	{
		return root;
	}
	BTNode* left = BinaryTreeFind(root->left, x);
	if (left) { return left; }
	BTNode* right = BinaryTreeFind(root->right, x);
	if (right) { return right; }
	/*if (!left && !right)
	{
		return NULL;
	}
	if (left)return left;
	if (right)return right;*/

	
	return NULL;
}

BTNode* BinaryTreeCreate(BTDataType* a, int* pi)
{
	if (a[*pi] == '#')
	{
		(*pi)++;
		return NULL;
	}
	BTNode* root = (BTNode*)malloc(sizeof(BTNode));
	root->data = a[(*pi)++];
	root->left = BinaryTreeCreate(a,pi);
	root->right = BinaryTreeCreate(a,pi);
	return root;
}

//void BinaryTreeDestory(BTNode** root) //自己写的
//{
//	BTNode* rootleft = (*root)->left;
//	BTNode* rootright = (*root)->right;
//	free(*root);
//	*root = NULL;
//	if (rootleft != NULL)
//	{
//		BinaryTreeDestory(&rootleft);
//	}
//	if (rootright != NULL)
//	{
//		BinaryTreeDestory(&rootright);
//	}
//}

void BinaryTreeDestory(BTNode** root) //好处就是不要存储值了
{
	if (root == NULL)
		return;
	BinaryTreeDestory((*root)->left);
	BinaryTreeDestory((*root)->right);
	free(*root);
	*root = NULL;
}
void BinaryTreeLevelOrder(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	if (root)
	{
		QueuePush(&q, root);
	}
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		printf("%c ", front->data);

		if (front->left)
		{
			QueuePush(&q, front->left);
		}
		if (front->right)
		{
			QueuePush(&q, front->right);
		}
	}
	QueueDestory(&q);
}

//bool TreeComplete(BTNode* root) // 自己写的，个人感觉比老师讲的好点
//{
//	int flag = 0;
//	Queue q;
//	QueueInit(&q);
//	if (root)
//		QueuePush(&q, root);
//	while (!QueueEmpty(&q))
//	{
//		BTNode* front = QueueFront(&q);
//		QueuePop(&q);
//		if (front == NULL)
//		{
//			flag = 1;
//		}
//		if (flag == 1 && front != NULL)
//		{
//			QueueDestory(&q);
//			return false;
//		}
//		if (front != NULL)
//		{
//			QueuePush(&q, front->left);
//			QueuePush(&q, front->right);
//		}
//	}
//
//	QueueDestory(&q);
//	return true;
//}


bool TreeComplete(BTNode* root)
{
	int flag = 0;
	Queue q;
	QueueInit(&q);
	if (root)
		QueuePush(&q, root);
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		if (front == NULL)
		{
			break;
		}
		else
		{
			QueuePush(&q, front->left);
			QueuePush(&q, front->right);
		}
	}
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		if (front)
		{
			QueueDestory(&q);
			return false;
		}
	}
	QueueDestory(&q);
	return true;
}

int main()
{
	//BTNode* root = CreateTree();
	/*PreOrder(root);
	printf("\n");
	InOrder(root);
	printf("\n");
	PostOrder(root);*/

	/*int n = TreeKLevel(root, 3);
	printf("%d\n", n);

	int height = TreeHeight(root);
	printf("%d\n", height);

	int size = TreeSize(root);
	printf("%d\n", size);*/
	/*BTNode*Find = BinaryTreeFind(root, 3);
	printf("%d\n", Find->data);*/
	BTDataType a[] = { 'A', 'B', 'D','#', '#', 'E', '#', 'H', '#', '#'
		, 'C', 'F','#', '#', 'G','#', '#' };
	int i = 0;
	BTNode* root = BinaryTreeCreate(a, &i);
	BinaryTreeLevelOrder(root);
	printf("%d\n", TreeComplete(root));
	BinaryTreeDestory(&root);
	return 0;
}
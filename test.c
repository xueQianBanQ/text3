#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef int BTDataType;
typedef struct BinaryTreeNode
{
	BTDataType data;
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
}BTNode;

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

int main()
{
	BTNode* root = CreateTree();
	/*PreOrder(root);
	printf("\n");
	InOrder(root);
	printf("\n");
	PostOrder(root);*/

	int n = TreeKLevel(root, 3);
	printf("%d\n", n);

	int height = TreeHeight(root);
	printf("%d\n", height);

	int size = TreeSize(root);
	printf("%d\n", size);
	return 0;
}
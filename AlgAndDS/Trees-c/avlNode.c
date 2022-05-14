#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define min(a,b) (((a) < (b)) ? (a) : (b))
#define max(a,b) (((a) > (b)) ? (a) : (b))

struct avl_node{
	struct avl_node *left_child, *right_child;
	int data;
};

struct avl_node *root;



struct avl_node* avl_delete(struct avl_node *root, int new_key);
void display(struct avl_node *node);
struct avl_node* avl_add(struct avl_node **root, int new_key);
struct avl_node* rebalance(struct avl_node **node);
int get_height_diff(struct avl_node *node);
int get_height(struct avl_node *node);
struct avl_node* rotate_left_right(struct avl_node *parent);
struct avl_node* rotate_right_left(struct avl_node *parent);
struct avl_node* rotate_left(struct avl_node *parent);
struct avl_node* rotate_right(struct avl_node *parent);
struct avl_node* minValueNode(struct avl_node *node);
struct avl_node* avl_delete(struct avl_node *root, int key);

void main()
{
}

void display(struct avl_node *node)
{
	if(node!=NULL)
	{
		printf("(");
		display(node->left_child);
		printf("%d", node->data);
		display(node->right_child);
		printf(")");
	}
}

int get_height(struct avl_node *node)
{
	int height = 0;
	if(node!=NULL)
		height = 1+max(get_height(node->left_child), get_height(node->right_child));
	return height;
}

int get_height_diff(struct avl_node *node)
{
	int height_diff = 0;
	if(node == NULL)return 0;
	return get_height(node->left_child) - get_height(node->right_child);
}

struct avl_node* rotate_left(struct avl_node *parent)
{
	struct avl_node *child = parent->right_child;
	parent->right_child = child->left_child;
	child->left_child = parent;
	return child;
}

struct avl_node* rotate_right(struct avl_node *parent)
{
	struct avl_node *child = parent->left_child;
	parent->left_child = child->right_child;
	child->right_child = parent;
	return child;
}

struct avl_node* rotate_left_right(struct avl_node *parent)
{
	struct avl_node *child = parent->left_child;
	parent->left_child = rotate_left(child);
	return rotate_right(parent);
}

struct avl_node* rotate_right_left(struct avl_node *parent)
{
	struct avl_node *child = parent->right_child;
	parent->right_child = rotate_right(child);
	return rotate_left(parent);
}

struct avl_node* rebalance(struct avl_node **node)
{
	int height_diff = get_height_diff(*node);
	if(height_diff > 1)
	{
		if(get_height_diff((*node)->left_child) > 0)
			*node = rotate_right(*node);
		else
			*node = rotate_left_right(*node);
	}

	else if(height_diff < -1)
	{
		if(get_height_diff((*node)->right_child) < 0)
			*node = rotate_left(*node);
		else
			*node = rotate_right_left(*node);
	}
	return *node;
}

struct avl_node* avl_add(struct avl_node **root, int new_key)
{
	if(*root == NULL)
	{
		*root = (struct avl_node*)malloc(sizeof(struct avl_node));
		if(*root == NULL)
			exit(1);
		(*root)->data = new_key;
		(*root)->left_child = (*root)->right_child = NULL;
	}
	else if(new_key < (*root)->data)
	{
		(*root)->left_child = avl_add(&(*root)->left_child, new_key);
		*root = rebalance(root);
	}
	else if(new_key > (*root)->data)
	{
		(*root)->right_child = avl_add(&(*root)->right_child, new_key);
			*root = rebalance(root);
	}
	else
	{
		exit(1);
	}
	return *root;
}

struct avl_node* minValueNode(struct avl_node* node)
{
	struct avl_node* current = node;

	while(current->left_child != NULL)
		current = current->left_child;
	return current;
}

struct avl_node* avl_delete(struct avl_node *root, int key)
{
	if(root == NULL)
		return root;

	if(key < root->data)
		root->left_child = avl_delete(root->left_child, key);

	else if(key > root->data)
		root->right_child = avl_delete(root->right_child, key);

	else
	{
		if(root->left_child == NULL || (root->right_child == NULL))
		{
			struct avl_node *temp = root->left_child ? root->left_child : root->right_child;
			if(temp == NULL)
			{
				temp = root;
				root = NULL;
			}
			else
				*root = *temp;
			free(temp);
		}
		else
		{
			struct avl_node *temp = minValueNode(root->right_child);
			root->data = temp->data;
			root->right_child = avl_delete(root->right_child, temp->data);
		}

		if(root == NULL)
			return root;

		root = rebalance(&root);
	}
	return root;
}




			
#include <stdlib.h>
#include <stdbool.h>
#include "HUFFMAN.h"

float get_node_payload(TNode* node)
{
	float tmp_payload;
	tmp_payload = node->payload;
	return tmp_payload;
};

char get_node_symbol(TNode* node)
{
	char tmp_symbol;
	tmp_symbol = node->symbol;
	return tmp_symbol;
};

TNode* init_node(float payload, char symbol)
{
	TNode* n = NULL;
	n = (TNode*)malloc(sizeof(TNode));

	if (n != NULL)
	{
		/*may be need some if-else for null payload or symbol */
		n->payload = payload;
		n->symbol = symbol;
		n->left_child = NULL;
		n->right_child = NULL;
	}
	else
	{
		free(n);
		n = NULL;
	}
	return n;
};

void add_child(TNode* node, TNode* child)
{
	if (node->left_child == NULL)
		node->left_child = child;
	else
	{
		float tmp_node_payload = get_node_payload(node->left_child);
		if (tmp_node_payload <= child->payload)
			node->right_child = child;
		else
		{
			node->right_child = node->left_child;
			node->left_child = child;
		}
	}
	node->payload += child->payload;
};

bool is_node_leaf(TNode* node)
{
	return (node->left_child == NULL) && (node->right_child == NULL);
};

TBinaryTree* init_binary_tree(TNode* root)
{
	/*some code*/
};
/*
TNode* get_left_child(TNode* node)
{

};

TNode* get_right_child(TNode* node)
{

};
*/
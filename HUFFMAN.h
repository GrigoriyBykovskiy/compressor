#ifndef __HUFFMAN_H__
#define __HUFFMAN_H__

typedef struct {
	float payload;//probability
	char symbol;
	struct TNode* left_child;
	struct TNode* right_child;
} TNode;
typedef struct {
	TNode* root;
} TBinaryTree;

TBinaryTree* init_binary_tree(TNode* root);

/*
float get_tree_payload(TBinaryTree* tree);
TNode get_tree_root(TBinaryTree* tree);
*/

TNode* init_node(float payload, char symbol);

/*
TNode* get_left_child(TNode* node);
TNode* get_right_child(TNode* node);
*/

bool is_node_leaf(TNode* node);
float get_node_payload(TNode *node);
char get_node_symbol(TNode* node);
void add_child(TNode* node, TNode* child);

#endif
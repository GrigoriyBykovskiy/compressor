#ifndef __HUFFMAN_H__
#define __HUFFMAN_H__

typedef struct {
    float payload;//probability
    char symbol;
    struct TNode* left_child;
    struct TNode* right_child;
} TNode;

TNode* init_node(float payload, char symbol);
void add_child(TNode* node, TNode* child);
float get_node_payload(TNode *node);
char get_node_symbol(TNode* node);
bool is_node_leaf(TNode* node);

typedef struct {
    TNode* root;
} TBinaryTree;

TBinaryTree* init_binary_tree(TNode* root);
float get_tree_payload(TBinaryTree* tree);

typedef struct {
    TBinaryTree **data;
    unsigned data_count;
} TPriorityQueue;

TPriorityQueue* init_queue();
void add_queue_element();
void remove_queue_element();

#endif

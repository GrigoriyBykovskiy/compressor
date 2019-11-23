#ifndef __HUFFMAN_H__
#define __HUFFMAN_H__

#include <stdbool.h>

typedef struct {
	char symbol;
	unsigned payload;
} TSymbol;

TSymbol* init_tsymbol(void);
void set_tsymbol_symbol(TSymbol* tsymbol, char symbol);
void set_tsymbol_payload(TSymbol* tsymbol, unsigned payload);
char get_tsymbol_symbol(TSymbol* tsymbol);
unsigned get_tsymbol_payload(TSymbol* tsymbol);

typedef struct {
	TSymbol** array_of_tsymbols;
	unsigned tsymbols_count;
} TFile;

TFile* init_tfile(void);
void add_tfile_tsymbol(TFile* tfile, TSymbol* tsymbol);
bool is_tfile_tsymbol_symbol_exist(TFile* tfile, char symbol);


typedef struct {
    char symbol;
	unsigned payload;
    struct TNode* left_child;
    struct TNode* right_child;
} TNode;

TNode* init_tnode(void);
void set_tnode_symbol(TNode* tnode, char symbol);
void set_tnode_payload(TNode* tnode, unsigned payload);
void set_tnode_child(TNode* node, TNode* child);
char get_tnode_symbol(TNode* tnode);
unsigned get_tnode_payload(TNode* tnode);
TNode* get_node_left_child(TNode* tnode);
TNode* get_node_right_child(TNode* tnode);
bool is_tnode_leaf(TNode* node);

typedef struct {
    TNode* root;
} TBinaryTree;

TBinaryTree* init_tree(void);
void set_tbinarytree_tnode_root(TBinaryTree* tbinarytree, TNode* tnode);
unsigned get_tbinarytree_payload(TBinaryTree* tbinarytree);

typedef struct {
    TBinaryTree **data;
    unsigned data_count;
} TPriorityQueue;

TPriorityQueue* init_queue();
void add_tpriorityqueue_tbinarytree(TPriorityQueue* tpriorityqueue, TBinaryTree* tbinarytree);
void remove_tpriorityqueue_tbinarytree(TPriorityQueue* tpriorityqueue, TBinaryTree* tbinarytree);

#endif

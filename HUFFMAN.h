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
    TSymbol* root;
	char code[256];
	struct TBinaryTree* left_tbinarytree;
	struct TBinaryTree* right_tbinarytree;
} TBinaryTree;

TBinaryTree* init_tbinarytree(void);
//void set_tbinarytree_tnode_root(TBinaryTree* tbinarytree, TNode* tnode);
unsigned get_tbinarytree_payload(TBinaryTree* tbinarytree);
//TBinaryTree* merge_tbinarytrees(TBinaryTree* tbinarytree_1, TBinaryTree* tbinarytree_2);
int cmp_tbinarytrees(const void* a, const void* b);

typedef struct {
    TBinaryTree **data;
    unsigned data_count;
} TPriorityQueue;

TPriorityQueue* init_queue(void);
void add_tpriorityqueue_tbinarytree(TPriorityQueue* tpriorityqueue, TBinaryTree* tbinarytree);

TBinaryTree* create_huffman_tree(TPriorityQueue* tpriorityqueue, unsigned count);


#endif

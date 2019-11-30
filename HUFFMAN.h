#ifndef COMPRESSOR_TMP_HUFFMAN_H
#define COMPRESSOR_TMP_HUFFMAN_H
#include <stdbool.h>

typedef struct {
    char symbol;
    unsigned payload;
    char code[256];
} TSymbol;

TSymbol* init_tsymbol(void);
void set_tsymbol_symbol(TSymbol* tsymbol, char symbol);
void set_tsymbol_payload(TSymbol* tsymbol, unsigned payload);
char get_tsymbol_symbol(TSymbol* tsymbol);
unsigned get_tsymbol_payload(TSymbol* tsymbol);
int cmp_tsymbols(const void* a, const void* b);

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
unsigned get_tbinarytree_payload(TBinaryTree* tbinarytree);
int cmp_tbinarytrees(const void* a, const void* b);

typedef struct {
    TBinaryTree **data;
    unsigned data_count;
} TPriorityQueue;

TPriorityQueue* init_queue(void);
void add_tpriorityqueue_tbinarytree(TPriorityQueue* tpriorityqueue, TBinaryTree* tbinarytree);

TBinaryTree* create_huffman_tree(TPriorityQueue* tpriorityqueue, unsigned count);
void get_codes(TBinaryTree* tbinarytree);

#endif //COMPRESSOR_TMP_HUFFMAN_H

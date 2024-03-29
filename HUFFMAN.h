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
void print_tsymbol_data(TSymbol* tsymbol);

typedef struct {
    TSymbol** array_of_tsymbols;
    unsigned tsymbols_count;
} TFile;

TFile* init_tfile(void);
void add_tfile_tsymbol(TFile* tfile, TSymbol* tsymbol);
bool is_tfile_tsymbol_symbol_exist(TFile* tfile, char symbol);
int find_tfile_tsymbol(TFile* tfile, char symbol);
void print_tfile_data(TFile* tfile);

typedef struct {
    TSymbol* root;
    char code[256];
    struct TBinaryTree* left_tbinarytree;
    struct TBinaryTree* right_tbinarytree;
} TBinaryTree;

TBinaryTree* init_tbinarytree(void);
unsigned get_tbinarytree_payload(TBinaryTree* tbinarytree);
int cmp_tbinarytrees(const void* a, const void* b);
void print_tbinarytree_data(TBinaryTree* tbinarytree);

typedef struct {
    TBinaryTree **data;
    unsigned data_count;
} TPriorityQueue;

TPriorityQueue* init_queue(void);
void add_tpriorityqueue_tbinarytree(TPriorityQueue* tpriorityqueue, TBinaryTree* tbinarytree);
void print_tpriorityqueue_data(TPriorityQueue* tpriorityqueue);

TBinaryTree* create_huffman_tree(TPriorityQueue* tpriorityqueue, unsigned count);
void get_codes(TBinaryTree* tbinarytree);
void add_tsymbol_additional_code(TFile* tfile);
void delete_tsymbol_additional_code(TFile* tfile);
char unsigned_to_char(unsigned* a);

#endif //COMPRESSOR_TMP_HUFFMAN_H

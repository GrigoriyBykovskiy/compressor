#define _CRT_SECURE_NO_WARNINGS

#include "HUFFMAN.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

TSymbol* init_tsymbol(void)
{
    TSymbol* s = NULL;
    s = (TSymbol*)malloc(sizeof(TSymbol));

    if (s != NULL)
    {
        s->symbol = NULL;
        s->payload = 0;
        s->code[0] = 0;
    }
    else
    {
        free(s);
        s = NULL;
    }
    return s;
};

void set_tsymbol_symbol(TSymbol* tsymbol, char symbol)
{
    tsymbol->symbol = symbol;
};

void set_tsymbol_payload(TSymbol* tsymbol, unsigned payload)
{
    tsymbol->payload = payload;
};

char get_tsymbol_symbol(TSymbol* tsymbol)
{
    char tmp;
    tmp = tsymbol->symbol;
    return tmp;
};

unsigned get_tsymbol_payload(TSymbol* tsymbol)
{
    unsigned tmp;
    tmp = tsymbol->payload;
    return tmp;
};

int cmp_tsymbols(const void* a, const void* b)//fuck, it is dirty magic, i dont know how it work!
{
    TSymbol** tmp_pointer_s_a = a, ** tmp_pointer_s_b = b;
    TSymbol* tmp_tsymbol_a = *tmp_pointer_s_a, * tmp_tsymbol_b = *tmp_pointer_s_b;
    unsigned tmp_payload_a = tmp_tsymbol_a->payload;
    unsigned tmp_payload1_b = tmp_tsymbol_b->payload;
    int result = tmp_payload_a - tmp_payload1_b;
    return (-1)*result;
};

void print_tsymbol_data(TSymbol* tsymbol)
{
    printf(stdout, "\nCode of symbol is %3d;                 Payload is %3d;\n", tsymbol->symbol, tsymbol->payload);
    printf(stdout, "\n%s\n", tsymbol->code);
};

TFile* init_tfile(void)
{
    TFile* f = NULL;
    f = (TFile*)malloc(sizeof(TFile));

    if (f != NULL)
    {
        f->array_of_tsymbols = NULL;
        f->tsymbols_count = 0;
    }
    else
    {
        free(f);
        f = NULL;
    }
    return f;
};

void add_tfile_tsymbol(TFile* tfile, TSymbol* tsymbol)
{

    TSymbol** new_array_of_tsymbols;

    new_array_of_tsymbols = (TSymbol**)realloc(tfile->array_of_tsymbols,(tfile->tsymbols_count + 1) * sizeof(TSymbol*));

    if (new_array_of_tsymbols != NULL)
    {
        tfile->array_of_tsymbols = new_array_of_tsymbols;
        tfile->array_of_tsymbols[tfile->tsymbols_count] = tsymbol;
        tfile->tsymbols_count += 1;
    }
    else
        printf(stderr, "Out of memory!\n");
};

void print_tfile_data(TFile* tfile)
{
    printf(stdout, "\n====================TFILE_____DATA====================\n");
    for (int i = 0; i < tfile->tsymbols_count; i++)
        print_tsymbol_data(tfile->array_of_tsymbols[i]);
    printf(stdout, "\n======================================================\n");
};

bool is_tfile_tsymbol_symbol_exist(TFile* tfile, char symbol)//if true then increment payload
{
    for (int i = 0; i < tfile->tsymbols_count; i++)
    {
        char tmp_symbol = get_tsymbol_symbol(tfile->array_of_tsymbols[i]);

        if (tmp_symbol == symbol)
        {
            unsigned tmp_payload = get_tsymbol_payload(tfile->array_of_tsymbols[i]);
            tmp_payload++;
            set_tsymbol_payload(tfile->array_of_tsymbols[i], tmp_payload);
            return 1;
        }
    }
    return 0;
};

int find_tfile_tsymbol(TFile* tfile, char symbol)
{
    for (int i = 0; i < (tfile->tsymbols_count); i++)
    {
        char tmp_symbol = get_tsymbol_symbol(tfile->array_of_tsymbols[i]);

        if (tmp_symbol == symbol)
        {
            return i;
        }
    }

    return -1;
};

TBinaryTree* init_tbinarytree(void)
{
    TBinaryTree* t = (TBinaryTree*)malloc(sizeof(TBinaryTree));

    if (t != NULL)
    {
        t->root = NULL;
        t->code[0] = 0;
        t->left_tbinarytree = NULL;
        t->right_tbinarytree = NULL;
    }
    else
    {
        printf(stderr, "Out of memory!\n");
        free(t);
        t = NULL;
    }
    return t;
};

unsigned get_tbinarytree_payload(TBinaryTree* tbinarytree)
{
    unsigned tmp_payload;
    tmp_payload = get_tsymbol_payload(tbinarytree->root);
    return tmp_payload;
};

bool is_leaf(TBinaryTree* tbinarytree)
{
    return (tbinarytree->left_tbinarytree == NULL) && (tbinarytree->right_tbinarytree == NULL);
};

/*TBinaryTree* merge_tbinarytrees(TBinaryTree* tbinarytree_left, TBinaryTree* tbinarytree_right)
{
	TBinaryTree* new_tree = init_tbinarytree();

	if (new_tree != NULL)
	{
		set_tnode_child(new_tree->root, tbinarytree_left->root);
		set_tnode_child(new_tree->root, tbinarytree_right->root);
		return new_tree;
	}
};*/

int cmp_tbinarytrees(const void* a, const void* b)//fuck, it is dirty magic, i dont know how it work!
{
    TBinaryTree** tmp_pointer_t_a = a, ** tmp_pointer_t_b = b;
    TBinaryTree* tmp_tree_a = *tmp_pointer_t_a, * tmp_tree_b = *tmp_pointer_t_b;
    unsigned tmp_payload_a = tmp_tree_a->root->payload;
    unsigned tmp_payload1_b = tmp_tree_b->root->payload;
    int result = tmp_payload_a - tmp_payload1_b;
    return (-1)*result;
};

void print_tbinarytree_data(TBinaryTree* tbinarytree)
{
    printf(stdout, "\n====================TTREE____DATA====================\n");
    print_tsymbol_data(tbinarytree->root);
    printf(stdout, "\n%s\n", tbinarytree->code);
    printf(stdout, "\n======================================================\n");
};
TPriorityQueue* init_queue(void)
{
    TPriorityQueue* q = NULL;
    q = (TPriorityQueue*)malloc(sizeof(TPriorityQueue));

    if (q != NULL)
    {
        q->data = NULL;
        q->data_count = 0;
    }
    else
    {
        printf(stderr, "Out of memory!\n");
        free(q);
        q = NULL;
    }
    return q;
};

void add_tpriorityqueue_tbinarytree(TPriorityQueue* tpriorityqueue, TBinaryTree* tbinarytree)// add in the end
{
    TBinaryTree** new_data;

    new_data = (TBinaryTree**)realloc(tpriorityqueue->data, (tpriorityqueue->data_count + 1) * sizeof(TBinaryTree*));

    if (new_data != NULL)
    {
        tpriorityqueue->data = new_data;
        tpriorityqueue->data[tpriorityqueue->data_count] = tbinarytree;
        tpriorityqueue->data_count += 1;

    }
    else
        printf(stderr, "Out of memory!\n");
};

void print_tpriorityqueue_data(TPriorityQueue* tpriorityqueue)
{
    printf(stdout, "\n====================TQUEUE____DATA====================\n");
    for (int i = 0; i < tpriorityqueue->data_count; i++)
        print_tbinarytree_data(tpriorityqueue->data[i]);
    printf(stdout, "\n======================================================\n");
};

TBinaryTree* create_huffman_tree(TPriorityQueue* tpriorityqueue, unsigned count)
{
    TBinaryTree* tmp_tree = init_tbinarytree();
    TSymbol* tmp_root = init_tsymbol();
    unsigned tmp_payload = get_tbinarytree_payload(tpriorityqueue->data[count - 2]) + get_tbinarytree_payload(tpriorityqueue->data[count - 1]);
    set_tsymbol_payload(tmp_root, tmp_payload);
    tmp_tree->root = tmp_root;
    tmp_tree->left_tbinarytree = tpriorityqueue->data[count - 1];
    tmp_tree->right_tbinarytree = tpriorityqueue->data[count - 2];

    if (count == 2)
        return tmp_tree;
    else
    {
        add_tpriorityqueue_tbinarytree(tpriorityqueue, tmp_tree);
        qsort(tpriorityqueue->data, tpriorityqueue->data_count, sizeof(TBinaryTree*), cmp_tbinarytrees);
        create_huffman_tree(tpriorityqueue, count - 1);
    }
};

void get_codes(TBinaryTree* tbinarytree)
{
    if (tbinarytree->left_tbinarytree)
    {
        TBinaryTree* tmp_l = tbinarytree->left_tbinarytree;
        strcpy(tmp_l->code, tbinarytree->code);
        strcat(tmp_l->code, "0");
        get_codes(tmp_l);
    }
    if (tbinarytree->right_tbinarytree)
    {
        TBinaryTree* tmp = tbinarytree->right_tbinarytree;
        strcpy(tmp->code, tbinarytree->code);
        strcat(tmp->code, "1");
        get_codes(tmp);
    }
};

void add_tsymbol_additional_code(TFile* tfile)
{
    for (int count_of_tsymbols = 0; count_of_tsymbols < (tfile->tsymbols_count); count_of_tsymbols++)
    {
        TSymbol* tmp = tfile->array_of_tsymbols[count_of_tsymbols];
        strcat(tmp->code, "1");
        while (strlen(tmp->code)%8 != 0 )
            strcat(tmp->code, "0");
    }
};

void delete_tsymbol_additional_code(TFile* tfile)
{
    for (int count_of_tsymbols = 0; count_of_tsymbols < (tfile->tsymbols_count); count_of_tsymbols++)
    {
        TSymbol* tmp = tfile->array_of_tsymbols[count_of_tsymbols];
        for (int i = strlen(tmp->code) - 1; i >= 0; i--)
        {
            if (tmp->code[i] == '0') {
                tmp->code[i] = 0;
            }
            if (tmp->code[i] == '1'){
                tmp->code[i] = 0;
                break;
            }
        }
    }
};

char unsigned_to_char(unsigned* a)
{
    char tmp = 0;
    for (int i = 0; i < 8; i++)
    {
        if ((*a & (1 << i)) == 0)
            tmp &= ~(1 << i);
        else
            tmp |= (1 << i);
    }
    return tmp;
};
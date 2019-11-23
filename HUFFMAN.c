#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "HUFFMAN.h"

TSymbol* init_tsymbol(void)
{
	TSymbol* s = NULL;
	s = (TSymbol*)malloc(sizeof(TSymbol));

	if (s != NULL)
	{
		s->symbol = NULL;
		s->payload = 0;
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

	new_array_of_tsymbols = (TSymbol**)realloc(tfile->array_of_tsymbols,(tfile->tsymbols_count + 1) * sizeof(unsigned));

	if (new_array_of_tsymbols != NULL)
	{
		tfile->array_of_tsymbols = new_array_of_tsymbols;
		tfile->array_of_tsymbols[tfile->tsymbols_count] = tsymbol;
		tfile->tsymbols_count += 1;
	}
	else
		printf("Out of memory!\n");
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

TNode* init_tnode(void)
{
	TNode* n = NULL;
	n = (TNode*)malloc(sizeof(TNode));

	if (n != NULL)
	{
		n->symbol = NULL;
		n->payload = 0;
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

void set_tnode_symbol(TNode* tnode, char symbol)
{
	tnode->symbol = symbol;
};

void set_tnode_payload(TNode* tnode, unsigned payload)
{
	tnode->payload = payload;
};

void set_tnode_child(TNode* tnode, TNode* tnode_child)
{
	if (tnode->left_child == NULL)
		tnode->left_child = tnode_child;
	else
	{
		unsigned tmp_tnode_payload = get_tnode_payload(tnode->left_child);
		if (tmp_tnode_payload <= tnode_child->payload)
			tnode->right_child = tnode_child;
		else
		{
			tnode->right_child = tnode->left_child;
			tnode->left_child = tnode_child;
		}
	}
	tnode->payload += tnode_child->payload;
};

char get_tnode_symbol(TNode* tnode)
{
	char tmp;
	tmp = tnode->symbol;
	return tmp;
};

unsigned get_tnode_payload(TNode* tnode)
{
	unsigned tmp;
	tmp = tnode->payload;
	return tmp;
};

TNode* get_tnode_left_child(TNode* tnode)
{
	return tnode->left_child;
};

TNode* get_tnode_right_child(TNode* tnode)
{
	return tnode->right_child;
};

bool is_tnode_leaf(TNode* tnode)
{
	return (tnode->left_child == NULL) && (tnode->right_child == NULL);
};


TBinaryTree* init_tree(void)
{
    TBinaryTree* t = NULL;
    t = (TBinaryTree*)malloc(sizeof(TBinaryTree));

    if (t != NULL)
    {
        t->root = NULL;
    }
    else
    {
        free(t);
        t = NULL;
    }
    return t;
};

void set_tbinarytree_tnode_root(TBinaryTree* tbinarytree, TNode* tnode)
{
	tbinarytree->root = tnode;
};

unsigned get_tbinarytree_payload(TBinaryTree* tbinarytree)
{
	unsigned tmp_payload;
	tmp_payload = get_tnode_payload(tbinarytree->root);
	return tmp_payload;
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
        free(q);
        q = NULL;
    }
    return q;
};

void add_tpriorityqueue_tbinarytree(TPriorityQueue* tpriorityqueue, TBinaryTree* tbinarytree)
{
	TBinaryTree** new_data;

	new_data = (TBinaryTree**)realloc(tpriorityqueue->data, (tpriorityqueue->data_count + 1) * sizeof(unsigned));

	if (new_data != NULL)
	{
		tpriorityqueue->data = new_data;
		tpriorityqueue->data[tpriorityqueue->data_count] = tbinarytree;
		tpriorityqueue->data_count += 1;
	}
	else
		printf("Out of memory!\n");
};

void remove_tpriorityqueue_tbinarytree(TPriorityQueue* tpriorityqueue, TBinaryTree* tbinarytree)
{
	for (int i = 0; i < tpriorityqueue->data_count; i++)
	{

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


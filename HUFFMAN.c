#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
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
/*
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
		printf("Out of memory!\n");
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
	TNode* tnode_tmp = init_tnode();
	set_tnode_symbol(tnode_tmp, tnode->symbol);
	set_tnode_payload(tnode_tmp, tnode->payload);
	return tnode_tmp;
};

TNode* get_tnode_right_child(TNode* tnode)
{
	TNode* tnode_tmp = init_tnode();
	set_tnode_symbol(tnode_tmp, tnode->symbol);
	set_tnode_payload(tnode_tmp, tnode->payload);
	return tnode_tmp;
};

void free_tnode(TNode* tnode)
{
	if (tnode->left_child != NULL)
		free_tnode(tnode->left_child);

	if (tnode->right_child != NULL)
		free_tnode(tnode->right_child);

	free(tnode);
}

bool is_tnode_leaf(TNode* tnode)
{
	return (tnode->left_child == NULL) && (tnode->right_child == NULL);
};
*/
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
		printf("Out of memory!\n");
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
		printf("Out of memory!\n");
        free(q);
        q = NULL;
    }
    return q;
};

void add_tpriorityqueue_tbinarytree(TPriorityQueue* tpriorityqueue, TBinaryTree* tbinarytree)// add in the end
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

void fillEncodingArray(TBinaryTree* tbinarytree) 
{//заполнить кодировочную таблицу
	if (tbinarytree->left_tbinarytree) {
		if (is_leaf(tbinarytree)) printf("LEAF!\n");
		TBinaryTree* tmp = tbinarytree->left_tbinarytree;
		strcpy(tmp->code, tbinarytree->code);
		strcat(tmp->code, "0");
		fillEncodingArray(tbinarytree->left_tbinarytree);
	}
	if (tbinarytree->right_tbinarytree) {
		if (is_leaf(tbinarytree)) printf("LEAF!\n");
		TBinaryTree* tmp = tbinarytree->right_tbinarytree;
		strcpy(tmp->code, tbinarytree->code);
		strcat(tmp->code, "1");
		fillEncodingArray(tbinarytree->right_tbinarytree);
	}
}
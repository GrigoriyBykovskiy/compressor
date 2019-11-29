// HuffmanCode.c Define the entry point of program
//

#define _CRT_SECURE_NO_WARNINGS
#define FILENAME "/home/grigoriy/projects/compressor_tmp/8.tex"
#include <stdio.h>
#include <stdlib.h>
#include "HUFFMAN.h"


int main()
{
    FILE* input_text = NULL;
    TFile* tfile = init_tfile();

    if (((input_text = fopen(FILENAME, "r")) != NULL) && (tfile != NULL)) {
        char symbol;
        unsigned count = 0;

        do {
            count++;
            symbol = fgetc(input_text);

            if (!is_tfile_tsymbol_symbol_exist(tfile, symbol)) {
                TSymbol *tmp_tsymbol = init_tsymbol();
                set_tsymbol_symbol(tmp_tsymbol, symbol);
                set_tsymbol_payload(tmp_tsymbol, 1);
                add_tfile_tsymbol(tfile, tmp_tsymbol);
            }

        } while (symbol != EOF);

        TPriorityQueue *queue = init_queue();

        for (int i = 0; i < tfile->tsymbols_count; i++) {
            TBinaryTree *tmp_tree = init_tbinarytree();
            tmp_tree->root = tfile->array_of_tsymbols[i];
            add_tpriorityqueue_tbinarytree(queue, tmp_tree);
        }

        qsort(queue->data, queue->data_count, sizeof(TBinaryTree *), cmp_tbinarytrees);
        /*
        printf("\n====================Encoding table====================\n");
        for (int i = 0; i < queue->data_count; i++)
        {
            unsigned char tmp_symbol = queue->data[i]->root->symbol;
            unsigned char tmp_payload = queue->data[i]->root->payload;
            printf("\nCode of symbol is %3d;                 Payload is %3d;\n", tmp_symbol, tmp_payload);
            printf("\n%s\n", queue->data[i]->root->code);
        }
        printf("\n======================================================\n");
        */
        TBinaryTree *tmp_tree = create_huffman_tree(queue, queue->data_count);
        fillEncodingArray(tmp_tree);
        /*
        for (int i = 0; i < queue->data_count; i++) {
            unsigned char tmp_symbol = queue->data[i]->root->symbol;
            unsigned char tmp_payload = queue->data[i]->root->payload;
            printf("\nCode of symbol is %3d;                 Payload is %3d;\n", tmp_symbol, tmp_payload);
            printf("\n%s\n", queue->data[i]->code);
        }
*/
        printf("\n====================Encoding table====================\n");
        for (int i = 0; i < tfile->tsymbols_count; i++) {
            unsigned char tmp = tfile->array_of_tsymbols[i]->symbol;
            printf("\nCode of symbol is %3d;                 Payload is %3d;\n", tmp,
                   tfile->array_of_tsymbols[i]->payload);
            printf("%s\n", tfile->array_of_tsymbols[i]->);
        }
        printf("\n======================================================\n");
    }
    else
        fprintf(stderr, "Can not open input file!\n");

    return 0;
}

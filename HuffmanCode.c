// HuffmanCode.c Define the entry point of program
//

#define _CRT_SECURE_NO_WARNINGS
#define FILENAME "/home/grigoriy/projects/compressor_tmp/8.tex"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

        TBinaryTree *tmp_tree = create_huffman_tree(queue, queue->data_count);

        get_codes(tmp_tree);

        //copy codes from tree to symbol
        for (int i = 0; i < queue->data_count; i++) {
            if (queue->data[i]->root->symbol != 0) {
                unsigned char tmp_symbol = queue->data[i]->root->symbol;
                unsigned char tmp_payload = queue->data[i]->root->payload;
                strcpy(queue->data[i]->root->code, queue->data[i]->code);
            }
        }
        // end

        // add additional code of symbols
        for (int count_of_tsymbols = 0; count_of_tsymbols < (tfile->tsymbols_count); count_of_tsymbols++)
        {
            TSymbol* tmp = tfile->array_of_tsymbols[count_of_tsymbols];
            strcat(tmp->code, "1");
            while (strlen(tmp->code)%8 != 0 )
                strcat(tmp->code, "0");
        }
        //end add additional code of symbols

        qsort(tfile->array_of_tsymbols,tfile->tsymbols_count,sizeof(TSymbol*),cmp_tsymbols);

        printf("\n====================Encoding table====================\n");
        for (int i = 0; i < tfile->tsymbols_count; i++) {
            unsigned char tmp = tfile->array_of_tsymbols[i]->symbol;
            printf("\nCode of symbol is %3d;                 Payload is %3d;\n", tmp,
                   tfile->array_of_tsymbols[i]->payload);
            printf("\n%s\n", tfile->array_of_tsymbols[i]->code);
        }
        printf("\n======================================================\n");

        // create table of association
        for (int count_of_tsymbols = 0; count_of_tsymbols < (tfile->tsymbols_count); count_of_tsymbols++)
        {
            TSymbol* tmp = tfile->array_of_tsymbols[count_of_tsymbols];
            unsigned byte = strlen(tmp->code) / 8;
            unsigned code_len = 0;

            for (int k = 0; k < byte; k ++)
            {

                unsigned char buf = 0;

                for (int i = 7; i >= 0; i--)
                {
                    if (tmp->code[code_len] == '1')
                    {
                        buf |= (1 << i);
                    }
                    if (tmp->code[code_len] == '0')
                    {
                        buf &= ~(1 << i);
                    }
                    code_len++;
                }
                printf("buf is %d\n", buf);//replace write in file
            }
        }
        // end create table of association

        // delete additional code of symbols
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
        //end delete additional code of symbols

        /*
        printf("\n====================Encoding table====================\n");
        for (int i = 0; i < tfile->tsymbols_count; i++) {
            unsigned char tmp = tfile->array_of_tsymbols[i]->symbol;
            printf("\nCode of symbol is %3d;                 Payload is %3d;\n", tmp,
                   tfile->array_of_tsymbols[i]->payload);
            printf("\n%s\n", tfile->array_of_tsymbols[i]->code);
        }
        printf("\n======================================================\n");
        */
    }
    else
        fprintf(stderr, "Can not open input file!\n");

    return 0;
}

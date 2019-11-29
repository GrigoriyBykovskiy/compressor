// HuffmanCode.c Define the entry point of program
//

#define _CRT_SECURE_NO_WARNINGS
#define FILENAME "/home/grigoriy/projects/compressor_tmp/8.tex"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "HUFFMAN.h"

void bit_check(char symbol) {/*little-endian format*/
    int array_of_bits[8];
    printf("%c : ", symbol);
    for (int i = 0; i < 8; i++) {
        if ((symbol & (1 << i)) == 0) {
            array_of_bits[i] = 0;
        }
        else {
            array_of_bits[i] = 1;
        }
        printf("%d", array_of_bits[i]);
    }
    printf("\n");
};

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
        get_codes(tmp_tree);
        for (int i = 0; i < queue->data_count; i++) {
            if (queue->data[i]->root->symbol != 0) {
                unsigned char tmp_symbol = queue->data[i]->root->symbol;
                unsigned char tmp_payload = queue->data[i]->root->payload;
                strcpy(queue->data[i]->root->code, queue->data[i]->code);
                printf("\nCode of symbol is %3d;                 Payload is %3d;\n", tmp_symbol, tmp_payload);
                printf("\n%s\n", queue->data[i]->code);
            }
        }
        printf("\n====================Encoding table====================\n");
        for (int i = 0; i < tfile->tsymbols_count; i++) {
            unsigned char tmp = tfile->array_of_tsymbols[i]->symbol;
            printf("\nCode of symbol is %3d;                 Payload is %3d;\n", tmp,
                   tfile->array_of_tsymbols[i]->payload);
            printf("\n%s\n", tfile->array_of_tsymbols[i]->code);
        }
        printf("\n======================================================\n");
        // add additional code of symbols
        for (int count_of_tsymbols = 0; count_of_tsymbols < (tfile->tsymbols_count); count_of_tsymbols++)
        {
            TSymbol* tmp = tfile->array_of_tsymbols[count_of_tsymbols];
            strcat(tmp->code, "1");
            while (strlen(tmp->code)%8 != 0 )
                strcat(tmp->code, "0");
        }
        //end add additional code of symbols

        for (int count_of_tsymbols = 0; count_of_tsymbols < (tfile->tsymbols_count); count_of_tsymbols++)
        {
            TSymbol* tmp = tfile->array_of_tsymbols[count_of_tsymbols];
            unsigned byte = strlen(tmp->code) / 8;
            //printf("%d\n", byte);
            unsigned code_len = strlen(tmp->code) - 1;

            for (int k = 0; k < byte; k ++)
            {
                //printf("%d\n", k);

                unsigned char buf = 0;

                for (int i = 0; i < 8; i++)
                {
                    //printf("code len is %d\n", code_len);
                    //printf("i = %d\n", i);
                    if (tmp->code[code_len] == '1')
                    {
                        buf |= (1 << i);
                        //printf("tmp->code[code_len] == 0 \n");
                    }
                    if (tmp->code[code_len] == '0')
                    {
                        buf &= ~(1 << i);
                    }
                    code_len--;
                }
                printf("buf is %d\n", buf);
                bit_check(buf);
            }
        }
        printf("\n====================Encoding table====================\n");
        for (int i = 0; i < tfile->tsymbols_count; i++) {
            unsigned char tmp = tfile->array_of_tsymbols[i]->symbol;
            printf("\nCode of symbol is %3d;                 Payload is %3d;\n", tmp,
                   tfile->array_of_tsymbols[i]->payload);
            printf("\n%s\n", tfile->array_of_tsymbols[i]->code);
        }
        printf("\n======================================================\n");
    }
    else
        fprintf(stderr, "Can not open input file!\n");

    return 0;
}

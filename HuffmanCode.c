// HuffmanCode.c Define the entry point of program
//

#define _CRT_SECURE_NO_WARNINGS
#define FILENAME "8.tex"
#define OUTPUTFILENAME "output.txt"
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
        for (int i = 0; i < queue->data_count; i++)
        {
            if (queue->data[i]->root->symbol != 0) {
                unsigned char tmp_symbol = queue->data[i]->root->symbol;
                unsigned char tmp_payload = queue->data[i]->root->payload;
                strcpy(queue->data[i]->root->code, queue->data[i]->code);
            }
        }
        // end

        add_tsymbol_additional_code(tfile);

        //qsort(tfile->array_of_tsymbols,tfile->tsymbols_count,sizeof(TSymbol*),cmp_tsymbols);

        FILE* output_text = NULL;
        if (((output_text = fopen(OUTPUTFILENAME, "w")) != NULL))
        {
            // create table of association
            for (int count_of_tsymbols = 0; count_of_tsymbols < (tfile->tsymbols_count); count_of_tsymbols++)
            {
                TSymbol* tmp = tfile->array_of_tsymbols[count_of_tsymbols];
                unsigned byte = strlen(tmp->code) / 8;
                unsigned code_len = 0;

                fprintf(output_text,"%c", tmp->symbol);
                printf("%d\n",tmp->symbol);

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
                    fprintf(output_text,"%c", buf);//replace write in file
                }
            }
            // end create table of association
        }

        delete_tsymbol_additional_code(tfile);
        /*
        // create output file
        if (((input_text = fopen(FILENAME, "r")) != NULL) && (output_text = fopen(OUTPUTFILENAME, "wb")) != NULL) {
            char symbol;
            char *buf = malloc(1);
            int buf_len = 0;
            buf[0] = 0;

            do {
                int count = is_tfile_tsymbol_symbol_exist(tfile, symbol);
                symbol = fgetc(input_text);

                //printf("len of buf %d\n",strlen(buf));
                if (count)
                {
                    printf("OK\n");
                    TSymbol* tsymbol_buf = tfile->array_of_tsymbols[count];
                    buf_len += strlen(tsymbol_buf->code);
                    //printf("new len of buf %d\n",buf_len);
                    buf = (char*) realloc (buf, (buf_len + 1) * sizeof(char));
                    strcpy(buf,tsymbol_buf->code);
                    printf("len of buf %d\n",strlen(buf));
                    if ((buf_len % 8 == 0) && (buf != NULL))
                    {
                        printf("\n%s\n", buf);
                        free(buf);
                        buf_len = 0;
                    }
                }

            } while (symbol != EOF);
        }

        // end create output file
        */
    }
    else
        fprintf(stderr, "Can not open input file!\n");

    return 0;
}

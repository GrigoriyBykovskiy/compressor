#define _CRT_SECURE_NO_WARNINGS
#define FILENAME "8.tex"
#define OUTPUTFILENAME "output.cmp"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "HUFFMAN.h"

int main()
{
    FILE* input_text = NULL;
    TFile* tfile = init_tfile();

    if (((input_text = fopen(FILENAME, "rb")) != NULL) && (tfile != NULL)) {
        char symbol;
        unsigned count_of_symbols = 0;
        unsigned count_of_unique_symbols = 0;

        do {
            symbol = fgetc(input_text);

            if (!is_tfile_tsymbol_symbol_exist(tfile, symbol))
            {
                TSymbol *tmp_tsymbol = init_tsymbol();
                set_tsymbol_symbol(tmp_tsymbol, symbol);
                set_tsymbol_payload(tmp_tsymbol, 1);
                add_tfile_tsymbol(tfile, tmp_tsymbol);
                count_of_unique_symbols++;

            }

            count_of_symbols++;

        } while (symbol != EOF);

        fclose(input_text);

        TPriorityQueue *queue = init_queue();

        for (int i = 0; i < tfile->tsymbols_count; i++)
        {
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

        qsort(tfile->array_of_tsymbols,tfile->tsymbols_count,sizeof(TSymbol*),cmp_tsymbols);

        //print_tfile_data(tfile);

        add_tsymbol_additional_code(tfile);

        FILE* output_text = NULL;
        if ((output_text = fopen(OUTPUTFILENAME, "wb")) != NULL)
        {
            // create table of association
            for (int count_of_tsymbols = 0; count_of_tsymbols < (tfile->tsymbols_count); count_of_tsymbols++)
            {
                TSymbol* tmp = tfile->array_of_tsymbols[count_of_tsymbols];
                unsigned byte = strlen(tmp->code) / 8;
                unsigned code_len = 0;
                char tmp_byte = 0;
                tmp_byte = unsigned_to_char(&byte);

                fprintf(output_text,"%c", tmp->symbol);
                fprintf(output_text,"%c", tmp_byte);

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
                    fprintf(output_text,"%c", buf);
                }
            }
            // end create table of association
        }

        fclose(output_text);

        delete_tsymbol_additional_code(tfile);

        // create output file
        if (((input_text = fopen(FILENAME, "r")) != NULL) && (output_text = fopen(OUTPUTFILENAME, "ab")) != NULL) {
            char symbol;
            int buf_len = 0;
            char *buf = (char*)malloc(sizeof(char)*(buf_len+1));
            buf[0] = '\0';
            int index = 0;

            do {
                symbol = fgetc(input_text);
                index  = find_tfile_tsymbol(tfile, symbol);

                if (index >= 0)
                {
                    TSymbol *tmp_tsymbol = tfile->array_of_tsymbols[index];
                    buf_len += strlen(tmp_tsymbol->code);
                    buf = (char*)realloc(buf,sizeof(char)*(strlen(buf)+strlen(tmp_tsymbol->code)+2));
                    strcat(buf, tmp_tsymbol->code);

                    if (strlen(buf) % 8 == 0)
                    {

                        unsigned byte = strlen(buf) / 8;
                        unsigned code_len = 0;

                        for (int k = 0; k < byte; k ++)
                        {

                            unsigned char char_buf = 0;

                            for (int i = 7; i >= 0; i--)
                            {
                                if (buf[code_len] == '1')
                                {
                                    char_buf |= (1 << i);
                                }
                                if (buf[code_len] == '0')
                                {
                                    char_buf &= ~(1 << i);
                                }
                                code_len++;
                            }
                            fprintf(output_text,"%c", char_buf);
                        }

                        free(buf);
                        buf_len = 0;
                        buf = (char*)malloc(sizeof(char)*(buf_len+1));
                        buf[0] = '\0';
                    }
                }
                else
                {
                    printf(stderr, "Something was wrong!\n");
                    break;
                }
            } while (symbol != EOF);

            fclose(input_text);

            if (strlen(buf) % 8 != 0)
            {
                strcat(buf, "1");
                while (strlen(buf) % 8 != 0 )
                {
                    strcat(buf, "0");
                }
            }

            unsigned byte = strlen(buf) / 8;
            unsigned code_len = 0;


            for (int k = 0; k < byte; k ++)
            {

                unsigned char char_buf = 0 ;

                for (int i = 7; i >= 0; i--) {
                    if (buf[code_len] == '1') {
                        char_buf |= (1 << i);
                    }
                    if (buf[code_len] == '0') {
                        char_buf &= ~(1 << i);
                    }
                    code_len++;
                }
                fprintf(output_text, "%c", char_buf);
            }
            free(buf);
            fclose(output_text);
        }

        // end create output file
    }
    else
        fprintf(stderr, "Can not open input file!\n");

    return 0;
}

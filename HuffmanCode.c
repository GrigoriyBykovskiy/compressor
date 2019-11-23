// HuffmanCode.c Define the entry point of program
//
#define _CRT_SECURE_NO_WARNINGS
#define FILENAME "8.tex"
#include <stdio.h>
#include "HUFFMAN.H"

int main()
{
	FILE* input_text = NULL;
	TFile* tfile = NULL;
	tfile = init_tfile();

	if (((input_text = fopen(FILENAME, "r")) != NULL) && (tfile != NULL))
	{
		char symbol;
		unsigned count = 0;

		do
		{
			count++;
			symbol = fgetc(input_text);
			printf("%c", symbol);

			if (!is_tfile_tsymbol_symbol_exist(tfile, symbol))
			{
				TSymbol* tmp_tsymbol = NULL;
				tmp_tsymbol = init_tsymbol();
				set_tsymbol_symbol(tmp_tsymbol, symbol);
				set_tsymbol_payload(tmp_tsymbol, 1);
				add_tfile_tsymbol(tfile, tmp_tsymbol);
			}
			//проверка на то, есть ли в массиве структур структура с полем символ == symbol
			//если есть, то увеличиваем payload на 1
			//если нет, то создаем структуру и кладем в массив структур
		} while (symbol != EOF);
	}
	else 
	{
		fprintf(stderr, "Can not open input file!\n");
		return NULL;
	}
	printf("\n====================Encoding table====================\n");
	for (int i = 0; i < tfile->tsymbols_count; i++)
	{
		unsigned char tmp = tfile->array_of_tsymbols[i]->symbol;
		printf("\nCode of symbol is %3d;                 Payload is %3d;\n", tmp, tfile->array_of_tsymbols[i]->payload);
	}
	printf("\n======================================================\n");
	return 0;
}

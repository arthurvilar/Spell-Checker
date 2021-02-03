//GRR20197153 Arthur Henrique Canello Vilar

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <locale.h>
#include <ctype.h>
#include "dicionario.h"

int main () {

	FILE *dict;
	int line = 0;
	char palavra[100];
	char *locale;
	char c;

	//coloca o locale em ISO-8859-1
	locale = setlocale(LC_CTYPE, "pt_BR.iso88591"); 
	if (!locale) {
		printf("Can't set the locale.\n");
		return -1;
	}

	//testa se o dicionario abriu corretamente
	if ((dict = fopen("/usr/share/dict/brazilian", "r")) == NULL)
		if ((dict = fopen("brazilian", "r")) == NULL) {
			printf("Erro ao abrir o dicionario.\n");
			return 0;
		}

	//aloca dinamicamente o dicionario e ordena ele
	char **vet = aloca_dict(dict, &line);
	qsort(vet, line, sizeof(char *), str_compare);

	fclose(dict);

	c = getchar();

	//loop principal para ler o texto
	while (c != EOF) {

		//se nao for letra imprime direto no stdout
		while (!isalpha(c) && c != EOF) {
			fprintf(stdout, "%c", c);
			c = getchar();
		}

		strcpy(palavra, ""); //limpa a variavel palavra

		//enquanto for letra concatena na variavel palavra
		while (isalpha(c) && c != EOF) {
			strncat(palavra, &c, 1);
			c = getchar();
		}
	
		//busca a palava no dicionario e imprime
		if (c != EOF) { 
			if (!busca_dicionario(vet, line, palavra))
				fprintf(stdout, "[%s]", palavra); //nao achou a palavra
			else
				fprintf(stdout, "%s", palavra);   //achou a palavra
		}
	}

	printf("\n");

	//libra o espaço alocado
	libera_dict(vet, line);

	return 1;
}
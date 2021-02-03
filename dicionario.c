//GRR20197153 Arthur Henrique Canello Vilar

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

//ALOCA O DICIONARIO EM VET E RETORNA VET, CONTA O TAMANHO DO DICIONARIO EM LINE
char **aloca_dict(FILE *dict, int *line) {
	
	char **vet = NULL;
	int cont = 10000; 
	int i = 0;

	vet = (char**)malloc(sizeof(char*)*cont);

	//alocação em blocos 
	vet[i] = (char*)malloc(sizeof(char)*100);
	while (fgets(vet[i], 100, dict) != NULL) {
		vet[i] = strtok(vet[i], "\n");
		i++;
		if (i >= cont) {   //faz o realloc para o valor de cont
			cont += 10000;
			vet = (char**)realloc(vet, sizeof(char*)*cont);
		}	
		vet[i] = (char*)malloc(sizeof(char)*100);
	}

	*line = i;
	return vet;
}

//RETORNA CONSTANTE CHAR COM STRCASECMP PARA USAR NO QSORT
int str_compare(const void *a, const void *b) {

	const char **ia = (const char **)a;
	const char **ib = (const char **)b;

	return strcasecmp(*ia, *ib);
}

//USA BUSCA BINARIA PARA PROCURAR A PALAVRA
int busca_dicionario(char *vet[], int line, char palavra[]) {

	int ini, fim, meio;
	ini = 0;
	fim = line-1;

	while (ini <= fim) {
		meio = (ini + fim)/2;
		if (strcasecmp(palavra, vet[meio]) == 0) //se palavra = vet[meio]
			return 1;
		else if (strcasecmp(palavra, vet[meio]) > 0)  //se palavra esta depois do vet[meio]
			ini = meio + 1;
		else  
			fim = meio - 1;  //se palavra esta antes do vet[meio]
	}

	return 0;
}

//LIBERA O ESPAÇO ALOCADO PRO DICT
int libera_dict(char *vet[], int line) {

	int i;

	for (i = 0; i <= line; i++)
		free(vet[i]);
	free(vet);

	return 1;
}
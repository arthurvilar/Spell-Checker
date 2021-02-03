//GRR20197153 Arthur Henrique Canello Vilar

#ifndef __DICIO__
#define __DICIO__

//ALOCA O DICIONARIO EM VET E RETORNA VET, CONTA O TAMANHO DO DICIONARIO EM LINE
char **aloca_dict(FILE *dict, int *line);

//RETORNA CONSTANTE CHAR COM STRCASECMP PARA USAR NO QSORT
int str_compare(const void *a, const void *b);

//USA BUSCA BINARIA PARA PROCURAR A PALAVRA
int busca_dicionario(char *vet[], int line, char palavra[]);

//LIBERA O ESPAÇO ALOCADO PRO DICT
int libera_dict(char *vet[], int line);

#endif
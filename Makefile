#GRR20197153 Arthur Henrique Canello Vilar

# regra default 
all: ortografia

# regras de ligação
ortografia: ortografia.o dicionario.o
	gcc ortografia.o dicionario.o -o ortografia

# regras de compilação
ortografia.o: ortografia.c dicionario.h
	gcc -c ortografia.c -Wall

dicionario.o: dicionario.c dicionario.h
	gcc -c dicionario.c -Wall

# remove arquivos temporários
clean:
	-rm -f *~ *.o

# remove tudo o que não for o código-fonte original
purge: clean
	-rm -f ortografia *.txt
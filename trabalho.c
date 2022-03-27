#include <stdio.h>
#include <conio.h>

typedef struct ler
{

	int conteudo;
	float *prox;
} Celula;

Celula *inserir(int valor, Celula *topo)
{
	Celula *novo; // para alocar nova celula

	// alocar memoria
	novo = (Celula *)malloc(sizeof(Celula));

	// depositar valor
	novo->conteudo = valor;

	// engatar
	novo->prox = topo; // o novo elemento conhece o topo

	return novo; // novo topo eh retornado
}


Celula *localizar(int valor, Celula *topo)
{
	Celula *p;
	if (topo)
	{
		for (p = topo; p; p = p->prox)
		{
			if (valor == p->conteudo)
			{
				return p; // achou o valor
			}
		}
	}
	return NULL; // valor não localizado
}

void main()
{
	FILE *arq;
	char Linha[100];
	char *result;
	int valor;
	int i = 1;
	int meuTopo;
	Celula *pilha = NULL;

	printf("BEM VINDO!\n");
	// TEXTO para LEITURA
	arq = fopen("leitura.txt", "r");//nome do bloco de texto + .txt
	if (arq == NULL) // erro na abertura
	{
		printf("Problemas na abertura do arquivo\n");
		return;
	}
	// Vai ficar repetindo enquanto ler o arquivo
	while (!feof(arq))
	{
		result = fgets(Linha, 100, arq);
		// 100 caracteres de uma linha
		printf("Linha - %i | Result: %s\n", i, result);
		// TESTE DE AQUISIÇÃO DE DADOS
		if (result)
		{
			valor = atoi(result);
			pilha = inserir(valor, pilha);
		}
		i++;
	}
	printf("MEU TOPO:%i", pilha->conteudo);
	fclose(arq);
}

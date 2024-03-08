#include <stdio.h>
#include <stdlib.h>

int contador;

struct No{
		int info;
		struct No *prox;
	};
	// posso carregar o main antes da fun��o usando void inserirLista(int nr);
	struct No *cabeca = NULL;
	struct No *ult; // precisa de um ponteiro para o ultimo elemento da lista caso ela seja maior que 1
	/*
	Passo a passo
	o novo receber� um endere�o livre de tamanho struct No
	ele passar� o valor inserido na fun��o pro info, e definir� o prox endere�o como null
	se o cabeca for null, ele passar� o endere�o do primeiro ponteiro para o cabeca, indicando o inicio da lista
	se n�o, ele aponta para o *prox do endere�o passado e define como o endere�o de novo.
	*/
void inserirLista(int num){
	struct No *novo; // o novo vai armazenar um endere�o que o malloc ir� achar, e o tipo de novo ser� o struct No
	novo =(struct No*) malloc(sizeof(struct No)); // malloc � uma fun��o que aloca espa�o na mem�ria de acordo com o argumento passado	
                                  //sizeof vai pegar o tamanho do struct No e o malloc vai alocar um espa�o do tamanho do struct No
    novo->info = num;
    novo->prox = NULL;
    if (cabeca == NULL){ //ele nao quer para onde ele aponta, ele quer saber se o endere�o � null
		cabeca=novo;
	} else {
		ult->prox = novo;
	}
    ult = novo;
    contador +=1;
}

void exibirLista();
void qtdeElementos();
void removerLista(int valor);
void menu();                             
	
int main()
{	
	menu();	
	return 0;
}

void menu(){
	int opcao;
	do {
		system("CLS");
		printf("1 - Inserir\n");
		printf("2 - Exibir\n");
		printf("3 - Remover n�mero\n");
		printf("4 - Quantidade da lista\n");
		printf("5 - Sair\n");
		printf("Escolha a opcao: ");
		scanf("%d", &opcao);
		int resp;
		if (opcao == 1){
			printf("Insira o numero: ");
			scanf("%d", &resp);
			inserirLista(resp);
		}
		else if (opcao == 2){
			exibirLista();
		} else if (opcao == 3){
			printf("Insira o numero: ");
			scanf("%d", &resp);
			removerLista(resp);
		} else if (opcao == 4){
			qtdeElementos();
		}
		system("pause");
	} while(opcao != 5);
}


void exibirLista(){
	struct No *aux;
	aux = cabeca; //definimos outro ponteiro para nao mexermos na lista com a chance de perd�-la
	while (aux != NULL){
		printf("%x %d -> %x\n", aux, aux->info, aux->prox);
		aux = aux->prox;
	}
}

void qtdeElementos(){
	printf("Quantidade de elementos: %d\n", contador);
}

/*
Cen�rios de remo��o:
- remover 1o elemento
- remover 2o elemento
- remover o 3o elemento
- remover o ultimo
- elemento que nao existe na lista
- lista vazia
*/
void removerLista(int valor){
	struct No *ant; // ponteiro do elemento anterior da lista
	struct No *aux;
	if (cabeca == NULL){
		printf("Lista vazia.");
		return;
	}
	aux = cabeca;
	
	while(aux->info != valor && aux->prox != NULL){
		ant = aux; // salva o endere�o do elemento anterior
		aux = aux->prox;
	}
	if(aux->info != valor && aux->prox == NULL){
		printf("Valor n�o encontrado.");
		return;
	} else if(aux == cabeca){ // condi��o para remover o primeiro elemento, j� que ele nao percorreu o while
		cabeca = aux->prox;
	} else {
		ant->prox = aux->prox; //define o endere�o do item prox da variavel anterior para o item prox da vari�vel atual
								//ex: queremos remover o 30, o 20 est� antes e o 40 depois, ele altera o endere�o do 20 que leva
								// pro 30 e recebe o endere�o do 30 que leva pro 40
	}
	free(aux); // libera espa�o do elemento que acabou de ser removido

}

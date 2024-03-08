#include <stdio.h>
#include <stdlib.h>

int contador;

struct No{
		int info;
		struct No *prox;
	};
	struct No *cabeca = NULL;
	struct No *ult; // precisa de um ponteiro para o ultimo elemento da lista caso ela seja maior que 1
	/*
	Passo a passo
	o novo receberá um endereço livre de tamanho struct No
	ele passará o valor inserido na função pro info, e definirá o prox endereço como null
	se o cabeca for null, ele passará o endereço do primeiro ponteiro para o cabeca, indicando o inicio da lista
	se não, ele aponta para o *prox do endereço passado e define como o endereço de novo.
	*/
void inserirLista(int num){
	struct No *novo; // o novo vai armazenar um endereço que o malloc irá achar, e o tipo de novo será o struct No
	novo =(struct No*) malloc(sizeof(struct No)); // malloc é uma função que aloca espaço na memória de acordo com o argumento passado	
                                  //sizeof vai pegar o tamanho do struct No e o malloc vai alocar um espaço do tamanho do struct No
    novo->info = num;
    novo->prox = NULL;
    if (cabeca == NULL){ //ele nao quer para onde ele aponta, ele quer saber se o endereço é null
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
		printf("3 - Remover número\n");
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
	aux = cabeca; //definimos outro ponteiro para nao mexermos na lista com a chance de perdê-la
	while (aux != NULL){
		printf("%x %d -> %x\n", aux, aux->info, aux->prox);
		aux = aux->prox;
	}
}

void qtdeElementos(){
	printf("Quantidade de elementos: %d\n", contador);
}

/*
Cenários de remoção:
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
		ant = aux; // salva o endereço do elemento anterior
		aux = aux->prox;
	}
	if(aux->info != valor && aux->prox == NULL){
		printf("Valor não encontrado.");
		return;
	} else if(aux == cabeca){ // condição para remover o primeiro elemento, já que ele nao percorreu o while
		cabeca = aux->prox;
	} else {
		ant->prox = aux->prox; //define o endereço do item prox da variavel anterior para o item prox da variável atual
								//ex: queremos remover o 30, o 20 está antes e o 40 depois, ele altera o endereço do 20 que leva
								// pro 30 e recebe o endereço do 30 que leva pro 40
	}
	free(aux); // libera espaço do elemento que acabou de ser removido

}

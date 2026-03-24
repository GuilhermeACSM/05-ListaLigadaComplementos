#include <iostream>
using namespace std;

// definicao de tipo
struct NO {
	int valor;
	NO* prox;
};

NO* primeiro = NULL;
NO* ultimo = NULL;

// headers
void menu();
void inicializar();
void exibirQuantidadeElementos();
void exibirElementos();
void inserirElemento();
void excluirElemento();
void buscarElemento();
NO* posicaoElemento(int numero);
//--------------------------


int main()
{
	menu();
}

void menu()
{
	int op = 0;
	while (op != 7) {
		system("cls"); // somente no windows
		cout << "Menu Lista Ligada";
		cout << endl << endl;
		cout << "1 - Inicializar Lista \n";
		cout << "2 - Exibir quantidade de elementos \n";
		cout << "3 - Exibir elementos \n";
		cout << "4 - Buscar elemento \n";
		cout << "5 - Inserir elemento \n";
		cout << "6 - Excluir elemento \n";
		cout << "7 - Sair \n\n";

		cout << "Opcao: ";
		cin >> op;

		switch (op)
		{
		case 1: inicializar();
			break;
		case 2: exibirQuantidadeElementos();
			break;
		case 3: exibirElementos();
			break;
		case 4: buscarElemento();
			break;
		case 5: inserirElemento();
			break;
		case 6: excluirElemento();
			break;

		case 7:
			return;
		default:
			break;
		}

		system("pause"); // somente no windows
	}
}

void inicializar()
{

	// se a lista j� possuir elementos
	// libera a memoria ocupada
	NO* aux = primeiro;
	while (aux != NULL) {
		NO* paraExcluir = aux;
		aux = aux->prox;
		free(paraExcluir);
	}

	primeiro = NULL;
	ultimo = NULL;
	cout << "Lista inicializada \n";

}

void exibirQuantidadeElementos() {

	int nElementos = 0;
	NO* aux = primeiro;
	while (aux != NULL) {
		nElementos++;
		aux = aux->prox;
	}
	cout << "Quantidade de elementos: " << nElementos << endl;

}

void exibirElementos()
{
	if (primeiro == NULL) {
		cout << "Lista vazia \n";
		return;
	}
	else {
		cout << "Elementos: \n";
		NO* aux = primeiro;
		while (aux != NULL) {
			cout << aux->valor << endl;
			aux = aux->prox;
		}
	}
}

void inserirElemento()
{
	// aloca memoria dinamicamente para o novo elemento
	NO* novo = (NO*)malloc(sizeof(NO));
	if (novo == NULL)
	{
		return;
	}

	int valor;
	cout << "Digite o elemento: ";
	cin >> valor;

	if(posicaoElemento(valor) != NULL) {
		cout << "Esse elemento já existe!" << endl;
		return;
	}

	novo->valor = valor;
	novo->prox = NULL;

	if (primeiro == NULL)
	{
		primeiro = novo;
		ultimo = novo;
	}
	else
	{
		ultimo->prox = novo;
		ultimo = novo;
	}
}

void excluirElemento()
{
	int valor;
	cout << "Digite o elemento: ";
	cin >> valor;

	NO* paraExcluir = posicaoElemento(valor);
	if (paraExcluir == NULL) {
		cout << "Elemento não encontrado!" << endl;
		return;
	}

	if (paraExcluir == primeiro) {
		primeiro = primeiro->prox;

		if (primeiro == NULL) {
			ultimo = NULL;
		}

		free(paraExcluir);
	} else {
		NO* anterior = primeiro;
		while (anterior->prox != paraExcluir) {
			anterior = anterior->prox;
		}

		if (paraExcluir == ultimo) {
			ultimo = anterior;
			ultimo->prox = NULL;
		} else {
			anterior->prox = paraExcluir->prox;
		}
		free(paraExcluir);
	}
}

void buscarElemento()
{
	int valor;
	cout << "Digite o elemento: ";
	cin >> valor;

	if (posicaoElemento(valor) != NULL) {
		cout << "Encontrado!" << endl;
	}
	else {
		cout << "Número não encontrado!" << endl;
	}
}



// retorna um ponteiro para o elemento buscado
// ou NULL se o elemento n�o estiver na lista
NO* posicaoElemento(int numero)
{
	NO* aux = primeiro;
	while (aux != NULL) {
		if (aux->valor == numero)
		{
			break;
		}
		aux = aux->prox;
	}
	return aux;
}
#ifndef LISTA_H
#define LISTA_H

#include "listaDuplaEncad.cpp"


using namespace std;

typedef struct tipoItem{
    int id = 1;
    string nome;
    string linha;
    string companhia;
    int idStop = 0;

    tipoListaDupla paradas;
};

typedef struct tipoElemento *Apontador;

typedef struct tipoElemento{
    tipoItem item;
    Apontador prox;
};

bool listaCriada = false;

typedef struct tipoLista
{
    Apontador primeiro;
    Apontador ultimo;
    int tamanho = 0;
};

void criarListaVazia(tipoLista *lista);
bool verificaListaVazia(tipoLista *lista);
int tamanhoLista(tipoLista *lista);
void insereListaPrimeiro(tipoLista *lista, tipoItem *item);
void atualizaUltimo(tipoLista *lista);
void insereListaUltimo(tipoLista *lista, tipoItem *item);
void insereListaAposElemento(tipoLista *lista, tipoItem *item, int id);
void imprimeLista(tipoLista lista);
Apontador pesquisaItem(tipoLista *lista, int id);
void imprimeItem(tipoLista *lista, int id);
void imprimeItemRecebido(tipoItem item);
void removeListaPrimeiro(tipoLista *lista);
void removeListaUltimo(tipoLista *lista);
void removeItemPorId(tipoLista *lista, int id);


#endif

#include <iostream>
#include "listaEncadSimples.hpp"
#include <windows.h>

#define MAX_TAM 5;

using namespace std;

void criarListaVazia(tipoLista *lista){
    if(!listaCriada){
        lista->primeiro = new tipoElemento;
        lista->ultimo = lista->primeiro;
        lista->ultimo->prox = NULL;
        listaCriada = true;
    }
}

bool verificaListaVazia(tipoLista *lista){
    return (lista->primeiro == lista->ultimo);
}

int tamanhoLista(tipoLista *lista){
    return lista->tamanho;
}

void insereListaPrimeiro(tipoLista *lista, tipoItem *item){
    Apontador aux;
    aux = lista->primeiro->prox;
    lista->primeiro->prox = new tipoElemento;
    lista->primeiro->prox->prox = aux;
    lista->primeiro->prox->item = *item;
    lista->tamanho++;
    atualizaUltimo(lista);
}

void atualizaUltimo(tipoLista *lista){
    Apontador aux;
    aux = lista->primeiro;
    while(aux->prox != NULL){
        aux = aux->prox;
    }
    lista->ultimo = aux;
}

void insereListaUltimo(tipoLista *lista, tipoItem *item){
    lista->ultimo->prox = new tipoElemento;
    lista->ultimo = lista->ultimo->prox;
    lista->ultimo->item = *item;
    lista->ultimo->prox = NULL;
    lista->tamanho++;
}

void insereListaAposElemento(tipoLista *lista, tipoItem *item, int id){
    Apontador aux, pAux, x;
    bool find = false;
    pAux = lista->primeiro->prox;
    while (pAux != NULL){
        if (pAux->item.id == id){
            find = true;
            x = pAux;
            aux = x->prox;
            x->prox = new tipoElemento;
            x->prox->prox = aux;
            x->prox->item = *item;
            break;
        }
        pAux = pAux->prox;
    }
    if (find){
        cout << "Item inserido com sucesso!";
        atualizaUltimo(lista);
        lista->tamanho++;
    }else{
        cout << "Elemento anterior não encontrado na lista.";
    }
}

void imprimeLista(tipoLista lista){
    if (verificaListaVazia(&lista)){
        cout << "Lista vazia!\n";
        Sleep(1000);
        return;
    }
    Apontador aux;
    aux = lista.primeiro->prox;
    while (aux != NULL){
        cout << "ID: " << aux->item.id << endl;
        cout << "Nome: " << aux->item.nome << endl << endl;
        aux = aux->prox;
    }
    system("pause");
}

Apontador pesquisaItem(tipoLista *lista, int id){
    Apontador aux;
    aux = lista->primeiro->prox;
    while (aux != NULL){
        if (aux->item.id == id){
            return aux;
        }
        aux = aux->prox;
    }
    return aux;
}

void imprimeItem(tipoLista *lista, int id){
    Apontador aux;
    aux = lista->primeiro->prox;
    while (aux != NULL){
        if (aux->item.id == id){
            cout << "ID: " << aux->item.id << endl;
            cout << "Nome: " << aux->item.nome << endl << endl;
            break;
        }
        aux = aux->prox;
    }
}

void imprimeItemRecebido(tipoItem item){
    cout << "ID: " << item.id << endl;
    cout << "Companhia: " << item.companhia << endl;
}

void removeListaPrimeiro(tipoLista *lista){
    if (verificaListaVazia(lista)){
        return;
    }
    Apontador aux;
    aux = lista->primeiro->prox;
    lista->primeiro->prox = aux->prox;
    delete aux;
    lista->tamanho--;
}

void removeListaUltimo(tipoLista *lista){
    if (verificaListaVazia(lista)){
        return;
    }
    Apontador aux, atual;
    atual = lista->primeiro->prox;
    aux = lista->ultimo;
    while (atual->prox != lista->ultimo){
        atual = atual->prox;
    }
    atual->prox = NULL;
    lista->ultimo = atual;
    delete aux;
    lista->tamanho--;
}

void removeItemPorId(tipoLista *lista, int id){
    if (verificaListaVazia(lista)){
        return;
    }

    Apontador aux, anterior, x;
    x = lista->primeiro;

    while (x != NULL){
        if (x->prox->item.id == id){
            anterior = x;
            break;
        }
        x = x->prox;
    }
    aux = anterior->prox;
    anterior->prox = aux->prox;
    delete aux;
    lista->tamanho--;
    atualizaUltimo(lista);
}
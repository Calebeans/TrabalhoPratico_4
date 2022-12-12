#include "listaDuplaEncad.hpp"


void criarListaVaziaDupla(tipoListaDupla *lista){
    lista->primeiro = new tipoElementoDupla;
    lista->ultimo = lista->primeiro;
    lista->ultimo->prox = lista->ultimo;
    lista->ultimo->ant = lista->ultimo;
    lista->tamanho = 0;
}

bool verificaListaVaziaDupla(tipoListaDupla *lista){
    if(lista->tamanho == 0 && lista->ultimo == lista->primeiro){
        return true;
    }
    return false;
}

void insereListaUltimoDupla(tipoListaDupla *lista, tipoItemDupla item){
    lista->ultimo->prox = new tipoElementoDupla;
    lista->ultimo->prox->ant = lista->ultimo;
    lista->ultimo = lista->ultimo->prox;
    lista->ultimo->item = item;
    lista->ultimo->prox = lista->primeiro;
    lista->primeiro->ant = lista->ultimo;
    lista->tamanho++;
}

void insereListaPrimeiroDupla(tipoListaDupla *lista, tipoItemDupla item){
    ApontadorDupla inserido = new tipoElementoDupla;
    
    inserido->item = item;
    inserido->prox = lista->primeiro->prox;
    inserido->ant = lista->primeiro;
    lista->primeiro->prox->ant = inserido;
    lista->primeiro->prox = inserido;
    lista->tamanho++;
}

void insereAposElementoDupla(tipoListaDupla *lista, tipoItemDupla item, int id){
    ApontadorDupla atual = localizaIDDupla(lista, id);

    if(atual == NULL){
        cout << "\nCidade inexistente.\n" << endl;
        return;
    }else{
        cout << "\nParada inserida.\n";
        return;
    }

    ApontadorDupla inserido = new tipoElementoDupla;
    inserido->item = item;

    if(atual == lista->ultimo){
        insereListaUltimoDupla(lista, item);
    }else{
        inserido->prox = atual->prox;
        inserido->ant = atual;
        inserido->prox->ant = inserido;
    }
    atual->prox = inserido;
    lista->tamanho++;
}

ApontadorDupla localizaIDDupla(tipoListaDupla *lista, int id){
    ApontadorDupla aux = lista->primeiro->prox;
    while(aux != lista->primeiro){
        if(aux->item.id == id){
            return aux;
        }
        aux = aux->prox;
    }
    return NULL;
}

tipoItemDupla retiraIDDupla(tipoListaDupla *lista, int id){
    tipoItemDupla retorno;
    retorno.id = -1;

    if(verificaListaVaziaDupla(lista)){
        return retorno;
    }
    ApontadorDupla atual = localizaIDDupla(lista, id);

    if(atual != lista->primeiro){
        atual->ant->prox = atual->prox;

        if (atual == lista->ultimo){
            lista->ultimo = atual->ant;
            lista->primeiro->ant = lista->ultimo;
        }else{
            atual->prox->ant = atual->ant;
        }

        retorno = atual->item;
        delete atual;
    }
    lista->tamanho--;
    return retorno;
}

void imprimeItemDupla(tipoItemDupla item){
    if(item.id == -1){
        cout << "Item inexistente!" << endl;
        return;
    }

    cout << "ID: " << item.id << endl;
    cout << "Cidade: " << item.cidade << endl;
    cout << "Chegada: " << item.horarioChegada << endl;
    cout << "Saida: " << item.horarioSaida << endl;
    cout << "Preco da passagem: " << item.passagem << endl;
    cout << endl;
}

void imprimeListaDupla(tipoListaDupla *lista){
    ApontadorDupla aux = lista->primeiro->prox;
    while(aux != lista->primeiro){
        imprimeItemDupla(aux->item);
        aux = aux->prox;
    }
}

void imprimeContrarioDupla(tipoListaDupla *lista){
    ApontadorDupla aux = lista->ultimo;
    while(aux != lista->primeiro){
        imprimeItemDupla(aux->item);
        aux = aux->ant;
    }
}
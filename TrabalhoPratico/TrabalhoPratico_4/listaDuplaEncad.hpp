#include <iostream>

using namespace std;

typedef struct tipoItemDupla{
    int id;
    string cidade;
    string horarioChegada;
    string horarioSaida;
    double passagem;
};

typedef struct tipoElementoDupla *ApontadorDupla;

typedef struct tipoElementoDupla{
    ApontadorDupla ant;
    tipoItemDupla item;
    ApontadorDupla prox;
};

typedef struct tipoListaDupla{
    ApontadorDupla primeiro;
    ApontadorDupla ultimo;
    int tamanho;
};

void criarListaVaziaDupla(tipoListaDupla *lista);
bool verificaListaVaziaDupla(tipoListaDupla *lista);
void insereListaUltimoDupla(tipoListaDupla *lista, tipoItemDupla item);
void insereListaPrimeiroDupla(tipoListaDupla *lista, tipoItemDupla item);
void insereAposElementoDupla(tipoListaDupla *lista, tipoItemDupla item, int id);
ApontadorDupla localizaIDDupla(tipoListaDupla *lista, int id);
tipoItemDupla retiraIDDupla(tipoListaDupla *lista, int id);
void imprimeItemDupla(tipoItemDupla item);
void imprimeListaDupla(tipoListaDupla *lista);
void imprimeContrarioDupla(tipoListaDupla *lista);
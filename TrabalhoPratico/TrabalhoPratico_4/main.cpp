#include <iostream>
#include "funcoesMain.cpp"
#include <windows.h>
 
using namespace std;
 
int main() {
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);

    int idLinhas = 1;
    string senha;
    string senhaCorreta = "viajens123";

    tipoLista linhas;
    criarListaVazia(&linhas);
    viagensLinha(&linhas, &idLinhas);

    imprimeListaDupla(&linhas.ultimo->item.paradas);
    int escolha;

    while(escolha != 0){
        menu();

        cin >> escolha;

        if(escolha == 1){
            system("cls");
            encontreLinha(&linhas);
        }else if(escolha == 2){
            system("cls");
            cout << "Informe a senha! ";
            cin >> senha;

            if(senha == senhaCorreta){
                system("cls");
                alteracaoCompleta(&linhas, &idLinhas);
            }else{
              cout << endl;
                cout << "Senha incorreta!" << endl;
            }
        }
    }
    return 0;
}


void menu(){
    cout << " ______________" << endl;
    cout << "|              |" << endl;
    cout << "|1 - Rodoviária|" << endl;
    cout << "|2 - Edicao    |" << endl;
    cout << "|0 - Sair      |" << endl;
    cout << "|______________|" << endl << endl;
}


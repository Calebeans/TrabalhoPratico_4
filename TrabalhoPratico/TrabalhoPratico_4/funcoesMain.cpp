#include "funcoesMain.hpp"

using namespace std;

void viagensLinha(tipoLista *linha, int *id){
    
    //Linha Principal
    tipoItem item;
    item.id = *id;
    *id += 1;
    item.nome = "BH-SJE";
    item.companhia = "Onibus_1";

    criarListaVaziaDupla(&item.paradas);

    tipoItemDupla parada;

    //saida da linha - BH
    parada.id = item.id;
    item.id++;
    parada.horarioChegada = "01:00";
    parada.horarioSaida = "01:15";
    parada.cidade = "BH";
    parada.passagem = 0;

    insereListaUltimoDupla(&item.paradas, parada);

    //linha Itabira
    parada.id = item.id;
    item.id++;
    parada.horarioChegada = "01:50";
    parada.horarioSaida = "02:00";
    parada.cidade = "ITA";
    parada.passagem = 13.00;

    insereListaUltimoDupla(&item.paradas, parada);

    //linha Santa Maria de Itabira
    parada.id = item.id;
    item.id++;
    parada.horarioChegada = "05:15";
    parada.horarioSaida = "05:25";
    parada.cidade = "STM";
    parada.passagem = 31.00;

    insereListaUltimoDupla(&item.paradas, parada);

    //linha Guanhaes
    parada.id = item.id;
    item.id++;
    parada.horarioChegada = "06:15";
    parada.horarioSaida = "06:35";
    parada.cidade = "GHS";
    parada.passagem = 71.00;

    insereListaUltimoDupla(&item.paradas, parada);

    //linha SJE
    parada.id = item.id;
    item.id++;
    parada.horarioChegada = "09:25";
    parada.horarioSaida = "09:45";
    parada.cidade = "SJE";
    parada.passagem = 54.18;

    insereListaUltimoDupla(&item.paradas, parada);

    insereListaUltimo(linha, &item);
}

void encontreLinha(tipoLista *linhas){
    int op;
    ApontadorDupla umaOrigem;
    ApontadorDupla umDestino;

    do{
        cout << "1 - Encontre pela sua cidade" << endl;
        cout << "2 - Encontrar por codigo" << endl;
        cout << "0 - Voltar" << endl << endl;
        cout << "Opção: ";
        cin >> op;
        system("cls");
    } while (op != 0 && op != 1 && op != 2);
    

    if(op == 1){
        float valor = 0;
        int rotas = 0;

        string cidadeOrigem;
        string cidadeDestino;

        bool Origem = false;
        bool Destino = false;

        Apontador linha;
        linha = linhas->primeiro->prox;

        cout << "Informe a sua cidade de origem: ";
        cin >> cidadeOrigem;
        cout << "Informe a cidade de destino: ";
        cin >> cidadeDestino;

        while(linha != NULL){
            umDestino = linha->item.paradas.primeiro->prox;

            while (umDestino != linha->item.paradas.primeiro){
                if (umDestino->item.cidade == cidadeDestino){
                    Destino = true;
                    umaOrigem = umDestino;
                    valor = 0;
                    while (umaOrigem != linha->item.paradas.primeiro){
                        if (umaOrigem->item.cidade == cidadeOrigem){
                            Origem = true;
                            system("cls");
                            imprimeItemRecebido(linha->item);
                            cout << endl;
                            cout << "Preço da passagem: " << valor << endl;
                            cout << "Horário de saída: " << umaOrigem->item.horarioSaida << endl;
                            cout << "Horário de chegada: " << umDestino->item.horarioChegada << endl << endl;
                            rotas++;
                        }
                        valor += umaOrigem->item.passagem;
                        umaOrigem = umaOrigem->ant;
                    }
                }
                umDestino = umDestino->prox;
            }
            linha = linha->prox;
        }
        if(!Origem){
            cout << "\nOrigem inexistente.\n\n";
        }
        if(!Destino){
            cout << "\nDestino inexistente.\n\n";
        }
        if(rotas == 0 && !Origem && !Destino){
            cout << "\nLinha inexistente.\n\n";
        }
        system("pause");
        system("cls");
        return;
    }

    if(op == 2){
        int id;
        cout << "Informe o codigo da linha: ";
        cin >> id;

        Apontador aux = pesquisaItem(linhas, id);

        if(aux == NULL){
            cout << "Não possui essa linha";
            cout << endl;
            return;
        }
        imprimeItemRecebido(aux->item);
        cout << endl;

        cout << "Cidades: " << endl;
        imprimeListaDupla(&aux->item.paradas);
        system("pause");
        system("cls");
    }
    if(op == 3){
        return;
    }
}

void criarLinha(tipoLista *linhas, int *id){
    tipoItem item;
    item.id = *id;

    cout << "Informe o nome da companhia que deseja adcionar: ";
    cin >> item.companhia;

    cout << "Insira o nome (código) da linha: ";
    cin >> item.linha;

    cout << "\n\nLinha criada.\n\n";

    criarListaVaziaDupla(&item.paradas);
    insereListaUltimo(linhas, &item);

    *id = *id + 1;
}

void criarParada(tipoLista *linhas){
    int id;

    cout << "Informe o ID que sera adcionado na parada: ";
    cin >> id;

    Apontador aux = pesquisaItem(linhas, id);
    while(aux == NULL){
        cout << "Nenhuma linha encontrada." << endl << endl;
    }

    tipoItemDupla parada;

    parada.id = aux->item.idStop;
    aux->item.idStop++;

    cout << "Informe o codigo da cidade: ";
    cin >> parada.cidade;
    cout << "Informe o horario de chegada: ";
    cin >> parada.horarioChegada;
    cout << "Informe o horário saida: ";
    cin >> parada.horarioSaida;
    cout << "Informe o valor da passagem: ";
    cin >> parada.passagem;

    if(verificaListaVaziaDupla(&aux->item.paradas)){
        cout << "Linha nao contem paradas." << endl;
        cout << "A parada foi inserida." << endl;

        insereListaUltimoDupla(&aux->item.paradas, parada);

        return;
    }
    imprimeListaDupla(&aux->item.paradas);

    cout << "Onde deseja incluir a parada? (Digite ''0'' para inserí-la no início).\n";
    cout << "ID: ";
    cin >> id;

    if(id == 0){
        insereListaPrimeiroDupla(&aux->item.paradas, parada);
        cout << "\nParada inserida.\n\n";
        return;
    }
    insereAposElementoDupla(&aux->item.paradas, parada, id);
}

void mudarParada(tipoLista *linhas){
    int id;

    cout << "Insira o ID da linha à qual deseja alterar uma parada: ";
    cin >> id;

    Apontador aux;
    aux = pesquisaItem(linhas, id);

    if(aux == NULL){
        cout << "Não existe essa linha no nosso registro!" << endl;
        return;
    }

    if(verificaListaVaziaDupla(&aux->item.paradas)){
        cout << "Não contem parada nessa linha!" << endl;
        return;
    }

    imprimeListaDupla(&aux->item.paradas);

    cout << "Codigo da Parada que deseja alterar: ";
    cin >> id;

    ApontadorDupla aux1;
    aux1 = localizaIDDupla(&aux->item.paradas, id);

    if(aux1 == NULL){
        cout << "Não contem parada nessa linha!" << endl;
        return;
    }

    cout << "Dados alterados!" << endl;

    imprimeItemDupla(aux1->item);

    cout << "Informe o codigo da cidade: ";
    cin >> aux1->item.cidade;
    cout << "Informe o horario em que o onibus chegara na cidade: ";
    cin >> aux1->item.horarioChegada;
    cout << "Informe o horário em que o ônibus saira da cidade: ";
    cin >> aux1->item.horarioSaida;
    cout << "Informe o valor da passagem: ";
    cin >> aux1->item.passagem;
}

void excluirParada(tipoLista *linhas){
    int id;

    cout << "Informe o codigo da linha que deseja remover uma parada: ";
    cin >> id;

    Apontador aux;
    aux = pesquisaItem(linhas, id);

    if(aux == NULL){
        cout << "Não existe essa linha no nosso registro!" << endl;
        return;
    }

    if(verificaListaVaziaDupla(&aux->item.paradas)){
        cout << "Não contem parada nessa linha!" << endl;
        return;
    }

    imprimeListaDupla(&aux->item.paradas);

    cout << "Codigo da parada que deseja remover: ";
    cin >> id;

    ApontadorDupla aux1 = localizaIDDupla(&aux->item.paradas, id);

    if(aux1 == NULL){
        cout << "Não contem parada nessa linha!" << endl;
        return;
    }

    retiraIDDupla(&aux->item.paradas, id);
    cout << "Parada removida da linha!" << endl << endl;
}

void excluirLinha(tipoLista *linhas){
    int id;

    cout << "Informe o codigo da linha: ";
    cin >> id;

    Apontador aux;
    aux = pesquisaItem(linhas, id);

    if(aux == NULL){
        cout << "Essa linha não existe no nosso registro!" << endl;
        return;
    }

    removeItemPorId(linhas, id);
    cout << "Linha removida com sucesso!" << endl;
}

void alteracaoCompleta(tipoLista *linhas, int *id){
    int op;

    while(op != 6){
        cout << "1- Inserir uma nova linha" << endl;
        cout << "2- Inserir uma nova parada na linha" << endl;
        cout << "3- Altere uma parada" << endl;
        cout << "4- Elimine uma parada" << endl;
        cout << "5- Elimine uma linha" << endl;
        cout << "6- Voltar" << endl;
        cout << "Escolha: ";

        cin >> op;

        cout << endl << endl;

        switch (op){
            case 1:
                system("cls");
                criarLinha(linhas, id);
                break;

            case 2:
                system("cls");
                criarParada(linhas);
                break;

            case 3:
                system("cls");
                mudarParada(linhas);
                break;

            case 4:
                system("cls");
                excluirParada(linhas);
                break;

            case 5:
                system("cls");
                excluirLinha(linhas);
                break;

            default:
                break;
        }
        system("pause");
        system("cls");
    }
}
#include <stdio.h>
#include <stdlib.h>

#ifndef INCLUDE_LISTABASE
#include "lista_base.hpp"
#endif

#define INCLUDE_LISTA_DESORDENADA

class ListaDesordenada : protected ListaBase{
    public:
        using ListaBase::Criar;
        using ListaBase::imprimirInfo;

        // O(n)
        void InserirNoInicio(int id, int valor){
            if(!VerificacaoAptoInserir()) return;

            for(int x = qtdLista; x > 0; x--)
                lista[x] = lista[x-1];
            lista[0] = Elemento(id, valor);
            qtdLista++;
        }

        // O(1)
        void InserirNoFinal(int id, int valor){
            if(!VerificacaoAptoInserir()) return;

            lista[qtdLista] = Elemento(id, valor);
            qtdLista++;
        }

        // O(n)
        int BuscarPeloId(int id) const {
            for(int x = 0; x < qtdLista; x++)
                if(lista[x].getID() == id) return x;
            return -1;
        }

        // O(n)
        void RemoverPeloId(int id){
            int pos = BuscarPeloId(id);
            lista[pos] = lista[qtdLista-1];
            qtdLista--;
        }

        void Menu(){
            int id, valor;

            int escolha = 0;
            while(escolha != -1){
                printf("\nMenu de Lista Nao Ordenada\n");
                printf("---------------\n");
                printf(" 1 - Inserir valor no inicio\n");
                printf(" 2 - Inserir valor no final\n");
                printf(" 3 - Remover valor\n");
                printf(" 4 - Imprimir lista\n");
                printf("---------------\n");
                printf("-1 - Sair\n");
                printf("---------------\n");
                printf("Digite sua escolha: ");

                scanf("%i", &escolha);
                printf("\n");

                switch(escolha){
                    case 1: 
                        printf("Digite os valores...\n");
                        printf("id: ");
                        scanf("%i", &id);
                        printf("valor: ");
                        scanf("%i", &valor);
                        InserirNoInicio(id, valor);
                        break;
                    case 2: 
                        printf("Digite os valores...\n");
                        printf("id: ");
                        scanf("%i", &id);
                        printf("valor: ");
                        scanf("%i", &valor);
                        InserirNoFinal(id, valor);
                        break;
                    case 3:
                        imprimirInfo();
                        printf("Digite o valor do id: ");
                        scanf("%i", &id);
                        RemoverPeloId(id);
                        break;
                    case 4:
                        imprimirInfo();
                        break;
                }
            }
        }
};
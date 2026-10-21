#include <stdio.h>
#include <stdlib.h>

#ifndef INCLUDE_LISTA_DESORDENADA
#include "lista_nao_ordenada.hpp"
#endif

class Pilha : private ListaDesordenada{
    public:
        using ListaBase::Criar;
        using ListaBase::VerificarCheio;
        using ListaBase::VerificarVazio;
        using ListaBase::imprimirInfo;

        // O(1)
        void empilhar(int id, int valor) { 
            if(!VerificacaoAptoInserir()) return;

            InserirNoFinal(id, valor); 
        }

        // O(1)
        Elemento consultarTopo(){
            return lista[qtdLista-1]; 
        }

        // O(1)
        Elemento desempilhar(){
            class Elemento elemento = consultarTopo();
            RemoverUltimo();
            return elemento;
        }

        void Menu(){
            int id, valor;

            int escolha = 0;
            while(escolha != -1){
                printf("\nMenu de Pilha\n");
                printf("---------------\n");
                printf(" 1 - Empilhar\n");
                printf(" 2 - Desempilhar\n");
                printf(" 3 - Consultar topo\n");
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
                        empilhar(id, valor);
                        break;
                    case 2: 
                        if(VerificarVazio()){
                            printf("Pilha vazia\n");
                            break;
                        }
                        printf("Elemento desempilhado: \n");
                        printf("Id | Valor\n");
                        desempilhar().imprimirInfo();
                        break;
                    case 3:
                        if(VerificarVazio()){
                            printf("Pilha vazia\n");
                            break;
                        }
                        printf("Elemento do topo: \n");
                        printf("Id | Valor\n");
                        consultarTopo().imprimirInfo();
                        break;
                    case 4:
                        imprimirInfo();
                        break;
                }
            }
        }
};
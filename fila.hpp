#include <stdio.h>
#include <stdlib.h>

#ifndef INCLUDE_LISTA_DESORDENADA
#include "lista_nao_ordenada.hpp"
#endif

class Fila : private ListaDesordenada{
    public:
        using ListaBase::Criar;
        using ListaBase::VerificarCheio;
        using ListaBase::VerificarVazio;
        using ListaBase::imprimirInfo;

        // O(1)
        Elemento consultarProximo(){
            return lista[0];
        };

        // O(n)
        Elemento RetirarFila(){
            class Elemento elemento = consultarProximo();
            RemoverPrimeiro();
            return elemento;
        }

        // O(1)
        void AdicionarFila(int id, int valor){
            if(!VerificacaoAptoInserir()) return;

            InserirNoFinal(id, valor);
        }

        void Menu(){
            int id, valor;

            int escolha = 0;
            while(escolha != -1){
                printf("\nMenu de Fila\n");
                printf("---------------\n");
                printf(" 1 - Adicionar a fila\n");
                printf(" 2 - Retirar da fila\n");
                printf(" 3 - Consultar proximo\n");
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
                        AdicionarFila(id, valor);
                        break;
                    case 2: 
                        if(VerificarVazio()){
                            printf("Fila vazia\n");
                            break;
                        }
                        printf("Elemento retirado: \n");
                        printf("Id | Valor\n");
                        RetirarFila().imprimirInfo();
                        break;
                    case 3:
                        if(VerificarVazio()){
                            printf("Fila vazia\n");
                            break;
                        }
                        printf("Elemento do topo: \n");
                        printf("Id | Valor\n");
                        consultarProximo().imprimirInfo();
                        break;
                    case 4:
                        imprimirInfo();
                        break;
                }
            }
        }
};
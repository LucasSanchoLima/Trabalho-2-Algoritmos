#include <stdio.h>
#include <stdlib.h>

#ifndef INCLUDE_LISTABASE
#include "lista_base.hpp"
#endif

#define INCLUDE_LISTA_ORDENADA

class ListaOrdenada : protected ListaBase{
   
    public:
        using ListaBase::Criar;
        using ListaBase::imprimirInfo;

        // O(log(n))
        int BuscarPeloId(int id) const {

            if(VerificarVazio()){
                return 0;
            }

            int meio, valor, inicio, fim;
            inicio = 0;
            fim = qtdLista;

            while(inicio != fim){
                meio = inicio + ((fim - inicio)/2);
                valor = lista[meio].getID();
                if(valor == id) return meio;
                if(valor < id) inicio = meio + 1;
                else fim = meio - 1;
            }

            return inicio;
        }

        // O(n)
        void Inserir(int id, int valor){
            if(!VerificacaoAptoInserir()) return;

            int pos = BuscarPeloId(id);
            if(lista[pos].getID() == id){
                printf("\nFalha ao inserir id: %i\nId já inserido\n", id);
                return;   
            }

            for(int x = qtdLista; x > pos; x--)
                lista[x] = lista[x-1];

            lista[pos] = Elemento(id, valor);

            qtdLista++;
        }

        // O(n)
        void RemoverPeloId(int id){
            int pos = BuscarPeloId(id);

            for(int x = pos; x < qtdLista; x++)
                lista[x] = lista[x+1];
            qtdLista--;
        }

        void Menu(){
            int id, valor;

            int escolha = 0;
            while(escolha != -1){
                printf("\nMenu de Lista Ordenada\n");
                printf("---------------\n");
                printf(" 1 - Inserir valor\n");
                printf(" 2 - Remover valor\n");
                printf(" 3 - Imprimir lista\n");
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
                        Inserir(id, valor);
                        break;
                    case 2:
                        imprimirInfo();
                        printf("Digite o valor do id: ");
                        scanf("%i", &id);
                        RemoverPeloId(id);
                        break;
                    case 3:
                        imprimirInfo();
                        break;
                }
            }
        }

};

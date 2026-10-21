#include <stdio.h>
#include <stdlib.h>

#ifndef INCLUDE_ELEMENTO
#include "elemento.hpp"
#endif

#define INCLUDE_LISTABASE;

class ListaBase{
    protected:
        class Elemento * lista;
        int qtdMaximaLista;
        int qtdLista;

    public:
        int getQtdLista()       const { return qtdLista; }
        int getQtdMaximaLista() const { return qtdMaximaLista; }
        virtual int BuscarPeloId(int id) const = 0;

        void Criar(int qtdMax){
            lista = (class Elemento *)malloc(qtdMax * sizeof(class Elemento));
            qtdMaximaLista = qtdMax;
            qtdLista = 0;
        }

        void imprimirInfo() const{
            printf(" Pos | Id | Valor\n");
            for(int x = 0; x < qtdLista; x++){
                printf(" %3i | ", x);
                lista[x].imprimirInfo();
            }
        }

        // O(n)
        void RemoverPrimeiro(){
            if(VerificarVazio()) return;

            for(int x = 0; x < qtdLista; x++)
                lista[x] = lista[x+1];
            qtdLista--;
        }

        // O(1)
        void RemoverUltimo(){
            qtdLista--;
        }

        // O(n) ou O(log(n))
        void AlterarPeloId(int id, int novoValor){
            int pos = BuscarPeloId(id);

            lista[pos].putValor(novoValor);
        }

        // O(1)
        bool VerificarVazio() const{
            if(qtdLista == 0)
                return true;
            return false;
        }

        // O(1)
        bool VerificarCheio() const{
            if(qtdLista == qtdMaximaLista)
                return true;
            return false;
        }

        bool VerificacaoAptoInserir(){
            if(VerificarCheio()){
                printf("\nNao foi possivel inserir, lista cheia\n");
                return false;
            }
            return true;
        }
    };


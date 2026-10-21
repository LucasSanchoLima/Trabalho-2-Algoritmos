#include <stdio.h>
#include <stdlib.h>

#include "lista_ordenada.hpp"
#include "lista_nao_ordenada.hpp"
#include "pilha.hpp"
#include "fila.hpp"

int main(){
    class ListaOrdenada listaOrd;
    class ListaDesordenada listaDes;
    class Pilha pilha;
    class Fila fila;

    int tamanho;
    printf("Digite o tamanho das listas: ");
    scanf("%i", &tamanho);

    listaDes.Criar(tamanho);
    listaOrd.Criar(tamanho);
    pilha.Criar(tamanho);
    fila.Criar(tamanho);

    int escolha = 0;
    while(escolha != -1){
        printf(" 1 - Lista Ordenada\n");
        printf(" 2 - Lista Nao Ordenada\n");
        printf(" 3 - Pilha\n");
        printf(" 4 - Fila\n");
        printf("----------\n");
        printf("-1 - Sair\n");
        printf("----------\n");
        
        printf("Digite sua escolha: ");
        scanf("%i", &escolha);

        switch(escolha){
            case 1: listaOrd.Menu();
                    break;
            case 2: listaDes.Menu();
                    break;
            case 3: pilha.Menu();
                    break;
            case 4: fila.Menu();
                    break;
        }
    }

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

class ElementoBase{
    protected: 
        int ID;
    public:
        int getID() const { return ID; }
        void putID(int id) { ID = id; }
        // virtual void imprimirInfo() = 0;
};

class Elemento : public ElementoBase{
    private:
        int valor;

    public:
        Elemento(int id, int val){
            putID(id);
            valor = val;
        }

        void putValor(int val) { valor = val; }
        int  getValor() const  { return valor; }

        void imprimirInfo(){
            printf("%i | %i\n", ID, valor);
        }
};

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
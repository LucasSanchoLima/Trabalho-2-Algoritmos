#include <stdio.h>
#define INCLUDE_ELEMENTO

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
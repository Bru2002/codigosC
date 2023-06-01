#include <stdio.h>
#include <stdlib.h>
//#include <ncurses.h>

#define MAXPILHA 100

struct testaPilha
{
    int topo;
    int elem[MAXPILHA];

};

void inicPilha(struct testaPilha *pp)
{
   pp->topo = -1;
}

//testa se a pilha esta vazia ou não 1 ou 0

int pilhaVazia(struct testaPilha *pp)
{

    if(pp->topo == -1)
        return (1);
    else
        return (0);
}

int pilhaCheia(struct testaPilha *pp)
{
    if(pp->topo == MAXPILHA-1)
        return(1);
    else
        return(0);

}
void insElem(struct testaPilha *pp, int x)
{
    pp->topo++;
    pp->elem[pp->topo] = x;

}

void remElem(struct testaPilha *pp)
{
    pp->topo--;
}

void mostraPilha(struct testaPilha *pp)
{
    int i;
    printf("\n");
    for(i=pp->topo; i>=0; i--)
        printf("\n %i  ", pp->elem[i]);

}

int vetor(int x){
    int numero[15] = {10, 20, 30, 40, 58, 45, 66, 32, 45, 22, 11, 24, 45, 88, 56};

    return numero[x];
}

int main()
{
    struct testaPilha p;
    int x = -1, numero;
    inicPilha(&p);
    do{
        x++;
        numero = vetor(x);
        printf("%i -", numero);

        if(numero%2 == 0)
        {
            insElem(&p, numero);
        }
        else{
            if(pilhaVazia(&p) == 1)
            {
                printf("UNDERFLOW");
            }
            else
            {
                remElem(&p);
            }
        }

    }while (x < 14);

    mostraPilha(&p);

}

#include <stdio.h>
#include <stdlib.h>
//#include <ncurses.h>

#define MAXPILHA 100

struct testaPilha2
{
    int topo;
    int elem[MAXPILHA];
};

void inicPilha(struct testaPilha2 *pp)
{
   pp->topo = -1;
}


int pilhaVazia(struct testaPilha2 *pp)
{
    if(pp->topo == -1)
        return (1);
    else
        return (0);
}

int pilhaCheia(struct testaPilha2 *pp)
{
    if(pp->topo == MAXPILHA-1)
        return(1);
    else
        return(0);

}
void insElem(struct testaPilha2 *pp, int x)
{
    pp->topo++;
    pp->elem[pp->topo] = x;

}

void remElem(struct testaPilha2 *pp)
{
    pp->topo--;
}

void mostraPilha(struct testaPilha2 *pp)
{
    int i;
    printf("\n");
    for(i=pp->topo; i>=0; i--)
        printf("\t%i\n", pp->elem[i]);

}
int menu(){
    int opcao;

    printf("\n\n===== MENU  ===== \n\n");
    printf("0 - SAIR \n");
    printf("1 - INSERIR \n");
    printf("2 - EXCLUIR \n");
    printf("3 - MOSTRAR O CONTEUDO DA PILHA \n");
    printf("4 - ESVAZIAR PILHA \n");
    printf("\n O que deseja fazer? ");
    scanf("%d", &opcao);

    return opcao;
}

int main()
{
    struct testaPilha2 *p;
    struct testaPilha2 *n;

    int a = 0;
    int b = 0;
    int opcao_selecionada, x;
    inicPilha(&p);
    inicPilha(&n);
    do{
        opcao_selecionada = menu();
        switch(opcao_selecionada){
            case 0: break;
            case 1:
                if(pilhaCheia(&p)== 1)
                {
                    printf("\n OVERFLOW");
                    break;

                }else
                {
                    printf("\n Entre com um valor a ser inserido:");
                    scanf("%d", &x);

                    if (x > 0) {
                        insElem(&p, x);
                    } else if (x < 0) {
                        insElem(&n, x);
                    } else {
                        remElem(&p);
                        remElem(&n);
                    }
                }
                break;
            case 2:
                if(pilhaVazia(&p) == 1)
                {
                    printf("\n UNDERFLOW \n");
                    break;
                }else
                {
                    remElem(&p);
                }break;

            case 3:

                    printf("\n*** Inicio P ***\n");
                    mostraPilha(&p);
                    printf("\n*** Final P ***\n");
                    printf("\n\n*** Inicio N ***\n");
                    mostraPilha(&n);
                    printf("\n*** Final N ***\n");
                break;

            case 4:
                inicPilha(&p);
                break;

            default:
                printf("-------- OPCAO INVALIDA ---------");

        }
    }while (opcao_selecionada > 0);



}

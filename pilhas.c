#include <stdio.h>
#include <stdlib.h>
//#include <ncurses.h>

#define MAXPILHA 100

struct pilha
{
    int topo;
    int elem[MAXPILHA];

};

void inicPilha(struct pilha *pp)
{
   pp->topo = -1;
}

//testa se a pilha esta vazia ou não 1 ou 0

int pilhaVazia(struct pilha *pp)
{

    if(pp->topo == -1)
        return (1);
    else
        return (0);
}

int pilhaCheia(struct pilha *pp)
{
    if(pp->topo == MAXPILHA-1)
        return(1);
    else
        return(0);

}
void insElem(struct pilha *pp, int x)
{
    pp->topo++;
    pp->elem[pp->topo] = x;

}

void remElem(struct pilha *pp)
{
    pp->topo--;
}

void mostraPilha(struct pilha *pp)
{
    int i;
    printf("\n");
    for(i=pp->topo; i>=0; i--)
        printf("\n %i  ", pp->elem[i]);

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
    struct pilha p;
    int opcao_selecionada, x;
    inicPilha(&p);
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
                    insElem(&p, x);
                }break;
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
                if(pilhaVazia(&p)==1)
                {
                    printf("\n UNDERFLOW \n");
                    break;
                }else
                {
                    mostraPilha(&p);
                }break;

            case 4:
                inicPilha(&p);
                break;

            default:
                printf("-------- OPCAO INVALIDA ---------");

        }
    }while (opcao_selecionada > 0);



}

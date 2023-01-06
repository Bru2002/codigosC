#include <stdio.h>
#include <stdlib.h>
#define MAXPILHA 1

// o typedef renomeia a struct, assim toda vez q for usada o tipo_elen nao necessitara usar struct elem
typedef struct elem
{
    int info;
    struct elem *lig;

}tipo_elem;

//DEFININDO UMA ESTRUTURA PARA FILA QUE DEVE CONTER STRUCT TIPO_ELEM
typedef struct fila
{
    tipo_elem *inicio;
    tipo_elem *fim;
    int tamanho;

}fila;


void cria_fila(fila *q)
{
      /*Cria uma fila vazia.Deve ser usado antes de qualquer
    outra operacao */
    q->inicio = NULL;
    q->fim = NULL;
    q->tamanho = 0;
}
int ver_fila_vazia(fila *q)
{
    if(q->inicio == NULL){
        return 1;
    }else{
        return 0;
    }

}


int inserir_elem(fila *q, int x){

    tipo_elem *p;
    p = malloc(sizeof(tipo_elem));

    if(p == NULL){
        return 0;
    }
    p->info = x;
    p->lig = NULL;

    if (ver_fila_vazia(q)) {
        q->inicio = p;
    }else{
        q->fim->lig = p;
    }
    q->fim = p;

	return 1;

}
int remove_elem(fila *q){
    tipo_elem *p;

    //recebe o 2 elem da fila
    p = q->inicio;
    q->inicio = p->lig;
    // libera o espaco da memoria
    free(p);
    /*qnd a fila tem um unico elemento o p lig seria null logo a fila estaria vazia
    porem o q->fim ainda teria o valor de q->inicio, por esse motivo esse if abaixo*/
    return 1;
    if(q->inicio == NULL){
        q->fim = NULL;
        return 0;
    }

}
int expurga(fila *q){
    tipo_elem *p;

    do{
        p = q->inicio;
        q->inicio = p->lig;
        // libera o espaco da memoria
        free(p);
    }while(p->lig != NULL);


    return 1;

    if(q->inicio == NULL){
        q->fim = NULL;
        return 0;
    }

}
void exibe_fila(fila *q){
    tipo_elem *p = q->inicio;//ponteiro recebe o q->inicio

    while(p->lig != NULL)//enquanto o apontamento for diferente de nulo
    {
        printf("%d ", p->info);//exibe o numero da fila
        p = p->lig;//atribui o p->lig do novo elemento ao ponteiro
    }
    printf("%d ", p->info);

}

int elimina_elem(fila *q, int vitima){
    tipo_elem *p = q->fim;//ponteiro recebe o q->inicio

    int temp = 0;

    if(p->lig == NULL && vitima == p->info){

    }
    else{
        do{//enquanto o apontamento for diferente de nulo

            if(p->info != vitima){
                p = p->lig;//atribui o p->lig do novo elemento ao ponteiro
                continue;
            }
            if (p->info == vitima){
                return 1;
            }
            else{
                return 0;
            }
        }while(p->lig != NULL);
    }
}
int menu(){
    int opcao;

    printf("\n\n===== MENU  ===== \n\n");
    printf("0 - SAIR \n");
    printf("1 - INSERIR \n");
    printf("2 - VERIFICA SE FILA ESTA VAZIA \n");
    printf("3 - REMOVE ELEMENTO \n");
    printf("4 - VER FILA\n");
    printf("5 - EXPURGA FILA\n");
    printf("6 - ELIMINA ELEMENTO POBI");
    printf("\n O que deseja fazer? ");
    scanf("%d", &opcao);

    return opcao;
}

int main()
{
    fila q;
    tipo_elem e;
    //envia o endereco de e = &e, que vai ser enviado o ponteiro *q
    cria_fila(&q);
    int vazio, item, res;
    int opcao_selecionada;

    do
    {
        opcao_selecionada = menu();
        switch(opcao_selecionada){
            case 0: break;
            case 1:
                printf("Digite o elem: ");
                scanf("%i", &item);
                res = inserir_elem(&q, item);

                if(res = 1){
                    printf("\n Elemento inserido \n");
                }else{
                    printf("\n Fila cheia \n");
                }
            break;

            case 2:
                vazio = ver_fila_vazia(&q);
                if(vazio == 1)
                {
                    printf("\n Fila vazia");
                }
                else
                {
                    printf("\n Fila possui elementos");
                }
            break;
            case 3:
                if(ver_fila_vazia(&q)){
                    printf("\n Desculpe!\n Fila vazia");
                }
                else
                {
                    if(remove_elem(&q)){
                        printf("\n Elemento removido");
                    }
                }

            break;
            case 4:
                if(ver_fila_vazia(&q)){
                    printf("\n Desculpe! \n Fila vazia");
                }
                else{
                    exibe_fila(&q);
                }
            break;
            case 5:
                if(ver_fila_vazia(&q)){
                    printf("\n Desculpe! \n Fila vazia");
                }
                else{
                    expurga(&q);
                    printf("\n Fila expurgada");
                }
            break;
            case 6:
                if(ver_fila_vazia(&q)){
                    printf("Desculpe fila vazia");
                }
                else
                {
                    int vitima = 0;
                    printf("\n Qual elemento sera a vitima : ");
                    scanf("%d", &vitima);

                    if(elimina_elem(&q, vitima))
                        printf("\n Elemento eliminado");
                    else
                        printf("\n Elemento NAO encontrado");

                }


            break;

        }

    }while(opcao_selecionada != 0);

    return 0;
}

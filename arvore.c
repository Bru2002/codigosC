#include <stdio.h>
#include <stdlib.h>
#define MAXPILHA 1

// o typedef renomeia a struct, assim toda vez q for usada o tipo_elen nao necessitara usar struct elem


//DEFININDO UMA ESTRUTURA PARA FILA QUE DEVE CONTER STRUCT TIPO_ELEM
 struct arvore
{
    int info;
    struct arvore *esquerda;
    struct arvore *direita;


};
int arvore_vazia(struct arvore *a)
{
  /* Retorna 1 se a árvore for vazia e 0 caso contrário */
  return a == NULL;

}
/*
void mostra_arvore(arvoreptr *a)
{
  printf("%d ", a->info);

  if(a->esquerda != NULL){
    mostra_arvore(a->esquerda);
  }

  if(a->direita != NULL){
    mostra_arvore(a->direita);
  }

 }
*/
typedef struct arvore *arvoreptr;

void pre(struct arvore *a){

    if(a != NULL){
        printf("%d ", a->info);
        pre(a->esquerda);
        pre(a->direita);
    }
}
void in(struct arvore *a){
    if(a){
        in(a->esquerda);
        printf("%d ", a->info);

        in(a->direita);
    }
}
int busca_elem(arvoreptr *a, int elem){

    if(*a == NULL){
        return 0;
    }
    else if(elem == (*a)->info){
        return 1;
    }
    else if(elem > (*a)->info){
        busca_elem((&(*a)->direita), elem);
    }
    else if (elem < (*a)->info){
        busca_elem((&(*a)->esquerda), elem);
    }
    else{
       printf("Elemento nao encontrado \n");
       return 0;
    }



}

arvoreptr  retorna_endereco(arvoreptr *a, int elem){

    if(*a == NULL){
        //return 0;
    }
    else if(elem == (*a)->info){
        return *a;
    }
    else if(elem > (*a)->info){
        busca_elem((&(*a)->direita), elem);
    }
    else if (elem < (*a)->info){
        busca_elem((&(*a)->esquerda), elem);
    }
    else{
       printf("Elemento nao encontrado \n");
       //return 0;
    }



}


int inserir_elem(arvoreptr *a, int x){


    if(*a == NULL){

        (*a) = malloc(sizeof(struct arvore));
        (*a)->info = x;
        (*a)->esquerda = NULL;
        (*a)->direita = NULL;

        return 1;
    }else{

        if((*a)->info < x){
            inserir_elem(&((*a)->direita), x);
        }
        else{
            inserir_elem(&((*a)->esquerda), x);
        }
    return 1;
    }

   return 0;
}


int menu(){
    int opcao;

    printf("\n\n===== MENU  ===== \n\n");
    printf("0 - SAIR \n");
    printf("1 - INSERIR \n");
    printf("2 - MOSTRA ARVORE PRE\n");
    printf("3 - MOSTRA ARVORE IN\n");
    printf("4 - BUSCA ELEMENTO\n");
    printf("5 - RETORNA ENDERECO\n");
    scanf("%d", &opcao);
    return opcao;
}

int main()
{
    arvoreptr no = NULL;

    int opcao_selecionada;
    int elem = 0;

    do
    {
        opcao_selecionada = menu();

        switch(opcao_selecionada){
            case 0: break;
            case 1:
                printf("Digite o elemento:\n");
                int valor;
                scanf("%d", &valor);

                inserir_elem(&no, valor);

            break;
            case 2:
                pre(no);
            break;
            case 3:
                in(no);
            case 4:

                printf("qual valor?\n");
                scanf("%d", &elem);
                if(busca_elem(&no, elem))
                    printf("Achou");
                else
                    printf("nao deu dessa vez");
            break;
            case 5:
                printf("qual valor?\n");
                scanf("%d", &elem);
                arvoreptr num = retorna_endereco(&no, elem);
                printf("endereco: %p valor: %d", num, num->info);
        }

    }while(opcao_selecionada != 0);

    return 0;
}

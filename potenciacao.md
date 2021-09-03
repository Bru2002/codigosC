# codigosC
Códigos em C 

#include <stdio.h>

int main(){

    int a, b, pot=1, i;

    printf("digite a: ");
    scanf("%d", &a);
    printf("digite b: ");
    scanf("%d", &b);
    
    for(i = 0; i < b ; i++){
        pot = pot * a;

    }

    printf("resultado %d", pot);
    return 0;
}

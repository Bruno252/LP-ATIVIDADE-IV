#include <stdio.h>
#include <stdlib.h>

struct dados{
char nome[250];
float preco;
int qnt;
};

float valorTotal(struct dados produto[]){



}


int main(){
struct dados produto[50];
int escolha;
int i=0;

printf("1 - Realizar uma compra\n");
printf("2 - Consultar estoque\n");
printf("3 - Sair do programa.\n");
scanf("%d",&escolha); 

do{

    switch(escolha){

        case 1:
            printf("Nome:");
            fgets(produto[i].nome,sizeof(produto[i].nome),stdin);

            printf("Preco:");
            scanf("%f",&produto[i].preco);

            printf("Quantidade:");
            scanf("%d",&produto[i].qnt);
            valorTotal(produto);
            
            i+1;
        break;

        case 2:
            i+1;
        break;

    
        break;

        default:
            printf("Escolha Invalida");

        break;

    }

}while(escolha!=3);
    return 0;
}
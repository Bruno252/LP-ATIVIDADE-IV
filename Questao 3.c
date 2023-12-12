#include <stdio.h>
#include <stdlib.h>
#define TAM 50

struct dados {
    char nome[250];
    float preco;
    float valorQnt;
    int qnt;
    int qntTotal;
};

void limpatudo(){
system("cls || clear");
fflush(stdin);
//setbuf(stdin,NULL);
}

void a() {
    printf("=================================\n");
}

float valorSoma(int contador,struct dados produto[]) {
    int i=contador;
       return produto[i].preco*produto[i].qnt;
    
}

int subt(int contador,struct dados produto[],int qnt) {
    int i=contador;
    return produto[i].qntTotal-=qnt;
}

float valorTotal(int contador,struct dados produto[]) {
    float soma=0;
    int i;
    for(i=0; i<contador; i++) {
        soma+=produto[i].valorQnt;
    }
    return soma;
}

void imprimir(int contador,struct dados produto[],float soma) {
    int i;
    for(i=0; i<contador; i++) {
        a();
        printf("Nome do Produto:%s",produto[i].nome);
        printf("Valor do Produto:%.2f\n",produto[i].preco);
        printf("Quantidade retirada do estoque:%d\n",produto[i].qnt);
        printf("Valor por Quantidade:%.2f\n",produto[i].valorQnt);
        a();
    }
    printf("Valor Total:%.2f",soma);
}

void imprimirEstoque(int contador,struct dados produto[]) {
    int i;
    for(i=0; i<contador; i++) {
        printf("Nome do Produto:%s",produto[i].nome);
        printf("Quantidade no estoque:%d\n",produto[i].qntTotal);
        printf("\n");
    }
}

int main() {
    struct dados produto[TAM];
    int escolha;
    float soma=0;
    int i=0;

    do {
        a();
        printf("1 - Realizar uma compra\n");
        printf("2 - Consultar estoque\n");
        printf("3 - Sair do programa.\n");
        a();
        scanf("%d",&escolha);
        switch(escolha) {

        case 1:
            produto[i].qntTotal=25;
            fflush(stdin);
            setbuf(stdin,NULL);
            printf("\nNome:");
            fgets(produto[i].nome,sizeof(produto[i].nome),stdin);

            printf("Preco:");
            scanf("%f",&produto[i].preco);

            printf("Quantidade:");
            scanf("%d",&produto[i].qnt);

            produto[i].qntTotal=subt(i,produto,produto[i].qnt);
            produto[i].valorQnt=valorSoma(i,produto);

            i++;
            limpatudo();
            break;

        case 2:
            a();
            imprimirEstoque(i,produto);
            a();
            break;

            break;

        case 3:

            break;

        default:
            printf("Escolha Invalida");

            break;

        }

    } while(escolha!=3);
    limpatudo();
    soma=valorTotal(i,produto);
    imprimir(i,produto,soma);

    return 0;
}

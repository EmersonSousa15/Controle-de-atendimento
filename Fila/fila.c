#include "fila.h"
#include <stdio.h>
#include <stdlib.h>

#define TAM 10

 struct fila{
    int senhas[TAM];
    int inicio, qtdSenhas;
};

Fila* criarFila() {
    Fila* f = (Fila*)malloc(sizeof(Fila));

    if (f == NULL){
        printf("Erro na alocacao de memoria.\n");
        exit(1);
    }

    f->inicio = 0;
    f->qtdSenhas = 0;

    return f;
}

int filaCheia(Fila* f){
    return (f->qtdSenhas == TAM);
}
void enfileirar(Fila *f, int senha) {

    if (filaCheia(f)){
        printf("A fila esta cheia!\n");

    }else{
        int fim = (f->inicio + f->qtdSenhas) % TAM;
        f->senhas[fim] = senha;
        f->qtdSenhas++;
    }

}

int desenfileirar(Fila *f) {
    if(filaVazia(f)){
        printf("Fila vazia!\n");

    }else{
        int senha = f->senhas[f->inicio];

        f->inicio = (f->inicio + 1) % TAM;
        f->qtdSenhas--;
        
        return senha;
    }
    
}

void visualizarFila(Fila *f) {
    if (filaVazia(f)) {
        printf("A fila esta vazia.\n");


    } else {
        for (int i = 0; i < f->qtdSenhas; i++) {
            printf("%d -> ", f->senhas[(f->inicio + i) % TAM]);
        }
        printf("FIM \n");
    }
}

int filaVazia(Fila *f) {
    return (f->qtdSenhas <= 0);
}


void liberaFila(Fila *p){
    free(p);
}
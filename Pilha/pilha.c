#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
    char tipo;
    int senha;
    struct lista *prox;
} Lista;


struct pilha {
    Lista* topo;
};

Pilha* criarPilha(){
    Pilha* p = (Pilha*) malloc(sizeof(Pilha));

    if (p == NULL) {
        printf("Erro na alocacao de memoria.\n");
        exit(1);
    }

    p->topo = NULL;
    
    return p;
}

void empilhar(Pilha *p, int senha, char tipo){

    Lista *novo = (Lista*) malloc(sizeof(Lista));
    novo->senha = senha;
    novo->tipo = tipo;
    novo->prox = p->topo;

    p->topo = novo;
}

int desempilhar(Pilha *p){
    if (pilhaVazia(p))
    {
        printf("A pilha esta vazia!\n");
    }else{
        Lista* aux = p->topo;
        int senha = aux->senha;

        p->topo = aux->prox;

        aux = NULL;
        free(aux);
        return senha;
    }
    
}

void visualizarPilha(Pilha *p){
    if(pilhaVazia(p)){
        printf("Sem ultimas chamadas!\n");
    }else{
        printf("Ultimas chamadas: \n");
        Lista *q;
        for(q = p->topo; q != NULL; q = q->prox){
            if (q->tipo == 'p')
            {
                printf("( %d - Prioritaria ) -> ", q->senha);
            }
            else if (q->tipo == 'n')
            {
                printf("( %d - Normal ) -> ", q->senha);
            }
            else
            {
                printf("Tipo indefinido!");
            }
            
            
        }  
        printf("FIM \n");
    }
    
}

int pilhaVazia(Pilha *p){
    return (p->topo == NULL);
}

void liberaPilha(Pilha *p){
    while(!pilhaVazia(p)){
        desempilhar(p);
    }
    free(p);
}
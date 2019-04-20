//
// Created by Pedro António on 30-03-2019.
//
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
typedef struct nodo {
    int valor;
    struct nodo *esq, *dir;
} *ABin;

typedef struct lligada {
    int valor;
    struct lligada *prox;
} *LInt;

// QUESTAO 1
int length (LInt l){
    int i;
    for (i = 0; l != NULL; i++, l= l->prox);

    return i;
}

// QUESTAO 2
void freeL (LInt l) {
    LInt ant;

    while (l != NULL) {
        ant = l;
        l = l->prox;
        free(ant);
    }
}

// QUESTAO 3
void imprimeL (LInt l) {
    while (l != NULL) {
        printf("O valor desta célula é: %d\n", l->valor)
        l = l->prox;
    }
}

// QUESTAO 4
LInt reverseL (LInt l){
    LInt ant = NULL, aux = l;
    while (aux != NULL) {
        l = aux;
        aux = aux->prox;
        l -> prox = ant;
        ant = l;
    }

    return l;
}

// QUESTAO 5
void insertOrd (LInt *l, int x){
    LInt ant = NULL, novo = newLInt(x,NULL), l1 = *l;

    while (l1 != NULL && l1->valor <= x) {
        ant = l1;
        l1 = l1->prox;
    }

    if (ant == NULL) {
        novo -> prox = *l;
        *l = novo;
    } else {
        ant -> prox = novo;
        novo -> prox = l1;
    }
}

// QUESTAO 6
int removeOneOrd (LInt *l, int x){
    LInt aux = *l, ant = NULL;
    int sucesso = 0;

    while (aux != NULL && aux -> valor != x) {
        ant = aux;
        aux = aux->prox;
    }

    if (aux != NULL) {
        if (ant == NULL)
            *l = (*l)->prox;
        else {
            ant -> prox = aux->prox;
        }
    } else sucesso = 1;

    return sucesso;
}

// QUESTAO 7
void merge (LInt *r, LInt l1, LInt l2){
    LInt re;

    if (l1 == NULL) {
        *r = l2;
    } else if (l2 == NULL) {
        *r == l1;
    } else {
        if (l1 -> valor > l2 -> valor) {
            re = *r = l2;
            l2 = l2->prox;
        } else {
            re = *r = l1;
            l1 = l1->prox;
        }

        while (l1 != NULL && l2 != NULL) {
            if (l1 -> valor > l2->valor) {
                re -> prox = l2;
                l2 = l2->prox;
            } else {
                re -> prox = l1;
                l1 = l1->prox;
            }
            re = re->prox;
        }

        if (l1 == NULL)
            re->prox = l2;
        else
            re->prox = l1;
    }
}

// QUESTAO 8
void splitQS (LInt l, int x, LInt *mx, LInt *Mx){
    LInt maiores = NULL, menores = NULL;

    while (l != NULL) {
        if (l -> valor < x) {
            if (menores == NULL) {
                *mx = l;
                menores = *mx;
            } else {
                menores -> prox = l;
                menores = menores->prox;
            }
            l = l->prox;
            menores -> prox = NULL;
        } else {
            if (maiores == NULL) {
                *Mx = l;
                maiores = *Mx;
            } else {
                maiores -> prox = l;
                maiores = maiores->prox;
            }
            l = l -> prox;
            maiores -> prox = NULL;
        }
    }
}

// QUESTAO 9
LInt parteAmeio (LInt *l){
    LInt aux, y = NULL, res = NULL;
    int length = 0;

    for (aux = *l; aux != NULL; aux = aux->prox)
        length++;

    length = length/2;

    while (length > 0) {
        if (y == NULL) {
            y = *l;
            *l = (*l)->prox;
            y -> prox = NULL;
            res = y;
        } else {
            y -> prox = *l;
            *l = (*l)->prox;
            y = y->prox;
        }
        y->prox = NULL;
        length--;
    }
    return res;
}

// QUESTAO 10
int removeAll (LInt *l, int x){
    LInt ant = NULL;
    LInt aux = *l;
    int conta = 0;

    while (aux != NULL) {
        if (aux -> valor == x) {
            if (ant == NULL) {
                *l = (*l)->prox;
                aux = *l;
            } else {
                ant -> prox = aux -> prox;
                aux = aux -> prox;
            }
            conta++;
        } else {
            ant = aux;
            aux = aux->prox;
        }
    }
    return conta;
}

// QUESTAO 11
int removeDups (LInt *l){
    LInt inicio = *l;
    LInt ant = inicio, aux = NULL;
    int conta = 0;

    if ((*l) -> prox != NULL) {
        aux = (*l)->prox;
        while (inicio != NULL) {
            aux = inicio->prox;
            ant = inicio;
            while (aux != NULL) {
                if (inicio -> valor == aux -> valor) {
                    ant -> prox = aux -> prox;
                    conta++;
                } else {
                    ant = aux;
                }
                aux = aux->prox;
            }
            inicio = inicio->prox;
        }
    }
    return conta;
}

// QUESTAO 12
int removeMaiorL (LInt *l){
    LInt aux = *l, ant = NULL;
    int maior = aux-> valor;

    while (aux != NULL) {
        if (aux -> valor > maior)
            maior = aux->valor;

        aux = aux->prox;
    }

    aux = *l;
    while (aux -> valor != maior) {
        ant = aux;
        aux = aux->prox;
    }

    if (ant == NULL)
        *l = (*l)->prox;
    else ant -> prox = aux -> prox;

    return maior;
}

// QUESTAO 13
void init (LInt *l){
    LInt aux = *l, ant = NULL;

    while ( aux -> prox != NULL) {
        ant = aux;
        aux = aux -> prox;
    }

    if (ant != NULL) {
        ant -> prox = aux -> prox;
        free(aux);
    } else {
        *l = NULL;
        free(*l);
    }
}

// QUESTAO 14
void appendL (LInt *l, int x) {
    LInt aux = *l, ant = NULL, novo = newLInt(x, NULL);

    while (aux != NULL) {
        ant = aux;
        aux = aux->prox;
    }

    if (ant == NULL)
        *l = novo;
    else
        ant->prox = novo;
}

// QUESTAO 15
void concatL (LInt *a, LInt b){
    LInt aux = *a;

    if (*a == NULL)
        *a = b;
    else {
        while (aux -> prox != NULL)
            aux = aux->prox;

        aux -> prox = b;
    }
}

// QUESTAO 16
LInt cloneL (LInt l) {
    LInt nova = NULL, aux;

    while (l != NULL) {
        if (nova == NULL) {
            nova = newLInt(l->valor, NULL);
            aux = nova;
        } else {
            aux->prox = newLInt(l->valor, NULL);
            aux = aux -> prox;
        }
    }
    return nova;
}

// QUESTAO 17
LInt cloneRev (LInt l){
    LInt nova = NULL, ant;

    while (l != NULL) {
        if (nova == NULL) {
            nova = newLInt (l->valor, NULL);
        } else {
            nova = newLInt (l-> valor, ant);
        }
        ant = nova;
        l = l->prox;
    }
    return nova;
}

// QUESTAO 18
int maximo (LInt l){
    int max = l->valor;

    while(l!=NULL) {
        if (l->valor > max)
            max = l->valor;
        l = l->prox;
    }
    return max;
}

// QUESTAO 19
int take (int n, LInt *l){
    int length = 0, contador = 0, res;
    LInt aux = *l, ant;

    while (aux != NULL) {
        length++;
        aux=aux->prox;
    }

    aux = *l;

    if (length > n) {
        res = n;
        while (n>0) {
            ant = aux;
            aux = aux->prox;
            n--;
        }

        while (aux != NULL) {
            ant ->prox = NULL;
            ant = aux;
            aux = aux->prox;
            free(ant);
        }
    } else res = length;

    return res;
}

// QUESTAO 20
int drop (int n, LInt *l){
    LInt aux = *l, ant = NULL;
    int length = 0, res;

    while (aux != NULL) {
        length++;
        aux = aux->prox;
    }

    aux = *l;

    if (n > length)
        res = length;
    else res = n;

    while (*l != NULL && n != 0) {
        ant = *l;
        *l = (*l)->prox;
        free(ant);
        n--;
    }
    return res;
}

// QUESTAO 21
LInt NForward (LInt l, int N){
    LInt aux = l;

    while (N >1) {
        aux = aux->prox;
        N--;
    }
    return aux->prox;
}

// QUESTAO 22
int listToArray (LInt l, int v[], int N){
    int i;

    for (i = 0; l!= NULL && N>0; i++, N--, l=l->prox)
        v[i] = l->valor;

    return i;
}

// QUESTAO 23
LInt arrayToList (int v[], int N){
    LInt nova = NULL,aux;
    int i;

    for (i = 0; N>0; N--, i++) {
        if (nova == NULL) {
            nova = newLInt(v[i],NULL);
            aux = nova;
        } else {
            aux->prox = newLInt(v[i],NULL);
            aux = aux->prox;
        }
    }

    return nova;
}

// QUESTAO 24
LInt somasAcL (LInt l) {
    int i, conta = 0;
    LInt nova = NULL, aux=l, somatorio, aux2;

    for (i = 0; aux!=NULL; i++, aux=aux->prox) {
        if(nova == NULL) {
            nova = newLInt(l->valor,NULL);
            somatorio = nova;
        } else {
            somatorio->prox = newLInt(0,NULL);
            somatorio = somatorio->prox;
            aux2 = l;
            conta = 0;

            while(conta <= i) {
                conta++;
                somatorio->valor+=aux2->valor;
                aux2=aux2->prox;
            }
        }
    }
    return nova;
}

// QUESTAO 25
void remreps (LInt l){
    LInt aux, ant = l,libertador;

    if(l!= NULL && l->prox!=NULL) {

        for(aux = l->prox; aux!= NULL; aux=aux->prox) {
            if(ant->valor != aux ->valor) {
                ant->prox = aux;
                ant = aux;
            } else {
                libertador = aux;
                ant ->prox = NULL;
                free(libertador);
            }
        }
    }
}

// QUESTAO 26
LInt rotateL (LInt l){
    LInt aux = l, ant;

    if (l!=NULL && l->prox!=NULL) {
        ant = l;
        l=l->prox;
        aux = l;

        while(aux->prox!=NULL)
            aux = aux->prox;

        aux->prox = ant;
        ant->prox = NULL;
    }

    return l;
}

// QUESTAO 27
LInt parte (LInt l){
    LInt ant = NULL, aux = l, nova = NULL, aux2;
    int i;

    for (i = 1; aux != NULL; i++) {
        if (i % 2 == 1) {
            if (ant == NULL)
                ant = aux;
            else {
                ant -> prox = aux;
                ant = ant->prox;
            }
            aux = aux->prox;
            ant -> prox = NULL;
        } else {
            if (nova == NULL) {
                nova = aux;
                aux = aux->prox;
                aux2 = nova;
            } else {
                aux2 -> prox = aux;
                aux2 = aux2->prox;
                aux = aux->prox;
            }
            aux2 -> prox = NULL;
        }
    }
    return nova;
}


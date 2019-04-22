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
    for (;l != NULL; l = l->prox)
        printf("O valor desta célula é: %d\n", l->valor;
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
    LInt ant = NULL, novo = newLInt(x,NULL), l1;

    for (l1 = *l; l1 != NULL && l1->valor <= x; l1 = l1->prox)
        ant = l1;

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
    LInt aux, ant = NULL;
    int sucesso = 0;

    for (aux = *l; aux != NULL && aux -> valor != x; aux = aux->prox)
        ant = aux;

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

    if (l1 == NULL)
        *r = l2;
    else if (l2 == NULL)
        *r == l1;
    else {
        if (l1 -> valor > l2 -> valor) {
            re = *r = l2;
            l2 = l2->prox;
        } else {
            re = *r = l1;
            l1 = l1->prox;
        }

        for(;l1 != NULL && l2 != NULL; re = re->prox)
            if (l1 -> valor > l2->valor) {
                re -> prox = l2;
                l2 = l2->prox;
            } else {
                re -> prox = l1;
                l1 = l1->prox;
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
    LInt aux, nova = NULL, res = NULL;
    int length = 0;

    for (aux = *l; aux != NULL; length++, aux = aux->prox);

    for (length = length/2; length > 0; nova->prox = NULL, length--)
        if (nova == NULL) {
            nova = *l;
            *l = (*l)->prox;
            res = nova;
        } else {
            nova -> prox = *l;
            *l = (*l)->prox;
            nova = nova->prox;
        }

    return res;
}

// QUESTAO 10
int removeAll (LInt *l, int x){
    int conta = 0;
    LInt aux, ant = NULL;

    for(aux = *l; aux != NULL; aux = aux->prox)
        if (aux -> valor == x) {
            if (ant == NULL)
                *l = aux->prox;
            else
                ant -> prox = aux->prox;
            conta++;
        } else ant = aux;

    return conta;
}

// QUESTAO 11
int removeDups (LInt *l){
    LInt inicio, aux, ant;
    int conta = 0;

    for (inicio = *l; inicio != NULL; inicio = inicio->prox)
        for (aux = inicio->prox, ant = inicio; aux != NULL; aux = aux->prox)
            if (inicio->valor == aux->valor) {
                ant -> prox = aux->prox;
                conta++;
            } else ant = aux;

    return conta;
}

// QUESTAO 12
int removeMaiorL (LInt *l){
    LInt aux, ant = NULL;
    int maior = aux-> valor;

    for (aux = *l; aux != NULL; aux = aux->prox)
        if (aux -> valor > maior)
            maior = aux->valor;

    for (aux = *l; aux -> valor != maior; ant = aux, aux = aux->prox);

    if (ant == NULL)
        *l = (*l)->prox;
    else ant -> prox = aux -> prox;

    return maior;
}

// QUESTAO 13
void init (LInt *l){
    LInt aux, ant;

    for (aux = *l, ant = NULL; aux -> prox != NULL; ant = aux, aux = aux->prox);

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
    LInt aux, ant, novo = newLInt(x, NULL);

    for (aux = *l, ant = NULL; aux != NULL; ant = aux, aux = aux->prox);

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
        for (; aux -> prox != NULL; aux = aux->prox);

        aux -> prox = b;
    }
}

// QUESTAO 16
LInt cloneL (LInt l) {
    LInt nova, aux;

    for (nova = NULL;l != NULL; l=l->prox)
        if (nova == NULL)
            aux = nova = newLInt(l->valor, NULL);
        else
            aux = aux->prox = newLInt(l->valor, NULL);

    return nova;
}

// QUESTAO 17
LInt cloneRev (LInt l){
    LInt nova, ant;

    for (nova = NULL; l != NULL; ant = nova, l=l->prox)
        if (nova == NULL)
            nova = newLInt (l->valor, NULL);
        else
            nova = newLInt (l-> valor, ant);

    return nova;
}


// QUESTAO 18
int maximo (LInt l){
    int max = l->valor;

    for (; l!=NULL; l = l->prox)
        if (l->valor > max)
            max = l->valor;

    return max;
}

// QUESTAO 19
int take (int n, LInt *l){
    LInt aux, lib = NULL;
    int c = n;

    for( aux = *l ; aux != NULL && c > 0 ; c--, aux = aux->prox)
        lib = aux;

    if(aux)
        lib->prox = NULL;

    while (aux){
        lib = aux;
        aux = aux->prox;
        free(lib);
    }
    return n-c;
}

// QUESTAO 20
int drop (int n, LInt * l) {
    LInt liberta;
    int c = 0;

    for (; *l != NULL && c < n; c++) {
        liberta = *l;
        *l=(*l)->prox;
        free (liberta);
    }

    return c;
}

// QUESTAO 21
LInt NForward (LInt l, int N){
    for (; N > 0; l = l->prox, N--);

    return l;
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
    LInt nova = NULL, aux = NULL;
    int i;

    for (i = 0; i < N; i++)
        if (aux == NULL)
            aux = nova = newLInt(v[i],NULL);
        else
            aux = aux -> prox = newLInt(v[i], NULL);

    return nova;
}

// QUESTAO 24
LInt somasAcL (LInt l) {
    LInt nova = NULL, inicio, aux, auxnova = NULL;

    for (inicio = l; inicio != NULL; inicio = inicio->prox) {
        if (auxnova == NULL)
            auxnova = nova = newLInt(0, NULL);
        else auxnova = auxnova->prox = newLInt(0, NULL);

        for (aux = l; aux != inicio->prox; aux = aux->prox)
            auxnova->valor += aux ->valor;
    }
    return nova;
}

// QUESTAO 25
void remreps (LInt l){
    LInt inicio, aux, ant, liberta;

    for (inicio = l; inicio != NULL; inicio = inicio->prox)
        for (aux = inicio->prox, ant = inicio ; aux != NULL;)
            if (inicio -> valor == aux->valor) {
                ant ->prox = aux->prox;
                liberta = aux;
                aux = aux->prox;
                free(liberta);
            } else {
                ant = aux;
                aux = aux->prox;
            }
}

// QUESTAO 26
LInt rotateL (LInt l){
    LInt aux, ant;

    if (l!=NULL && l->prox!=NULL) {
        ant = l;
        l=l->prox;

        for(aux = l;aux->prox!=NULL; aux = aux->prox);

        aux->prox = ant;
        ant->prox = NULL;
    }
    return l;
}

// QUESTAO 27
LInt parte (LInt l){
    LInt nova = NULL, ant = l, aux = l, auxnova = NULL;
    int conta = 1;

    for (aux =l; aux != NULL; conta++)
        if (conta % 2 == 1) {
            ant = aux;
            aux = aux->prox;
            ant->prox = NULL;
        } else {
            ant->prox = aux->prox;
            if (auxnova == NULL)
                auxnova = nova = newLInt(aux->valor, NULL);
            else
                auxnova = auxnova->prox = newLInt(aux->valor, NULL);
            aux = aux->prox;
        }
    return nova;
}

// QUESTAO 28
int altura (ABin a){
    if (a == NULL)
        return 0;
    else
    if (altura (a->esq) > altura (a->dir))
        return 1 + altura(a->esq);
    else
        return 1 + altura (a->dir);
}

// QUESTAO 30
void mirror (ABin * a) {
    if (*a) {
        ABin salva = (*a)->esq;
        (*a)->esq = (*a)->dir;
        (*a)->dir = salva;

        mirror (&(*a)->dir);
        mirror (&(*a)->esq);
    }
}

// QUESTAO 37
int iguaisAB (ABin a, ABin b) {
    if (a && b) {
        return (a->valor == b->valor) && iguaisAB(a->esq, b->esq) && iguaisAB(a->dir, b->dir);
    } else if (!a && !b)
        return 1;
    else return 0;
}

// QUESTAO 42
int contaFolhas (ABin a) {
    if (a) {
        if (!a->esq && !a->dir)
            return 1;
        else return contaFolhas (a->esq) + contaFolhas (a->dir);
    }
    return 0;
}

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
        printf("O valor desta célula é: %d\n", l->valor);
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
    if (!l2)
        *r = l1;
    else if (!l1)
        *r = l2;

    for (;l1 && l2; *r = &(*r)->prox)
        if (l1->valor > l2->valor) {
            *r = l2;
            l2 = l2->prox;
        } else {
            *r = l1;
            l1 = l1->prox;
        }

    if (!l1)
        *r = l2;
    else
        *r = l1;
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
    int r, ae, ad;

    if (a) {
        ae = altura(a->esq);
        ad = altura(a->dir);

        if (ae > ad)
            r = 1 + ae;
        else
            r = 1 + ad;
    } else
        r = 0;

    return r;
}

// QUESTAO 29
ABin cloneAB (ABin a) {
    ABin r;

    if (a) {
        r = malloc(sizeof(struct nodo));
        r -> valor = a->valor;
        r->esq = cloneAB(a->esq);
        r->dir = cloneAB(a->dir);
    } else r = NULL;

    return r;
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

// QUESTAO 31
void inorder (ABin a, LInt * l) {
    *l = NULL;

    if (a) {
        inorder(a->esq, l);
        while (*l) l = &(*l)->prox;

        *l = malloc(sizeof(struct nodo));
        (*l)->valor = a->valor;
        (*l)->prox = NULL;

        inorder (a->dir, &(*l)->prox);
    }
}

// QUESTAO 32
void preorder (ABin a, LInt * l) {
    *l = NULL;

    if (a) {
        *l = malloc(sizeof(struct nodo));
        (*l)->valor = a->valor;
        (*l)->prox = NULL;

        preorder(a->esq, &(*l)->prox);
        while (*l) l = &(*l)->prox;
        preorder (a->dir, l);
    }
}

// QUESTAO 33
void posorder (ABin a, LInt * l) {
    *l = NULL;
    if (a) {
        posorder(a->esq, l);
        while (*l) l = &(*l)->prox;
        posorder (a->dir, l);
        while (*l) l = &(*l)->prox;
        *l = malloc(sizeof(struct nodo));
        (*l)->valor = a->valor;
        (*l)->prox = NULL;
    }
}

// QUESTAO 34 - provavelmente rever...
int depth (ABin a, int x) {
    int res = -1, depthEsq, depthDir;

    if (a) {
        if (a->valor == x) {
            res = 1;
        } else {
            depthEsq = depth(a->esq, x);
            depthDir = depth(a->dir, x);

            if (depthEsq > 0 && depthDir > 0)
                if (depthEsq < depthDir)
                    res = 1 + depthEsq;
                else res = 1 + depthDir;
            else if (depthEsq > 0)
                res = 1 + depthEsq;
            else if (depthDir > 0)
                res = 1 + depthDir;
        }
    }
    return res;
}
// QUESTAO 35
int freeAB (ABin a) {
    int r = 0;

    if (a) {
        r += 1 + freeAB (a->esq) + freeAB(a->dir);
        free (a);
    }

    return r;
}

// QUESTAO 36
int pruneAB (ABin *a, int l) {
    int r = 0;
    ABin aux;

    if (*a)
        if (l <= 1) {
            r =  1 + pruneAB (&(*a)->esq, l-1) + pruneAB(&(*a)->dir, l-1);
            aux = (*a)->esq;
            (*a)->esq = NULL;
            free (aux);
            aux = (*a)->dir;
            (*a)->dir = NULL;
            free (aux);
        } else
            r = pruneAB(&(*a)->esq, l-1) + pruneAB(&(*a)->dir, l-1);

    return r;
}

// QUESTAO 37
int iguaisAB (ABin a, ABin b) {
    int c = 0;

    if (a && b) {
        if (a->valor == b->valor)
            c = iguaisAB(a->esq, b->esq) && iguaisAB(a->dir, b->dir);
    } else if (!a && !b)
        c = 1;

    return c;
}

// QUESTAO 38
LInt nivelL (ABin a, int n) {
    LInt l = NULL, aux;

    if (a && n>0)
        if (n > 1) {
            l = nivelL(a->esq, n-1);
            if (l) {
                for(aux = l; aux->prox != NULL; aux = aux->prox);
                aux->prox = nivelL(a->dir, n-1);
            } else
                l = nivelL(a->dir, n-1);
        } else {
            l = malloc(sizeof(struct lligada));
            l->valor = a->valor;
            l->prox = NULL;
        }

    return l;
}

// QUESTAO 39
int nivelV (ABin a, int n, int v[]) {
    int r = 0;

    if (a)
        if (n != 1) {
            r+= nivelV(a->esq,n-1,v);
            r+= nivelV(a->dir,n-1,v+r);
        } else
            v[r++] = a->valor;

    return r;
}

// QUESTAO 40
int dumpAbin (ABin a, int v[], int N) {
    int r = 0, p;
    if (a)
        if(N > 0) {
            r = dumpAbin (a->esq, v, N-1);
            v[r++] = a->valor;
            r+=dumpAbin (a->dir, v+r, N-r);
        }
    return r;
}

// QUESTAO 41
ABin somasAcA (ABin a) {
    ABin nova=NULL;

    if(a){
        nova=malloc(sizeof(struct nodo));
        nova->esq = somasAcA(a->esq);
        nova->dir = somasAcA(a->dir);
        nova->valor = a->valor;

        if(nova->esq)
            nova->valor+=nova->esq->valor;
        if(nova->dir)
            nova->valor+=nova->dir->valor;
    }

    return nova;
}

// QUESTAO 42
int contaFolhas (ABin a) {
    int r = 0;

    if (a)
        if (!a->esq && !a->dir)
            r = 1;
        else r =  contaFolhas (a->esq) + contaFolhas (a->dir);

    return r;
}

// QUESTAO 43
ABin cloneMirror (ABin a) {
    ABin nova;

    if (a) {
        nova = malloc(sizeof(struct nodo));
        nova-> valor = a->valor;
        nova->esq = cloneMirror (a->dir);
        nova->dir = cloneMirror (a->esq);
    }
    else nova = NULL;

    return nova;
}

// QUESTAO 44
int addOrd (ABin *a, int x) {
    int r = 0;

    while (*a && !r)
        if ((*a)->valor > x)
            a = &(*a)->esq;
        else if ((*a)->valor < x)
            a = &(*a)->dir;
        else r = 1;

    if (!r) {
        *a = malloc(sizeof(struct nodo));
        (*a)->valor = x;
        (*a)->esq = NULL;
        (*a)->dir = NULL;
    }
    return r;
}

// QUESTAO 45
int lookupAB (ABin a, int x) {
    int res = 0;

    while (a && x != a->valor)
        if (a->valor > x)
            a = a->esq;
        else a = a->dir;

    if (a && a->valor == x)
        res = 1;

    return res;
}

// QUESTAO 46
int depthOrd (ABin a, int x) {
    int i;

    for (i = 1; a && a->valor != x;i++)
        if (a->valor < x)
            a = a->dir;
        else
            a = a->esq;

    if (!a)
        i = -1;

    return i;
}

// QUESTAO 47
int maiorAB (ABin a) {

    while (a ->dir)
        a = a->dir;

    return a->valor;
}

// QUESTAO 48
void removeMaiorA (ABin *a) {

    if((*a)->dir)
        removeMaiorA(&(*a)->dir);
    else if ((*a)->esq)
        *a = (*a)->esq;
    else
        *a = NULL;
}

// QUESTAO 49
int quantosMaiores (ABin a, int x) {
    int r = 0;

    if (a)
        if (a->valor > x)
            r+= 1 + quantosMaiores(a->esq, x) + quantosMaiores(a->dir, x);
        else r += quantosMaiores(a->dir,x);


    return r;
}

// QUESTAO 50 - provavelmente rever, está uma caca
int comprimento (LInt l) {
    int r = 0;

    while (l) {
        r++;
        l = l->prox;
    }

    return r;
}

LInt avanca (LInt l, int p) {
    while (p > 0) {
        l = l->prox;
        p--;
    }
    return l;
}

void fromList(LInt l, ABin *a, int N) {
    int r,p;
    LInt aux;

    if (N > 0) {
        *a = malloc(sizeof(struct nodo));
        p = N/2;
        aux = avanca(l, p);
        (*a)->valor = aux->valor;
        fromList(l, &(*a)->esq, p);
        fromList(aux->prox, &(*a)->dir, N - p - 1);
    } else
        *a = NULL;
}

void listToBTree (LInt l, ABin *a) {
    int N = comprimento(l);

    fromList(l, a, N);
}

// QUESTAO 51
int seraDeProcura (ABin a, int avo, int ramo) {
    int procura = 1;
    if (a) {
        if (a->esq)
            if (ramo == 0)
                procura = procura && a->esq->valor < avo && a->esq->valor < a->valor && seraDeProcura(a->esq, a->valor,0);
            else
                procura = procura && a->esq->valor > avo && a->esq->valor < a->valor && seraDeProcura(a->esq, a->valor,0);

        if (a->dir)
            if (ramo == 0)
                procura = procura && a->dir->valor < avo && a->dir->valor > a->valor && seraDeProcura(a->dir, a->valor,1);
            else
                procura = procura && a->dir->valor > avo && a->dir->valor > a->valor && seraDeProcura(a->dir, a->valor,1);
    }
    return procura;
}

int deProcura (ABin a) {
    int procura = 1;
    if (a)
        procura = seraDeProcura (a->esq, a->valor,0) && seraDeProcura (a->dir, a->valor,1);
    return procura;
}
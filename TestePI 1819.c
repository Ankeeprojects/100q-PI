//
// Created by Pedro on 01-06-2019.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>


///////////////////////////// PARTE A /////////////////////////////////////////////////////////////////////

// Questao 1
void strrev (char s[]) {
    int i, j;
    char guarda;

    for (i = 0; s[i]; i++) ;
    i--;

    for (j = 0; j < i; j++, i--) {
        guarda = s[j];
        s[j] = s[i];
        s[i] = guarda;
    }
}

// Questao 2
int remRep (char texto []) {
    int i, j;

    for (i = 0; texto[i]; i++)
        if (texto[i] == texto[i+1]) {
            for (j = i+1; texto[j]; j++)
                texto[j] = texto[j+1];
            i--;
        }

    return i;
}

// Questao 3
void merge (int r [], int a[], int b[], int na, int nb){
    int i, j, k;
    i = j = k = 0;

    while (i < na && j < nb)
        if (a[i] > b[j]) r[k++] = b[j++];
        else r[k++] = a[i++];

    while (j < nb) r[k++] = b[j++];
    while (i < na) r[k++] = a[i++];
}

// Questao 4
int menor (ABin a, int x) {
    int res = 1;
    if (a)
        res = a->valor > x && menor (a->esq, x) && menor (a->dir, x);

    return res;
}

int maior (ABin a, int x) {
    int res = 1;
    if (a)
        res = a->valor < x && maior (a->esq, x) && maior (a->dir, x);

    return res;
}

int deProcura (ABin a) {
    int res = 1;

    if (a)
        res = maior (a->esq, a->valor) && menor (a->dir, a->valor) && deProcura (a->esq) && deProcura (a->dir);

    return res;
}

// QUESTAO 5
int pruneAB (ABin *a, int l) {
    int r = 0;
    if (*a) {
        r += pruneAB(&(*a)->esq, l-1) + pruneAB(&(*a)->dir, l-1);
        if (l <= 0) {
            r++;
            free(*a);
            *a = NULL;
        }
    }
    return r;
}


///////////////////////////// PARTE B /////////////////////////////////////////////////////////////////////
typedef struct digito {
    unsigned char val;
    struct digito *prox;
}*Num;

// Pergunta 1 a
Num fromInt (unsigned int i) {
    int valor, decresce = i, conta = 0;
    Num nova = NULL, aux = NULL;

    if (i) {
        while (decresce) {
            decresce/=10;
            conta++;
        }
        decresce = pow(10, conta-1);

        while (i) {
            valor = i;

            while (valor > 9)
                valor/=10;

            nova = malloc(sizeof(struct digito));
            nova->val = valor;
            nova->prox = aux;
            aux = nova;

            i -= valor * decresce;
            decresce /= 10;

            if (i < decresce) {
                nova = malloc(sizeof(struct digito));
                nova->val = 0;
                nova->prox = aux;
                aux = nova;
                decresce /=10;
            }
        }
    }
    return nova;
}

// Pergunta 1 b
unsigned int toInt(Num n) {
    int multiplica = 1, soma = 0;

    while (n) {
        soma += multiplica * n->val;
        n = n->prox;
        multiplica *= 10;
    }
    return soma;
}

// Pergunta 2
Num addNum (Num a, Num b) {
    Num nova = NULL, aux;
    int carry = 0, soma = 0;

    while (a && b) {
        if (!nova)
            nova = aux = malloc(sizeof(struct digito));
        else
            aux = aux->prox = malloc(sizeof(struct digito));

        soma = a->val + b->val + carry;
        carry = 0;
        if (soma > 9) {
            carry = 1;
            soma-=10;
        }

        aux->val = soma;
        aux->prox = NULL;
        a = a->prox;
        b = b->prox;
    }

    while (a) {
        if (!nova)
            nova = aux = malloc(sizeof(struct digito));
        else
            aux = aux->prox = malloc(sizeof(struct digito));

        aux->val = a->val + carry;
        aux->prox = NULL;
        carry = 0;
        a = a->prox;
    }

    while (b) {
        if (!nova)
            nova = aux = malloc(sizeof(struct digito));
        else
            aux = aux->prox = malloc(sizeof(struct digito));

        aux->val = b->val + carry;
        carry = 0;
        aux->prox = NULL;
        b = b->prox;
    }

    if (carry) {
        if (!nova)
            nova = aux = malloc(sizeof(struct digito));
        else
            aux = aux->prox = malloc(sizeof(struct digito));
        aux->val = 1;
        aux->prox = NULL;
    }
    return nova;
}

// Pergunta 3
Num mulDig (unsigned char dig, Num a) {
    Num nova = fromInt (dig * toInt(a));

    return nova;
}

// Pergunta 4
Num mulNum (Num a, Num b) {
    Num nova = fromInt ( toInt(a) * toInt(b));

    return nova;
}
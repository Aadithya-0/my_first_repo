#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int coeff;
    int exp;
} Term;

typedef struct {
    Term *terms;
    int numTerms;
} Polynomial;

void inputPolynomial(Polynomial *p) {
    printf("Enter the number of terms: ");
    scanf("%d", &p->numTerms);
    p->terms = (Term *)malloc(p->numTerms * sizeof(Term));
    for (int i = 0; i < p->numTerms; i++) {
        printf("Enter coefficient and exponent for term %d: ", i + 1);
        scanf("%d %d", &p->terms[i].coeff, &p->terms[i].exp);
    }
}

void displayPolynomial(Polynomial p) {
    for (int i = 0; i < p.numTerms; i++) {
        printf("%dx^%d", p.terms[i].coeff, p.terms[i].exp);
        if (i != p.numTerms - 1) {
            printf(" + ");
        }
    }
    printf("\n");
}

Polynomial addPolynomials(Polynomial p1, Polynomial p2) {
    Polynomial result;
    result.terms = (Term *)malloc((p1.numTerms + p2.numTerms) * sizeof(Term));
    result.numTerms = 0;

    int i = 0, j = 0;
    while (i < p1.numTerms && j < p2.numTerms) {
        if (p1.terms[i].exp > p2.terms[j].exp) {
            result.terms[result.numTerms++] = p1.terms[i++];
        } else if (p1.terms[i].exp < p2.terms[j].exp) {
            result.terms[result.numTerms++] = p2.terms[j++];
        } else {
            result.terms[result.numTerms].exp = p1.terms[i].exp;
            result.terms[result.numTerms++].coeff = p1.terms[i++].coeff + p2.terms[j++].coeff;
        }
    }

    while (i < p1.numTerms) {
        result.terms[result.numTerms++] = p1.terms[i++];
    }

    while (j < p2.numTerms) {
        result.terms[result.numTerms++] = p2.terms[j++];
    }

    return result;
}

int main() {
    Polynomial p1, p2, sum;

    printf("Enter the first polynomial:\n");
    inputPolynomial(&p1);

    printf("Enter the second polynomial:\n");
    inputPolynomial(&p2);

    sum = addPolynomials(p1, p2);

    printf("First Polynomial: ");
    displayPolynomial(p1);

    printf("Second Polynomial: ");
    displayPolynomial(p2);

    printf("Sum of Polynomials: ");
    displayPolynomial(sum);

    free(p1.terms);
    free(p2.terms);
    free(sum.terms);

    return 0;
}
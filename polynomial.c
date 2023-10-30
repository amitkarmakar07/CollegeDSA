#include <stdio.h>
#include <stdlib.h>

struct Term {
    int coefficient;
    int exponent;
    struct Term* next;
};

typedef struct Term Polynomial;

Polynomial* createTerm(int coefficient, int exponent) {
    Polynomial* term = (Polynomial*)malloc(sizeof(Polynomial));
    term->coefficient = coefficient;
    term->exponent = exponent;
    term->next = NULL;
    return term;
}

// Function to insert a term at the end of the polynomial
void insertTerm(Polynomial** poly, int coefficient, int exponent) {
    Polynomial* newTerm = createTerm(coefficient, exponent);
    
    if (*poly == NULL) {
        *poly = newTerm;
    } else {
        Polynomial* current = *poly;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newTerm;
    }
}

// Function to display a polynomial
void displayPolynomial(Polynomial* poly) {
    Polynomial* current = poly;
    while (current != NULL) {
        printf("%dx^%d ", current->coefficient, current->exponent);
        if (current->next != NULL) {
            printf("+ ");
        }
        current = current->next;
    }
    printf("\n");
}

// Function to add two polynomials
Polynomial* addPolynomials(Polynomial* poly1, Polynomial* poly2) {
    Polynomial* result = NULL;
    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->exponent > poly2->exponent) {
            insertTerm(&result, poly1->coefficient, poly1->exponent);
            poly1 = poly1->next;
        } else if (poly1->exponent < poly2->exponent) {
            insertTerm(&result, poly2->coefficient, poly2->exponent);
            poly2 = poly2->next;
        } else {
            int sum = poly1->coefficient + poly2->coefficient;
            if (sum != 0) {
                insertTerm(&result, sum, poly1->exponent);
            }
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }
    
    // If there are any remaining terms in poly1 or poly2, add them
    while (poly1 != NULL) {
        insertTerm(&result, poly1->coefficient, poly1->exponent);
        poly1 = poly1->next;
    }
    while (poly2 != NULL) {
        insertTerm(&result, poly2->coefficient, poly2->exponent);
        poly2 = poly2->next;
    }
    
    return result;
}

// Function to subtract two polynomials
Polynomial* subtractPolynomials(Polynomial* poly1, Polynomial* poly2) {
    // Negate the coefficients of poly2 and then add the polynomials
    Polynomial* negPoly2 = poly2;
    while (negPoly2 != NULL) {
        negPoly2->coefficient *= -1;
        negPoly2 = negPoly2->next;
    }
    return addPolynomials(poly1, poly2);
}

int main() {
    Polynomial* poly1 = NULL;
    Polynomial* poly2 = NULL;
    
    // Insert terms into the first polynomial
    insertTerm(&poly1, 5, 2);
    insertTerm(&poly1, 3, 1);
    insertTerm(&poly1, 2, 0);
    
    // Insert terms into the second polynomial
    insertTerm(&poly2, 4, 2);
    insertTerm(&poly2, 1, 1);
    insertTerm(&poly2, 3, 0);
    
    printf("Polynomial 1: ");
    displayPolynomial(poly1);
    
    printf("Polynomial 2: ");
    displayPolynomial(poly2);
    
    Polynomial* sum = addPolynomials(poly1, poly2);
    printf("Sum of the polynomials: ");
    displayPolynomial(sum);
    
    Polynomial* diff = subtractPolynomials(poly1, poly2);
    printf("Difference of the polynomials: ");
    displayPolynomial(diff);
    
    free(poly1);
    free(poly2);
    free(sum);
    free(diff);
    
    return 0;
}

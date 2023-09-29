/*Author : RAJ ROY*/

#include<stdio.h>
#include<stdlib.h>

struct Node {
    int coeff;
    int pow;
    struct Node* next;
};

void create(int x, int y, struct Node** temp){
    struct Node *first, *second;
    second = *temp;
    if (second == NULL) {
        first = (struct Node*)malloc(sizeof(struct Node));
        first->coeff = x;
        first->pow = y;
        *temp = first;
        first->next = (struct Node*)malloc(sizeof(struct Node));
        first = first->next;
        first->next = NULL;
    }
    else {
        first->coeff = x;
        first->pow = y;
        first->next = (struct Node*)malloc(sizeof(struct Node));
        first = first->next;
        first->next = NULL;
    }
}

void display(struct Node* node){
    while (node->next != NULL) {
        printf("%dx^%d", node->coeff, node->pow);
        node = node->next;
        if (node->coeff >= 0) {
            if (node->next != NULL)
                printf("+");
        }
    }
    printf("\n");
}

void polyadd(struct Node* poly1, struct Node* poly2,struct Node* poly){
    while (poly1->next && poly2->next) {
        if (poly1->pow > poly2->pow) {
            poly->pow = poly1->pow;
            poly->coeff = poly1->coeff;
            poly1 = poly1->next;
        }
        else if (poly1->pow < poly2->pow) {
            poly->pow = poly2->pow;
            poly->coeff = poly2->coeff;
            poly2 = poly2->next;
        }
        else {
            poly->pow = poly1->pow;
            poly->coeff = poly1->coeff + poly2->coeff;
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
  
        poly->next = (struct Node*)malloc(sizeof(struct Node));
        poly = poly->next;
        poly->next = NULL;
    }
    while (poly1->next || poly2->next) {
        if (poly1->next) {
            poly->pow = poly1->pow;
            poly->coeff = poly1->coeff;
            poly1 = poly1->next;
        }
        if (poly2->next) {
            poly->pow = poly2->pow;
            poly->coeff = poly2->coeff;
            poly2 = poly2->next;
        }
        poly->next = (struct Node*)malloc(sizeof(struct Node));
        poly = poly->next;
        poly->next = NULL;
    }
}

int main(){
	struct Node *poly1 = NULL, *poly2 = NULL, *poly = NULL;
    create(10, 5, &poly1);
    create(9, 5, &poly1);
    create(3, 2, &poly1);
  
    create(3, 2, &poly2);
    create(-3, 1, &poly2);
    
    display(poly1);
    display(poly2);
    
    poly = (struct Node*)malloc(sizeof(struct Node));
  
    polyadd(poly1, poly2, poly);
    display(poly);
    return 0;
}
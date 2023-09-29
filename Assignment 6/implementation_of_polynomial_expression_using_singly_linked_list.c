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

int main(){
	struct Node *poly1 = NULL, *poly2 = NULL;
    create(10, 5, &poly1);
    create(9, 5, &poly1);
    create(3, 2, &poly1);
  
    create(3, 2, &poly2);
    create(-3, 1, &poly2);
    
    display(poly1);
    display(poly2);
    return 0;
}
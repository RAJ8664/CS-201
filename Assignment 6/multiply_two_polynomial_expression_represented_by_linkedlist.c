/*Author : RAJ ROY*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    int power;
    struct Node * next;
}Node;

Node * getNode(int data, int power){
    Node * ref = (Node * ) malloc(sizeof(Node));
    if (ref == NULL)
    {
        return NULL;
    }
    ref->data = data;
    ref->power = power;
    ref->next = NULL;
    return ref;
}

void updateRecord(Node * ref, int data, int power)
{
    ref->data = data;
    ref->power = power;
}
typedef struct MultiplyPolynomial{
    struct Node * head;
}MultiplyPolynomial;

MultiplyPolynomial * getMultiplyPolynomial(){
    MultiplyPolynomial * ref = (MultiplyPolynomial * )
                    malloc(sizeof(MultiplyPolynomial));
    if (ref == NULL)
    {
        return NULL;
    }
    ref->head = NULL;
    return ref;
}
void insert(MultiplyPolynomial * ref, int data, int power)
{
    if (ref->head == NULL)
    {
        ref->head = getNode(data, power);
    }
    else
    {
        Node * node = NULL;
        Node * temp = ref->head;
        Node * location = NULL;
        while (temp != NULL && temp->power >= power)
        {
            location = temp;
            temp = temp->next;
        }
        if (location != NULL && location->power == power)
        {
            location->data = location->data + data;
        }
        else
        {
            node = getNode(data, power);
            if (location == NULL)
            {
                node->next = ref->head;
                ref->head = node;
            }
            else
            {
                node->next = location->next;
                location->next = node;
            }
        }
    }
}
MultiplyPolynomial * multiplyPolynomials(
  MultiplyPolynomial * ref, MultiplyPolynomial * other)
{
    MultiplyPolynomial * result = getMultiplyPolynomial();
    Node * poly1 = ref->head;
    Node * temp = other->head;
    int power_value = 0;
    int coefficient = 0;
    while (poly1 != NULL)
    {
        temp = other->head;
        while (temp != NULL)
        {
            power_value = poly1->power + temp->power;
            coefficient = poly1->data * temp->data;
            insert(result, coefficient, power_value);
            temp = temp->next;
        }
        poly1 = poly1->next;
    }
    return result;
}
void display(MultiplyPolynomial * ref)
{
    if (ref->head == NULL)
    {
        printf("Empty Polynomial ");
    }
    printf(" ");
    Node * temp = ref->head;
    while (temp != NULL)
    {
        if (temp != ref->head)
        {
            printf(" + %d", temp->data);
        }
        else
        {
            printf("%d",temp->data);
        }
        if (temp->power != 0)
        {
            printf("x^%d", temp->power);
        }
        temp = temp->next;
    }
    printf("\n");
}
int main()
{
    MultiplyPolynomial * a = getMultiplyPolynomial();
    MultiplyPolynomial * b = getMultiplyPolynomial();
    insert(a, 9, 3);
    insert(a, 4, 2);
    insert(a, 3, 0);
    insert(a, 7, 1);
    insert(a, 3, 4);
    insert(b, 7, 3);
    insert(b, 4, 0);
    insert(b, 6, 1);
    insert(b, 1, 2);
    printf("\n Polynomial A\n");
    display(a);
    printf(" Polynomial B\n");
    display(b);
    MultiplyPolynomial * result = multiplyPolynomials(a, b);
    printf(" Result\n");
    display(result);
}
/*Author : Raj Roy*/

#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node* next;
};

void InsertAtLast(struct Node** head,int data){
	struct Node* current = (struct Node*)malloc(sizeof(struct Node));
	current->data = data;
	struct Node* temp = *head;
	if(*head == NULL){
		*head = current;
		current->next = NULL;
		return;
	}
	while(temp->next != NULL){
		temp = temp->next;
	}
	
	temp->next = current;
	current->next = NULL;
}
void PrintLinkedList(struct Node* head){
	printf("Head-->");
	while(head != NULL){
		printf("%d-->" ,head->data );
		head = head->next;
	}
	printf("NULL\n");

}



//Reversing the linkedlist using interative method;
void ReverseLinkedList(struct Node** head){
	struct Node* current = *head;
	struct Node* prev = NULL;
	struct Node* nextptr = NULL;
	if(current == NULL || current->next == NULL){
		return;
	}
	while(current != NULL){
		nextptr = current->next;
		current->next = prev;
		
		prev = current;
		current = nextptr;
	}
	
	*head = prev;
}

//Reversing linkedlist using stack

void push(struct Node** stack ,int data){
	struct Node* current = (struct Node*)malloc(sizeof(struct Node));
	current->data = data;
	current->next = *stack;
	*stack = current;
}

int pop(struct Node** stack){
	int popped = (*stack)->data;
	
	
	//letting current stack pointer go;
	//directly move *stack to it next;
	*stack = (*stack)->next;
	return popped;
}

void ReverseLinkedList1(struct Node** head){
	struct Node* stack = NULL;
	struct Node* current = *head;
	
	while(current != NULL){
		push(&stack,current->data);
		current = current->next;
	}
	
	current = *head;
	while(current != NULL){
		current->data = pop(&stack);
		current = current->next;
	}
}

int main(){
	struct Node* head = NULL;
	
	int n;
	scanf("%d",&n);
	for(int i = 0; i < n; i++){
		int x;
		scanf("%d",&x);
		InsertAtLast(&head,x);
	}
	PrintLinkedList(head);
	
	printf("After Reversing the linkedlist: Iterative\n");
	ReverseLinkedList(&head);
	PrintLinkedList(head);
	
	printf("After Reversing the linkedlist : Recursion\n");
	//here the current state of linked list is 5->4->3->2---->null and so on due to above reverse
	//hence the answer for this reverse will be the reverse of above;
	//that is 1 - > 2 - > 3 - > 4 - > 5  ans so on;
	ReverseLinkedList1(&head);
	PrintLinkedList(head);
}

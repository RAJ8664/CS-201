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

//reversing the linkedlist from position m to n;

void ReverseLinkedList(struct Node** head,int m ,int n){
	struct Node* current = *head;
	struct Node* prev = NULL;
	struct Node* start = NULL;
	struct Node* end = NULL;
	struct Node* next = NULL;
	
	for(int i = 1; i < m; i++){
		prev = current;
		current = current->next;
	}
	
	start =  prev;
	end = current;
	prev = NULL;
	
	for(int i = m; i <= n; i++){
		next = current->next;
		current->next = prev;
		prev= current;
		current = next;
		
	}
	if(start != NULL){
		start->next = prev;
	}
	else{
		*head = prev;
	}
	
	end->next = current;
	
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
	
	printf("After Reversing the linkedlist:\n");
	ReverseLinkedList(&head,2,5);
	
	PrintLinkedList(head);
	
}

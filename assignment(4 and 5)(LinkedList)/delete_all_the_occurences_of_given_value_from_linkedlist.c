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

void DeleteAllOccurences(struct Node** head,int val){
	struct Node* current = *head;
	struct Node* prev = NULL;
	if(*head == NULL){
		return;
	}
	
	while(current != NULL){
		if(current->data == val){
			if(prev == NULL){
				*head = current->next;
				free(current);
				current = *head;
			}
			else{
				prev->next = current->next;
				free(current);
				current = prev->next;
			}
		}
		else{
			prev = current;
			current = current->next;
		}
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
	 DeleteAllOccurences(&head,2);
	 PrintLinkedList(head);
	return 0;
}

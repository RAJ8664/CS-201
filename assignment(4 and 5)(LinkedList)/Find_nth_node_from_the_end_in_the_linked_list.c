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

int Find_nth_node_from_end(struct Node** head,int n){
	struct Node* current = *head;
	int count = 0;
	while(current != NULL){
		count++;
		current = current->next;
	}
	
	current = *head;
	count = count + 1;
	int req = count - n;
	
	while(req != 1){
		req--;
		current = current->next;
	}
	return current->data;
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
	
	int nth = 4;
	int ans = Find_nth_node_from_end(&head,nth);
	printf("%d ",ans);
	return 0;
}

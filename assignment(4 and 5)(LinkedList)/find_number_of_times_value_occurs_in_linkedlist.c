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

int GetCount(struct Node** head,int val){
	if(*head == NULL){
		return 0;
	}
	
	struct Node* current = *head;
	int count = 0;
	while(current != NULL){
		if(current->data == val){
			count++;
		}
		current = current->next;
	}
	return count;
}

int main(){
	struct Node* head = NULL;
	int n;
	int val;
	scanf("%d%d",&n,&val);
	for(int i = 0; i < n; i++){
		int x;
		scanf("%d",&x);
		InsertAtLast(&head,x);
	}
	
	 PrintLinkedList(head);
	 int ans = GetCount(&head,val);
	 printf("%d ",ans);
	return 0;
}

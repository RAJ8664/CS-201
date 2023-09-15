/*Author : Raj Roy*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

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


bool contains(struct Node** head,int key){
	struct Node* current = *head;
	while(current != NULL){
		if(current->data == key){
			return true;
		}
		current = current->next;
	}
	return false;
	
}
Node* Intersection(struct Node** head1,struct Node** head2){
	struct Node* current1 = *head1;
	struct Node* current2 = *head2;
	struct Node* ans = NULL;
	
	while(current1 != NULL){
		if(!contains(&ans,current1->data)){
			InsertAtLast(&ans,current1->data);
		}
		current1 = current1->next;
	}
	while(current2 != NULL){
		if(!contains(&ans,current2->data)){
			InsertAtLast(&ans,current2->data);
		}
		current2 = current2->next;
	}
	return ans;	
}
int main(){
	struct Node* head1 = NULL;
	struct Node* head2 = NULL;
	struct Node* ans = NULL;
	int n;
	scanf("%d",&n);
	for(int i = 0; i < n; i++){
		int x;
		scanf("%d",&x);
		InsertAtLast(&head1,x);
	}
	
	int m;
	scanf("%d",&m);
	for(int i = 0; i < m; i++){
		int x;
		scanf("%d",&x);
		InsertAtLast(&head2,x);
	}
	
	printf("First linkedlist:\n");
	PrintLinkedList(head1);
	
	printf("second linkedlist:\n");
	PrintLinkedList(head2);	
	
	printf("Resultant linkedlist:\n");
	ans = Intersection(&head1,&head2);
	PrintLinkedList(ans);
	return 0;
}

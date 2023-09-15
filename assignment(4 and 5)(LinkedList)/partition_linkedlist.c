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

Node* Partition(struct Node** head,int val){
	struct Node* current = *head;
	struct Node* ans = NULL;
	
	while(current != NULL){
		if(current->data < val){
			InsertAtLast(&ans,current->data);
		}
		current = current->next;
	}
	current = *head;
	while(current != NULL){
		if(current->data == val){
			InsertAtLast(&ans,current->data);
		}
		current = current->next;
	}
	current = *head;
	while(current != NULL){
		if(current->data >= val){
			InsertAtLast(&ans,current->data);
		}
		current = current->next;
	}
	return ans;
}

int main(){
	/*
	Given a linked list and a value x, 
	write a program to partition it such that all nodes less than x come
    first, then all nodes with a value equal to x, 
    and finally nodes with a value greater than or equal to x.
	
	
	According to the problem statement val x will be printed twice if x is
	present in the linkedlist;
	since we are asked to print 
	first = all values less than x;
	second = all values equals to x;
	third = all value greater than or equal to x;
	*/
	
	
	struct Node* head1 = NULL;
	struct Node* ans = NULL;
	int n;
	scanf("%d",&n);
	for(int i = 0; i < n; i++){
		int x;
		scanf("%d",&x);
		InsertAtLast(&head1,x);
	}

	PrintLinkedList(head1);
	
	printf("Resultant linkedlist:\n");
	int val;
	scanf("%d ",&val);
	ans = Partition(&head1,val);
	PrintLinkedList(ans);
	return 0;
}

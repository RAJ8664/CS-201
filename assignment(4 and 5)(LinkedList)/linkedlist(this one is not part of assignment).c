/*Author : Raj Roy*/

#include<stdio.h>
#include<stdlib.h>

//Node Constructor;
//current node is the starting node node in each function;

struct Node{
	int data;
	struct Node* next;
};

//Print LinkedList;
void printlinkedlist(struct Node* head){
	if(head == NULL){
		return;
	}
	printf("Head-->");
	while(head != NULL){
		printf("%d-->" , head->data);
		head = head->next;
	}
	printf("NULL");
}


/************************INSERTION OF NODE***************************/

//Insert Node int the beginning;
void InsertAtFirst(struct Node** head,int data){
	struct Node* current = (struct Node*)malloc(sizeof(struct Node));
	current->data = data;
	current->next = *head;
	*head = current;
}

//Insert node at last;
void InsertAtLast(struct Node** head,int data){
	struct Node* current = (struct Node*)malloc(sizeof(struct Node));
	current->data = data;
	current->next = NULL;
	if(*head == NULL){
		*head = current;
		return;
	}
	struct Node* temp = *head;
	while(temp->next != NULL){
		temp = temp->next;
	}
	temp->next = current;
	return;
	
	
}

//Insert Node at particular index;
void InsertAtIndex(struct Node** head,int data,int index){
	struct Node* current = (struct Node*) malloc(sizeof(struct Node));
	current->data = data;
	struct Node* temp = *head;
	int count = 0;
	if(index == 0){
		current->next = *head;
		*head = current;
		return;
	}
	while(index != 1){
		temp = temp->next;
		index--;
		
	}
	
	current->next = temp->next;
	temp->next = current;
}

//Insert Node in the middle of linkedlist;
void InsertAtMiddle(struct Node** head,int data){
	struct Node* current = (struct Node*)malloc(sizeof(struct Node));
	current->data = data;
	struct Node* temp = *head;
	int count = 0;
	while(temp != NULL){
		count++;
		temp = temp->next;
		
	}
	//count here is the number of nodes in the linked list;
	if(count % 2 == 0){
		count = count / 2;
	}
	else{
		count = count / 2 + 1;
	}
	temp = *head;
	while(count != 1){
		temp = temp->next;
		count--;
	}
	current->next = temp->next;
	temp->next = current;
	
	
}

//Insert Node after give Node;
void InsertAfter(struct Node* prev , int data){
	struct Node* current = (struct Node*)malloc(sizeof(struct Node));
	current->data = data;
	if(prev == NULL){
		//not possible;
		return;
	}
	current->next = prev->next;
	prev->next = current;
}



/***********************DELETION OF NODE ******************/

//delete any particular node in the linked list;
void DeleteNode(struct Node** head, int key){
	struct Node* current = *head;
	struct Node* prev = current;
	if(current != NULL && current->data == key){
		*head = current->next;
		free(current);
		return;
	}
	
	while(current != NULL && current->data != key){
		prev = current;
		current = current->next;
	}
	
	//if the key was not found;
	if(current == NULL){
		return;
	}
	
	prev->next = current->next;
	free(current);
}

//Delete first Node of linkedlist;
void DeleteFirstNode(struct Node** head){
	struct Node* current = *head;
	*head = current->next;
	free(current);
}


//delete last node;
void DeleteLastNode(struct Node** head){
	struct Node* current = *head;
	struct Node* prev = current;
	while(current->next != NULL){
		prev = current;
		current = current->next;
	}
	prev->next = NULL;
	free(current);
	
}

//delete middle node
//note if number of nodes is even the delete n / 2 th node;
//if number of nodes is odd then delete n / 2 + 1 the node;

void DeleteMiddleNode(struct Node** head){
	struct Node* current = *head;
	int len = 0;
	
	//count the total nodes in the linkedlist;
	while(current != NULL){
		len++;
		current = current->next;
	}
	
	current = *head;
	if(len % 2 == 0){
		len = len / 2;
	}
	else{
		len = len / 2 + 1;
	}
	
	struct Node* prev = current;
	while(len != 1){
		prev = current;
		current = current->next;
		len--;
	}
	prev->next = current->next;
	free(current);
	
}

//Delete Node at any particular index;
void DeleteNodeIndex(struct Node** head,int index){
	struct Node* current = *head;
	struct Node* prev = current;
	if(index == 0){
		*head = current->next;
		free(current);
		return;
	}
	while(index != 0){
		index--;
		prev = current;
		current = current->next;
	}
	prev->next = current->next;
	free(current);
}

void ReverseLinkedList(struct Node** head){
	struct Node* current = *head;
	struct Node* next = NULL;
	struct Node* prev = NULL;
	while(current != NULL){
		next = current->next;
		current->next = prev;
		
		//change the position of pointer
		prev = current;
		current = next;
	}
	*head = prev;
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
	ReverseLinkedList(&head);
	
	
	
	printlinkedlist(head);
	
	return 0;
	
}
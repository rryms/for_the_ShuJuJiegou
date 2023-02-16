#include<stdio.h>
#include<stdlib.h>
//C����ʵ��linked list,��C�����У�node�����ڶ�������������ƣ�ͨ�������ݽṹ�������������������﷨Ϊ��struct Node{...};�����ṹ�����ڶ���������Ժ�ֱ���ø����ƾͿ��Զ������C�����л����ڡ�Node * a���͡�Node* &a����
//Definition of the nodes structure
typedef struct node {
	int data;
	struct node* next; 
}node ;
node* create_node(int data) {
	node* new_node = malloc(sizeof(node));
	new_node->data = data;
	new_node->next = NULL;
	return new_node;
}
//Function to insert a new node at the beginning of the list
void insert_a_begin(node** head, int data) {
	node* new_node = malloc(sizeof(node));
	new_node->next = *head;
	*head = new_node;
}
 //Function to insert a new node at the end of the list
void insert_at_end(node** head, int data) {
	node* new_node = create_node(data);
	if (*head == NULL) {
		*head = new_node;
		return;
	}
	node* current = *head;
	while (current->next != NULL) {
		current = current->next;
	}
	current->next = new_node;
}
//Function to delete a node from the list
void delete_node(node** head, int data) {
	node* current = *head;
	node* previous = NULL;
	while (current != NULL) {
		if (current->data == data) {
			*head = current->next;
		}
		else {
			previous->next = current->next;
		}
		free(current);
		return;
	}
	previous = current;
	current = current->next;
}
//Function to print the list
void print_list(node* head) {
	node* current = head;
	while (current != NULL)
	{
		printf("%d", current->data);
		current = current->next;
	}
	printf("\n");
}
int main(int argc, char const* argv[])
{
	/*code����*/
	node* head = NULL;
	insert_at_begin(&head, 1);
	insert_at_begin(&head, 2);
	insert_at_begin(&head, 3);
	insert_at_begin(&head, 4);
	insert_at_begin(&head, 5);
	print_list(head);
	delete_node(&head, 4);
	print_list(head);
	return 0;
}
#include <stdio.h>
#include<stdlib.h>

typedef struct node{
	int value;
	struct node *next;
} node;

node *head = NULL;
node *tail = NULL;
int isEmpty()
{
	if (head==NULL) return 1;
	else return 0;
}

void init(int value)
{
	struct node *tmp;
	tmp=(node*)malloc(sizeof(node));
	tmp->value=value;
	tmp->next=NULL;
	head=tmp;
	tail=tmp;
}
void push(int data)
{
	if (isEmpty()==1) init(data);
	else
	{
		struct node *tmp=(node*)malloc(sizeof(node));
		tmp->value=data;
		tmp->next=head;
		head=tmp;
	}
}

void get_posled()
{
	if (isEmpty()==0)
	{
		struct node *tmp=head;
		printf("%d", tmp->value);
		printf("\n");
	}
}

void get_out ()
{
if (isEmpty()==0)
{
	node *tmp=head; 
	printf("%d",tmp->value); 
	while (tmp->next!=NULL) 
	{  
		tmp=tmp->next;
		printf(" ");
		printf("%d",tmp->value); 

	}
		printf("\n");
}
}

void remove_posled()
{
	struct node *tmp;
	if (head != NULL)
	{
		tmp=head;
		head=tmp->next;
		free(tmp);
	}

}

void delete(node **head)
{
	struct node *prev=NULL;
	while((*head)->next)
	{
		prev = *head;
		*head = (*head)->next;
		free(prev);
	}
	free(*head);
}

int main()
{
	int n=0,val=0;
	scanf("%d",&n);
	for (int i=0; i<n;i++)
	{
		scanf("%d", &val);
		push(val);
	}
	get_out();
	remove_posled();
	get_out();
	get_posled();
	delete(&head);
	return 0;
}

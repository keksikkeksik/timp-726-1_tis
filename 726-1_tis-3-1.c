#include <stdio.h>
#include<stdlib.h>

typedef struct node {
int value;
struct node *next;
struct node *prev;
} node;

node *head=NULL;
node *tail=NULL;

int isEmpty()
{
if ((head==NULL)&&(tail==NULL))
return 1;
else return 0;
}

int init(int value)
{
struct node *tmp;
tmp = (struct node*)malloc(sizeof(struct node));
tmp->value=value;
tmp->next=NULL;
tmp->prev=NULL;
head= tmp;
tail = tmp;
}

void zap(int x)
{
if(isEmpty()==1)
init (x);
else
{
struct node *tmp = (struct node*)malloc(sizeof(struct node));
tmp->value=x;
tmp->prev=tail;
tmp->next=NULL;
tail=tmp;
tmp->prev->next=tmp;
}
};
int destroy()
{
if(isEmpty()==0)
{
struct node *tmp=head;
struct node *temp=NULL;
while(tmp!=NULL)
{
temp=tmp->next;
free(tmp);
tmp=temp;
}
head=NULL;
tail=NULL;
}
};
void get_out()
{
struct node *tmp=head;
printf("%d", tmp->value);
while(tmp->next!=NULL)
{
tmp=tmp->next;
printf(" %d", tmp->value);
}
printf("\n");
}

struct node *adressk(int k)
{
struct node *tmp=head;
for (int i =1;i<k;i++)
{
tmp=tmp->next;
if(tmp==NULL) break;
}
return tmp;
}

struct node *znach(int k)
{
node *tmp=head;

while (tmp!=NULL && tmp->value != k)
{
tmp=tmp->next;
}
return tmp;}

void append(int num, int data)
{
node *tmp = adressk(num);
if (tmp==NULL||tmp==tail)
{
struct node *temp = malloc(sizeof(node));
temp->value=data;
temp->next=NULL;
temp->prev=tail;
temp->prev->next=temp;
tail=temp;
}
else
{
node *temp = malloc(sizeof(node));
temp->value=data;
temp->next=tmp->next;
temp->prev=tmp;
tmp->next->prev=temp;
tmp->next=temp;  
}   
}
void prepend(int num, int data)
{ 
node *tmp = adressk(num);
if (tmp==NULL||tmp==head) 
{
node *temp = malloc(sizeof(node));
temp->value=data; 
temp->prev=NULL; 
temp->next=head; 
head=temp; 
temp->next->prev=temp;
}
else
{
node *temp = malloc(sizeof(node));
temp->value=data;
temp->prev=tmp->prev;
temp->next=tmp;
tmp->prev=temp;
temp->prev->next=temp;    
}    
} 
void deletk(struct node *tmp)
{
int f=0;
if(tmp==NULL)
f=1;
if (tmp==head && tmp==tail &&f==0 ){ destroy();f=1;}
if (tmp==head&&f==0)
{
head=tmp->next;
tmp->next->prev=NULL;
free(tmp);
f=1;
}
if(tmp==tail&&f==0)
{
tail=tmp->prev;
tmp->prev->next=NULL;
free(tmp);
f=1;
}
if (tmp!=head && tmp!=tail && f==0)
{
tmp->next->prev=tmp->prev;
tmp->prev->next=tmp->next;
free(tmp);
f=1;
}
}


int main()
{
int n=0,x=0,k=0;
scanf("%d",&n);
for (int i=0;i<n;i++)
{
scanf("%d",&x);
zap(x);
}
get_out();
scanf("%d", &k);
deletk(adressk(k));
if(isEmpty()==0) get_out();
scanf("%d", &k);
deletk(znach(k));
if(isEmpty()==0) get_out();
scanf("%d %d", &k, &n);
append(k,n);
if(isEmpty()==0) get_out();
scanf("%d %d", &k, &n);
prepend(k,n);
if(isEmpty()==0) get_out();
destroy();
return 0;
}

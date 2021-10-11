#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node
{
  int id;
  struct node *next,*prev;
};
void append(struct node **);
void display(struct node *);
void rev(struct node **pt)
{
    struct node *curr=*pt;
    while(curr->next!=NULL)
    {
        curr=curr->next;
    }
    while(curr!=NULL)
    {
        printf("%d ",curr->id);
        curr=curr->prev;
    }
}
int main()
{
  struct node *head;
  head=NULL;
 char choice[10];
  do
  {
    append(&head);
    printf("Do you want to add details of another student? Type Yes/No\n");
    scanf("%s",choice);
  }while(!strcmp(choice,"Yes"));
  printf("The details of the students are\n");
  display(head);
  printf("\n");
  rev(&head);
  
return 0;
}
void append(struct node **head)
{
  struct node *newstud=(struct node*)malloc(sizeof(struct node));
  struct node *temp=*head;
 
 
  printf("Enter the id\n");
  scanf("%d",&(newstud->id));
 
  newstud->next=NULL;

  if(*head==NULL)
  {
    newstud->prev=NULL;
    *head=newstud;
    return;

  }
  while(temp->next!=NULL)
  {
    temp=temp->next;
  }
  temp->next=newstud;
  newstud->prev=temp;
}
void display(struct node *head)
{
  struct node *temp=head;
    printf("The values are:\n");
  while(temp!=NULL)
  {
  printf("%d ",temp->id);
  temp=temp->next;
  }
}

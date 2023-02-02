#include <stdio.h>
#include <stdlib.h>

struct Node
{
   int data;
   struct Node *next;
};

struct Node *head = NULL;

void insertAtBeginning(int data)
{
   struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
   temp->data = data;
   temp->next = head;
   head = temp;
}

void insertAtEnd(int data)
{
   struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
   temp->data = data;
   temp->next = NULL;

   if (head == NULL)
   {
      head = temp;
      return;
   }

   struct Node *last = head;
   while (last->next != NULL)
      last = last->next;

   last->next = temp;
}

void deleteNode(int data)
{
   struct Node *temp = head, *prev = NULL;

   if (temp != NULL && temp->data == data)
   {
      head = temp->next;
      free(temp);
      return;
   }

   while (temp != NULL && temp->data != data)
   {
      prev = temp;
      temp = temp->next;
   }

   if (temp == NULL)
      return;

   prev->next = temp->next;
   free(temp);
}

void displayList()
{
   struct Node *temp = head;
   while (temp != NULL)
   {
      printf("%d ", temp->data);
      temp = temp->next;
   }
   printf("\n");
}

int main()
{
   insertAtBeginning(5);
   insertAtBeginning(10);
   insertAtEnd(15);
   insertAtEnd(20);
   displayList();
   deleteNode(10);
   displayList();
   return 0;
}

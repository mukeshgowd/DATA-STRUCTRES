#include <stdio.h>

#define MAX_SIZE 100

void insert(int arr[], int *n, int index, int value)
{
   int i;
   if (*n >= MAX_SIZE)
   {
      printf("Array is full, cannot insert.\n");
      return;
   }
   for (i = *n; i > index; i--)
      arr[i] = arr[i - 1];
   arr[index] = value;
   (*n)++;
}

void delete(int arr[], int *n, int index)
{
   int i;
   if (*n <= 0)
   {
      printf("Array is empty, cannot delete.\n");
      return;
   }
   for (i = index; i < *n - 1; i++)
      arr[i] = arr[i + 1];
   (*n)--;
}

void display(int arr[], int n)
{
   int i;
   printf("Array: ");
   for (i = 0; i < n; i++)
      printf("%d ", arr[i]);
   printf("\n");
}

int main()
{
   int arr[MAX_SIZE];
   int n = 0;
   int choice, index, value;

   while (1)
   {
      printf("1. Insert\n");
      printf("2. Delete\n");
      printf("3. Display\n");
      printf("4. Exit\n");
      printf("Enter your choice: ");
      scanf("%d", &choice);

      switch (choice)
      {
      case 1:
         printf("Enter the index and value to be inserted: ");
         scanf("%d%d", &index, &value);
         insert(arr, &n, index, value);
         break;
      case 2:
         printf("Enter the index of the element to be deleted: ");
         scanf("%d", &index);
         delete(arr, &n, index);
         break;
      case 3:
         display(arr, n);
         break;
      case 4:
         return 0;
      default:
         printf("Invalid choice.\n");
         break;
      }
   }

   return 0;
}

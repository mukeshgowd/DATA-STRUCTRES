#include <stdio.h>

int search(int arr[], int n, int key)
{
   int i;
   for (i = 0; i < n; i++)
   {
      if (arr[i] == key)
         return i;
   }
   return -1;
}

int main()
{
   int arr[] = {1, 2, 3, 4, 5};
   int n = sizeof(arr) / sizeof(arr[0]);
   int key, index;

   printf("Enter the key to be searched: ");
   scanf("%d", &key);

   index = search(arr, n, key);
   if (index == -1)
      printf("Key not found in the array.\n");
   else
      printf("Key found at index %d.\n", index);

   return 0;
}

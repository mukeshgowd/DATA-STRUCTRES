#include <stdio.h>

int binarySearch(int arr[], int low, int high, int key)
{
   if (high >= low)
   {
      int mid = low + (high - low) / 2;

      if (arr[mid] == key)
         return mid;

      if (arr[mid] > key)
         return binarySearch(arr, low, mid - 1, key);

      return binarySearch(arr, mid + 1, high, key);
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

   index = binarySearch(arr, 0, n - 1, key);
   if (index == -1)
      printf("Key not found in the array.\n");
   else
      printf("Key found at index %d.\n", index);

   return 0;
}

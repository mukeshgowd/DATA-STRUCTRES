#include <stdio.h>

int partition(int arr[], int low, int high) {
  int pivot = arr[high];
  int i = (low - 1);
  int j;
  for (j = low; j <= high - 1; j++) {
    if (arr[j] <= pivot) {
      i++;
      int temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
    }
  }
  int temp = arr[i + 1];
  arr[i + 1] = arr[high];
  arr[high] = temp;
  return (i + 1);
}

void quickSort(int arr[], int low, int high) {
  if (low < high) {
    int pi = partition(arr, low, high);
    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
  }
}

void printArray(int arr[], int size) {
  int i;
  for (i = 0; i < size; i++)
    printf("%d ", arr[i]);
  printf("\n");
}

int main() {
  int n, i;
  printf("Enter number of elements: ");
  scanf("%d", &n);
  int arr[n];
  printf("Enter %d integers\n", n);
  for (i = 0; i < n; i++)
    scanf("%d", &arr[i]);
  printf("Given array is \n");
  printArray(arr, n);
  quickSort(arr, 0, n - 1);
  printf("\nSorted array is \n");
  printArray(arr, n);
  return 0;
}

// Copyright 2017 Yashkov Vladislav + Kiparenko Ilya

#include "include/interpolation_search.h"
#include <stdio.h>

bool InterpolationSearch::isArrayValid(int* sortedArray, int length) {
  if (sortedArray == nullptr) {
    printf("Zero ptr\n");
    throw "Array is null";
  } else {
    if (length < 1) {
      printf("Length %i\n", length);
      throw "length is null or negative";
    } else {
      printf("Validation ");
      for (int i = 0; i < length; i++)
        printf("%i ", sortedArray[i]);
      printf("\n");
      for (int i = 1; i < length; i++)
        if (sortedArray[i] < sortedArray[i - 1])
          return false;
      return true;
    }
  }
  return false;
}

int InterpolationSearch::Search(int toFind, int* sortedArray, int length) {
  // Returns the index of an element with a value of toFind or -1,
  // if there is no such element
  int low = 0;
  int high = length - 1;
  int steps = 0;
  while (sortedArray[low] < toFind && sortedArray[high] > toFind) {
    int mid = low + ((toFind - sortedArray[low]) *
      (high - low)) / (sortedArray[high] - sortedArray[low]);
     printf("Search %i %i %i\n", high, low, mid);
    if (sortedArray[mid] < toFind)
      low = mid + 1;
    else if (sortedArray[mid] > toFind)
      high = mid - 1;
    else
      return mid;
    steps++;
    if (steps > 100)
      return -1;
  }
  if (sortedArray[low] == toFind) {
    return low;
  } else {
    if (sortedArray[high] == toFind)
      return high;
    else
      return -1;  // Not found
  }
  return -1;
}

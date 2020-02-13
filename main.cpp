/* 
Name: Derick Bui
Class: CECS 282
Instructor: Minhthong Nguyen
Purpose of the program: To understand how bubble sort works and how to code it.
Last updated: November 20, 2019
*/

#include <iostream>
using namespace std;

//Function for Bubble Sort to use to swap
//@param a reference of first integer
//@param b reference of second integer
void swap(int& a, int& b) {
  int temp = a;
  a = b;
  b = temp;
}

//This function does bubble sort
//@param a[] an array to sort
//@param size the size of an array
void bubbleSort(int a[], int size) {
  bool check = true;

  for (int i = 0; i < size - 1; i++) { //each pass depending on the size
    check = false;
    for (int j = 0; j < size - 1; j++) { //interate through the array for swapping
      if (a[j] > a[j + 1]) { //swap if condition found
        swap(a[j], a[j + 1]);
        check = true; //this continues the loop
      }
    }

    if (check == false) { //break if no swaps used in pass
      break;
    }
  }
}

//This function merges an array for merge sort
//@param arr[] an array to sort
//@param lower The lower limit of the array
//@param mid The middle number between lower and upper
//@param upper The upper limit of the array
//@param b[] buffer array for merging
void mergeArr(int arr[], int lower, int mid, int upper, int b[]) {
  int i = lower; //mainly for lower range
  int j = mid + 1; //mainly for upper range
  int k = lower; //marks buffer

  while (i <= mid && j <= upper) { //while both arrays still have elements
    if (arr[i] <= arr[j]) { //i is smaller than j
      b[k] = arr[i];
      k++;
      i++;
    }
    else { //j is smller than i
      b[k] = arr[j];
      k++;
      j++;
    }
  }

  while (i <= mid) //if left array still have left over elements
    { 
      b[k] = arr[i]; 
      i++; 
      k++; 
    } 

  while (j <= upper) //if right array still have left over elements
    { 
      b[k] = arr[j]; 
      j++; 
      k++; 
    } 

  for (i = lower; i < k; i++)  { //copy array to buffer, k is count total count elements in array
    arr[i] = b[i];
  }
}

//This function does the merge sort
//@param arr[] An array to sort
//@param low The lower limit of the array
//@param high The higher limit of the array
//@param b[] Buffer array to use for merging
void mergeSort(int arr[], int low, int high, int b[]) {
  if (low < high) {
    int mid = (low + high) / 2;

    mergeSort(arr, low, mid, b); //recursion making left half
    mergeSort(arr, mid + 1, high, b); //recursion making right half
    mergeArr(arr, low, mid, high, b); //sort and merge arrays
  }
}

int main() {
  int array[] = {5,4,3,2,1}; //array for bubble sort
  int array2[] = {15,14,13,12,11,10,9,8,7,6,5,4,3,2}; //array for merge sort

  int arr_size = sizeof(array2)/sizeof(array2[0]);
  cout << "Array size: " << arr_size << endl;
  int buffer[arr_size]; //buffer for merge sort

  bubbleSort(array, 5); //bubble sorting
  for (int i = 0; i < 5; i++) { //printing result of bubble sort
    cout << array[i] << endl;
  }

  mergeSort(array2, 0, arr_size - 1, buffer); //merge sorting
  for(int i = 0; i < arr_size; i++) { //printing result of merge sort
    cout << array2[i] << " ";
  }

}
#include <iostream>
using namespace std;

void selectionSort(int nums[], int size);
void swap(int nums[], int idx1, int idx2);
void printArr(int* nums, int size);

// 1. get the min element in remaing array
// 2. swap it to the starting position
// 3. shift counter by 1
int main () {
  int nums[] = { 64, 25, 43, 22, 13, 12, 99, 11 };
  int numsLength = sizeof(nums) / sizeof(nums[0]);
  
  cout << "before : ";
  printArr(nums, numsLength);
  selectionSort(nums, numsLength);
  cout << "after  : ";
  printArr(nums, numsLength);  
  
  
  int nums2[] = { 7, 6, 5, 4, 3, 3, 2, 1 };
  int nums2Length = sizeof(nums2) / sizeof(nums2[0]);
  cout << endl << "before : ";
  printArr(nums2, nums2Length);
  selectionSort(nums2, nums2Length);
  cout << "after  : ";
  printArr(nums2, nums2Length);  
  return 0;
}

void selectionSort(int nums[], int size) {
  int minIdx = 0;
  for (int i = 0; i < size-1; i++) {
    int currNum = nums[i];
    int mindIdx = i;
    int minNum = currNum;
    
    for (int j = i+1; j < size; j++) {
      int tempNum = nums[j];
      if (tempNum < minNum) {
        minIdx = j;
        minNum = tempNum;
      }
    }
    
    if (minNum < currNum) {
      swap(nums, i, minIdx);
    }
    
    // cout << "         ";
    // printArr(nums, size);
  } 
}

void swap(int nums[], int idx1, int idx2) {
  int temp = nums[idx1];
  nums[idx1] = nums[idx2];
  nums[idx2] = temp;
}

void printArr(int nums[], int size) {
  cout << "[";
  for (int i = 0; i < size; i++) {
    int num = nums[i];
    cout << num;
    
    if (i < size -1) {
      cout << ", ";
    }
  }
  
  cout << "]" << endl;
  
}

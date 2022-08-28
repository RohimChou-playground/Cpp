#include <iostream>
#include <typeinfo>
using namespace std;

void mergeSort(int  nums[], int startIdx, int endIdx);
void merge(int nums[], int startIdx, int midIdx, int endIdx);
void swap(int nums[], int idx1, int idx2);
string getArrStr(int* nums, int size);
string padSpaces(int numOfSpaces);

// 1. Divide the unsorted list into n sublists, each containing one 
//    element (a list of one element is considered sorted).
// 2. Repeatedly merge sublists to produce new sorted sublists until 
//    there is only one sublist remaining. This will be the sorted list.
int main () {
  int nums[] = { 64, 25, 43, 22, 12, 99, 11 };
  int numsLength = sizeof(nums) / sizeof(nums[0]);
  
  cout << endl << "=============================================================" << endl << endl;
  cout << "before : " << getArrStr(nums, numsLength) << endl;
  mergeSort(nums, 0, numsLength-1);
  cout << "after  : " << getArrStr(nums, numsLength) << endl;
  
  cout << endl << "=============================================================" << endl << endl;
  int nums2[] = { 77, 66, 55, 33, 33, 22, 11 };
  int nums2Length = sizeof(nums2) / sizeof(nums2[0]);
  cout << "before : " << getArrStr(nums2, nums2Length) << endl;
  mergeSort(nums2, 0, nums2Length-1);
  cout << "after  : " << getArrStr(nums2, nums2Length) << endl;
  
  cout << endl << "=============================================================" << endl << endl;
  int nums3[] = { 11, 22, 88, 33, 66, 55, 77 };
  int nums3Length = sizeof(nums3) / sizeof(nums3[0]);
  cout << "before : " << getArrStr(nums3, nums3Length) << endl;
  mergeSort(nums3, 0, nums3Length-1);
  cout << "after  : " << getArrStr(nums3, nums3Length) << endl;
  return 0;
}

int spaceCnt = -1;
void mergeSort(int nums[], int startIdx, int endIdx) {
  spaceCnt++;

  if (startIdx >= endIdx) {
    cout << padSpaces(spaceCnt*4) << "return" << endl;
    spaceCnt--;
    return; // Returns recursively
  }
  
  int midIdx = startIdx + (endIdx - startIdx) / 2;
  cout << padSpaces(spaceCnt*4) << startIdx << "~" << midIdx << "~";
  cout << midIdx+1 << "~" << endIdx << endl;

  mergeSort(nums, startIdx, midIdx);
  mergeSort(nums, midIdx + 1, endIdx);
  merge(nums, startIdx, midIdx, endIdx);
  spaceCnt--;
}

void merge(int nums[], int startIdx, int midIdx, int endIdx) {
  int leftNumsSize = midIdx - startIdx + 1;
  int rightNumsSize = endIdx - midIdx;
  int leftNums[leftNumsSize] = { };
  int rightNums[rightNumsSize] = { };
  
  // copy data to nums
  for (int i = startIdx; i < midIdx+1; i++) {
    leftNums[i-startIdx] = nums[i];
  }
  
  for (int i = midIdx+1; i < endIdx+1; i++) {
    rightNums[i-(midIdx+1)] = nums[i];
  }
  
  cout << padSpaces(spaceCnt*4);
  cout << getArrStr(leftNums, leftNumsSize) << ", ";
  cout << getArrStr(rightNums, rightNumsSize) << endl;
  
  int leftIdx = 0;
  int rightIdx = 0;
  int numsIdx = startIdx;
  while (leftIdx < leftNumsSize && rightIdx < rightNumsSize) {
    int leftNum = leftNums[leftIdx];
    int rightNum = rightNums[rightIdx];
    if (leftNum < rightNum) {
      nums[numsIdx] = leftNum;
      leftIdx++;
    } else {
      nums[numsIdx] = rightNum;
      rightIdx++;  
    }
    numsIdx++;
  }
  
  // copy the remaining eles to nums
  while (leftIdx < leftNumsSize) {
    nums[numsIdx++] = leftNums[leftIdx++];
  }
  while (rightIdx < rightNumsSize) {
    nums[numsIdx++] = rightNums[rightIdx++];
  }
  
  cout << padSpaces(spaceCnt*4) << getArrStr(nums, 7) << endl;
}


void swap(int nums[], int idx1, int idx2) {
  int temp = nums[idx1];
  nums[idx1] = nums[idx2];
  nums[idx2] = temp;
}

string getArrStr(int nums[], int size) {
  string str = "[";
  for (int i = 0; i < size; i++) {
    int num = nums[i];
    str += to_string(num);
    
    if (i < size -1) {
       str += ", ";
    }
  }
  
  str += "]";
  return str;
}

string padSpaces(int numOfSpaces) {
  string str = "";
  for (int i = 0; i < numOfSpaces; i++) {
    str += " ";
  }
  
  return str;
}

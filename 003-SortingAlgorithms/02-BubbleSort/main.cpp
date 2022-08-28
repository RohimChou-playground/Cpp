#include <iostream>
using namespace std;

void bubbleSort(int nums[], int size);
void bubbleSort2(int nums[], int size);
void swap(int nums[], int idx1, int idx2);
string getArrStr(int* nums, int size);

// repeatedly comparing and swapping adjacent items
// 1. compare 2 adjacent elements
// 2. swap it if first is greater then second
// 3. shift counter by 1
int main () {
  int nums[] = { 64, 25, 43, 22, 13, 12, 99, 11 };
  int numsLength = sizeof(nums) / sizeof(nums[0]);
  
  cout << endl << "=============================================================" << endl << endl;
  cout << "before : " << getArrStr(nums, numsLength) << endl;
  bubbleSort2(nums, numsLength);
  cout << "after  : " << getArrStr(nums, numsLength) << endl;
  
  cout << endl << "=============================================================" << endl << endl;
  int nums2[] = { 77, 66, 55, 44, 33, 33, 22, 11 };
  int nums2Length = sizeof(nums2) / sizeof(nums2[0]);
  cout << "before : " << getArrStr(nums2, nums2Length) << endl;
  bubbleSort2(nums2, nums2Length);
  cout << "after  : " << getArrStr(nums2, nums2Length) << endl;
  
  cout << endl << "=============================================================" << endl << endl;
  int nums3[] = { 11, 22, 88, 44, 33, 66, 55, 77 };
  int nums3Length = sizeof(nums3) / sizeof(nums3[0]);
  cout << "before : " << getArrStr(nums3, nums3Length) << endl;
  bubbleSort2(nums3, nums3Length);
  cout << "after  : " << getArrStr(nums3, nums3Length) << endl;
  return 0;
}

void bubbleSort(int nums[], int size) {
  for (int i = 0; i < size-1; i++) {
    cout << "-------- i=" << i << " j=1~" << size-i-1 << " --------" << endl;
    bool swappedAtLast = false;
  
    for (int j = 1; j < size-i; j++) {
      int currNum = nums[j-1];
      int nextNum = nums[j];
      cout << "j=" << j << " " << "curr=" << currNum << " next=" << nextNum << "  ";
      cout << getArrStr(nums, size) << " ";
      
      if (currNum > nextNum) {
        swap(nums, j-1, j);
        if (j == size-i-1) {
          swappedAtLast = true;
        }
        cout << "swap";
      }
      
      cout << endl;
    }
    
    if (swappedAtLast) {
      cout << "                     " << getArrStr(nums, size) << endl;  
    }
  } 
}


// improved (best case O(n))
void bubbleSort2(int nums[], int size) {
  int innerCycle = size;
  for (int i = 0; i < size - 1; i++) {
    cout << "-------- i=" << i << " j=1~" << innerCycle-1 << " --------" << endl;
    bool swappedAtLast = false;
  
    int lastSwapIdx = 0;
    for (int j = 1; j < innerCycle; j++) {
      int currNum = nums[j-1];
      int nextNum = nums[j];
      cout << "j=" << j << " " << "curr=" << currNum << " next=" << nextNum << "  ";
      cout << getArrStr(nums, size) << " ";
      
      if (currNum > nextNum) {
        swap(nums, j-1, j);
        if (j == innerCycle - 1) {
          swappedAtLast = true;
        }
        lastSwapIdx = j;
        cout << "swap";
      }
      
      cout << endl;
    }
    innerCycle = lastSwapIdx;
    
    if (innerCycle == 0) {
      break;
    }
    
    if (swappedAtLast) {
      cout << "                     " << getArrStr(nums, size) << endl;  
    }
  } 
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

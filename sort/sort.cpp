#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  // 1. 冒泡排序
  // -- 每次for循环把最大的元素排到最后，下次for循环遍历的个数少一
  vector<int> bubbleSort(vector<int> &arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
      // 标记是否发生交换，若没有交换则提前退出
      // bool swapped = false;
      for (int j = 0; j < n - 1 - i; j++) {
        if (arr[j] > arr[j + 1]) {
          // 交换相邻的元素
          swap(arr[j], arr[j + 1]);
          // swapped = true;
        }
      }
      // 如果这一趟没有交换，说明数组已经有序
      // if (!swapped)
      //   break;
    }
    return arr;
  }

  // 2. 选择排序
  // 选择排序的基本思想是每次从未排序的部分中选择最小（或最大）元素，然后将其与未排序部分的第一个元素交换。
  // 这样，经过一轮后，最小（或最大）元素就排好了。然后，忽略已排好的元素，继续对剩余的部分进行相同操作。
  // -- 前面都排好了,从后面的数组中选择最小的放在前面的数组的末尾,
  // 这样每一轮循环后，前面的元素是从小到大排序的
  vector<int> selectionSort(vector<int> &arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
      // 假设当前元素为最小值
      int minIndex = i;
      // 找到未排序部分的最小值
      for (int j = i + 1; j < n; j++) {
        if (arr[j] < arr[minIndex]) {
          minIndex = j;
        }
      }
      // 交换最小值与当前位置的元素
      if (minIndex != i) {
        swap(arr[i], arr[minIndex]);
      }
    }
    return arr;
  }

  // 3. 插入排序
  // 前面的数据已经排好，把要插入的元素插入到前面已经排好的数组中。时间复杂度为O(n^2), 空间复杂度为O(1)
  vector<int> insertSort(vector<int> &arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
      int key = arr[i]; // 当前需要插入的元素
      int j = i - 1;
      // 向后移动元素，直到找到插入位置
      while (j >= 0 && arr[j] > key) {
        arr[j + 1] = arr[j];
        j--;
      }
      // 插入当前元素到正确位置
      arr[j + 1] = key;
    }
    return arr;
  }

  // 插入排序
  vector<int> insertSort2(vector<int> &arr) {
    // {9, 10, 2, 1, 5};
    int len = arr.size();
    for (int i = 1; i < len; i++) {
      // current elem as insert elem, prev sequence is sorted well.
      // insert elem to sorted sequence
      int insert_elem = arr[i];
      int position = i;
      while (position > 0 && insert_elem < arr[position - 1]) {
        arr[position] = arr[position - 1];
        position = position - 1;
      }
      arr[position] = insert_elem;
    }
    return arr;
  }
};

int main() {
  Solution *sln = new Solution();
  vector<int> arr{9, 10, 2, 1, 5};
  vector<int> res = sln->bubbleSort(arr);
  // vector<int> res = sln->insertSort(arr);
  for (int i = 0; i < arr.size(); i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
  return 0;
}

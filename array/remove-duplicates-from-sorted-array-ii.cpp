#include <iostream>
#include <vector>
using namespace std;


#include <assert.h>
using namespace std;

class Solution{
  public:
     int removeDuplicates(vector<int>& nums) {
       //thoughts:   fast and slow pointer
       //walk through vector array using fast pointer, and
       //then update slow pointer
       // [0,0,1,1,1,1,2,3,3]
       if (nums.size() <= 2) return nums.size(); 
       unsigned slow = 2;
       for (unsigned int fast = 2; fast < nums.size(); fast++) {
          if(nums[fast] != nums[slow - 2] ) {
              nums[slow] = nums[fast];
              slow++;
          } 
       }
       return slow ;
     }
};

int main() {
  Solution* sln = new Solution();
  vector< vector<int>> nums{{1,1,1,2,2,3},  {2,2,3,4,5,5}};
  vector< int> expectedNums{5, 6};
  for (unsigned int i = 0; i < expectedNums.size(); i++) {
     int length = sln->removeDuplicates(nums[i]);
     cout << "lenght: " << length << endl;
     assert(length == expectedNums[i]);
  }
  return 0;
}

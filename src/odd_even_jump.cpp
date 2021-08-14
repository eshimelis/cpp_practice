#include <vector>
#include <iostream>

using namespace std;

class Solution{
public:

  int oddEvenJumps(vector<int>& array) {

    int solutions = 0;
    bool odd_jump, valid, done;

    unordered_set even;
    unordered_set odd;

    // base case (last index is reachable)
    even.insert(array.size()-1);
    odd.insert(array.size()-1);

    // iterate through the array backwards
    for (auto ii = array.end()-1; ii > array.begin(); ii--) {

      // this is our first jump
      odd_jump = true;
      valid = true;
      done = false;

      while (valid && !done) {

        if (odd_jump) {
          // find next j such that arr[i] <= arr[j], and arr[j] is the smallest value

          auto min = ii;

          valid = false;
          for (auto jj = ii++; jj < array.end(); jj++) {

            if (*jj <= *ii) {

              min = jj;

              if (even.contains(*min)) {
                odd.insert(*ii);
              }

            }

            if (even.contains(*min)) {
              odd.insert(*ii);
            }

          }

        } else {  // even jump

          for (auto jj = ii; jj < array.end(); jj++) {
            
          }
          
        }
      }

      if (current == array.end()) {
        // yay!
        solutions += 1;
      } else {
        cout << "yo let's see if we can make it to the end" << endl;

        valid = true;

        while (valid)
        

      }
    }

    return solutions;
  }
};


int main() {

  vector<int> input{10,13,12,14,15};
  int expected = 2;

  Solution solution = Solution();

  if (solution.oddEvenJumps(input) == expected) {
    cout << "correct" << endl;
  } else {
    cout << "wrong" << endl;
  }
}

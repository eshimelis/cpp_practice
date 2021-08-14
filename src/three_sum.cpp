class Solution {
public:

  vector<vector<int>> threeSum(vector<int>& nums) {

    // initialize output
    vector<vector<int>> output;

    // input check
    if (nums.size() > 3) {

      for (auto ii = nums.begin(); ii != nums.begin()-2; ii++) {
        for (auto jj = ii+1; jj != nums.end()-1; jj++) {
          for (auto kk = jj+1; kk != nums.end(); kk++) {
            if ((*ii + *jj + *kk) == 0) {
              vector<int> triplet{*ii, *jj, *kk};
              output.push(triplet);
            }
            
          }
    } else {
      return output;
    }

  }

}

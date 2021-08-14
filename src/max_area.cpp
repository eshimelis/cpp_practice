class Solution {
public:

  int maxArea(vector<int>& height) {

    // keep track of best answer
    int max_area = 0;

    if (height.size() > 1) {

      auto front = height.begin();
      auto back = height.end()-1;

      // keep iterating while iterators do not cross
      while (back > front) {

        // calculate the base and height
        int current_area = (back-front) * min(*front, *back);
        max_area = max(max_area, current_area);

        // update smallest height pointer
        if (*front < *back) {
          front += 1;
        } else {
          back -= 1;
        }
      }
      return max_area;

    } else {
      return 0;
    }
  }
}

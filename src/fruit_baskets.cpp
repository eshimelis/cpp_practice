class Solution {
public:

  int count_fruits(map<int,int>& basket) {
    int sum = 0;
    for (auto it = basket.begin(); it < basket.end(); it++) {
      sum += basket[*it];
    }
    return sum;
  }

  int 

  int totalFruit(vector<int>& fruits) {

    int n = fruits.size();
    int max_size = 1;
    int current_size = 0;
    size_t b_size = 2;
    vector<int> basket_order;
    map<int, int> basket;
    int a, b;

    if (n > b_size) {

      // add our first fruit
      basket_order.push_back(fruits[0]);
      basket.insert({fruits[0], 0});

      // one iteration through
      for (auto it = fruits.begin(); it != fruits.end(); it++) {

        if (basket.find(*it) != basket.end()) {  // yay, fruit we can pick

          // count it
          basket[*it] += 1;

          // move to back
          auto pos = find(basket_order.begin(), basket_order.end(), *it);

          cout << *pos << endl;

          basket_order.push_back(*it);

          // basket_order.erase(pos);
          basket[*it] += 1;


        } else {

          if (basket.size() < b_size) { // fruit we haven't seen, but there's room

            basket.insert({*it, 1});
            basket_order.push_back(*it);

          } else { // no room, gotta restart

            // remove furthest fruit type
            basket.erase(*basket_order.begin());
            basket_order.erase(basket_order.begin());

            // add new fruit
            basket.insert({*it, 1});
            basket_order.push_back(*it);
          }
        }
        max_size = max(max_size, count_fruits(basket));
      }
      return max_size;
    } else {
      return fruits.size();
    }
  }
};

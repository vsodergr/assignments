#include <iostream>
#include <random>
#include <set>
#include <map>

const int n = 10000;
const int n_bins = 34;

int main() {
  srand(time(0));
  std::set<int> rand_nbrs{n, 0};
  std::map<int, int> histogram({n_bins, 0});
  std::map<int, int>::iterator itr;

  for (int i = 0; i < n; i++) rand_nbrs.emplace(rand() % 34);

  for (itr = histogram.begin(); itr != histogram.end(); itr++) {
    std::cout << itr->first << " " << itr->second << "\n";
  }

  // for (int i = 0; i < histogram.size(); i++) {
  //   std::cout << i << " genereated " << histogram.count(i) << "\n";
  // }

  std::cout << "\n";
}
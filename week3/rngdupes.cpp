/*
 * Generate random numbers between 0-33, ten thousand times, then print how many
 * duplicates of each number you have generated -- print in ascending order.
 */

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <random>
#include <vector>

const int n = 10000;
const int n_bins = 34;

bool compare(std::pair<int, int>& a, std::pair<int, int>& b) {
  return a.second < b.second;
}

int main() {
  srand(time(0));
  std::vector<std::pair<int, int>> histogram(n_bins, {0, 0});

  for (size_t i = 0; i < n; i++) {
    int rnr = rand() % 34;
    histogram.at(rnr).first = rnr;
    histogram.at(rnr).second++;
  }

  std::cout << "\n";

  // std::sort(histogram.begin(), histogram.end(), compare);
  // I learned that a lambda could be aproppriate for comparing.
  std::sort(histogram.begin(), histogram.end(),
            [](const auto& a, const auto& b) { return a.second < b.second; });

  std::cout << "Sorted set of " << n << " randomized numbers (0-33):\n";
  std::cout << std::setw(3) << "Key"
            << ":" << std::setw(6) << "Value"
            << "\n";

  for (const auto& each : histogram) {
    std::cout << std::setw(3) << each.first << ":" << std::setw(6)
              << each.second << "\n";
  }

  std::cout << "\n";
}
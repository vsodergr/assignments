/*
 * We want to generate 1024 random integers, then given a new random number;
 * find two integers which are the closest to the given number (smaller, and
 * bigger) with less than twelve lookups.
 *
 * Tip: Create a sorted container and populate it, then pick a random integer
 * and look for the boundaries – implement your own logarithmic search if you
 * are in the mood for it ☺
 */

#include <iostream>
#include <random>
#include <set>

const int n = 1024;
const int kTenThousand = 10000;

int main() {
  srand(time(0));
  std::set<int> nbr_set;
  const int lonely_number{rand() % kTenThousand};

  // Randomize some numbers between zero and a lot.
  for (size_t i = 0; i < n; i++) nbr_set.insert(rand() % kTenThousand);

  // Find friends for the lonley number.
  auto lil_buddy{std::prev(nbr_set.lower_bound(lonely_number))};
  auto big_buddy{std::next(lil_buddy)};
  if (*big_buddy == lonely_number) big_buddy = std::next(lil_buddy, 2);

  // Print comradery with a sanity check.
  if (lonely_number > *lil_buddy && *big_buddy > lonely_number) {
    std::cout << "The lonely number (" << lonely_number
              << ") now has little buddy (" << *lil_buddy
              << ") and bigger buddy (" << *big_buddy
              << ") as friends.\nI think they found eachother in at most 11 "
                 "lookups.\n";
  } else {
    std::cout << "The lonely number must be bigger than little buddy and "
                 "smaller than big buddy.\nSomething has gone wrong here!\n";
  }
}
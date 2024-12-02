/*
 * Copyright 2024 Le Van Minh
 */

#include <bits/stdc++.h>
#include <fmt/base.h>
#include <fmt/ranges.h>

#include <functional>
#include <ios>
#include <iostream>
#include <string>

// ordered_set
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using __gnu_pbds::null_type;
using __gnu_pbds::rb_tree_tag;
using __gnu_pbds::tree;
using __gnu_pbds::tree_order_statistics_node_update;
using std::less;
typedef tree<int, null_type, less<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_set;

// pretty print containers
#include <sstream>

using std::string;
using std::stringstream;
template <typename T>
string dumpContainer(const T& container, std::string sep) {
  typename T::const_iterator itr;
  stringstream sstream;

  for (itr = container.begin(); itr != container.end(); ++itr) {
    // insert a seperator char for all but the first element
    if (itr != container.begin()) {
      sstream << sep;
    }

    sstream << *itr;
  }

  return sstream.str();
}

// main with fast io
using std::cin;
using std::ios_base;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}

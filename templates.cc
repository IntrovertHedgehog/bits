#include <bits/stdc++.h>
#include <fmt/base.h>
#include <fmt/ranges.h>

using namespace std;

// ordered_set
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_set;

// pretty print containers
#include <sstream>

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
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}

// longest increasing subsequences

#include <bits/stdc++.h>

#include <sstream>
#include <vector>

using namespace std;

template <typename T>
string dumpContainer(const T &container, std::string sep) {
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

unsigned lis(const vector<int> &vec) {
  vector<int> M{vec[0]};

  for (const int &e : vec) {
    if (e > M.back()) {
      M.push_back(e);
    } else {
      int lo = 0, hi = M.size() - 1;
      while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (M[mid] >= e) {
          hi = mid - 1;
        } else {
          lo = mid + 1;
        }
      }

      M[lo] = e;
    }
  }

  return M.size();
}

unsigned lis(const vector<int> &vec, vector<int> &length) {
  length.clear();
  vector<int> M{vec[0]};

  for (const int &e : vec) {
    if (e > M.back()) {
      M.push_back(e);
      length.push_back(M.size());
    } else {
      int lo = 0, hi = M.size() - 1;
      while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (M[mid] >= e) {
          hi = mid - 1;
        } else {
          lo = mid + 1;
        }
      }

      length.push_back(lo + 1);
      M[lo] = e;
    }
  }

  return M.size();
}

unsigned lis(const vector<int> &vec, vector<int> &length, vector<int> &trace) {
  length.clear();
  trace.clear();
  vector<int> mem{-1};  // contains index, not value

  for (unsigned i = 0; i < vec.size(); ++i) {
    const int &e = vec[i];
    int lo = 1, hi = mem.size() - 1;
    while (lo <= hi) {
      int mid = lo + (hi - lo) / 2;
      if (vec[mem[mid]] >= e) {
        hi = mid - 1;
      } else {
        lo = mid + 1;
      }
    }

    if (lo >= mem.size()) {
      mem.push_back(i);
    } else {
      mem[lo] = i;
    }

    length.push_back(lo);
    trace.push_back(mem[lo - 1]);
  }

  return mem.size() - 1;
}

int main() {
  // 1 2 2 3 2 3 3 4
  istringstream input("0 8 4 12 2 10 6 14 1 9 5 13 3 11 7 15");
  vector<int> vec{0};
  while (input >> vec.back()) {
    vec.push_back(0);
  }
  vec.pop_back();

  vector<int> length, trace;
  unsigned l = lis(vec, length);
  cout << l << endl;
  cout << dumpContainer(length, ", ") << endl;
  // cout << dumpContainer(trace, ", ") << endl;

  // vector<int> str{-1};
  // for (unsigned i = 0; i < vec.size(); ++i) {
  //   if (length[i] == l) {
  //     str.back() = i;
  //     break;
  //   }
  // }
  //
  // while (str.back() != -1) {
  //   str.push_back(trace[str.back()]);
  // }
  //
  // for (auto beg = str.rbegin() + 1; beg != str.rend(); ++beg) {
  //   cout << vec[*beg] << " ";
  // }
  // cout << endl;
}

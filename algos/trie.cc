#include <bits/stdc++.h>

#include <map>
#include <string>

using namespace std;

struct TrieNode {
  bool terminate{false};
  map<char, TrieNode *> children;
};

struct Trie {
  TrieNode *root{new TrieNode()};

  void insert(string s) {
    TrieNode *cur = root;
    for (char &e : s) {
      if (cur->children.find(e) == cur->children.end()) {
        cur->children[e] = new TrieNode();
      }
      cur = cur->children[e];
    }
    cur->terminate = true;
  }

  void erase(string s) {
    // not implemented
  }

  bool query(const string &s) {
    TrieNode *cur = root;
    for (char e : s) {
      if (cur->children.find(e) == cur->children.end()) {
        return false;
      }
      cur = cur->children[e];
    }
    return cur->terminate;
  }


  // return the longest string in the tree that is a prefix of s
  unsigned long longestPrefixInTree(const string &s) {
    TrieNode *cur = root;
    unsigned long res = 0, buffer = 0;
    for (const char &e : s) {
      if (cur->children.find(e) != cur->children.end()) {
        cur = cur->children[e];
        buffer += 1;

        if (cur->terminate) {
          res += buffer;
          buffer = 0;
        }
      } else {
        break;
      }
    }

    return res;
  }

  // find the longest common prefix of s with a string in the tree
  unsigned long longestprefixMatch(const string &s) {
    TrieNode *cur = root;
    unsigned long res = 0;
    for (const char &e : s) {
      if (cur->children.find(e) != cur->children.end()) {
        cur = cur->children[e];
        res += 1;
      } else {
        break;
      }
    }
    return res;
  }
};

int main() {
  Trie trie{};
  cout << trie.query("") << endl;
  cout << trie.query("iam") << endl;
  trie.insert("shit");
  cout << trie.query("shit") << endl;
  trie.insert("iam");
  cout << trie.query("iam") << endl;
  cout << trie.longestprefixMatch("sh") << endl;
  cout << trie.longestprefixMatch("shithead") << endl;
  cout << trie.longestPrefixInTree("sh") << endl;
  cout << trie.longestPrefixInTree("shithead") << endl;
  trie.insert("/bag/bdo/bga/bgg");
  cout << trie.query("/bag/bdo/bga/bgq") << endl;
  cout << trie.longestPrefixInTree("/bag/bdo/bga/bgq/bgt") << endl;
}

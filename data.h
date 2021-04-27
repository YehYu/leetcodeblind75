#ifndef DATA_H
#define DATA_H

#include <string>
#include <unordered_map>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//208. Implement Trie (Prefix Tree)
class Trie
{
    unordered_map<char, Trie*> childMap;
    bool isWord;

public:
    /** Initialize your data structure here. */
    Trie() : isWord(false)
    {

    }

    /** Inserts a word into the trie. */
    void insert(string word)
    {
        Trie *root = this;
        for (const char &c : word)
        {
            if (root->childMap.find(c) == root->childMap.end())
                root->childMap[c] = new Trie();
            root = root->childMap[c];
        }
        root->isWord = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word)
    {
        Trie *root = this;
        for (const char &c : word)
        {
            if (root->childMap.find(c) == root->childMap.end())
                return false;
            root = root->childMap[c];
        }
        return root->isWord;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix)
    {
        Trie *root = this;
        for (const char &c : prefix)
        {
            if (root->childMap.find(c) == root->childMap.end())
                return false;
            root = root->childMap[c];
        }
        return true;
    }
};

class TrieS
{
    TrieS *childrenArray[26];
    bool isWord;

public:
    /** Initialize your data structure here. */
    TrieS() : isWord(false)
    {
        for (int i = 0; i < 26; i++)
            childrenArray[i] = nullptr;
    }

    /** Inserts a word into the trie. */
    void insert(string word)
    {
        TrieS *root = this;
        for (const char &c : word)
        {
            if (!root->childrenArray[c - 'a'])
                root->childrenArray[c - 'a'] = new TrieS();
            root = root->childrenArray[c-'a'];
        }
        root->isWord = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word)
    {
        TrieS *root = this;
        for (const char &c : word)
        {
            if (!root->childrenArray[c - 'a'])
                return false;
            root = root->childrenArray[c - 'a'];
        }
        return root->isWord;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix)
    {
        TrieS *root = this;
        for (const char &c : prefix)
        {
            if (!root->childrenArray[c - 'a'])
                return false;
            root = root->childrenArray[c - 'a'];
        }
        return true;
    }
};

#endif

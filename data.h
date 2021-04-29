#ifndef DATA_H
#define DATA_H

#include <string>
#include <unordered_map>
#include <queue>
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

//TrieNode
struct TrieNode
{
    unordered_map<char, TrieNode *> childMap;
    bool isComplete;
    TrieNode() : isComplete(false){}
};

//208. Implement Trie (Prefix Tree)
class Trie
{
    TrieNode* node;

    TrieNode *getEndTrie(string word)
    {
        TrieNode *root = node;
        for (const char &c : word)
        {
            if (root->childMap.find(c) == root->childMap.end())
                return nullptr;
            root = root->childMap[c];
        }
        return root;
    }

public:
    /** Initialize your data structure here. */
    Trie() : node(new TrieNode())
    {
    }
    ~Trie()
    {
        for (unordered_map<char, TrieNode *>::iterator it = node->childMap.begin(); it != node->childMap.end(); it++)
            delete it->second;
        node->childMap.clear();
    }

    /** Inserts a word into the trie. */
    void insert(string word)
    {
        TrieNode *root = node;
        for (const char &c : word)
        {
            if (root->childMap.find(c) == root->childMap.end())
                root->childMap[c] = new TrieNode();
            root = root->childMap[c];
        }
        root->isComplete = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word)
    {
        TrieNode *root = getEndTrie(word);
        return (root && root->isComplete);
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix)
    {
        TrieNode *root = getEndTrie(prefix);
        return root;
    }
};

//211. Design Add and Search Words Data Structure
class WordDictionary
{
    TrieNode* node;

public:
    /** Initialize your data structure here. */
    WordDictionary() : node(new TrieNode())
    {
    }

    void addWord(string word)
    {
        TrieNode *root = node;
        for (const char &c : word)
        {
            if (root->childMap.find(c) == root->childMap.end())
                root->childMap[c] = new TrieNode();
            root = root->childMap[c];
        }
        root->isComplete = true;
    }

    bool search(string word)
    {
        return searchBypos(word, 0, node);
    }

    bool searchBypos(const string &word, int pos, TrieNode *dict)
    {
        if (pos >= word.size())
            return dict->isComplete;

        const char &c = word[pos];
        if (c == '.')
        {
            for (unordered_map<char, TrieNode *>::iterator it = dict->childMap.begin(); it != dict->childMap.end(); it++)
                if (searchBypos(word, pos + 1, it->second))
                    return true;
        }
        else if (dict->childMap.find(c) != dict->childMap.end())
        {
            return searchBypos(word, pos + 1, dict->childMap[c]);
        }
        return false;
    }
};

#endif

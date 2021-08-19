#ifndef DATA_H
#define DATA_H

#include <string>
#include <unordered_map>
#include <queue>
#include <iostream>

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
    friend ostream &operator<<(ostream &ostr, TreeNode *rhs);
};
ostream &operator<<(ostream &ostr, TreeNode *rhs)
{
    if (!rhs)
        return ostr;

    ostr << "[";
    queue<TreeNode *> nodeQueue;
    nodeQueue.push(rhs);
    while (nodeQueue.size())
    {
        TreeNode *cur = nodeQueue.front();
        if (cur)
        {
            ostr << (cur->val) << ", ";
            TreeNode *left = cur->left;
            TreeNode *right = cur->right;
            nodeQueue.push(left);
            nodeQueue.push(right);
        }
        else
        {
            ostr << "nullptr, ";
        }
        nodeQueue.pop();
    }
    ostr << "]";
    return ostr;
}

//TrieNode
struct TrieNode
{
    unordered_map<char, TrieNode *> childMap;
    bool isComplete;
    TrieNode() : isComplete(false) {}
};

//208. Implement Trie (Prefix Tree)
class Trie
{
    TrieNode *node;

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
    TrieNode *node;

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

//212. Word Search II
struct TrieWordSearchNode
{
    vector<TrieWordSearchNode *> childVec;
    string word;
    TrieWordSearchNode() : word(""), childVec(26, nullptr) {}
    ~TrieWordSearchNode()
    {
        for (TrieWordSearchNode *node : childVec)
            delete node;
        childVec.clear();
    }
    void addNode(const string &word)
    {
        TrieWordSearchNode *root = this;
        for (const char &i : word)
        {
            int &&c = i - 'a';
            if (!root->childVec[c])
                root->childVec[c] = new TrieWordSearchNode();
            root = root->childVec[c];
        }
        root->word = word;
    }
};

//295. Find Median from Data Stream
class MedianFinder
{
    //最大的優先取出
    priority_queue<int> min_queue;
    //最小的優先取出
    priority_queue<int, vector<int>, greater<int>> max_queue;

public:
    /** initialize your data structure here. */
    MedianFinder()
    {
    }

    void addNum(int num)
    {
        if (min_queue.size() > max_queue.size())
        {
            min_queue.push(num);
            max_queue.push(min_queue.top());
            min_queue.pop();
        }
        else
        {
            max_queue.push(num);
            min_queue.push(max_queue.top());
            max_queue.pop();
        }
    }

    double findMedian()
    {
        return (min_queue.size() > max_queue.size()) ? min_queue.top() : (min_queue.top() + max_queue.top()) * 0.5;
    }
};

#endif

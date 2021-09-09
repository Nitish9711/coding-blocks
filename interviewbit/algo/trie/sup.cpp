#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;
 
// Data structure to store a Trie node
struct TrieNode
{
    // each node stores a map to its child nodes
    map<char, TrieNode*> child;
 
    // keep track of the total number of times the current node is visited
    // while inserting data in Trie
    int freq = 0;
};
 
// Function to insert a given string into a Trie
void insert(TrieNode* &root, string word)
{
    // start from the root node
    TrieNode* curr = root;
    for (char c: word)
    {
        // create a new node if the path doesn't exist
        if (curr->child.find(c) == curr->child.end()) {
            curr->child[c] = new TrieNode();
        }
 
        // increment frequency
        curr->child[c]->freq++;
 
        // go to the next node
        curr = curr->child[c];
    }
}
 
// Function to recursively traverse the Trie in a preorder fashion and
// print the shortest unique prefix for each word in the Trie
void printShortestPrefix(TrieNode *root, string word_so_far)
{
    if (root == nullptr) {
        return;
    }
 
    // print `word_so_far` if the current Trie node is visited only once
    if (root->freq == 1)
    {
        cout << word_so_far << endl;
        return;
    }
 
    // recur for all child nodes
    for (auto &child: root->child) {
        printShortestPrefix(child.second, word_so_far + child.first);
    }
}
 
// Find the shortest unique prefix for every word in a given array
void findShortestPrefix(vector<string> &words)
{
    // construct a Trie from the given items
    TrieNode* root = new TrieNode();
    for (string s: words) {
        insert(root, s);
    }
 
    // Recursively traverse the Trie in a preorder fashion to list all prefixes
    printShortestPrefix(root, "");
}
 
int main()
{
    vector<string> words = { "AND", "BOOL", "BONFIRE", "CATCH", "CASE", "CHAR" };
    findShortestPrefix(words);
 
    return 0;
}



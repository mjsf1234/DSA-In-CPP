#include <iostream>
using namespace std;

class TrieNode
{
public:
    char data;
    TrieNode **children;
    bool isTerminal;

    TrieNode(char data)
    {
        this->data = data;
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie
{

    TrieNode *root;

public:
    Trie()
    {
        root = new TrieNode('\0');
    }
    void insertWordHelper(TrieNode *root, string word)
    {
        // base case
        if (word.size() == 0)
        {
            root->isTerminal = true;
            return;
        }
        // small calculation
        int index = word[0] - 'a';
        TrieNode *child;
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }
        // recursion calling
        insertWordHelper(child, word.substr(1));
    }
    void insertWord(string word)
    {
        insertWordHelper(root, word);
    }

    bool search(string word)
    {
        return searchHelper(root, word);
    }
    bool searchHelper(TrieNode *root, string word)
    {
        if (word.size() == 0)
        {
            if (root->isTerminal)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        int index = word[0] - 'a';
        if (root->children[index] != NULL)
        {
            return searchHelper(root->children[index], word.substr(1));
        }
        else
        {
            return false;
        }
    }
    void removeWordHelper(TrieNode *root, string word)
    {
        if (word.size() == 0)
        {
            root->isTerminal = false;
            return;
        }

        int index = word[0] - 'a';
        TrieNode *child;
        if (root->children[index] != NULL)
        {
            child = root->children[index];
            removeWordHelper(child, word.substr(1));
        }
        else
        {
            return;
        }
        if (root->children[index]->isTerminal == false)
        {
            for (int i = 0; i < 26; i++)
            {
                if (root->children[i] != NULL)
                {
                    return;
                }
            }
            delete child;
            root->children[index] = NULL;
        }
    }
    void removeWord(string word)
    {
        removeWordHelper(root, word);
    }
};

int main()
{
    Trie *test = new Trie();
    test->insertWord("are");
    test->insertWord("and");
    test->insertWord("dot");
    cout << test->search("dot") << endl;
    test->removeWord("dot");
    cout << test->search("dot") << endl;
    return 0;
}
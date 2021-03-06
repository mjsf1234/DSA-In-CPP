#include <iostream>
using namespace std;
#include <vector>
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

    // TODO InsertHelper function
    void insertWordHelper(TrieNode *root, string word)
    {
        // base case
        if (word.size() == 0)
        {
            if (!root->isTerminal)
            {
                root->isTerminal = true;
            }
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
    // TODO insert fucntion for users
    void insertWord(string word)
    {
        insertWordHelper(root, word);
    }

    // TODO search fucnction for user
    bool search(string word)
    {
        return searchHelper(root, word);
    }
    //?search helper fucnction
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

    //!________
    bool searchPattern(string word)
    {
        return searchPatternHelper(root, word);
    }
    //?search helper fucnction
    bool searchPatternHelper(TrieNode *root, string word)
    {
        if (word.size() == 0)
        {
            return true;
        }
        int index = word[0] - 'a';
        if (root->children[index] != NULL)
        {
            return searchPatternHelper(root->children[index], word.substr(1));
        }
        else
        {
            return false;
        }
    }

    vector<string> getAllBelowNode(TrieNode *root)
    {
        vector<string> main;
        if (root->isTerminal)
        {
            string t = "";
            t = t + root->data;
            main.push_back(t);
        }
        for (int i = 0; i < 26; i++)
        {
            vector<string> child;
            if (root->children[i] != NULL)
            {
                child = getAllBelowNode(root->children[i]);
                for (int i = 0; i < child.size(); i++)
                {
                    string word = root->data + child[i];
                    main.push_back(word);
                }
            }
        }
        return main;
    }
    vector<string> autoCompleteHelper(TrieNode *root, string pattern)
    {
        vector<string> rootNode;
        if (pattern.size() == 0)
        {
            rootNode = getAllBelowNode(root);
            return rootNode;
        }

        int index = pattern[0] - 'a';
        TrieNode *child;
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            vector<string> v;
            return v;
        }
        vector<string> v = autoCompleteHelper(child, pattern.substr(1));
        if (root->data != '\0')
        {
            for (int i = 0; i < v.size(); i++)
            {
                string rootData;
                rootData.push_back(root->data);
                string word = rootData + v[i];
                rootNode.push_back(word);
            }
            return rootNode;
        }

        return v;
    }

    void autoComplete(vector<string> input, string pattern)
    {
        // insert all the word into the tries
        for (int i = 0; i < input.size(); i++)
        {
            insertWord(input[i]);
        }

        vector<string> v = autoCompleteHelper(root, pattern);

        for (int i = 0; i < v.size(); i++)
        {
            cout << v[i] << endl;
        }
    }
};

// TODO patter matching (implementation of suffixe tries)

string trim(string value, int start)
{
    string Newstr;
    for (int idx = start; idx < value.length(); idx++)
    {
        Newstr += value[idx];
    }

    return Newstr;
}

bool patternMatching(vector<string> vect, string pattern)
{
    Trie t;
    for (int i = 0; i < vect.size(); i++)
    {
        string word = vect[i];

        for (int i = 0; i < word.size(); i++)
        {
            string next = trim(word, i);
            t.insertWord(next);
        }
    }

    return t.searchPattern(pattern);
}

int main()
{
    Trie test;
    vector<string> v = {"do", "dont", "note", "den", "no", "not", "notes"};
    test.autoComplete(v, "do");
    test.search("do");

    /* cout << patternMatchindg(v, "ab");*/
    return 0;
}
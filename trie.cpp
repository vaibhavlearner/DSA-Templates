#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    Node *arr[26];
    bool flag = 0;
    int ew = 0;
    int cp = 0;
    bool contain(char ch)
    {
        return (arr[ch - 'a'] != NULL);
    }
    Node *get(char ch)
    {
        return arr[ch - 'a'];
    }
    void put(char ch, Node *node)
    {
        arr[ch - 'a'] = node;
    }
    void incend()
    {
        ew++;
    }
    void incpre()
    {
        cp++;
    }
    void decend()
    {
        ew--;
    }
    void decpre()
    {
        cp--;
    }
};
class Trie
{
public:
    Node *root;
    Trie()
    {
        // Write your code here.
        root = new Node();
    }

    void insert(string &s)
    {
        // Write your code here.
        Node *node = root;
        for (int i = 0; i < s.size(); i++)
        {
            if (!node->contain(s[i]))
            {
                node->put(s[i], new Node());
            }
            node = node->get(s[i]);
            node->incpre();
        }
        node->incend();
    }

    int countWordsEqualTo(string &s)
    {
        // Write your code here.
        Node *node = root;
        for (int i = 0; i < s.size(); i++)
        {
            if (node->contain(s[i]))
            {
                node = node->get(s[i]);
            }
            else
            {
                return 0;
            }
        }
        return node->ew;
    }

    int countWordsStartingWith(string &s)
    {
        // Write your code here.
        Node *node = root;
        for (int i = 0; i < s.size(); i++)
        {
            if (node->contain(s[i]))
            {
                node = node->get(s[i]);
            }
            else
            {
                return 0;
            }
        }
        return node->cp;
    }

    void erase(string &s)
    {
        // Write your code here.
        Node *node = root;
        for (int i = 0; i < s.size(); i++)
        {
            if (node->contain(s[i]))
            {
                node = node->get(s[i]);
                node->decpre();
            }
            else
            {
                return;
            }
        }
        node->decend();
    }
};

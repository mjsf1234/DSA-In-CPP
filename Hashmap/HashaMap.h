#include <iostream>
using namespace std;

template <typename V>
class MapNode
{
    string key;
    V value;
    MapNode *next;

    MapNode(string key, V value)
    {
        this->key = key;
        this->value = value;
        this->next = NULL;
    }

    ~MapNode()
    {
        delete next;
    }
};

template <typename V>
class ourmap
{
public:
    int count;
    int bucketSize = 20;
    MapNode<V> **buckets;
    ourmap()
    {
        buckets = new MapNode<V> *[bucketSize];
    }

    ~ourmap()
    {
        for (int i = 0; i < bucketSize; i++)
        {
            delete buckets[i];
        }
        delete[] buckets;
    }

private:
    int getBucketIndex(string key)
    {
        int hashCode;
        int currentCoeff = 1;
        for (int i = key.length() - 1; i <= 0; i--)
        {
            hashCode += key[i] * currentCoeff;
            hashCode = hashCode % bucketSize;
            currentCoeff *= 37;
            currentCoeff = currentCoeff % bucketSize;
        }
        return hashCode % bucketSize;
    }

public:
    int size()
    {
        return count;
    }

    void insert(string key, V value)
    {
        int bucketIndex = getBucketIndex(key);
        MapNode<V> *head = buckets[bucketIndex];
        while (head != NULL)
        {
            if (head->key == key)
            {
                head->value = value;
                return;
            }
            head = head->next;
        }
        head = buckets[bucketIndex];
        MapNode<V> *node = new MapNode<V>(key, value);
        node->next = head;
        buckets[bucketIndex] = node;
        count++;
    }

    V remove(string key)
    {
        int bucketIndex = getBucketIndex(key);
        MapNode<V> *head = buckets[bucketIndex];
        MapNode<V> *prev = NULL;
        while (head != NULL)
        {
            if (head->key == key)
            {
                if (prev == NULL)
                {
                    buckets[bucketIndex] = head->next;
                }
                else
                {
                    prev->next = head->next;
                }
                head->next = NULL;
                V value = head->value;
                delete head;
                count--;
                return value;
            }
            prev = head;
            head = head->next;
        }
        return 0;
    }

    V getValue(string key)
    {
        int bucketIndex = getBucketIndex(key);
        MapNode<V> *head = buckets[bucketIndex];
        while (head != NULL)
        {
            if (head->key == key)
            {
                return head->value;
            }
            head = head->next;
        }
        return 0;
    }
};
#include <iostream>
using namespace std;

template <typename V>
class MapNode
{
public:
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
    int count = 0;
    int numBuckets = 10;
    MapNode<V> **buckets;
    ourmap()
    {
        buckets = new MapNode<V> *[numBuckets];
        for (int i = 0; i < numBuckets; i++)
        {
            buckets[i] = NULL;
        }
    }

    ~ourmap()
    {
        for (int i = 0; i < numBuckets; i++)
        {
            delete buckets[i];
        }
        delete[] buckets;
    }

private:
    void rehash()
    {
        cout << "reshaed " << endl;
        MapNode<V> **temp = buckets;                // To store the old bucket
        buckets = new MapNode<V> *[2 * numBuckets]; // doubling the size
        for (int i = 0; i < 2 * numBuckets; i++)
        {
            buckets[i] = NULL; // initialising each head pointer to NULL
        }
        int oldBucketCount = numBuckets;
        numBuckets *= 2; // updating new size
        count = 0;
        for (int i = 0; i < oldBucketCount; i++)
        {
            MapNode<V> *head = temp[i];
            while (head != NULL)
            {
                string key = head->key;
                V value = head->value;
                insert(key, value); // inserting each value of old bucket
                // into the new one
                head = head->next;
            }
        }
        // deleting the old bucket
        for (int i = 0; i < oldBucketCount; i++)
        {
            MapNode<V> *head = temp[i];
            delete head;
        }
        delete[] temp;

        for (int i = 0; i < 20; i++)
        {
            cout << " rehashed " << buckets[i] << endl;
        }
        cout << "__________" << endl;
    }

    int getBucketIndex(string key)
    { // to provide the index using hash function
        int hashCode = 0;
        int currentCoeff = 1;
        for (int i = key.length() - 1; i >= 0; i--)
        {
            hashCode += key[i] * currentCoeff;
            hashCode = hashCode % numBuckets;
            currentCoeff *= 37; // taking p = 37
            currentCoeff = currentCoeff % numBuckets;
        }
        return hashCode % numBuckets;
    }

public:
    int size()
    {
        return count;
    }

    void insert(string key, V value)
    {
        int bucketIndex = getBucketIndex(key);
        cout << "key :" << key << " bucketIndex " << bucketIndex << endl;
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
        // Now we will check the load factor after insertion.
        double loadFactor = (1.0 * count) / numBuckets;
        if (loadFactor > 0.7)
        {
            rehash(); // We will rehash.
        }
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
                V value = head->value;
                head->next = NULL;
                delete head;
                count--;
                cout << "count is " << count << endl;
                return value;
            }
            prev = head;
            head = head->next;
        }
        return 0;
    }

    V getValue(string key)
    {
        int bucketIndex = getBucketIndex(key);   // find the index
        MapNode<V> *head = buckets[bucketIndex]; // head of linked list
        while (head != NULL)
        {
            if (head->key == key)
            { // if found, returned the value
                return head->value;
            }
            head = head->next;
        }
        return 0; // if not found, returning 0 as default value.
    }
};
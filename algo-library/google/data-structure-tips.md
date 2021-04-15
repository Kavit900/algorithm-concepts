## To Insert, delete in O(1) worst case

-> `unordered_map<int, int>`
-> `unordered_multimap<int, int>`

## To find in O(1) average case

-> `unordered_multimap<int, int>`

## SET

-> Use set to find top k elements in O(k) times, because in set, everything is stored as binary search tree, using rbegin(), we can start with the rightmost element in the tree, which is of the highest value and move towards beginning of the container in a decreasing sorted order.


## Get Random element from collection

```
class RandomizedCollection {
    unordered_multimap<int, int> valmap;
    vector<unordered_multimap<int, int>::iterator> itvec;
    
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        srand(time(0));
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        auto it = valmap.insert(pair<int, int>{val, itvec.size()});
        itvec.push_back(it);
        return true;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        auto it = valmap.find(val);
        if (it == valmap.end())
            return false;
        
        int i = it->second;
        swap(itvec[i], itvec[itvec.size() - 1]); // swap i with the last element
        itvec[i]->second = i;
        itvec.pop_back();  // pop_back() takes O(1) in average
        valmap.erase(it);
        
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        return (itvec[rand() % itvec.size()])->first;
    }
};
```

## Dp - solution involving all possible moves for a knight on a phone dialer pad

-> 935 problem

```
class Solution {

  // Phone dialer pad
  char mat[4][3] = {
    {
      '1',
      '2',
      '3'
    },
    {
      '4',
      '5',
      '6'
    },
    {
      '7',
      '8',
      '9'
    },
    {
      '*',
      '0',
      '*'
    }
  };
  int dp[4][3][5005] = {
    0
  };

  int xx[8] = {
    -2,
    -2,
    -1,
    1,
    2,
    2,
    -1,
    1
  };
  int yy[8] = {
    -1,
    1,
    2,
    2,
    -1,
    1,
    -2,
    -2
  };
  int nn = 4;
  int mm = 3;
  set < string > st;
  public:
    bool isOk(int x, int y) {
      if (x < 0 || x >= nn || y < 0 || y >= mm || mat[x][y] == '*')
        return false;

      return true;
    }

  int fun(int x, int y, int n) {

    if (n == 1) {
      return 1;
    }

    if (dp[x][y][n] != 0)
      return dp[x][y][n];

    int sum = 0;

    for (int i = 0; i < 8; i++) {
      if (isOk(x + xx[i], y + yy[i]))
        sum = (sum + fun(x + xx[i], y + yy[i], n - 1)) % 1000000007;
    }

    return dp[x][y][n] = sum % 1000000007;
  }
  int knightDialer(int n) {

    int ans = 0;

    for (int i = 0; i < nn; i++) {
      for (int j = 0; j < mm; j++) {
        if (mat[i][j] != '*') {
          ans = (ans + fun(i, j, n)) % 1000000007;
        }
      }
    }

    return ans % 1000000007;

  }
};
```

## Implement or Design a HashMap

As we can't use an in-built library, let's try to mimic how the exsiting in-built library is written. We can use a hash value (it should be a big prime number). So now we take modulo of each key and then we fill in the bucket with (key%hash) value.

```
class MyHashMap {
public:
    int hash = 3197;
    vector<vector<pair<int, int>>> v;
    /** Initialize your data structure here. */
    MyHashMap() {
        vector<vector<pair<int, int>>> v1(hash , vector<pair<int, int>> (0, make_pair(0,0)));
        
        v = v1;
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        int val = key%hash;
        
        vector<pair<int, int>> temp = v[val];
        
        for(int i=0; i<temp.size(); i++) {
            if(temp[i].first == key) {
                temp[i].second = value;
                v[val] = temp;
                return;
            }
        }
        temp.push_back(make_pair(key, value));
        v[val] = temp;
        return;
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int val = key%hash;
        
        vector<pair<int, int>> temp = v[val];
        
        for(int i=0; i<temp.size(); i++) {
            if(temp[i].first == key) {
                return temp[i].second;
            }
        }
        return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int val = key%hash;
        
        vector<pair<int, int>> temp = v[val];
        
        for(int i=0; i<temp.size(); i++) {
            if(temp[i].first == key) {
                auto it = find(temp.begin() , temp.end() , temp[i]);
                temp.erase(it);
                v[val] = temp;
                return;
            }
        }
        return;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
```

## Design a LFU cache 

```
//Just for better readability
typedef int Key_t;
typedef int Count_t;

struct Node
{
    int value;
    list<Key_t>::iterator itr;
};

class LFUCache
{
    unordered_map<Key_t, Node> m_values;
    unordered_map<Key_t, Count_t> m_counts;
    map<Count_t, list<Key_t>> m_countKeyMap;

    int m_maxCapacity;

public:
    LFUCache(int capacity)
    {
        m_maxCapacity = capacity;
    }

    int get(int key)
    {
        if(m_values.find(key) == m_values.end() || m_maxCapacity <= 0)
        {
            return -1;
        }
        //update frequency, & return value
        put(key, m_values[key].value);
        return m_values[key].value;
    }

    void put(int key, int value)
    {
        if (m_maxCapacity <= 0)
        {
            return;
        }
        
        //If key is not present and capacity has exceeded,
        //then remove the key entry with least frequency
        //else just make the new key entry
        if (m_values.find(key) == m_values.end())
        {
            if (m_values.size() == m_maxCapacity)
            {

                auto leastCountListItr = m_countKeyMap.begin();
                int keyToDelete = leastCountListItr->second.back();
                leastCountListItr->second.pop_back();
                if (leastCountListItr->second.empty())
                {
                    m_countKeyMap.erase(leastCountListItr);
                }
                m_values.erase(keyToDelete);
                m_counts.erase(keyToDelete);
            }
            m_values[key].value = value;
            m_counts[key] = 0;
            m_countKeyMap[m_counts[key]].push_front(key);
            auto listKeyItr = m_countKeyMap[0].begin();
            m_values[key].itr = listKeyItr;
        }
        else
        {
			//key is present and value updated. Just updating frequency
            auto itr = m_values[key].itr;
            m_countKeyMap[m_counts[key]].erase(itr);
            if (m_countKeyMap[m_counts[key]].empty())
            {
                m_countKeyMap.erase(m_counts[key]);
            }
            m_values[key].value = value;
            m_counts[key]++;
            m_countKeyMap[m_counts[key]].push_front(key);
            m_values[key].itr = m_countKeyMap[m_counts[key]].begin();
        }
    }
};
```


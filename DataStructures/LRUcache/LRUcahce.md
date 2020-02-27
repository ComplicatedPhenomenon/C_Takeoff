# LRUcahce
Scenario: limited storage in memory to store which item on disk

Implement a DS which has constant time complexity to **update** and **access**. 
* Maintain a map(to look up the key is existed in the DLL or not) and Double linked list(to evict and insert new node in a constant time)

* https://www.interviewcake.com/concept/java/lru-cache


```md
cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // returns 1
cache.put(3, 3);    // evicts key 2
cache.get(2);       // returns -1 (not found)
cache.put(4, 4);    // evicts key 1
cache.get(1);       // returns -1 (not found)
cache.get(3);       // returns 3
cache.get(4);       // returns 4
```
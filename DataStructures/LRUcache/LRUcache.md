# LRU cache
Scenario: limited storage in memory to store which item on disk

Implement a DS which has constant time complexity to **update** and **access**. 
* Maintain a map(to look up the key is existed in the DLL or not) and Double linked list(to evict and insert new node in a constant time)

* https://www.interviewcake.com/concept/java/lru-cache


Follow up:
Could you do both operations in O(1) time complexity?

The method is to sacrifice space usage for speed.

Example:
```md
LRUCache cache = new LRUCache( 2 /* capacity */ );

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

processing demo
```md
Entrance      Exit
[1,1] # a [key, value] pair
[2,2]   [1,1]
[1,1]   [2,2]
[3,3]   [1,1]   
[3,3]   [1,1]   
[4,4]   [3,3] 
[4,4]   [3,3]
[3,3]   [4,4]
[4,4]   [3,3]
```



Limited memory(which you can fast accessed)

An LRU cache is built by combining two data structures: a `doubly linked list` and a `hash map`.

How to debug this test?
```md
Input: 
["LRUCache","put","put","put","put","put","get","put","get","get","put","get","put","put","put","get","put","get","get","get","get","put","put","get","get","get","put","put","get","put","get","put","get","get","get","put","put","put","get","put","get","get","put","put","get","put","put","put","put","get","put","put","get","put","put","get","put","put","put","put","put","get","put","put","get","put","get","get","get","put","get","get","put","put","put","put","get","put","put","put","put","get","get","get","put","put","put","get","put","put","put","get","put","put","put","get","get","get","put","put","put","put","get","put","put","put","put","put","put","put"]
[[10],

[10,13],
[3,17],
[6,11],
[10,5],
[9,10],[13],
[2,19],[2],[3],
[5,25],[8],
[9,22],
[5,5],
[1,30],[11],
[9,12],[7],[5],[8],[9],
[4,30],
[9,3],[9],[10],[10],[6,14],[3,1],[3],[10,11],[8],[2,14],[1],[5],[4],[11,4],[12,24],[5,18],[13],[7,23],[8],[12],[3,27],[2,12],[5],[2,9],[13,4],[8,18],[1,7],[6],[9,29],[8,21],[5],[6,30],[1,12],[10],[4,15],[7,22],[11,26],[8,17],[9,29],[5],[3,4],[11,30],[12],[4,29],[3],[9],[6],[3,4],[1],[10],[3,29],[10,28],[1,20],[11,13],[3],[3,12],[3,8],[10,9],[3,26],[8],[7],[5],[13,17],[2,27],[11,15],[12],[9,19],[2,15],[3,16],[1],[12,17],[9,1],[6,19],[4],[5],[5],[8,1],[11,7],[5,2],[9,28],[1],[2,2],[7,4],[4,22],[7,24],[9,26],[13,28],[11,26]]

output:
[null,null,null,null,null,null,-1,null,19,17,null,-1,null,null,null,-1,null,-1,5,-1,12,null,null,3,5,5,null,null,1,null,-1,null,30,5,30,null,null,null,-1,null,-1,24,null,null,18,null,null,null,null,-1,null,null,18,null,null,-1,null,null,null,null,null,-1,null,null,-1,null,4,29,-1,null,-1,-1,null,null,null,null,-1,null,null,null,null,-1,-1,-1,null,null,null,-1,null,null,null,-1,null,null,null,-1,-1,-1,null,null,null,null,-1,null,null,null,null,null,null,null]

expected:
[null,null,null,null,null,null,-1,null,19,17,null,-1,null,null,null,-1,null,-1,5,-1,12,null,null,3,5,5,null,null,1,null,-1,null,30,5,30,null,null,null,-1,null,-1,24,null,null,18,null,null,null,null,-1,null,null,18,null,null,-1,null,null,null,null,null,18,null,null,-1,null,4,29,30,null,12,-1,null,null,null,null,29,null,null,null,null,17,22,18,null,null,null,-1,null,null,null,20,null,null,null,-1,18,18,null,null,null,null,20,null,null,null,null,null,null,null]
```
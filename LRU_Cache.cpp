#include <bits/stdc++.h>

using namespace std; 

struct Node {
  int key;
  int value;
  Node *prev;
  Node *next;

  Node(int k, int v) : key(k), value(v), prev(nullptr),next(nullptr) {}
};
class LRUCache {
private:
  unordered_map<int,Node*> mp;
  int capacity;
  Node* head;
  Node* tail;
  
  void addNode(Node *node);
  void removeNode(Node *node);
  void moveToHead(Node *node);
  Node* popTail();
  
  public:
   
  LRUCache(int capacity): capacity(capacity) {
    head = new Node(0,0);
    tail = new Node(0,0);
    head->next = tail;
    tail->prev = head;
    }
    
    int get(int key) {
      //hashmap check
      if (mp.find(key) == mp.end()){
        return -1; //Cache miss
      }

      Node *node = mp[key];
      moveToHead(node);

      return node->value;
    }
    
    void put(int key, int value) {
      
      if (mp.find(key) != mp.end()){
        Node *node = mp[key];
        node->value = value;
        moveToHead(node);
      }
      else {
        if(mp.size() == capacity){
          Node *lru = popTail();
          mp.erase(lru->key);
          delete lru;
        }

        Node* newNode = new Node(key, value);
        addNode(newNode);
        mp[key] = newNode;
      }
    }

    ~LRUCache(){
      Node *curr = head;
      while(curr != nullptr){
        Node *next = curr->next;
        delete curr;
        curr = next;
      }
    }
};

void LRUCache::removeNode(Node* node){
  node->prev->next = node->next;
  node->next->prev = node->prev;
}

void LRUCache::addNode(Node* node){
  node->next = head->next;
  node->prev = head;

  head->next->prev = node;
  head->next = node;
}

void LRUCache::moveToHead(Node *node){
  removeNode(node);

  addNode(node);
}

Node* LRUCache::popTail(){
  Node *lru = tail->prev;

  removeNode(lru);
  return lru;
}

int main()
{
    // Example Test Cases
    LRUCache cache(2);
    cache.put(1, 1);
    cache.put(2, 2);
    cout << "Get 1: " << cache.get(1) << endl; // returns 1 (MRU: 1)
    cache.put(3, 3); // evicts key 2 (LRU)
    cout << "Get 2: " << cache.get(2) << endl; // returns -1 (Cache Miss)
    cache.put(4, 4); // evicts key 3 (LRU: 3)
    cout << "Get 1: " << cache.get(1) << endl; // returns 1 (MRU: 1)
    cout << "Get 3: " << cache.get(3) << endl; // returns -1 (Cache Miss)
    
    return 0;
}

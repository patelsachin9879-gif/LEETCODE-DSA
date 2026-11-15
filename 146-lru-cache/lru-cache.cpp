//:LRU CAche
class LRUCache {
public:
    class Node {
    public:
        int key, val;
        Node* prev;
        Node* next;

        Node(int k, int v) {
            key = k;
            val = v;
            prev = next = NULL;
        }
    };
    
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);
    unordered_map<int, Node*> m;
    int limit;


    LRUCache(int capacity) {
        limit = capacity;
        head->next = tail;
        tail->prev = head;
    }

    // Adds a node right after the head (Most Recently Used position)
    void addNode(Node* newNode) {
        Node* oldNext = head->next;
        head->next = newNode;
        oldNext->prev = newNode;
        newNode->next = oldNext;
        newNode->prev = head;
    }

    // Removes a node from its current position in the linked list
    void delNode(Node* oldNode) {
        Node* oldPrev = oldNode->prev;
        Node* oldNext = oldNode->next;
        oldPrev->next = oldNext;
        oldNext->prev = oldPrev;
    }

    int get(int key) {
        // Key not found
        if (m.find(key) == m.end()) {
            return -1;
        }

        // Key found: move node to head (Most Recently Used)
        Node* ansNode = m[key];
        int ans = ansNode->val;
        
        m.erase(key);
        delNode(ansNode);
        addNode(ansNode);
        
        m[key] = head->next;
        return ans;
    }

    void put(int key, int val) {
        // If key already exists, delete the old version
        if (m.find(key) != m.end()) {
            Node* oldNode = m[key];
            delNode(oldNode);
            m.erase(key);
            delete oldNode; // Free memory of the overwritten node
        }

        // If cache is full, evict the least recently used element (before tail)
        if (m.size() == limit) {
            m.erase(tail->prev->key);
            Node* toDelete = tail->prev;
            delNode(toDelete);
            delete toDelete; // Free memory of the evicted node
        }

        // Add the new key-value pair
        Node* newNode = new Node(key, val);
        addNode(newNode);
        m[key] = head->next;
    }
};

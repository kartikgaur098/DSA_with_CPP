class LRUCache {
private:
    int capacity;
    list<int> lruList;  // Doubly linked list to store keys
    unordered_map<int, pair<int, list<int>::iterator>> cache;

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        if (cache.find(key) == cache.end())
            return -1;

        // Move the accessed key to the front of the list
        lruList.erase(cache[key].second);
        lruList.push_front(key);
        cache[key].second = lruList.begin();

        return cache[key].first;
    }

    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            // Remove old key from list
            lruList.erase(cache[key].second);
        }
        else if (cache.size() == capacity) {
            // Remove least recently used item (from back)
            int lruKey = lruList.back();
            lruList.pop_back();
            cache.erase(lruKey);
        }

        // Insert new key at front
        lruList.push_front(key);
        cache[key] = {value, lruList.begin()};
    }
};

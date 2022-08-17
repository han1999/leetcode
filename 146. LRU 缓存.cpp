class LRUCache {
private:
    struct DLinkedNode{
        int key, value;
        DLinkedNode *pre, *next;
        DLinkedNode(int key, int value):key(key), value(value), pre(nullptr), next(nullptr){};//这种写法可以吗？
        DLinkedNode(): key(-1), value(-1), pre(nullptr), next(nullptr){};
    };

    //定义完结构体就可以用结构体了
    unordered_map<int, DLinkedNode*> mp;
    DLinkedNode *head, *tail;
    int capacity;
    int size;

    
public:
    LRUCache(int capacity) {
        this->capacity=capacity;
        size=0;
        head=new DLinkedNode();
        tail=new DLinkedNode();
        head->next=tail;
        tail->pre=head;
    }
    
    int get(int key) {
        if (!mp.count(key)){
            return -1;
        }else {
            DLinkedNode *node=mp[key];
            moveToHead(node);
            return node->value;
        }
    }
    void moveToHead(DLinkedNode *node){
        remove(node);
        addToHead(node);
    }

    void addToHead(DLinkedNode *node){
        node->next=head->next;
        node->next->pre=node;
        node->pre=head;
        head->next=node;
    }

    void remove(DLinkedNode *node){
        node->pre->next=node->next;
        node->next->pre=node->pre;
        node->next=node->pre=nullptr;
    }
    
    void put(int key, int value) {
        if (mp.count(key)){
            DLinkedNode *node=mp[key];
            node->value=value;
            moveToHead(node);
            /*
            这里关于moveToHead和addToHead极容易错
            moveToHead前提是双向链表中，有这个节点了
            addToHead是双向链表中并不存在这个节点
            */
            // moveToHead(node);
        }else {
            DLinkedNode *node=new DLinkedNode(key, value);
            // moveToHead(node);
            addToHead(node);
            mp[key]=node;
            size++;
            if (size>capacity){
                // mp.erase(tail->pre->key);
                // remove(tail->pre);
                /*
                由key，还要存储key, value，就是为了通过value找到key
                要保持，map和双向链表的一致性
                */
                DLinkedNode *node=removeTail();
                mp.erase(node->key);
                delete(node);
                size--;
            }
        }
    }
    
    DLinkedNode *removeTail(){
        DLinkedNode *node=tail->pre;
        remove(tail->pre);
        return node;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */


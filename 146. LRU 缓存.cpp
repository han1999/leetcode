class LRUCache {
private:
    struct DLinkedNode{
        int key, value;
        DLinkedNode *pre, *next;
        DLinkedNode(int key, int value):key(key), value(value), pre(nullptr), next(nullptr){};//����д��������
        DLinkedNode(): key(-1), value(-1), pre(nullptr), next(nullptr){};
    };

    //������ṹ��Ϳ����ýṹ����
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
            �������moveToHead��addToHead�����״�
            moveToHeadǰ����˫�������У�������ڵ���
            addToHead��˫�������в�����������ڵ�
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
                ��key����Ҫ�洢key, value������Ϊ��ͨ��value�ҵ�key
                Ҫ���֣�map��˫�������һ����
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


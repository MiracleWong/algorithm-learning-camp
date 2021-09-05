class LRUCache {

    private class Node {
        public int key;
        public int value;
        public Node pre;
        public Node next;
    }
    private HashMap<Integer, Node> map;
    // 保护节点
    private Node head;
    private Node tail;
    private int capacity;

    public LRUCache(int capacity) {
        this.capacity = capacity;
        this.map = new HashMap<Integer, Node>();

        // 建立带有保护节点的空双向链表
        head = new Node();
        tail = new Node();
        head.next = tail;
        tail.pre = head;
    }

    public int get(int key) {
        if (!this.map.containsKey(key)) return -1;
        Node node = this.map.get(key);
        // 从链表中删除掉
        this.removeFromList(node);
        // 重新插入到头部
        this.insertToListHead(node.key, node.value);
        return node.value;
    }

    public void put(int key, int value) {
        if (this.map.containsKey(key)) {
            Node node = this.map.get(key);
            // 从链表中删除掉
            this.removeFromList(node);
            // 重新插入到头部，维护时间顺序
            this.insertToListHead(key, value);
        } else {
            // 在链表中插入新结点，返回新结点的引用
            Node node = this.insertToListHead(key, value);
            // 建立映射关系
            this.map.put(key, node);
        }
        // 超出范围
        if (this.map.size() > this.capacity) {
            this.removeFromList(tail.pre);
        }
    }
    // 模板: 双向链表删除一个结点
    private void removeFromList(Node node) {
        node.pre.next = node.next;
        node.next.pre = node.pre;
        this.map.remove(node.key);
    }
    // 模板：双向链表插入一个结点
    private Node insertToListHead(int key, int value) {
        Node node = new Node();
        node.key = key;
        node.value = value;
        // node 与 head的下一个结点之间建立联系
        node.next = head.next;
        head.next.pre = node;

        // node 与 head 之间建立联系
        node.pre = head;
        head.next = node;

        // 建立映射关系
        this.map.put(key, node);
        return node;
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
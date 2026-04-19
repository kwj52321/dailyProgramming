class MyLinkedList {
private:
    struct ListNode {
        int val;
        ListNode* next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
    };
    ListNode* head;
    int size;
public:
    MyLinkedList() {
       head = nullptr;
        size = 0;
    }
    
    int get(int index) {
        if (index < 0 || index >= size) return -1;
        ListNode* node = head;
        int index_count = 0;
        while (index_count < index){
            index_count++;
            node = node->next;
        }
        return node->val;
    }
    
    void addAtHead(int val) {
        ListNode* new_node = new ListNode(val);
        ListNode* old_head = head;
        head = new_node;
        head->next = old_head;
        size++;        
    }
    
    void addAtTail(int val) {
        ListNode* tail_node = new ListNode(val);
        if (head == nullptr) {
            head = tail_node;
        } else {
            ListNode* node = head;
            while (node->next != nullptr){
                node = node->next;
            }
            node->next = tail_node;
        }
        size++;        
    }
    
    void addAtIndex(int index, int val) {
        if (index > size) {
            return;
        } else if (index <= 0) {
            addAtHead(val);
            return;
        } else if (index == size) {
            addAtTail(val);
            return;
        }

        ListNode* prev;
        ListNode* curr = head;
        int index_count = 0;
        while (index_count < index) {
            prev = curr;
            curr = curr->next;
            index_count++;
        }
        ListNode* new_node = new ListNode(val);
        ListNode* temp = prev->next;
        prev->next = new_node;
        new_node->next = temp;
        size++;
    }
    
    void deleteAtIndex(int index) {
        if (size == 0) return;
        if (index >= size) return;
        int index_count = 0;
        ListNode* curr = head;
        if (index == 0) {
            head = curr->next;
            delete curr;
            size--;
            return;
        }
        ListNode* prev = nullptr;
        while (index_count < index){
            prev = curr;
            curr = curr->next;
            index_count++;
        }
        prev->next = curr->next;
        delete curr;
        size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
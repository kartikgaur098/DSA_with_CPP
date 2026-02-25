class MyLinkedList {
private:
    // Step 1: Create Node structure
    struct Node {
        int val;
        Node* next;

        Node(int value) {
            val = value;
            next = NULL;
        }
    };

    Node* head;   // starting node
    int size;     // number of nodes

public:
    // Step 2: Constructor
    MyLinkedList() {
        head = NULL;
        size = 0;
    }

    // Step 3: Get value at index
    int get(int index) {
        if (index < 0 || index >= size) {
            return -1;
        }

        Node* temp = head;

        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }

        return temp->val;
    }

    // Step 4: Add at head
    void addAtHead(int val) {
        Node* newNode = new Node(val);

        newNode->next = head;
        head = newNode;

        size++;
    }

    // Step 5: Add at tail
    void addAtTail(int val) {
        Node* newNode = new Node(val);

        if (head == NULL) {
            head = newNode;
        } else {
            Node* temp = head;

            while (temp->next != NULL) {
                temp = temp->next;
            }

            temp->next = newNode;
        }

        size++;
    }

    // Step 6: Add at index
    void addAtIndex(int index, int val) {
        if (index < 0 || index > size) {
            return;
        }

        if (index == 0) {
            addAtHead(val);
            return;
        }

        Node* temp = head;

        for (int i = 0; i < index - 1; i++) {
            temp = temp->next;
        }

        Node* newNode = new Node(val);

        newNode->next = temp->next;
        temp->next = newNode;

        size++;
    }

    // Step 7: Delete at index
    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) {
            return;
        }

        if (index == 0) {
            Node* temp = head;
            head = head->next;
            delete temp;
        } else {
            Node* temp = head;

            for (int i = 0; i < index - 1; i++) {
                temp = temp->next;
            }

            Node* nodeToDelete = temp->next;
            temp->next = nodeToDelete->next;

            delete nodeToDelete;
        }

        size--;
    }
};
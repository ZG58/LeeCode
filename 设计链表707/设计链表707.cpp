#include <iostream>

using namespace std;

class MyLinkedList {
public:
    struct LinkedNode
    {
        int val;
        LinkedNode* next;
        LinkedNode(int val) :val(val), next(nullptr) {};
    };

    MyLinkedList() {
        _dummyHead = new LinkedNode(0);
        _size = 0;
    }

    int get(int index) {
        if (index > (_size - 1) || index < 0) {
            return -1;
        }
        LinkedNode* cur = _dummyHead->next;
        while (index--) {
            cur = cur->next;
        }
        return cur->val;
    }

    void addAtHead(int val) {
        LinkedNode* newNode = new LinkedNode(val);
        newNode->next = _dummyHead->next;
        _dummyHead->next = newNode;
        _size++;
    }

    void addAtTail(int val) {
        LinkedNode* newNode = new LinkedNode(val);
        LinkedNode* cur = _dummyHead;
        while (cur->next != nullptr) {
            cur = cur->next;
        }
        cur->next = newNode;
        _size++;
    }

    void addAtIndex(int index, int val) {
        if (index > _size) return;
        if (index < 0) index = 0;
        LinkedNode* newNode = new LinkedNode(val);
        LinkedNode* cur = _dummyHead;
        while (index--) {
            cur = cur->next;
        }
        newNode->next = cur->next;
        cur->next = newNode;
        _size++;
    }

    void deleteAtIndex(int index) {
        if (index >= _size || index < 0) return;
        LinkedNode* cur = _dummyHead;
        while (index--) {
            cur = cur->next;
        }
        LinkedNode* temp = cur->next;
        cur->next = cur->next->next;
        delete temp;
        temp = nullptr;
        _size--;
    }

    void printLinkedlist() {
        LinkedNode* cur = _dummyHead;
        while (cur->next != nullptr) {
            cout << cur->next->val << " ";
            cur = cur->next;
        }
        cout << endl;
    }

private:
    LinkedNode* _dummyHead;
    int _size;
};

int main()
{

    MyLinkedList myLinkedList;
    myLinkedList.addAtHead(1);
    myLinkedList.printLinkedlist();

    myLinkedList.addAtTail(3);
    myLinkedList.printLinkedlist();

    myLinkedList.addAtIndex(1, 2); 
    myLinkedList.printLinkedlist();

    int num = myLinkedList.get(1);    
    cout << num << endl;

    myLinkedList.deleteAtIndex(1);  
    myLinkedList.printLinkedlist();

    int nums = myLinkedList.get(1);
    cout << nums << endl;

	return 0;
}

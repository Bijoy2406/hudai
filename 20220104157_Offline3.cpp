#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class SinglyLinkedList {
private:
    Node* head;

public:
    SinglyLinkedList() : head(nullptr) {}

    void insertFirst(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    void insertLast(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
            return;
        }

        Node* current = head;
        while (current->next) {
            current = current->next;
        }

        current->next = newNode;
    }

    void insertAnywhere(int value, int position) {
        Node* newNode = new Node(value);
        if (position == 1) {
            newNode->next = head;
            head = newNode;
            return;
        }

        Node* current = head;
        for (int i = 1; i < position - 1 && current; ++i) {
            current = current->next;
        }

        if (!current) {
            cout << "Invalid position\n";
            return;
        }

        newNode->next = current->next;
        current->next = newNode;
    }

    void deleteFirst() {
        if (!head) {
            cout << "List is empty\n";
            return;
        }

        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void deleteLast() {
        if (!head) {
            cout << "List is empty\n";
            return;
        }

        if (!head->next) {
            delete head;
            head = nullptr;
            return;
        }

        Node* current = head;
        while (current->next->next) {
            current = current->next;
        }

        delete current->next;
        current->next = nullptr;
    }

    void deleteAnywhere(int position) {
        if (!head) {
            cout << "List is empty\n";
            return;
        }

        if (position == 1) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* current = head;
        for (int i = 1; i < position - 1 && current; ++i) {
            current = current->next;
        }

        if (!current || !current->next) {
            cout << "Invalid position\n";
            return;
        }

        Node* temp = current->next;
        current->next = current->next->next;
        delete temp;
    }

    void printing() {
        Node* current = head;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << "\n";
    }

    bool searching(int value) {
        Node* current = head;
        while (current) {
            if (current->data == value) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    int last_node() {
        if (!head) {
            cout << "List is empty\n";
            return -1;
        }

        Node* current = head;
        while (current->next) {
            current = current->next;
        }

        return current->data;
    }

    int previous_of_last_node() {
        if (!head || !head->next) {
            cout << "List doesn't have enough nodes\n";
            return -1;
        }

        Node* current = head;
        while (current->next->next) {
            current = current->next;
        }

        return current->data;
    }

    int list_size() {
        int size = 0;
        Node* current = head;
        while (current) {
            size++;
            current = current->next;
        }
        return size;
    }
};

int main() {
    SinglyLinkedList myList;

    myList.insertLast(1);
    myList.insertLast(2);
    myList.insertLast(3);

    cout << "Linked List: ";
    myList.printing();

    cout << "Size of the Linked List: " << myList.list_size() << "\n";

    myList.insertFirst(0);
    myList.insertAnywhere(99, 2);

    cout << "Linked List after insertion: ";
    myList.printing();

    cout << "Searching for value 3: " << (myList.searching(3) ? "Found" : "Not Found") << "\n";

    cout << "Last node value: " << myList.last_node() << "\n";
    cout << "Previous of last node value: " << myList.previous_of_last_node() << "\n";

    myList.deleteFirst();
    myList.deleteLast();
    myList.deleteAnywhere(2);

    cout << "Linked List after deletion: ";
    myList.printing();

    return 0;
}

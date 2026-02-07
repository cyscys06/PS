#include <bits/stdc++.h>
using namespace std;

struct node {
    int data;
    node* left;
    node* right;
};

struct bst {
private:
    node* root = nullptr;

    node* findImpl(node* current, int value) {
        if (!current) return nullptr;

        if (current->data == value) {
            return current;
        }

        if (value < current->data) {
            return findImpl(current->left, value);
        }
        return findImpl(current->right, value);
    }

    void insertImpl(node* current, int value) {
        if (value < current->data) {
            if (!current->left) {
                current->left = new node{value, nullptr, nullptr};
            } else {
                insertImpl(current->left, value);
            }
        } else {
            if (!current->right) {
                current->right = new node{value, nullptr, nullptr};
            } else {
                insertImpl(current->right, value);
            }
        }
    }

    void inOrderImpl(node* start) {
        if (!start) {
            return;
        }
        inOrderImpl(start->left);
        cout << start->data << " ";
        inOrderImpl(start->right);
    }

    node* deleteImpl(node* start, int value) {
        if (!start) {
            return nullptr;
        }

        if (value < start->data) {
            start->left = deleteImpl(start->left, value);
        } else if (value > start->data) {
            start->right = deleteImpl(start->right, value);
        } else {
            if (!start->left) {
                node* tmp = start->right;
                delete start;
                return tmp;
            }
            if (!start->right) {
                node* tmp = start->left;
                delete start;
                return tmp;
            }

            node* succNode = successor(start);
            start->data = succNode->data;
            start->right = deleteImpl(start->right, succNode->data);
        }
        return start;
    }

    node* successor(node* start) {
        node* current = start->right;
        while (current && current->left) {
            current = current->left;
        }
        return current;
    }

public:
    node* find(int value) {
        return findImpl(root, value);
    }

    void insert(int value) {
        if (!root) {
            root = new node{value, nullptr, nullptr};
        } else {
            insertImpl(root, value);
        }
    }

    void inOrder() {
        inOrderImpl(root);
    }

    void deleteValue(int value) {
        root = deleteImpl(root, value);
    }
};

int main() {
    bst tree;
    tree.insert(12);
    tree.insert(10);
    tree.insert(20);
    tree.insert(8);
    tree.insert(11);
    tree.insert(15);
    tree.insert(28);
    tree.insert(4);
    tree.insert(2);

    cout << "중위 순회: ";
    tree.inOrder();
    cout << endl;

    tree.deleteValue(12);
    cout << "12를 삭제한 후 중위 순회: ";
    tree.inOrder();
    cout << endl;

    if (tree.find(12)) {
        cout << "원소 12는 트리에 있습니다. " << endl;
    } else {
        cout << "원소 12는 트리에 없습니다. " << endl;
    }

    return 0;
}
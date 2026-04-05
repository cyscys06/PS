#include <bits/stdc++.h>
using namespace std;

struct Node {
    char data;
    Node* left;
    Node* right;
} rootNode{'A', nullptr, nullptr};
Node* root = &rootNode;
bool direction; // true면 왼쪽, false면 오른쪽

Node* find(char value, Node* root);
Node* add(char value, Node* parent, bool direction);
void preOrder(Node* start);
void inOrder(Node* start);
void postOrder(Node* start);

int main() {
    int n;
    char parent, left, right;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> parent >> left >> right;
        if (parent == 'A') {
            // 문제점: 테스트케이스는 통과했으나, A 루트 노드에서 한 개의 자식 노드만 존재할 수도 있는 경우를 고려하지 않았음
            // 해결(AI 도움 받음): 루트 노드 입력받은 경우에도 '.' 검사하는 코드 추가
            if (left != '.') {
                direction = true;
                add(left, root, direction); 
            }
            
            if (right != '.') {
                direction = false;
                add(right, root, direction); 
            }

            continue;
        }

        Node* parentNode = find(parent, root);
        if (left != '.') {
            direction = true;
            add(left, parentNode, direction); 
        }
        
        if (right != '.') {
            direction = false;
            add(right, parentNode, direction); 
        }
    }

    preOrder(root);
    cout << '\n';
    inOrder(root);
    cout << '\n';
    postOrder(root);

    return 0;
}

Node* find(char value, Node* root) {
    if (!root) {
        return nullptr;
    }

    if (root->data == value) {
        return root;
    }

    Node* left = find(value, root->left);
    if (left != nullptr) {
        return left;
    }

    return find(value, root->right);
}

Node* add(char value, Node* parent, bool direction) {
    // 문제점: 먼저 입력받은 자식 노드 값을 무조건 왼쪽부터 채워서, 테스트케이스 중 F . G에서 G가 오른쪽이 아닌 왼쪽 노드로 들어가는 경우
    // 해결(AI 도움 받음): 방향 플래그 선언해서 왼쪽일때랑 오른쪽일때랑 개별적으로 접근할 수 있게 만들기
    if (!find(parent->data, root)) {
        return nullptr;
    }

    if (direction) {
        if (parent->left) {
            return nullptr;
        }
        parent->left = new Node{value, nullptr, nullptr};
        return parent->left;
    } else {
        if (parent->right) {
            return nullptr;
        }
        parent->right = new Node{value, nullptr, nullptr};
        return parent->right;
    }
}

void preOrder(Node* start) {
    if (!start) {
        return;
    }

    cout << start->data;
    preOrder(start->left);
    preOrder(start->right);
}

void inOrder(Node* start) {
    if (!start) {
        return;
    }

    inOrder(start->left);
    cout << start->data;
    inOrder(start->right);
}

void postOrder(Node* start) {
    if (!start) {
        return;
    }

    postOrder(start->left);
    postOrder(start->right);
    cout << start->data;
}
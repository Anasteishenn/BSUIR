#include <iostream>
#include <cstdlib>
using namespace std;

struct Node {
    int key; 
    int priority; 
    Node* l;
    Node* r;  

    Node(int k) {
        key = k;
        priority = rand();
        l = nullptr;
        r = nullptr;
    }
};

void split(Node* root, int key, Node*& L, Node*& R) {
    if (!root) {
        L = R = nullptr;
        return;
    }
    if (key < root->key) {
        split(root->l, key, L, root->l);
        R = root;
    }
    else {
        split(root->r, key, root->r, R);
        L = root;
    }
}

Node* merge(Node* L, Node* R) {
    if (!L || !R) return L ? L : R;

    if (L->priority > R->priority) {
        L->r = merge(L->r, R);
        return L;
    }
    else {
        R->l = merge(L, R->l);
        return R;
    }
}

Node* insert(Node* root, int key) {
    Node* L, * R;
    split(root, key, L, R);

    Node* L1, * mid;
    split(L, key - 1, L1, mid);
    if (!mid) mid = new Node(key);

    return merge(merge(L1, mid), R);
}

Node* erase(Node* root, int key) {
    Node* L, * mid, * R;
    split(root, key - 1, L, R);
    split(R, key, mid, R);

    if (mid) delete mid;

    return merge(L, R);
}

bool search(Node* root, int key) {
    if (!root) return false;
    if (root->key == key) return true;
    return key < root->key ? search(root->l, key) : search(root->r, key);
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->l);
    cout << root->key << " ";
    inorder(root->r);
}

int main() {
    Node* root = nullptr;

    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 15);
    root = insert(root, 5);

    int c;
    bool pro = true;
    while (pro) {
        cout << "Menu" << endl;
        cout << "1- In-order" << endl;
        cout << "2- Search" << endl;
        cout << "3- Erase" << endl;
        cout << "4- Insert" << endl;
        cin >> c;

        if (c == 1) {
            cout << "In-order: ";
            inorder(root);
            cout << endl;
        }
        else if (c == 2) {
            int p;
            cout << "Enter key" << endl;
            cin >> p;
            cout << "Search " << (p) << ":" << (search(root, p) ? "Yes" : "No") << endl;
        }
        else if (c == 3) {
            int p;
            cout << "Enter key" << endl;
            cin >> p;
            root = erase(root, p);
            cout << "After deletion " << (p) << ":";
            inorder(root);
        }
        else if (c == 4) {
            int p;
            cout << "Enter key" << endl;
            cin >> p;
            root = insert(root, p);
            cout << "After insertion " << p << ": ";
            inorder(root);
        }
        else {
            cout << "Invalid input" << endl;
            break;
        }
    }
    return 0;
}
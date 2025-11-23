#include <iostream>
using namespace std;

class AVLnode {
public:
    int id;
    AVLnode* lft;
    AVLnode* rgt;
    int h;
    AVLnode(int v=0, int hh=1) : id(v), h(hh), lft(nullptr), rgt(nullptr) {}
};

int getH(AVLnode* n) {
    return n ? n->h : 0;
}

int bf(AVLnode* n) {
    return n ? getH(n->lft) - getH(n->rgt) : 0;
}

AVLnode* doLeft(AVLnode* a) {
    AVLnode* b = a->rgt;
    AVLnode* t = b->lft;

    b->lft = a;
    a->rgt = t;

    a->h = 1 + max(getH(a->lft), getH(a->rgt));
    b->h = 1 + max(getH(b->lft), getH(b->rgt));

    cout << "[Rotation] Left turn at node: " << a->id << "\n";
    return b;
}

AVLnode* doRight(AVLnode* a) {
    AVLnode* b = a->lft;
    AVLnode* t = b->rgt;

    b->rgt = a;
    a->lft = t;

    a->h = 1 + max(getH(a->lft), getH(a->rgt));
    b->h = 1 + max(getH(b->lft), getH(b->rgt));

    cout << "[Rotation] Right turn at node: " << a->id << "\n";
    return b;
}

AVLnode* addNode(AVLnode* root, int key) {
    if (!root) return new AVLnode(key);

    if (key < root->id) root->lft = addNode(root->lft, key);
    else root->rgt = addNode(root->rgt, key);

    root->h = 1 + max(getH(root->lft), getH(root->rgt));
    int bal = bf(root);

    if (bal > 1 && key < root->lft->id) return doRight(root);
    if (bal < -1 && key > root->rgt->id) return doLeft(root);
    if (bal > 1 && key > root->lft->id) {
        root->lft = doLeft(root->lft);
        return doRight(root);
    }
    if (bal < -1 && key < root->rgt->id) {
        root->rgt = doRight(root->rgt);
        return doLeft(root);
    }

    cout << "Node[" << root->id << "] H=" << root->h << " BF=" << bf(root) << "\n";
    return root;
}

AVLnode* removeNode(AVLnode* root, int key) {
    if (!root) return root;

    if (key < root->id) root->lft = removeNode(root->lft, key);
    else if (key > root->id) root->rgt = removeNode(root->rgt, key);
    else {
        if (!root->lft && !root->rgt) {
            delete root;
            return nullptr;
        }
        if (!root->lft) {
            AVLnode* t = root->rgt;
            delete root;
            return t;
        }
        if (!root->rgt) {
            AVLnode* t = root->lft;
            delete root;
            return t;
        }
        AVLnode* cur = root->rgt;
        while (cur->lft) cur = cur->lft;

        root->id = cur->id;
        root->rgt = removeNode(root->rgt, cur->id);
    }

    if (!root) return root;

    root->h = 1 + max(getH(root->lft), getH(root->rgt));
    int bal = bf(root);

    if (bal > 1 && bf(root->lft) >= 0) return doRight(root);
    if (bal < -1 && bf(root->rgt) <= 0) return doLeft(root);
    if (bal > 1 && bf(root->lft) < 0) {
        root->lft = doLeft(root->lft);
        return doRight(root);
    }
    if (bal < -1 && bf(root->rgt) > 0) {
        root->rgt = doRight(root->rgt);
        return doLeft(root);
    }

    cout << "Node[" << root->id << "] H=" << root->h << " BF=" << bf(root) << "\n";
    return root;
}

void show(AVLnode* root) {
    if (!root) return;
    show(root->lft);
    cout << root->id << " ";
    show(root->rgt);
}

int main() {
    AVLnode* root = nullptr;

    int arr[] = {30, 20, 40, 10, 25, 35, 50};
    for (int v : arr) root = addNode(root, v);

    cout << "\nSequence after adding all: ";
    show(root);
    cout << "\n\n";

    cout << "Removing 20...\n";
    root = removeNode(root, 20);
    cout << "Removing 40...\n";
    root = removeNode(root, 40);
    cout << "Removing 25...\n";
    root = removeNode(root, 25);
    cout << "Removing 30...\n";
    root = removeNode(root, 30);

    cout << "Final sequence: ";
    show(root);
    cout << "\n";
}
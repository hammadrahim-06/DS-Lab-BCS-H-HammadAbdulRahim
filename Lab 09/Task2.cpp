#include <iostream>
using namespace std;

class ItemNode {
public:
    int cost;
    string label;
    ItemNode* L;
    ItemNode* R;
    int ht;
    ItemNode(int c=0, string s="item") : cost(c), label(s), ht(1), L(nullptr), R(nullptr) {}
};

int getH(ItemNode* p) {
    return p ? p->ht : 0;
}

int getBF(ItemNode* p) {
    return p ? getH(p->L) - getH(p->R) : 0;
}

ItemNode* rotateL(ItemNode* a) {
    ItemNode* b = a->R;
    ItemNode* t = b->L;

    b->L = a;
    a->R = t;

    a->ht = 1 + max(getH(a->L), getH(a->R));
    b->ht = 1 + max(getH(b->L), getH(b->R));
    return b;
}

ItemNode* rotateR(ItemNode* a) {
    ItemNode* b = a->L;
    ItemNode* t = b->R;

    b->R = a;
    a->L = t;

    a->ht = 1 + max(getH(a->L), getH(a->R));
    b->ht = 1 + max(getH(b->L), getH(b->R));
    return b;
}

ItemNode* insertPrice(ItemNode* root, int c, string s) {
    if (!root) return new ItemNode(c, s);

    if (c < root->cost) root->L = insertPrice(root->L, c, s);
    else root->R = insertPrice(root->R, c, s);

    root->ht = 1 + max(getH(root->L), getH(root->R));
    int bal = getBF(root);

    if (bal > 1 && c < root->L->cost) return rotateR(root);
    if (bal < -1 && c > root->R->cost) return rotateL(root);
    if (bal > 1 && c > root->L->cost) {
        root->L = rotateL(root->L);
        return rotateR(root);
    }
    if (bal < -1 && c < root->R->cost) {
        root->R = rotateR(root->R);
        return rotateL(root);
    }
    return root;
}

void display(ItemNode* p) {
    if (!p) return;
    display(p->L);
    cout << p->label << "($" << p->cost << ") ";
    display(p->R);
}

void rangeLookup(ItemNode* root, int a, int b) {
    if (!root) return;

    if (root->cost > a) rangeLookup(root->L, a, b);

    if (root->cost >= a && root->cost <= b)
        cout << root->label << "($" << root->cost << ") ";

    if (root->cost < b) rangeLookup(root->R, a, b);
}

int main() {
    ItemNode* root = nullptr;

    int vals[] = {30, 20, 40, 10, 25, 35, 50};
    string lab[] = {"Biscuit", "Chips", "Milk", "Eggs", "Bread", "Chocolate", "Juice"};

    for (int i = 0; i < 7; i++)
        root = insertPrice(root, vals[i], lab[i]);

    cout << "All stored prices: ";
    display(root);
    cout << "\n\n";

    cout << "Prices within range 25 to 40:\n";
    rangeLookup(root, 25, 40);
    cout << "\n";
}
#include <iostream>
using namespace std;

class PNode {
public:
    int score;
    PNode* L;
    PNode* R;
    int h;
    PNode(int v=0) : score(v), L(nullptr), R(nullptr), h(1) {}
};

int ht(PNode* p) {
    return p ? p->h : 0;
}

int diff(PNode* p) {
    return p ? ht(p->L) - ht(p->R) : 0;
}

PNode* rotL(PNode* a) {
    PNode* b = a->R;
    PNode* t = b->L;
    b->L = a;
    a->R = t;
    a->h = 1 + max(ht(a->L), ht(a->R));
    b->h = 1 + max(ht(b->L), ht(b->R));
    cout << "Left rotation applied at severity " << a->score << "\n";
    return b;
}

PNode* rotR(PNode* a) {
    PNode* b = a->L;
    PNode* t = b->R;
    b->R = a;
    a->L = t;
    a->h = 1 + max(ht(a->L), ht(a->R));
    b->h = 1 + max(ht(b->L), ht(b->R));
    cout << "Right rotation applied at severity " << a->score << "\n";
    return b;
}

PNode* add(PNode* root, int val) {
    if (!root) return new PNode(val);

    if (val < root->score) root->L = add(root->L, val);
    else root->R = add(root->R, val);

    root->h = 1 + max(ht(root->L), ht(root->R));
    int b = diff(root);

    if (abs(b) > 1) cout << "Unbalanced detected, fixing...\n";

    if (b > 1 && val < root->L->score) return rotR(root);
    if (b < -1 && val > root->R->score) return rotL(root);
    if (b > 1 && val > root->L->score) {
        root->L = rotL(root->L);
        return rotR(root);
    }
    if (b < -1 && val < root->R->score) {
        root->R = rotR(root->R);
        return rotL(root);
    }

    return root;
}

PNode* removeNode(PNode* root, int val) {
    if (!root) return root;

    if (val < root->score) root->L = removeNode(root->L, val);
    else if (val > root->score) root->R = removeNode(root->R, val);
    else {
        if (!root->L && !root->R) {
            delete root;
            return nullptr;
        }
        if (!root->L) {
            PNode* t = root->R;
            delete root;
            return t;
        }
        if (!root->R) {
            PNode* t = root->L;
            delete root;
            return t;
        }

        PNode* t = root->R;
        while (t->L) t = t->L;
        root->score = t->score;
        root->R = removeNode(root->R, t->score);
    }

    if (!root) return root;

    root->h = 1 + max(ht(root->L), ht(root->R));
    int b = diff(root);

    if (b > 1 && diff(root->L) >= 0) return rotR(root);
    if (b < -1 && diff(root->R) <= 0) return rotL(root);
    if (b > 1 && diff(root->L) < 0) {
        root->L = rotL(root->L);
        return rotR(root);
    }
    if (b < -1 && diff(root->R) > 0) {
        root->R = rotR(root->R);
        return rotL(root);
    }

    return root;
}

void traverse(PNode* r) {
    if (!r) return;
    traverse(r->L);
    cout << r->score << " ";
    traverse(r->R);
}

int mostCritical(PNode* r) {
    if (!r) return -1;
    while (r->R) r = r->R;
    return r->score;
}

int main() {
    PNode* root = nullptr;

    int data[] = {30, 40, 50, 10, 20, 35, 25};
    for (int i = 0; i < 7; i++) {
        cout << "New patient, severity = " << data[i] << "\n";
        root = add(root, data[i]);
        cout << "Height now: " << ht(root) << " | Critical max: " << mostCritical(root) << "\n";
    }

    cout << "\nPatients in-order: ";
    traverse(root);
    cout << "\n";

    int leaving[] = {20, 40, 25, 30};
    for (int i = 0; i < 4; i++) {
        cout << "Patient discharged, severity = " << leaving[i] << "\n";
        root = removeNode(root, leaving[i]);
        cout << "Height now: " << ht(root) << " | Critical max: " << mostCritical(root) << "\n";
    }

    cout << "After discharges: ";
    traverse(root);
    cout << "\n";
}
#include <iostream>
#include <queue>
#include <string>
using namespace std;

class Member {
public:
    string person;
    Member* mom;
    Member* dad;
    Member(string n) : person(n), mom(nullptr), dad(nullptr) {}

    void setParents() {
        if(!mom) {
            cout << "Enter mother's name for " << person << " ('unknown' if not known): ";
            string m;
            cin >> m;
            if(m != "unknown") {
                mom = new Member(m);
                mom->setParents();
            }
        }
        if(!dad) {
            cout << "Enter father's name for " << person << " ('unknown' if not known): ";
            string f;
            cin >> f;
            if(f != "unknown") {
                dad = new Member(f);
                dad->setParents();
            }
        }
    }
};

class FamilyTree {
public:
    Member* start;
    FamilyTree(string rootName) {
        start = new Member(rootName);
        start->setParents();
    }

    void showAncestors(Member* node) {
        if(!node) return;
        if(!node->mom && !node->dad) {
            cout << node->person << endl;
            return;
        }
        showAncestors(node->mom);
        showAncestors(node->dad);
    }

    int calculateHeight(Member* node) {
        if(!node) return 0;
        int a = calculateHeight(node->mom);
        int b = calculateHeight(node->dad);
        return 1 + max(a, b);
    }

    string youngestPerson() {
        return start->person;
    }

    void displayLevels(Member* node) {
        if(!node) return;
        queue<Member*> q;
        q.push(node);
        int lvl = 0;
        while(!q.empty()) {
            int size = q.size();
            cout << "Level " << lvl << ": ";
            for(int i = 0; i < size; i++) {
                Member* current = q.front();
                q.pop();
                cout << current->person << " ";
                if(current->mom) q.push(current->mom);
                if(current->dad) q.push(current->dad);
            }
            cout << endl;
            lvl++;
        }
    }

    void showFamilyInfo() {
        cout << endl << "Root (youngest person): " << youngestPerson() << endl;
        cout << endl << "Leaf nodes (ancestors with no known parents):" << endl;
        showAncestors(start);
        cout << endl << "Height of tree: " << calculateHeight(start) << endl;
        cout << endl << "Members by level:" << endl;
        displayLevels(start);
    }
};

int main() {
    string mainName;
    cout << "Enter the youngest person's name: ";
    cin >> mainName;
    FamilyTree fam(mainName);
    fam.showFamilyInfo();
}
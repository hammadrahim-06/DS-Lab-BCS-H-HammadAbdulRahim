#include <iostream>
#include <string>
using namespace std;

class Track {
public:
    string title;
    int count;
    Track* leftSide;
    Track* rightSide;
    Track(string t, int c) : title(t), count(c), leftSide(nullptr), rightSide(nullptr) {}
};

class Playlist {
public:
    Track* head;
    Playlist(string t, int c) {
        head = new Track(t, c);
    }

    void addSong(string t, int c) {
        Track* temp = new Track(t, c);
        if(!head) {
            head = temp;
            return;
        }
        Track* cur = head;
        while(cur) {
            if(c < cur->count) {
                if(!cur->leftSide) {
                    cur->leftSide = temp;
                    return;
                }
                cur = cur->leftSide;
            } else if(c > cur->count) {
                if(!cur->rightSide) {
                    cur->rightSide = temp;
                    return;
                }
                cur = cur->rightSide;
            } else {
                cout << "Duplicate play count found. Song not added." << endl;
                return;
            }
        }
    }

    void findSong(Track* root, int c) {
        if(!root) {
            cout << "No song has play count " << c << endl;
            return;
        }
        if(root->count == c) {
            cout << "Found song: " << root->title << " with play count " << c << endl;
            return;
        }
        if(c < root->count)
            findSong(root->leftSide, c);
        else
            findSong(root->rightSide, c);
    }

    void showInOrder(Track* root) {
        if(root) {
            showInOrder(root->leftSide);
            cout << root->title << ", " << root->count << endl;
            showInOrder(root->rightSide);
        }
    }

    void showPostOrder(Track* root) {
        if(root) {
            showPostOrder(root->leftSide);
            showPostOrder(root->rightSide);
            cout << root->title << ", " << root->count << endl;
        }
    }

    Track* removeSong(Track* root, int c) {
        if(!root) {
            cout << "No song found with play count " << c << " to delete." << endl;
            return nullptr;
        }
        if(c < root->count)
            root->leftSide = removeSong(root->leftSide, c);
        else if(c > root->count)
            root->rightSide = removeSong(root->rightSide, c);
        else {
            if(!root->leftSide && !root->rightSide) {
                delete root;
                return nullptr;
            }
            if(!root->leftSide) {
                Track* tmp = root->rightSide;
                delete root;
                return tmp;
            }
            if(!root->rightSide) {
                Track* tmp = root->leftSide;
                delete root;
                return tmp;
            }
            Track* succ = root->rightSide;
            while(succ->leftSide)
                succ = succ->leftSide;
            root->count = succ->count;
            root->title = succ->title;
            root->rightSide = removeSong(root->rightSide, succ->count);
        }
        return root;
    }
};

int main() {
    Playlist music("TeraBanJaunga", 100);
    music.addSong("AfreenAfreen", 150);
    music.addSong("ChaiyyaChaiyya", 90);
    music.addSong("DilDilPakistan", 120);
    music.addSong("TumHiHo", 200);
    music.addSong("AjeebDastanHaiYeh", 170);
    music.addSong("Sayonee", 130);

    cout << endl << "Songs (Inorder - Least to Most Played):" << endl;
    music.showInOrder(music.head);

    cout << endl << "Songs (Postorder - Removed in Reverse Popularity Order):" << endl;
    music.showPostOrder(music.head);

    cout << endl << "Searching song with play count 120..." << endl;
    music.findSong(music.head, 120);

    cout << endl << "Deleting song with play count 120..." << endl;
    music.head = music.removeSong(music.head, 120);

    cout << endl << "Updated Songs (Inorder):" << endl;
    music.showInOrder(music.head);
}
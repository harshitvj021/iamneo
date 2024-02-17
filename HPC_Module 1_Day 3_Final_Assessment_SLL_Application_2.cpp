#include <iostream>
#include <string>
using namespace std;

struct Song {
    string title;
    string artist;
    Song* next;

    Song(const string& t, const string& a) : title(t), artist(a), next(nullptr) {}
};

Song* createSong(const string& title, const string& artist) {
    return new Song(title, artist);
}

void addSong(Song*& head, Song*& tail, const string& title, const string& artist) {
    Song* newSong = createSong(title, artist);

    if (head == nullptr) {
        head = newSong;
        tail = newSong;
    } else {
        tail->next = newSong;
        tail = newSong;
    }
}

void playFromBeginning(Song* head) {
    Song* current = head;
    while (current != nullptr) {
        cout << "Playing: " << current->title << " - " << current->artist << endl;
        current = current->next;
    }
}

void playReverse(Song* current) {
    if (current == nullptr) {
        return;
    }

    playReverse(current->next);
    cout << "Playing: " << current->title << " - " << current->artist << endl;
}

void playFromEnd(Song* head) {
    playReverse(head);
}

int main() {
    Song* head = nullptr;
    Song* tail = nullptr;
    int numSongs;

    cin >> numSongs;
    cin.ignore(); // Consume the newline character

    for (int i = 0; i < numSongs; i++) {
        string title, artist;
        getline(cin, title);
        getline(cin, artist);
        addSong(head, tail, title, artist);
    }

    cout << "Playlist created successfully!\n";

    // Playing songs from the playlist
    cout << "\nPlaying songs from the beginning" << endl;
    playFromBeginning(head);

    cout << "\nPlaying songs from the end" << endl;
    playFromEnd(head);

    // Clean up memory
    while (head != nullptr) {
        Song* temp = head->next;
        delete head;
        head = temp;
    }

    return 0;
}
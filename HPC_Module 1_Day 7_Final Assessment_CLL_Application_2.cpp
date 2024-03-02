#include <iostream>
#include <string>
using namespace std;

struct PlayerNode {
    string playerName;
    PlayerNode* next;

    PlayerNode(string name) : playerName(name), next(nullptr) {}
};

PlayerNode* head = nullptr;

void addPlayer(string playerName) {
    PlayerNode* newNode = new PlayerNode(playerName);

    if (head == nullptr) {
        head = newNode;
        newNode->next = head;
    } else {
        PlayerNode* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }

    cout << "Player " << playerName << " added to the lobby." << endl;
}

void removePlayer(string playerName) {
    if (head == nullptr) {
        cout << "The lobby is empty." << endl;
        return;
    }

    PlayerNode* curr = head;
    PlayerNode* prev = nullptr;

    // Find the player to remove
    do {
        if (curr->playerName == playerName) {
            break;
        }
        prev = curr;
        curr = curr->next;
    } while (curr != head);

    // If player not found
    if (curr->playerName != playerName) {
        cout << "Player " << playerName << " is not in the lobby." << endl;
        return;
    }

    // Remove the player from the lobby
    if (curr == head) {
        if (head->next == head) {
            head = nullptr;
        } else {
            PlayerNode* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = head->next;
            head = head->next;
        }
    } else {
        prev->next = curr->next;
    }
    delete curr;

    cout << "Player " << playerName << " removed from the lobby." << endl;
}

void rotateList() {
    if (head == nullptr) {
        cout << "The lobby is empty." << endl;
        return;
    }

    head = head->next;
    cout << "Next player's turn: " << head->playerName << endl;
}

void displayPlayers() {
    if (head == nullptr) {
        cout << "The lobby is empty." << endl;
        return;
    }

    PlayerNode* temp = head;
    cout << "Players in the lobby: ";
    do {
        cout << temp->playerName << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

int main() {
    int choice;
    string playerName;

    while (true) {
        cin >> choice;
        cin.ignore(); // Consume the newline character

        switch (choice) {
            case 1:
                getline(cin, playerName);
                addPlayer(playerName);
                break;
            case 2:
                getline(cin, playerName);
                removePlayer(playerName);
                break;
            case 3:
                rotateList();
                break;
            case 4:
                displayPlayers();
                break;
            case 5:
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }
}

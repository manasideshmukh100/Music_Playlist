#include <iostream>
using namespace std;

struct Song
{
    char name[50];
    Song *prev;
    Song *next;
};

Song *head = NULL;
Song *tail = NULL;
Song *current = NULL;

void addSong()
{
    Song *newSong = new Song;

    cout << "Enter song name (single word): ";
    cin >> newSong->name;

    newSong->prev = NULL;
    newSong->next = NULL;

    if (head == NULL)
    {
        head = newSong;
        tail = newSong;
        current = newSong;
    }
    else
    {
        tail->next = newSong;
        newSong->prev = tail;
        tail = newSong;
    }

    cout << "Song added successfully.\n";
}

void displayPlaylist()
{
    Song *temp = head;

    if (head == NULL)
    {
        cout << "Playlist is empty.\n";
        return;
    }

    cout << "\nMusic Playlist:\n";

    while (temp != NULL)
    {
        cout << temp->name << "\n";
        temp = temp->next;
    }
}

void searchSong()
{
    Song *temp = head;
    char name[50];

    cout << "Enter song name to search: ";
    cin >> name;

    while (temp != NULL)
    {
        int i = 0;

        while (temp->name[i] == name[i] &&
               temp->name[i] != '\0')
        {
            i++;
        }

        if (temp->name[i] == '\0' &&
            name[i] == '\0')
        {
            cout << "Song found: " << temp->name << "\n";
            return;
        }

        temp = temp->next;
    }

    cout << "Song not found.\n";
}

void deleteSong()
{
    Song *temp = head;
    char name[50];

    cout << "Enter song name to delete: ";
    cin >> name;

    while (temp != NULL)
    {
        int i = 0;

        while (temp->name[i] == name[i] &&
               temp->name[i] != '\0')
        {
            i++;
        }

        if (temp->name[i] == '\0' &&
            name[i] == '\0')
        {
            break;
        }

        temp = temp->next;
    }

    if (temp == NULL)
    {
        cout << "Song not found.\n";
        return;
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;
    else
        tail = temp->prev;

    if (current == temp)
    {
        if (temp->next != NULL)
            current = temp->next;
        else
            current = temp->prev;
    }

    delete temp;

    cout << "Song deleted successfully.\n";
}

void nextSong()
{
    if (current == NULL)
        cout << "Playlist is empty.\n";
    else if (current->next == NULL)
        cout << "This is the last song.\n";
    else
    {
        current = current->next;
        cout << "Current song: " << current->name << "\n";
    }
}

void previousSong()
{
    if (current == NULL)
        cout << "Playlist is empty.\n";
    else if (current->prev == NULL)
        cout << "This is the first song.\n";
    else
    {
        current = current->prev;
        cout << "Current song: " << current->name << "\n";
    }
}

void freePlaylist()
{
    Song *temp;

    while (head != NULL)
    {
        temp = head;
        head = head->next;
        delete temp;
    }

    tail = NULL;
    current = NULL;
}

int main()
{
    int choice;

    do
    {
        cout << "\n--- MUSIC PLAYLIST MANAGER ---\n";
        cout << "1. Add Song\n";
        cout << "2. Display Playlist\n";
        cout << "3. Search Song\n";
        cout << "4. Delete Song\n";
        cout << "5. Next Song\n";
        cout << "6. Previous Song\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";

        cin >> choice;

        switch (choice)
        {
            case 1:
                addSong();
                break;

            case 2:
                displayPlaylist();
                break;

            case 3:
                searchSong();
                break;

            case 4:
                deleteSong();
                break;

            case 5:
                nextSong();
                break;

            case 6:
                previousSong();
                break;

            case 7:
                freePlaylist();
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice.\n";
        }

    } while (choice != 7);

    return 0;
}
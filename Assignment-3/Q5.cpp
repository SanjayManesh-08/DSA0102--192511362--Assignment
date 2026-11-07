
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
using namespace std;

class Time {
    int minutes;
    int seconds;

    void normalize() {
        if (seconds >= 60) {
            minutes += seconds / 60;
            seconds = seconds % 60;
        }
    }

public:
    Time(int m = 0, int s = 0) {
        minutes = m;
        seconds = s;
        normalize();
    }

    // Prefix increment
    Time& operator++() {
        seconds++;
        normalize();
        return *this;
    }

    // Postfix increment
    Time operator++(int) {
        Time old = *this;
        seconds++;
        normalize();
        return old;
    }

    // Equality operator
    bool operator==(const Time& other) const {
        return minutes == other.minutes &&
               seconds == other.seconds;
    }

    // Less-than operator
    bool operator<(const Time& other) const {
        if (minutes == other.minutes) {
            return seconds < other.seconds;
        }
        return minutes < other.minutes;
    }

    void display() const {
        cout << minutes << ":";
        if (seconds < 10) {
            cout << "0";
        }
        cout << seconds << endl;
    }
};

class Playlist {
    vector<string> songs;

public:
    void addSong(const string& song) {
        songs.push_back(song);
    }

    // Non-const subscript operator
    string& operator[](int index) {
        if (index < 0 || index >= (int)songs.size()) {
            throw out_of_range("Invalid playlist index");
        }
        return songs[index];
    }

    // Const subscript operator
    const string& operator[](int index) const {
        if (index < 0 || index >= (int)songs.size()) {
            throw out_of_range("Invalid playlist index");
        }
        return songs[index];
    }

    int size() const {
        return (int)songs.size();
    }
};

int main() {
    cout << "TIME OPERATIONS" << endl;

    Time t(5, 59);

    cout << "Original Time: ";
    t.display();

    Time a = t++;
    cout << "Postfix Result: ";
    a.display();

    cout << "After Postfix: ";
    t.display();

    Time b = ++t;
    cout << "Prefix Result: ";
    b.display();

    cout << boolalpha;
    cout << "Times Equal: " << (a == b) << endl;
    cout << "First Time Less Than Second: "
         << (a < b) << endl;

    cout << "\nPLAYLIST OPERATIONS" << endl;

    Playlist p;

    p.addSong("Song A");
    p.addSong("Song B");
    p.addSong("Song C");

    cout << "Playlist Songs:" << endl;

    for (int i = 0; i < p.size(); i++) {
        cout << p[i] << endl;
    }

    // Modify a song using subscript operator
    p[1] = "Updated Song B";

    cout << "\nAfter Modification:" << endl;

    for (int i = 0; i < p.size(); i++) {
        cout << p[i] << endl;
    }

    // Invalid index test
    try {
        cout << p[-1] << endl;
    }
    catch (const out_of_range& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}


#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
using namespace std;

void display(int n) {
    if (n == 0) {
        cout << "-------" << endl;
    }
    if (n == 1) {
        cout << "-------" << endl;
        cout << "   |   " << endl;
    }
    if (n == 2) {
        cout << "-------" << endl;
        cout << "   |   " << endl;
        cout << "   O   " << endl;
    }
    if (n == 3) {
        cout << "-------" << endl;
        cout << "   |   " << endl;
        cout << "   O   " << endl;
        cout << "   |   " << endl;
    }
    if (n == 4) {
        cout << "-------" << endl;
        cout << "   |   " << endl;
        cout << "   O   " << endl;
        cout << "  /|   " << endl;
    }
    if (n == 5) {
        cout << "-------" << endl;
        cout << "   |   " << endl;
        cout << "   O   " << endl;
        cout << "  /|\\  " << endl;
    }
    if (n == 6) {
        cout << "-------" << endl;
        cout << "   |   " << endl;
        cout << "   O   " << endl;
        cout << "  /|\\  " << endl;
        cout << "  /    " << endl;
    }
    if (n == 7) {
        cout << "-------" << endl;
        cout << "   |   " << endl;
        cout << "   O   " << endl;
        cout << "  /|\\  " << endl;
        cout << "  / \\  " << endl;
    }
}

string arr[5][5] = {
    {"BEAR", "DEER", "FOX", "LION", "WOLF"},
    {"WRESTLING", "CRICKET", "HOCKEY", "GOLF", "TENNIS"},
    {"BEE", "FLY", "BEETLE", "ANT", "FLEA"},
    {"JEEP", "TOYOTA", "HONDA", "TATA", "NISSAN"},
    {"LIVERMORIUM", "BISMUTH", "ROENTGENIUM", "ZIRCONIUM", "DUBNIUM"}
};

pair<string, string> getWord() {
    int x = rand() % 5;
    int y = rand() % 5;
    string element = arr[x][y];
    string category;
    if (x == 0) {
        category = "ANIMALS";
    } else if (x == 1) {
        category = "SPORTS";
    } else if (x == 2) {
        category = "INSECTS";
    } else if (x == 3) {
        category = "CAR BRANDS";
    } else if (x == 4) {
        category = "ELEMENTS";
    }
    return {element, category};
}

pair<bool, vector<int>> in(char ch, string s) {
    bool found = false;
    vector<int> v1;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ch) {
            found = true;
            v1.push_back(i);
        }
    }
    return {found, v1};
}

bool check(vector<char>& s) {
    for (char c : s) {
        if (c == '_') return false; // still hidden
    }
    return true;
}

int main() {
    srand(time(nullptr)); // seed once

    cout << "HANGMAN" << endl;
    int n = 0; // wrong guesses

    pair<string, string> values = getWord();
    string element = values.first;
    string category = values.second;

    cout << "Category: " << category << endl;

    // hidden word with underscores
    vector<char> display_string(element.length(), '_');

    bool win = false;

    while (n <= 7) {
        if (check(display_string)) {
            win = true;
            break;
        }

        display(n);

        // print current word state
        for (char c : display_string) cout << c << " ";
        cout << endl;

        char c;
        cout << "Enter a character: ";
        cin >> c;
        c = toupper(c); // handle lowercase input

        auto result = in(c, element);
        if (result.first) {
            for (int i : result.second) {
                display_string[i] = c;
            }
        } else {
            n++; // wrong guess
        }

        if (n == 7) {
            win = false;
            break;
        }
    }

    if (win) {
        cout << "\n You Win! The word was: " << element << endl;
    } else {
        cout << "\n You Lost! The word was: " << element << endl;
    }

    return 0;
}

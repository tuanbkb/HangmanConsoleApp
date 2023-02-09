#include <iostream>

using namespace std;

void drawHangman(int badGuessCount) {
    switch(badGuessCount) {
        case 0: 
            cout << " _______" << endl;
            cout << " |" << endl;
            cout << " |" << endl;
            cout << " |" << endl;
            cout << " |" << endl;
            cout << "---" << endl;
            break;
        case 1:
            cout << " _______" << endl;
            cout << " |     |" << endl;
            cout << " |" << endl;
            cout << " |" << endl;
            cout << " |" << endl;
            cout << "---" << endl;
            break;
        case 2:
            cout << " _______" << endl;
            cout << " |     |" << endl;
            cout << " |     O" << endl;
            cout << " |" << endl;
            cout << " |" << endl;
            cout << "---" << endl;
            break;
        case 3:
            cout << " _______" << endl;
            cout << " |     |" << endl;
            cout << " |     O" << endl;
            cout << " |     |" << endl;
            cout << " |" << endl;
            cout << "---" << endl;
            break;
        case 4:
            cout << " _______" << endl;
            cout << " |     |" << endl;
            cout << " |     O" << endl;
            cout << " |     |" << endl;
            cout << " |    /" << endl;
            cout << "---" << endl;
            break;
        case 5:
            cout << " _______" << endl;
            cout << " |     |" << endl;
            cout << " |     O" << endl;
            cout << " |     |" << endl;
            cout << " |    / \\" << endl;
            cout << "---" << endl;
            break;
        case 6:
            cout << " _______" << endl;
            cout << " |     |" << endl;
            cout << " |     O" << endl;
            cout << " |    /|" << endl;
            cout << " |    / \\" << endl;
            cout << "---" << endl;
            break;
        case 7:
            cout << " _______" << endl;
            cout << " |     |" << endl;
            cout << " |     O" << endl;
            cout << " |    /|\\" << endl;
            cout << " |    / \\" << endl;
            cout << "---" << endl;
            break;
    }
}
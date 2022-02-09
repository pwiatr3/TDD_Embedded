#include "bowling.hpp"

int main() {
    int totalScore = 0;
    Game game {};
    // Frame 1
    game.roll(6);
    game.roll(2);
    //cout << "Frame 1 points total: "<< game.score() << endl;
    // Frame 2
    game.roll(5);
    game.roll(4);
    //cout << "Frame 2 points total: "<< game.score() << endl;
    // Frame 3
    game.roll(5);
    game.roll(5);
    //cout << "Frame 3 points total: "<< game.score() << endl;
    // Frame 4
    game.roll(6);
    game.roll(2);
    //cout << "Frame 4 points total: "<< game.score() << endl;
    // Frame 5
    game.roll(10);
    //cout << "Frame 5 points total: "<< game.score() << endl;
    // Frame 6
    game.roll(7);
    game.roll(2);
    //cout << "Frame 6 points total: "<< game.score() << endl;
    // // Frame 7
    game.roll(6);
    game.roll(4);
    //cout << "Frame 7 points total: "<< game.score() << endl;
    // // Frame 8
    game.roll(10);
    //cout << "Frame 8 points total: "<< game.score() << endl;
    // Frame 9
    game.roll(7);
    game.roll(2);
    //cout << "Frame 9 points total: "<< game.score() << endl;
    // // Frame 10
    // game.roll(10);
    // game.roll(6);
    // game.roll(3);

    // game.roll(10);
    // game.roll(10);
    // game.roll(10);

    game.roll(9);
    game.roll(1);
    game.roll(10);
    //totalScore = game.score();
    cout << "Frame 10 points total: "<< game.score() << endl;
    return 0;
}
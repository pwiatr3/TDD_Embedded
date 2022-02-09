#pragma once

#include <iostream>
#include <memory>
#include <array>

using namespace std;

constexpr int numOfFrames = 10;
constexpr int numOfRolls = 21;

class Game {
public:
    Game(); // c'tor
    array<int, numOfRolls> rollPoints;
    array<int, numOfFrames> bonusPoints;
    int rollNumber;
    void roll(int pinsKnockedDown);
    int getFramePoints(int rollIndex, int frameNum);
    int score();
    int currentFrame;
};
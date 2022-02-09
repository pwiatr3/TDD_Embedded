#include "bowling.hpp"



// default constructor of Game class
Game::Game() : rollPoints {}, rollNumber(0), bonusPoints{} {}

void Game::roll(int pinsKnockedDown) {

    rollPoints.at(rollNumber) = pinsKnockedDown;
    rollNumber++;
    // if strike and not 10'th frame -> add one empty roll
    if(pinsKnockedDown == 10 && rollNumber < 18) {
        rollPoints.at(rollNumber) = 0;        
        rollNumber++;
    }
}
// returns 1'st, 2'nd or 3'd roll points from frameNum frame
int Game::getFramePoints(int rollIndex, int frameNum) {
    int rollNum = (2 * frameNum) + rollIndex - 1;
    return rollPoints.at(rollNum);
}
int Game::score() {
    int scoreTotal = 0;
    int frameIndex = 0;
    int framePoints = 0;
    int frameBonusPoints = 0;
    int firstRollPoints = 0;
    int secondRollPoints = 0;
    int thirdRollPoints = 0;
    bool isSpare = false;
    bool isStrike = false;

    // add bonus points
    for(frameIndex = 0; frameIndex < numOfFrames; frameIndex++) {
        //reset flags
        isSpare = false;
        isStrike = false;
        framePoints = 0;
        frameBonusPoints = 0;
        firstRollPoints = 0;
        secondRollPoints = 0;
        thirdRollPoints = 0;
        rollNumber = 0;

        if(frameIndex < 9) {
            firstRollPoints = getFramePoints(1, frameIndex); // 1'st roll
            secondRollPoints = getFramePoints(2, frameIndex); // 2'nd roll
            framePoints = firstRollPoints + secondRollPoints;

            // check if strike
            if(firstRollPoints == 10) {
                isStrike = true;
                frameBonusPoints = getFramePoints(1, frameIndex + 1);
                frameBonusPoints += getFramePoints(2, frameIndex + 1);
                
            }
            else if(framePoints == 10) {
            // check if spare
                isSpare = true;
                frameBonusPoints = getFramePoints(1, frameIndex + 1);
            }
            bonusPoints.at(frameIndex) = frameBonusPoints;
            
        }        
        if(frameIndex == 9) {
            firstRollPoints = getFramePoints(1, frameIndex);
            secondRollPoints = getFramePoints(2, frameIndex);
            thirdRollPoints = getFramePoints(3, frameIndex);
            framePoints = firstRollPoints + secondRollPoints + thirdRollPoints;
            int j = 0;
        }
        scoreTotal += framePoints + frameBonusPoints;
        int j = 0;
    }
    return scoreTotal;
}

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
    totalScore = game.score();
    //cout << "Frame 10 points total: "<< game.score() << endl;
    return 0;
}
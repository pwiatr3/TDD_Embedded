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

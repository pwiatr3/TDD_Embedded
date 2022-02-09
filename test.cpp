#include <catch2/catch_test_macros.hpp>
#include "bowling.hpp"

SCENARIO("Testing score() in Game class") {

    GIVEN("Adding to an empty game") {
        Game game {};
        
        // Frame 1
        game.roll(6);
        game.roll(2);
        // Frame 2
        game.roll(5);
        game.roll(4);
        // Frame 3
        game.roll(5);
        game.roll(5);
        // Frame 4
        game.roll(6);
        game.roll(2);
        // Frame 5
        game.roll(10);
        // Frame 6
        game.roll(7);
        game.roll(2);
        // // Frame 7
        game.roll(6);
        game.roll(4);
        // // Frame 8
        game.roll(10);
        // Frame 9
        game.roll(7);
        game.roll(2);
        // Frame 10
        game.roll(10);
        game.roll(6);
        game.roll(3);
                
        WHEN("sort by PESEL is called") {
            THEN("First salary in sorted database is 1000") {
                REQUIRE(game.score() == 136);
            }                       
        }
    }   
}

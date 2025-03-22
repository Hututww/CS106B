#include "Labyrinth.h"
#include <memory>
using namespace std;

bool isPathToFreedom(MazeCell* start, const string& moves) {
    MazeCell *current = start;
    
    bool hasWand = false;
    bool hasPotion = false;
    bool hasSpellBook = false;

    if(current->whatsHere == Item::WAND){
        hasWand = true; 
    }
    if(current->whatsHere == Item::POTION){
        hasPotion = true;
    }
    if(current->whatsHere == Item::SPELLBOOK){
        hasSpellBook = true;
    }

    for(char singleMove : moves){
        if(singleMove == 'N'){
            if (current->north == nullptr){
                return false;
            }
            current = current->north;
        }else if(singleMove == 'S'){
            if (current->south == nullptr){
                return false;
            }
            current = current->south;
        }else if(singleMove == 'E'){
            if (current->east == nullptr){
                return false;
            }
            current = current->east;
        }else if(singleMove == 'W'){
            if (current->west == nullptr){
                return false;
            }
            current = current->west;
        }
    
        if(current->whatsHere == Item::WAND){
            hasWand = true; 
        }
        if(current->whatsHere == Item::POTION){
            hasPotion = true;
        }
        if(current->whatsHere == Item::SPELLBOOK){
            hasSpellBook = true;
        }
    }
    return hasWand && hasPotion && hasSpellBook;
    
}


/* * * * * * Test Cases Below This Point * * * * * */
#include "GUI/SimpleTest.h"
#include "Demos/MazeGenerator.h"
















/* * * * * Provided Tests Below This Point * * * * */

/* Utility function to free all memory allocated for a maze. */
void deleteMaze(const Grid<MazeCell*>& maze) {
    for (auto* elem: maze) {
        delete elem;
    }
    /* Good question to ponder: why don't we write 'delete maze;'
     * rather than what's shown above?
     */
}

PROVIDED_TEST("Checks paths in the sample maze.") {
    auto maze = toMaze({"* *-W *",
                        "| |   |",
                        "*-* * *",
                        "  | | |",
                        "S *-*-*",
                        "|   | |",
                        "*-*-* P"});

    /* These paths are the ones in the handout. They all work. */
    EXPECT(isPathToFreedom(maze[2][2], "ESNWWNNEWSSESWWN"));
    EXPECT(isPathToFreedom(maze[2][2], "SWWNSEENWNNEWSSEES"));
    EXPECT(isPathToFreedom(maze[2][2], "WNNEWSSESWWNSEENES"));

    /* These paths don't work, since they don't pick up all items. */
    EXPECT(!isPathToFreedom(maze[2][2], "ESNW"));
    EXPECT(!isPathToFreedom(maze[2][2], "SWWN"));
    EXPECT(!isPathToFreedom(maze[2][2], "WNNE"));

    /* These paths don't work, since they aren't legal paths. */
    EXPECT(!isPathToFreedom(maze[2][2], "WW"));
    EXPECT(!isPathToFreedom(maze[2][2], "NN"));
    EXPECT(!isPathToFreedom(maze[2][2], "EE"));
    EXPECT(!isPathToFreedom(maze[2][2], "SS"));

    deleteMaze(maze);
}

PROVIDED_TEST("Can't walk through walls.") {
    auto maze = toMaze({"* S *",
                        "     ",
                        "W * P",
                        "     ",
                        "* * *"});

    EXPECT(!isPathToFreedom(maze[1][1], "WNEES"));
    EXPECT(!isPathToFreedom(maze[1][1], "NWSEE"));
    EXPECT(!isPathToFreedom(maze[1][1], "ENWWS"));
    EXPECT(!isPathToFreedom(maze[1][1], "SWNNEES"));

    deleteMaze(maze);
}

PROVIDED_TEST("Works when starting on an item.") {
    auto maze = toMaze({"P-S-W"});

    EXPECT(isPathToFreedom(maze[0][0], "EE"));
    EXPECT(isPathToFreedom(maze[0][1], "WEE"));
    EXPECT(isPathToFreedom(maze[0][2], "WW"));

    deleteMaze(maze);
}


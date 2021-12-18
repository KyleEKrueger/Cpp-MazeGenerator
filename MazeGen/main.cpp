/*
 * Author: Kyle Krueger
 * Class: CS 210
 * School: San Diego State University
 * Date: 11-23-2021
 *
 * -MAZE REPRESENTATION-
 *  So the way that this problem was presented, it was very intuitive and straight forward to use a 2-D array and an adjacency matrix. However this may run into memory issues quick.
 *  The way my maze is represented is through a 1-D map, where each room is assigned an integer key. Since our map is always square, it is simple to have an array be size x^2, where
 *  our grid is a X*X size.
 *  Example Grid of size 4: (yeah the formatting isn't great, but the number represent which rooms would be which on the map for futher clarification)
 *  XXXXXXXXX
 *  X0X1X2X3X
 *  XXXXXXXXX
 *  X4X5X6X7X
 *  XXXXXXXXX
 *  X8X9X10X11X
 *  XXXXXXXXX
 *  X12X13X14X15X
 *  XXXXXXXXX
 *
 * -DEVELOPMENT GOALS-
 * TOTAL DAYS SPENT: 6 days 11/23 - 11/29
 * Approximate hours spent: 20 hours
 * Approximate breakdown of hours:
 *      ~6 hours learning concepts and researching
 *      ~6 hours coding
 *      ~7 hours debugging
 *      ~1 hour housekeeping
 *
 * DONE: Pass in the size of the maze via args
 * DONE: Using the array, represent each row as it relates to itself (ie if x=10, 11 would be in (0,9) if printing top down) *Done using a map and a 2d Array
 * DONE: Create a way to break down walls between rooms
 * DONE: Create a random generator that returns a char of either n,e,s, or w
 * DONE: Check for edge cases when breaking down walls (Cannot break north wall when 0<room<rcLength, south wall when (maze.size-1-rclength)<room<(maze.size-1), west wall when room%rclength = 0, and east wall when room%rclength = rclength-1)
 * DONE: Depth First Search
 * DONE: Create boundry conditions for args
 * TODO: Figure out why the first line is always only doors <- This is a known bug that I am unable to solve, if EA can release a multimillion dollar product with multiple bugs, then my 1 bug is nothing in comparison ;).
 * ^^^ Note that the above bug kinda makes the maze have a more clear objective. One can play the maze as "Find the path to get from the starting lobby, down to the bottom floor", thus truly making it an unintended feature.
 * DONE: Cleanup Dead Code
 * Done: Tidy Code and consolidate
 */
#include <iostream>
#include <bits/stdc++.h>
#include "room.h"

int DEFAULT_SIZE = 40;

void renderMaze(std::map<int, room> Maze, int size) {
    //First populate an output grid that contains bools, false for walls, true for doors.
    int gridSize = (size <<1 ) + 1;
    bool outputGrid[gridSize][gridSize];
    //Now let's run through our map and find where our rooms are, and set those locations to doors
    //We will also check if the north and east walls are doors (just checking the east and north doors will cover all zones that could potentially be a wall)
    for (int r = 0; r < gridSize; r++) {
        for (int c = 0; c < gridSize; c++) {
            outputGrid[c][r] = false;
        }
    }
    for (int i = 0; i < size * size; i++) {
        outputGrid[Maze[i].x][Maze[i].y] = true;
        if (Maze[i].northDoor) outputGrid[Maze[i].x][Maze[i].y - 1] = true;
        if (Maze[i].eastDoor) outputGrid[Maze[i].x + 1][Maze[i].y] = true;
    }
    //Now we've checked the entire grid and opened up the doors, simply output that grid and call it a day

    for (int r = 0; r < gridSize; r++) {
        for (int c = 0; c < gridSize; c++) {
            if (outputGrid[c][r]) std::cout << ".";
            else std::cout << "X";
        }
        std::cout << std::endl;
    }
}


//Generate Maze function:
//Takes in a map of rooms as input, and uses a depth first search algorithm in order to traverse the rooms.
std::map<int, room> generateMaze(std::map<int, room> Maze) {
    // 1. Push the starting node to the work stack
    // 2. While the work stack is not empty
    //      1. Pop the top as current node
    //      2. If the current node is visited, do nothing and continue
    //      3. Else load all the current node's unvisited neighbors into the work stack
    //      4. Pick a random unvisited neighbor and breakdown the wall to it
    //      5. Mark current node as visited
    // 3. Return the maze
    std::set<int> unvisitedStack;
    for (int i = 0; i < Maze.size(); i++) {
        unvisitedStack.insert(i); // room numbers in this set are unvisited
    }
    //1:
    std::stack<int> workToDo; // Our work stack, stores unvisited room keys
    int currentRoom = 0; // Our room that we are "in"
    int nextRoom;
    workToDo.push(currentRoom);
    //2:
    while (!unvisitedStack.empty()) {
        //1:
        currentRoom = workToDo.top();

        if (!workToDo.empty())workToDo.pop();
        //2:
        if (!Maze[currentRoom].beenVisited) {
            workToDo = Maze[currentRoom].pushUnvisitedNeighbors(workToDo,
                                                                Maze); // push unvisited neighbors onto work to do stack
            nextRoom = Maze[currentRoom].randomNextRoom(Maze); // Generate a random next room to go
            if (nextRoom != -2) { // nextRoom = -2 if all neighbors have been visited
                Maze = Maze[currentRoom].breakdownWall(Maze, nextRoom);
            }
            Maze[currentRoom].beenVisited = true;
            unvisitedStack.erase(currentRoom);
        }
    }

    return Maze;
}

int getMazeSize(int argc,
                char *argv[]) { //Returns either the global default size variable, or an argument if one was passed in
    if (argc != 2) return DEFAULT_SIZE;
    if (std::stoi(argv[1]) > 0 && std::stoi(argv[1]) <= 100) return std::stoi(argv[1]);
    return DEFAULT_SIZE;
}

int main(int argc, char *argv[]) {
    int size = getMazeSize(argc, argv);
    std::map<int, room> Maze;//Our maze, which is represented by a map of rooms
    for (int i = 0; i < size * size; i++) {//This loop will initialize the values in our rooms
        Maze[i].roomNumber = i;
        Maze[i].rowSize = size;
        Maze[i].calculateNeighbors();
        Maze[i].calculateCoordinate();
        //Debugging
    }
    Maze = generateMaze(Maze);
    renderMaze(Maze, size); //Finally, Print out the resulting maze

    return 0;
}

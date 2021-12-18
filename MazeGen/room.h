//
// Created by imakepoptarts on 11/23/21.
//

#ifndef MAZEGEN_ROOM_H
#define MAZEGEN_ROOM_H


class room {
public:
    //The room of our maze, starting from the top left, each row being defined by roomNumber/rowSize
    int roomNumber;
    //The amount of rooms per row. This is passed in by a command line argument, or set to 40 by default
    int rowSize;
    //x and y coordinates on the output grid
    int x;
    int y;
    //Condition will be true if we have been in the room
    bool beenVisited = false;
    //Below is relationship information, stating the key values for all the neighbors, and if a door exists between them (south and west doors are never checked, however I kept them in case we wanted to check a specific room)
    bool northDoor = false;
    int northRoomNumber;
    bool southDoor = false;
    int southRoomNumber;
    bool eastDoor = false;
    int eastRoomNumber;
    bool westDoor = false;
    int westRoomNumber;

    //ROOM FUNCTIONS
    void calculateNeighbors() { // Checks if there is a valid neighbor in each direction, and stores the room numbers
        //NORTH
        if (roomNumber - rowSize >= 0) northRoomNumber = roomNumber - rowSize;
        else northRoomNumber = -1;
        //SOUTH
        if (roomNumber + rowSize < rowSize * rowSize) southRoomNumber = roomNumber + rowSize;
        else southRoomNumber = -1;
        //EAST
        if (roomNumber % rowSize != rowSize - 1) eastRoomNumber = roomNumber + 1;
        else eastRoomNumber = -1;
        //WEST
        if (roomNumber % rowSize != 0) westRoomNumber = roomNumber - 1;
        else westRoomNumber = -1;
    }

    void
    calculateCoordinate() { //These are the functions that will give me the coordinates to the center of the rooms based on their room numbers
        x = (2 * (roomNumber % rowSize) + 1);
        y = (2 * (roomNumber / rowSize) + 1);
    }

    //MAZE HELPER FUNCTIONS
    std::stack<int> pushUnvisitedNeighbors(std::stack<int> unvisitedStack, std::map<int, room> Maze) {
        //First we check if there is a room and that it is not our next room, then check if the room has been visited, and push it to the stack if it has not
        //North

        if (northRoomNumber != -1) { // Check if the north room is a room that we are not traveling to, proceed if true
            if (!Maze[northRoomNumber].beenVisited) { // Check if the north room is marked unvisited
                unvisitedStack.push(northRoomNumber); // Push to the unvisited stack
            }
        }
        //South
        if (southRoomNumber != -1) {
            if (!Maze[southRoomNumber].beenVisited) {
                unvisitedStack.push(southRoomNumber);
            }
        }
        //East
        if (eastRoomNumber != -1) {
            if (!Maze[eastRoomNumber].beenVisited) {
                unvisitedStack.push(eastRoomNumber);
            }
        }
        //West
        if (westRoomNumber != -1) {
            if (!Maze[westRoomNumber].beenVisited) {
                unvisitedStack.push(westRoomNumber);
            }
        }
        return unvisitedStack;
    }

    std::map<int, room> breakdownWall(std::map<int, room> Maze,
                                      int nextRoom) { // Given a direction, open the door in that direction and the opposite door in the room we are entering
        if (nextRoom == northRoomNumber) {
            Maze[roomNumber].northDoor = true;
            Maze[northRoomNumber].southDoor = true;
        }
        if (nextRoom == southRoomNumber) {
            Maze[roomNumber].southDoor = true;
            Maze[southRoomNumber].northDoor = true;
        }
        if (nextRoom == eastRoomNumber) {
            Maze[roomNumber].eastDoor = true;
            Maze[eastRoomNumber].westDoor = true;
        }
        if (nextRoom == westRoomNumber) {
            Maze[roomNumber].westDoor = true;
            Maze[westRoomNumber].eastDoor = true;
        }
        return Maze;
    }

    //Places all unvisited neighbors onto a stack, and pops a random amount between 0-3 (end of range shrinks if there are less options) before returning the top of the stack, returns -2 if there are no visitable neighbors
    int randomNextRoom(std::map<int, room> Maze) {
        std::stack<int> unvisitedNeighbors;
        //1. Add visitable, unvisited neighbors to a set
        if (northRoomNumber != -1) { // checks if it is a wall
            if (Maze[northRoomNumber].beenVisited) { //checks if it has been visited
                unvisitedNeighbors.push(northRoomNumber);
            }
        }
        if (southRoomNumber != -1) { // checks if it is a wall
            if (Maze[southRoomNumber].beenVisited) { //checks if it has been visited
                unvisitedNeighbors.push(southRoomNumber);
            }
        }
        if (eastRoomNumber != -1) { // checks if it is a wall
            if (Maze[eastRoomNumber].beenVisited) { //checks if it has been visited
                unvisitedNeighbors.push(eastRoomNumber);
            }
        }
        if (westRoomNumber != -1) { // checks if it is a wall
            if (Maze[westRoomNumber].beenVisited) { //checks if it has been visited
                unvisitedNeighbors.push(westRoomNumber);
            }
        }
        if (unvisitedNeighbors.empty()) return -2;
        srand(time(nullptr) + roomNumber);//rng seed
        int randNum = rand() % unvisitedNeighbors.size(); // 0-unvisited size rng
        for (int i = 0; i < randNum; i++) {
            unvisitedNeighbors.pop();
        }
        return unvisitedNeighbors.top();

    }

};


#endif //MAZEGEN_ROOM_H

// === Region: Project Overview ===
//
//  COMP2011 Spring 2023 
//  PA1: Moving Blocks to Targets Game
// 
//  Your name: KAO, Chi Yuk
//  Your ITSC email: cykao@connect.ust.hk 
//
//
//  Project TA: CHUNG, Peter (cspeter@cse.ust.hk)
//
//  For code-level questions, please send a direct email to the above TA. 
//  Asking questions with code blocks in a public discussion forum (e.g., Piazza) may cause plagiarism issues
//  Usually, you will get the quickest response via a direct email.
//
// =====================================

// === Region: Headers ===
// iostream and cstring are included. 
// Do not include extra header files 
// =======================
#include <iostream>
#include <cstring>
using namespace std;

// === Region: Constants ===
// Useful constants are defined for this project assignment
// =======================
const int MAX_ROWS = 20;
const int MAX_COLS = 30;
const int MAX_NUM_BLOCKS = 26;
const char CHAR_EMPTY = '.';
const char CHAR_WALL = '#';
const char CHAR_TARGET = '*';
const char CHAR_END_INPUT = '!';
const char DIRECTION_EAST = 'e';
const char DIRECTION_WEST = 'w';
const char DIRECTION_SOUTH = 's';
const char DIRECTION_NORTH = 'n';

// === Region: function declarations ===
// The function declarations. 
// The implementation is done in the function definitions 
// =====================================

/**
 * function: readInput reads the game map, the number of rows, and the number of columns 
 * @param map:     a 2D character array storing the game map
 * @param mapRows: the number of rows of the game map. Note: it is pass by reference.
 * @param mapCols: the number of columns of the game map. Note: it is pass by reference. 
 * 
 * Note: This function is given. You don't need to implement this function 
*/
void readInput(char map[MAX_ROWS][MAX_COLS], int& mapRows, int& mapCols);

/**
 * function: displayMap displays the current game map
 * @param map:     a 2D character array storing the game map
 * @param mapRows: the number of rows of the game map
 * @param mapCols: the number of columns of the game map
 * 
 * Note: This function is given. You don't need to implement this function
*/
void displayMap(const char map[MAX_ROWS][MAX_COLS], const int mapRows, const int mapCols);

/**
 * function: isValidBlockLetter checks whether a block letter is valid
 * @param map:    a 2D character array storing the game map
 * @param mapRows: the number of rows of the game map
 * @param mapCols: the number of columns of the game map
 * @param letter:  the block letter
 * 
 * @return true if letter is between A to Z (capital letter, inclusive) and the letter can be found inside the map. 
 * Otherwise, return false. 
 * 
 * For example, if the letter is C (capital letter, and is between A..Z) but cannot be found in the game map, you should return false
*/
bool isValidBlockLetter(const char map[MAX_ROWS][MAX_COLS], const int mapRows, const int mapCols, const char letter);

/**
 * function: isValidDirectionLetter checks whether the letter is a valid direction letter
 * @param letter: the direction letter
 * 
 * @return true if the direction letter is valid. Otherwise, return false 
 * 
 * Note: You can use constants DIRECTION_XXX defined above 
*/
bool isValidDirectionLetter(const char letter);


/**
 * function: countBlocksInMap counts the number of blocks in the game map
 * @param: map: a 2D character array storing the game map
 * @param mapRows: the number of rows of the game map
 * @param mapCols: the number of columns of the game map
 * 
 * @return the numbers of blocks in the game map
*/
int countBlocksInMap(const char map[MAX_ROWS][MAX_COLS], const int mapRows, const int mapCols);


/**
 * function: updateMapReturnArrival updates the game map based on the blockLetter and the direction letter
 * @param: map: a 2D character array storing the game map
 * @param mapRows: the number of rows of the game map
 * @param mapCols: the number of columns of the game map
 * @param blockLetter: a block letter. The block letter needs to be valid
 * @param directionLetter: a direction letter. The direction letters needs to be valid
 * 
 * Note: This function will update the game map
 * 
 * @return true if the block arrives one of the targets. Otherwise, return false.
 * 
*/
bool updateMapReturnArrival(char map[MAX_ROWS][MAX_COLS], const int mapRows, const int mapCols, 
                char blockLetter, char directionLetter);

/**
 * function: updateBlockArrivalHistory updates the arrival history (i.e., a 1D character array)
 * @param blockArrivalHistory: a 1D array storing the block arrival history
 * @param blockLetter: a block letter. The block letter needs to be valid
 * @param totalArrivalBlock: the total number of blocks arrived so far. Note: it is pass by reference.
 * 
*/
void updateBlockArrivalHistory(char blockArrivalHistory[MAX_NUM_BLOCKS], 
                                const char blockLetter,
                                int& totalArrivalBlock);

/**
 * function: the main function
 * 
 * Note: The main function is given. 
 * Do not modify anything inside the main function
*/
int main() {

    char map[MAX_ROWS][MAX_COLS];
    char blockLetter, directionLetter;
    int mapRows, mapCols, totalSteps, totalBlocks, totalArrivalBlock, i;
    bool checkBlockLetter, checkDirectionLetter, isArrived;
    char blockArrivalHistory[MAX_NUM_BLOCKS];

    // Start by reading the input
    // Usage:
    // ./pa1 < testcase/inputXX.txt
    readInput(map, mapRows, mapCols);

    totalArrivalBlock = 0;

    cout << "The original map: " << endl;
    displayMap(map, mapRows, mapCols);

    while (true) {
        cin >> blockLetter >> directionLetter  ;
        if ( blockLetter == CHAR_END_INPUT && directionLetter == CHAR_END_INPUT)
            break;

        checkBlockLetter = isValidBlockLetter(map, mapRows, mapCols, blockLetter);
        checkDirectionLetter = isValidDirectionLetter(directionLetter);

        if ( checkBlockLetter == false && checkDirectionLetter == false ) {
            cout << "Both block letter " << blockLetter << " and direction letter " << directionLetter << " are invalid" << endl;
        } else if ( checkBlockLetter == false ) {
            cout << "Block letter " << blockLetter << " is invalid" << endl;
        } else if ( checkDirectionLetter == false) {
            cout << "Direction letter " << directionLetter << " is invalid" << endl;
        } else {
            cout << "Move block " << blockLetter << " to the direction " << directionLetter << endl;
            isArrived = updateMapReturnArrival(map, mapRows, mapCols, blockLetter, directionLetter);
            if ( isArrived ) {
                updateBlockArrivalHistory(blockArrivalHistory, blockLetter, totalArrivalBlock);
            }
            displayMap(map, mapRows, mapCols);
        }
    }

    cout << "=== Game Ended ===" << endl;
    cout << countBlocksInMap(map, mapRows, mapCols) << " block(s) remain(s) in the map" << endl;
    if ( totalArrivalBlock > 0) {
        cout << "The escape order is " ;
        for (i=0; i<totalArrivalBlock; i++)
            cout << blockArrivalHistory[i];
        cout << endl;
    } else {
        cout << "No blocks escape the map" << endl;
    }
  

    return 0;
}

void updateBlockArrivalHistory(char blockArrivalHistory[MAX_NUM_BLOCKS], 
                                const char blockLetter,
                                int& totalArrivalBlock) {

    blockArrivalHistory[totalArrivalBlock] = blockLetter;
    totalArrivalBlock++;

}


bool isValidBlockLetter(
        const char map[MAX_ROWS][MAX_COLS], 
        const int mapRows, 
        const int mapCols, 
        const char letter) {
        
        int r, c;
        for (r=0;r<mapRows; r++) 
        {
            for (c=0; c<mapCols; c++)
            {
                if (map[r][c] == letter) 
                    return true;
            }
        }
                return false; // TODO: delete this line and write your own code
}

bool isValidDirectionLetter(const char letter) {
    switch (letter)
    {
        case DIRECTION_EAST:
        case DIRECTION_SOUTH:
        case DIRECTION_WEST:
        case DIRECTION_NORTH:
            return true;
        default:
            return false;
    }
}

int countBlocksInMap(const char map[MAX_ROWS][MAX_COLS], const int mapRows, const int mapCols) {
    int r,c,test,count=0;
    for (r=0;r<mapRows; r++) 
        {
            for (c=0; c<mapCols; c++)
            {
                test = map[r][c];
                if (test >= static_cast<int>('A') && test <= static_cast<int>('Z')) 
                    count++;
            }
        }
    return count;
}





bool updateMapReturnArrival(char map[MAX_ROWS][MAX_COLS], const int mapRows, const int mapCols, 
                char blockLetter, char directionLetter) {
    int r,c, thisRow, thisCol;
    for (r=0;r<mapRows; r++) 
        {
            for (c=0; c<mapCols; c++)
            {
                if (map[r][c] == blockLetter)
                {
                    thisRow = r;
                    thisCol = c;
                }
            }
        }
    switch (directionLetter)
    {
        case DIRECTION_EAST:
            for(c = thisCol; c < mapCols; c++)
            {
                if (map[thisRow][c+1] == CHAR_TARGET)
                {
                    map[thisRow][thisCol] = CHAR_EMPTY;
                    return true;
                }
                else if(map[thisRow][c+1] == CHAR_WALL || (static_cast<int>(map[thisRow][c+1])>='A' && static_cast<int>(map[thisRow][c+1])<='Z') || (c+1) == mapCols)
                {
                    map[thisRow][thisCol] = CHAR_EMPTY;
                    map[thisRow][c] = blockLetter;
                    break;
                }
            }
            break;

        case DIRECTION_SOUTH:
            for(r = thisRow; r < mapRows; r++)
            {
                if (map[r+1][thisCol] == CHAR_TARGET)
                {
                    map[thisRow][thisCol] = CHAR_EMPTY;
                    return true;
                }
                    
                else if(map[r+1][thisCol] == CHAR_WALL || (static_cast<int>(map[r+1][thisCol])>='A' && static_cast<int>(map[r+1][thisCol])<='Z') || (r+1) == mapRows)
                {
                    
                    map[thisRow][thisCol] = CHAR_EMPTY;
                    map[r][thisCol] = blockLetter;
                    break;
                }
            }

            
            break;
        
        case DIRECTION_WEST:
            for(c = thisCol; c >= 0 ; c--)
            {
                if (map[thisRow][c-1] == CHAR_TARGET)
                {
                    map[thisRow][thisCol] = CHAR_EMPTY;
                    return true;
                }
                    
                else if(map[thisRow][c-1] == CHAR_WALL || (static_cast<int>(map[thisRow][c-1])>='A' && static_cast<int>(map[thisRow][c-1])<='Z') || c == 0)
                {
                    map[thisRow][thisCol] = CHAR_EMPTY;
                    map[thisRow][c] = blockLetter;
                    break;
                }
            }
            break;
        case DIRECTION_NORTH:
            for(r = thisRow; r >= 0; r--)
            {
                if (map[r-1][thisCol] == CHAR_TARGET)
                {
                    map[thisRow][thisCol] = CHAR_EMPTY;
                    return true;
                }
                    
                else if(map[r-1][thisCol] == CHAR_WALL || (static_cast<int>(map[r-1][thisCol])>='A' && static_cast<int>(map[r-1][thisCol])<='Z') || r == 0)
                {
                    map[thisRow][thisCol] = CHAR_EMPTY;
                    map[r][thisCol] = blockLetter;
                    break;
                }
            }
            break;
        default:
            return false;
    }
    return false;
}




void readInput(char map[MAX_ROWS][MAX_COLS], int& mapRows, int& mapCols) {
    int r, c;
    char line[MAX_COLS+1]; // character array to store each line
    cin >> mapRows >> mapCols;
    cin.ignore();  // ignore the end line character in the first line 
    for (r=0;r<mapRows; r++) {
        cin.getline(line, MAX_COLS+1);
        for (c=0; c<mapCols; c++)
            map[r][c] = line[c];
    }
}

void displayMap(const char map[MAX_ROWS][MAX_COLS], const int mapRows, const int mapCols) {
    int r, c;
    for (r=0;r<mapRows; r++) {
        for (c=0; c<mapCols; c++)
            cout << map[r][c] << " ";
        cout << endl ;
    }
}
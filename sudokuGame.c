//Importing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>



//Creating board Struct with all the array names and sizes
struct board{
    int y1[9];
    int y2[9];
    int y3[9];
    int y4[9];
    int y5[9];
    int y6[9];
    int y7[9];
    int y8[9];
    int y9[9];

    int y1Not[9];
    int y2Not[9];
    int y3Not[9];
    int y4Not[9];
    int y5Not[9];
    int y6Not[9];
    int y7Not[9];
    int y8Not[9];
    int y9Not[9];
};
typedef struct board Board;
struct board currentBoard;

//Board difficulty
struct board easyBoard(){

    struct board easyBoardStruct = {{3,5,0,4,0,0,8,0,6}, 
                                    {0,7,6,8,1,0,0,0,0}, 
                                    {0,0,0,0,6,0,0,0,2}, 
                                    {0,0,0,0,4,0,6,3,0}, 
                                    {0,0,3,5,0,0,0,0,0}, 
                                    {6,1,0,0,0,0,0,2,4}, 
                                    {5,9,1,0,8,4,7,6,0}, 
                                    {0,0,0,0,5,7,0,0,1}, 
                                    {0,6,4,0,9,3,2,8,5},

                                    {3,5,0,4,0,0,8,0,6}, 
                                    {0,7,6,8,1,0,0,0,0}, 
                                    {0,0,0,0,6,0,0,0,2}, 
                                    {0,0,0,0,4,0,6,3,0}, 
                                    {0,0,3,5,0,0,0,0,0}, 
                                    {6,1,0,0,0,0,0,2,4}, 
                                    {5,9,1,0,8,4,7,6,0}, 
                                    {0,0,0,0,5,7,0,0,1}, 
                                    {0,6,4,0,9,3,2,8,5}
                                    };

    return easyBoardStruct;
}
struct board mediumBoard(){

    struct board mediumBoardStruct = {{0,3,0,4,9,6,0,0,0}, 
                                    {7,4,0,0,0,8,3,9,0}, 
                                    {0,0,0,0,5,3,0,8,4}, 
                                    {0,0,0,1,0,0,0,6,0}, 
                                    {3,7,8,9,6,0,0,0,5}, 
                                    {5,0,1,0,7,0,9,0,0}, 
                                    {9,0,4,5,3,1,6,0,0}, 
                                    {0,5,0,6,0,9,0,0,0}, 
                                    {6,1,0,0,2,0,0,4,0},

                                    {0,3,0,4,9,6,0,0,0}, 
                                    {7,4,0,0,0,8,3,9,0}, 
                                    {0,0,0,0,5,3,0,8,4}, 
                                    {0,0,0,1,0,0,0,6,0}, 
                                    {3,7,8,9,6,0,0,0,5}, 
                                    {5,0,1,0,7,0,9,0,0}, 
                                    {9,0,4,5,3,1,6,0,0}, 
                                    {0,5,0,6,0,9,0,0,0}, 
                                    {6,1,0,0,2,0,0,4,0},
                                    };

    return mediumBoardStruct;
}
struct board hardBoard(){

    struct board hardBoardStruct = {{0,7,0,0,0,4,5,0,0}, 
                                    {0,0,1,2,0,7,0,0,0}, 
                                    {0,4,0,6,0,0,8,0,0}, 
                                    {0,0,5,0,7,0,0,6,0}, 
                                    {0,0,0,4,0,9,0,0,0}, 
                                    {9,0,0,0,6,0,0,7,4}, 
                                    {0,0,7,0,3,0,4,0,0}, 
                                    {3,0,0,0,0,0,0,0,8}, 
                                    {2,0,4,0,0,0,7,5,3},

                                    {0,7,0,0,0,4,5,0,0}, 
                                    {0,0,1,2,0,7,0,0,0}, 
                                    {0,4,0,6,0,0,8,0,0}, 
                                    {0,0,5,0,7,0,0,6,0}, 
                                    {0,0,0,4,0,9,0,0,0}, 
                                    {9,0,0,0,6,0,0,7,4}, 
                                    {0,0,7,0,3,0,4,0,0}, 
                                    {3,0,0,0,0,0,0,0,8}, 
                                    {2,0,4,0,0,0,7,5,3}
                                    };

    return hardBoardStruct;
}
struct board emptyBoard(){
    struct board emptyBoard = {0};

    return emptyBoard;
}

//Declaring structs for the undo and redo function
struct board undoStack[100];
int undoTop = -1;
struct board redoStack[100];
int redoTop = -1;
int timeLimit;

//Declaring menu function so it can be called before it is coded
void menu(struct board currentBoard);
void displayBoard(struct board displayCurrentBoard);
void writeToFile();
bool isPresetValue(struct board currentBoard, int x, int y);
void pushUndoStack(struct board currentBoard);
bool isTimeUp(time_t startTime);
int main();


//All necessary functions
struct board inputValue(struct board currentBoard){
    int x;
    int y;
    int newValue;
    
    //Get user inputs
    printf("Enter y coordinate \n");
    scanf("%d", &y);
    writeToFile(y);

    printf("Enter x coordinate \n");
    scanf("%d", &x);
    writeToFile(x);
    
    


     // Check if the cell contains a preset value
    if (isPresetValue(currentBoard, x, y)) {
        printf("Cannot overwrite preset value.\n");
        displayBoard(currentBoard);
        return currentBoard; // Return the unchanged board
    }

    printf("Enter new value \n");
    scanf("%d", &newValue);
    writeToFile(newValue);

    // Update the board if the value is within the valid range
    if (newValue >= 1 && newValue <= 9) {
        // Update the board
        switch (y) {
            case 1:
                currentBoard.y1[x - 1] = newValue;
                break;
            case 2:
                currentBoard.y2[x - 1] = newValue;
                break;
            case 3:
                currentBoard.y3[x - 1] = newValue;
                break;
            case 4:
                currentBoard.y4[x - 1] = newValue;
                break;
            case 5:
                currentBoard.y5[x - 1] = newValue;
                break;
            case 6:
                currentBoard.y6[x - 1] = newValue;
                break;
            case 7:
                currentBoard.y7[x - 1] = newValue;
                break;
            case 8:
                currentBoard.y8[x - 1] = newValue;
                break;
            case 9:
                currentBoard.y9[x - 1] = newValue;
                break;
            default:
                printf("Invalid y coordinate.\n");
                break;
        }
    } else {
        printf("Invalid value. Please enter a value between 1 and 9.\n");
    }
    pushUndoStack(currentBoard);
    displayBoard(currentBoard);
    return currentBoard;
}

bool isPresetValue(struct board currentBoard, int x, int y) {
    switch (y) {
        case 1:
            return currentBoard.y1Not[x - 1] != 0;
        case 2:
            return currentBoard.y2Not[x - 1] != 0;
        case 3:
            return currentBoard.y3Not[x - 1] != 0;
        case 4:
            return currentBoard.y4Not[x - 1] != 0;
        case 5:
            return currentBoard.y5Not[x - 1] != 0;
        case 6:
            return currentBoard.y6Not[x - 1] != 0;
        case 7:
            return currentBoard.y7Not[x - 1] != 0;
        case 8:
            return currentBoard.y8Not[x - 1] != 0;
        case 9:
            return currentBoard.y9Not[x - 1] != 0;
        default:
            printf("Invalid y coordinate.\n");
            return false;
    }
}


void pushUndoStack(struct board currentBoard) {
    if (undoTop < 100 - 1) {
        undoStack[++undoTop] = currentBoard;
    } else {
        printf("Undo stack overflow\n");
    }
}
void undo(struct board *currentBoard) {
    printf("Undo \n");

    if (undoTop >= 0) {
        //undo the top of the undo stack and change the board
        *currentBoard = undoStack[undoTop--];
        //change redo stack to be of the current board
        redoStack[++redoTop] = *currentBoard;
    } else {
        printf("Undo stack is empty\n");
    }

    // Display the updated board
    displayBoard(*currentBoard);
}
void redo(struct board *currentBoard) {
    printf("Redo \n");

    if (redoTop >= 0) {
        //Pop value off of the redo stack 
        *currentBoard = redoStack[redoTop--];
        //add the move to the undo stack
        pushUndoStack(*currentBoard);
    } else {
        printf("Redo stack is empty\n");
    }

    // Display the updated board
    displayBoard(*currentBoard);
}


struct board delete(struct board currentBoard){

    int x;
    int y;
    
    
    printf("Enter y coordinate \n");
    scanf("%d", &y);
    writeToFile(y);

    printf("Enter x coordinate \n");
    scanf("%d", &x);
    writeToFile(x);
    
     // Check if the cell contains a preset value
    if (isPresetValue(currentBoard, x, y)) {
        printf("Cannot overwrite preset value.\n");
        displayBoard(currentBoard);
        return currentBoard;
    }

        // Update the board
        switch (y) {
            case 1:
                currentBoard.y1[x - 1] = 0;
                break;
            case 2:
                currentBoard.y2[x - 1] = 0;
                break;
            case 3:
                currentBoard.y3[x - 1] = 0;
                break;
            case 4:
                currentBoard.y4[x - 1] = 0;
                break;
            case 5:
                currentBoard.y5[x - 1] = 0;
                break;
            case 6:
                currentBoard.y6[x - 1] = 0;
                break;
            case 7:
                currentBoard.y7[x - 1] = 0;
                break;
            case 8:
                currentBoard.y8[x - 1] = 0;
                break;
            case 9:
                currentBoard.y9[x - 1] = 0;
                break;
            default:
                printf("Invalid y coordinate.\n");
                break;
        }
    displayBoard(currentBoard);
    return currentBoard;
}

int quit(){
    printf("Goodbye \n");
    exit(0);

}

bool isSolved(struct board currentBoard) {


    //Check all rows
    for (int i = 0; i < 9; i++){
        //Initializes an array to check each value in the row
        int rowCheck[10] = {false}; 
        //J represents the column in a 2D array
        for (int j = 0; j < 9; j++) {
            //The formula [i * 9 + j] makes the row and column indexes of a 2D array into a 1D array
            int value = currentBoard.y1[i * 9 + j];
            //Checks if the number is 0 or if the value has already been entered in the row
            if (value == 0 || rowCheck[value] != 0) {
                //If there is a 0 or a value that has already been entered it will return false as the row is not solved
                return false;
            }
            //Changes the value of the number to true as it has been checked
            rowCheck[value] = true;
        }
    }

    // Check all columns
    //i represents the row (x) coordinate
    for (int i = 0; i < 9; i++) {
        //Initializes an array to check each value in the column
        int columnCheck[10] = {false}; 
        //j represents the colimn (y) coordinate
        for (int j = 0; j < 9; j++) {
            //Checks the first value of each column using the formula used to check the row just flipped to accomodate columns
            int value = currentBoard.y1[j * 9 + i];
            //Checks if the value has been entered before or if there there hasn't been anything inputted
            if (value == 0 || columnCheck[value] != 0) {
                //If there is a 0 or a value that has already been entered it will return false as the column is not solved
                return false; 
            }
            //Changes the value of the number to true as it has been checked
            columnCheck[value] = true;
        }
    }

    // Check 3x3 subgrids
    //k represents the row of the grid and traverses the array by 3 for each grid
    for (int k = 0; k < 9; k += 3) {
        //l represents the column of the grid and traverses the array by 3 for each grid
        for (int l = 0; l < 9; l += 3) {
            //Initializes an array to check each value in the grid
            int gridCheck[10] = {false}; 
            //i represents the row values that are being checked in the grid k
            for (int i = k; i < k + 3; i++) {
                //j represents the column values that are being checked in the grid l
                for (int j = l; j < l + 3; j++) {
                    //The formula calculates the index in the 1D array as if it were a 2D array
                    int value = currentBoard.y1[(i * 9) + j];
                    //Checks if the value is 0 or if the value has been entered before
                    if (value == 0 || gridCheck[value] != 0) {
                        //If there is a 0 or a value that has already been entered it will return false as the grid is not solved
                        return false; 
                    }
                    //Changes the value of the number to true as it has been checked
                    gridCheck[value] = true;
                }
            }
        }
    }
    //Once all the values in the sudoku grid have been checked and there are no 0's or duplicate values in the same row, column or grid then the code will return true
    return true;
}

void writeToFile(input){
    //Create file pointer
    FILE *file;
    //Opens the savegame file and appends new value to the file
    file = fopen("savegame.txt", "a");
    fprintf(file, "%d", input);
    fclose(file);

}

void displayBoard(struct board displayCurrentBoard) {
    //Prints horizontal coordinate system
    printf("    1  2  3   4  5  6   7  8  9\n");
    //Top line of grid
    printf("   -----------------------------\n");
    for (int i = 0; i < 9; i++) {
        int yValue = i+1;
        //Prints vertical coordinate system along with vertical line
        printf("%d |", yValue);
        for (int j = 0; j < 9; j++) {
            int value;
            //Switch cases to get each row using i as the y value and j as the column value
            switch (i) {
                case 0: value = displayCurrentBoard.y1[j]; break;
                case 1: value = displayCurrentBoard.y2[j]; break;
                case 2: value = displayCurrentBoard.y3[j]; break;
                case 3: value = displayCurrentBoard.y4[j]; break;
                case 4: value = displayCurrentBoard.y5[j]; break;
                case 5: value = displayCurrentBoard.y6[j]; break;
                case 6: value = displayCurrentBoard.y7[j]; break;
                case 7: value = displayCurrentBoard.y8[j]; break;
                case 8: value = displayCurrentBoard.y9[j]; break;
            }
            if (value == 0) {
                //Prints space if the value of the index is 0
                printf("   ");
            } else {
                //Prints value of index
                printf(" %d ", value);
            }
            if ((j + 1) % 3 == 0) {
                //Adds vertical seperator after every 3 columns
                printf("|");
            }
        }
        printf("\n");
        if ((i + 1) % 3 == 0 && i != 8) {
            // Add horizontal separator after every 3 rows
            printf("  |---------|---------|---------|\n"); 
        }
    }
    //Bottom line of grid
    printf("   -----------------------------\n");
}

void menu(struct board currentBoard){
    //Start time for time limit
    time_t startTime = time(NULL);
    
    //Get user choice and check input
    int choice;
    printf("\n1) Input Value\n2) Undo\n3) Redo\n4) Delete\n5) Display Board\n6) Solved?\n7) Quit ");
    scanf("%d", &choice);
    writeToFile(choice);


   while (choice < 1 || choice > 7) {
        printf("Invalid: Enter another value ");
        scanf("%d", &choice);   
    }
    //Switch case to call the correct function
    switch (choice) {
        case 1:
            currentBoard = inputValue(currentBoard);
            menu(currentBoard);
            break;
        case 2:
            undo(&currentBoard);
            menu(currentBoard);
            break;
        case 3:
            redo(&currentBoard);
            break;
        case 4:
            currentBoard = delete(currentBoard);
            menu(currentBoard);
            break;
        case 5:
            displayBoard(currentBoard);
            menu(currentBoard);
            break;
        case 6:
            if(isSolved(currentBoard)){
                printf("The board has been solved!!\n");
                quit();
            }
            else{
                int userChoice;
                printf("Would you like to continue?\n1) Yes\n2) No\n");
                scanf("%d", &userChoice);
                if(userChoice == 1){
                    menu(currentBoard);
                }
                else{
                    quit();
                }
                
            }
            break;
        case 7:
            
            printf("Would you like to go to the main menu? \n1) Yes \n2) No \n");
            int menuChoice;
            scanf("%d", &menuChoice);
            if(menuChoice == 1){
                main();
            }
            else{
                quit();
            }
            break;
        default:
            printf("Invalid choice.\n");
            menu(currentBoard); // Restart the menu
    }
    // while (true) {
    //           // Check if time limit is reached
    //             if (isTimeUp(startTime)) {
    //                 printf("Time's up! Game over.\n");
    //             break;
    //             }
    // }
}

void startTimer() {
    printf("Timer started. You have %d seconds.\n", timeLimit);
}

// checking to see if the time limit is up
bool isTimeUp(time_t startTime) {
    // Get the current time
    time_t currentTime = time(NULL);
    return (currentTime - startTime >= timeLimit);
}

//initialize the timer and start the game
void initializeGame() {
    printf("Enter the time limit (in seconds): ");
    scanf("%d", &timeLimit);
    startTimer(); // Start the timer
}

int main(){
    //Initializing values
    int startChoice;
    int timeChoice;
    
    int difficultyChoice;
    struct board selectedBoard;

    //Start of the game
    printf("\n\nWelcome to my sudoku game\n\n");

    printf("Select an option - \n1) Start new game \n2) View previous game \n3) Quit\n");
    scanf("%d", &startChoice);
    char readValue;
    //Switch case for user choice
    switch(startChoice){
        //Created file pointer and started a new savegame.txt file
        FILE *file;
        case 1:
            file = fopen("savegame.txt", "w");

            //Gets user board difficulty
            printf("Pick a difficulty - \n1) Easy \n2) Medium \n3) Hard \n4) Empty Board\n");
            scanf("%d", &difficultyChoice);
            switch(difficultyChoice){
                case 1:
                    selectedBoard = easyBoard();
                break;
                case 2:
                    selectedBoard = mediumBoard();
                break;
                case 3:
                    selectedBoard = hardBoard();
                break;
                case 4:
                    selectedBoard = emptyBoard();
                break;
            }
            writeToFile(difficultyChoice);
            printf("Would you like to set a time limit?\n1) Yes\n2) No");
            scanf("%d", &timeChoice);
            if(timeChoice == 1){
            initializeGame();
              
            }
            writeToFile(timeChoice);
            
            displayBoard(selectedBoard);
            menu(selectedBoard);

            
        break;

        case 2:
            
            //Reads in file and prints the previous game
            //Ran out of time to code the load game
            file = fopen("savegame.txt", "r");
            readValue = fgetc(file);

            if (file == NULL) {
                printf("Error opening file.\n");
            }
            printf("The user input was recorded from when the new game mode was selected.\n");
            printf("The moves from the previous game were: ");
            while (readValue != EOF) {
                printf("%c", readValue);
                readValue = fgetc(file);
            }
            printf("\n");
            break;

        case 3:
            quit();
        break;
    }
}

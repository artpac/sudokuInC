//Importing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>



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

    struct board easyBoardStruct = {{3,5,0,4,0,0,8,0,0}, 
                                    {0,7,6,8,1,0,0,0,0}, 
                                    {0,0,0,0,6,0,0,0,2}, 
                                    {0,0,0,0,4,6,3,0}, 
                                    {0,0,3,5,0,0,0,0,0}, 
                                    {6,1,0,0,0,0,0,2,4}, 
                                    {5,9,1,8,4,7,6,0}, 
                                    {0,0,0,0,5,7,0,0,1}, 
                                    {0,6,4,0,9,3,2,8,5},
                                    
                                    {1,2,4,7},
                                    {2,3,4,5},
                                    {5,9},
                                    {5,6,7,8},
                                    {3,4},
                                    {1,2,8,9},
                                    {1,2,3,4,5,6,7,8},
                                    {5,6,9},
                                    {2,3,5,6,7,8,9}};

    return easyBoardStruct;
}


//Declaring menu function so it can be called before it is coded
void menu(struct board currentBoard);
void displayBoard(struct board displayCurrentBoard);
void writeToFile();


//All necessary functions
struct board inputValue(struct board currentBoard){
    int x;
    int y;
    int newValue;
    
    
    printf("Enter y coordinate \n");
    scanf("%d", &y);
    writeToFile(y);
    printf("Enter x coordinate \n");
    scanf("%d", &x);
    writeToFile(x);
    int length = sizeof(currentBoard.y1Not) / sizeof(currentBoard.y1Not[0]);
    
    printf("Enter new value \n");
    scanf("%d", &newValue);
    writeToFile(newValue);

    if(y == 1){
        
        

        // for (int i = 0; i < sizeof(currentBoard.y1Not); i++){
        //     if(x == currentBoard.y1Not[i]){
        //         printf("Cannot enter value there enter: Enter another value\n");
        //         scanf("%d", &x);
        //     }
        // }
        

        currentBoard.y1[x-1] = newValue;
    }
    else if(y == 2){
        currentBoard.y2[x-1] = newValue;
    }
    else if(y == 3){
        currentBoard.y3[x-1] = newValue;
    }
    else if(y == 4){
        currentBoard.y4[x-1] = newValue;
    }
    else if(y == 5){
        currentBoard.y5[x-1] = newValue;
    }
    else if(y == 6){
        currentBoard.y6[x-1] = newValue;
    }
    else if(y == 7){
        currentBoard.y7[x-1] = newValue;
    }
    else if(y == 8){
        currentBoard.y8[x-1] = newValue; 
    }
    else if(y == 9){
        currentBoard.y9[x-1] = newValue;
    }

    displayBoard(currentBoard);
    return currentBoard;
}
int undo(){
    printf("Undo \n");

    return 0;
}
int redo(){
    printf("Redo \n");

    return 0;
}
void delete(struct board currentBoard){
    
}
int quit(){
    printf("quit \n");
    exit(1);

}
int isSolved(){
    printf("Is the board solved");
    return 0;
}
int timeLimit(void){
    clock_t t;
    return 0;
}

void writeToFile(input){
    FILE *file;
    file = fopen("savegame.txt", "a");
    fprintf(file, "%d", input);
    fclose(file);

}
void displayBoard(struct board displayCurrentBoard){
    // char currentX[] = "xX";
    // for(int value = 0; value < 9; value++){
    //     currentX[1] = value + '0';
    // }

    printf("\n------------------------------------\n|");
    for(int i = 0; i < 9; i++){
        if(displayCurrentBoard.y1[i] == 0){
            printf("  | ");
        }
        if(displayCurrentBoard.y1[i] != 0){
            printf("%d | ", displayCurrentBoard.y1[i]);
        }

    }
    printf("\n------------------------------------\n|");

    for(int i = 0; i < 9; i++){
        if(displayCurrentBoard.y2[i] == 0){
            printf("  | ");
        }
        if(displayCurrentBoard.y2[i] != 0){
            printf("%d | ", displayCurrentBoard.y2[i]);
        }
        
    }
    printf("\n------------------------------------\n|");

    for(int i = 0; i < 9; i++){
        if(displayCurrentBoard.y3[i] == 0){
            printf("  | ");
        }
        if(displayCurrentBoard.y3[i] != 0){
            printf("%d | ", displayCurrentBoard.y3[i]);
        }

    }
    printf("\n------------------------------------\n|");

    for(int i = 0; i < 9; i++){
        if(displayCurrentBoard.y4[i] == 0){
            printf("  | ");
        }
        if(displayCurrentBoard.y4[i] != 0){
            printf("%d | ", displayCurrentBoard.y4[i]);
        }

    }
    printf("\n------------------------------------\n|");

    for(int i = 0; i < 9; i++){
        if(displayCurrentBoard.y5[i] == 0){
            printf("  | ");
        }
        if(displayCurrentBoard.y5[i] != 0){
            printf("%d | ", displayCurrentBoard.y5[i]);
        }

    }
    printf("\n------------------------------------\n|");

    for(int i = 0; i < 9; i++){
        if(displayCurrentBoard.y6[i] == 0){
            printf("  | ");
        }
        if(displayCurrentBoard.y6[i] != 0){
            printf("%d | ", displayCurrentBoard.y6[i]);
        }

    }
    printf("\n------------------------------------\n|");

    for(int i = 0; i < 9; i++){
        if(displayCurrentBoard.y7[i] == 0){
            printf("  | ");
        }
        if(displayCurrentBoard.y7[i] != 0){
            printf("%d | ", displayCurrentBoard.y7[i]);
        }

    }
    printf("\n------------------------------------\n|");

    for(int i = 0; i < 9; i++){
        if(displayCurrentBoard.y8[i] == 0){
            printf("  | ");
        }
        if(displayCurrentBoard.y8[i] != 0){
            printf("%d | ", displayCurrentBoard.y8[i]);
        }

    }
    printf("\n------------------------------------\n|");

    for(int i = 0; i < 9; i++){
        if(displayCurrentBoard.y9[i] == 0){
            printf("  | ");
        }
        if(displayCurrentBoard.y9[i] != 0){
            printf("%d | ", displayCurrentBoard.y9[i]);
        }

    }
    printf("\n------------------------------------\n|");

}


//Creating menu function
void menu(struct board currentBoard){
    int choice;
    printf("\n1) Input Value\n2) Undo\n3) Redo\n4) Delete\n5) Display Board\n6) Quit ");
    scanf("%d", &choice);
    writeToFile(choice);
    while(choice < 1 || choice > 6 ){
        printf("Invalid: Enter another value ");
        scanf("%d", &choice);   
    }
    if (choice == 1){
        currentBoard = inputValue(currentBoard);
        menu(currentBoard);
    }
    else if(choice == 2){
        undo();
    }
    else if (choice == 3){
        redo();
    }
    else if (choice == 4){
        // currentBoard = delete(currentBoard);
        menu(currentBoard);
    }
    else if(choice == 5){
        displayBoard(currentBoard);
        menu(currentBoard);
    }
    else if(choice == 6){
        quit();
    }
}



int main(){
    //Created file pointer and started a new savegame.txt file
    FILE *file;
    file = fopen("savegame.txt", "w");
    //Created board struct to chose level;
    struct board selectedBoard;
    // currentBoard = selectedBoard;

    printf("hello\n");

    selectedBoard = easyBoard();
    displayBoard(selectedBoard);
    menu(selectedBoard);

    
}
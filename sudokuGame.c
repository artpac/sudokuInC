//Importing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>



//Creating board Struct with all the array names and sizes
struct board{
    int x1[9];
    int x2[9];
    int x3[9];
    int x4[9];
    int x5[9];
    int x6[9];
    int x7[9];
    int x8[9];
    int x9[9];
};
typedef struct board Board;

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
                                    {0,6,4,0,9,3,2,8,5}};

    return easyBoardStruct;
}


//Declaring menu function so it can be called before it is coded
int menu(void);

//All necessary functions
int inputValue(void){
    printf("Enter a value \n");
    menu();
    return 0;
}
int undo(void){
    printf("Undo \n");
    menu();
    return 0;
}
int redo(void){
    printf("Redo \n");
    menu();
    return 0;
}
int delete(void){
    printf("delete \n");
    menu();
    return 0;
}
int quit(){
    printf("quit \n");
    exit(1);

}
int isSolved(void){
    printf("Is the board solved");
    return 0;
}
int timeLimit(void){
    clock_t t;
    return 0;
}

int writeToFile(input){
    FILE *file;
    file = fopen("savegame.txt", "a");
    fprintf(file, "%d", input);
    fclose(file);

    return 0;
}
int displayBoard(Board displayCurrentBoard){
    // char currentX[] = "xX";
    // for(int value = 0; value < 9; value++){
    //     currentX[1] = value + '0';
    // }
    printf("\n---------------------------------------\n|");
    printf("| ");
    for(int i = 0; i < 9; i++){
        if(displayCurrentBoard.x1[i] == 0){
            printf("  | ");
        }
        if(displayCurrentBoard.x1[i] != 0){
            printf("%d | ", displayCurrentBoard.x1[i]);
        }

    }
    printf("\n---------------------------------------\n|");

    for(int i = 0; i < 9; i++){
        if(displayCurrentBoard.x2[i] == 0){
            printf("  | ");
        }
        if(displayCurrentBoard.x2[i] != 0){
            printf("%d | ", displayCurrentBoard.x2[i]);
        }

    }
    printf("\n---------------------------------------\n|");

    for(int i = 0; i < 9; i++){
        if(displayCurrentBoard.x3[i] == 0){
            printf("  | ");
        }
        if(displayCurrentBoard.x3[i] != 0){
            printf("%d | ", displayCurrentBoard.x3[i]);
        }

    }
    printf("\n---------------------------------------\n|");

    for(int i = 0; i < 9; i++){
        if(displayCurrentBoard.x4[i] == 0){
            printf("  | ");
        }
        if(displayCurrentBoard.x4[i] != 0){
            printf("%d | ", displayCurrentBoard.x4[i]);
        }

    }
    printf("\n---------------------------------------\n|");

    for(int i = 0; i < 9; i++){
        if(displayCurrentBoard.x5[i] == 0){
            printf("  | ");
        }
        if(displayCurrentBoard.x5[i] != 0){
            printf("%d | ", displayCurrentBoard.x5[i]);
        }

    }
    printf("\n---------------------------------------\n|");

    for(int i = 0; i < 9; i++){
        if(displayCurrentBoard.x6[i] == 0){
            printf("  | ");
        }
        if(displayCurrentBoard.x6[i] != 0){
            printf("%d | ", displayCurrentBoard.x6[i]);
        }

    }
    printf("\n---------------------------------------\n|");

    for(int i = 0; i < 9; i++){
        if(displayCurrentBoard.x7[i] == 0){
            printf("  | ");
        }
        if(displayCurrentBoard.x7[i] != 0){
            printf("%d | ", displayCurrentBoard.x7[i]);
        }

    }
    printf("\n---------------------------------------\n|");

    for(int i = 0; i < 9; i++){
        if(displayCurrentBoard.x8[i] == 0){
            printf("  | ");
        }
        if(displayCurrentBoard.x8[i] != 0){
            printf("%d | ", displayCurrentBoard.x8[i]);
        }

    }
    printf("\n---------------------------------------\n|");

    for(int i = 0; i < 9; i++){
        if(displayCurrentBoard.x9[i] == 0){
            printf("  | ");
        }
        if(displayCurrentBoard.x9[i] != 0){
            printf("%d | ", displayCurrentBoard.x9[i]);
        }

    }
    printf("\n---------------------------------------\n|");
    return 0;
}


//Creating menu function
int menu(void){
    int choice;
    printf("\n1) Input Value\n2) Undo\n3) Redo\n4) Delete\n5) Quit ");
    scanf("%d", &choice);
    writeToFile(choice);
    while(choice < 1 || choice > 5 ){
        printf("Invalid: Enter another value ");
        scanf("%d", &choice);   
    }
    if (choice == 1){
        inputValue();
    }
    else if(choice == 2){
        undo();
    }
    else if (choice == 3){
        redo();
    }
    else if (choice == 4){
        delete();
    }
    else if(choice == 5){
        quit();
    }
    return 0;
}



int main(void){
    //Created file pointer and started a new savegame.txt file
    FILE *file;
    file = fopen("savegame.txt", "w");
    //Created board struct to chose level;
    struct board selectedBoard;


    printf("hello\n");
    int functionCall;
    printf("Enter your choice");
    scanf("%d", &functionCall);
    writeToFile(functionCall);
    printf("You entered %d \n", functionCall);

    if(functionCall == 1){
        menu();
    }
    if(functionCall == 2){
        selectedBoard = easyBoard();
    }
    displayBoard(selectedBoard);

    
}
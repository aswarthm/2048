#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROWS 4
#define COLUMNS 4

int A[ROWS][COLUMNS];
int score = 0;

void show(int A[ROWS][COLUMNS]){
    printf("//////////////////////////\n");
    for (int i=0; i<ROWS; i++){
        for (int j=0; j<COLUMNS; j++){
            if(A[i][j]==-1)
                printf("  \t",A[i][j]);
            else
                printf("%d\t",A[i][j]);
        }
        printf("\n");     
    }
    printf("//////////////////////////\n");
}

void shift_up(int A[ROWS][COLUMNS], int i, int j){
    for(i; i<ROWS-1; i++){
        A[i][j] = A[i+1][j];
    }
    A[ROWS-1][j] = -1;
}

void shift_down(int A[ROWS][COLUMNS], int i, int j){
    for(i; i>0; i--){
        A[i][j] = A[i-1][j];
    }
    A[0][j] = -1;
}

void shift_left(int A[ROWS][COLUMNS], int i, int j){
    for(j; j<COLUMNS-1; j++){
        A[i][j] = A[i][j+1];
    }
    A[i][COLUMNS-1] = -1;

}

void shift_right(int A[ROWS][COLUMNS], int i, int j){
    for(j; j>0; j--){
        A[i][j] = A[i][j-1];
    }
    A[i][0] = -1;
}

int up(int A[ROWS][COLUMNS]){
    int flag = 0;
    for (int j=0;j<COLUMNS;j++){
        int count =0;
        int i =0;
        while(count<ROWS && i<ROWS-1){
            if (A[i][j] == -1){
                shift_up(A, i, j);
                count++;

                for (int k=i; k<=ROWS-1; k++){
                    if (A[k][j] != -1)
                        flag = 1;
                }
            }
            else{
                if (A[i+1][j] == -1){
                    shift_up(A,i+1,j);
                    count++;

                    for (int k=i+1; k<=ROWS-1; k++){
                        if (A[k][j] != -1)
                            flag = 1;
                    }
                }

                else if (A[i][j] != A[i+1][j]){
                    i++;
                }

                else {
                    A[i][j] = 2*A[i][j];
                    score += A[i][j];
                    A[i+1][j] = -1;
                    i++;
                    flag = 1;
                    

                }
            }
        }
    }
    return flag;
}

int down(int A[ROWS][COLUMNS]){
    int flag = 0;
    for (int j=0;j<COLUMNS;j++){
        int count =0;
        int i =ROWS-1;
        while(count<ROWS && i>0){       
            if (A[i][j] == -1){
                shift_down(A, i, j);  
                count++;

                for(int k = i-1; k>=0; k--){
                    if(A[k][j] != -1)
                        flag = 1;
                }

            }
            else{
                if (A[i-1][j] == -1){
                    shift_down(A,i-1,j);
                    count++;

                    for(int k=i-2;k>=0;k--){
                        if (A[k][j] != -1)
                            flag=1;
                    }
                }

                else if (A[i][j] != A[i-1][j]){
                    i--;                            
                }

                else {
                    A[i][j] = 2*A[i][j];
                    score += A[i][j];
                    A[i-1][j] = -1;
                    i--;
                    flag = 1;
                    

                }
            }
        }
    }
    return flag;
}

int left(int A[ROWS][COLUMNS]){
    int flag = 0;
    for (int i=0;i<ROWS;i++){
        int count =0;
        int j =0;
        while(count<COLUMNS && j<COLUMNS-1){       
            if (A[i][j] == -1){
                shift_left(A, i, j);
                count++;

                for (int k=j; k<=COLUMNS-1; k++){
                    if (A[i][k] != -1)          
                        flag = 1;
                }

            }
            else{
                if (A[i][j+1] == -1){
                    shift_left(A,i,j+1);
                    count++;

                    for (int k=j+1; k<=COLUMNS-1; k++){        
                        if (A[i][k] != -1)          
                            flag = 1;
                    }

                }

                else if (A[i][j] != A[i][j+1]){
                    j++;
                }

                else {
                    A[i][j] = 2*A[i][j];
                    score += A[i][j];
                    A[i][j+1] = -1;
                    j++;
                    flag = 1;
                    

                }
            }
        }
    }
    return flag;
}

int right(int A[ROWS][COLUMNS]){
    int flag = 0;
    for (int i=0;i<ROWS;i++){
        int count =0;
        int j =COLUMNS-1;
        while(count<COLUMNS && j>0){       
            if (A[i][j] == -1){
                shift_right(A, i, j);  
                count++;

                for(int k = j-1; k>=0; k--){
                    if(A[i][k] != -1)
                        flag = 1;
                }

            }
            else{
                if (A[i][j-1] == -1){
                    shift_right(A,i,j-1);//////
                    count++;

                    for(int k = j-2; k>=0; k--){
                        if(A[i][k] != -1)
                            flag = 1;     
                    }
                }

                else if (A[i][j] != A[i][j-1]){
                    j--;                            
                }

                else {
                    A[i][j] = 2*A[i][j];
                    score += A[i][j];
                    A[i][j-1] = -1;
                    j--;
                    flag=1;  
                }
            }
        }
    }
    return flag;
}

void randomSquare(int A[ROWS][COLUMNS]){
    while(1){
        for (int i=0; i<ROWS; i++){
            for (int j=0; j<COLUMNS; j++){
                if(A[i][j] == -1 && rand()%2*ROWS*COLUMNS ==0){
                    A[i][j] = rand()%10==0?4:2;                
                    return;
                }
            }
        }

    }
}

int isGameOver(int A[ROWS][COLUMNS]){
    int dontChangeScore = score;
    int B[ROWS][COLUMNS];
    for (int i=0;i<ROWS;i++){
        for(int j=0;j<COLUMNS;j++){
            B[i][j] = A[i][j];
        }
    }

    int tempVar = !(up(B) || down(B) || left(B) || right(B));
    score = dontChangeScore; 
    return tempVar;
}

int reset(){
    for(int i=0;i<ROWS;i++){
        for (int j=0; j<COLUMNS; j++){
            A[i][j] = -1;
        }
    }
    score =0;
}

void artsy(){
        printf(
" _____  _____    ___  _____ \n"
"/ __  \\|  _  |  /   ||  _  |\n"
"`' / /'| |/' | / /| | \\ V / \n"
"  / /  |  /| |/ /_| | / _ \\ \n"
"./ /___\\ |_/ /\\___  || |_| |\n"
"\\_____/ \\___/     |_/\\_____/\n");
printf("Made by shishiraiyar\n");
printf("Use wasd to play\n");
                                                       
}

void initialise(){
    for (int i=0; i<ROWS; i++){
        for (int j=0; j<COLUMNS;j++){
            A[i][j] = -1;
        }
    }
    randomSquare(A);
    randomSquare(A);
}

int main(){
    artsy();
    srand(time(0));                
    initialise();
    char c = 'z';
    char play = 'y';
    while(c != 'e'){                 
        show(A);
        if(isGameOver(A)){
            printf("***GAME OVER***\n");
            printf("Your score: %d\n",score);
            return 0;
        }
        
        printf("Current score: %d\n",score);
        printf("Make a move: ");
        scanf(" %c",&c);     

        switch (c)
        {
        case 'w':
            if(up(A)){
                randomSquare(A);
            }
            break;
        
        case 'a':
            if (left(A)){
                randomSquare(A);
            }
            break;

        case 's':
            if (down(A)){
                randomSquare(A);
            }
            break;

        case 'd':
            if(right(A)){
                randomSquare(A);
            }
            break;
        }
    }
}
//COMPILE WITH C99

#include<stdio.h>

int A[4][4] = {-1,-1,2,16, -1,-1,2,-1, 2,2,2,2, 8,2,2,2};
void show(int A[4][4]){
    for (int i=0; i<4; i++){
        for (int j=0; j<4; j++){
            printf("%d\t",A[i][j]);
        }
        printf("\n");     
    }
    printf("///////////////////////\n");
}

void shift_up(int A[4][4], int i, int j){
    for(i; i<4-1; i++){
        A[i][j] = A[i+1][j];
    }
    A[3][j] = -1;
}

void shift_left(int A[4][4], int i, int j){
    for(j; j<4-1; j++){
        A[i][j] = A[i][j+1];
    }
    A[i][3] = -1;

}


void up(int A[4][4]){
    for (int j=0;j<4;j++){
        int count =0;
        int i =0;
        while(count<4 && i<3){       
            if (A[i][j] == -1){
                shift_up(A, i, j);
                count++;
            }
            else{
                if (A[i+1][j] == -1){
                    shift_up(A,i+1,j);
                    count++;
                }

                else if (A[i][j] != A[i+1][j]){
                    i++;
                }

                else {
                    A[i][j] = 2*A[i][j];
                    A[i+1][j] = -1;
                    i++;

                }
            }
        }
    }
}

void left(int A[4][4]){
    for (int i=0;i<4;i++){
        int count =0;
        int j =0;
        while(count<4 && j<3){       
            if (A[i][j] == -1){
                shift_left(A, i, j);
                count++;
            }
            else{
                if (A[i][j+1] == -1){
                    shift_left(A,i,j+1);
                    count++;
                }

                else if (A[i][j] != A[i][j+1]){
                    j++;
                }

                else {
                    A[i][j] = 2*A[i][j];
                    A[i][j+1] = -1;
                    j++;

                }
            }
        }
    }
}

int main(){
    char c = 'z';
    show(A);
    while(c!='e'){
        printf("Make a move \n");
        scanf("%c",&c);
        
        switch (c)
        {
        case 'w':
            up(A);
            break;
        
        case 'a':
            left(A);
            break;
        
        default:
            printf("lol\n");
            break;
        }
        
        show(A);

    }
}

/*
For each column;
check if -1; shift up only everything below. else if num check whats below it. If -1 shi.        ; if last row terminate.

while count<4(maybe take more just in case)
    if -1 shift up. count++ ; else check below. 
        if unequal. i++
        if equal. this = double. below = -1. i++(to prevent adding again. not alowd to touch it again)

        if -1. shift up for below. keep i same.    (also maybe count++)
        


 ;i++; while -1 shift up;   terminate if last row.  [count shift ups and focus downs. if 4. terminate]



in one of the columns put random[2 or 4 (weighted)] in any of the -1 spots.
*/


//why is it printing twice
//DOWN and RIGHT functions
//REPLACE RANDOM -1 with num

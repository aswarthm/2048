//COMPILE WITH C99

#include<stdio.h>
#include<stdlib.h>

//int A[4][4] = {-1,-1,2,16, -1,-1,2,-1, 2,2,2,2, 8,2,2,2};
int A[4][4] = {2,2,2,2, 8,2,2,2, -1,-1,2,16, -1,-1,2,-1};

void show(int A[4][4]){
    for (int i=0; i<4; i++){
        for (int j=0; j<4; j++){
            if(A[i][j]==-1)
                printf("  \t",A[i][j]);
            else
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

void shift_down(int A[4][4], int i, int j){
    for(i; i>0; i--){
        A[i][j] = A[i-1][j];
    }
    A[0][j] = -1;
}

void shift_left(int A[4][4], int i, int j){
    for(j; j<4-1; j++){
        A[i][j] = A[i][j+1];
    }
    A[i][3] = -1;

}

void shift_right(int A[4][4], int i, int j){
    for(j; j>0; j--){
        A[i][j] = A[i][j-1];
    }
    A[i][0] = -1;
}

int up(int A[4][4]){
    int flag = 0;
    for (int j=0;j<4;j++){
        int count =0;
        int i =0;
        while(count<4 && i<3){       //maybe i<2 actually. coz shiftup(2+1) is called. and shift up also does +1. so it tries to access A[4]
            if (A[i][j] == -1){
                shift_up(A, i, j);
                count++;

                for (int k=i; k<=3; k++){        //Checks if its all -1 below this -1. If so shift up is not considered a move.
                    if (A[k][j] != -1)          //Ensures there's atleast one non -1 below
                        flag = 1;
                }
            }
            else{
                if (A[i+1][j] == -1){
                    shift_up(A,i+1,j);
                    count++;

                    for (int k=i+1; k<=3; k++){        //Checks if its all -1 below this -1. If so shift up is not considered a move.
                        if (A[k][j] != -1)            //Ensures there's atleast one non -1 below
                            flag = 1;
                    }
                }

                else if (A[i][j] != A[i+1][j]){
                    i++;
                }

                else {
                    A[i][j] = 2*A[i][j];
                    A[i+1][j] = -1;
                    i++;
                    flag = 1;

                }
            }
        }
    }
    return flag;
}

int down(int A[4][4]){
    int flag = 0;
    for (int j=0;j<4;j++){
        int count =0;
        int i =3;
        while(count<4 && i>0){       
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
                    shift_down(A,i-1,j);//////
                    count++;

                    for(int k=i-2;k>=0;k--){
                        if (A[k][j] != -1)
                            flag=1;
                    }
                }

                else if (A[i][j] != A[i-1][j]){
                    i--;                            /////
                }

                else {
                    A[i][j] = 2*A[i][j];
                    A[i-1][j] = -1;
                    i--;
                    flag = 1;

                }
            }
        }
    }
    return flag;
}

int left(int A[4][4]){
    int flag = 0;
    for (int i=0;i<4;i++){
        int count =0;
        int j =0;
        while(count<4 && j<3){       
            if (A[i][j] == -1){
                shift_left(A, i, j);
                count++;

                for (int k=j; k<=3; k++){        //Checks if its all -1 to the right of this -1. If so shift left is not considered a move.
                    if (A[i][k] != -1)          //Ensures there's atleast one non -1 to the right.
                        flag = 1;
                }

            }
            else{
                if (A[i][j+1] == -1){
                    shift_left(A,i,j+1);
                    count++;

                    for (int k=j+1; k<=3; k++){        //Checks if its all -1 to the right of this -1. If so shift left is not considered a move.
                        if (A[i][k] != -1)          //Ensures there's atleast one non -1 to the right.
                            flag = 1;
                    }

                }

                else if (A[i][j] != A[i][j+1]){
                    j++;
                }

                else {
                    A[i][j] = 2*A[i][j];
                    A[i][j+1] = -1;
                    j++;
                    flag = 1;

                }
            }
        }
    }
    return flag;
}

int right(int A[4][4]){
    int flag = 0;
    for (int i=0;i<4;i++){
        int count =0;
        int j =3;
        while(count<4 && j>0){       
            if (A[i][j] == -1){
                shift_right(A, i, j);  ////
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
                    j--;                            /////
                }

                else {
                    A[i][j] = 2*A[i][j];
                    A[i][j-1] = -1;
                    j--;
                    flag=1;
                }
            }
        }
    }
    return flag;
}

void randomSquare(int A[4][4]){
    int place = 1;
    while(place){
        for (int i=0; i<4; i++){
            for (int j=0; j<4; j++){
                if(A[i][j] == -1 && rand()%16 ==0){
                    A[i][j] = rand()%10==0?4:2;  
                    place = 0;
                }
            }
        }

    }
}

int main(){
    char c = 'z';
    // printf("kkk");
    while(c != 'e'){                   //e for exit
        show(A);
        printf("Make a move \n");

        //for(int k=0; k<100000;k++){}
        scanf(" %c",&c);     //without empty space scanf takes \n as input. No idea why. no idea where it comes from. dangling \n

        //printf("ascii = %d\n",c);

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
        
        // default:
        //     printf("lol\n");
        }


    }
}
//// BIG ISSUE WITH CODE> DONT ADD RANDOM IF MOVE DOESNT CHANGE ANYTHING. DUM DUM  FIXED IT IG

// RANDOM INITIALISE

// MAKE -1 appear as 0 by changing show function

// IS GAME OVER FUNCTION



/*
For each column;

while count<4(maybe take more just in case)
    if -1 shift up. count++ ; else check below. 
        if unequal. i++
        if equal. this = double. below = -1. i++(to prevent adding again. not alowd to touch it again)

        if -1. shift up for below. keep i same.    (also maybe count++)
        



in one of the columns put random[2 or 4 (weighted)] in any of the -1 spots.
*/


//why is it printing twice
//DOWN and RIGHT functions
//REPLACE RANDOM -1 with num



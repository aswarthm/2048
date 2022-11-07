//COMPILE WITH C99

#include<stdio.h>

//int A[4][4] = {-1,-1,2,16, -1,-1,2,-1, 2,2,2,2, 8,2,2,2};
int A[4][4] = {2,2,2,2, 8,2,2,2, -1,-1,2,16, -1,-1,2,-1};

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

void up(int A[4][4]){
    for (int j=0;j<4;j++){
        int count =0;
        int i =0;
        while(count<4 && i<3){       //maybe i<2 actually. coz shiftup(2+1) is called. and shift up also does +1. so it tries to access A[4]
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

void down(int A[4][4]){
    for (int j=0;j<4;j++){
        int count =0;
        int i =3;
        while(count<4 && i>0){       
            if (A[i][j] == -1){
                shift_down(A, i, j);  ////
                count++;
            }
            else{
                if (A[i-1][j] == -1){
                    shift_down(A,i-1,j);//////
                    count++;
                }

                else if (A[i][j] != A[i-1][j]){
                    i--;                            /////
                }

                else {
                    A[i][j] = 2*A[i][j];
                    A[i-1][j] = -1;
                    i--;

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

void right(int A[4][4]){
    for (int i=0;i<4;i++){
        int count =0;
        int j =3;
        while(count<4 && j>0){       
            if (A[i][j] == -1){
                shift_right(A, i, j);  ////
                count++;
            }
            else{
                if (A[i][j-1] == -1){
                    shift_right(A,i,j-1);//////
                    count++;
                }

                else if (A[i][j] != A[i][j-1]){
                    j--;                            /////
                }

                else {
                    A[i][j] = 2*A[i][j];
                    A[i][j-1] = -1;
                    j--;

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
        scanf("\n%c",&c);     //without \n scanf takes \n as input. No idea why. no idea where it comes from. 

        printf("kek = %d\n",c);


        switch (c)
        {
        case 'w':
            up(A);
            break;
        
        case 'a':
            left(A);
            break;

        case 's':
            down(A);
            break;

        case 'd':
            right(A);
            break;
        
        // default:
        //     printf("lol\n");
        }

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


/* WHY DOESNT THIS WORK??
switch (c)
        {
        case 'w':
            up(A);
            break;
        
        case 'a':
            left(A);
            break;

        case 's':
            down(A);
            break;

        case 'd':
            right(A);
            break;
        
        default:
            printf("lol\n");
        }


   if(c == 'w')
        up(A);

        if(c == 'a')
        left(A);

        if(c == 's')
        down(A);

        if(c == 'd')
        right(A);
        
        show(A);
        
*/
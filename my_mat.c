#include <stdio.h>
#include <stdbool.h>
#include "my_mat.h"
#define SIZE 10
#define INF 99999


/* Function creates matrix 10X10,
   The user chooses the values */
void createMat(int mat[SIZE][SIZE]) {
    int i,j;
    for(i=0;i<SIZE;i++) {
        for(j=0;j<SIZE;j++) {
            scanf("%d",&mat[i][j]);
        }
    }
}


/* Function gets junction from the matrix,
   And checks if there is a route for it */
int ifExistRoute(int line,int col,int mat[SIZE][SIZE]) {
    if(mat[line][col]!=0)
        return 1;
    else {
        int arr[SIZE];
        int i, j, k, count=0, index;

        for ( i = 0; i < SIZE; i++) {
            arr[i]=INF;
        }


        for(i=0;i<SIZE;i++) {
            if(mat[line][i]!=0){
                arr[count]=i;
                index=count;
                count++;
            }
        }


        int counthowmuch=0;
        for(i=0;(i<SIZE)&&(arr[i]!=INF);i++){
            for(j=0;j<SIZE;j++){
                if(mat[arr[i]][j]!=0){
                    for(k=0;k<SIZE;k++){
                        if(arr[k]!=j&&arr[k]!=INF)
                            counthowmuch++;
                    }
                    if(counthowmuch==count){
                        count++;
                        index++;
                        arr[index]=j;
                    } 
                }
                counthowmuch=0;
            }
        }
        
        for(i=0;i<SIZE;i++){
            if(arr[i]==col)
                return 1;
        }
        return 0;
        
    }
    
} 

/* function gets junction and matrix,
    Returns the shortest way to the junction*/
int bringTheShortestRoute(int line,int col,int mat[SIZE][SIZE]){
    if(ifExistRoute(line,col,mat)==1){
        int helpmat[SIZE][SIZE];
        int i,j,k;

       for(i=0;i<SIZE;i++)
            for(j=0;j<SIZE;j++)
                helpmat[i][j]=mat[i][j];
        
        for(i=0;i<SIZE;i++){
            for(j=0;j<SIZE;j++){
                if(helpmat[i][j]==0)
                    helpmat[i][j]=INF;
            }
        }

        for(i=0;i<SIZE;i++)
            helpmat[i][i]=0;      

        for(k=0;k<SIZE;k++){
            for(i=0;i<SIZE;i++){
                for(j=0;j<SIZE;j++){
                    if(helpmat[i][k]+helpmat[k][j]<helpmat[i][j])
                        helpmat[i][j] = helpmat[i][k]+helpmat[k][j];
                }
            }
        }
        
        return helpmat[line][col];
    }
    else
        return -1;
}
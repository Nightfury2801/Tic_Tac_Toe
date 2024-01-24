#include <stdio.h>
#define N 3

int check(int x[][N]){
    int row,column,d1=0,d2=0;
    for(int i=0;i<3;i++){
        row=0;
        column=0;
        for(int j=0;j<3;j++){
            row+=x[i][j];
            column+=x[j][i];

        }
        d1+=x[i][i];
        d2+=x[i][2-i];
        if(row==3||column==3){
            printf("Player 2 wins.");
            return 0;
        }
        else if(column==0||row==0){
            printf("Player 1 wins.");
            return 0;
        }
    }
    if(d1==3||d2==3){
        printf("Player 2 wins.");
        return 0;
    }
    else if(d1==0||d2==0){
        printf("Player 1 wins.");
        return 0;
    }
    return 1;   
}

void print_arry(int arr[][3]){
    // printf("\n-------------\n");
    for(int i=0;i<3;i++){
        if(i==1)
            printf("|");
        for(int j=0;j<3;j++){
            if(i==1){
                if (arr[i][j]==1)
                    printf(" X |");
                else if (arr[i][j]==0)
                    printf(" O |");
                else
                    printf("   |");
            }
            // else{
            //     if(j==2)
            // }
        }
        if(i!=2)
            printf("\n-------------\n");
    }
}

void print_array(int arr[][3]){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(j!=2){
                if (arr[i][j]==1)
                    printf(" X |");
                else if (arr[i][j]==0)
                    printf(" O |");
                else
                    printf("   |");
            }
            else{
                if (arr[i][j]==1)
                    printf(" X ");
                else if (arr[i][j]==0)
                    printf(" O ");
                else
                    printf("   ");
            }
        }
        if(i!=2)
            printf("\n-----------\n");
    }
}

int main(){
    int game[][3]={{5,5,5},{5,5,5},{5,5,5}};
    //x=1 o=0
    int result=1,count=0;

    while(result&&(count<9)){
        int i=0,j=0;
        print_array(game);
        if(count&1){
            printf("\nPlayer 2 play: ");
            scanf("%d %d",&i,&j);
            if(game[i][j]!=5){
                printf("Already entered. Try Again!\n");
                continue;
            }
            game[i][j]=1;
        }
        else{
            printf("\nPlayer 1 play: ");
            scanf("%d %d",&i,&j);
            if(game[i][j]!=5){
                printf("Already entered. Try Again!\n");
                continue;
            }
            game[i][j]=0;
        }
        result=check(game);
        count+=1;

    }
    if(count==9&&result==1){
        print_array(game);
        printf("Draw!");
    }
    return 0;
}
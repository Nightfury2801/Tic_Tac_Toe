#include <stdio.h>
#define N 3

int check_3(int z[][N]){
    int row,column,d1=0,d2=0;
    for(int i=0;i<3;i++){
        row=0;
        column=0;
        for(int j=0;j<3;j++){
            row+=z[i][j];
            column+=z[j][i];

        }
        if(row==7){
            for(int j=0;j<3;j++){
                if(z[i][j]==5){
                    z[i][j]=0;
                    return 1;
                }
            }
        }
        else if(row==5){
            for(int j=0;j<3;j++){
                if(z[i][j]==5){
                    z[i][j]=0;
                    return 1;
                }
            }
        }
        else if(column==7){
            for(int j=0;j<3;j++){
                if(z[j][i]==5){
                    z[j][i]=0;
                    return 1;
                }
            }
        }
        else if(column==5){
            for(int j=0;j<3;j++){
                if(z[j][i]==5){
                    z[j][i]=0;
                    return 1;
                }
            }
        }
        d1+=z[i][i];
        d2+=z[i][2-i];
    }
    if(d1==7||d1==5){
        for(int i=0;i<3;i++){
            if(z[i][i]==5){
                z[i][i]=0;
                return 1;
            }
        }
    }
    else
    return 0;
    if(d2==7||d2==5){
        for(int i=0;i<3;i++){
            if(z[i][2-i]==5){
                z[i][2-i]=0;
                return 1;
            }
        }

    }
    else
    return 0;
}

void comp_play(int y[][N]){
    if(check_3(y)){
        return ;
    }
    else{
        if(y[1][1]==5){
            y[1][1]=0;
            return ;
        }
        else{
            for(int i=0;i<=2;i+=2){
                for(int j=0;j<=2;j+=2){
                    if(y[i][j]==5){
                        y[i][j]=0;
                        return ;
                    }
                }
            }
        }
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(y[i][j]==5){
                    y[i][j]=0;
                    return ;
                }
            }
        }
    }
}

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
            printf("Player 1 wins.");
            return 0;
        }
        else if(column==0||row==0){
            printf("Computer wins.");
            return 0;
        }
    }
    if(d1==3||d2==3){
        printf("Player 1 Wins.");
        return 0;
    }
    else if(d1==0||d2==0){
        printf("Computer wins");
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
            comp_play(game);
            printf("\nComputer played!\n");
        }
        else{
            printf("\nPlayer 1 play: ");
            scanf("%d %d",&i,&j);
            if(game[i][j]!=5){
                printf("Already entered. Try Again!\n");
                continue;
            }
            game[i][j]=1;
        }
        result=check(game);
        count+=1;

    }
    if(count==9&&result==1){
        print_array(game);
        printf("/nDraw!");
    }
    return 0;
}
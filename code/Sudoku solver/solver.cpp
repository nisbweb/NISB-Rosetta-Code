#include<iostream>
#include<process.h>
using namespace std;

int ques[9][9]={
    {0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,9,0,0,0},
    {0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0}
};

int nearest(int n){
    if(n>=0 && n<=2)
        return 0;
    else if(n>=3 && n<=5){
        return 3;
    }
    else{
        return 6;
    }
}

int nearPair(int n){
    if(n>=0 && n<=2)
        return 2;
    else if(n>=3 && n<=5){
        return 5;
    }
    else{
        return 8;
    }
}

void display(){
int i,j;
    for(i=0;i<9;i++){
        for(j=0;j<9;j++){
        	if(j==3 || j==6)
            cout<<" "<<ques[i][j]<<" ";
            else
            cout<<ques[i][j]<<" ";
        }
        if(i==2 || i==5)
        cout<<endl<<endl;
        else
        cout<<endl;
    }
}


bool isPossible(int x,int y, int n){
    int i,j;
    for(i=0;i<9;i++){
        if(ques[x][i]==n){
            return false;
        }
        if(ques[i][y]==n){
            return false;
        }
    }
    for(i=nearest(x);i<=nearPair(x);i++){
        for(j=nearest(y);j<=nearPair(y);j++){
            if(ques[i][j]==n)
                return false;
        }
        cout<<endl;
    }
    return true;
}




bool solver(){
    int i,j,k;
    for(i=0;i<9;i++){
        for(j=0;j<9;j++){
            if(ques[i][j]==0){
                for(k=1;k<10;k++){
                    if(isPossible(i,j,k)){
                        display();
                        system("pause");
                        system('cls');
                        ques[i][j]=k;
                        if(solver()){
                        	return true;
						}
						ques[i][j]=0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}

int main(){

    solver();
    display();
}

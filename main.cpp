#include <iostream>
#include<vector>
#include<cmath>
#include<algorithm>


using namespace std;
int scount=0;
int printsud(vector<vector<int>> mat){
    cout<<"\n";
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
int checksud(vector<vector<int>> mat ){

    vector<int> a(10,0);
    for(int i=0;i<9;i++){
        a={0,0,0,0,0,0,0,0,0,0};
        for(int j=0;j<9;j++){
            a[mat[i][j]]+=1;
        }
        if(*max_element(next(a.begin()),a.end())>1)//check row for repetition not including first index as 0 represents not filled
            return 1;
        a={0,0,0,0,0,0,0,0,0,0};
        for(int j=0;j<9;j++){
            a[mat[j][i]]+=1;
        }
        if(*max_element(next(a.begin()),a.end())>1)//check column
            return 2;
        a={0,0,0,0,0,0,0,0,0,0};
        for(int j=0;j<9;j++){
            a[mat[3*(i/3)+j/3][3*(i%3)+j%3]]+=1;
        }
        if(*max_element(next(a.begin()),a.end())>1)//check box
            return 3;
    }
    return 0;
}
int fillsud(vector<vector<int>> mat,int ix,int jx){
    if(checksud(mat)!=0){
        return 0;
    }
    int c=0;
    for(int i=ix;i<9;i++){
        for(int j=0;j<9;j++){
            if(mat[i][j]==0){
                c=1;//check it was not full
/*
                vector<int> b={1,2,3,4,5,6,7,8,9};
                vector<int> b2= {mat[i][0], mat[i][1], mat[i][2], mat[i][3], mat[i][4], mat[i][5], mat[i][6], mat[i][7], mat[i][8],mat[0][j], mat[1][j], mat[2][j], mat[3][j], mat[4][j], mat[5][j], mat[6][j], mat[7][j],mat[8][j]};
                if(i==1) {
                    if (j == 1) {

                        b2.push_back(mat[2][2]);
                    } else if (j == 8) {
                        b2.push_back(mat[2][7]);
                    } else {
                        b2.push_back(mat[2][j - 1]);

                        b2.push_back(mat[2][j + 1]);
                    }
                }
                    else if(i==8){
                    if (j == 1) {

                        b2.push_back(mat[6][2]);
                    } else if (j == 8) {
                        b2.push_back(mat[6][7]);
                    } else {
                        b2.push_back(mat[6][j - 1]);

                        b2.push_back(mat[6][j + 1]);
                    }

                }
                    else{
                if (j == 1) {

                    b2.push_back(mat[2][2]);
                } else if(j == 8) {
                    b2.push_back(mat[2][7]);
                } else {
                    b2.push_back(mat[i-1][j - 1]);

                    b2.push_back(mat[i-1][j + 1]);
                    b2.push_back(mat[i+1][j - 1]);
                    b2.push_back(mat[i+1][j + 1]);

                }
                    }
                    vector<int>::iterator ip;
                ip = std::unique(b2.begin(), b2.end());
                b2.resize(std::distance(b2.begin(), ip));
                for(int x: b2){
                    b.erase(remove(b.begin(),b.end(),x),b.end());
                }*/
                int i2=i,j2=j;
                if(j==8){
                    i2=i+1;
                    j2=0;
                }
                mat[i][j]=1;
                c+=fillsud(mat,i2,j2);
                mat[i][j]=2;
                c+=fillsud(mat,i2,j2);
                mat[i][j]=3;
                c+=fillsud(mat,i2,j2);
                mat[i][j]=4;
                c+=fillsud(mat,i2,j2);
                mat[i][j]=5;
                c+=fillsud(mat,i2,j2);
                mat[i][j]=6;
                c+=fillsud(mat,i2,j2);
                mat[i][j]=7;
                c+=fillsud(mat,i2,j2);
                mat[i][j]=8;
                c+=fillsud(mat,i2,j2);
                mat[i][j]=9;
                c+=fillsud(mat,i2,j2);

            }
        }
    }
    //cout<<c;
    if(c==0) {
        printsud(mat);
        scount += 1;
    }
    return 0;
}
int main(){


    cout<<"\nEnter numbers in squares in this format row\ncolumn\nnumber\nRow and column indices start at 1. \n Enter one value at a time\n Enter 10 to stop\n";
    vector<vector<int>> mat(9,vector<int>(9,0));
    int r,c,v;
    do{
        cin>>r;
        if(r==10)
            continue;
        cin>>c;
        if(c==10)
            continue;
        cin>>v;

        //cout<<r<<","<<c<<","<<v<<"\nIs this correct 0-wrong 1-correct";
        //cin>>cnfm;
        //if(cnfm)
        mat[r-1][c-1]=v;
        printsud(mat);
        cout<<"\n If you see a mistake just rewrite the value to 0\n";
    }while(r!=10&&c!=10&&v!=10);
    printsud(mat);
    if(checksud(mat)!=0){
        cout<<"No arrangement possible for this arrangement there is an error in question";
        cout<<checksud(mat);
        return 1;
    };
    fillsud(mat,0,0);

    //cout<<"\n"<<scount<<" arrangements possible";//division by 8 required due to recursion
    scount=0;//made zero in case continued
    return 0;
}


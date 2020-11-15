//
//  main.cpp
//  1
//
//  Created by 胡开域 on 2020/11/15.
//  Copyright © 2020 胡开域. All rights reserved.
//

#include <iostream>
struct Matrix{
    int row;
    int column;
};
using namespace std;
int main(int argc, const char * argv[]) {
    Matrix A;
    Matrix B;
    Matrix C;
    
    //enter the row number and column
    cout<<"enter the number of row of the first matrix"<<endl;
    cin>>A.row;
    cout<<"enter the number of column of the first matrix"<<endl;
    cin>>A.column;
    cout<<"enter the number of row of the second matrix"<<endl;
    cin>>B.row;
    if(B.row!=A.column){
        cout<<"illegal input"<<endl;
        exit(0);
    }
    cout<<"enter the number of column of the second matrix"<<endl;
    cin>>B.column;
    
    //enter the matrix
    float a[A.row][A.column];
    float b[B.row][B.column];
    float c[A.row][B.column];
    cout<<"enter the first matirx"<<endl;
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            cin>>a[i][j];
            if(cin.fail())
            {
            cout<<"illegal input"<<endl;
            exit(0);
            }
        }
    }
    cout<<"enter the second matirx"<<endl;
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            cin>>b[i][j];
            if(cin.fail())
            {
            cout<<"illegal input"<<endl;
            exit(0);
            }
        }
    }
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            cin>>b[i][j];
            
        }
    }
    //calculate
    for(int m=0;m<A.row;m++){
        for(int s=0;s<B.column;s++){
            c[m][s]=0;
            for(int n=0;n<A.column;n++){
                c[m][s]+=a[m][n]*b[n][s];
            }
        }
    }
    
    //print the result
    for(int m=0;m<A.row;m++){
        for(int s=0;s<B.column;s++){
            cout<<c[m][s]<<"\t";
        }
        cout<<endl;
    }

}

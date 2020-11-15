//
//  main.cpp
//  super-matrix-calculator
//
//  Created by 胡开域 on 2020/11/14.
//  Copyright © 2020 胡开域. All rights reserved.
//
#include <iostream>
#include<chrono>
using namespace std;
int main() {
    int N = 10000;
    
    float **A = new float*[N];
    for(int i=0; i<N; i++){
        A[i]=new float[N];
    }
    
    float **B = new float*[N];
    for(int i=0; i<N; i++){
        B[i]=new float[N];
    }
    
    float **C = new float*[N];
    for(int i=0; i<N; i++){
        C[i]=new float[N];
    }
    
    srand(time(0));
    for(int i=0; i<N; i++){
        for(int i1=0 ;i1<N; i1++){
            A[i][i1]=rand()%100;
        }
    }
    for(int i=0; i<N; i++){
        for(int i1=0 ;i1<N; i1++){
            B[i][i1]=rand()%100;
        }
    }
    
    chrono::steady_clock::time_point time_start=chrono::steady_clock::now();
    for (int m = 0; m < N; m += 4) {
      for (int n = 0; n < N; n += 4) {
        C[m + 0][n + 0] = 0; C[m + 0][n + 1] = 0; C[m + 0][n + 2] = 0; C[m + 0][n + 3] = 0;
        C[m + 1][n + 0] = 0; C[m + 1][n + 1] = 0; C[m + 1][n + 2] = 0; C[m + 1][n + 3] = 0;
        C[m + 2][n + 0] = 0; C[m + 2][n + 1] = 0; C[m + 2][n + 2] = 0; C[m + 2][n + 3] = 0;
        C[m + 3][n + 0] = 0; C[m + 3][n + 1] = 0; C[m + 3][n + 2] = 0; C[m + 3][n + 3] = 0;
        for (int k = 0; k < N; k += 4) {
          //k+0
          float A00=A[m+0][k+0] , A10=A[m+1][k+0] , A20=A[m+2][k+0] , A30=A[m+3][k+0];
          float B00=B[k+0][n+0] , B01=B[k+0][n+1] , B02=B[k+0][n+2] , B03=B[k+0][n+3];
          C[m+0][n+0] += A00*B00;  C[m+0][n+1] += A00*B01;  C[m+0][n+2] += A00*B02;  C[m+0][n+3] += A00*B03;
          C[m+1][n+0] += A10*B00;  C[m+1][n+1] += A10*B01;  C[m+1][n+2] += A10*B02;  C[m+1][n+3] += A10*B03;
          C[m+2][n+0] += A20*B00;  C[m+2][n+1] += A20*B01;  C[m+2][n+2] += A20*B02;  C[m+2][n+3] += A20*B03;
          C[m+3][n+0] += A30*B00;  C[m+3][n+1] += A30*B01;  C[m+3][n+2] += A30*B02;  C[m+3][n+3] += A30*B03;
          //k+1
          float A01=A[m+0][k+1] , A11=A[m+1][k+1] , A21=A[m+2][k+1] , A31=A[m+3][k+1];
          float B10=B[k+1][n+0] , B11=B[k+1][n+1] , B12=B[k+1][n+2] , B13=B[k+1][n+3];
          C[m+0][n+0] += A01*B10;  C[m+0][n+1] += A01*B11;  C[m+0][n+2] += A01*B12;  C[m+0][n+3] += A01*B13;
          C[m+1][n+0] += A11*B10;  C[m+1][n+1] += A11*B11;  C[m+1][n+2] += A11*B12;  C[m+1][n+3] += A11*B13;
          C[m+2][n+0] += A21*B10;  C[m+2][n+1] += A21*B11;  C[m+2][n+2] += A21*B12;  C[m+2][n+3] += A21*B13;
          C[m+3][n+0] += A31*B10;  C[m+3][n+1] += A31*B11;  C[m+3][n+2] += A31*B12;  C[m+3][n+3] += A31*B13;
          //k+2
          float A02=A[m+0][k+2] , A12=A[m+1][k+2] , A22=A[m+2][k+2] , A32=A[m+3][k+2];
          float B20=B[k+2][n+0] , B21=B[2+1][n+1] , B22=B[2+1][n+2] , B23=B[2+1][n+3];
          C[m+0][n+0] += A02*B20;  C[m+0][n+1] += A02*B21;  C[m+0][n+2] += A02*B22;  C[m+0][n+3] += A02*B23;
          C[m+1][n+0] += A12*B20;  C[m+1][n+1] += A12*B21;  C[m+1][n+2] += A12*B22;  C[m+1][n+3] += A12*B23;
          C[m+2][n+0] += A22*B20;  C[m+2][n+1] += A22*B21;  C[m+2][n+2] += A22*B22;  C[m+2][n+3] += A22*B23;
          C[m+3][n+0] += A32*B20;  C[m+3][n+1] += A32*B21;  C[m+3][n+2] += A32*B22;  C[m+3][n+3] += A32*B23;
          //k+3
          float A03=A[m+0][k+3] , A13=A[m+1][k+3] , A23=A[m+2][k+3] , A33=A[m+3][k+3];
          float B30=B[k+3][n+0] , B31=B[3+1][n+1] , B32=B[3+1][n+2] , B33=B[3+1][n+3];
          C[m+0][n+0] += A03*B30;  C[m+0][n+1] += A03*B31;  C[m+0][n+2] += A03*B32;  C[m+0][n+3] += A03*B33;
          C[m+1][n+0] += A13*B30;  C[m+1][n+1] += A13*B31;  C[m+1][n+2] += A13*B32;  C[m+1][n+3] += A13*B33;
          C[m+2][n+0] += A20*B30;  C[m+2][n+1] += A20*B31;  C[m+2][n+2] += A20*B32;  C[m+2][n+3] += A20*B33;
          C[m+3][n+0] += A33*B30;  C[m+3][n+1] += A33*B31;  C[m+3][n+2] += A33*B32;  C[m+3][n+3] += A33*B33;
        }
      }
    }
    
    for(int i=0; i<N; i++){
        delete[] A[i];
    }
    delete[]A;
    
    for(int i=0; i<N; i++){
        delete[] B[i];
    }
    delete[]B;
    
    for(int i=0; i<N; i++){
        delete[] C[i];
    }
    delete[]C;
    
    chrono::steady_clock::time_point time_end=chrono::steady_clock::now();
    chrono::duration<double> time_used=chrono::duration_cast<chrono::duration<double>>(time_end-time_start);
    cout<<"Time use:"<<time_used.count()<<"s"<<endl;
    return 0;
}

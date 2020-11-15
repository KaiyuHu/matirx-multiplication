//
//  main.cpp
//  openblas-test
//
//  Created by 胡开域 on 2020/11/13.
//  Copyright © 2020 胡开域. All rights reserved.
//

#include <iostream>
#include <cblas.h>
using namespace std;
int main(int argc, const char * argv[]) {
    const enum CBLAS_ORDER Order=CblasRowMajor;
    const enum CBLAS_TRANSPOSE TransA=CblasNoTrans;
    const enum CBLAS_TRANSPOSE TransB=CblasNoTrans;
    const int M=10000;//A的行数，C的行数
    const int N=10000;//B的列数，C的列数
    const int K=10000;//A的列数，B的行数
    const float alpha=1;
    const float beta=0;
    const int lda=K;//A的列
    const int ldb=N;//B的列
    const int ldc=N;//C的列
    float *A=new float[M*K];
    srand(time(0));
    for(int i=0; i<10000; i++){
        A[i]=rand()%100;
    }
    float *B=new float[K*N];
    for(int i=0; i<10000; i++){
        B[i]=rand()%100;
    }
    float *C=new float[M*N];
    chrono::steady_clock::time_point time_start=chrono::steady_clock::now();
    cblas_sgemm(Order, TransA, TransB, M, N, K, alpha, A, lda, B, ldb, beta, C, ldc);
    chrono::steady_clock::time_point time_end=chrono::steady_clock::now();
    chrono::duration<double> time_used=chrono::duration_cast<chrono::duration<double>>(time_end-time_start);
    cout<<"Time use:"<<time_used.count()<<"s"<<endl;
    delete[] A;
    delete[] B;
    delete[] C;
    return EXIT_SUCCESS;
    return 0;
}

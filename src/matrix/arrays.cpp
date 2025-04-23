/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <algorithm>

using namespace std;
#define N_macro 2

void print_arr(int* arr, int m, int n){
    for (int i=0;i<m;i++){
        for (int j=0;j<n;j++){
            std::cout << *(arr + i*n +j) << " ";
        }
        std::cout << std::endl;
    }
}

void search_arr(int* arr, int m, int n, int x){
    for (int i=0;i<m;i++){
        for (int j=0;j<n;j++){
            if (*(arr + i*n +j) == x){
                std::cout<< x << " Found at "<< "["<< i<< "]"<< "["<< j<< "]";
            }
        }
        std::cout << std::endl;
    }
}


void add_arr(int* arr, int*arr2, int*arr3, int m, int n, int m2, int n2){
    if (m==m2 && n==n2){
        for (int i=0;i<m;i++){
            for (int j=0;j<n;j++){
                *(arr3 + i*n + j) = *(arr + i*n + j) + *(arr2 + i*n + j);
            }
        }
    }
    else {
        std::cout << "Not Possible";
    }
}

void sub_arr(int* arr, int*arr2, int*arr3, int m, int n, int m2, int n2){
    if (m==m2 && n==n2){
        for (int i=0;i<m;i++){
            for (int j=0;j<n;j++){
                *(arr3 + i*n + j) = *(arr + i*n + j) - *(arr2 + i*n + j);
            }
        }
    }
    else {
        std::cout << "Not Possible";
    }
}

void mul_arr(int* arr, int*arr2, int*arr3, int m, int n, int m2, int n2){
    if (n==m2){
        for (int i=0;i<m;i++){
            for (int j=0;j<n2;j++){
                *(arr3 + i*n2 + j) = 0;
                for (int k=0;k<n;k++){
                    *(arr3 + i*n2 + j) += *(arr + i*n + k) * *(arr2 + k*n + j);
                }
            }
        }
    }
    else {
        std::cout << "Not Possible";
    }
}

//works for non-square matrix also.
void rotate_arr(int* arr, int* arr2, int m, int n, bool clock){
    if (clock == true){
        for (int i=0;i<m;i++){
            for (int j=0;j<n;j++){
                *(arr2 + i*n + j) = *(arr + (n-j-1)*n + i); //arr[n-j-1][i]
            }
        }
    }
    else { // anti-clockwise rotation
        for (int i=0;i<m;i++){
            for (int j=0;j<n;j++){
                *(arr2 + i*n + j) = *(arr + j*n + n-i-1); //arr[j][n-i-1]
            }
        }
    }
}

//works only for square matrix & anti-clockwise rotation
void inp_rotate(int mat[][N_macro]){
    for (int i=0;i<N_macro;i++){
        reverse(mat[i], mat[i]+N_macro);
    }
    
    for (int i=0;i<N_macro;i++){
        for (int j=0;j<N_macro;j++){
            swap(mat[i][j], mat[j][i]);
        }
    }
}


int main()
{
    int M = 2, N = 2;
    int arr[M][N_macro] = {{1,2},
                     {3,4}};
    int arr2[M][N];
    //print_arr(&arr[0][0], M, N);    
    //search_arr(&arr[0][0], M, N, 5);
    //add_arr(&arr[0][0], &arr[0][0], &arr2[0][0], M, N, M, N);
    //sub_arr(&arr[0][0], &arr[0][0], &arr2[0][0], M, N, M, N);
    //mul_arr(&arr[0][0], &arr[0][0], &arr2[0][0], M, N, M, N);
    int rotated_arr[N][M];
    rotate_arr(&arr[0][0], &rotated_arr[0][0], M, N, false);
    //inp_rotate(arr);
    print_arr(&rotated_arr[0][0], M, N);
    return 0;
}


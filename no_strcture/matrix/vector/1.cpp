#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

vector<int> search_elem_rwise_cwise(std::vector<vector<int>> mat, int x){
   int k = 0;
   int m = mat.size() - 1;
   int l = 0;
   int n = mat[0].size() - 1;
   int i = 0;
   //cout << k <<" " << m << " "<< l << " " << n << endl;
   while(k<=mat.size()-1 and n>-1){
       if (x == mat[k][n]){
           return {k,n};
       }
       else if (x > mat[k][n]){
           k += 1;
       }
       else {
           n -= 1;
       }
   }

   return {-1, -1};
}


int main() {
	// your code goes here
	std::vector<vector<int>> mat = {{1,2,3},
	                                {4,5,6},
	                                {7,8,9}};
	/*for (int i=0;i<mat.size();i++){
	    for (int j=0;j<mat[0].size();j++){
	        std::cout << mat[i][j] << " ";
	    }
	    std::cout << endl;
	}*/
	
	vector<int> ind = search_elem_rwise_cwise(mat, 1);
	
	if (ind[0] != -1){
	    cout << "Index is : [" << ind[0] <<"," << ind[1] << "]" << endl;
	}
	else {
	    cout << "Not found";
	}

    return 0;
}

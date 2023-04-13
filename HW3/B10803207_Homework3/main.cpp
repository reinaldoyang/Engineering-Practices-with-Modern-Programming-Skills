#include <vector>
#include <iostream>
#include<time.h>
using namespace std;

// A type alias declaration for a vector of double value
using RealVec=vector<double>;

// A type alias for vector dimensions (size)
using Dim = RealVec::size_type;

//A type alias for vector type (e.g. double)
using DataType = RealVec::value_type;

//A type alias for a vector of vectors with doubles= a real matrix
using RealMatrix=vector<RealVec>;

void nonDiagonalSum(RealMatrix m)
{
    //Accumulate elements except the diagonal
    double non_diagonal_sum {};
    
    for (int r=0; r < m.size();++r)
        for(int c=0;c<m[0].size();++c)
            if (c != r)
                non_diagonal_sum += m[r][c];
    cout<<"Sum of m except the diagonal "<<non_diagonal_sum<<endl;
}


void generateMatrix(double **a){
    int i,j;
   
    for (i=0 ; i<4 ; i++){
        a[i]=new double[4];
        for (j=0; j<4 ; j++){
            a[i][j] = rand()%(201)-100;
        }
    }
     for( i = 0; i < 4; ++i)
        {for( j = 0; j < 4; ++j)
     cout<<a[i][j]<<'\t';
   cout<<'\n';
 }
}

void matrixAddition(double **a,double **b, double**sum){
int i,j;
for(i = 0; i < 4; ++i){
        sum[i]=new double[4];
        for(j = 0; j < 4; ++j)
            sum[i][j] = a[i][j] + b[i][j];
}

for( i = 0; i < 4; ++i){
        {for( j = 0; j < 4; ++j)
     cout<<sum[i][j]<<'\t';
   cout<<'\n';
 }
}
}

void matrixSubstraction(double **a,double **b, double**min){
int i,j;
for(i = 0; i < 4; ++i){
        min[i]=new double[4];
        for(j = 0; j < 4; ++j)
            min[i][j] = a[i][j] - b[i][j];
}

for( i = 0; i < 4; ++i){
        {for( j = 0; j < 4; ++j)
     cout<<min[i][j]<<'\t';
   cout<<'\n';
 }
}
}

int main(){
double **M1= new double*[4], **M2=new double*[4];
double **MPLUS=new double*[4], **MMINUS=new double*[4];
// Using RealMatrix as it is
RealMatrix m ={
                { 2, 2, 0, 11 },
                { 3, 4, 5, 0 },
                { -1, 2, -1, 7 }
            };

//Add next row
m.push_back({ 5, 3, 5, -3 });
 srand(time(0));
nonDiagonalSum(m);
cout<<"\nFirst Matrix M1"<<endl;
generateMatrix(M1);


cout<<"\nSecond Matrix M2"<<endl;
generateMatrix(M2);
cout<<"\nAddition"<<endl;
matrixAddition(M1,M2,MPLUS);
cout<<"\nSubstraction"<<endl;
matrixSubstraction(M1,M2,MMINUS);
//First Matrix
//Second Matrix
}

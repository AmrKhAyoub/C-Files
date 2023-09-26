#include<iostream>
using namespace std;
int main() {
    int row,
    col;
    cout<<" MATRIX SHOULD BE [A×B] and [B×C] WHERE B=B  \n";
    int a,
    b,
    c;
    cout<<"Insert A :\n";
    cin>>a;
    cout<<"Insert B :\n";
    cin>>b;
    cout<<"Insert C :\n";
    cin>>c;

    int A[a][b];
    cout<<"Insert Array A :\n------";
    for (row = 0; row < a; row++) {
        for (col = 0; col < b; col++) {
            cin>>A[row][col];
        }
    }

    cout<<"Insert Array B :\n------";
    int B [b][c];
    for (row = 0; row < b; row++) {
        for (col = 0; col < c; col++) {
            cin>>B[row][col];
        }
    }

    int C[a][c];
    for (row = 0; row < a; row++) {
        for (col = 0; col < c; col++) {
            C[row][col] = 0;
            for (int i = 0; i < b; i++) {
                C[row][col] += A[row][i]*B[i][col];
            }
        }
    }

    cout<<"Result AB :\n---------------";
    for (row = 0; row < a; row++) {
        for (col = 0; col < c; col++)
        cout<<C[row][col]<<"  ";
        cout<<"\n";
    }
    return 0;
}
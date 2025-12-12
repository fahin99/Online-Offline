#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

class Figure{
    int row, col;
    string name;
    int** matrix;
public:
    void set_name(){
        switch(row){
            case 2: name="Line"; 
                    break;
            case 3: name="Triangle"; 
                    break;
            case 4: name="Rectangle"; 
                    break;
            default: name="Polygon"; 
                     break;
        }
        name+=to_string(col)+"D";
    }
    Figure(){
        row=0;
        col=0;
        name="";
        matrix=nullptr;
    }
    Figure(int r, int c, int* m){
        row=r;
        col=c;
        set_name();
        matrix=new int*[row];
        for(int i=0; i<row; i++){
            matrix[i]=new int[col];
            for(int j=0; j<col; j++){
                matrix[i][j]= m[i*col+j];
            }
        }
    }
    Figure(const Figure &fig){
        row=fig.row;
        col=fig.col;
        name=fig.name;
        matrix=new int*[row];
        for(int i=0; i<row; i++){
            matrix[i]=new int[col];
            for(int j=0; j<col; j++){
                matrix[i][j] = fig.matrix[i][j];
            }
        }
    }
    ~Figure(){
        row=0;
        col=0;
        name="";
        cout<<"Figure has been destroyed."<<endl;
        if(matrix){
            for(int i=0; i<row; i++){
                delete[] matrix[i];
            }
            delete[] matrix;
        }
    }
    int getSum(){
        int sum=0;
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                sum +=matrix[i][j];
            }
        }
        return sum;
    }
    int getSum(int x, int y){
        if(x>row or y>col){
            cout<<"Out of bounds"<<endl;
            return -1;
        }
        int sum=0;
        for(int i=0;i<x;i++){
            for(int j=0;j<y;j++){
                sum +=matrix[i][j];
            }
        }
        return sum;
    }
};

int main(){
    Figure fig1;

    int m[8]={1, 2, 3, 4, 5, 6, 7, 8};
    Figure fig2(2, 3, m);
    cout<<"Sum of all elements in fig2: "<<fig2.getSum()<<endl;
    cout<<"Sum of first 2x2 elements in fig2: "<<fig2.getSum(2, 2)<<endl;

    Figure fig3(fig2);
    cout<<"Sum of all elements in fig3: "<<fig3.getSum()<<endl;

    return 0;
}
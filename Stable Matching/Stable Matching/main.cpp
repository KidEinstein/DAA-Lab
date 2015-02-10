//============================================================================
// Name        : Matching.cpp
// Author      : Anirudh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#define row 5
#define column 6
using namespace std;



//bool matchComplete() {
//	bool done = true;
//	for(int i = 0; i < row; i++) {
//		if(a[i][0][1] == "no") {
//			done = false;
//			break;
//		}
//	}
//	return done;
//}
int main() {
    ifstream fa("a.txt");
    ifstream fb("b.txt");
    string a[row][column][2];
    string b[row][column][2];
    int newManPos, oldManPos;
    bool done = false;
    string man;
    string woman;
    string oldMan;
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < column; j++) {
            fa>>a[i][j][0];
            a[i][j][1]="no";
        }
    }
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < column; j++) {
            cout<<a[i][j][0]<<" ";
            cout<<a[i][j][1]<<" ";
        }
        cout<<endl;
    }
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < column; j++) {
            fb>>b[i][j][0];
            b[i][j][1] = "no";
        }
    }
    cout<<endl;
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < column; j++) {
            cout<<b[i][j][0]<<" ";
            cout<<b[i][j][1]<<" ";
        }
        cout<<endl;
    }
    for (int z = 0; z < 1000; z++) {
        done = true;
        for(int i = 0; i < row; i++) {
            if(a[i][0][1] == "no") {
                done = false;
                break;
            }
        }
        if(done == true)
            break;
        for(int i = 0; i < row; i++) {
            man = a[i][0][0];
            for(int j = 1; j < column; j++) {
                if (a[i][0][1] == "yes")
                    break;
                woman = a[i][j][0];
                for(int k = 0; k < row; k++) {
                    if(b[k][0][0] == woman) {
                        if(b[k][0][1] == "no") {
                            for(int l = 1; l < column; l++) {
                                if(b[k][l][0] == man) {
                                    b[k][0][1] = "yes";
                                    b[k][l][1] = "yes";
                                    a[i][0][1] = "yes";
                                    a[i][j][1] = "yes";
                                    break;
                                }
                            }
                            
                        }
                        else {
                            for(int l = 1; l < column; l++) {
                                if(b[k][l][0] == man)
                                    newManPos = l;
                                if(b[k][l][1] == "yes") {
                                    oldManPos = l;
                                }
                            }
                            if(newManPos < oldManPos) {
                                b[k][newManPos][1] = "yes";
                                a[i][j][1] = "yes";
                                a[i][0][1] = "yes";
                                b[k][oldManPos][1] = "no";
                                oldMan = b[k][oldManPos][0];
                                for(int m = 0; m < row; m++) {
                                    if(a[m][0][0] == oldMan) {
                                        a[m][0][1] = "no";
                                        for(int n = 1; n < column; n++) {
                                            if(a[m][n][0] == woman) {
                                                a[m][n][1] = "no";
                                                break;
                                            }
                                        }
                                        break;
                                    }
                                    
                                }
                            }
                            
                        }
                    }
                }
            }
            
            
        }
    }
    cout<<endl;
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < column; j++) {
            cout<<a[i][j][0]<<" ";
            cout<<a[i][j][1]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < column; j++) {
            cout<<b[i][j][0]<<" ";
            cout<<b[i][j][1]<<" ";
        }
        cout<<endl;
    }

    
    
}

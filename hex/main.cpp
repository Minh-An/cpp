/*
 * Hex Game
 */

#include <iostream>
using namespace std;

int main() {

  int d = 11; //dimensions of hex board
  cout << "Game Of Hex" << endl;
  cout << endl;	

  //print out hex board
  for(int i = 0; i < d; i++) {

    for(int k = 0; k < i; k++){
      cout << "  ";
    }

    for(int j = 0; j < d; j++) {
      if(j == d-1) {
	cout << ".";
      }
      else {
	cout << ". - ";
      }
      
    }
    cout << endl;
    for(int k = 0; k < i; k++) {
      cout << "  ";
    }

    if(i != d-1) {
      for(int j = 0; j < d; j++) {
	cout << " \\";
	if (j != d-1) {
	  cout << " /";
	}
      }
      cout << endl;
    }
  }
  cout << endl;
  
}

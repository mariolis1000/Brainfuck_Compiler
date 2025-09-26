#include<iostream>
#include<string>
#include<vector>
using namespace std;
const int N = 30000;

void run(string &input, vector<unsigned char> &tape, int &i){
char x;
for(int iter = 0; iter < input.length(); iter++) {
  x = input[iter];
  switch(x){
    //Navigating the tape
    case '>':
      if(i<(N-1)) (i)++;
      break;
    case '<':
      if(i>0) (i)--;
      break;

    //Adding or Subtracting for each element
    case '+':
      tape[i]++;
      break;
    case '-':
      tape[i]--;
      break;

      //Basic I/O
    case '.':
      cout << tape[i];
      break;
    case ',':
      char inp;
      cin.get(inp);
      tape[i] = inp;

      //loop implementation
    case '[':
      if(tape[i] == 0){

      }
      else{

      }
      //run(&tape[0], &i);
      break;
    case ']':
      //return;
      break;

  }
 }
}

int main(){
  vector<unsigned char> tape(N, 0);
  int i = 0;
  
  string input;
  char c;

  while(cin.get(c)){
    if(c == '>' || c == '<' 
    || c == '+' || c == '-'
    || c == '.' || c == ','
    || c == '[' || c == ']')
      input += c;
  }
  
  run(input, tape, i);
  cout << endl;

}


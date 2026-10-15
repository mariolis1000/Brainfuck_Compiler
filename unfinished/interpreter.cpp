#include<iostream>
#include<string>
#include<vector>
#include<cstdio>
using namespace std;

const int N = 30000;

int main(){
  vector<unsigned char> tape(N, 0);
  int i = 0;
  
  string input;
  input.reserve(100000);
  char c;

  // Read BrainFuck source from standard input, keeping only
  // valid BrainFuck characters, just like the compiler does.
  while(cin.get(c)){
    if(c == '>' || c == '<' 
    || c == '+' || c == '-'
    || c == '.' || c == ','
    || c == '[' || c == ']')
      input += c;
  }

  // Match every '[' with its corresponding ']' so that loops
  // can be skipped or repeated without recursion.
  vector<int> match(input.size(), -1);
  vector<int> stack;
  for(size_t k = 0; k < input.size(); k++){
    if(input[k] == '['){
      stack.push_back((int)k);
    }
    else if(input[k] == ']'){
      if(stack.empty()){
        fprintf(stderr, "Unmatched ']'\n");
        return 1;
      }
      int open = stack.back();
      stack.pop_back();
      match[open] = (int)k;
      match[(int)k] = open;
    }
  }
  if(!stack.empty()){
    fprintf(stderr, "Unmatched '['\n");
    return 1;
  }

  size_t ip = 0;
  while(ip < input.size()){
    char x = input[ip];
    switch(x){
      //Navigating the tape
      case '>':
        if(i < (N-1)) (i)++;
        break;
      case '<':
        if(i > 0) (i)--;
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
        putchar(tape[i]);
        fflush(stdout);
        break;
      case ',':
      {
        int ch = getchar();
        tape[i] = (ch == EOF) ? 0 : (unsigned char)ch;
        break;
      }

      //loop implementation
      case '[':
        if(tape[i] == 0){
          ip = match[ip];
        }
        break;
      case ']':
        if(tape[i] != 0){
          ip = match[ip];
        }
        break;
    }
    ip++;
  }

  putchar('\n');
  return 0;
}
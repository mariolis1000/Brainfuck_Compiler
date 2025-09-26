#include<stdio.h>

const int N = 30000;

int normalise(int y){


}


int main(){
  unsigned char tape[30000] = {0};
  int i =0;

  while(true){
    char x = getchar();
    if(x == EOF) break;

    switch(x){
      //Navigating the tape
      case '>':
        if(i<(N-1)) i++;
        break;
      case '<':
        if(i>0) i--;
        break;
      
      //Adding or Subtracting for each element  
      case '+':
        tape[i]++;
        break;
      case '-':
        tape[i]--;
        break;


      case '.':
        putchar(tape[i]);
        break;
      case ',':
        char in;
        scanf("%c", &in);
        tape[i] = in;
      case '[':
      case ']':

    }
    
  }

}

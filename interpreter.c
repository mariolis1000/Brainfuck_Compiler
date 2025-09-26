#include<stdio.h>

const int N = 30000;

//int normalise(int y){}

void run(unsigned char *tape, int *i){ 
  while(true){
    char x = getchar();
    if(x == EOF) break;

    switch(x){
      //Navigating the tape
      case '>':
        if(*i<(N-1)) (*i)++;
        break;
      case '<':
        if(*i>0) (*i)--;
        break;

      //Adding or Subtracting for each element
      case '+':
        tape[*i]++;
        break;
      case '-':
        tape[*i]--;
        break;

      //Basic I/O
      case '.':
        putchar(tape[*i]);
        break;
      case ',':
        char inp;
        scanf("%c", &inp);
        tape[*i] = inp;

      //loop implementation
      case '[':
        if(tape[*i] == 0){
          
        }
        else{

        }
        //run(&tape[0], &i);
        break;
      case ']':
        return;

    }

  }


}


int main(){
  unsigned char tape[30000] = {0};
  int i =0;
  char mode;
  scanf("%c", &mode); //I should automate that with a bash script/alias
                      //That 
  
  switch(mode){
    case'r': //calls run , which is my interpreter
      program(&tape[0], &i);
      break;
    case'c': //runs the compiler, which i hope to write eventually
      break;
  }
}

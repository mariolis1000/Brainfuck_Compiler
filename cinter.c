#include<stdio.h>
#include<stdlib.h>
#include<string.h>

const int N = 30000;

//int normalise(int y){}

void run(unsigned char *tape, int *i, char mode[], FILE *f){ 
  char lin[255];
  int indx=0;


  while(true){
   if (strcmp(mode, "Default")==0 ) {
     if(fgets(lin, sizeof(lin), stdin) == NULL) return;
   }
   else if(strcmp(mode, "Run")==0 && f != NULL) {
     if(fgets(lin, sizeof(lin), f) == NULL) return;
   }
   //strcmp(mode , "...")==0 compares two strings , if they are equal

   indx = 0;
   while(indx < 255 && lin[indx] != '\n'){
    char x = lin[indx];
    if(x == EOF) return;
    indx++;
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


}


int main(int argc, char *argv[]){

  

  unsigned char tape[30000] = {0};
  int i =0;
  //char mode;
  //char program[];


  if(argc == 1) {
    run(&tape[0], &i, "Default", NULL); //if nothing is inserted, interpretet interactively
  }
  else{
    FILE *f = fopen(argv[1], "r");
    if(!f){
      printf("Couldnt open the file\n"); //check if the file isnt opened correctly
      return 1;
    }
    
    char runmode;
    if(argc == 2)  runmode = 'r';
    else if(argc >= 3) runmode = argv[2][0];
    switch(runmode){
      case 'r': //calls run , which is my interpreter
        run(&tape[0], &i, "Run", f);
        break;
      case 'c': //runs the compiler, which i hope to write eventually
        break;
      default:
        printf("I dont know what you want to do\n");
    }

  }

  //scanf("%c", &mode); //I should automate that with a bash script/alias
                      //That 


  return 0;
}

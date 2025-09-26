#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main(){
    string input;
    input.reserve(100000);
    char c;

    while(cin.get(c)){
        if(c == '>' || c == '<'
            || c == '+' || c == '-'
        || c == '.' || c == ','
        || c == '[' || c == ']')
            input += c;
    }

    ofstream myFile("a.c");
    myFile << "#include<stdio.h>\n#include<stdlib.h>\n#include<string.h>\nconst int N = 30000;\nint main(){\n unsigned char \n tape[30000]={0};\n int i =0;\n char inp;\n";
    for(int iter=0; iter<input.size(); iter++){
        char x = input[iter];
        switch(x){
            case '>':
                myFile << "\n if(i<(N-1)) (i)++;";
                break;
            case '<':
                myFile << "\n if(i>0) (i)--;";
                break;

            case '+':
                myFile << "\n tape[i]++;";
                break;
            case '-':
                myFile << "\n tape[i]--;";
                break;

                //Basic I/O
            case '.':
                myFile << "\n putchar(tape[i]);";
                break;
            case ',':
                myFile << "\n inp=getchar();\n tape[i] = inp;";
                break;


            //loop implementation
            case '[':
               myFile << "\n while(tape[i] != 0){";
               break;
            case ']':
               myFile << "\n }\n";
                break;
        }
    }
    myFile << "\n putchar('\\n');\n return 0;\n}";
    myFile.close();
}

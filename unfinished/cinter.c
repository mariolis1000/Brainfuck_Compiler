#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 30000

typedef struct {
    char *data;
    size_t len;
    size_t cap;
} Buffer;

static void buffer_append(Buffer *b, char ch){
    if(b->len + 1 > b->cap){
        size_t newcap = b->cap ? b->cap * 2 : 4096;
        char *tmp = realloc(b->data, newcap);
        if(!tmp){
            fprintf(stderr, "Out of memory\n");
            exit(1);
        }
        b->data = tmp;
        b->cap = newcap;
    }
    b->data[b->len++] = ch;
    b->data[b->len] = '\0';
}

static void load_program(FILE *f, Buffer *prog){
    int c;
    while((c = fgetc(f)) != EOF){
        if(c == '>' || c == '<' || c == '+' || c == '-' ||
           c == '.' || c == ',' || c == '[' || c == ']'){
            buffer_append(prog, (char)c);
        }
    }
}

int main(int argc, char *argv[]){
    FILE *f = NULL;
    Buffer prog;
    prog.data = NULL;
    prog.len = 0;
    prog.cap = 0;

    if(argc == 1){
        // Interactive-ish mode: read BrainFuck from standard input.
        load_program(stdin, &prog);
    }
    else{
        f = fopen(argv[1], "r");
        if(!f){
            printf("Couldn't open the file\n");
            return 1;
        }
        load_program(f, &prog);
        fclose(f);
    }

    // Match brackets.
    int *match = malloc(prog.len * sizeof(int));
    int *stack = malloc(prog.len * sizeof(int));
    int sp = 0;
    if((prog.len > 0 && (!match || !stack))){
        fprintf(stderr, "Out of memory\n");
        return 1;
    }
    for(size_t k = 0; k < prog.len; k++) match[k] = -1;
    for(size_t k = 0; k < prog.len; k++){
        if(prog.data[k] == '['){
            stack[sp++] = (int)k;
        }
        else if(prog.data[k] == ']'){
            if(sp == 0){
                fprintf(stderr, "Unmatched ']'\n");
                free(match); free(stack); free(prog.data);
                return 1;
            }
            int open = stack[--sp];
            match[open] = (int)k;
            match[k] = open;
        }
    }
    if(sp != 0){
        fprintf(stderr, "Unmatched '['\n");
        free(match); free(stack); free(prog.data);
        return 1;
    }

    unsigned char tape[N] = {0};
    int ptr = 0;
    size_t ip = 0;
    while(ip < prog.len){
        char x = prog.data[ip];
        switch(x){
            case '>':
                if(ptr < (N-1)) ptr++;
                break;
            case '<':
                if(ptr > 0) ptr--;
                break;
            case '+':
                tape[ptr]++;
                break;
            case '-':
                tape[ptr]--;
                break;
            case '.':
                putchar(tape[ptr]);
                fflush(stdout);
                break;
            case ',':
            {
                int ch = getchar();
                tape[ptr] = (ch == EOF) ? 0 : (unsigned char)ch;
                break;
            }
            case '[':
                if(tape[ptr] == 0){
                    ip = match[ip];
                }
                break;
            case ']':
                if(tape[ptr] != 0){
                    ip = match[ip];
                }
                break;
        }
        ip++;
    }

    putchar('\n');
    free(match);
    free(stack);
    free(prog.data);
    return 0;
}
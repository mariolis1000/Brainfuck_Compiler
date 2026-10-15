#!/usr/bin/env bash

#compile the BrainFuck compiler
#Which I wrote in C++
g++ compiler.cpp -o compiler || {
    echo "Failed to compile compiler.cpp"
    exit 1
}

# Delete any stale executable so the user can never mistake
# an old binary for a freshly compiled one.
rm -f a.out

#put your file as input to the compiler
#it doesnt have to be .bf ,any file will do
#if not a brainfuck file, the compiler will still treat it as such
if [ -z "$1" ]; then
    echo "Usage: $0 <brainfuck source file>"
    exit 1
fi
./compiler < "$1"

#compile the intermediate C file,
#if there were any errors in the original brainfuck program
#they will be cought here
if ! gcc a.c -o a.out; then
    echo "Compilation error occurred in a.c"
    rm -f a.out
    exit 1
fi

#run the executable program
./a.out

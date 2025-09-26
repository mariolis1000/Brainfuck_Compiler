#!/usr/bin/env bash

          #compile the BrainFuck compiler
          #Which I wrote in C++
g++ compiler.cpp -o compiler


          #put your file as input to the compiler
          #it doesnt have to be .bf ,any file will do
          #if not a brainfuck file, the compiler will still treat it as such
./compiler < $1
          # it will create an intermediate file of C code a.c
          # note that my compiler doesnt check for errors at all, 
          # so it is possible that a.c will be created no matter what


          #compile the intermediate C file, 
          #if there were any errors in the original brainfuck program
          #they will be cought here
gcc a.c


          #run the executable program
./a.out
          #Beware that if there already was an executable
          #but the compilation failed
          #the old executable will still be run

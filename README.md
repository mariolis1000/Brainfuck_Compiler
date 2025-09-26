The documentation for the BrainFuck compiler that I wrote in C++:

Basically what the compiler does is read from standard input.
It reads BrainFuck code and translates it into a new file called a.c
That is all that the compiler itself does, it doesn't know anything of input files,
file extensions or if what you input in it is even brainfuck code , and it doesn't
even check for errors. Note that it will always create the "a.c" file no matter
what is entered. The compiler itself is just a translation layer from BrainFuck to C

How do programs run then? How do we check for errors?
Everything is taken care of when we take the next step, 
which is to actually compile the a.c file 
if any illegal BrainFuck was entered in the original file, a.c will fail to compile
and gcc will even tell you where in the intermediate a.c fille the error occured

Afterwards, all that needs to be done is for the executable to be run,
and then, congratulations, you have made a BrainFuck program !!!

(Needless to say, if you already have some kind of file called a.c in the 
directory that you use the compiler from, it will get overwritten, so be careful)


    

While you can make this run on any system that has a C compiler AND a C++ compiler,
I realise that writting the same few commands can be a bit tedious.
For that, I wrote a quick Bash script that automates the following steps:
    1) compiles the compiler.cpp using g++ , the GNU C++ compiler.
    2) runs the compiler on a specified given BrainFuck source code file
    3) compiles the intermediate a.c file using gcc
    4) runs the executable that resulted from the compilation, if it was sucessful
(Important Note: if your program failed to compile , 
but you already have an executable from a previous compilation, 
but your current one failed to compile, this script will still run the
previously compiled executable)

This script is the "run.sh" file, and can be used
people with a Unix-like OS (Linux, Mac, BSD) ,
As long as the following are installed:
1) A terminal (or terminal emulator)
2) bash 
3) gcc AND g++  (Should both be included on any system with GCC installed)
4) git

(If you are on Windows you can follow along,
by downloading an app called "Git Bash" from:
https://github.com/git-for-windows/git/releases/tag/v2.51.0.windows.1
)

In the directory , i already have two example brainfuck files included,
one outputs "Q" to the terminal, and the other outputs "hi"

Now , to actually download this do the following:
1) Create and/or enter an empty Folder/Directory
2) Run:   git clone https://github.com/mariolis1000/Brainfuck_Compiler.git
3) Run:   cd Brainfuck_Compiler

Now onto the fun part, ACTULLY USING the Compiler.
The commands you need to run are as follows:
1)  ./run.sh yourfile.bf    
(substitute yourfile.bf with the name of your actual BrainFuck file)

If you have already compiled a BrainFuck program, you can run it again by typing:
1) ./a.out   
(If you are on a Unix-Like system, you may need to run ./a.exe if you are on Windows)


Notes on the files provided:
    compiler.cpp         -  Is the C++ programm that does the translating
    README.md            -  The documentation you are currently reading
    run.sh               -  The script you actually run to compile in a single command
    example.bf, test.bf  - Example files that include BrainFuck code for testing

Notes on the files produced by running run.sh:
    compiler   -   Is the actual program/executable that translates BF into C
    a.c        -   Is the intermediate a.c file that will then be fed into gcc
    a.out      -   Is the completed version of your BrainFuck program, your binary executable
    
    

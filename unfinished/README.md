This README is just to explain why this "unfinished" folder exists


When I started working on Brainfuck, i thought an interpreter, 
written in C, would be the best choice,
that file is cinter.c

But as I am much more experienced in C++,
i abandoned my attempt to finish it in C, 
and so i decided to rewrite the interpreter in C++.

This is why interpreter.cpp exists
I managed to almost complete it,
but i couldn't figure out how to implement the '['
character of Brainfuck, maybe I could finish it eventually, 
but I thought it would be easier to just write a compiler instead,
... and it actually was, which is why these attempts to write an interpeter
remain here.

I don't plan of finishing these, maybe at some point when  I am really bored.


Update: 

Both interpreter attempts have now been completed (originally left unfinished because of the loop handling). I added bracket matching ([ with ]) so nested loops work, fixed the fall-through bug after the , instruction, added EOF handling on input (sets the cell to 0), kept pointer bounds checks, and added C/C++ error messages for unmatched brackets. The implementations now match the behavior of the main BrainFuck compiler and were tested with example.bf, test.bf, and a nested-loop "Hello World" program.

Disclosure: These changes to cinter.c and interpreter.cpp were AI-assisted.
The "Update:" section above was also AI-assisted (written to summarize the changes).

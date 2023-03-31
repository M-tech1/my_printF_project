# Welcome to My Printf
***

## Task
To write program functon that implements what the generic printf function does in C language
This project is simple about recreating the functioning logic replicating the behaviours of 'printf' in C. 

The function implements `%[doux]` (for different number formats), 
`%c` (for character), `%s` (for string) and `%p` (for pointers).
I encounterd so many repeating blocks in the code, so I opted to refactor the entire codebase. It is now modular,

## Description

The my_printf() function produce output according to a format as described below. 
The my_printf() functions write output to stdout, the standard output stream;
This function writes the output under the control of a format string that specifies how subsequent arguments 
(or arguments accessed via the variable-length argument facilities of stdarg(3)) are converted for output.
The format string is composed of zero or more directives: ordinary characters (not PERCENT), 
which are copied unchanged to the output stream; and conversion specifications, 
each of which results in fetching zero or more subsequent arguments.

Each conversion specification is introduced by the PERCENT character. The arguments must correspond properly 
(after type promotion) with the conversion specifier. After the PERCENT, the following appear in sequence:

doux The int (or appropriate variant) argument is converted to signed decimal (d). 
unsigned octal (o), unsigned decimal (u), unsigned hexadecimal (x).
c The int argument is converted to an unsigned char, and the resulting character is written.
s The char * argument is expected to be a pointer to an array of character type (pointer to a string). 
Characters from the array are written up to (but not including) a terminating NUL character.
p The void * pointer argument is printed in hexadecimal.



## Installation
No external Installation Made

## Usage
To use the function 'my_printf funtion', u can simple call it into where you want to use it, in this format:

my_printf(char* restrict format, ...)

#e.g.
int main(){
 my_printf("Martins learning real Programming...);   
}

my_printf("My name is %s, he im %u years old. also scored %d in the past test", "Martins", 20, -1);


### The Core Team
OutSource academy
Martins Olu Ake

<span><i>Made at <a href='https://qwasar.io'>Qwasar Silicon Valley</a></i></span>
<span><img alt='Qwasar Silicon Valley Logo' src='https://storage.googleapis.com/qwasar-public/qwasar-logo_50x50.png' width='20px'></span>

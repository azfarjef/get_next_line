# get_next_line

The get_next_line project is a function that reads a file descriptor and returns a line from it. In the bonus part, it is designed to be able to handle reading from multiple file descriptors at the same time.

## Function Prototype
```bash
char *get_next_line(int fd);
```

## Parameter
`fd` : The file descriptor to read from.

## Return Value
`char*`: The line read from the file descriptor.

`NULL` : If there is nothing else to read or if an error occured.

## Usage

Because you will have to read files in get_next_line(), add this option to your compiler call: -D BUFFER_SIZE=n. It will define the buffer size for read():
```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c
```
Run the program:
```bash
./a.out files/part1_test01_with_lines
```
Here, `files/part1_test01_with_lines` is the file descriptor to be read from. If you want to read from the stdin (fd = 0), just run `./a.out` without any argument. The output will be the lines read from the file descriptor until EOF.

## Conclusion
The get_next_line function is a useful tool for reading text files line by line, and is commonly used in various applications. Implementing this function will help you understand how to work with file descriptors, memory allocation, and string manipulation in C.

## Credit
This project was completed as part of the curriculum of the Ecole 42 program. The instructions for the project were provided by the school.

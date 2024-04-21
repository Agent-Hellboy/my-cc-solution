# wccc 

solution for https://codingchallenges.fyi/challenges/challenge-wc/

The Word Count Tool (wccc) is a command-line utility designed to count the number of words, lines, characters, and bytes in a text file. It provides a simple and efficient way to analyze the content of text files.

## Usage

To use the Word Count Tool, follow these steps:

1. Clone or download the repository containing the Word Count Tool source code.

2. Compile the source code using your preferred compiler. For example, if you're using GCC, you can compile it with the following command:

    ```bash
    gcc -o wccc wccc.c
    ```

3. Run the compiled executable with the desired options and the path to the text file you want to analyze. Available options include:

    - `-w`: Count words.
    - `-l`: Count lines.
    - `-c`: Count characters.
    - `-b`: Count bytes.

    For example:

    ```bash
    ./wccc -w text.txt
    ```

    This command will count the number of words in the `text.txt` file and print the result.

## Example Output

Here are some examples of using the Word Count Tool with different options:

    ./wccc -w text.txt
        8   text.txt%

    ./wccc -l text.txt
        2   text.txt%

    ./wccc -b text.txt
       33   text.txt%

    ./wccc -c text.txt
       33   text.txt%

##  TODO 

- [ ] Formate code using indent 
- [*] Improve Error reporting 
- [ ] Write test , maybe try to use wc test suite , use unity for unittest  
- [ ] Try to package this 
- [ ] Try to use optind

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

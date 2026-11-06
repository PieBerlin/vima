set -xe
gcc vima.c constructors.c ./vasm/lexer.c -o vima -Wall -Wextra

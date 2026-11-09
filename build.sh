set -xe
gcc vima.c constructors.c ./vasm/lexer.c ./vasm/parser.c -o vima -Wall -Wextra

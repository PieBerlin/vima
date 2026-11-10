set -xe
gcc vima.c constructors.c ./vasm/lexer.c ./vasm/parser.c ./vasm/generatebytes.c -o vima -Wall -Wextra

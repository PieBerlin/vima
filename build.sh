set -xe
gcc vima.c constructors.c ./vasm/lexer.c assembly.c ./vasm/parser.c ./vasm/generatebytes.c ./symbol_table.c -o vima -Wall -Wextra

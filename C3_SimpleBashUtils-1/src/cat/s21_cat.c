#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
typedef struct args
{
    int b, n, s, E, T, v;
} args;
args *arg_parser(int argc, char **argv)
{
    args arg = {0};
    struct option long_options[] = {
        {"number", no_argument, NULL, 'n'},
        {"number-nonblank", no_argument, NULL, 'b'},
        {"squeeze-blank", no_argument, NULL, 's'},
        {0, 0, 0, 0},
    };
    int opt;
    opt = getopt_long(argc, argv, "bnsEeTt", long_options, 0);
    switch (opt)
    {
    case 'b':
        arg.b = 1;
        break;
    case 'n':
        arg.n = 1;
        break;
    case 's':
        arg.s = 1;
        break;
    case 'e':
        arg.E = 1;
        arg.v = 1;
        break;
    case 't':
        arg.T = 1;
        arg.v = 1;
        break;
    case 'T':
        arg.T = 1;
        break;
    case '?':
        perror("error");
    default:
        break;
    }
}
void print_out(char *line, int n)
{
    for (int i = 0; i < n; i++)
    {
        putchar(line[i]);
    }
}

void readfile()
{
    
}
int main(int argc, char **argv)
{
    FILE *file = fopen(argv[1], "r");
    char *line = NULL;
    int memline = 0;
    int read = 0;
    read = getline(&line, &memline, file);
    while(read != -1)
    {
        print_out(line, read);
        read = getline(&line, &memline, file);
    }
    fclose(file);
    return 0;
}
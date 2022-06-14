#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TokenRow 50
#define TokenCol 10

int acc, tokenLen;
char input[100];
char tokens[TokenRow][TokenCol];

void initialize()
{
    acc = 0;

    int i, j;
    for(i=0; i<TokenRow; i++)
    {
        for(j = 0; j<TokenCol; j++)
        {
            tokens[i][j] = '\0';
        }
    }
}

void readFile()
{

    FILE *infile;
    infile = fopen("input.txt", "r");

    int i, r = 0, c=0;

    char test[10];

    while(1)
    {

        fgets(test,10, infile);

        if(!strcmp(test, "Finished"))
        {
            break;
        }


        c = 0;

        for(i=0; i<strlen(test); i++)
        {
            if(test[i] == ' ')
            {
                tokens[r][c++] = '-';
                continue;
            }

            tokens[r][c++] = test[i];
        }

        r++;

    }
    tokenLen = r;

    printf("Opcodes and Operand: \n");

    for(i=0; i<tokenLen; i++)
    {
        puts(tokens[i]);
    }
}
void runPersing()
{

    int i, x;

    for(i=0; i<tokenLen; i++)
    {
        if(tokens[i][0] == 'A' && tokens[i][1] == 'D')
        {

            x = (int)(tokens[i][4]) - 48;
            acc += x;
        }
        else if(tokens[i][0] == 'S' && tokens[i][1] == 'U')
        {
            x = (int)(tokens[i][4]) - 48;
            acc -= x;
        }
        else if(tokens[i][0] == 'M' && tokens[i][1] == 'U')
        {
            x = (int)(tokens[i][4]) - 48;
            acc *= x;
        }
        else if(tokens[i][0] == 'D' && tokens[i][1] == 'I')
        {
            x = (int)(tokens[i][4]) - 48;
            acc /= x;
        }
        else if(tokens[i][0] == 'N' && tokens[i][1] == 'O')
        {
            acc = ~acc;
        }
        else if(tokens[i][0] == 'O' && tokens[i][1] == 'R')
        {
            x = (int)(tokens[i][4]) - 48;
            acc = acc | x;
        }
        else if(tokens[i][0] == 'L' && tokens[i][1] == 'D')
        {
            acc = (int)(tokens[i][3]) - 48;
        }
    }

    printf("ACC: %d", acc);
    printf("\n\n");
}


int main()
{

    initialize();
    readFile();
    runPersing();

    return 0;
}


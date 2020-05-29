#include "errors.h"
#include <string.h>


int main(int argc, char **argv)
{
    int error = 0;
    if (argc < 3 && strlen(argv[1]) != 2)
        error = ARG_ERROR;
    if (!error)
        switch (argv[1][0])
        {
            case 's':
                if (argv[1][1] == 'b' && argc == 3)
                {

                }
                else if (argv[1][1] == 't' && argc == 3)
                {

                }
                else
                    error = ARG_ERROR;
                
                break;
            case 'f':
                if (argv[1][1] == 'b' && argc == 5)
                {

                }
                else if (argv[1][1] == 't' && argc == 5)
                {

                }
                else
                    error = ARG_ERROR;
                
                break;
            case 'd':
                if (argv[1][1] == 'b' && argc == 3)
                {

                }
                else if (argv[1][1] == 't' && argc == 3)
                {

                }
                else
                    error = ARG_ERROR;
                
                break;

            default:
                error = ARG_ERROR;
                break;
        }

    return error;
}
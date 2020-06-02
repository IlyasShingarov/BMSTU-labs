#include "errors.h"
#include "wrap.h"
#include <string.h>


int main(int argc, char **argv)
{
    int error = 0;
    if (argc < 3 && strlen(argv[1]) != 2)
        error = ARG_ERROR;

    if (!error)
    {
        switch (argv[1][0])
        {
            case 's':
                if (argv[1][1] == 'b' && argc == 3)
                {
                    sb_mode(argv[2]);
                }
                else if (argv[1][1] == 't' && argc == 3)
                {
                    st_mode(argv[2]);
                }
                else
                    error = ARG_ERROR;
                break;
            case 'f':
                if (argv[1][1] == 'b' && argc == 5)
                {
                    fb_mode(argv[2], argv[3], argv[4]);
                }
                else if (argv[1][1] == 't' && argc == 5)
                {
                    ft_mode(argv[2], argv[3], argv[4]);
                }
                else
                    error = ARG_ERROR;
                break;
            case 'd':
                if (argv[1][1] == 'b' && argc == 3)
                {
                    db_mode(argv[2]);
                }
                else if (argv[1][1] == 't' && argc == 3)
                {
                    dt_mode(argv[2]);
                }
                else
                    error = ARG_ERROR;
                break;
            default:
                error = ARG_ERROR;
                break;
        }
    }

    return error;
}
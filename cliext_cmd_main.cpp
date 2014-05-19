#include "cliext_cmd_main.h"

#include <stdlib.h>
#include <string.h>

clie_callback_ret cliext_input_cb_cmd_main(struct cli_engine *engine, char *input_buf, void *user_data)
{
    char *input;
    int argc;
    char **argv;
    char *p;
    clie_callback_ret ret;

    cliext_cmd_main *cliext = (cliext_cmd_main *) user_data;
    argv = (char **) malloc(cliext->m_max_arg * sizeof(char *));

    input = (char *) malloc(engine->m_input_buf_size);
    strcpy(input, input_buf);
    
    p = input;
    argc = 0;
    while (*p)
    {
        while (*p == ' ')
        {
            *p = 0;
            p++;
        }
        if (*p != 0)
        {
            argv[argc] = p;
            argc++;

        }
        while (*p && *p != ' ') p++;
    }
    argv[argc] = 0;
    
    ret = cliext->m_cmd_main(argc, argv, cliext->m_cmd_main_user_data);
    
    //memset(argv, 0, 4 * cliext->m_max_arg);
    free(argv);
    free(input);
    
    return ret;
}

int cliext_cmd_main_init(struct cliext_cmd_main *cliext, int max_arg)
{
    cliext->m_max_arg = max_arg;
    return 0;
}
int cliext_cmd_main_set_cb(struct cliext_cmd_main *cliext, cliext_cmd_main_callback cmd_main, void *user_data)
{
    cliext->m_cmd_main = cmd_main;
    cliext->m_cmd_main_user_data = user_data;
    return 0;
}
int cliext_cmd_main_exit(struct cliext_cmd_main *cliext)
{
    return 0;
}
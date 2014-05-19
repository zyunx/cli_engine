#ifndef __UNARY_CLOUD2HAN9_CLI_ENGINE_EXT_CMD_MAIN_H__
#define __UNARY_CLOUD2HAN9_CLI_ENGINE_EXT_CMD_MAIN_H__

/************************************************************************
Example:
    struct cli_engine my_cli;
    my_cli.m_input_buf_size = 100;
    clie_init(&my_cli);

    clie_set_output_cb(&my_cli, mycli_output_cb, g);
    clie_set_prompt_cb(&my_cli, mycli_prompt_cb, g);

    struct cliext_cmd_main cliext_cmd;
    cliext_cmd_main_init(&cliext_cmd, 10);
    cliext_cmd_main_set_cb(&cliext_cmd, my_cmd_main, g);
    // use cmd_main extension
    clie_set_input_cb(&my_cli, cliext_input_cb_cmd_main, &cliext_cmd);

    clie_run(&my_cli);

    cliext_cmd_main_exit(&cliext_cmd);
    clie_exit(&my_cli);                                                        
************************************************************************/

#include "cli_engine.h"

typedef clie_callback_ret (*cliext_cmd_main_callback)(int argc, char *argv[], void *user_data);

struct cliext_cmd_main
{
    int m_max_arg;
    cliext_cmd_main_callback m_cmd_main;
    void *m_cmd_main_user_data;
};


int cliext_cmd_main_init(struct cliext_cmd_main *cliext, int max_arg);
int cliext_cmd_main_set_cb(struct cliext_cmd_main *cliext, cliext_cmd_main_callback cmd_main, void *user_data);
int cliext_cmd_main_exit(struct cliext_cmd_main *cliext);


// extension entry point for cli engine.
// Extends the cli engine by setting this input callback 
// with user_data being the cliext_cmd_main structure.
clie_callback_ret cliext_input_cb_cmd_main(struct cli_engine *engine, char *input_buf, void *user_data);


#endif
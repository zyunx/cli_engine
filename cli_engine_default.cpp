#include "cli_engine_default.h"
#include <stdio.h>
#include <string.h>

int clie_default_set_config(struct cli_engine *engine)
{
    engine->m_input_buf_size = CLIE_DEFAULT_INPUT_BUF_SIZE;
    return 0;
}

clie_callback_ret clie_default_output_cb(struct cli_engine *engine, void *user_data)
{
    printf("Machine: Hello\n\n");
    return CLIE_CB_RET_CONTINUE;
}

clie_callback_ret clie_default_prompt_cb(struct cli_engine *engine, void *user_data)
{
    printf("Give a response > ");
    return CLIE_CB_RET_CONTINUE;
}

clie_callback_ret clie_default_input_cb(struct cli_engine *engine, char *input_buf, void *user_data)
{
    if (strcmp(input_buf, "world") != 0)
    {
        printf("\nCan you remember the first program?\n\n");
        return CLIE_CB_RET_CONTINUE;
    } 
    else
    {
        return CLIE_CB_RET_GOTO_EXIT;
    }
    
}
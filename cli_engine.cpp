#include "cli_engine.h"

#include <stdlib.h>
#include <stdio.h>

#define NULL    0

int clie_init(struct cli_engine *engine)
{
    engine->m_input_buf = (char *) malloc(engine->m_input_buf_size);
    //engine->m_prompt_buf = (char *) malloc(engine->m_prompt_buf_size);

    clie_set_output_cb(engine, NULL, NULL);
    clie_set_prompt_cb(engine, NULL, NULL);
    clie_set_input_cb(engine, NULL, NULL);
    return 0;
}

#define CLIE_RUN_GOTO(ret) do                                                        \
{                                                                                    \
    switch((ret))                                                                    \
    {                                                                                \
    case CLIE_CB_RET_GOTO_EXIT:                                                      \
        goto l_exit;                                                                 \
    case CLIE_CB_RET_GOTO_OUTPUT:                                                    \
        goto l_output;                                                               \
    case CLIE_CB_RET_GOTO_PROMPT:                                                    \
        goto l_prompt;                                                               \
    case CLIE_CB_RET_CONTINUE:                                                       \
        break;                                                                       \
    default:                                                                         \
        break;                                                                       \
    }                                                                                \
} while (0)

int clie_run(struct cli_engine *engine)
{
    clie_callback_ret ret;
    while (1)
    {
l_output:
        ret = CLIE_CB_RET_CONTINUE;
        if (engine->m_output_cb) 
        {
            ret = engine->m_output_cb(engine, engine->m_output_cb_user_data);  
        }  
        CLIE_RUN_GOTO(ret);
l_prompt:
        ret = CLIE_CB_RET_CONTINUE;
        if (engine->m_prompt_cb)
        {
            ret = engine->m_prompt_cb(engine, engine->m_prompt_cb_user_data);
        }
        CLIE_RUN_GOTO(ret);
        
        gets(engine->m_input_buf);
        if (engine->m_input_cb)
        {
            ret = engine->m_input_cb(engine, engine->m_input_buf, engine->m_input_cb_user_data);
        }
        CLIE_RUN_GOTO(ret);
    }

l_exit:

    return 0;
}

int clie_exit(struct cli_engine *engine)
{
    return 0;
}
/* call back setter */
int clie_set_output_cb(struct cli_engine *engine, 
                       clie_output_callback output_cb, 
                       void *user_data)
{
    engine->m_output_cb = output_cb;
    engine->m_output_cb_user_data = user_data;
    return 0;
}

int clie_set_prompt_cb(struct cli_engine *engine, 
                       clie_prompt_callback prompt_cb, 
                       void *user_data)
{
    engine->m_prompt_cb = prompt_cb;
    engine->m_prompt_cb_user_data = user_data;
    return 0;
}

int clie_set_input_cb(struct cli_engine *engine, 
                       clie_input_callback input_cb, 
                       void *user_data)
{
    engine->m_input_cb = input_cb;
    engine->m_input_cb_user_data = user_data;
    return 0;
}
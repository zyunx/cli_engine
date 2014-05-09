#ifndef __UNARY_CLOUD2HAN9_CLI_ENGINE_H__
#define __UNARY_CLOUD2HAN9_CLI_ENGINE_H__

/* Call back types */
typedef int clie_callback_ret;
typedef clie_callback_ret (*clie_output_callback)(struct cli_engine *engine, void *user_data);
typedef clie_callback_ret (*clie_prompt_callback)(struct cli_engine *engine, void *user_data);
typedef clie_callback_ret (*clie_input_callback)(struct cli_engine *engine, char *input_buf, void *user_data);

struct cli_engine
{
    /* configs, these field must be set before engine init. */
    int m_input_buf_size;
    //int m_prompt_buf_size;

    /* call back parameter */
    
    char *m_input_buf;
    //char *m_prompt_buf;

    /* callbacks */
    clie_output_callback m_output_cb;
    void *m_output_cb_user_data;

    clie_prompt_callback m_prompt_cb;
    void *m_prompt_cb_user_data;

    clie_input_callback m_input_cb;
    void *m_input_cb_user_data;
};


int clie_init(struct cli_engine *engine);
int clie_run(struct cli_engine *engine);
int clie_exit(struct cli_engine *engine);

/* cli engine life cycle :
 *
 *   init -> output -> prompt -> input  -> exit
 *           /  ^         ^        /         ^
            /    \         \      /           \
           /      +---------+----+             \
          /                                     \
         + --------------------------------------+
/* Call backs. Users of cli engine use call back */

#define CLIE_CB_RET_CONTINUE        0
#define CLIE_CB_RET_GOTO_OUTPUT     1
#define CLIE_CB_RET_GOTO_PROMPT     2
#define CLIE_CB_RET_GOTO_EXIT       3


/* call back setter */
int clie_set_output_cb(struct cli_engine *engine, 
                       clie_output_callback output_cb, 
                       void *user_data);

int clie_set_prompt_cb(struct cli_engine *engine, 
                       clie_prompt_callback prompt_cb, 
                       void *user_data);

int clie_set_input_cb(struct cli_engine *engine, 
                       clie_input_callback input_cb, 
                       void *user_data);

#endif
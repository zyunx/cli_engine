#ifndef __UNARY_CLOUD2HAN9_CLI_ENGINE_DEFAULT_H__
#define __UNARY_CLOUD2HAN9_CLI_ENGINE_DEFAULT_H__

#include "cli_engine.h"

#define CLIE_DEFAULT_INPUT_BUF_SIZE 256

int clie_default_set_config(struct cli_engine *engine);
clie_callback_ret clie_default_output_cb(struct cli_engine *engine, void *user_data);
clie_callback_ret clie_default_prompt_cb(struct cli_engine *engine, void *user_data);
clie_callback_ret clie_default_input_cb(struct cli_engine *engine, char *input_buf, void *user_data);


#endif
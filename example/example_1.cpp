#include "../cli_engine.h"
#include "../cli_engine_default.h"

#define NULL 0

int main()
{
    struct cli_engine e;
    clie_default_set_config(&e);

    clie_init(&e);

    clie_set_output_cb(&e, clie_default_output_cb, NULL);
    clie_set_prompt_cb(&e, clie_default_prompt_cb, NULL);
    clie_set_input_cb(&e, clie_default_input_cb, NULL);

    clie_run(&e);

    clie_exit(&e);
    return 0;
}
#include "../include/cli_app.h"

void greet_command(cli_t *cli, int argc, char **argv) {
    const char *name = cli_option_value(cli, "name");
    if (name) {
        printf("Olá, %s!\n", name);
    } else {
        printf("Olá!\n");
    }
}

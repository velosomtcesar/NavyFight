#include "../include/cli_app.h"

int main(int argc, char **argv) {
    cli_t *cli = cli_init("Exemplo CLI");

    cli_command(cli, "greet", greet_command, "Comando de saudação");
    cli_option(cli, "name", 'n', CLI_STRING, "Nome da pessoa a ser saudada");

    cli_parse(cli, argc, argv);
    cli_free(cli);

    return 0;
}

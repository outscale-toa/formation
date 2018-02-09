#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <glib.h>
#include <ctype.h>

int main(int argc, char **argv) {

    char msg[200]={'\0'};
    char *cmd1 = NULL;
    char *cmd = NULL;
    
    if (system("ponysay --help > /dev/null"))
	return -1;

    for (int i = 1; i < argc; i++) {
	strcat(msg, argv[i]);
	strcat(msg, " ");
    }
    cmd1 = g_strdup_printf("%s", msg);

    if (g_strrstr(cmd1, "hello") != NULL) {
	cmd = g_strdup_printf("ponysay -f lily Hello comment tu vas?");
	system(cmd);
    }
    if (g_strrstr(cmd1, "bonjour") != NULL) {
	cmd = g_strdup_printf("Bonjour comment tu vas?");
	system(cmd);
    }
    if (g_strrstr(cmd1, "bonsoir") != NULL) {
	cmd = g_strdup_printf("ponysay bonsoir comment tu vas?");
	system(cmd);
	}
    return 0;
}

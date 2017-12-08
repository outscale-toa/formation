#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include <glib.h>
#include <ctype.h>
#include<time.h>

void victoire(int val ) {
	char *cmd = NULL;

	if (system("ponysay --help > /dev/null") == 0) {
		cmd = g_strdup_printf ("ponysay BRAVO VOUS AVEZ TROUVER LE NOMBRE MAGIC: %d", val);
		system(cmd);
		g_free(cmd);
	} else if (system("cowsay --help > /dev/null") == 0) {
		cmd = g_strdup_printf ("cowsay BRAVO VOUS AVEZ TROUVER LE NOMBRE MAGIC: %d", val);
		system(cmd);
		g_free(cmd);
	}
}

bool verifier(int nb, int magic) {
	bool check = false;
	char *msg = NULL;
	
	if (nb == magic) {
		victoire(magic);
		check = true;
	} else if (nb < magic) {
		msg = g_strdup_printf ("\n\nponysay -f derpysad Plus grand que %d\n", nb);
		system(msg);
		system("sl");
		g_free(msg);
		check = false;
	} else if (nb > magic) {
		msg = g_strdup_printf ("\n\nponysay -f derpysad Plus petit que %d\n", nb);
		system(msg);
		g_free(msg);
		check = false;
	}
	return check;
}

int main() {
	int magic = 0;
	int nb = 'c';
	bool is_true = false;
	
	srand(time(NULL));
	magic = ((rand() % 100) + 1);
	system("clear");
	while(!is_true) {
		printf("\nQuel est le nombre magic: ");
		scanf("%d", &nb);
		is_true = verifier(nb, magic);
	}
	return 0;
}

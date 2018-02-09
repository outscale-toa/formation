#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <glib.h>
#include <ctype.h>

int main(int argc, char **argv) {

    /* boucle do ... while */
    int exit = 0;
    char nom;
    char *pony =NULL;

    if (system("ponysay --help > /dev/null"))
	    return -1;

    system("ponysay -f lily Connaissez vous un nom de pony?");

    do {
	printf("Reponse: ");
	scanf("%s", &nom);
	pony = g_strdup_printf("ponysay -f %s BAVO!!! tu es trop fort ", &nom);

	
	if (system(pony) == 0) {
	    printf("Voulez vous continuer (1->Oui/0->Non):");
	    scanf("%d", &exit);
	} else {
	    system("ponysay -f derpysad OHH NON!!! Tu peux faire mieux");
	}
	
	if (!exit) {
	    system("ponysay -f derpysad Au revoir");
	} else {
	    system("ponysay -f lily un autre nom de pony");
	}
    } while(exit);
     g_free(pony);
    return 0;
}

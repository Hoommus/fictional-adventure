#include <string.h>
#include <ctype.h>
#include <stdio.h>

int to_upper(void) {
	char str[1024];
	int i = 0;

	printf("Enter a string to capitalize:\n");
	scanf("%s", str);
	while (str[i]) {
		str[i] = toupper(str[i]);
		i++;
	}
	printf("%s\n", str);
}

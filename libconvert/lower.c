#include <string.h>
#include <ctype.h>
#include <stdio.h>

int to_lower(void) {
	char str[1024];
	int i = 0;

	printf("Enter a string to lowerize:\n");
	scanf("%s", str);
	while (str[i]) {
		str[i] = tolower(str[i]);
		i++;
	}
	printf("%s\n", str);
	return 0;
}

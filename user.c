#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
	char username[512];
	char password[512];
	printf("username: ");
	scanf("%s", username);
	printf("password: ");
	scanf("%s", password);

	FILE *fp;
	fp = fopen("passwd", "r");
	if (fp == NULL) {
		printf("failed to open passwd\n");
		return 1;
	}

	char target[512];
	sprintf(target, "%s:%s\n", username, password);
	char buf[512];
	while (fgets(buf, 512, fp) != NULL) {
		if (strcmp(buf, target) == 0) {
			printf("OK\n");
			return 0;
		}
	}
	printf("NG");
	return 0;
}

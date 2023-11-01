#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char filename[] = "test.txt";

    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error\n");
        return 1;
    }

    char **lines = NULL;
    char line[1000];
    int lineCount = 0;

    while (fgets(line, sizeof(line), file) != NULL) {

        char *newLine = (char *)malloc(strlen(line) + 1);
        strcpy(newLine, line);


        lines = (char **)realloc(lines, (lineCount + 1) * sizeof(char *));
        lines[lineCount] = newLine;
        lineCount++;
    }

    fclose(file);


    for (int i = lineCount - 1; i >= 0; i--) {
        printf("%s", lines[i]);
        free(lines[i]);
    }

    free(lines);

    return 0;
}


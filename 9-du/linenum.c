#include <stdio.h>

enum {
	ST_OK = 0,
	ST_WRONG_PARAMETERS = 1,
	ST_FOPEN_ERROR = 2
};

int main(int argc, char **argv)
{
	if (argc != 3) return ST_WRONG_PARAMETERS;

	FILE *in, *out;

	in = fopen(argv[1], "r");
	out = fopen(argv[2], "w");

	if (in == NULL || out == NULL) {
		if (in != NULL) fclose(in);
		if (out != NULL) fclose(out);

		return ST_FOPEN_ERROR;
	}

	int line = 1;
	int c;
	char first = 1;

	while ((c = fgetc(in)) != EOF) {

		if (!first) {
			fputc(c, out);

			if (c == '\n') {
				fprintf(out, "%05d ", line);
				line++;
			}
		} else {
			fprintf(out, "%05d %c", line, c);
			line++;
			first = 0;
		}

	}

	if (first) {
		fprintf(out, "%05d ", line);
	}

	fclose(in);
	fclose(out);

	return ST_OK;
}
#include "morse.h"

#include "tree.h"
#include "ptree.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int morse_checkArgs (int argc, char **argv, char **f_def_path, char **f_out_path, char *cmd, char *cmd_decode, char *f_out_d_path)
{
	switch (argc) {

		case 1:
			break;

		case 3:
			*f_def_path = argv[1];

			if (strcmp(argv[2], cmd_decode) == 0) {
				*cmd = 'd';
				*f_out_path = f_out_d_path;
			}

			break;

		default:
			fprintf(stderr, "error: invalid number of parameters\n");
			return RET_INVALID_PARAM_COUNT;

			break;

	}

	return RET_OK;
}

int morse_openFiles (FILE **f_def, char *f_def_path, char *f_def_opened, FILE **f_out, char *f_out_path, char *f_out_opened)
{
	*f_def = fopen(f_def_path, "r");
	if (*f_def == NULL) {
		fprintf(stderr, "error: could not open definition file '%s': %s (%d)\n", f_def_path, strerror(errno), errno);
		return RET_FOPEN_DEF_ERROR;
	} else {
		*f_def_opened = 'y';
	}

	*f_out = fopen(f_out_path ,"w");
	if (*f_out == NULL) {
		fprintf(stderr, "error: could not open output file '%s': %s (%d)\n", f_out_path, strerror(errno), errno);
		return RET_FOPEN_OUT_ERROR;
	} else {
		*f_out_opened = 'y';
	}

	return RET_OK;
}

int morse_loadDefinition (FILE *f_def, int line_size, Tree *t_encode, pTree *t_decode)
{
	int i;
	int i_alloc = line_size;

	int c = ' ';
	char index;
	char code[17];

	char *line, *nline = NULL;

	line = (char*)malloc(line_size * sizeof(char));
	if (line == NULL) {
		fprintf(stderr, "error: memory allocation error\n");
		return RET_MALLOC_ERROR;
	}

	while (c != EOF) {

		for (i=0; (c = fgetc(f_def)) != '\n'; i++) {
			if (c == EOF) break;

			line[i] = c;

			if (i >= i_alloc - 2) {
				nline = (char*)realloc(line, (i_alloc+line_size) * sizeof(char));
				if (nline == NULL) {
					fprintf(stderr, "error: memory allocation error\n");
					free(line);
					return RET_MALLOC_ERROR;
				}

				line = nline;
				i_alloc += line_size;
			}
		}

		line[i] = '\0';

		if (sscanf(line, "%c %s", &index, code) == 2) {
			if (index >= 'a' && index <= 'z') {
				index -= ('a' - 'A');
			}

			addItem(t_encode, index, code);
			addpItem(t_decode, index, (char*)code);
		}
	}

	free(line);

	return RET_OK;
}

int morse_encode (FILE *f_out, Tree *t_encode)
{
	int c = ' ';

	int prev = '\0';
	char *code_s = NULL;
	char c_upper;
	char word_started = 0;

	while ( (c = getchar()) != EOF ) {

		if (c == '\n') {

			fputc('\n', f_out);
			word_started = 0;

		} else if (c == ' ') {

			if (prev != ' ') {
				fprintf(f_out, "/");

				if (word_started == 0) {
					fprintf(f_out, "/");
				}
			}

			word_started = 0;

		} else {

			c_upper = c;
			if (c >= 'a' && c <= 'z') {
				c_upper -=  ('a' - 'A');
			}

			code_s = findData(t_encode, c_upper);
			if (code_s == NULL) {
				fprintf(stderr, "error: can not encode character '%c'\n", c);
			} else {
				fprintf(f_out, "%s/", code_s);
				word_started = 1;
			}

		}


		prev = c;
	}

	return RET_OK;
}

int morse_decode (FILE *f_out, pTree *t_decode, int line_size, char left, char right)
{
	char *line, *nline = NULL;

	line = (char*)malloc(line_size * sizeof(char));
	if (line == NULL) {
		fprintf(stderr, "error: memory allocation error\n");
		return RET_MALLOC_ERROR;
	}

	char index = ' ';
	int c = ' ';
	int i_alloc = line_size;
	char prev_slash = 1;
	int i;

	while (c != EOF) {

		for (i=0; (c = getchar()) != '/'; ) {
			if (c == EOF) break;

			if (c == '\n') break;

			if (c == left || c == right) {
				line[i] = c;
				i++;
			}

			if (i >= i_alloc - 2) {
				nline = (char*)realloc(line, (i_alloc+line_size) * sizeof(char));
				if (nline == NULL) {
					fprintf(stderr, "error: memory allocation error\n");
					free(line);
					return RET_MALLOC_ERROR;
				}

				line = nline;
				i_alloc += line_size;
			}

		}

		line[i] = '\0';

		if (i != 0) {

			index = indexByPrefix(t_decode, line);
			if (index >= 0) {
				fputc(index, f_out);
			} else {
				fprintf(stderr, "error: can not decode sequence '%s'\n", line);
			}
			prev_slash = 0;

		} else if (i == 0 && c == '/') {

			if (prev_slash == 0) {
				fputc(' ', f_out);
				prev_slash = 1;
			} else {
				prev_slash = 0;
			}

		}

		if (c == '\n') {
			fputc('\n' ,f_out);
			prev_slash = 1;
		}

	}

	free(line);

	return RET_OK;
}
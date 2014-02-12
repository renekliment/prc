#include <stdio.h>

#include "tree.h"
#include "ptree.h"

#include "morse.h"

int ascii_comparator (const void *f, const void *s)
{
	char a = * ( (char*)f );
	char b = * ( (char*)s );

	if (a < b) {
		return -1;
	} else if (a > b) {
		return 1;
	}

	return 0;
}

int main (int argc, char **argv)
{
	int return_code = RET_OK;

	//char cmd_encode[] = "encode";
	char cmd_decode[] = "decode";

	char cmd = 'e'; // 'd' means decode, 'e' means encode

	char f_def_path_default[] = "morse.def";
	char *f_def_path = (char*)&f_def_path_default;

	char f_out_e_path[] = "encoded.txt";
	char f_out_d_path[] = "decoded.txt";
	char *f_out_path = (char*)&f_out_e_path;

	char left = '.';
	char right = '-';

	Tree t_encode;
	pTree t_decode;

	initializeTree(&t_encode, ascii_comparator);
	initializepTree(&t_decode, ascii_comparator);
	setBinaryPrefix(&t_decode, left, right);

	FILE *f_def = NULL;
	FILE *f_out = NULL;

	char f_def_opened = 0;
	char f_out_opened = 0;

	int line_size = 24;

	// check app arguments and if necessary sets some variables accordingly
	return_code = morse_checkArgs(argc, argv, &f_def_path, &f_out_path, &cmd, cmd_decode, f_out_d_path);
	if (return_code != RET_OK) goto cleanup;

	// opens definition and output files
	return_code = morse_openFiles(&f_def, f_def_path, &f_def_opened, &f_out, f_out_path, &f_out_opened);
	if (return_code != RET_OK) goto cleanup;

	// loads the definition from a file into the trees
	return_code = morse_loadDefinition(f_def, line_size, &t_encode, &t_decode);
	if (return_code != RET_OK) goto cleanup;

	// runs either encoding or decoding based on user's choice
	if (cmd == 'e') {

		return_code = morse_encode(f_out, &t_encode);
		if (return_code != RET_OK) goto cleanup;

	} else {

		return_code = morse_decode(f_out, &t_decode, line_size, left, right);
		if (return_code != RET_OK) goto cleanup;

	}

	goto cleanup;

	// cleans up the mess after a party
	cleanup:

		if (f_def_opened) fclose(f_def);
		if (f_out_opened) fclose(f_out);

		delTree(&t_encode);
		delpTree(&t_decode);

		putchar('\n');

		return return_code;
}
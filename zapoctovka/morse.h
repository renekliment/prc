#ifndef _MORSE_H_
#define _MORSE_H_

#include <stdio.h>

#include "tree.h"
#include "ptree.h"

enum returnCodes {
	RET_OK = 0,
	RET_INVALID_PARAM_COUNT = -1,
	RET_FOPEN_DEF_ERROR = -2,
	RET_FOPEN_OUT_ERROR = -3,
	RET_MALLOC_ERROR = -4,
	RET_INVALID_FUNCTION_PARAMS = -5,
};


int morse_checkArgs (int argc, char **argv, char **f_def_path, char **f_out_path, char *cmd, char *cmd_decode, char *f_out_d_path);

int morse_openFiles (FILE **f_def, char *f_def_path, char *f_def_opened, FILE **f_out, char *f_out_path, char *f_out_opened);

int morse_loadDefinition (FILE *f_def, int line_size, Tree *t_encode, pTree *t_decode);

int morse_encode (FILE *f_out, Tree *t_encode);

int morse_decode (FILE *f_out, pTree *t_decode, int line_size, char left, char right);

#endif
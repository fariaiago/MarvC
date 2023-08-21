#ifndef MARVC_ARGUMENTS_H
#define MARVC_ARGUMENTS_H

#include <concord/types.h>
#include <stddef.h>
#include <stdbool.h>

#define ARG_CAP 16
#define ARG_DELIM_DEFAULT " "

struct ArgsVector
{
	int len;
	char *data[ARG_CAP];
};

/**
 * Inserts an argument into an ArgsVecotr
*/
bool add_arg(struct ArgsVector *, char *);

/**
 * Separates a string into tokens and puts them on an ArgsVector
*/
bool tokenize(struct ArgsVector *, char *);

void get_snowflake(char *, u64snowflake *);

#endif
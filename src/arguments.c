#include "arguments.h"
#include <stdio.h>
#include <string.h>

bool add_arg(struct ArgsVector *args, char *arg)
{
	if(!args || !arg)
	{
		return false;
	}
	args->data[args->len] = arg;
	args->len++;
	return true;
}

bool tokenize(struct ArgsVector *args, char *str)
{
	if(!args || !str)
	{
		return false;
	}
	char *token = strtok(str, ARG_DELIM_DEFAULT);
	while (token)
	{
		add_arg(args, token);
		token = strtok(NULL, ARG_DELIM_DEFAULT);
		if(args->len >= ARG_CAP)
		{
			return false;
		}
	}
	return true;
}

void get_snowflake(char *og, u64snowflake *u64)
{
	char sub[20];
	sub[19] = '\0';
	memcpy(sub, &og[2], 19);
	sscanf(sub, "%lu", u64);
}
#include "commands.h"
#include <concord/discord.h>
#include <stdio.h>
#include <stdlib.h>

#define CMD_PREFIX "->"

int main(int argc, char *argv[])
{
	if(argc < 2)
	{
		return -1;
	}
	srand(time(NULL));
	ccord_global_init();
	
	struct discord *client = discord_init(argv[1]);
	
	discord_add_intents(client, DISCORD_GATEWAY_MESSAGE_CONTENT | DISCORD_GATEWAY_GUILD_MEMBERS);
	discord_set_prefix(client, CMD_PREFIX);

	discord_set_on_command(client, PING_CMD_NAME, &on_ping);
	discord_set_on_command(client, PICK_CMD_NAME, &on_pick);
	discord_set_on_command(client, MUTE_CMD_NAME, &on_mute);
	discord_set_on_command(client, UNMUTE_CMD_NAME, &on_unmute);
	
	discord_run(client);
	
	discord_cleanup(client);
	ccord_global_cleanup();

	return 0;
}
#include <concord/discord.h>
#include <stdio.h>
#include <string.h>

#define GUILD_ID 1

void setup_commands(struct discord *client, const struct discord_ready *event)
{
	struct discord_create_guild_application_command command = {
		.name = "ping",
		.description = "Ping pong command"
	};
	discord_create_guild_application_command(client, event->application->id,
			GUILD_ID, &command, NULL);
}

void on_interaction(struct discord *client, const struct discord_interaction *event)
{
	if(event->type != DISCORD_INTERACTION_APPLICATION_COMMAND)
		return;
	
	if(strcmp(event->data->name, "ping") == 0)
	{
		struct discord_interaction_response response = {
			.type = DISCORD_INTERACTION_CHANNEL_MESSAGE_WITH_SOURCE,
			.data = &(struct discord_interaction_callback_data){
				.content = "pong"
			}
		};
		discord_create_interaction_response(client, event->id, event->token,
				&response, NULL);
	}
}

int main(int argc, char *argv[])
{
	if(argc < 2)
		return -1;
	struct discord *client = discord_init(argv[1]);
	discord_add_intents(client, DISCORD_GATEWAY_MESSAGE_CONTENT);
	discord_set_on_ready(client, &setup_commands);
	discord_set_on_interaction_create(client, &on_interaction);
	discord_run(client);
	discord_cleanup(client);
	return 0;
}
#include "commands.h"
#include "arguments.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SILENCIADO_ROLE_ID 1138854775002239087

void on_ping(struct discord *client, const struct discord_message *event)
{
	struct discord_create_message msg = { .content = "Pong!"};
	discord_create_message(client, event->channel_id, &msg, NULL);
}

void on_pick(struct discord *client, const struct discord_message *event)
{
	struct ArgsVector args = {0};
	tokenize(&args, event->content);
	struct discord_create_message msg = { .content = args.data[rand() % args.len] };
	discord_create_message(client, event->channel_id, &msg, NULL);
}

void on_tempmute(struct discord *client, const struct discord_message *event)
{}

void on_tempban(struct discord *client, const struct discord_message *event)
{}

void on_mute(struct discord *client, const struct discord_message *event)
{
	struct ArgsVector args = {0};
	tokenize(&args, event->content);
	u64snowflake target_id = 0;
	get_snowflake(args.data[0], &target_id);
	struct discord_add_guild_member_role role = {.reason = "Bruh!", };
	discord_add_guild_member_role(client, event->guild_id, target_id, SILENCIADO_ROLE_ID, &role, NULL);
}

void on_unmute(struct discord *client, const struct discord_message *event)
{
	struct ArgsVector args = {0};
	tokenize(&args, event->content);
	u64snowflake target_id = 0;
	get_snowflake(args.data[0], &target_id);
	struct discord_remove_guild_member_role role = {.reason = "Bruh!", };
	discord_remove_guild_member_role(client, event->guild_id, target_id, SILENCIADO_ROLE_ID, &role, NULL);
}

void on_kick(struct discord *client, const struct discord_message *event)
{}

void on_ban(struct discord *client, const struct discord_message *event)
{}

void on_unban(struct discord *client, const struct discord_message *event)
{
	struct ArgsVector args = {0};
	tokenize(&args, event->content);
	u64snowflake target_id = 0;
	get_snowflake(args.data[0], &target_id);
	struct discord_add_guild_member_role role = {.reason = "Bruh!", };
	discord_add_guild_member_role(client, event->guild_id, target_id, SILENCIADO_ROLE_ID, &role, NULL);
}
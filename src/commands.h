#ifndef MARVC_COMMANDS_H
#define MARVC_COMMANDS_H

#include <concord/discord.h>

#define PING_CMD_NAME "ping"
#define PICK_CMD_NAME "pick"
#define MUTE_CMD_NAME "mute"
#define UNMUTE_CMD_NAME "unmute"

/**
 * Replies "ping" with pong
*/
void on_ping(struct discord *, const struct discord_message *);

void on_pick(struct discord *, const struct discord_message *);

void on_tempmute(struct discord *, const struct discord_message *);

void on_tempban(struct discord *, const struct discord_message *);

void on_mute(struct discord *, const struct discord_message *);

void on_unmute(struct discord *, const struct discord_message *);

void on_kick(struct discord *, const struct discord_message *);

void on_ban(struct discord *, const struct discord_message *);

void on_unban(struct discord *, const struct discord_message *);

#endif
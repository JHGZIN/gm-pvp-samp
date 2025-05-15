//#define ID_GUILD "1229603889926635620"
#define ANTCHEATCHANNEL_ID  "1365569769667035136"

stock DCC_SendEmbedViridian(DCC_Channel:channel, const title[], const description[]) {
    new DCC_Embed:embed; embed = DCC_Embed:DCC_CreateEmbed(title);
    DCC_SetEmbedDescription(embed, description);
    DCC_SendChannelEmbedMessage(channel, embed);
    return true;
}

stock DCC_SendEmbedAntCheat(DCC_Channel:channel, const title[], const description[], skin) {
    new DCC_Embed:embed; embed = DCC_Embed:DCC_CreateEmbed(title);
    DCC_SetEmbedDescription(embed, description);
    DCC_SetEmbedThumbnail(embed, va_return("https://assets.open.mp/assets/images/skins/%d.png", skin));
    DCC_SetEmbedColor(embed, 0x0080C0);
    DCC_SendChannelEmbedMessage(channel, embed);
    return true;
}
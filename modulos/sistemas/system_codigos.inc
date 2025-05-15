enum eCodigo {
    c_Tipo[16],
    c_Valor,
    c_Dias,
    c_Resgatado
};

new g_CodigoTemp[MAX_PLAYERS][eCodigo];
new gString[256];

function OnResgatarCodigo(playerid, const code[]) {
    if (cache_num_rows() == 0) return SendClientMessage(playerid, -1, "Código inválido ou não encontrado.");

    new tipo[16];
    cache_get_value_name(0, "tipo", tipo);
    cache_get_value_name_int(0, "valor", g_CodigoTemp[playerid][c_Valor]);
    cache_get_value_name_int(0, "dias", g_CodigoTemp[playerid][c_Dias]);
    cache_get_value_name_int(0, "resgatado", g_CodigoTemp[playerid][c_Resgatado]);
    format(g_CodigoTemp[playerid][c_Tipo], 16, "%s", tipo);

    if (g_CodigoTemp[playerid][c_Resgatado] == 1) {
        return SendClientMessage(playerid, -1, "Esse código já foi resgatado.");
    }

    if (strcmp(g_CodigoTemp[playerid][c_Tipo], "vip", true) == 0) {
        format(gString, sizeof gString, "Voce resgatou um codigo de VIP de %d dias!", g_CodigoTemp[playerid][c_Dias]);
        SendClientMessage(playerid, -1, gString);
    } else if (strcmp(g_CodigoTemp[playerid][c_Tipo], "coins", true) == 0) {
        format(gString, sizeof gString, "Voce resgatou %d coins!", g_CodigoTemp[playerid][c_Valor]);
        SendClientMessage(playerid, -1, gString);
        g_PlayerData[playerid][g_Coins] = g_CodigoTemp[playerid][c_Valor];
    }

    new query[128];
    mysql_format(DBConn, query, sizeof query, "UPDATE `codigos` SET `resgatado` = 1 WHERE `codigo` = '%e'", code);
    mysql_tquery(DBConn, query);
    return 1;
}

function MostrarCodigosValidos(playerid){
    new rows = cache_num_rows();
    
    if (rows == 0)
        return SendClientMessage(playerid, -1, "[INFO] Nenhum codigo valido foi encontrado.");

    new str[1024], linha[128];

    strcat(str, "{00FF00}Top 10 Codigos válidos:\n\n");
    
    for (new i = 0; i < rows; i++)
    {
        new codigo[64], tipo[16], valor, dias;
        cache_get_value_name(i, "codigo", codigo);
        cache_get_value_name(i, "tipo", tipo);
        cache_get_value_name_int(i, "valor", valor);
        cache_get_value_name_int(i, "dias", dias);

        if (strcmp(tipo, "vip") == 0)
            format(linha, sizeof linha, "{FFFFFF}Codigo: {00FF00}%s\n{FFFFFF}Tipo: {FFFF00}VIP - %d dias\n\n", codigo, dias);
        else
            format(linha, sizeof linha, "{FFFFFF}Codigo: {00FF00}%s\n{FFFFFF}Tipo: {FFFF00}Coins - %d\n\n", codigo, valor);

        strcat(str, linha);
    }

    ShowPlayerDialog(playerid, D_NULL, DIALOG_STYLE_MSGBOX, "Codigos Válidos (Top 10)", str, "Fechar", "");
    return 1;
}

CMD:gcodigo(playerid, params[]) {
    if(g_PlayerData[playerid][g_Admin] < 5)
        return SendClientMessage(playerid, COR_GERAL, MSGERRO);

    new tipo[8], valor, dias = 0;
    if (sscanf(params, "s[8]iI(0)", tipo, valor, dias)) {
        SendClientMessage(playerid, -1, "Use: /gerarcodigo [vip/coins] [valor] (dias - se for VIP)");
        return 1;
    }

    if (!(strcmp(tipo, "vip", true) == 0 || strcmp(tipo, "coins", true) == 0)) {
        return SendClientMessage(playerid, -1, "Tipo invalido! Use 'vip' ou 'coins'.");
    }

    new codigo[32], letra;
    for (new i = 0; i < 12; i++) {
        letra = random(36); // 0-9 + A-Z
        if (letra < 10) codigo[i] = '0' + letra;
        else codigo[i] = 'A' + (letra - 10);
    }
    codigo[4] = '-';
    codigo[9] = '-';
    codigo[13] = '\0';

    new query[256];
    mysql_format(DBConn, query, sizeof query, "INSERT INTO `codigos` (codigo, tipo, valor, dias) VALUES ('%e', '%e', %d, %d)", codigo, tipo, valor, dias);
    mysql_tquery(DBConn, query);

    format(gString, sizeof gString, "Codigo gerado: %s (Tipo: %s | Valor: %d | Dias: %d)", codigo, tipo, valor, dias);
    SendClientMessage(playerid, -1, gString);
    return 1;
}

CMD:vercodigos(playerid){
    if(g_PlayerData[playerid][g_Admin] < 5)
        return SendClientMessage(playerid, COR_GERAL, MSGERRO);

    mysql_tquery(DBConn, "SELECT * FROM codigos WHERE resgatado = 0 LIMIT 10", "MostrarCodigosValidos", "i", playerid);
    return 1;
}
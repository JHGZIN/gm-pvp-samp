
//===ceres===//
#define VERMELHO 0xFF0000AA
#define AMARELO 0xFFFF00AA
#define VERDE 0x00FF00AA
#define ASUL 0x0080FFAA
#define ROSA 0xFF00FFAA
#define PRETO 0x000000AA
#define BRANCO 0xFFFFFFAA
#define LILAZ 0x8000FFAA
#define LARANGA 0xFF8000AA
#define MAROM 0x804000AA

#define Vaga_Aureola1       20
#define Vaga_Aureola2       21

#define COLOR_LIGHTGREEN 0x24FF0AB9
#define SPEEDUPDATE 250 // <100 can make lag >500 doesn't looks good

#define SlotAKeFUZIL 1
#define SlotEscopeta 2

#define PRESSED(%0) (((newkeys & (%0)) == (%0)) && ((oldkeys & (%0)) != (%0)))

//native SendClientCheck(playerid, type, arg, offset, size);
forward OnClientCheckResponse(playerid, type, arg, response);
forward UmSegundo();
#define IsPlayerAndroid(%0)      GetPVarInt(%0, "NotAndroid") == 0

#define Amarelo  0xEBFF00AA

#define SERVER_MAX_PLAYERS 50

#define varGet(%0)      getproperty(0,%0)
#define varSet(%0,%1)   setproperty(0, %0, %1)
#define new_strcmp(%0,%1) \
                (varSet(%0, 1), varGet(%1) == varSet(%0, 0))

/* | => Defines/Variaveis Servidor Chavin <= | */
#define VIRIDIAN::%0(%1) 		forward %0(%1);\
							public %0(%1)

#define COLOR_GRAD1             0xCAFF70AA
#define COLOR_GRAD2             0xFFF68FFF

#define    COLOR_CHAVIN            0xFFF68FAA
#define    COLOR_CHAVINRED         0xEE3B3BAA
#define    COLOR_CHAVIN2		   0x1E90FFAA
#define    COLOR_REDD		  	   0xFF3030AA

#define    COLOR_CHAVIN2		   0x1E90FFAA

#define COR_ANUNCIO1		   COR_TOALL1
#define COR_ANUNCIO2           COR_TOALL2
#define COR_TOALL1 "{FF0000}"
#define COR_TOALL2 "{FF3030}"

#define COR_AZULFORTE			   0x436EEEAA
#define COR_PLATINA 			   0x7FFFD4FF
#define COR_CARRO 				   0xFFC1C1AA
#define COR_ERRO 				   0xFF6A6AAA
#define MSG_USE 				   0xFFF68FFF
#define COR_GERAL 				   0xCAFF70FF
#define COR_LILAS 				   0x4876FFAA
#define COR_MONEY				   0x32CD32AA
#define COR_MONEYEX				   0x00CD00AA
#define COR_HELPER			       0x00FF7FAA

#define MSGERRO          "[ERRO]: Comando invalido."
#define MSGJOGAR         "{FF6A6A}[ERRO]:{FAFAD2} Voce nao pode usar esse comando modo jogo, use: (/jogar)"

#define SCM 				SendClientMessage
#define Dialog 				ShowPlayerDialog

#define DCMD_PREFIX '!' //Prefixo bot (OBS: 1 caractere somente)
#define PREFIX_MSG  "!"  //Prefix q aparece na msg
#define STATUS_BOT INVISIBLE

#define function%0(%1) forward%0(%1);public%0(%1)

#define AV_MAX_STRING 2048

#define MAX_PASS_LEN (65)
#define SALT_LEN (13)

#define ConvertDays(%0) (gettime() + (86400 * (%0)))

#define SERVER_VERSION "v1.0"

#define DIALOG_CREDITOS \
	"{007DFB}Creditos VIRIDIAN PvP\n\n" \
	"{FFFFFF}- Fundador e Dono Geral: NITY.\n" \
	"{FFFFFF}Desenvolvido por: AstroVille Group.\n" \
	"{FFFFFF}- Mapeacoes, Designer: AstroVille Group.\n" \
	"{FFFFFF}VIRIDIAN PvP todos os direitos reservados.\n" \
	"{FFFFFF}- Para mais informacoes, visite nossa aba de Apresentacao.\n" \
	"{FFFFFF}no discord atraves do link abaixo ou em nosso site.\n" \
    "{FFFFFF}- Discord: https://discord.gg/viridianpvp"
    
#define DIALOG_LOJACOIN \
    "{007DFB}[1] {FFFFFF}- {007DFB}Vips\n" \
    "{007DFB}[2] {FFFFFF}- {007DFB}Familia\n" \
    "{007DFB}[3] {FFFFFF}- {007DFB}Resgatar Codigo"

#define DIALOG_LOJAVIP \
    "{007DFB}VIP NORMAL{FFFFFF}\n" \
    "{007DFB}VIP RUBI{FFFFFF}\n" \
    "{007DFB}VIP GOLDEN{FFFFFF}"

#define DIALOG_FAMILIA \
   "{007DFB}Comprar Familia | {EEEE00}20c"
  

#define DIALOG_VIPNORMAL \
    "{007DFB}VIP NORMAL {FFFFFF}(30 dias){FFFFFF} | {EEEE00}10c\n" \
    "{007DFB}VIP NORMAL {FFFFFF}(60 dias){FFFFFF} | {EEEE00}20c\n" \
    "{007DFB}VIP NORMAL {FFFFFF}(1 ano){FFFFFF} | {EEEE00}30c"

#define DIALOG_VIPRUBI \
    "{007DFB}VIP RUBI {FFFFFF}(30 dias){FFFFFF} | {EEEE00}40c\n" \
    "{007DFB}VIP RUBI {FFFFFF}(60 dias){FFFFFF} | {EEEE00}50c\n" \
    "{007DFB}VIP RUBI {FFFFFF}(1 ano){FFFFFF} | {EEEE00}60c"

#define DIALOG_VIPGOLDEN \
    "{007DFB}VIP GOLDEN {FFFFFF}(30 dias){FFFFFF} | {EEEE00}70c\n" \
    "{007DFB}VIP GOLDEN {FFFFFF}(60 dias){FFFFFF} | {EEEE00}80c\n" \
    "{007DFB}VIP GOLDEN {FFFFFF}(1 ano){FFFFFF} | {EEEE00}90c"

enum {
    UNDFINED,
    TIMEAZUL,
    TIMEVERMELHO
}

enum pSalaData {
    g_SalaId,
    g_NameSala[23],
    g_PasswordSala,
    g_QtdPlayerSala,
    g_QtdPlayer,
    g_QtdRouds,
    g_MaxRouds,
    g_QualModo,
    g_WeaponId,
    g_MunicaoWeapon,
    g_ArenaId,
    
    g_MaxPlayerTime[2],
    g_QtdRoudsGanhos[2],
    g_MinutosSala,
    g_SegundosSala,
    g_JogadoresNesseTime[2],
    g_JogadoresMorto[2],

    bool:g_SalaTemNome,
    bool:g_SalaCriada,
    g_TimerSala
}
new g_SalaData[MAX_PLAYERS][pSalaData];

new g_JogadorId[MAX_PLAYERS][4][2];
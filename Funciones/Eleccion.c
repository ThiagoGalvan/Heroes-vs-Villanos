void eleccion(){
    int heroe, enemigo;

    switch(heroe) {
        case 1: stats_Batman(); break;
        case 2: stats_Superman(); break;
        case 3: stats_Flash(); break;
        case 4: stats_FlechaVerde(); break;
        case 5: stats_Aquaman(); break;
        case 6: stats_Shazam(); break;
        case 7: stats_Joker(); break;
        case 8: stats_LexLuthor(); break;
        case 9: stats_FlashReverso(); break;
        case 10: stats_Deathstroke(); break;
        case 11: stats_MantaNegra(); break;
        case 12: stats_BlackAdam(); break;
        default: printf("Estadísticas del personaje no implementadas.\n");
    }
}

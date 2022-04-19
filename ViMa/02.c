#pragma once
#include "01.c"

typedef struct{
    bool 
        neghah_daashtane_mouse,
        neghah_daashtane_ctrl;
    SDL_Point makaane_mouse;
}KelidHaa;

typedef struct{
    SDL_Window *panjare;
    SDL_Renderer *safhe;
    SDL_Event ruydaad;
    SDL_Rect mogheiat;
    //طول و عرض تقسیم بر پنجاه
    SDL_Point andaaze_bar_50;
    KelidHaa kelid_haa;
    char *masire_barnaame;
}RaabeteKaarbari;

typedef struct{
    Uint16 *horuf;
    size_t 
        andaaze, 
        aakharin;
}Matn;

typedef struct{
    SDL_Texture *nemaa;

    //طول و عرض
    SDL_Point andaaze;
}Vaazhe;

typedef struct{
    SDL_Rect mogheiat;
    Sint64 shomaare_harf;
}MakaanNemaa;

typedef struct{
    SDL_Color range_matn;
    SDL_Point 
        makaane_vaazhe_avval,
        makaane_vaazhe_aakhar;
    int andaaze_dastkhat;
    MakaanNemaa makaan_nemaa;
    TTF_Font *dastkhat;
    //مجموعه ای از تصویر هر واژه
    Vaazhe vaazhe[140];
    char *masire_dastkhat;
}Nemaa;

typedef struct{
    Matn matn;
    Nemaa nemaa;
}Neveshtaar;

typedef struct{
    SDL_Color 
        range_zir,
        range_ru;
    SDL_Rect 
        zir,
        ru;
    bool entekhaab_shode;
}NavaareHarekat;


typedef struct{
    RaabeteKaarbari RaaKaa;
    Neveshtaar neveshtaar;
    NavaareHarekat navaar;
}ViraayeshgareMatn;

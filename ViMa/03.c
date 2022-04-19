#pragma once
#include "02.c"



void TaineMogheiat(SDL_Rect *mogheiat, int x, int y, int tul, int arz){
    mogheiat->x = x;
    mogheiat->y = y;
    mogheiat->w = tul;
    mogheiat->h = arz;
}

void Eslaahe_MasireBarnaame(char *MasireBarnaame){
    for (size_t i = 0; MasireBarnaame[i] != 0; i++)
    {
        if (MasireBarnaame[i] == '\\' )
        {
            MasireBarnaame[i] = '/';
        }
    }
}

void RaaKaa_Besaaz(RaabeteKaarbari *RaaKaa){
    RaaKaa->masire_barnaame = SDL_GetBasePath(); Eslaahe_MasireBarnaame(RaaKaa->masire_barnaame);
    TaineMogheiat(&RaaKaa->mogheiat, 1000, 200, 800, 800);
    RaaKaa->panjare = SDL_CreateWindow("ViMa_05", RaaKaa->mogheiat.x, RaaKaa->mogheiat.y, RaaKaa->mogheiat.w, RaaKaa->mogheiat.h, SDL_WINDOW_RESIZABLE);
    RaaKaa->safhe = SDL_CreateRenderer(RaaKaa->panjare, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_TARGETTEXTURE);
    RaaKaa->andaaze_bar_50.x = RaaKaa->mogheiat.w / 50;
    RaaKaa->andaaze_bar_50.y = RaaKaa->mogheiat.h / 50;
    RaaKaa->kelid_haa.neghah_daashtane_ctrl = false;
}

void MakaanNemaa_Besaaz(MakaanNemaa *makaan_nemaa, SDL_Point *makaane_vaazhe_avval, int andaaze_dastkhat){
    makaan_nemaa->mogheiat.w = andaaze_dastkhat / 20;
    makaan_nemaa->mogheiat.h = andaaze_dastkhat;
    makaan_nemaa->mogheiat.x = makaane_vaazhe_avval->x - makaan_nemaa->mogheiat.w;
    makaan_nemaa->mogheiat.y = makaane_vaazhe_avval->y;
    makaan_nemaa->shomaare_harf = -1;
}

void Matn_Besaaz(Matn *matn){
    matn->horuf = malloc( sizeof(Uint16) * 1024 );
    matn->andaaze = 1024; matn->aakharin = 0;
}

void NemaaYeVaazhegaan_Besaaz(Nemaa *nemaa, SDL_Renderer *safhe){
    //میتونی از 0 برای پایان متن استفاده کنی
    Uint16 shomaare_vaazhe[] = {
    //0
    65167, 65168, 65169, 65170, //be
    64342, 64343, 64344, 64345, //pe 
    65173, 65174, 65175, 65176, //te
    65177, 65178, 65179, 65180, //the
    65181, 65182, 65183, 65184, //jim
    64378, 64379, 64380, 64381, //che
    65185, 65186, 65187, 65188, //he
    65189, 65190, 65191, 65192, //khe
    65201, 65202, 65203, 65204, //sin
    65205, 65206, 65207, 65208, //shin
    65209, 65210, 65211, 65212, //saad
    65213, 65214, 65215, 65216, //zaad
    65217, 65218, 65219, 65220, //taa
    65221, 65222, 65223, 65224, //zaa
    65225, 65226, 65227, 65228, //ayn
    65229, 65230, 65231, 65232, //ghayn
    65233, 65234, 65235, 65236, //fe
    65237, 65238, 65239, 65240, //ghaaf
    64398, 64399, 64400, 64401, //kaaf
    64402, 64403, 64404, 64405, //gaaf   
    65245, 65246, 65247, 65248, //laam
    65249, 65250, 65251, 65252, //mim
    65253, 65254, 65255, 65256, //nun
    65257, 65258, 65259, 65260, //he
    64508, 64509, 65267, 65268, //ye

    //100
    65165, 65166, //alef
    65193, 65194, //daal
    65195, 65196, //zaal
    65197, 65198, //re
    65199, 65200, //ze
    64394, 64395, //zhe
    65261, 65262, //vaav

    //114
    32, //faasele
    65153, //aa
    41, // (
    40, // )
    58, // :
    1776, 1777, 1778, 1779, 1780, 1781, 1782, 1783, 1784, 1785, //0, 1, 2, 3, 4, 5, 6, 7, 8, 9
    46, //noghte
    1548, //virgul 

    //131
    1611, 1612, 1613, 1614, 1615, 1616, // an, on, en, a, o, e
    1617, // tashdid
    
    //138
    29, //null _ khaali
    13, //alaamat zade nashode
    };

    for(int i = 0; i < 139; i++){
        SDL_Surface *surface = TTF_RenderGlyph_Blended(nemaa->dastkhat, shomaare_vaazhe[i], nemaa->range_matn);
        nemaa->vaazhe[i].nemaa = SDL_CreateTextureFromSurface(safhe, surface);
        SDL_QueryTexture(nemaa->vaazhe[i].nemaa, NULL, NULL, &nemaa->vaazhe[i].andaaze.x, &nemaa->vaazhe[i].andaaze.y);
    }
}




void NavaareHarekat_Besaaz(NavaareHarekat *navaar, RaabeteKaarbari *RaaKaa){
    navaar->range_zir.r = 50; 
    navaar->range_zir.g = 50; 
    navaar->range_zir.b = 50; 
    navaar->range_zir.a = 255;

    navaar->range_ru.r = 100; 
    navaar->range_ru.g = 100; 
    navaar->range_ru.b = 100; 
    navaar->range_ru.a = 255;

    navaar->zir.x = RaaKaa->mogheiat.w - RaaKaa->andaaze_bar_50.x; 
    navaar->zir.y = 0; 
    navaar->zir.w = RaaKaa->andaaze_bar_50.x; 
    navaar->zir.h = RaaKaa->mogheiat.h;

    navaar->ru.x = RaaKaa->mogheiat.w - RaaKaa->andaaze_bar_50.x; 
    navaar->ru.y = 0; 
    navaar->ru.w = RaaKaa->andaaze_bar_50.x; 
    navaar->ru.h = RaaKaa->andaaze_bar_50.y * 4;

    navaar->entekhaab_shode = false;
}

void Nemaa_Besaaz(Nemaa *nemaa, RaabeteKaarbari *RaaKaa, NavaareHarekat *navaar){
    nemaa->range_matn.r = 255;
    nemaa->range_matn.g = 255;
    nemaa->range_matn.b = 255;
    nemaa->range_matn.a = 255;

    nemaa->makaane_vaazhe_avval.x = navaar->zir.x - (RaaKaa->andaaze_bar_50.x / 2);
    nemaa->makaane_vaazhe_avval.y = RaaKaa->andaaze_bar_50.y;
    nemaa->andaaze_dastkhat = 50;

    MakaanNemaa_Besaaz(&nemaa->makaan_nemaa, &nemaa->makaane_vaazhe_avval, nemaa->andaaze_dastkhat);
    nemaa->masire_dastkhat = ""; strcat(nemaa->masire_dastkhat, RaaKaa->masire_barnaame); strcat(nemaa->masire_dastkhat, "1/dastkhat.ttf");
    nemaa->dastkhat = TTF_OpenFont(nemaa->masire_dastkhat, nemaa->andaaze_dastkhat);
    NemaaYeVaazhegaan_Besaaz(nemaa, RaaKaa->safhe);
    TTF_CloseFont(nemaa->dastkhat);
}

void NemaaYeVaazhegaan_Bazsaazi(Nemaa *nemaa, RaabeteKaarbari *RaaKaa){
    nemaa->dastkhat = TTF_OpenFont(nemaa->masire_dastkhat, nemaa->andaaze_dastkhat);
    NemaaYeVaazhegaan_Besaaz(nemaa, RaaKaa->safhe);
    nemaa->makaan_nemaa.mogheiat.w = nemaa->andaaze_dastkhat / 20;
    nemaa->makaan_nemaa.mogheiat.h = nemaa->andaaze_dastkhat;
    TTF_CloseFont(nemaa->dastkhat);
}

void Neveshtaar_Besaaz(Neveshtaar *neveshtaar, RaabeteKaarbari *RaaKaa, NavaareHarekat *navaar){
    Matn_Besaaz(&neveshtaar->matn);
    Nemaa_Besaaz(&neveshtaar->nemaa, RaaKaa, navaar);
}

void ViMa_Besaaz(ViraayeshgareMatn *ViMa){
    RaaKaa_Besaaz(&ViMa->RaaKaa);
    NavaareHarekat_Besaaz(&ViMa->navaar, &ViMa->RaaKaa);
    Neveshtaar_Besaaz(&ViMa->neveshtaar, &ViMa->RaaKaa, &ViMa->navaar);
}
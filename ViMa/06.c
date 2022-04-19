#pragma once
#include "05.c"



void Navaar_EntekhaabShode(NavaareHarekat *navaar, SDL_Point *makaane_mouse){
    if 
    (
        makaane_mouse->x > navaar->ru.x && makaane_mouse->x < navaar->ru.x + navaar->ru.w
        &&
        makaane_mouse->y > navaar->ru.y && makaane_mouse->y < navaar->ru.y + navaar->ru.h
    )
    {
        navaar->entekhaab_shode = true;
    }
}

//با کشیدن موس حرکت میکند
void Navaar_Tazesaazi_1(ViraayeshgareMatn *ViMa){
    SDL_Point *makaane_mouse = &ViMa->RaaKaa.kelid_haa.makaane_mouse;
    SDL_Point *makaane_vaazhe_avval = &ViMa->neveshtaar.nemaa.makaane_vaazhe_avval;
    SDL_Point *makaane_vaazhe_aakhar = &ViMa->neveshtaar.nemaa.makaane_vaazhe_aakhar;
    NavaareHarekat *navaar = &ViMa->navaar;
    switch (navaar->entekhaab_shode)
    {
    case true:
    
        if 
        ( 
            makaane_mouse->y > navaar->ru.h / 2 && makaane_mouse->y < ViMa->RaaKaa.mogheiat.h - (navaar->ru.h / 2)
        )
        {
            navaar->ru.y = makaane_mouse->y - (navaar->ru.h / 2);
            int faasele = (makaane_vaazhe_aakhar->y - makaane_vaazhe_avval->y);
            int ghadam = -(faasele / (navaar->zir.h - navaar->ru.h ));
            int makaan = ghadam * navaar->ru.y;
            //printf("___navaar->ru.y %d\n",navaar->ru.y);
            //printf("faasele %d\nghadam %d\nmakaan %d\n",faasele, ghadam,makaan);
            makaane_vaazhe_avval->y = makaan;
            ViMa_Tazesaazi(ViMa);
        }
        break;
    }
}

//با جرخش موس حرکت میکند
void Navaar_Tazesaazi_2(ViraayeshgareMatn *ViMa, Sint8 jahat){
    SDL_Point *makaane_vaazhe_avval = &ViMa->neveshtaar.nemaa.makaane_vaazhe_avval;
    SDL_Point *makaane_vaazhe_aakhar = &ViMa->neveshtaar.nemaa.makaane_vaazhe_aakhar;
    NavaareHarekat *navaar = &ViMa->navaar;
    
        printf("___navaar->ru.y %d\n",navaar->ru.y);
        printf("navaar->zir.h - navaar->ru.y %d\n",navaar->zir.h - navaar->ru.y);
    if 
    ( 
        navaar->ru.y >= 0 && jahat == -1
        ||
        navaar->ru.y < navaar->zir.h - navaar->ru.h && jahat == 1
    )
    {
        navaar->ru.y += jahat;
        int faasele = (makaane_vaazhe_aakhar->y - makaane_vaazhe_avval->y);
        int ghadam = -(faasele / (navaar->zir.h - navaar->ru.h ));
        int makaan = ghadam * navaar->ru.y;
        makaane_vaazhe_avval->y = makaan;
        ViMa_Tazesaazi(ViMa);
            
    }
}

void HazfHarf(Matn *matn, MakaanNemaa *makaan_nemaa){
    if (matn->andaaze > 1024 && matn->aakharin < matn->andaaze / 4)
    {
        matn->horuf = realloc(matn->horuf, (matn->andaaze / 2) * sizeof(Uint16));
        matn->andaaze /= 2;
    }
    
    if (makaan_nemaa->shomaare_harf >= 0) 
    { 
        for (Uint64 i = makaan_nemaa->shomaare_harf; i < matn->aakharin; i++)
        { 
            matn->horuf[i] = matn->horuf[i + 1]; 
        }
        makaan_nemaa->shomaare_harf -= 1;
        if (matn->aakharin > 0) 
        { 
            matn->aakharin -= 1; 
        }
    }

}















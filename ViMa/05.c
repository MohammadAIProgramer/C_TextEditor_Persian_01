#pragma once
#include "04.c"


void MakaanNemaa_Bekesh(MakaanNemaa *makaan_nemaa, SDL_Renderer *safhe){
    SDL_SetRenderDrawColor(safhe, 150, 150, 150, 255);
    SDL_RenderFillRect(safhe, &makaan_nemaa->mogheiat);
}

void Neveshtaar_Bekesh(Neveshtaar *neveshtaar, RaabeteKaarbari *RaaKaa){

    //در آخر مکان واژه آخر را ذخیره میکنیم
    //neveshtaar->nemaa.makaane_vaazhe_aakhar = neveshtaar->nemaa.makaane_vaazhe_avval;
    Vaazhe *bargozide;
    neveshtaar->nemaa.makaane_vaazhe_aakhar = neveshtaar->nemaa.makaane_vaazhe_avval;
    SDL_Rect mogheiat_vaazhe_aakhar = {
        .x = neveshtaar->nemaa.makaane_vaazhe_aakhar.x,
        .y = neveshtaar->nemaa.makaane_vaazhe_aakhar.y
    };

        if (neveshtaar->nemaa.makaan_nemaa.shomaare_harf < 0)
        {
            neveshtaar->nemaa.makaan_nemaa.mogheiat.x = neveshtaar->nemaa.makaane_vaazhe_avval.x;
            neveshtaar->nemaa.makaan_nemaa.mogheiat.y = neveshtaar->nemaa.makaane_vaazhe_avval.y;
        }

    int ghadam_badi;
    Uint8 ettesaal;
    Uint16 
        shomaare_nemaad,
        shomaare_nemaade_harfe_ghabli = 114, //faasele
        shomaare_nemaade_harfe_badi;

    for (size_t i = 0; i < neveshtaar->matn.aakharin; i++)
    {

        ettesaal = 0; ghadam_badi = 0;
        shomaare_nemaad = TabdileMatnBeNemaad(neveshtaar->matn.horuf[i]); 
        do{ ghadam_badi += 1;
            shomaare_nemaade_harfe_badi = TabdileMatnBeNemaad(neveshtaar->matn.horuf[i + ghadam_badi]);
        }while(shomaare_nemaade_harfe_badi < 138 &&  shomaare_nemaade_harfe_badi > 130); //اگر اعراب است

        if (shomaare_nemaad < 100)//اگر از دو طرف قابل اتصال بود
        {
            if (shomaare_nemaade_harfe_ghabli < 100)//اگر از قبل متصل میشود
            { ettesaal += 1; }
            
            if(shomaare_nemaade_harfe_badi < 114)//اگر از بعد متصل میشود
            { ettesaal += 2; }
        }
        else if(shomaare_nemaad < 114)//اگر از قبل قابل اتصال بود
        {
            if (shomaare_nemaade_harfe_ghabli < 100)//اگر از قبل متصل میشود
            { ettesaal += 1; }
        }
        
        bargozide = &neveshtaar->nemaa.vaazhe[shomaare_nemaad + ettesaal];
        mogheiat_vaazhe_aakhar.w = bargozide->andaaze.x;
        mogheiat_vaazhe_aakhar.h = bargozide->andaaze.y;

        
        switch (neveshtaar->matn.horuf[i])
        {
        case 2573:
            mogheiat_vaazhe_aakhar.x = neveshtaar->nemaa.makaane_vaazhe_avval.x;
            mogheiat_vaazhe_aakhar.y += neveshtaar->nemaa.andaaze_dastkhat;
            shomaare_nemaade_harfe_ghabli = shomaare_nemaad;
            if (neveshtaar->nemaa.makaan_nemaa.shomaare_harf == i)
            {
                neveshtaar->nemaa.makaan_nemaa.mogheiat.x = mogheiat_vaazhe_aakhar.x;
                neveshtaar->nemaa.makaan_nemaa.mogheiat.y = mogheiat_vaazhe_aakhar.y;
            }
            neveshtaar->nemaa.makaane_vaazhe_aakhar.x = mogheiat_vaazhe_aakhar.x;
            neveshtaar->nemaa.makaane_vaazhe_aakhar.y = mogheiat_vaazhe_aakhar.y;
            continue;
            break;

        case 35801://an
                mogheiat_vaazhe_aakhar.y -= neveshtaar->nemaa.andaaze_dastkhat / 4;
                mogheiat_vaazhe_aakhar.x = neveshtaar->nemaa.makaane_vaazhe_aakhar.x - (mogheiat_vaazhe_aakhar.w / 2);
            break;
            
        case 36057://on
                mogheiat_vaazhe_aakhar.y -= neveshtaar->nemaa.andaaze_dastkhat / 4;
                mogheiat_vaazhe_aakhar.x = neveshtaar->nemaa.makaane_vaazhe_aakhar.x - (mogheiat_vaazhe_aakhar.w / 2);
            break;
            
        case 36313://en
        
            break;
            
        case 36569://a
                mogheiat_vaazhe_aakhar.y -= neveshtaar->nemaa.andaaze_dastkhat / 4;
                mogheiat_vaazhe_aakhar.x = neveshtaar->nemaa.makaane_vaazhe_aakhar.x - (mogheiat_vaazhe_aakhar.w / 2);
            break;
            
        case 36825://o
                mogheiat_vaazhe_aakhar.y -= neveshtaar->nemaa.andaaze_dastkhat / 4;
                mogheiat_vaazhe_aakhar.x = neveshtaar->nemaa.makaane_vaazhe_aakhar.x - (mogheiat_vaazhe_aakhar.w / 2);
            break;
            
        case 37081://e
        
            break;
            
        case 37337://tashdid
                mogheiat_vaazhe_aakhar.x = neveshtaar->nemaa.makaane_vaazhe_aakhar.x - (mogheiat_vaazhe_aakhar.w / 2);
            break;
            
            default:
                mogheiat_vaazhe_aakhar.x = neveshtaar->nemaa.makaane_vaazhe_aakhar.x - mogheiat_vaazhe_aakhar.w;
                mogheiat_vaazhe_aakhar.y = neveshtaar->nemaa.makaane_vaazhe_aakhar.y;
                if (mogheiat_vaazhe_aakhar.x < 0)
                {
                    mogheiat_vaazhe_aakhar.x = neveshtaar->nemaa.makaane_vaazhe_avval.x - mogheiat_vaazhe_aakhar.w;
                    mogheiat_vaazhe_aakhar.y += mogheiat_vaazhe_aakhar.h;
                }
                neveshtaar->nemaa.makaane_vaazhe_aakhar.x = mogheiat_vaazhe_aakhar.x;
                neveshtaar->nemaa.makaane_vaazhe_aakhar.y = mogheiat_vaazhe_aakhar.y;
                shomaare_nemaade_harfe_ghabli = shomaare_nemaad;

                if (neveshtaar->nemaa.makaan_nemaa.shomaare_harf == i)
                {
                    neveshtaar->nemaa.makaan_nemaa.mogheiat.x = mogheiat_vaazhe_aakhar.x;
                    neveshtaar->nemaa.makaan_nemaa.mogheiat.y = mogheiat_vaazhe_aakhar.y;
                }
            break;
        }
        
        /*
        //تعین مکانِ نمای واژه روی صفحه
        if (shomaare_nemaad < 131 || shomaare_nemaad > 137) //اعراب نیست
        {
            mogheiat_vaazhe_aakhar.x = neveshtaar->nemaa.makaane_vaazhe_aakhar.x - mogheiat_vaazhe_aakhar.w;
            mogheiat_vaazhe_aakhar.y = neveshtaar->nemaa.makaane_vaazhe_aakhar.y;
            if (mogheiat_vaazhe_aakhar.x < 0)
            {
                mogheiat_vaazhe_aakhar.x = neveshtaar->nemaa.makaane_vaazhe_avval.x - mogheiat_vaazhe_aakhar.w;
                mogheiat_vaazhe_aakhar.y += mogheiat_vaazhe_aakhar.h;
            }
            neveshtaar->nemaa.makaane_vaazhe_aakhar.x = mogheiat_vaazhe_aakhar.x;
            neveshtaar->nemaa.makaane_vaazhe_aakhar.y = mogheiat_vaazhe_aakhar.y;
            shomaare_nemaade_harfe_ghabli = shomaare_nemaad;

            if (neveshtaar->nemaa.makaan_nemaa.shomaare_harf == i)
            {
                neveshtaar->nemaa.makaan_nemaa.mogheiat.x = mogheiat_vaazhe_aakhar.x;
                neveshtaar->nemaa.makaan_nemaa.mogheiat.y = mogheiat_vaazhe_aakhar.y;
            }
        }
        else 
        {
            if (shomaare_nemaad == 133 || shomaare_nemaad == 136)//این  ِ یا  ٍ است
            { }
            else if (shomaare_nemaad < 137) //اعراب است(تشدید و  ِ و  ٍ نیست)
            {
                
                mogheiat_vaazhe_aakhar.y -= neveshtaar->nemaa.andaaze_dastkhat / 4;
                mogheiat_vaazhe_aakhar.x = neveshtaar->nemaa.makaane_vaazhe_aakhar.x - (mogheiat_vaazhe_aakhar.w / 2);
            }
            else if (shomaare_nemaad == 137) //تشدید است
            {
                mogheiat_vaazhe_aakhar.x = neveshtaar->nemaa.makaane_vaazhe_aakhar.x - (mogheiat_vaazhe_aakhar.w / 2);
            }
        }
        */

        if (mogheiat_vaazhe_aakhar.y > -bargozide->andaaze.y && mogheiat_vaazhe_aakhar.y < RaaKaa->mogheiat.h)
        {
            SDL_RenderCopy(RaaKaa->safhe, bargozide->nemaa, NULL, &mogheiat_vaazhe_aakhar);
        }
        
    }
}


void Navaar_Bekesh(NavaareHarekat *navaar, SDL_Renderer *safhe){
    SDL_SetRenderDrawColor(safhe, navaar->range_zir.r, navaar->range_zir.g, navaar->range_zir.b, navaar->range_zir.a);
    SDL_RenderFillRect(safhe, &navaar->zir);
    SDL_SetRenderDrawColor(safhe, navaar->range_ru.r, navaar->range_ru.g, navaar->range_ru.b, navaar->range_ru.a);
    SDL_RenderFillRect(safhe, &navaar->ru);
}

void ViMa_Tazesaazi(ViraayeshgareMatn *ViMa){
    SDL_SetRenderDrawColor(ViMa->RaaKaa.safhe, 0, 0, 0, 255);
    SDL_RenderClear(ViMa->RaaKaa.safhe);
    Neveshtaar_Bekesh(&ViMa->neveshtaar, &ViMa->RaaKaa);
    Navaar_Bekesh(&ViMa->navaar, ViMa->RaaKaa.safhe);
    MakaanNemaa_Bekesh(&ViMa->neveshtaar.nemaa.makaan_nemaa, ViMa->RaaKaa.safhe);
    SDL_RenderPresent(ViMa->RaaKaa.safhe);
}

void AndaazeJadid_Bekesh(ViraayeshgareMatn *ViMa){
    
    SDL_GetWindowSize(ViMa->RaaKaa.panjare, &ViMa->RaaKaa.mogheiat.w, &ViMa->RaaKaa.mogheiat.h);
    NavaareHarekat_Besaaz(&ViMa->navaar, &ViMa->RaaKaa);
    ViMa->neveshtaar.nemaa.makaane_vaazhe_avval.x = ViMa->navaar.zir.x - (ViMa->RaaKaa.andaaze_bar_50.x / 2);
    ViMa_Tazesaazi(ViMa);
}
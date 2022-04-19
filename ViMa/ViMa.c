#pragma once
#include "06.c"


void ViraayeshgareMatn_Shoru(char *argv){
    SDL_Init(SDL_INIT_VIDEO); TTF_Init();
    ViraayeshgareMatn ViMa;
    ViMa_Besaaz(&ViMa);
    //SDL_SetWindowOpacity(ViMa.RaaKaa.panjare, 0.9f);

    //SDL_SetRenderDrawBlendMode(ViMa.RaaKaa.safhe, SDL_BLENDMODE_BLEND);
    SDL_SetRenderDrawColor(ViMa.RaaKaa.safhe, 0, 0, 0, 255);//SDL_ALPHA_OPAQUE
    SDL_RenderClear(ViMa.RaaKaa.safhe);
    Navaar_Bekesh(&ViMa.navaar, ViMa.RaaKaa.safhe);
    SDL_RenderPresent(ViMa.RaaKaa.safhe);
    
    //نوستن متن ذخیره شده
    unsigned char vaazhe[2];
    SDL_RWops *f1 = SDL_RWFromFile(argv,"r");
    Sint64 tul = SDL_RWsize(f1);
    for (size_t i = 0; i < tul/2; i++)
    {
        SDL_RWread(f1,vaazhe,1,2);
        AfzudaneVaazhe( &ViMa.neveshtaar.matn, vaazhe[0] | (vaazhe[1]<<8), &ViMa.neveshtaar.nemaa.makaan_nemaa);
        ViMa.neveshtaar.nemaa.makaan_nemaa.shomaare_harf += 1;
    }
    SDL_RWclose(f1);
    ViMa_Tazesaazi(&ViMa);
    

    bool charkhesh = true;
    while (charkhesh)
    {

        if (SDL_PollEvent(&ViMa.RaaKaa.ruydaad))
        {
            SDL_GetMouseState(&ViMa.RaaKaa.kelid_haa.makaane_mouse.x, &ViMa.RaaKaa.kelid_haa.makaane_mouse.y);

            switch (ViMa.RaaKaa.ruydaad.type){ 

                case SDL_QUIT: charkhesh = false; break; 

                case SDL_TEXTINPUT: 

                    unsigned char *vaazhe = ViMa.RaaKaa.ruydaad.text.text;
                    AfzudaneVaazhe( &ViMa.neveshtaar.matn, vaazhe[0] | (vaazhe[1]<<8), &ViMa.neveshtaar.nemaa.makaan_nemaa);
                    ViMa.neveshtaar.nemaa.makaan_nemaa.shomaare_harf += 1;
                    ViMa_Tazesaazi(&ViMa);
                    break;

                case SDL_MOUSEBUTTONDOWN:
                    ViMa.RaaKaa.kelid_haa.neghah_daashtane_mouse = true;
                    Navaar_EntekhaabShode(&ViMa.navaar, &ViMa.RaaKaa.kelid_haa.makaane_mouse);
                    break;

                case SDL_MOUSEBUTTONUP:
                    ViMa.RaaKaa.kelid_haa.neghah_daashtane_mouse = false;
                    ViMa.navaar.entekhaab_shode = false;
                    break;

                case SDL_MOUSEWHEEL:
                    //printf("MW\n");
                    if (ViMa.RaaKaa.kelid_haa.neghah_daashtane_ctrl)
                    {
                        if (ViMa.RaaKaa.ruydaad.wheel.y > 0)
                        {
                            if (ViMa.neveshtaar.nemaa.andaaze_dastkhat < ViMa.RaaKaa.mogheiat.w / 4)
                            {
                                ViMa.neveshtaar.nemaa.andaaze_dastkhat += ViMa.RaaKaa.andaaze_bar_50.x;
                                NemaaYeVaazhegaan_Bazsaazi(&ViMa.neveshtaar.nemaa, &ViMa.RaaKaa);
                            }
                        }
                        else if (ViMa.RaaKaa.ruydaad.wheel.y < 0)
                        {
                            if (ViMa.neveshtaar.nemaa.andaaze_dastkhat > ViMa.RaaKaa.andaaze_bar_50.x)
                            {
                                ViMa.neveshtaar.nemaa.andaaze_dastkhat -= ViMa.RaaKaa.andaaze_bar_50.x;
                                NemaaYeVaazhegaan_Bazsaazi(&ViMa.neveshtaar.nemaa, &ViMa.RaaKaa);
                            }
                        }
                    }else if (ViMa.RaaKaa.ruydaad.wheel.y > 0)
                    {
                        Navaar_Tazesaazi_2(&ViMa, -1);
                    }
                    else if (ViMa.RaaKaa.ruydaad.wheel.y < 0)
                    {
                        Navaar_Tazesaazi_2(&ViMa, 1);
                    }

                    break;

                case SDL_KEYDOWN:
                    switch (ViMa.RaaKaa.ruydaad.key.keysym.scancode)
                    {
                        case SDL_SCANCODE_RIGHT:
                            if (ViMa.neveshtaar.nemaa.makaan_nemaa.shomaare_harf >= 0)
                            { ViMa.neveshtaar.nemaa.makaan_nemaa.shomaare_harf -= 1; }
                            break;
                        case SDL_SCANCODE_LEFT:
                            if (ViMa.neveshtaar.nemaa.makaan_nemaa.shomaare_harf < (Sint64)ViMa.neveshtaar.matn.aakharin - 1)
                            { ViMa.neveshtaar.nemaa.makaan_nemaa.shomaare_harf += 1; }
                            break;
                        case SDL_SCANCODE_BACKSPACE:
                            HazfHarf(&ViMa.neveshtaar.matn, &ViMa.neveshtaar.nemaa.makaan_nemaa);
                            break;
                        case SDL_SCANCODE_LCTRL:
                            ViMa.RaaKaa.kelid_haa.neghah_daashtane_ctrl = true;
                            break;
                        case SDL_SCANCODE_RCTRL:
                            ViMa.RaaKaa.kelid_haa.neghah_daashtane_ctrl = true;
                            break;
                        case SDL_SCANCODE_S:
                            if (ViMa.RaaKaa.kelid_haa.neghah_daashtane_ctrl)
                            {
                                //ذخیره کردن داده کنونی
                                SDL_RWops *f1 = SDL_RWFromFile(argv,"w");
                                SDL_RWwrite(f1,ViMa.neveshtaar.matn.horuf,2,ViMa.neveshtaar.matn.aakharin);
                                SDL_RWclose(f1);
                                ViMa_Tazesaazi(&ViMa);
                            }
                            break;
                        case SDL_SCANCODE_RETURN:
                            AfzudaneVaazhe( &ViMa.neveshtaar.matn, 2573, &ViMa.neveshtaar.nemaa.makaan_nemaa);
                            ViMa.neveshtaar.nemaa.makaan_nemaa.shomaare_harf += 1;
                            ViMa_Tazesaazi(&ViMa);

                            break;
                    }
                    ViMa_Tazesaazi(&ViMa);
                    break;

                case SDL_KEYUP:
                    switch (ViMa.RaaKaa.ruydaad.key.keysym.scancode)
                    {
                        case SDL_SCANCODE_LCTRL:
                            ViMa.RaaKaa.kelid_haa.neghah_daashtane_ctrl = false;
                            break;
                        case SDL_SCANCODE_RCTRL:
                            ViMa.RaaKaa.kelid_haa.neghah_daashtane_ctrl = false;
                            break;
                    }
                    break;

                case SDL_WINDOWEVENT:
                        switch (ViMa.RaaKaa.ruydaad.window.event) 
                        { case SDL_WINDOWEVENT_RESIZED: AndaazeJadid_Bekesh(&ViMa); break; } 
                        
                        break;

                case 1024: break;

                default : SDL_Delay(2); continue; break;
                
            }

            Navaar_Tazesaazi_1(&ViMa);
        }
        SDL_Delay(3);
    }
    
    
    TTF_Quit();
    SDL_Quit();
}
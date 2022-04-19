#pragma once
#include "03.c"



AfzudaneVaazhe(Matn *matn, Uint16 vaazhe, MakaanNemaa *makaan_nemaa){
    if (matn->andaaze <= matn->aakharin)
    {
        matn->horuf = realloc(matn->horuf, 2 * matn->andaaze * sizeof(Uint16));
        matn->andaaze *= 2;
    }
    matn->aakharin += 1;
    
    Uint16 
        bezaar = vaazhe,
        negahdaar;
    for (Uint64 i = makaan_nemaa->shomaare_harf + 1; i < matn->aakharin; i++)
    {
        negahdaar = matn->horuf[i];
        matn->horuf[i] = bezaar;
        bezaar = negahdaar;
    }

}


Uint16 TabdileMatnBeNemaad(Uint16 matn){
    switch (matn)
    {
    case 43224: return 0; break; //be
    case 48857: return 4; break; //pe
    case 43736: return 8; break; //te
    case 43992: return 12; break; //the
    case 44248: return 16; break; //jim
    case 34522: return 20; break; //che
    case 44504: return 24; break; //he
    case 44760: return 28; break; //khe
    case 46040: return 32; break; //sin
    case 46296: return 36; break; //shin
    case 46552: return 40; break; //saad
    case 46808: return 44; break; //zaad
    case 47064: return 48; break; //taa
    case 47320: return 52; break; //zaa
    case 47576: return 56; break; //ayn
    case 47832: return 60; break; //ghayn
    case 33241: return 64; break; //fe
    case 33497: return 68; break; //ghaaf
    case 43482: return 72; break; //kaaf
    case 45018: return 76; break; //gaaf
    case 34009: return 80; break; //laam
    case 34265: return 84; break; //mim
    case 34521: return 88; break; //nun
    case 34777: return 92; break; //he
    case 36059: return 96; break; //ye

    case 42968: return 100; break; //alef
    case 45016: return 102; break; //daal
    case 45272: return 104; break; //zaal
    case 45528: return 106; break; //re
    case 45784: return 108; break; //ze
    case 39130: return 110; break; //zhe
    case 35033: return 112; break; //vaav

    case 32: return 114; break; //faasele
    case 41688: return 115; break; //aa
    case 40: return 116; break; // )
    case 41: return 117; break; // (
    case 58: return 118; break; // :
    case 48: return 119; break; //0
    case 49: return 120; break; //1
    case 50: return 121; break; //2
    case 51: return 122; break; //3
    case 52: return 123; break; //4
    case 53: return 124; break; //5
    case 54: return 125; break; //6
    case 55: return 126; break; //7
    case 56: return 127; break; //8
    case 57: return 128; break; //9
    case 46: return 129; break; //noghte
    case 36056: return 130; break; //virgul
    case 35801: return 131; break; //an
    case 36057: return 132; break; //on
    case 36313: return 133; break; //en
    case 36569: return 134; break; //a
    case 36825: return 135; break; //o
    case 37081: return 136; break; //e
    case 37337: return 137; break; //tashdid

    default: return 138; break;
    }
}


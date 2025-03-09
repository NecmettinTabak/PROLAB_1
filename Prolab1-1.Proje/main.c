#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <curl/curl.h>
#include <SDL2/SDL.h>

#define GRID_SIZE 20
#define CELL_SIZE 30
#define IMAGE_SIZE 150
#define IMAGE_SPACING 20
#define TOP_IMAGE_WIDTH 200
#define TOP_IMAGE_HEIGHT 130

void izgaraCiz(SDL_Renderer* renderer, int offsetX, int offsetY) {
    SDL_SetRenderDrawColor(renderer, 169, 169, 169, 255);
    SDL_Rect gridBackground = { offsetX, offsetY, GRID_SIZE * CELL_SIZE, GRID_SIZE * CELL_SIZE };
    SDL_RenderFillRect(renderer, &gridBackground);

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    for (int i = 0; i <= GRID_SIZE; ++i) {
        SDL_RenderDrawLine(renderer, offsetX, offsetY + i * CELL_SIZE, offsetX + GRID_SIZE * CELL_SIZE, offsetY + i * CELL_SIZE); // Yatay çizgiler
        SDL_RenderDrawLine(renderer, offsetX + i * CELL_SIZE, offsetY, offsetX + i * CELL_SIZE, offsetY + GRID_SIZE * CELL_SIZE); // Dikey çizgiler
    }
}

void canBarCiz(SDL_Renderer* renderer, int x, int y, int health, int max_health)
{
    float health_percentage = (float)health / max_health;
    int bar_width = CELL_SIZE;
    int health_width = (int)(bar_width * health_percentage);

    SDL_Rect backgroundRect = {x, y + CELL_SIZE, bar_width, 5};
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderFillRect(renderer, &backgroundRect);

    SDL_Rect healthRect = {x, y + CELL_SIZE, health_width, 5};
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    SDL_RenderFillRect(renderer, &healthRect);
}
struct Bulunankahraman
{
    char bulunan1[50];
};
struct Bulunanarastirma
{
    char arastirmaisim[50];
    int seviye;
};
struct Bulunancanavar
{
    char bulunan1[50];
};
struct Askerler
{
    float saldiri;
    float savunma;
    float saglik;
    float kritsans;
};
struct Birimler
{
    float suvarisayi;
    float okcusayi;
    float piyadesayi;
    float kusatma_m_sayi;
    float orkdovuscu;
    float  mizrakci;
    float vargbinici;
    float troller;
};
struct Kahramanlar
{
    int etki_miktari;
    char etkiledigi_birim[100];
    char etkiledigi_ozellik[30];
};
struct Canavarlar
{
    int etki_miktari;
    char etkiledigi_birim[100];
    char etkiledigi_ozellik[30];
};
struct Arastirma
{
    int etki_miktari;
    char etkiledigi_birim[100];
    char etkiledigi_ozellik[30];
};
struct insan_imp
{
    struct Birimler birimler;
    struct Askerler piyade;
    struct Askerler okcu;
    struct Askerler suvari;
    struct Askerler kusatma_makine;
    struct Kahramanlar alparslan;
    struct Kahramanlar fatih_sultan_mehmet;
    struct Kahramanlar yavuz_sultan_selim;
    struct Kahramanlar tugrul_bey;
    struct Kahramanlar mete_han;
    struct Canavarlar ejderha;
    struct Canavarlar agri_dagi_devleri;
    struct Canavarlar tepegoz;
    struct Canavarlar karakurt;
    struct Canavarlar samur;
    struct Arastirma savunma_ustaligi_1;
    struct Arastirma savunma_ustaligi_2;
    struct Arastirma savunma_ustaligi_3;
    struct Arastirma saldiri_gelistirmesi_1;
    struct Arastirma saldiri_gelistirmesi_2;
    struct Arastirma saldiri_gelistirmesi_3;
    struct Arastirma elit_egitim_1;
    struct Arastirma elit_egitim_2;
    struct Arastirma elit_egitim_3;
    struct Arastirma kusatma_ustaligi_1;
    struct Arastirma kusatma_ustaligi_2;
    struct Arastirma kusatma_ustaligi_3;
    struct Bulunankahraman bulunankahraman;
    struct Bulunancanavar bulunancanavar;
    struct Bulunanarastirma bulunanarastirma;
};
struct ork_imp
{
    struct Askerler ork_dovuscu;
    struct Askerler mizrakci;
    struct Askerler varg_binici;
    struct Askerler troller;
    struct Kahramanlar goruk_vahsi;
    struct Kahramanlar thruk_kemikkiran;
    struct Kahramanlar vrog_kafakiran;
    struct Kahramanlar ugar_zalim;
    struct Canavarlar kara_troll;
    struct Canavarlar golge_kurtlari;
    struct Canavarlar camur_devleri;
    struct Canavarlar ates_iblisi;
    struct Canavarlar makrog_savas_beyi;
    struct Canavarlar buz_devleri;
    struct Arastirma savunma_ustaligi_1;
    struct Arastirma savunma_ustaligi_2;
    struct Arastirma savunma_ustaligi_3;
    struct Arastirma saldiri_gelistirmesi_1;
    struct Arastirma saldiri_gelistirmesi_2;
    struct Arastirma saldiri_gelistirmesi_3;
    struct Arastirma elit_egitim_1;
    struct Arastirma elit_egitim_2;
    struct Arastirma elit_egitim_3;
    struct Arastirma kusatma_ustaligi_1;
    struct Arastirma kusatma_ustaligi_2;
    struct Arastirma kusatma_ustaligi_3;
    struct Birimler birimler2;
    struct Bulunankahraman bulunankahraman;
    struct Bulunancanavar bulunancanavar;
    struct Bulunanarastirma bulunanarastirma;
};
void Kahraman_ata(FILE *dospoi2,struct Kahramanlar *kahraman)
{
    char dizim2[500];
    while (fgets(dizim2,sizeof(dizim2),dospoi2))
    {
        if (strstr(dizim2,"}"))
        {
            break;
        }
        if (strstr(dizim2,"\"bonus_turu\""))
        {
            char *metin=strchr(dizim2,':')+1;
            char *baslangic = strchr(metin, '\"');
            char *bitis = strrchr(metin, '\"');
            if (baslangic != NULL && bitis != NULL )
            {
                baslangic++;
                *bitis = '\0';
            }
            strcpy(kahraman->etkiledigi_ozellik,baslangic);
        }
        if (strstr(dizim2,"\"bonus_degeri\""))
        {
            char *metin2=strchr(dizim2,':')+1;
            char x,y,z;
            int deger;
            sscanf(metin2,"%c%c%d%c",&x,&y,&deger,&z);
            kahraman->etki_miktari=deger;
        }
        if (strstr(dizim2,"\"aciklama\""))
        {
            char *metin3=strchr(dizim2,':')+3;
            char birim[30];
            sscanf(metin3,"%s",&birim);

            if (birim[0]=='p')
            {
                strcpy(kahraman->etkiledigi_birim,"piyade");

            }
            if (birim[0]=='o')
            {
                strcpy(kahraman->etkiledigi_birim,"okcu");

            }
            if (birim[0]=='s')
            {
                strcpy(kahraman->etkiledigi_birim,"suvari");

            }
            if (birim[0]=='k')
            {
                strcpy(kahraman->etkiledigi_birim,"kusatma_makine");

            }
            if (birim[0]=='o' && birim[1]=='r')
            {
                strcpy(kahraman->etkiledigi_birim,"ork_dovuscu");

            }
            if (birim[0]=='m')
            {
                strcpy(kahraman->etkiledigi_birim,"mizrakci");

            }
            if (birim[0]=='v')
            {
                strcpy(kahraman->etkiledigi_birim,"varg_binici");

            }
            if (birim[0]=='t')
            {
                strcpy(kahraman->etkiledigi_birim,"troller");

            }
            if (birim[0]=='t' && birim[1]=='u')
            {
                strcpy(kahraman->etkiledigi_birim,"tum_birimler");

            }

        }
    }
}
void Canavar_ata(FILE *dospoi3,struct Canavarlar *canavar)
{
    char dizim3[500];
    while (fgets(dizim3,sizeof(dizim3),dospoi3))
    {
        if (strstr(dizim3,"}"))
        {
            break;
        }
        if (strstr(dizim3,"\"etki_turu\""))
        {
            char *metin=strchr(dizim3,':')+1;

            char *baslangic = strchr(metin, '\"');
            char *bitis = strrchr(metin, '\"');

            if (baslangic != NULL && bitis != NULL )
            {
                baslangic++;
                *bitis = '\0';
            }
            strcpy(canavar->etkiledigi_ozellik,baslangic);
        }
        if (strstr(dizim3,"\"etki_degeri\""))
        {
            char *metin2=strchr(dizim3,':')+1;
            char x,y,z;
            int deger;
            sscanf(metin2,"%c%c%d%c",&x,&y,&deger,&z);
            canavar->etki_miktari=deger;
        }
        if (strstr(dizim3,"\"aciklama\""))
        {
            char *metin3=strchr(dizim3,':')+3;
            char birim[30];
            sscanf(metin3,"%s",&birim);
            if (birim[0]=='p')
            {
                strcpy(canavar->etkiledigi_birim,"piyade");
            }
            if (birim[0]=='o')
            {
                strcpy(canavar->etkiledigi_birim,"okcu");
            }
            if (birim[0]=='s')
            {
                strcpy(canavar->etkiledigi_birim,"suvari");
            }
            if (birim[0]=='k')
            {
                strcpy(canavar->etkiledigi_birim,"kusatma_makine");
            }
            if (birim[0]=='o' && birim[1]=='r')
            {
                strcpy(canavar->etkiledigi_birim,"ork_dovuscu");
            }
            if (birim[0]=='m')
            {
                strcpy(canavar->etkiledigi_birim,"mizrakci");
            }
            if (birim[0]=='v')
            {
                strcpy(canavar->etkiledigi_birim,"varg_binici");
            }
            if (birim[0]=='t')
            {
                strcpy(canavar->etkiledigi_birim,"troller");
            }
            if (birim[0]=='t' && birim[1]=='u')
            {
                strcpy(canavar->etkiledigi_birim,"tum_birimler");
            }
        }
    }
}
void Arastirma_ata(FILE *dospoi4,struct Arastirma *arastirma)
{
    char dizim4[500];
    while (fgets(dizim4,sizeof(dizim4),dospoi4))
    {
        if (strstr(dizim4,"}"))
        {
            break;
        }
        if (strstr(dizim4,"\"deger\""))
        {
            char *metin2=strchr(dizim4,':')+1;
            char x,y,z;
            int deger;
            sscanf(metin2,"%c%c%d%c",&x,&y,&deger,&z);
            arastirma->etki_miktari=deger;
        }
        if (strstr(dizim4,"\"aciklama\""))
        {
            char *metin3=strchr(dizim4,':')+3;
            char birim[30];
            sscanf(metin3,"%s",&birim);
            if (birim[0]=='k')
            {
                strcpy(arastirma->etkiledigi_birim,"kusatma_makine");

            }
            if (birim[0]=='t' && birim[1]=='u')
            {
                strcpy(arastirma->etkiledigi_birim,"tum_birimler");
            }
        }
        if (strstr(dizim4,"\"aciklama\""))
        {
            char *metin3=strchr(dizim4,':')+3;
            char ozellik[30];
            char cop[50];
            sscanf(metin3,"%s%s",&cop,&ozellik);
            if (ozellik[0]=='s'&&ozellik[2]=='v')
            {
                strcpy(arastirma->etkiledigi_ozellik,"Savunma");
            }
            if (ozellik[0]=='s'&&ozellik[2]=='l')
            {
                strcpy(arastirma->etkiledigi_ozellik,"Saldiri");
            }
            if (ozellik[0]=='k')
            {
                strcpy(arastirma->etkiledigi_ozellik,"Krit_sans");
            }
            if (ozellik[0]=='s'&&ozellik[2]=='g')
            {
                strcpy(arastirma->etkiledigi_ozellik,"Saglik");
            }
        }
    }
}
void Arastirma_ata_2(FILE *dospoi4,struct Arastirma *arastirma)
{
    char dizim4[500];
    while (fgets(dizim4,sizeof(dizim4),dospoi4))
    {
        if (strstr(dizim4,"}"))
        {
            break;
        }
        if (strstr(dizim4,"\"deger\""))
        {
            char *metin2=strchr(dizim4,':')+1;
            char x,y,z;
            int deger;
            sscanf(metin2,"%c%c%d%c",&x,&y,&deger,&z);
            arastirma->etki_miktari=deger;
        }
        if (strstr(dizim4,"\"aciklama\""))
        {
            char *metin3=strchr(dizim4,':')+3;
            char birim[30];
            sscanf(metin3,"%s",&birim);
            if (birim[0]=='k')
            {
                strcpy(arastirma->etkiledigi_birim,"kusatma_makine");
            }
            if (birim[0]=='t' && birim[1]=='u')
            {
                strcpy(arastirma->etkiledigi_birim,"tum_birimler");
            }
        }
        if (strstr(dizim4,"\"aciklama\""))
        {
            char *metin3=strchr(dizim4,':')+3;
            char ozellik[30];
            char cop[50];
            char cop2[50];
            sscanf(metin3,"%s%s%s",&cop,&cop2,&ozellik);
            if (ozellik[0]=='s'&&ozellik[2]=='v')
            {
                strcpy(arastirma->etkiledigi_ozellik,"Savunma");
            }
            if (ozellik[0]=='s'&&ozellik[2]=='l')
            {
                strcpy(arastirma->etkiledigi_ozellik,"Saldiri");
            }
            if (ozellik[0]=='k')
            {
                strcpy(arastirma->etkiledigi_ozellik,"Krit_sans");
            }
            if (ozellik[0]=='s'&&ozellik[2]=='g')
            {
                strcpy(arastirma->etkiledigi_ozellik,"Saglik");
            }
        }
    }
}
void Askerlere_ata(FILE *dospoi,struct Askerler *asker)
{
    char dizim2[500];
    while(fgets(dizim2,sizeof(dizim2),dospoi))
    {
        if (strstr(dizim2,"}"))
        {
            break;
        }
        if (strstr(dizim2,"\"saldiri\""))
        {
            char *saldiri=strchr(dizim2,':')+1;
            asker->saldiri=atoi(saldiri);
        }
        if (strstr(dizim2,"\"savunma\""))
        {
            char *savunma=strchr(dizim2,':')+1;
            asker->savunma=atoi(savunma);
        }
        if (strstr(dizim2,"\"saglik\""))
        {
            char *saglik=strchr(dizim2,':')+1;
            asker->saglik=atoi(saglik);
        }
        if (strstr(dizim2,"\"kritik_sans\""))
        {
            char *kritsans=strchr(dizim2,':')+1;
            asker->kritsans=atoi(kritsans);
        }
    }
}
void senaryoArastirmaCek(FILE *dospoi9,struct insan_imp *insan_ordu,struct ork_imp *ork_ordu)
{
    char dizim[500];
    int arastirma_bulundu=0;
    int insan_arastirma=0;
    int ork_arastirma=0;
    while(fgets(dizim,sizeof(dizim),dospoi9))
    {
        if (strstr(dizim,"\"insan_imparatorlugu\""))
        {
            insan_arastirma=1;
            ork_arastirma=0;
        }
        if (strstr(dizim,"\"ork_legi\""))
        {
            insan_arastirma=0;
            ork_arastirma=1;
        }
        if (strstr(dizim,"\"arastirma_seviyesi\""))
        {
            arastirma_bulundu=1;
            continue;
        }
        if (arastirma_bulundu)
        {
            if(strstr(dizim,"}"))
            {
                arastirma_bulundu=0;
                continue;
            }
            char arastirma_adi[50];
            int seviye;
            if(sscanf(dizim," \"%49[^\"]\" : %d",arastirma_adi,&seviye) == 2)
            {
                if (insan_arastirma)
                {
                    insan_ordu->bulunanarastirma.seviye=seviye;
                    strcpy(insan_ordu->bulunanarastirma.arastirmaisim,arastirma_adi);
                }
                if (ork_arastirma)
                {
                    ork_ordu->bulunanarastirma.seviye=seviye;
                    strcpy(ork_ordu->bulunanarastirma.arastirmaisim,arastirma_adi);
                }
            }
        }
    }
}
size_t write_data(void *ptr, size_t size, size_t nmemb, FILE *stream)
{
    size_t written = fwrite(ptr, size, nmemb, stream);
    return written;
}
void jsonu_dosyayi_yukle(int seneryo_numarasi)
{
    CURL *curl;
    FILE *fp;
    CURLcode res;
    const char *urls[] =
    {
        "https://yapbenzet.org.tr/1.json",
        "https://yapbenzet.org.tr/2.json",
        "https://yapbenzet.org.tr/3.json",
        "https://yapbenzet.org.tr/4.json",
        "https://yapbenzet.org.tr/5.json",
        "https://yapbenzet.org.tr/6.json",
        "https://yapbenzet.org.tr/7.json",
        "https://yapbenzet.org.tr/8.json",
        "https://yapbenzet.org.tr/9.json",
        "https://yapbenzet.org.tr/10.json"
    };
    char dosyaadi[50];
    sprintf(dosyaadi, "indirilen_seneryo.json");
    const char *url = urls[seneryo_numarasi - 1];

    curl = curl_easy_init();
    if (curl)
    {
        fp = fopen(dosyaadi, "wb");
        if (fp == NULL)
        {
            printf("Dosya açılamadı!\n");
            return;
        }
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
        res = curl_easy_perform(curl);
        if (res != CURLE_OK)
        {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        }
        else
        {
            printf("Dosya basariyla indirildi: %s\n", dosyaadi);
        }
        fclose(fp);
        curl_easy_cleanup(curl);
    }
    else
    {
        printf("CURL başlatılamadı!\n");
    }
}

int main(int argc, char* argv[])
{
    int seneryo_numarasi;
    int A;
    A:
    printf("Lutfen 1 ile 10 arasinda bir senaryo numarasi seciniz: ");
    scanf("%d", &seneryo_numarasi);
    if (seneryo_numarasi >= 1 && seneryo_numarasi <= 10)
    {
        jsonu_dosyayi_yukle(seneryo_numarasi);



    FILE *dospoi =fopen("unit_types.json","r");
    if (dospoi==NULL)
    {
        printf("dosya1");
        printf("\nDosya acilamadi\n");
        return 1;
    }
    FILE *dospoi2 =fopen("heroes.json","r");
    if (dospoi2==NULL)
    {
        printf("dosya2");
        printf("\nDosya acilamadi\n");
        return 1;
    }
    FILE *dospoi3 =fopen("creatures.json","r");
    if (dospoi3==NULL)
    {
        printf("dosya3");
        printf("\nDosya acilamadi\n");
        return 1;
    }
    FILE *dospoi4 =fopen("research.json","r");
    if (dospoi4==NULL)
    {
        printf("dosya4");
        printf("\nDosya acilamadi\n");
        return 1;
    }
    FILE *dospoi5 =fopen("research.json","r");
    if (dospoi5==NULL)
    {
        printf("dosya5");
        printf("\nDosya acilamadi\n");
        return 1;
    }
    FILE *dospoi6 =fopen("indirilen_seneryo.json","r");
    if (dospoi6==NULL)
    {
        printf("dosya6");
        printf("\nDosya acilamadi\n");
        return 1;
    }
    FILE *dospoi7 =fopen("indirilen_seneryo.json","r");
    if (dospoi7==NULL)
    {
        printf("\nDosya acilamadi\n");
        return 1;
    }
    FILE *dospoi8 =fopen("indirilen_seneryo.json","r");
    if (dospoi8==NULL)
    {
        printf("dosya6");
        printf("\nDosya acilamadi\n");
        return 1;
    }
    FILE *dospoi9 =fopen("indirilen_seneryo.json","r");
    if (dospoi9==NULL)
    {
        printf("\nDosya acilamadi\n");
        return 1;
    }
    FILE *dospoi10 =fopen("indirilen_seneryo.json","r");
    if (dospoi10==NULL)
    {
        printf("\nDosya acilamadi\n");
        return 1;
    }
    FILE *dospoi11 =fopen("savas_sim.txt","w");
    if (dospoi11==NULL)
    {
        printf("\nDosya acilamadi\n");
        return 1;
    }

    char dizim[500];
    char dizim2[500];
    char dizim3[500];
    char dizim4[500];
    char dizim5[500];
    char dizim6[500];
    char dizim7[500];
    char dizim8[500];
    char dizim9[500];
    char dizim10[500];
    struct insan_imp insan_ordu;
    struct ork_imp ork_ordu;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL başlatılamadı! SDL Hatası: %s\n", SDL_GetError());
        return -1;
    }
    SDL_DisplayMode DM;
    SDL_GetCurrentDisplayMode(0, &DM);
    int screenWidth = DM.w;
    int screenHeight = DM.h;

    SDL_Window* window = SDL_CreateWindow("Savaş Simülasyonu", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                          screenWidth, screenHeight, SDL_WINDOW_SHOWN);
    if (window == NULL) {
        printf("Pencere oluşturulamadı! SDL Hatası: %s\n", SDL_GetError());
        SDL_Quit();
        return -1;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL) {
        printf("Renderer oluşturulamadı! SDL Hatası: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }
     SDL_Surface* arkaplanresmiindir = SDL_LoadBMP("arkaplan.bmp");
    if (!arkaplanresmiindir) {
        printf("Arka plan resmi yüklenemedi! SDL Hatası: %s\n", SDL_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }

    SDL_Texture* arkaplanresmidokusu = SDL_CreateTextureFromSurface(renderer, arkaplanresmiindir);
    SDL_FreeSurface(arkaplanresmiindir);

    SDL_Surface* insanlarresmiindir = SDL_LoadBMP("Insanlar.bmp");
    if (!insanlarresmiindir) {
        printf("Insanlar resmi yüklenemedi! SDL Hatası: %s\n", SDL_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }

    SDL_Texture* insanlarresmidokusu = SDL_CreateTextureFromSurface(renderer, insanlarresmiindir);
    SDL_FreeSurface(insanlarresmiindir);

    SDL_Surface* orklaresmiindir = SDL_LoadBMP("Orklar.bmp");
    if (!orklaresmiindir) {
        printf("Orklar resmi yüklenemedi! SDL Hatası: %s\n", SDL_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }

    SDL_Texture* orklarresmidokusu = SDL_CreateTextureFromSurface(renderer, orklaresmiindir);
    SDL_FreeSurface(orklaresmiindir);

     SDL_Surface* savasoncesiresmiindir = SDL_LoadBMP("savasoncesi.bmp");
    if (!savasoncesiresmiindir) {
        printf("Üst resim yüklenemedi! SDL Hatası: %s\n", SDL_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        return -1;
    }
    SDL_Texture* savasoncesidokusu = SDL_CreateTextureFromSurface(renderer, savasoncesiresmiindir);
    SDL_FreeSurface(savasoncesiresmiindir);
     SDL_Surface* savassonrasiresmiindir = SDL_LoadBMP("savassonrasi.bmp");
    if (!savassonrasiresmiindir) {
        printf("Üst resim yüklenemedi! SDL Hatası: %s\n", SDL_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        return -1;
    }
    SDL_Texture* savassonrasidokusu = SDL_CreateTextureFromSurface(renderer, savassonrasiresmiindir);
    SDL_FreeSurface(savassonrasiresmiindir);

    SDL_Surface* okcuresmiindir = SDL_LoadBMP("okcu.bmp");
    SDL_Surface* suvariresmiindir = SDL_LoadBMP("suvari.bmp");
    SDL_Surface* kusatmaresmiindir = SDL_LoadBMP("kusatma_makinesi.bmp");
    SDL_Surface* piyaderesmiindir = SDL_LoadBMP("piyade.bmp");
    SDL_Surface* orkdovuscuresmiindir = SDL_LoadBMP("ork_dovuscusu.bmp");
    SDL_Surface* mizrakciresmiindir = SDL_LoadBMP("mizrakci.bmp");
    SDL_Surface* vargbiniciresmiindir = SDL_LoadBMP("varg_binici.bmp");
    SDL_Surface* trolresmiindir = SDL_LoadBMP("trol.bmp");
    SDL_Surface* fsmresmiindir = SDL_LoadBMP("Fatih_sultan_mehmet.bmp");
    SDL_Surface* yssresmiindir = SDL_LoadBMP("Yavuz_sultan_selim.bmp");
    SDL_Surface* tugrulresmiindir = SDL_LoadBMP("Tugrul_bey.bmp");
    SDL_Surface* meteresmiindir = SDL_LoadBMP("Mete_han.bmp");
    SDL_Surface* alparslanresmiindir = SDL_LoadBMP("Alparslan.bmp");
    SDL_Surface* vrogresmiindir = SDL_LoadBMP("Vrog_kafakiran.bmp");
    SDL_Surface* thrukresmiindir = SDL_LoadBMP("Thruk_kemikkiran.bmp");
    SDL_Surface* ugarresmiindir = SDL_LoadBMP("Ugar_zalim.bmp");
    SDL_Surface* gorukresmiindir = SDL_LoadBMP("Goruk_vahsi.bmp");
    SDL_Surface* ejderharesmiindir = SDL_LoadBMP("Ejderha.bmp");
    SDL_Surface* tepegozresmiindir = SDL_LoadBMP("Tepegoz.bmp");
    SDL_Surface* karakurtresmiindir = SDL_LoadBMP("Karakurt.bmp");
    SDL_Surface* agridagiresmiindir = SDL_LoadBMP("Agri_dagi_devleri.bmp");
    SDL_Surface* samurresmiindir = SDL_LoadBMP("Samur.bmp");
    SDL_Surface* makrokresmiindir = SDL_LoadBMP("Makrog_savas_beyi.bmp");
    SDL_Surface* atesiblisiresmiindir = SDL_LoadBMP("Ates_iblisi.bmp");
    SDL_Surface* camurdeviresmiindir = SDL_LoadBMP("Camur_devi.bmp");
    SDL_Surface* buzdeviresmiindir = SDL_LoadBMP("Buz_devi.bmp");
    SDL_Surface* golgekurtlariresmiindir = SDL_LoadBMP("Golge_kurtlari.bmp");
    SDL_Surface* karatrolresmiindir = SDL_LoadBMP("Kara_trol.bmp");

    if (!makrokresmiindir)
    {
        printf("Resim yüklenemedi! SDL Hatası: %s\n", SDL_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }
    if (!atesiblisiresmiindir)
    {
        printf("Resim yüklenemedi! SDL Hatası: %s\n", SDL_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }
    if (!camurdeviresmiindir)
    {
        printf("Resim yüklenemedi! SDL Hatası: %s\n", SDL_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }
    if (!buzdeviresmiindir)
    {
        printf("Resim yüklenemedi! SDL Hatası: %s\n", SDL_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }
    if (!golgekurtlariresmiindir)
    {
        printf("Resim yüklenemedi! SDL Hatası: %s\n", SDL_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }
    if (!karatrolresmiindir)
    {
        printf("Resim yüklenemedi! SDL Hatası: %s\n", SDL_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }
    if (!ejderharesmiindir)
    {
        printf("Resim yüklenemedi! SDL Hatası: %s\n", SDL_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }
    if (!tepegozresmiindir)
    {
        printf("Resim yüklenemedi! SDL Hatası: %s\n", SDL_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }
    if (!karakurtresmiindir)
    {
        printf("Resim yüklenemedi! SDL Hatası: %s\n", SDL_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }
    if (!agridagiresmiindir)
    {
        printf("Resim yüklenemedi! SDL Hatası: %s\n", SDL_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }
    if (!samurresmiindir)
    {
        printf("Resim yüklenemedi! SDL Hatası: %s\n", SDL_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }
    if (!fsmresmiindir)
    {
        printf("Resim yüklenemedi! SDL Hatası: %s\n", SDL_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }
    if (!yssresmiindir)
    {
        printf("Resim yüklenemedi! SDL Hatası: %s\n", SDL_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }
    if (!tugrulresmiindir)
    {
        printf("Resim yüklenemedi! SDL Hatası: %s\n", SDL_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }
    if (!meteresmiindir)
    {
        printf("Resim yüklenemedi! SDL Hatası: %s\n", SDL_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }
    if (!alparslanresmiindir)
    {
        printf("Resim yüklenemedi! SDL Hatası: %s\n", SDL_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }
    if (!vrogresmiindir)
    {
        printf("Resim yüklenemedi! SDL Hatası: %s\n", SDL_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }
    if (!thrukresmiindir)
    {
        printf("Resim yüklenemedi! SDL Hatası: %s\n", SDL_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }
    if (!ugarresmiindir)
    {
        printf("Resim yüklenemedi! SDL Hatası: %s\n", SDL_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }
    if (!gorukresmiindir)
    {
        printf("Resim yüklenemedi! SDL Hatası: %s\n", SDL_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }
    if (!okcuresmiindir)
    {
        printf("Resim yüklenemedi! SDL Hatası: %s\n", SDL_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }
    if (!suvariresmiindir)
    {
        printf("Resim yüklenemedi! SDL Hatası: %s\n", SDL_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }
    if (!kusatmaresmiindir)
    {
        printf("Resim yüklenemedi! SDL Hatası: %s\n", SDL_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }
    if (!piyaderesmiindir)
    {
        printf("Resim yüklenemedi! SDL Hatası: %s\n", SDL_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }
    if (!orkdovuscuresmiindir)
    {
        printf("Resim yüklenemedi! SDL Hatası: %s\n", SDL_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }
    if (!mizrakciresmiindir)
    {
        printf("Resim yüklenemedi! SDL Hatası: %s\n", SDL_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }
    if (!vargbiniciresmiindir)
    {
        printf("Resim yüklenemedi! SDL Hatası: %s\n", SDL_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }
    if (!trolresmiindir)
    {
        printf("Resim yüklenemedi! SDL Hatası: %s\n", SDL_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }

    SDL_Texture* okcuresmidokusu = SDL_CreateTextureFromSurface(renderer, okcuresmiindir);
    SDL_FreeSurface(okcuresmiindir);
    SDL_Texture* suvariresmidokusu = SDL_CreateTextureFromSurface(renderer, suvariresmiindir);
    SDL_FreeSurface(suvariresmiindir);
    SDL_Texture* kusatmaresmidokusu = SDL_CreateTextureFromSurface(renderer, kusatmaresmiindir);
    SDL_FreeSurface(kusatmaresmiindir);
    SDL_Texture* piyaderesmidokusu = SDL_CreateTextureFromSurface(renderer, piyaderesmiindir);
    SDL_FreeSurface(piyaderesmiindir);
    SDL_Texture* orkdovuscuresmidokusu = SDL_CreateTextureFromSurface(renderer, orkdovuscuresmiindir);
    SDL_FreeSurface(orkdovuscuresmiindir);
    SDL_Texture* mizrakciresmidokusu = SDL_CreateTextureFromSurface(renderer, mizrakciresmiindir);
    SDL_FreeSurface(mizrakciresmiindir);
    SDL_Texture* vargbiniciresmidokusu = SDL_CreateTextureFromSurface(renderer, vargbiniciresmiindir);
    SDL_FreeSurface(vargbiniciresmiindir);
    SDL_Texture* trolresmidokusu = SDL_CreateTextureFromSurface(renderer, trolresmiindir);
    SDL_FreeSurface(trolresmiindir);
    SDL_Texture* fsmresmidokusu = SDL_CreateTextureFromSurface(renderer, fsmresmiindir);
    SDL_FreeSurface(fsmresmiindir);
    SDL_Texture* yssresmidokusu = SDL_CreateTextureFromSurface(renderer, yssresmiindir);
    SDL_FreeSurface(yssresmiindir);
    SDL_Texture* tugrulresmidokusu = SDL_CreateTextureFromSurface(renderer, tugrulresmiindir);
    SDL_FreeSurface(tugrulresmiindir);
    SDL_Texture* meteresmidokusu = SDL_CreateTextureFromSurface(renderer, meteresmiindir);
    SDL_FreeSurface(meteresmiindir);
    SDL_Texture* alparslanresmidokusu = SDL_CreateTextureFromSurface(renderer, alparslanresmiindir);
    SDL_FreeSurface(alparslanresmiindir);
    SDL_Texture* vrogresmidokusu = SDL_CreateTextureFromSurface(renderer, vrogresmiindir);
    SDL_FreeSurface(vrogresmiindir);
    SDL_Texture* thrukresmidokusu = SDL_CreateTextureFromSurface(renderer, thrukresmiindir);
    SDL_FreeSurface(thrukresmiindir);
    SDL_Texture* ugarresmidokusu = SDL_CreateTextureFromSurface(renderer, ugarresmiindir);
    SDL_FreeSurface(ugarresmiindir);
    SDL_Texture* gorukresmidokusu = SDL_CreateTextureFromSurface(renderer, gorukresmiindir);
    SDL_FreeSurface(gorukresmiindir);
    SDL_Texture* ejderharesmidokusu = SDL_CreateTextureFromSurface(renderer, ejderharesmiindir);
    SDL_FreeSurface(ejderharesmiindir);
    SDL_Texture* tepegozresmidokusu = SDL_CreateTextureFromSurface(renderer, tepegozresmiindir);
    SDL_FreeSurface(tepegozresmiindir);
    SDL_Texture* karakurtresmidokusu = SDL_CreateTextureFromSurface(renderer, karakurtresmiindir);
    SDL_FreeSurface(karakurtresmiindir);
    SDL_Texture* agridagiresmidokusu = SDL_CreateTextureFromSurface(renderer, agridagiresmiindir);
    SDL_FreeSurface(agridagiresmiindir);
    SDL_Texture* samurresmidokusu = SDL_CreateTextureFromSurface(renderer, samurresmiindir);
    SDL_FreeSurface(samurresmiindir);
    SDL_Texture* makrokresmidokusu = SDL_CreateTextureFromSurface(renderer, makrokresmiindir);
    SDL_FreeSurface(makrokresmiindir);
    SDL_Texture* atesiblisiresmidokusu = SDL_CreateTextureFromSurface(renderer, atesiblisiresmiindir);
    SDL_FreeSurface(atesiblisiresmiindir);
    SDL_Texture* camurdeviresmidokusu = SDL_CreateTextureFromSurface(renderer, camurdeviresmiindir);
    SDL_FreeSurface(camurdeviresmiindir);
    SDL_Texture* buzdeviresmidokusu = SDL_CreateTextureFromSurface(renderer, buzdeviresmiindir);
    SDL_FreeSurface(buzdeviresmiindir);
    SDL_Texture* golgekurtlariresmidokusu = SDL_CreateTextureFromSurface(renderer, golgekurtlariresmiindir);
    SDL_FreeSurface(golgekurtlariresmiindir);
    SDL_Texture* karatrolresmidokusu = SDL_CreateTextureFromSurface(renderer, karatrolresmiindir);
    SDL_FreeSurface(karatrolresmiindir);

    if (!okcuresmidokusu)
    {
        printf("Okcu resmi oluşturulamadı! SDL Hatası: %s\n", SDL_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }
    if (!suvariresmidokusu)
    {
        printf("Suvari resmi oluşturulamadı! SDL Hatası: %s\n", SDL_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }
    if (!kusatmaresmidokusu)
    {
        printf("Kusatma resmi oluşturulamadı! SDL Hatası: %s\n", SDL_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }
    if (!piyaderesmidokusu)
    {
        printf("Pİyade resmi oluşturulamadı! SDL Hatası: %s\n", SDL_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }
    if (!orkdovuscuresmidokusu)
    {
        printf("Ork dovuscu resmi oluşturulamadı! SDL Hatası: %s\n", SDL_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }
    if (!mizrakciresmidokusu)
    {
        printf("Mİzrakci resmi oluşturulamadı! SDL Hatası: %s\n", SDL_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }
    if (!vargbiniciresmidokusu)
    {
        printf("Varg binici resmi oluşturulamadı! SDL Hatası: %s\n", SDL_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }
    if (!trolresmidokusu)
    {
        printf("Trol resmi oluşturulamadı! SDL Hatası: %s\n", SDL_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }
    if (!ejderharesmidokusu)
    {
        printf("Resim yüklenemedi! SDL Hatası: %s\n", SDL_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }
    if (!tepegozresmidokusu)
    {
        printf("Resim yüklenemedi! SDL Hatası: %s\n", SDL_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }
    if (!karakurtresmidokusu)
    {
        printf("Resim yüklenemedi! SDL Hatası: %s\n", SDL_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }
    if (!agridagiresmidokusu)
    {
        printf("Resim yüklenemedi! SDL Hatası: %s\n", SDL_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }
    if (!samurresmidokusu)
    {
        printf("Resim yüklenemedi! SDL Hatası: %s\n", SDL_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }
    if (!fsmresmidokusu)
    {
        printf("Resim yüklenemedi! SDL Hatası: %s\n", SDL_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }
    if (!yssresmidokusu)
    {
        printf("Resim yüklenemedi! SDL Hatası: %s\n", SDL_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }
    if (!tugrulresmidokusu)
    {
        printf("Resim yüklenemedi! SDL Hatası: %s\n", SDL_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }
    if (!meteresmidokusu)
    {
        printf("Resim yüklenemedi! SDL Hatası: %s\n", SDL_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }
    if (!alparslanresmidokusu)
    {
        printf("Resim yüklenemedi! SDL Hatası: %s\n", SDL_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }
    if (!vrogresmidokusu)
    {
        printf("Resim yüklenemedi! SDL Hatası: %s\n", SDL_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }
    if (!thrukresmidokusu)
    {
        printf("Resim yüklenemedi! SDL Hatası: %s\n", SDL_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }
    if (!ugarresmidokusu)
    {
        printf("Resim yüklenemedi! SDL Hatası: %s\n", SDL_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }
    if (!gorukresmidokusu)
    {
        printf("Resim yüklenemedi! SDL Hatası: %s\n", SDL_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }
    if (!makrokresmidokusu)
    {
        printf("Resim yüklenemedi! SDL Hatası: %s\n", SDL_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }
    if (!atesiblisiresmidokusu)
    {
        printf("Resim yüklenemedi! SDL Hatası: %s\n", SDL_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }
    if (!camurdeviresmidokusu)
    {
        printf("Resim yüklenemedi! SDL Hatası: %s\n", SDL_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }
    if (!buzdeviresmidokusu)
    {
        printf("Resim yüklenemedi! SDL Hatası: %s\n", SDL_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }
    if (!golgekurtlariresmidokusu)
    {
        printf("Resim yüklenemedi! SDL Hatası: %s\n", SDL_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }
    if (!karatrolresmidokusu)
    {
        printf("Resim yüklenemedi! SDL Hatası: %s\n", SDL_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }


    insan_ordu.birimler.piyadesayi=0;
    insan_ordu.birimler.okcusayi=0;
    insan_ordu.birimler.suvarisayi=0;
    insan_ordu.birimler.kusatma_m_sayi=0;
    ork_ordu.birimler2.orkdovuscu=0;
    ork_ordu.birimler2.mizrakci=0;
    ork_ordu.birimler2.vargbinici=0;
    ork_ordu.birimler2.troller=0;

    while (fgets(dizim,sizeof(dizim),dospoi))
    {

        if (strstr(dizim,"\"insan_imparatorlugu\""))
        {
            while (fgets(dizim,sizeof(dizim),dospoi))
            {
                if (strstr(dizim,"}"))
                {
                    break;
                }
                if(strstr(dizim,"\"piyadeler\""))
                {
                    Askerlere_ata(dospoi,&insan_ordu.piyade);
                }
                else if (strstr(dizim,"\"okcular\""))
                {
                    Askerlere_ata(dospoi,&insan_ordu.okcu);
                }
                else if (strstr(dizim,"\"suvariler\""))
                {
                    Askerlere_ata(dospoi,&insan_ordu.suvari);
                }
                else if (strstr(dizim,"\"kusatma_makineleri\""))
                {
                    Askerlere_ata(dospoi,&insan_ordu.kusatma_makine);
                }
            }
        }
        else if (strstr(dizim,"\"ork_legi\""))
        {
            while (fgets(dizim,sizeof(dizim),dospoi))
            {
                if (strstr(dizim,"}"))
                {
                    break;
                }
                if(strstr(dizim,"\"ork_dovusculeri\""))
                {
                    Askerlere_ata(dospoi,&ork_ordu.ork_dovuscu);
                }
                else if (strstr(dizim,"\"mizrakcilar\""))
                {
                    Askerlere_ata(dospoi,&ork_ordu.mizrakci);
                }
                else if (strstr(dizim,"\"varg_binicileri\""))
                {
                    Askerlere_ata(dospoi,&ork_ordu.varg_binici);
                }
                else if (strstr(dizim,"\"troller\""))
                {
                    Askerlere_ata(dospoi,&ork_ordu.troller);
                }
            }
        }
    }
    while (fgets(dizim2,sizeof(dizim2),dospoi2))
    {

        if (strstr(dizim2,"\"insan_imparatorlugu\""))
        {

            while (fgets(dizim2,sizeof(dizim2),dospoi2))
            {
                if (strstr(dizim2,"}"))
                {
                    break;
                }
                if (strstr(dizim2,"\"Alparslan\""))
                {
                    Kahraman_ata(dospoi2,&insan_ordu.alparslan);
                }
                if (strstr(dizim2,"\"Fatih_Sultan_Mehmet\""))
                {
                    Kahraman_ata(dospoi2,&insan_ordu.fatih_sultan_mehmet);
                }
                if (strstr(dizim2,"\"Yavuz_Sultan_Selim\""))
                {
                    Kahraman_ata(dospoi2,&insan_ordu.yavuz_sultan_selim);
                }
                if (strstr(dizim2,"\"Tugrul_Bey\""))
                {
                    Kahraman_ata(dospoi2,&insan_ordu.tugrul_bey);
                }
                if (strstr(dizim2,"\"Mete_Han\""))
                {
                    Kahraman_ata(dospoi2,&insan_ordu.mete_han);
                }
            }
        }
        if (strstr(dizim2,"\"ork_legi\""))
        {

            while (fgets(dizim2,sizeof(dizim2),dospoi2))
            {
                if (strstr(dizim2,"}"))
                {
                    break;
                }
                if (strstr(dizim2,"\"Goruk_Vahsi\""))
                {
                    Kahraman_ata(dospoi2,&ork_ordu.goruk_vahsi);
                }
                if (strstr(dizim2,"\"Thruk_Kemikkiran\""))
                {
                    Kahraman_ata(dospoi2,&ork_ordu.thruk_kemikkiran);
                }
                if (strstr(dizim2,"\"Vrog_Kafakiran\""))
                {
                    Kahraman_ata(dospoi2,&ork_ordu.vrog_kafakiran);
                }
                if (strstr(dizim2,"\"Ugar_Zalim\""))
                {
                    Kahraman_ata(dospoi2,&ork_ordu.ugar_zalim);
                }
            }
        }
    }
    while(fgets(dizim3,sizeof(dizim3),dospoi3))
    {

        if(strstr(dizim3,"\"insan_imparatorlugu\""))
        {

            while(fgets(dizim3,sizeof(dizim3),dospoi3))
            {
                if (strstr(dizim3,"}"))
                {
                    break;
                }
                if (strstr(dizim3,"\"Ejderha\""))
                {
                    Canavar_ata(dospoi3,&insan_ordu.ejderha);
                }
                if (strstr(dizim3,"\"Agri_Dagi_Devleri\""))
                {
                    Canavar_ata(dospoi3,&insan_ordu.agri_dagi_devleri);
                }
                if (strstr(dizim3,"\"Tepegoz\""))
                {
                    Canavar_ata(dospoi3,&insan_ordu.tepegoz);
                }
                if (strstr(dizim3,"\"Karakurt\""))
                {
                    Canavar_ata(dospoi3,&insan_ordu.karakurt);
                }
                if (strstr(dizim3,"\"Samur\""))
                {
                    Canavar_ata(dospoi3,&insan_ordu.samur);
                }
            }
        }
        if (strstr(dizim3,"\"ork_legi\""))
        {

            while (fgets(dizim3,sizeof(dizim3),dospoi3))
            {
                if (strstr(dizim3,"}"))
                {
                    break;
                }
                if (strstr(dizim3,"\"Kara_Troll\""))
                {
                    Canavar_ata(dospoi3,&ork_ordu.kara_troll);
                }
                if (strstr(dizim3,"\"Golge_Kurtlari\""))
                {
                    Canavar_ata(dospoi3,&ork_ordu.golge_kurtlari);
                }
                if (strstr(dizim3,"\"Camur_Devleri\""))
                {
                    Canavar_ata(dospoi3,&ork_ordu.camur_devleri);
                }
                if (strstr(dizim3,"\"Ates_Iblisi\""))
                {
                    Canavar_ata(dospoi3,&ork_ordu.ates_iblisi);
                }
                if (strstr(dizim3,"\"Makrog_Savas_Beyi\""))
                {
                    Canavar_ata(dospoi3,&ork_ordu.makrog_savas_beyi);
                }
                if (strstr(dizim3,"\"Buz_Devleri\""))
                {
                    Canavar_ata(dospoi3,&ork_ordu.buz_devleri);
                }
            }
        }
    }
    while (fgets(dizim4,sizeof(dizim4),dospoi4))
    {

        if (strstr(dizim4,"\"savunma_ustaligi\""))
        {

            while (fgets(dizim4,sizeof(dizim4),dospoi4))
            {
                if (strstr(dizim4,"}"))
                {
                    break;
                }
                if (strstr(dizim4,"\"seviye_1\""))
                {
                    Arastirma_ata(dospoi4,&insan_ordu.savunma_ustaligi_1);
                }
                if (strstr(dizim4,"\"seviye_2\""))
                {
                    Arastirma_ata(dospoi4,&insan_ordu.savunma_ustaligi_2);
                }
                if (strstr(dizim4,"\"seviye_3\""))
                {
                    Arastirma_ata(dospoi4,&insan_ordu.savunma_ustaligi_3);
                }
            }
        }
        if (strstr(dizim4,"\"saldiri_gelistirmesi\""))
        {

            while (fgets(dizim4,sizeof(dizim4),dospoi4))
            {
                if (strstr(dizim4,"}"))
                {
                    break;
                }
                if (strstr(dizim4,"\"seviye_1\""))
                {
                    Arastirma_ata(dospoi4,&insan_ordu.saldiri_gelistirmesi_1);
                }
                if (strstr(dizim4,"\"seviye_2\""))
                {
                    Arastirma_ata(dospoi4,&insan_ordu.saldiri_gelistirmesi_2);
                }
                if (strstr(dizim4,"\"seviye_3\""))
                {
                    Arastirma_ata(dospoi4,&insan_ordu.saldiri_gelistirmesi_3);
                }
            }
        }
        if (strstr(dizim4,"\"elit_egitim\""))
        {

            while (fgets(dizim4,sizeof(dizim4),dospoi4))
            {
                if (strstr(dizim4,"}"))
                {
                    break;
                }
                if (strstr(dizim4,"\"seviye_1\""))
                {
                    Arastirma_ata_2(dospoi4,&insan_ordu.elit_egitim_1);
                }
                if (strstr(dizim4,"\"seviye_2\""))
                {
                    Arastirma_ata_2(dospoi4,&insan_ordu.elit_egitim_2);
                }
                if (strstr(dizim4,"\"seviye_3\""))
                {
                    Arastirma_ata_2(dospoi4,&insan_ordu.elit_egitim_3);
                }
            }
        }
        if (strstr(dizim4,"\"kusatma_ustaligi\""))
        {

            while (fgets(dizim4,sizeof(dizim4),dospoi4))
            {
                if (strstr(dizim4,"}"))
                {
                    break;
                }
                if (strstr(dizim4,"\"seviye_1\""))
                {
                    Arastirma_ata(dospoi4,&insan_ordu.kusatma_ustaligi_1);
                }
                if (strstr(dizim4,"\"seviye_2\""))
                {
                    Arastirma_ata(dospoi4,&insan_ordu.kusatma_ustaligi_2);
                }
                if (strstr(dizim4,"\"seviye_3\""))
                {
                    Arastirma_ata(dospoi4,&insan_ordu.kusatma_ustaligi_3);
                }
            }
        }
    }
    while (fgets(dizim5,sizeof(dizim5),dospoi5))
    {

        if (strstr(dizim5,"\"savunma_ustaligi\""))
        {

            while (fgets(dizim5,sizeof(dizim5),dospoi5))
            {
                if (strstr(dizim5,"}"))
                {
                    break;
                }
                if (strstr(dizim5,"\"seviye_1\""))
                {
                    Arastirma_ata(dospoi5,&ork_ordu.savunma_ustaligi_1);
                }
                if (strstr(dizim5,"\"seviye_2\""))
                {
                    Arastirma_ata(dospoi5,&ork_ordu.savunma_ustaligi_2);
                }
                if (strstr(dizim5,"\"seviye_3\""))
                {
                    Arastirma_ata(dospoi5,&ork_ordu.savunma_ustaligi_3);
                }
            }
        }
        if (strstr(dizim5,"\"saldiri_gelistirmesi\""))
        {

            while (fgets(dizim5,sizeof(dizim5),dospoi5))
            {
                if (strstr(dizim5,"}"))
                {
                    break;
                }
                if (strstr(dizim5,"\"seviye_1\""))
                {
                    Arastirma_ata(dospoi5,&ork_ordu.saldiri_gelistirmesi_1);
                }
                if (strstr(dizim5,"\"seviye_2\""))
                {
                    Arastirma_ata(dospoi5,&ork_ordu.saldiri_gelistirmesi_2);
                }
                if (strstr(dizim5,"\"seviye_3\""))
                {
                    Arastirma_ata(dospoi5,&ork_ordu.saldiri_gelistirmesi_3);
                }
            }
        }
        if (strstr(dizim5,"\"elit_egitim\""))
        {

            while (fgets(dizim5,sizeof(dizim5),dospoi5))
            {
                if (strstr(dizim5,"}"))
                {
                    break;
                }
                if (strstr(dizim5,"\"seviye_1\""))
                {
                    Arastirma_ata_2(dospoi5,&ork_ordu.elit_egitim_1);
                }
                if (strstr(dizim5,"\"seviye_2\""))
                {
                    Arastirma_ata_2(dospoi5,&ork_ordu.elit_egitim_2);
                }
                if (strstr(dizim5,"\"seviye_3\""))
                {
                    Arastirma_ata_2(dospoi5,&ork_ordu.elit_egitim_3);
                }
            }
        }
        if (strstr(dizim5,"\"kusatma_ustaligi\""))
        {

            while (fgets(dizim5,sizeof(dizim5),dospoi5))
            {
                if (strstr(dizim5,"}"))
                {
                    break;
                }
                if (strstr(dizim5,"\"seviye_1\""))
                {
                    Arastirma_ata(dospoi5,&ork_ordu.kusatma_ustaligi_1);
                }
                if (strstr(dizim5,"\"seviye_2\""))
                {
                    Arastirma_ata(dospoi5,&ork_ordu.kusatma_ustaligi_2);
                }
                if (strstr(dizim5,"\"seviye_3\""))
                {
                    Arastirma_ata(dospoi5,&ork_ordu.kusatma_ustaligi_3);
                }
            }
        }
    }
    while (fgets(dizim6, sizeof(dizim6), dospoi6))
    {
        if (strstr(dizim6, "\"insan_imparatorlugu\""))
        {
            while (fgets(dizim6, sizeof(dizim6), dospoi6))
            {
                if (strstr(dizim6, "\"birimler\""))
                {

                    while (fgets(dizim6, sizeof(dizim6), dospoi6))
                    {
                        if (strstr(dizim6, "okcular"))
                        {
                            int okcus;
                            sscanf(dizim6, "%*[^:]: %d", &okcus);
                            insan_ordu.birimler.okcusayi=okcus;
                        }
                        if (strstr(dizim6, "suvariler"))
                        {
                            int suvaris;
                            sscanf(dizim6, "%*[^:]: %d", &suvaris);
                            insan_ordu.birimler.suvarisayi=suvaris;
                        }
                        if (strstr(dizim6, "piyadeler"))
                        {
                            int piyades;
                            sscanf(dizim6, "%*[^:]: %d", &piyades);
                            insan_ordu.birimler.piyadesayi=piyades;
                        }
                        if (strstr(dizim6, "kusatma_makineleri"))
                        {
                            int kusatma_m;
                            sscanf(dizim6, "%*[^:]: %d", &kusatma_m);
                            insan_ordu.birimler.kusatma_m_sayi=kusatma_m;
                        }
                    }
                }
            }
        }
    }
    while (fgets(dizim7, sizeof(dizim7), dospoi7))
    {
        if (strstr(dizim7, "\"ork_legi\""))
        {
            while (fgets(dizim7, sizeof(dizim7), dospoi7))
            {
                if (strstr(dizim7, "birimler"))
                {
                    while (fgets(dizim7, sizeof(dizim7), dospoi7))
                    {
                        if (strstr(dizim7, "ork_dovusculeri"))
                        {
                            int ork;
                            sscanf(dizim7, "%*[^:]: %d", &ork);
                            ork_ordu.birimler2.orkdovuscu=ork;
                        }
                        if (strstr(dizim7, "mizrakcilar"))
                        {
                            int mizrakcilar;
                            sscanf(dizim7, "%*[^:]: %d", &mizrakcilar);
                            ork_ordu.birimler2.mizrakci=mizrakcilar;
                        }
                        if (strstr(dizim7, "varg_binicileri"))
                        {
                            int varg;
                            sscanf(dizim7, "%*[^:]: %d", &varg);
                            ork_ordu.birimler2.vargbinici=varg;
                        }
                        if (strstr(dizim7, "troller"))
                        {
                            int troller;
                            sscanf(dizim7, "%*[^:]: %d", &troller);
                            ork_ordu.birimler2.troller=troller;
                        }
                    }
                }
            }
        }
    }
    int insanKahramanlar = 0;
    int orkKahramanlar = 0;
    while (fgets(dizim8, sizeof(dizim8), dospoi8))
    {
        if (strstr(dizim8, "\"insan_imparatorlugu\""))
        {
            insanKahramanlar = 1;
            orkKahramanlar = 0;
        }
        if (strstr(dizim8, "\"ork_legi\""))
        {
            orkKahramanlar = 1;
            insanKahramanlar = 0;
        }
        if (strstr(dizim8, "\"kahramanlar\""))
        {
            char *metin = strchr(dizim8, ':') + 1;
            char *baslangic = strchr(metin, '[');
            char *bitis = strrchr(metin, ']');

            if (baslangic != NULL && bitis != NULL)
            {
                baslangic++;

                char kahraman[50];
                char *kahramanIsmi = strtok(baslangic, "\",");
                int kahramanNo = 0;

                while (kahramanIsmi != NULL && kahramanIsmi < bitis)
                {
                    strcpy(kahraman, kahramanIsmi);

                    if (insanKahramanlar)
                    {
                        if (kahramanNo == 0)
                            strcpy(insan_ordu.bulunankahraman.bulunan1, kahraman);
                    }

                    if (orkKahramanlar)
                    {
                        if (kahramanNo == 0)
                            strcpy(ork_ordu.bulunankahraman.bulunan1, kahraman);
                    }

                    kahramanIsmi = strtok(NULL, "\",");
                    kahramanNo++;
                }
            }
        }
    }
    int insanCanavarlar = 0;
    int orkCanavarlar = 0;
    while (fgets(dizim10, sizeof(dizim10), dospoi10))
    {
        if (strstr(dizim10, "\"insan_imparatorlugu\""))
        {
            insanCanavarlar = 1;
            orkCanavarlar = 0;
        }
        if (strstr(dizim10, "\"ork_legi\""))
        {
            orkCanavarlar = 1;
            insanCanavarlar = 0;
        }
        if (strstr(dizim10, "\"canavarlar\""))
        {
            char *metin = strchr(dizim10, ':') + 1;
            char *baslangic = strchr(metin, '[');
            char *bitis = strrchr(metin, ']');

            if (baslangic != NULL && bitis != NULL)
            {
                baslangic++;

                char canavar[50];
                char *canavarIsmi = strtok(baslangic, "\",");
                int canavarNo = 0;

                while (canavarIsmi != NULL)
                {
                    strcpy(canavar, canavarIsmi);
                    if (insanCanavarlar)
                    {
                        if (canavarNo == 0)
                            strcpy(insan_ordu.bulunancanavar.bulunan1, canavar);
                    }

                    if (orkCanavarlar)
                    {
                        if (canavarNo == 0)
                            strcpy(ork_ordu.bulunancanavar.bulunan1, canavar);
                    }
                    canavarIsmi = strtok(NULL, "\",");
                    canavarNo++;
                }
            }
        }
    }
    senaryoArastirmaCek(dospoi9,&insan_ordu,&ork_ordu);
    float ToplamPiyadeHasar=insan_ordu.piyade.saldiri*insan_ordu.birimler.piyadesayi;
    float ToplamPiyadeSavunma=insan_ordu.piyade.savunma*insan_ordu.birimler.piyadesayi;
    float ToplamPiyadeSaglik=insan_ordu.piyade.saglik*insan_ordu.birimler.piyadesayi;

    float ToplamOkcuHasar=insan_ordu.okcu.saldiri*insan_ordu.birimler.okcusayi;
    float ToplamOkcuSavunma=insan_ordu.okcu.savunma*insan_ordu.birimler.okcusayi;
    float ToplamOkcuSaglik=insan_ordu.okcu.saglik*insan_ordu.birimler.okcusayi;

    float ToplamSuvariHasar=insan_ordu.suvari.saldiri*insan_ordu.birimler.suvarisayi;
    float ToplamSuvariSavunma=insan_ordu.suvari.savunma*insan_ordu.birimler.suvarisayi;
    float ToplamSuvariSaglik=insan_ordu.suvari.saglik*insan_ordu.birimler.suvarisayi;

    float ToplamKusatmaHasar=insan_ordu.kusatma_makine.saldiri*insan_ordu.birimler.kusatma_m_sayi;
    float ToplamKusatmaSavunma=insan_ordu.kusatma_makine.savunma*insan_ordu.birimler.kusatma_m_sayi;
    float ToplamKusatmaSaglik=insan_ordu.kusatma_makine.saglik*insan_ordu.birimler.kusatma_m_sayi;

    float ToplamOrgDovuscuHasar=ork_ordu.ork_dovuscu.saldiri*ork_ordu.birimler2.orkdovuscu;
    float ToplamOrgDovuscuSavunma=ork_ordu.ork_dovuscu.savunma*ork_ordu.birimler2.orkdovuscu;
    float ToplamOrgDovuscuSaglik=ork_ordu.ork_dovuscu.saglik*ork_ordu.birimler2.orkdovuscu;

    float ToplamMizrakciHasar=ork_ordu.mizrakci.saldiri*ork_ordu.birimler2.mizrakci;
    float ToplamMizrakciSavunma=ork_ordu.mizrakci.savunma*ork_ordu.birimler2.mizrakci;
    float ToplamMizrakciSaglik=ork_ordu.mizrakci.saglik*ork_ordu.birimler2.mizrakci;

    float ToplamVargBiniciHasar=ork_ordu.varg_binici.saldiri*ork_ordu.birimler2.vargbinici;
    float ToplamVargBiniciSavunma=ork_ordu.varg_binici.savunma*ork_ordu.birimler2.vargbinici;
    float ToplamVargBiniciSaglik=ork_ordu.varg_binici.saglik*ork_ordu.birimler2.vargbinici;

    float ToplamTrolHasar=ork_ordu.troller.saldiri*ork_ordu.birimler2.troller;
    float ToplamTrolSavunma=ork_ordu.troller.savunma*ork_ordu.birimler2.troller;
    float ToplamTrolSaglik=ork_ordu.troller.saglik*ork_ordu.birimler2.troller;

    if (strcmp(insan_ordu.bulunankahraman.bulunan1,"Tugrul_Bey")==0)
    {
        if (strcmp(insan_ordu.tugrul_bey.etkiledigi_birim,"okcu")==0)
        {
            if (strcmp(insan_ordu.tugrul_bey.etkiledigi_ozellik,"saldiri")==0)
            {
                ToplamOkcuHasar=ToplamOkcuHasar*(insan_ordu.tugrul_bey.etki_miktari+100)/100;
            }
            if (strcmp(insan_ordu.tugrul_bey.etkiledigi_ozellik,"savunma")==0)
            {
                ToplamOkcuSavunma=ToplamOkcuSavunma*(insan_ordu.tugrul_bey.etki_miktari+100)/100;
            }
            if (strcmp(insan_ordu.tugrul_bey.etkiledigi_ozellik,"saglik")==0)
            {
                ToplamOkcuSaglik=ToplamOkcuSaglik*(insan_ordu.tugrul_bey.etki_miktari+100)/100;
            }
            if (strcmp(insan_ordu.tugrul_bey.etkiledigi_ozellik,"kritik_sans")==0)
            {
                insan_ordu.okcu.kritsans=insan_ordu.okcu.kritsans*(insan_ordu.tugrul_bey.etki_miktari+100)/100;
            }
        }
        if (strcmp(insan_ordu.tugrul_bey.etkiledigi_birim,"piyade")==0)
        {
            if (strcmp(insan_ordu.tugrul_bey.etkiledigi_ozellik,"saldiri")==0)
            {
                ToplamPiyadeHasar=ToplamPiyadeHasar*(insan_ordu.tugrul_bey.etki_miktari+100)/100;
            }
            if (strcmp(insan_ordu.tugrul_bey.etkiledigi_ozellik,"savunma")==0)
            {
                ToplamPiyadeSavunma=ToplamPiyadeSavunma*(insan_ordu.tugrul_bey.etki_miktari+100)/100;
            }
            if (strcmp(insan_ordu.tugrul_bey.etkiledigi_ozellik,"saglik")==0)
            {
                ToplamPiyadeSaglik=ToplamPiyadeSaglik*(insan_ordu.tugrul_bey.etki_miktari+100)/100;
            }
            if (strcmp(insan_ordu.tugrul_bey.etkiledigi_ozellik,"kritik_sans")==0)
            {
                insan_ordu.piyade.kritsans=insan_ordu.piyade.kritsans*(insan_ordu.tugrul_bey.etki_miktari+100)/100;
            }
        }
        if (strcmp(insan_ordu.tugrul_bey.etkiledigi_birim,"suvari")==0)
        {
            if (strcmp(insan_ordu.tugrul_bey.etkiledigi_ozellik,"saldiri")==0)
            {
                ToplamSuvariHasar=ToplamSuvariHasar*(insan_ordu.tugrul_bey.etki_miktari+100)/100;
            }
            if (strcmp(insan_ordu.tugrul_bey.etkiledigi_ozellik,"savunma")==0)
            {
                ToplamSuvariSavunma=ToplamSuvariSavunma*(insan_ordu.tugrul_bey.etki_miktari+100)/100;
            }
            if (strcmp(insan_ordu.tugrul_bey.etkiledigi_ozellik,"saglik")==0)
            {
                ToplamSuvariSaglik=ToplamSuvariSaglik*(insan_ordu.tugrul_bey.etki_miktari+100)/100;
            }
            if (strcmp(insan_ordu.tugrul_bey.etkiledigi_ozellik,"kritik_sans")==0)
            {
                insan_ordu.suvari.kritsans=insan_ordu.suvari.kritsans*(insan_ordu.tugrul_bey.etki_miktari+100)/100;
            }
        }
        if (strcmp(insan_ordu.tugrul_bey.etkiledigi_birim,"kusatma_makine")==0)
        {
            if (strcmp(insan_ordu.tugrul_bey.etkiledigi_ozellik,"saldiri")==0)
            {
                ToplamKusatmaHasar=ToplamKusatmaHasar*(insan_ordu.tugrul_bey.etki_miktari+100)/100;
            }
            if (strcmp(insan_ordu.tugrul_bey.etkiledigi_ozellik,"savunma")==0)
            {
                ToplamKusatmaSavunma=ToplamKusatmaSavunma*(insan_ordu.tugrul_bey.etki_miktari+100)/100;
            }
            if (strcmp(insan_ordu.tugrul_bey.etkiledigi_ozellik,"saglik")==0)
            {
                ToplamKusatmaSaglik=ToplamKusatmaSaglik*(insan_ordu.tugrul_bey.etki_miktari+100)/100;
            }
            if (strcmp(insan_ordu.tugrul_bey.etkiledigi_ozellik,"kritik_sans")==0)
            {
                insan_ordu.kusatma_makine.kritsans=insan_ordu.kusatma_makine.kritsans*(insan_ordu.tugrul_bey.etki_miktari+100)/100;
            }
        }
    }
    if (strcmp(insan_ordu.bulunankahraman.bulunan1,"Yavuz_Sultan_Selim")==0)
    {
        if (strcmp(insan_ordu.yavuz_sultan_selim.etkiledigi_birim,"okcu")==0)
        {
            if (strcmp(insan_ordu.yavuz_sultan_selim.etkiledigi_ozellik,"saldiri")==0)
            {
                ToplamOkcuHasar=ToplamOkcuHasar*(insan_ordu.yavuz_sultan_selim.etki_miktari+100)/100;
            }
            if (strcmp(insan_ordu.yavuz_sultan_selim.etkiledigi_ozellik,"savunma")==0)
            {
                ToplamOkcuSavunma=ToplamOkcuSavunma*(insan_ordu.yavuz_sultan_selim.etki_miktari+100)/100;
            }
            if (strcmp(insan_ordu.yavuz_sultan_selim.etkiledigi_ozellik,"saglik")==0)
            {
                ToplamOkcuSaglik=ToplamOkcuSaglik*(insan_ordu.yavuz_sultan_selim.etki_miktari+100)/100;
            }
            if (strcmp(insan_ordu.yavuz_sultan_selim.etkiledigi_ozellik,"kritik_sans")==0)
            {
                insan_ordu.okcu.kritsans=insan_ordu.okcu.kritsans*(insan_ordu.yavuz_sultan_selim.etki_miktari+100)/100;
            }
        }
        if (strcmp(insan_ordu.yavuz_sultan_selim.etkiledigi_birim,"piyade")==0)
        {
            if (strcmp(insan_ordu.yavuz_sultan_selim.etkiledigi_ozellik,"saldiri")==0)
            {
                ToplamPiyadeHasar=ToplamPiyadeHasar*(insan_ordu.yavuz_sultan_selim.etki_miktari+100)/100;
            }
            if (strcmp(insan_ordu.yavuz_sultan_selim.etkiledigi_ozellik,"savunma")==0)
            {
                ToplamPiyadeSavunma=ToplamPiyadeSavunma*(insan_ordu.yavuz_sultan_selim.etki_miktari+100)/100;
            }
            if (strcmp(insan_ordu.yavuz_sultan_selim.etkiledigi_ozellik,"saglik")==0)
            {
                ToplamPiyadeSaglik=ToplamPiyadeSaglik*(insan_ordu.yavuz_sultan_selim.etki_miktari+100)/100;
            }
            if (strcmp(insan_ordu.yavuz_sultan_selim.etkiledigi_ozellik,"kritik_sans")==0)
            {
                insan_ordu.piyade.kritsans=insan_ordu.piyade.kritsans*(insan_ordu.yavuz_sultan_selim.etki_miktari+100)/100;
            }
        }
        if (strcmp(insan_ordu.yavuz_sultan_selim.etkiledigi_birim,"suvari")==0)
        {
            if (strcmp(insan_ordu.yavuz_sultan_selim.etkiledigi_ozellik,"saldiri")==0)
            {
                ToplamSuvariHasar=ToplamSuvariHasar*(insan_ordu.yavuz_sultan_selim.etki_miktari+100)/100;
            }
            if (strcmp(insan_ordu.yavuz_sultan_selim.etkiledigi_ozellik,"savunma")==0)
            {
                ToplamSuvariSavunma=ToplamSuvariSavunma*(insan_ordu.yavuz_sultan_selim.etki_miktari+100)/100;
            }
            if (strcmp(insan_ordu.yavuz_sultan_selim.etkiledigi_ozellik,"saglik")==0)
            {
                ToplamSuvariSaglik=ToplamSuvariSaglik*(insan_ordu.yavuz_sultan_selim.etki_miktari+100)/100;
            }
            if (strcmp(insan_ordu.yavuz_sultan_selim.etkiledigi_ozellik,"kritik_sans")==0)
            {
                insan_ordu.suvari.kritsans=insan_ordu.suvari.kritsans*(insan_ordu.yavuz_sultan_selim.etki_miktari+100)/100;
            }
        }
        if (strcmp(insan_ordu.yavuz_sultan_selim.etkiledigi_birim,"kusatma_makine")==0)
        {
            if (strcmp(insan_ordu.yavuz_sultan_selim.etkiledigi_ozellik,"saldiri")==0)
            {
                ToplamKusatmaHasar=ToplamKusatmaHasar*(insan_ordu.yavuz_sultan_selim.etki_miktari+100)/100;
            }
            if (strcmp(insan_ordu.yavuz_sultan_selim.etkiledigi_ozellik,"savunma")==0)
            {
                ToplamKusatmaSavunma=ToplamKusatmaSavunma*(insan_ordu.yavuz_sultan_selim.etki_miktari+100)/100;
            }
            if (strcmp(insan_ordu.yavuz_sultan_selim.etkiledigi_ozellik,"saglik")==0)
            {
                ToplamKusatmaSaglik=ToplamKusatmaSaglik*(insan_ordu.yavuz_sultan_selim.etki_miktari+100)/100;
            }
            if (strcmp(insan_ordu.yavuz_sultan_selim.etkiledigi_ozellik,"kritik_sans")==0)
            {
                insan_ordu.kusatma_makine.kritsans=insan_ordu.kusatma_makine.kritsans*(insan_ordu.yavuz_sultan_selim.etki_miktari+100)/100;
            }
        }
    }
    if (strcmp(insan_ordu.bulunankahraman.bulunan1,"Fatih_Sultan_Mehmet")==0)
    {
        if (strcmp(insan_ordu.fatih_sultan_mehmet.etkiledigi_birim,"okcu")==0)
        {
            if (strcmp(insan_ordu.fatih_sultan_mehmet.etkiledigi_ozellik,"saldiri")==0)
            {
                ToplamOkcuHasar=ToplamOkcuHasar*(insan_ordu.fatih_sultan_mehmet.etki_miktari+100)/100;
            }
            if (strcmp(insan_ordu.fatih_sultan_mehmet.etkiledigi_ozellik,"savunma")==0)
            {
                ToplamOkcuSavunma=ToplamOkcuSavunma*(insan_ordu.fatih_sultan_mehmet.etki_miktari+100)/100;
            }
            if (strcmp(insan_ordu.fatih_sultan_mehmet.etkiledigi_ozellik,"saglik")==0)
            {
                ToplamOkcuSaglik=ToplamOkcuSaglik*(insan_ordu.fatih_sultan_mehmet.etki_miktari+100)/100;
            }
            if (strcmp(insan_ordu.fatih_sultan_mehmet.etkiledigi_ozellik,"kritik_sans")==0)
            {
                insan_ordu.okcu.kritsans=insan_ordu.okcu.kritsans*(insan_ordu.fatih_sultan_mehmet.etki_miktari+100)/100;
            }
        }
        if (strcmp(insan_ordu.fatih_sultan_mehmet.etkiledigi_birim,"piyade")==0)
        {
            if (strcmp(insan_ordu.fatih_sultan_mehmet.etkiledigi_ozellik,"saldiri")==0)
            {
                ToplamPiyadeHasar=ToplamPiyadeHasar*(insan_ordu.fatih_sultan_mehmet.etki_miktari+100)/100;
            }
            if (strcmp(insan_ordu.fatih_sultan_mehmet.etkiledigi_ozellik,"savunma")==0)
            {
                ToplamPiyadeSavunma=ToplamPiyadeSavunma*(insan_ordu.fatih_sultan_mehmet.etki_miktari+100)/100;
            }
            if (strcmp(insan_ordu.fatih_sultan_mehmet.etkiledigi_ozellik,"saglik")==0)
            {
                ToplamPiyadeSaglik=ToplamPiyadeSaglik*(insan_ordu.fatih_sultan_mehmet.etki_miktari+100)/100;
            }
            if (strcmp(insan_ordu.fatih_sultan_mehmet.etkiledigi_ozellik,"kritik_sans")==0)
            {
                insan_ordu.piyade.kritsans=insan_ordu.piyade.kritsans*(insan_ordu.fatih_sultan_mehmet.etki_miktari+100)/100;
            }
        }
        if (strcmp(insan_ordu.fatih_sultan_mehmet.etkiledigi_birim,"suvari")==0)
        {
            if (strcmp(insan_ordu.fatih_sultan_mehmet.etkiledigi_ozellik,"saldiri")==0)
            {
                ToplamSuvariHasar=ToplamSuvariHasar*(insan_ordu.fatih_sultan_mehmet.etki_miktari+100)/100;
            }
            if (strcmp(insan_ordu.fatih_sultan_mehmet.etkiledigi_ozellik,"savunma")==0)
            {
                ToplamSuvariSavunma=ToplamSuvariSavunma*(insan_ordu.fatih_sultan_mehmet.etki_miktari+100)/100;
            }
            if (strcmp(insan_ordu.fatih_sultan_mehmet.etkiledigi_ozellik,"saglik")==0)
            {
                ToplamSuvariSaglik=ToplamSuvariSaglik*(insan_ordu.fatih_sultan_mehmet.etki_miktari+100)/100;
            }
            if (strcmp(insan_ordu.fatih_sultan_mehmet.etkiledigi_ozellik,"kritik_sans")==0)
            {
                insan_ordu.suvari.kritsans=insan_ordu.suvari.kritsans*(insan_ordu.fatih_sultan_mehmet.etki_miktari+100)/100;
            }
        }
        if (strcmp(insan_ordu.fatih_sultan_mehmet.etkiledigi_birim,"kusatma_makine")==0)
        {
            if (strcmp(insan_ordu.fatih_sultan_mehmet.etkiledigi_ozellik,"saldiri")==0)
            {
                ToplamKusatmaHasar=ToplamKusatmaHasar*(insan_ordu.fatih_sultan_mehmet.etki_miktari+100)/100;
            }
            if (strcmp(insan_ordu.fatih_sultan_mehmet.etkiledigi_ozellik,"savunma")==0)
            {
                ToplamKusatmaSavunma=ToplamKusatmaSavunma*(insan_ordu.fatih_sultan_mehmet.etki_miktari+100)/100;
            }
            if (strcmp(insan_ordu.fatih_sultan_mehmet.etkiledigi_ozellik,"saglik")==0)
            {
                ToplamKusatmaSaglik=ToplamKusatmaSaglik*(insan_ordu.fatih_sultan_mehmet.etki_miktari+100)/100;
            }
            if (strcmp(insan_ordu.fatih_sultan_mehmet.etkiledigi_ozellik,"kritik_sans")==0)
            {
                insan_ordu.kusatma_makine.kritsans=insan_ordu.kusatma_makine.kritsans*(insan_ordu.fatih_sultan_mehmet.etki_miktari+100)/100;
            }
        }
    }
    if (strcmp(insan_ordu.bulunankahraman.bulunan1,"Alparslan")==0)
    {
        if (strcmp(insan_ordu.alparslan.etkiledigi_birim,"okcu")==0)
        {
            if (strcmp(insan_ordu.alparslan.etkiledigi_ozellik,"saldiri")==0)
            {
                ToplamOkcuHasar=ToplamOkcuHasar*(insan_ordu.alparslan.etki_miktari+100)/100;
            }
            if (strcmp(insan_ordu.alparslan.etkiledigi_ozellik,"savunma")==0)
            {
                ToplamOkcuSavunma=ToplamOkcuSavunma*(insan_ordu.alparslan.etki_miktari+100)/100;
            }
            if (strcmp(insan_ordu.alparslan.etkiledigi_ozellik,"saglik")==0)
            {
                ToplamOkcuSaglik=ToplamOkcuSaglik*(insan_ordu.alparslan.etki_miktari+100)/100;
            }
            if (strcmp(insan_ordu.alparslan.etkiledigi_ozellik,"kritik_sans")==0)
            {
                insan_ordu.okcu.kritsans=insan_ordu.okcu.kritsans*(insan_ordu.alparslan.etki_miktari+100)/100;
            }
        }
        if (strcmp(insan_ordu.alparslan.etkiledigi_birim,"piyade")==0)
        {
            if (strcmp(insan_ordu.alparslan.etkiledigi_ozellik,"saldiri")==0)
            {
                ToplamPiyadeHasar=ToplamPiyadeHasar*(insan_ordu.alparslan.etki_miktari+100)/100;
            }
            if (strcmp(insan_ordu.alparslan.etkiledigi_ozellik,"savunma")==0)
            {
                ToplamPiyadeSavunma=ToplamPiyadeSavunma*(insan_ordu.alparslan.etki_miktari+100)/100;
            }
            if (strcmp(insan_ordu.alparslan.etkiledigi_ozellik,"saglik")==0)
            {
                ToplamPiyadeSaglik=ToplamPiyadeSaglik*(insan_ordu.alparslan.etki_miktari+100)/100;
            }
            if (strcmp(insan_ordu.alparslan.etkiledigi_ozellik,"kritik_sans")==0)
            {
                insan_ordu.piyade.kritsans=insan_ordu.piyade.kritsans*(insan_ordu.alparslan.etki_miktari+100)/100;
            }
        }
        if (strcmp(insan_ordu.alparslan.etkiledigi_birim,"suvari")==0)
        {
            if (strcmp(insan_ordu.alparslan.etkiledigi_ozellik,"saldiri")==0)
            {
                ToplamSuvariHasar=ToplamSuvariHasar*(insan_ordu.alparslan.etki_miktari+100)/100;
            }
            if (strcmp(insan_ordu.alparslan.etkiledigi_ozellik,"savunma")==0)
            {
                ToplamSuvariSavunma=ToplamSuvariSavunma*(insan_ordu.alparslan.etki_miktari+100)/100;
            }
            if (strcmp(insan_ordu.alparslan.etkiledigi_ozellik,"saglik")==0)
            {
                ToplamSuvariSaglik=ToplamSuvariSaglik*(insan_ordu.alparslan.etki_miktari+100)/100;
            }
            if (strcmp(insan_ordu.alparslan.etkiledigi_ozellik,"kritik_sans")==0)
            {
                insan_ordu.suvari.kritsans=insan_ordu.suvari.kritsans*(insan_ordu.alparslan.etki_miktari+100)/100;
            }
        }
        if (strcmp(insan_ordu.alparslan.etkiledigi_birim,"kusatma_makine")==0)
        {
            if (strcmp(insan_ordu.alparslan.etkiledigi_ozellik,"saldiri")==0)
            {
                ToplamKusatmaHasar=ToplamKusatmaHasar*(insan_ordu.alparslan.etki_miktari+100)/100;
            }
            if (strcmp(insan_ordu.alparslan.etkiledigi_ozellik,"savunma")==0)
            {
                ToplamKusatmaSavunma=ToplamKusatmaSavunma*(insan_ordu.alparslan.etki_miktari+100)/100;
            }
            if (strcmp(insan_ordu.alparslan.etkiledigi_ozellik,"saglik")==0)
            {
                ToplamKusatmaSaglik=ToplamKusatmaSaglik*(insan_ordu.alparslan.etki_miktari+100)/100;
            }
            if (strcmp(insan_ordu.alparslan.etkiledigi_ozellik,"kritik_sans")==0)
            {
                insan_ordu.kusatma_makine.kritsans=insan_ordu.kusatma_makine.kritsans*(insan_ordu.alparslan.etki_miktari+100)/100;
            }
        }
    }
    if (strcmp(insan_ordu.bulunankahraman.bulunan1,"Mete_Han")==0)
    {
        if (strcmp(insan_ordu.mete_han.etkiledigi_birim,"okcu")==0)
        {
            if (strcmp(insan_ordu.mete_han.etkiledigi_ozellik,"saldiri")==0)
            {
                ToplamOkcuHasar=ToplamOkcuHasar*(insan_ordu.mete_han.etki_miktari+100)/100;
            }
            if (strcmp(insan_ordu.mete_han.etkiledigi_ozellik,"savunma")==0)
            {
                ToplamOkcuSavunma=ToplamOkcuSavunma*(insan_ordu.mete_han.etki_miktari+100)/100;
            }
            if (strcmp(insan_ordu.mete_han.etkiledigi_ozellik,"saglik")==0)
            {
                ToplamOkcuSaglik=ToplamOkcuSaglik*(insan_ordu.mete_han.etki_miktari+100)/100;
            }
            if (strcmp(insan_ordu.mete_han.etkiledigi_ozellik,"kritik_sans")==0)
            {
                insan_ordu.okcu.kritsans=insan_ordu.okcu.kritsans*(insan_ordu.mete_han.etki_miktari+100)/100;
            }
        }
        if (strcmp(insan_ordu.mete_han.etkiledigi_birim,"piyade")==0)
        {
            if (strcmp(insan_ordu.mete_han.etkiledigi_ozellik,"saldiri")==0)
            {
                ToplamPiyadeHasar=ToplamPiyadeHasar*(insan_ordu.mete_han.etki_miktari+100)/100;
            }
            if (strcmp(insan_ordu.mete_han.etkiledigi_ozellik,"savunma")==0)
            {
                ToplamPiyadeSavunma=ToplamPiyadeSavunma*(insan_ordu.mete_han.etki_miktari+100)/100;
            }
            if (strcmp(insan_ordu.mete_han.etkiledigi_ozellik,"saglik")==0)
            {
                ToplamPiyadeSaglik=ToplamPiyadeSaglik*(insan_ordu.mete_han.etki_miktari+100)/100;
            }
            if (strcmp(insan_ordu.mete_han.etkiledigi_ozellik,"kritik_sans")==0)
            {
                insan_ordu.piyade.kritsans=insan_ordu.piyade.kritsans*(insan_ordu.mete_han.etki_miktari+100)/100;
            }
        }
        if (strcmp(insan_ordu.mete_han.etkiledigi_birim,"suvari")==0)
        {
            if (strcmp(insan_ordu.mete_han.etkiledigi_ozellik,"saldiri")==0)
            {
                ToplamSuvariHasar=ToplamSuvariHasar*(insan_ordu.mete_han.etki_miktari+100)/100;
            }
            if (strcmp(insan_ordu.mete_han.etkiledigi_ozellik,"savunma")==0)
            {
                ToplamSuvariSavunma=ToplamSuvariSavunma*(insan_ordu.mete_han.etki_miktari+100)/100;
            }
            if (strcmp(insan_ordu.mete_han.etkiledigi_ozellik,"saglik")==0)
            {
                ToplamSuvariSaglik=ToplamSuvariSaglik*(insan_ordu.mete_han.etki_miktari+100)/100;
            }
            if (strcmp(insan_ordu.mete_han.etkiledigi_ozellik,"kritik_sans")==0)
            {
                insan_ordu.suvari.kritsans=insan_ordu.suvari.kritsans*(insan_ordu.mete_han.etki_miktari+100)/100;
            }
        }
        if (strcmp(insan_ordu.mete_han.etkiledigi_birim,"kusatma_makine")==0)
        {
            if (strcmp(insan_ordu.mete_han.etkiledigi_ozellik,"saldiri")==0)
            {
                ToplamKusatmaHasar=ToplamKusatmaHasar*(insan_ordu.mete_han.etki_miktari+100)/100;
            }
            if (strcmp(insan_ordu.mete_han.etkiledigi_ozellik,"savunma")==0)
            {
                ToplamKusatmaSavunma=ToplamKusatmaSavunma*(insan_ordu.mete_han.etki_miktari+100)/100;
            }
            if (strcmp(insan_ordu.mete_han.etkiledigi_ozellik,"saglik")==0)
            {
                ToplamKusatmaSaglik=ToplamKusatmaSaglik*(insan_ordu.mete_han.etki_miktari+100)/100;
            }
            if (strcmp(insan_ordu.mete_han.etkiledigi_ozellik,"kritik_sans")==0)
            {
                insan_ordu.kusatma_makine.kritsans=insan_ordu.kusatma_makine.kritsans*(insan_ordu.mete_han.etki_miktari+100)/100;
            }
        }
    }
    if (strcmp(ork_ordu.bulunankahraman.bulunan1,"Goruk_Vahsi")==0)
    {
        if (strcmp(ork_ordu.goruk_vahsi.etkiledigi_birim,"ork_dovuscu")==0)
        {
            if (strcmp(ork_ordu.goruk_vahsi.etkiledigi_ozellik,"saldiri")==0)
            {
                ToplamOrgDovuscuHasar=ToplamOrgDovuscuHasar*(ork_ordu.goruk_vahsi.etki_miktari+100)/100;
            }
            if (strcmp(ork_ordu.goruk_vahsi.etkiledigi_ozellik,"savunma")==0)
            {
                ToplamOrgDovuscuSavunma=ToplamOrgDovuscuSavunma*(ork_ordu.goruk_vahsi.etki_miktari+100)/100;
            }
            if (strcmp(ork_ordu.goruk_vahsi.etkiledigi_ozellik,"saglik")==0)
            {
                ToplamOrgDovuscuSaglik=ToplamOrgDovuscuSaglik*(ork_ordu.goruk_vahsi.etki_miktari+100)/100;
            }
            if (strcmp(ork_ordu.goruk_vahsi.etkiledigi_ozellik,"kritik_sans")==0)
            {
                ork_ordu.ork_dovuscu.kritsans=ork_ordu.ork_dovuscu.kritsans*(ork_ordu.goruk_vahsi.etki_miktari+100)/100;
            }
        }
        if (strcmp(ork_ordu.goruk_vahsi.etkiledigi_birim,"mizrakci")==0)
        {
            if (strcmp(ork_ordu.goruk_vahsi.etkiledigi_ozellik,"saldiri")==0)
            {
                ToplamMizrakciHasar=ToplamMizrakciHasar*(ork_ordu.goruk_vahsi.etki_miktari+100)/100;
            }
            if (strcmp(ork_ordu.goruk_vahsi.etkiledigi_ozellik,"savunma")==0)
            {
                ToplamMizrakciSavunma=ToplamMizrakciSavunma*(ork_ordu.goruk_vahsi.etki_miktari+100)/100;
            }
            if (strcmp(ork_ordu.goruk_vahsi.etkiledigi_ozellik,"saglik")==0)
            {
                ToplamMizrakciSaglik=ToplamMizrakciSaglik*(ork_ordu.goruk_vahsi.etki_miktari+100)/100;
            }
            if (strcmp(ork_ordu.goruk_vahsi.etkiledigi_ozellik,"kritik_sans")==0)
            {
                ork_ordu.mizrakci.kritsans=ork_ordu.mizrakci.kritsans*(ork_ordu.goruk_vahsi.etki_miktari+100)/100;
            }
        }
        if (strcmp(ork_ordu.goruk_vahsi.etkiledigi_birim,"varg_binici")==0)
        {
            if (strcmp(ork_ordu.goruk_vahsi.etkiledigi_ozellik,"saldiri")==0)
            {
                ToplamVargBiniciHasar=ToplamVargBiniciHasar*(ork_ordu.goruk_vahsi.etki_miktari+100)/100;
            }
            if (strcmp(ork_ordu.goruk_vahsi.etkiledigi_ozellik,"savunma")==0)
            {
                ToplamVargBiniciSavunma=ToplamVargBiniciSavunma*(ork_ordu.goruk_vahsi.etki_miktari+100)/100;
            }
            if (strcmp(ork_ordu.goruk_vahsi.etkiledigi_ozellik,"saglik")==0)
            {
                ToplamVargBiniciSaglik=ToplamVargBiniciSaglik*(ork_ordu.goruk_vahsi.etki_miktari+100)/100;
            }
            if (strcmp(ork_ordu.goruk_vahsi.etkiledigi_ozellik,"kritik_sans")==0)
            {
                ork_ordu.varg_binici.kritsans=ork_ordu.varg_binici.kritsans*(ork_ordu.goruk_vahsi.etki_miktari+100)/100;
            }
        }
        if (strcmp(ork_ordu.goruk_vahsi.etkiledigi_birim,"troller")==0)
        {
            if (strcmp(ork_ordu.goruk_vahsi.etkiledigi_ozellik,"saldiri")==0)
            {
                ToplamTrolHasar=ToplamTrolHasar*(ork_ordu.goruk_vahsi.etki_miktari+100)/100;
            }
            if (strcmp(ork_ordu.goruk_vahsi.etkiledigi_ozellik,"savunma")==0)
            {
                ToplamTrolSavunma=ToplamTrolSavunma*(ork_ordu.goruk_vahsi.etki_miktari+100)/100;
            }
            if (strcmp(ork_ordu.goruk_vahsi.etkiledigi_ozellik,"saglik")==0)
            {
                ToplamTrolSaglik=ToplamTrolSaglik*(ork_ordu.goruk_vahsi.etki_miktari+100)/100;
            }
            if (strcmp(ork_ordu.goruk_vahsi.etkiledigi_ozellik,"kritik_sans")==0)
            {
                ork_ordu.troller.kritsans=ork_ordu.troller.kritsans*(ork_ordu.goruk_vahsi.etki_miktari+100)/100;
            }
        }
    }
    if (strcmp(ork_ordu.bulunankahraman.bulunan1,"Thruk_Kemikkiran")==0)
    {
        if (strcmp(ork_ordu.thruk_kemikkiran.etkiledigi_birim,"ork_dovuscu")==0)
        {
            if (strcmp(ork_ordu.thruk_kemikkiran.etkiledigi_ozellik,"saldiri")==0)
            {
                ToplamOrgDovuscuHasar=ToplamOrgDovuscuHasar*(ork_ordu.thruk_kemikkiran.etki_miktari+100)/100;
            }
            if (strcmp(ork_ordu.thruk_kemikkiran.etkiledigi_ozellik,"savunma")==0)
            {
                ToplamOrgDovuscuSavunma=ToplamOrgDovuscuSavunma*(ork_ordu.thruk_kemikkiran.etki_miktari+100)/100;
            }
            if (strcmp(ork_ordu.thruk_kemikkiran.etkiledigi_ozellik,"saglik")==0)
            {
                ToplamOrgDovuscuSaglik=ToplamOrgDovuscuSaglik*(ork_ordu.thruk_kemikkiran.etki_miktari+100)/100;
            }
            if (strcmp(ork_ordu.thruk_kemikkiran.etkiledigi_ozellik,"kritik_sans")==0)
            {
                ork_ordu.ork_dovuscu.kritsans=ork_ordu.ork_dovuscu.kritsans*(ork_ordu.thruk_kemikkiran.etki_miktari+100)/100;
            }
        }
        if (strcmp(ork_ordu.thruk_kemikkiran.etkiledigi_birim,"mizrakci")==0)
        {
            if (strcmp(ork_ordu.thruk_kemikkiran.etkiledigi_ozellik,"saldiri")==0)
            {
                ToplamMizrakciHasar=ToplamMizrakciHasar*(ork_ordu.thruk_kemikkiran.etki_miktari+100)/100;
            }
            if (strcmp(ork_ordu.thruk_kemikkiran.etkiledigi_ozellik,"savunma")==0)
            {
                ToplamMizrakciSavunma=ToplamMizrakciSavunma*(ork_ordu.thruk_kemikkiran.etki_miktari+100)/100;
            }
            if (strcmp(ork_ordu.thruk_kemikkiran.etkiledigi_ozellik,"saglik")==0)
            {
                ToplamMizrakciSaglik=ToplamMizrakciSaglik*(ork_ordu.thruk_kemikkiran.etki_miktari+100)/100;
            }
            if (strcmp(ork_ordu.thruk_kemikkiran.etkiledigi_ozellik,"kritik_sans")==0)
            {
                ork_ordu.mizrakci.kritsans=ork_ordu.mizrakci.kritsans*(ork_ordu.thruk_kemikkiran.etki_miktari+100)/100;
            }
        }
        if (strcmp(ork_ordu.thruk_kemikkiran.etkiledigi_birim,"varg_binici")==0)
        {
            if (strcmp(ork_ordu.thruk_kemikkiran.etkiledigi_ozellik,"saldiri")==0)
            {
                ToplamVargBiniciHasar=ToplamVargBiniciHasar*(ork_ordu.thruk_kemikkiran.etki_miktari+100)/100;
            }
            if (strcmp(ork_ordu.thruk_kemikkiran.etkiledigi_ozellik,"savunma")==0)
            {
                ToplamVargBiniciSavunma=ToplamVargBiniciSavunma*(ork_ordu.thruk_kemikkiran.etki_miktari+100)/100;
            }
            if (strcmp(ork_ordu.thruk_kemikkiran.etkiledigi_ozellik,"saglik")==0)
            {
                ToplamVargBiniciSaglik=ToplamVargBiniciSaglik*(ork_ordu.thruk_kemikkiran.etki_miktari+100)/100;
            }
            if (strcmp(ork_ordu.thruk_kemikkiran.etkiledigi_ozellik,"kritik_sans")==0)
            {
                ork_ordu.varg_binici.kritsans=ork_ordu.varg_binici.kritsans*(ork_ordu.thruk_kemikkiran.etki_miktari+100)/100;
            }
        }
        if (strcmp(ork_ordu.thruk_kemikkiran.etkiledigi_birim,"troller")==0)
        {
            if (strcmp(ork_ordu.thruk_kemikkiran.etkiledigi_ozellik,"saldiri")==0)
            {
                ToplamTrolHasar=ToplamTrolHasar*(ork_ordu.thruk_kemikkiran.etki_miktari+100)/100;
            }
            if (strcmp(ork_ordu.thruk_kemikkiran.etkiledigi_ozellik,"savunma")==0)
            {
                ToplamTrolSavunma=ToplamTrolSavunma*(ork_ordu.thruk_kemikkiran.etki_miktari+100)/100;
            }
            if (strcmp(ork_ordu.thruk_kemikkiran.etkiledigi_ozellik,"saglik")==0)
            {
                ToplamTrolSaglik=ToplamTrolSaglik*(ork_ordu.thruk_kemikkiran.etki_miktari+100)/100;
            }
            if (strcmp(ork_ordu.thruk_kemikkiran.etkiledigi_ozellik,"kritik_sans")==0)
            {
                ork_ordu.troller.kritsans=ork_ordu.troller.kritsans*(ork_ordu.thruk_kemikkiran.etki_miktari+100)/100;
            }
        }
    }
    if (strcmp(ork_ordu.bulunankahraman.bulunan1,"Vrog_Kafakiran")==0)
    {
        if (strcmp(ork_ordu.vrog_kafakiran.etkiledigi_birim,"ork_dovuscu")==0)
        {
            if (strcmp(ork_ordu.vrog_kafakiran.etkiledigi_ozellik,"saldiri")==0)
            {
                ToplamOrgDovuscuHasar=ToplamOrgDovuscuHasar*(ork_ordu.vrog_kafakiran.etki_miktari+100)/100;
            }
            if (strcmp(ork_ordu.vrog_kafakiran.etkiledigi_ozellik,"savunma")==0)
            {
                ToplamOrgDovuscuSavunma=ToplamOrgDovuscuSavunma*(ork_ordu.vrog_kafakiran.etki_miktari+100)/100;
            }
            if (strcmp(ork_ordu.vrog_kafakiran.etkiledigi_ozellik,"saglik")==0)
            {
                ToplamOrgDovuscuSaglik=ToplamOrgDovuscuSaglik*(ork_ordu.vrog_kafakiran.etki_miktari+100)/100;
            }
            if (strcmp(ork_ordu.vrog_kafakiran.etkiledigi_ozellik,"kritik_sans")==0)
            {
                ork_ordu.ork_dovuscu.kritsans=ork_ordu.ork_dovuscu.kritsans*(ork_ordu.vrog_kafakiran.etki_miktari+100)/100;
            }
        }
        if (strcmp(ork_ordu.vrog_kafakiran.etkiledigi_birim,"mizrakci")==0)
        {
            if (strcmp(ork_ordu.vrog_kafakiran.etkiledigi_ozellik,"saldiri")==0)
            {
                ToplamMizrakciHasar=ToplamMizrakciHasar*(ork_ordu.vrog_kafakiran.etki_miktari+100)/100;
            }
            if (strcmp(ork_ordu.vrog_kafakiran.etkiledigi_ozellik,"savunma")==0)
            {
                ToplamMizrakciSavunma=ToplamMizrakciSavunma*(ork_ordu.vrog_kafakiran.etki_miktari+100)/100;
            }
            if (strcmp(ork_ordu.vrog_kafakiran.etkiledigi_ozellik,"saglik")==0)
            {
                ToplamMizrakciSaglik=ToplamMizrakciSaglik*(ork_ordu.vrog_kafakiran.etki_miktari+100)/100;
            }
            if (strcmp(ork_ordu.vrog_kafakiran.etkiledigi_ozellik,"kritik_sans")==0)
            {
                ork_ordu.mizrakci.kritsans=ork_ordu.mizrakci.kritsans*(ork_ordu.vrog_kafakiran.etki_miktari+100)/100;
            }
        }
        if (strcmp(ork_ordu.vrog_kafakiran.etkiledigi_birim,"varg_binici")==0)
        {
            if (strcmp(ork_ordu.vrog_kafakiran.etkiledigi_ozellik,"saldiri")==0)
            {
                ToplamVargBiniciHasar=ToplamVargBiniciHasar*(ork_ordu.vrog_kafakiran.etki_miktari+100)/100;
            }
            if (strcmp(ork_ordu.vrog_kafakiran.etkiledigi_ozellik,"savunma")==0)
            {
                ToplamVargBiniciSavunma=ToplamVargBiniciSavunma*(ork_ordu.vrog_kafakiran.etki_miktari+100)/100;
            }
            if (strcmp(ork_ordu.vrog_kafakiran.etkiledigi_ozellik,"saglik")==0)
            {
                ToplamVargBiniciSaglik=ToplamVargBiniciSaglik*(ork_ordu.vrog_kafakiran.etki_miktari+100)/100;
            }
            if (strcmp(ork_ordu.vrog_kafakiran.etkiledigi_ozellik,"kritik_sans")==0)
            {
                ork_ordu.varg_binici.kritsans=ork_ordu.varg_binici.kritsans*(ork_ordu.vrog_kafakiran.etki_miktari+100)/100;
            }
        }
        if (strcmp(ork_ordu.vrog_kafakiran.etkiledigi_birim,"troller")==0)
        {
            if (strcmp(ork_ordu.vrog_kafakiran.etkiledigi_ozellik,"saldiri")==0)
            {
                ToplamTrolHasar=ToplamTrolHasar*(ork_ordu.vrog_kafakiran.etki_miktari+100)/100;
            }
            if (strcmp(ork_ordu.vrog_kafakiran.etkiledigi_ozellik,"savunma")==0)
            {
                ToplamTrolSavunma=ToplamTrolSavunma*(ork_ordu.vrog_kafakiran.etki_miktari+100)/100;
            }
            if (strcmp(ork_ordu.vrog_kafakiran.etkiledigi_ozellik,"saglik")==0)
            {
                ToplamTrolSaglik=ToplamTrolSaglik*(ork_ordu.vrog_kafakiran.etki_miktari+100)/100;
            }
            if (strcmp(ork_ordu.vrog_kafakiran.etkiledigi_ozellik,"kritik_sans")==0)
            {
                ork_ordu.troller.kritsans=ork_ordu.troller.kritsans*(ork_ordu.vrog_kafakiran.etki_miktari+100)/100;
            }
        }
    }
    if (strcmp(ork_ordu.bulunankahraman.bulunan1,"Ugar_Zalim")==0)
    {
        if (strcmp(ork_ordu.ugar_zalim.etkiledigi_birim,"ork_dovuscu")==0)
        {
            if (strcmp(ork_ordu.ugar_zalim.etkiledigi_ozellik,"saldiri")==0)
            {
                ToplamOrgDovuscuHasar=ToplamOrgDovuscuHasar*(ork_ordu.ugar_zalim.etki_miktari+100)/100;
            }
            if (strcmp(ork_ordu.ugar_zalim.etkiledigi_ozellik,"savunma")==0)
            {
                ToplamOrgDovuscuSavunma=ToplamOrgDovuscuSavunma*(ork_ordu.ugar_zalim.etki_miktari+100)/100;
            }
            if (strcmp(ork_ordu.ugar_zalim.etkiledigi_ozellik,"saglik")==0)
            {
                ToplamOrgDovuscuSaglik=ToplamOrgDovuscuSaglik*(ork_ordu.ugar_zalim.etki_miktari+100)/100;
            }
            if (strcmp(ork_ordu.ugar_zalim.etkiledigi_ozellik,"kritik_sans")==0)
            {
                ork_ordu.ork_dovuscu.kritsans=ork_ordu.ork_dovuscu.kritsans*(ork_ordu.ugar_zalim.etki_miktari+100)/100;
            }
        }
        if (strcmp(ork_ordu.ugar_zalim.etkiledigi_birim,"mizrakci")==0)
        {
            if (strcmp(ork_ordu.ugar_zalim.etkiledigi_ozellik,"saldiri")==0)
            {
                ToplamMizrakciHasar=ToplamMizrakciHasar*(ork_ordu.ugar_zalim.etki_miktari+100)/100;
            }
            if (strcmp(ork_ordu.ugar_zalim.etkiledigi_ozellik,"savunma")==0)
            {
                ToplamMizrakciSavunma=ToplamMizrakciSavunma*(ork_ordu.ugar_zalim.etki_miktari+100)/100;
            }
            if (strcmp(ork_ordu.ugar_zalim.etkiledigi_ozellik,"saglik")==0)
            {
                ToplamMizrakciSaglik=ToplamMizrakciSaglik*(ork_ordu.ugar_zalim.etki_miktari+100)/100;
            }
            if (strcmp(ork_ordu.ugar_zalim.etkiledigi_ozellik,"kritik_sans")==0)
            {
                ork_ordu.mizrakci.kritsans=ork_ordu.mizrakci.kritsans*(ork_ordu.ugar_zalim.etki_miktari+100)/100;
            }
        }
        if (strcmp(ork_ordu.ugar_zalim.etkiledigi_birim,"varg_binici")==0)
        {
            if (strcmp(ork_ordu.ugar_zalim.etkiledigi_ozellik,"saldiri")==0)
            {
                ToplamVargBiniciHasar=ToplamVargBiniciHasar*(ork_ordu.ugar_zalim.etki_miktari+100)/100;
            }
            if (strcmp(ork_ordu.ugar_zalim.etkiledigi_ozellik,"savunma")==0)
            {
                ToplamVargBiniciSavunma=ToplamVargBiniciSavunma*(ork_ordu.ugar_zalim.etki_miktari+100)/100;
            }
            if (strcmp(ork_ordu.ugar_zalim.etkiledigi_ozellik,"saglik")==0)
            {
                ToplamVargBiniciSaglik=ToplamVargBiniciSaglik*(ork_ordu.ugar_zalim.etki_miktari+100)/100;
            }
            if (strcmp(ork_ordu.ugar_zalim.etkiledigi_ozellik,"kritik_sans")==0)
            {
                ork_ordu.varg_binici.kritsans=ork_ordu.varg_binici.kritsans*(ork_ordu.ugar_zalim.etki_miktari+100)/100;
            }
        }
        if (strcmp(ork_ordu.ugar_zalim.etkiledigi_birim,"troller")==0)
        {
            if (strcmp(ork_ordu.ugar_zalim.etkiledigi_ozellik,"saldiri")==0)
            {
                ToplamTrolHasar=ToplamTrolHasar*(ork_ordu.ugar_zalim.etki_miktari+100)/100;
            }
            if (strcmp(ork_ordu.ugar_zalim.etkiledigi_ozellik,"savunma")==0)
            {
                ToplamTrolSavunma=ToplamTrolSavunma*(ork_ordu.ugar_zalim.etki_miktari+100)/100;
            }
            if (strcmp(ork_ordu.ugar_zalim.etkiledigi_ozellik,"saglik")==0)
            {
                ToplamTrolSaglik=ToplamTrolSaglik*(ork_ordu.ugar_zalim.etki_miktari+100)/100;
            }
            if (strcmp(ork_ordu.ugar_zalim.etkiledigi_ozellik,"kritik_sans")==0)
            {
                ork_ordu.troller.kritsans=ork_ordu.troller.kritsans*(ork_ordu.ugar_zalim.etki_miktari+100)/100;
            }
        }
        if (strcmp(ork_ordu.ugar_zalim.etkiledigi_birim,"tum_birimler")==0)
        {
            if (strcmp(ork_ordu.ugar_zalim.etkiledigi_ozellik,"saldiri")==0)
            {
                ToplamTrolHasar=ToplamTrolHasar*(ork_ordu.ugar_zalim.etki_miktari+100)/100;
            }
            if (strcmp(ork_ordu.ugar_zalim.etkiledigi_ozellik,"savunma")==0)
            {
                ToplamTrolSavunma=ToplamTrolSavunma*(ork_ordu.ugar_zalim.etki_miktari+100)/100;
                ToplamOrgDovuscuSavunma=ToplamOrgDovuscuSavunma*(ork_ordu.ugar_zalim.etki_miktari+100)/100;
                ToplamMizrakciSavunma=ToplamMizrakciSavunma*(ork_ordu.ugar_zalim.etki_miktari+100)/100;
                ToplamVargBiniciSavunma=ToplamVargBiniciSavunma*(ork_ordu.ugar_zalim.etki_miktari+100)/100;
            }
            if (strcmp(ork_ordu.ugar_zalim.etkiledigi_ozellik,"saglik")==0)
            {
                ToplamTrolSaglik=ToplamTrolSaglik*(ork_ordu.ugar_zalim.etki_miktari+100)/100;
            }
            if (strcmp(ork_ordu.ugar_zalim.etkiledigi_ozellik,"kritik_sans")==0)
            {
                ork_ordu.troller.kritsans=ork_ordu.troller.kritsans*(ork_ordu.ugar_zalim.etki_miktari+100)/100;
            }
        }
    }
    if (strcmp(insan_ordu.bulunancanavar.bulunan1,"Ejderha")==0)
    {
        if (strcmp(insan_ordu.ejderha.etkiledigi_birim,"okcu")==0)
        {
            if (strcmp(insan_ordu.ejderha.etkiledigi_ozellik,"saldiri")==0)
            {
                ToplamOkcuHasar=ToplamOkcuHasar*(insan_ordu.ejderha.etki_miktari+100)/100;
            }
            if (strcmp(insan_ordu.ejderha.etkiledigi_ozellik,"savunma")==0)
            {
                ToplamOkcuSavunma=ToplamOkcuSavunma*(insan_ordu.ejderha.etki_miktari+100)/100;
            }
            if (strcmp(insan_ordu.ejderha.etkiledigi_ozellik,"saglik")==0)
            {
                ToplamOkcuSaglik=ToplamOkcuSaglik*(insan_ordu.ejderha.etki_miktari+100)/100;
            }
            if (strcmp(insan_ordu.ejderha.etkiledigi_ozellik,"kritik_sans")==0)
            {
                insan_ordu.okcu.kritsans=insan_ordu.okcu.kritsans*(insan_ordu.ejderha.etki_miktari+100)/100;
            }
        }
        if (strcmp(insan_ordu.ejderha.etkiledigi_birim,"piyade")==0)
        {
            if (strcmp(insan_ordu.ejderha.etkiledigi_ozellik,"saldiri")==0)
            {
                ToplamPiyadeHasar=ToplamPiyadeHasar*(insan_ordu.ejderha.etki_miktari+100)/100;
            }
            if (strcmp(insan_ordu.ejderha.etkiledigi_ozellik,"savunma")==0)
            {
                ToplamPiyadeSavunma=ToplamPiyadeSavunma*(insan_ordu.ejderha.etki_miktari+100)/100;
            }
            if (strcmp(insan_ordu.ejderha.etkiledigi_ozellik,"saglik")==0)
            {
                ToplamPiyadeSaglik=ToplamPiyadeSaglik*(insan_ordu.ejderha.etki_miktari+100)/100;
            }
            if (strcmp(insan_ordu.ejderha.etkiledigi_ozellik,"kritik_sans")==0)
            {
                insan_ordu.piyade.kritsans=insan_ordu.piyade.kritsans*(insan_ordu.ejderha.etki_miktari+100)/100;
            }
        }
        if (strcmp(insan_ordu.ejderha.etkiledigi_birim,"suvari")==0)
        {
            if (strcmp(insan_ordu.ejderha.etkiledigi_ozellik,"saldiri")==0)
            {
                ToplamSuvariHasar=ToplamSuvariHasar*(insan_ordu.ejderha.etki_miktari+100)/100;
            }
            if (strcmp(insan_ordu.ejderha.etkiledigi_ozellik,"savunma")==0)
            {
                ToplamSuvariSavunma=ToplamSuvariSavunma*(insan_ordu.ejderha.etki_miktari+100)/100;
            }
            if (strcmp(insan_ordu.ejderha.etkiledigi_ozellik,"saglik")==0)
            {
                ToplamSuvariSaglik=ToplamSuvariSaglik*(insan_ordu.ejderha.etki_miktari+100)/100;
            }
            if (strcmp(insan_ordu.ejderha.etkiledigi_ozellik,"kritik_sans")==0)
            {
                insan_ordu.suvari.kritsans=insan_ordu.suvari.kritsans*(insan_ordu.ejderha.etki_miktari+100)/100;
            }
        }
        if (strcmp(insan_ordu.ejderha.etkiledigi_birim,"kusatma_makine")==0)
        {
            if (strcmp(insan_ordu.ejderha.etkiledigi_ozellik,"saldiri")==0)
            {
                ToplamKusatmaHasar=ToplamKusatmaHasar*(insan_ordu.ejderha.etki_miktari+100)/100;
            }
            if (strcmp(insan_ordu.ejderha.etkiledigi_ozellik,"savunma")==0)
            {
                ToplamKusatmaSavunma=ToplamKusatmaSavunma*(insan_ordu.ejderha.etki_miktari+100)/100;
            }
            if (strcmp(insan_ordu.ejderha.etkiledigi_ozellik,"saglik")==0)
            {
                ToplamKusatmaSaglik=ToplamKusatmaSaglik*(insan_ordu.ejderha.etki_miktari+100)/100;
            }
            if (strcmp(insan_ordu.ejderha.etkiledigi_ozellik,"kritik_sans")==0)
            {
                insan_ordu.kusatma_makine.kritsans=insan_ordu.kusatma_makine.kritsans*(insan_ordu.tugrul_bey.etki_miktari+100)/100;
            }
        }
    }
    if (strcmp(insan_ordu.bulunancanavar.bulunan1,"Agri_Dagi_Devleri")==0)
    {
        if (strcmp(insan_ordu.agri_dagi_devleri.etkiledigi_birim,"okcu")==0)
        {
            if (strcmp(insan_ordu.agri_dagi_devleri.etkiledigi_ozellik,"saldiri")==0)
            {
                ToplamOkcuHasar=ToplamOkcuHasar*(insan_ordu.agri_dagi_devleri.etki_miktari+100)/100;
            }
            if (strcmp(insan_ordu.agri_dagi_devleri.etkiledigi_ozellik,"savunma")==0)
            {
                ToplamOkcuSavunma=ToplamOkcuSavunma*(insan_ordu.agri_dagi_devleri.etki_miktari+100)/100;
            }
            if (strcmp(insan_ordu.agri_dagi_devleri.etkiledigi_ozellik,"saglik")==0)
            {
                ToplamOkcuSaglik=ToplamOkcuSaglik*(insan_ordu.agri_dagi_devleri.etki_miktari+100)/100;
            }
            if (strcmp(insan_ordu.agri_dagi_devleri.etkiledigi_ozellik,"kritik_sans")==0)
            {
                insan_ordu.okcu.kritsans=insan_ordu.okcu.kritsans*(insan_ordu.agri_dagi_devleri.etki_miktari+100)/100;
            }
        }
        if (strcmp(insan_ordu.agri_dagi_devleri.etkiledigi_birim,"piyade")==0)
        {
            if (strcmp(insan_ordu.agri_dagi_devleri.etkiledigi_ozellik,"saldiri")==0)
            {
                ToplamPiyadeHasar=ToplamPiyadeHasar*(insan_ordu.agri_dagi_devleri.etki_miktari+100)/100;
            }
            if (strcmp(insan_ordu.agri_dagi_devleri.etkiledigi_ozellik,"savunma")==0)
            {
                ToplamPiyadeSavunma=ToplamPiyadeSavunma*(insan_ordu.agri_dagi_devleri.etki_miktari+100)/100;
            }
            if (strcmp(insan_ordu.agri_dagi_devleri.etkiledigi_ozellik,"saglik")==0)
            {
                ToplamPiyadeSaglik=ToplamPiyadeSaglik*(insan_ordu.agri_dagi_devleri.etki_miktari+100)/100;
            }
            if (strcmp(insan_ordu.agri_dagi_devleri.etkiledigi_ozellik,"kritik_sans")==0)
            {
                insan_ordu.piyade.kritsans=insan_ordu.piyade.kritsans*(insan_ordu.agri_dagi_devleri.etki_miktari+100)/100;
            }
        }
        if (strcmp(insan_ordu.agri_dagi_devleri.etkiledigi_birim,"suvari")==0)
        {
            if (strcmp(insan_ordu.agri_dagi_devleri.etkiledigi_ozellik,"saldiri")==0)
            {
                ToplamSuvariHasar=ToplamSuvariHasar*(insan_ordu.agri_dagi_devleri.etki_miktari+100)/100;
            }
            if (strcmp(insan_ordu.agri_dagi_devleri.etkiledigi_ozellik,"savunma")==0)
            {
                ToplamSuvariSavunma=ToplamSuvariSavunma*(insan_ordu.agri_dagi_devleri.etki_miktari+100)/100;
            }
            if (strcmp(insan_ordu.agri_dagi_devleri.etkiledigi_ozellik,"saglik")==0)
            {
                ToplamSuvariSaglik=ToplamSuvariSaglik*(insan_ordu.agri_dagi_devleri.etki_miktari+100)/100;
            }
            if (strcmp(insan_ordu.agri_dagi_devleri.etkiledigi_ozellik,"kritik_sans")==0)
            {
                insan_ordu.suvari.kritsans=insan_ordu.suvari.kritsans*(insan_ordu.agri_dagi_devleri.etki_miktari+100)/100;
            }
        }
        if (strcmp(insan_ordu.agri_dagi_devleri.etkiledigi_birim,"kusatma_makine")==0)
        {
            if (strcmp(insan_ordu.agri_dagi_devleri.etkiledigi_ozellik,"saldiri")==0)
            {
                ToplamKusatmaHasar=ToplamKusatmaHasar*(insan_ordu.agri_dagi_devleri.etki_miktari+100)/100;
            }
            if (strcmp(insan_ordu.agri_dagi_devleri.etkiledigi_ozellik,"savunma")==0)
            {
                ToplamKusatmaSavunma=ToplamKusatmaSavunma*(insan_ordu.agri_dagi_devleri.etki_miktari+100)/100;
            }
            if (strcmp(insan_ordu.agri_dagi_devleri.etkiledigi_ozellik,"saglik")==0)
            {
                ToplamKusatmaSaglik=ToplamKusatmaSaglik*(insan_ordu.agri_dagi_devleri.etki_miktari+100)/100;
            }
            if (strcmp(insan_ordu.agri_dagi_devleri.etkiledigi_ozellik,"kritik_sans")==0)
            {
                insan_ordu.kusatma_makine.kritsans=insan_ordu.kusatma_makine.kritsans*(insan_ordu.agri_dagi_devleri.etki_miktari+100)/100;
            }
        }
    }
    if (strcmp(insan_ordu.bulunancanavar.bulunan1,"Tepegoz")==0)
    {
        if (strcmp(insan_ordu.tepegoz.etkiledigi_birim,"okcu")==0)
        {
            if (strcmp(insan_ordu.tepegoz.etkiledigi_ozellik,"saldiri")==0)
            {
                ToplamOkcuHasar=ToplamOkcuHasar*(insan_ordu.tepegoz.etki_miktari+100)/100;
            }
            if (strcmp(insan_ordu.tepegoz.etkiledigi_ozellik,"savunma")==0)
            {
                ToplamOkcuSavunma=ToplamOkcuSavunma*(insan_ordu.tepegoz.etki_miktari+100)/100;
            }
            if (strcmp(insan_ordu.tepegoz.etkiledigi_ozellik,"saglik")==0)
            {
                ToplamOkcuSaglik=ToplamOkcuSaglik*(insan_ordu.tepegoz.etki_miktari+100)/100;
            }
            if (strcmp(insan_ordu.tepegoz.etkiledigi_ozellik,"kritik_sans")==0)
            {
                insan_ordu.okcu.kritsans=insan_ordu.okcu.kritsans*(insan_ordu.tepegoz.etki_miktari+100)/100;
            }
        }
        if (strcmp(insan_ordu.tepegoz.etkiledigi_birim,"piyade")==0)
        {
            if (strcmp(insan_ordu.tepegoz.etkiledigi_ozellik,"saldiri")==0)
            {
                ToplamPiyadeHasar=ToplamPiyadeHasar*(insan_ordu.tepegoz.etki_miktari+100)/100;
            }
            if (strcmp(insan_ordu.tepegoz.etkiledigi_ozellik,"savunma")==0)
            {
                ToplamPiyadeSavunma=ToplamPiyadeSavunma*(insan_ordu.tepegoz.etki_miktari+100)/100;
            }
            if (strcmp(insan_ordu.tepegoz.etkiledigi_ozellik,"saglik")==0)
            {
                ToplamPiyadeSaglik=ToplamPiyadeSaglik*(insan_ordu.tepegoz.etki_miktari+100)/100;
            }
            if (strcmp(insan_ordu.tepegoz.etkiledigi_ozellik,"kritik_sans")==0)
            {
                insan_ordu.piyade.kritsans=insan_ordu.piyade.kritsans*(insan_ordu.tepegoz.etki_miktari+100)/100;
            }
        }
        if (strcmp(insan_ordu.tepegoz.etkiledigi_birim,"suvari")==0)
        {
            if (strcmp(insan_ordu.tepegoz.etkiledigi_ozellik,"saldiri")==0)
            {
                ToplamSuvariHasar=ToplamSuvariHasar*(insan_ordu.tepegoz.etki_miktari+100)/100;
            }
            if (strcmp(insan_ordu.tepegoz.etkiledigi_ozellik,"savunma")==0)
            {
                ToplamSuvariSavunma=ToplamSuvariSavunma*(insan_ordu.tepegoz.etki_miktari+100)/100;
            }
            if (strcmp(insan_ordu.tepegoz.etkiledigi_ozellik,"saglik")==0)
            {
                ToplamSuvariSaglik=ToplamSuvariSaglik*(insan_ordu.tepegoz.etki_miktari+100)/100;
            }
            if (strcmp(insan_ordu.tepegoz.etkiledigi_ozellik,"kritik_sans")==0)
            {
                insan_ordu.suvari.kritsans=insan_ordu.suvari.kritsans*(insan_ordu.tepegoz.etki_miktari+100)/100;
            }
        }
        if (strcmp(insan_ordu.tepegoz.etkiledigi_birim,"kusatma_makine")==0)
        {
            if (strcmp(insan_ordu.tepegoz.etkiledigi_ozellik,"saldiri")==0)
            {
                ToplamKusatmaHasar=ToplamKusatmaHasar*(insan_ordu.tepegoz.etki_miktari+100)/100;
            }
            if (strcmp(insan_ordu.tepegoz.etkiledigi_ozellik,"savunma")==0)
            {
                ToplamKusatmaSavunma=ToplamKusatmaSavunma*(insan_ordu.tepegoz.etki_miktari+100)/100;
            }
            if (strcmp(insan_ordu.tepegoz.etkiledigi_ozellik,"saglik")==0)
            {
                ToplamKusatmaSaglik=ToplamKusatmaSaglik*(insan_ordu.tepegoz.etki_miktari+100)/100;
            }
            if (strcmp(insan_ordu.tepegoz.etkiledigi_ozellik,"kritik_sans")==0)
            {
                insan_ordu.kusatma_makine.kritsans=insan_ordu.kusatma_makine.kritsans*(insan_ordu.tepegoz.etki_miktari+100)/100;
            }
        }
    }
    if (strcmp(insan_ordu.bulunancanavar.bulunan1,"Karakurt")==0)
    {
        if (strcmp(insan_ordu.karakurt.etkiledigi_birim,"okcu")==0)
        {
            if (strcmp(insan_ordu.karakurt.etkiledigi_ozellik,"saldiri")==0)
            {
                ToplamOkcuHasar=ToplamOkcuHasar*(insan_ordu.karakurt.etki_miktari+100)/100;
            }
            if (strcmp(insan_ordu.karakurt.etkiledigi_ozellik,"savunma")==0)
            {
                ToplamOkcuSavunma=ToplamOkcuSavunma*(insan_ordu.karakurt.etki_miktari+100)/100;
            }
            if (strcmp(insan_ordu.karakurt.etkiledigi_ozellik,"saglik")==0)
            {
                ToplamOkcuSaglik=ToplamOkcuSaglik*(insan_ordu.karakurt.etki_miktari+100)/100;
            }
            if (strcmp(insan_ordu.karakurt.etkiledigi_ozellik,"kritik_sans")==0)
            {
                insan_ordu.okcu.kritsans=insan_ordu.okcu.kritsans*(insan_ordu.karakurt.etki_miktari+100)/100;
            }
        }
        if (strcmp(insan_ordu.karakurt.etkiledigi_birim,"piyade")==0)
        {
            if (strcmp(insan_ordu.karakurt.etkiledigi_ozellik,"saldiri")==0)
            {
                ToplamPiyadeHasar=ToplamPiyadeHasar*(insan_ordu.karakurt.etki_miktari+100)/100;
            }
            if (strcmp(insan_ordu.karakurt.etkiledigi_ozellik,"savunma")==0)
            {
                ToplamPiyadeSavunma=ToplamPiyadeSavunma*(insan_ordu.karakurt.etki_miktari+100)/100;
            }
            if (strcmp(insan_ordu.karakurt.etkiledigi_ozellik,"saglik")==0)
            {
                ToplamPiyadeSaglik=ToplamPiyadeSaglik*(insan_ordu.karakurt.etki_miktari+100)/100;
            }
            if (strcmp(insan_ordu.karakurt.etkiledigi_ozellik,"kritik_sans")==0)
            {
                insan_ordu.piyade.kritsans=insan_ordu.piyade.kritsans*(insan_ordu.karakurt.etki_miktari+100)/100;
            }
        }
        if (strcmp(insan_ordu.karakurt.etkiledigi_birim,"suvari")==0)
        {
            if (strcmp(insan_ordu.tepegoz.etkiledigi_ozellik,"saldiri")==0)
            {
                ToplamSuvariHasar=ToplamSuvariHasar*(insan_ordu.karakurt.etki_miktari+100)/100;
            }
            if (strcmp(insan_ordu.karakurt.etkiledigi_ozellik,"savunma")==0)
            {
                ToplamSuvariSavunma=ToplamSuvariSavunma*(insan_ordu.karakurt.etki_miktari+100)/100;
            }
            if (strcmp(insan_ordu.karakurt.etkiledigi_ozellik,"saglik")==0)
            {
                ToplamSuvariSaglik=ToplamSuvariSaglik*(insan_ordu.karakurt.etki_miktari+100)/100;
            }
            if (strcmp(insan_ordu.karakurt.etkiledigi_ozellik,"kritik_sans")==0)
            {
                insan_ordu.suvari.kritsans=insan_ordu.suvari.kritsans*(insan_ordu.karakurt.etki_miktari+100)/100;
            }
        }
        if (strcmp(insan_ordu.karakurt.etkiledigi_birim,"kusatma_makine")==0)
        {
            if (strcmp(insan_ordu.karakurt.etkiledigi_ozellik,"saldiri")==0)
            {
                ToplamKusatmaHasar=ToplamKusatmaHasar*(insan_ordu.karakurt.etki_miktari+100)/100;
            }
            if (strcmp(insan_ordu.karakurt.etkiledigi_ozellik,"savunma")==0)
            {
                ToplamKusatmaSavunma=ToplamKusatmaSavunma*(insan_ordu.karakurt.etki_miktari+100)/100;
            }
            if (strcmp(insan_ordu.karakurt.etkiledigi_ozellik,"saglik")==0)
            {
                ToplamKusatmaSaglik=ToplamKusatmaSaglik*(insan_ordu.karakurt.etki_miktari+100)/100;
            }
            if (strcmp(insan_ordu.karakurt.etkiledigi_ozellik,"kritik_sans")==0)
            {
                insan_ordu.kusatma_makine.kritsans=insan_ordu.kusatma_makine.kritsans*(insan_ordu.karakurt.etki_miktari+100)/100;
            }
        }
    }
    if (strcmp(insan_ordu.bulunancanavar.bulunan1,"Samur")==0)
    {
        if (strcmp(insan_ordu.samur.etkiledigi_birim,"okcu")==0)
        {
            if (strcmp(insan_ordu.samur.etkiledigi_ozellik,"saldiri")==0)
            {
                ToplamOkcuHasar=ToplamOkcuHasar*(insan_ordu.samur.etki_miktari+100)/100;
            }
            if (strcmp(insan_ordu.samur.etkiledigi_ozellik,"savunma")==0)
            {
                ToplamOkcuSavunma=ToplamOkcuSavunma*(insan_ordu.samur.etki_miktari+100)/100;
            }
            if (strcmp(insan_ordu.samur.etkiledigi_ozellik,"saglik")==0)
            {
                ToplamOkcuSaglik=ToplamOkcuSaglik*(insan_ordu.samur.etki_miktari+100)/100;
            }
            if (strcmp(insan_ordu.samur.etkiledigi_ozellik,"kritik_sans")==0)
            {
                insan_ordu.okcu.kritsans=insan_ordu.okcu.kritsans*(insan_ordu.samur.etki_miktari+100)/100;
            }
        }
        if (strcmp(insan_ordu.samur.etkiledigi_birim,"piyade")==0)
        {
            if (strcmp(insan_ordu.samur.etkiledigi_ozellik,"saldiri")==0)
            {
                ToplamPiyadeHasar=ToplamPiyadeHasar*(insan_ordu.samur.etki_miktari+100)/100;
            }
            if (strcmp(insan_ordu.samur.etkiledigi_ozellik,"savunma")==0)
            {
                ToplamPiyadeSavunma=ToplamPiyadeSavunma*(insan_ordu.samur.etki_miktari+100)/100;
            }
            if (strcmp(insan_ordu.samur.etkiledigi_ozellik,"saglik")==0)
            {
                ToplamPiyadeSaglik=ToplamPiyadeSaglik*(insan_ordu.samur.etki_miktari+100)/100;
            }
            if (strcmp(insan_ordu.samur.etkiledigi_ozellik,"kritik_sans")==0)
            {
                insan_ordu.piyade.kritsans=insan_ordu.piyade.kritsans*(insan_ordu.samur.etki_miktari+100)/100;
            }
        }
        if (strcmp(insan_ordu.samur.etkiledigi_birim,"suvari")==0)
        {
            if (strcmp(insan_ordu.samur.etkiledigi_ozellik,"saldiri")==0)
            {
                ToplamSuvariHasar=ToplamSuvariHasar*(insan_ordu.samur.etki_miktari+100)/100;
            }
            if (strcmp(insan_ordu.samur.etkiledigi_ozellik,"savunma")==0)
            {
                ToplamSuvariSavunma=ToplamSuvariSavunma*(insan_ordu.samur.etki_miktari+100)/100;
            }
            if (strcmp(insan_ordu.samur.etkiledigi_ozellik,"saglik")==0)
            {
                ToplamSuvariSaglik=ToplamSuvariSaglik*(insan_ordu.samur.etki_miktari+100)/100;
            }
            if (strcmp(insan_ordu.samur.etkiledigi_ozellik,"kritik_sans")==0)
            {
                insan_ordu.suvari.kritsans=insan_ordu.suvari.kritsans*(insan_ordu.samur.etki_miktari+100)/100;
            }
        }
        if (strcmp(insan_ordu.samur.etkiledigi_birim,"kusatma_makine")==0)
        {
            if (strcmp(insan_ordu.samur.etkiledigi_ozellik,"saldiri")==0)
            {
                ToplamKusatmaHasar=ToplamKusatmaHasar*(insan_ordu.samur.etki_miktari+100)/100;
            }
            if (strcmp(insan_ordu.samur.etkiledigi_ozellik,"savunma")==0)
            {
                ToplamKusatmaSavunma=ToplamKusatmaSavunma*(insan_ordu.samur.etki_miktari+100)/100;
            }
            if (strcmp(insan_ordu.samur.etkiledigi_ozellik,"saglik")==0)
            {
                ToplamKusatmaSaglik=ToplamKusatmaSaglik*(insan_ordu.samur.etki_miktari+100)/100;
            }
            if (strcmp(insan_ordu.samur.etkiledigi_ozellik,"kritik_sans")==0)
            {
                insan_ordu.kusatma_makine.kritsans=insan_ordu.kusatma_makine.kritsans*(insan_ordu.samur.etki_miktari+100)/100;
            }
        }
    }
    if (strcmp(ork_ordu.bulunancanavar.bulunan1,"Kara_Troll")==0)
    {
        if (strcmp(ork_ordu.kara_troll.etkiledigi_birim,"ork_dovuscu")==0)
        {
            if (strcmp(ork_ordu.kara_troll.etkiledigi_ozellik,"saldiri")==0)
            {
                ToplamOrgDovuscuHasar=ToplamOrgDovuscuHasar*(ork_ordu.kara_troll.etki_miktari+100)/100;
            }
            if (strcmp(ork_ordu.kara_troll.etkiledigi_ozellik,"savunma")==0)
            {
                ToplamOrgDovuscuSavunma=ToplamOrgDovuscuSavunma*(ork_ordu.kara_troll.etki_miktari+100)/100;
            }
            if (strcmp(ork_ordu.kara_troll.etkiledigi_ozellik,"saglik")==0)
            {
                ToplamOrgDovuscuSaglik=ToplamOrgDovuscuSaglik*(ork_ordu.kara_troll.etki_miktari+100)/100;
            }
            if (strcmp(ork_ordu.kara_troll.etkiledigi_ozellik,"kritik_sans")==0)
            {
                ork_ordu.ork_dovuscu.kritsans=ork_ordu.ork_dovuscu.kritsans*(ork_ordu.kara_troll.etki_miktari+100)/100;
            }
        }
        if (strcmp(ork_ordu.kara_troll.etkiledigi_birim,"mizrakci")==0)
        {
            if (strcmp(ork_ordu.kara_troll.etkiledigi_ozellik,"saldiri")==0)
            {
                ToplamMizrakciHasar=ToplamMizrakciHasar*(ork_ordu.kara_troll.etki_miktari+100)/100;
            }
            if (strcmp(ork_ordu.kara_troll.etkiledigi_ozellik,"savunma")==0)
            {
                ToplamMizrakciSavunma=ToplamMizrakciSavunma*(ork_ordu.kara_troll.etki_miktari+100)/100;
            }
            if (strcmp(ork_ordu.kara_troll.etkiledigi_ozellik,"saglik")==0)
            {
                ToplamMizrakciSaglik=ToplamMizrakciSaglik*(ork_ordu.kara_troll.etki_miktari+100)/100;
            }
            if (strcmp(ork_ordu.kara_troll.etkiledigi_ozellik,"kritik_sans")==0)
            {
                ork_ordu.mizrakci.kritsans=ork_ordu.mizrakci.kritsans*(ork_ordu.kara_troll.etki_miktari+100)/100;
            }
        }
        if (strcmp(ork_ordu.kara_troll.etkiledigi_birim,"varg_binici")==0)
        {
            if (strcmp(ork_ordu.kara_troll.etkiledigi_ozellik,"saldiri")==0)
            {
                ToplamVargBiniciHasar=ToplamVargBiniciHasar*(ork_ordu.kara_troll.etki_miktari+100)/100;
            }
            if (strcmp(ork_ordu.kara_troll.etkiledigi_ozellik,"savunma")==0)
            {
                ToplamVargBiniciSavunma=ToplamVargBiniciSavunma*(ork_ordu.kara_troll.etki_miktari+100)/100;
            }
            if (strcmp(ork_ordu.kara_troll.etkiledigi_ozellik,"saglik")==0)
            {
                ToplamVargBiniciSaglik=ToplamVargBiniciSaglik*(ork_ordu.kara_troll.etki_miktari+100)/100;
            }
            if (strcmp(ork_ordu.kara_troll.etkiledigi_ozellik,"kritik_sans")==0)
            {
                ork_ordu.varg_binici.kritsans=ork_ordu.varg_binici.kritsans*(ork_ordu.kara_troll.etki_miktari+100)/100;
            }
        }
        if (strcmp(ork_ordu.kara_troll.etkiledigi_birim,"troller")==0)
        {
            if (strcmp(ork_ordu.kara_troll.etkiledigi_ozellik,"saldiri")==0)
            {
                ToplamTrolHasar=ToplamTrolHasar*(ork_ordu.kara_troll.etki_miktari+100)/100;
            }
            if (strcmp(ork_ordu.kara_troll.etkiledigi_ozellik,"savunma")==0)
            {
                ToplamTrolSavunma=ToplamTrolSavunma*(ork_ordu.kara_troll.etki_miktari+100)/100;
            }
            if (strcmp(ork_ordu.kara_troll.etkiledigi_ozellik,"saglik")==0)
            {
                ToplamTrolSaglik=ToplamTrolSaglik*(ork_ordu.kara_troll.etki_miktari+100)/100;
            }
            if (strcmp(ork_ordu.kara_troll.etkiledigi_ozellik,"kritik_sans")==0)
            {
                ork_ordu.troller.kritsans=ork_ordu.troller.kritsans*(ork_ordu.kara_troll.etki_miktari+100)/100;
            }
        }
    }
    if (strcmp(ork_ordu.bulunancanavar.bulunan1,"Golge_Kurtlari")==0)
    {
        if (strcmp(ork_ordu.golge_kurtlari.etkiledigi_birim,"ork_dovuscu")==0)
        {
            if (strcmp(ork_ordu.golge_kurtlari.etkiledigi_ozellik,"saldiri")==0)
            {
                ToplamOrgDovuscuHasar=ToplamOrgDovuscuHasar*(ork_ordu.golge_kurtlari.etki_miktari+100)/100;
            }
            if (strcmp(ork_ordu.golge_kurtlari.etkiledigi_ozellik,"savunma")==0)
            {
                ToplamOrgDovuscuSavunma=ToplamOrgDovuscuSavunma*(ork_ordu.golge_kurtlari.etki_miktari+100)/100;
            }
            if (strcmp(ork_ordu.golge_kurtlari.etkiledigi_ozellik,"saglik")==0)
            {
                ToplamOrgDovuscuSaglik=ToplamOrgDovuscuSaglik*(ork_ordu.golge_kurtlari.etki_miktari+100)/100;
            }
            if (strcmp(ork_ordu.golge_kurtlari.etkiledigi_ozellik,"kritik_sans")==0)
            {
                ork_ordu.ork_dovuscu.kritsans=ork_ordu.ork_dovuscu.kritsans*(ork_ordu.golge_kurtlari.etki_miktari+100)/100;
            }
        }
        if (strcmp(ork_ordu.golge_kurtlari.etkiledigi_birim,"mizrakci")==0)
        {
            if (strcmp(ork_ordu.golge_kurtlari.etkiledigi_ozellik,"saldiri")==0)
            {
                ToplamMizrakciHasar=ToplamMizrakciHasar*(ork_ordu.golge_kurtlari.etki_miktari+100)/100;
            }
            if (strcmp(ork_ordu.golge_kurtlari.etkiledigi_ozellik,"savunma")==0)
            {
                ToplamMizrakciSavunma=ToplamMizrakciSavunma*(ork_ordu.golge_kurtlari.etki_miktari+100)/100;
            }
            if (strcmp(ork_ordu.golge_kurtlari.etkiledigi_ozellik,"saglik")==0)
            {
                ToplamMizrakciSaglik=ToplamMizrakciSaglik*(ork_ordu.golge_kurtlari.etki_miktari+100)/100;
            }
            if (strcmp(ork_ordu.golge_kurtlari.etkiledigi_ozellik,"kritik_sans")==0)
            {
                ork_ordu.mizrakci.kritsans=ork_ordu.mizrakci.kritsans*(ork_ordu.golge_kurtlari.etki_miktari+100)/100;
            }
        }
        if (strcmp(ork_ordu.golge_kurtlari.etkiledigi_birim,"varg_binici")==0)
        {
            if (strcmp(ork_ordu.golge_kurtlari.etkiledigi_ozellik,"saldiri")==0)
            {
                ToplamVargBiniciHasar=ToplamVargBiniciHasar*(ork_ordu.golge_kurtlari.etki_miktari+100)/100;
            }
            if (strcmp(ork_ordu.golge_kurtlari.etkiledigi_ozellik,"savunma")==0)
            {
                ToplamVargBiniciSavunma=ToplamVargBiniciSavunma*(ork_ordu.golge_kurtlari.etki_miktari+100)/100;
            }
            if (strcmp(ork_ordu.golge_kurtlari.etkiledigi_ozellik,"saglik")==0)
            {
                ToplamVargBiniciSaglik=ToplamVargBiniciSaglik*(ork_ordu.golge_kurtlari.etki_miktari+100)/100;
            }
            if (strcmp(ork_ordu.golge_kurtlari.etkiledigi_ozellik,"kritik_sans")==0)
            {
                ork_ordu.varg_binici.kritsans=ork_ordu.varg_binici.kritsans*(ork_ordu.golge_kurtlari.etki_miktari+100)/100;
            }
        }
        if (strcmp(ork_ordu.golge_kurtlari.etkiledigi_birim,"troller")==0)
        {
            if (strcmp(ork_ordu.golge_kurtlari.etkiledigi_ozellik,"saldiri")==0)
            {
                ToplamTrolHasar=ToplamTrolHasar*(ork_ordu.golge_kurtlari.etki_miktari+100)/100;
            }
            if (strcmp(ork_ordu.golge_kurtlari.etkiledigi_ozellik,"savunma")==0)
            {
                ToplamTrolSavunma=ToplamTrolSavunma*(ork_ordu.golge_kurtlari.etki_miktari+100)/100;
            }
            if (strcmp(ork_ordu.golge_kurtlari.etkiledigi_ozellik,"saglik")==0)
            {
                ToplamTrolSaglik=ToplamTrolSaglik*(ork_ordu.golge_kurtlari.etki_miktari+100)/100;
            }
            if (strcmp(ork_ordu.golge_kurtlari.etkiledigi_ozellik,"kritik_sans")==0)
            {
                ork_ordu.troller.kritsans=ork_ordu.troller.kritsans*(ork_ordu.golge_kurtlari.etki_miktari+100)/100;
            }
        }
    }
    if (strcmp(ork_ordu.bulunancanavar.bulunan1,"Camur_devleri")==0)
    {
        if (strcmp(ork_ordu.camur_devleri.etkiledigi_birim,"ork_dovuscu")==0)
        {
            if (strcmp(ork_ordu.camur_devleri.etkiledigi_ozellik,"saldiri")==0)
            {
                ToplamOrgDovuscuHasar=ToplamOrgDovuscuHasar*(ork_ordu.camur_devleri.etki_miktari+100)/100;
            }
            if (strcmp(ork_ordu.camur_devleri.etkiledigi_ozellik,"savunma")==0)
            {
                ToplamOrgDovuscuSavunma=ToplamOrgDovuscuSavunma*(ork_ordu.camur_devleri.etki_miktari+100)/100;
            }
            if (strcmp(ork_ordu.camur_devleri.etkiledigi_ozellik,"saglik")==0)
            {
                ToplamOrgDovuscuSaglik=ToplamOrgDovuscuSaglik*(ork_ordu.camur_devleri.etki_miktari+100)/100;
            }
            if (strcmp(ork_ordu.camur_devleri.etkiledigi_ozellik,"kritik_sans")==0)
            {
                ork_ordu.ork_dovuscu.kritsans=ork_ordu.ork_dovuscu.kritsans*(ork_ordu.camur_devleri.etki_miktari+100)/100;
            }
        }
        if (strcmp(ork_ordu.camur_devleri.etkiledigi_birim,"mizrakci")==0)
        {
            if (strcmp(ork_ordu.camur_devleri.etkiledigi_ozellik,"saldiri")==0)
            {
                ToplamMizrakciHasar=ToplamMizrakciHasar*(ork_ordu.camur_devleri.etki_miktari+100)/100;
            }
            if (strcmp(ork_ordu.camur_devleri.etkiledigi_ozellik,"savunma")==0)
            {
                ToplamMizrakciSavunma=ToplamMizrakciSavunma*(ork_ordu.camur_devleri.etki_miktari+100)/100;
            }
            if (strcmp(ork_ordu.camur_devleri.etkiledigi_ozellik,"saglik")==0)
            {
                ToplamMizrakciSaglik=ToplamMizrakciSaglik*(ork_ordu.camur_devleri.etki_miktari+100)/100;
            }
            if (strcmp(ork_ordu.camur_devleri.etkiledigi_ozellik,"kritik_sans")==0)
            {
                ork_ordu.mizrakci.kritsans=ork_ordu.mizrakci.kritsans*(ork_ordu.camur_devleri.etki_miktari+100)/100;
            }
        }
        if (strcmp(ork_ordu.camur_devleri.etkiledigi_birim,"varg_binici")==0)
        {
            if (strcmp(ork_ordu.camur_devleri.etkiledigi_ozellik,"saldiri")==0)
            {
                ToplamVargBiniciHasar=ToplamVargBiniciHasar*(ork_ordu.camur_devleri.etki_miktari+100)/100;
            }
            if (strcmp(ork_ordu.camur_devleri.etkiledigi_ozellik,"savunma")==0)
            {
                ToplamVargBiniciSavunma=ToplamVargBiniciSavunma*(ork_ordu.camur_devleri.etki_miktari+100)/100;
            }
            if (strcmp(ork_ordu.camur_devleri.etkiledigi_ozellik,"saglik")==0)
            {
                ToplamVargBiniciSaglik=ToplamVargBiniciSaglik*(ork_ordu.camur_devleri.etki_miktari+100)/100;
            }
            if (strcmp(ork_ordu.camur_devleri.etkiledigi_ozellik,"kritik_sans")==0)
            {
                ork_ordu.varg_binici.kritsans=ork_ordu.varg_binici.kritsans*(ork_ordu.camur_devleri.etki_miktari+100)/100;
            }
        }
        if (strcmp(ork_ordu.camur_devleri.etkiledigi_birim,"troller")==0)
        {
            if (strcmp(ork_ordu.camur_devleri.etkiledigi_ozellik,"saldiri")==0)
            {
                ToplamTrolHasar=ToplamTrolHasar*(ork_ordu.camur_devleri.etki_miktari+100)/100;
            }
            if (strcmp(ork_ordu.camur_devleri.etkiledigi_ozellik,"savunma")==0)
            {
                ToplamTrolSavunma=ToplamTrolSavunma*(ork_ordu.camur_devleri.etki_miktari+100)/100;
            }
            if (strcmp(ork_ordu.camur_devleri.etkiledigi_ozellik,"saglik")==0)
            {
                ToplamTrolSaglik=ToplamTrolSaglik*(ork_ordu.camur_devleri.etki_miktari+100)/100;
            }
            if (strcmp(ork_ordu.camur_devleri.etkiledigi_ozellik,"kritik_sans")==0)
            {
                ork_ordu.troller.kritsans=ork_ordu.troller.kritsans*(ork_ordu.camur_devleri.etki_miktari+100)/100;
            }
        }
    }
    if (strcmp(ork_ordu.bulunancanavar.bulunan1,"Camur_Devleri")==0)
    {
        if (strcmp(ork_ordu.camur_devleri.etkiledigi_birim,"ork_dovuscu")==0)
        {
            if (strcmp(ork_ordu.camur_devleri.etkiledigi_ozellik,"saldiri")==0)
            {
                ToplamOrgDovuscuHasar=ToplamOrgDovuscuHasar*(ork_ordu.camur_devleri.etki_miktari+100)/100;
            }
            if (strcmp(ork_ordu.camur_devleri.etkiledigi_ozellik,"savunma")==0)
            {
                ToplamOrgDovuscuSavunma=ToplamOrgDovuscuSavunma*(ork_ordu.camur_devleri.etki_miktari+100)/100;
            }
            if (strcmp(ork_ordu.camur_devleri.etkiledigi_ozellik,"saglik")==0)
            {
                ToplamOrgDovuscuSaglik=ToplamOrgDovuscuSaglik*(ork_ordu.camur_devleri.etki_miktari+100)/100;
            }
            if (strcmp(ork_ordu.camur_devleri.etkiledigi_ozellik,"kritik_sans")==0)
            {
                ork_ordu.ork_dovuscu.kritsans=ork_ordu.ork_dovuscu.kritsans*(ork_ordu.camur_devleri.etki_miktari+100)/100;
            }
        }
        if (strcmp(ork_ordu.camur_devleri.etkiledigi_birim,"mizrakci")==0)
        {
            if (strcmp(ork_ordu.camur_devleri.etkiledigi_ozellik,"saldiri")==0)
            {
                ToplamMizrakciHasar=ToplamMizrakciHasar*(ork_ordu.camur_devleri.etki_miktari+100)/100;
            }
            if (strcmp(ork_ordu.camur_devleri.etkiledigi_ozellik,"savunma")==0)
            {
                ToplamMizrakciSavunma=ToplamMizrakciSavunma*(ork_ordu.camur_devleri.etki_miktari+100)/100;
            }
            if (strcmp(ork_ordu.camur_devleri.etkiledigi_ozellik,"saglik")==0)
            {
                ToplamMizrakciSaglik=ToplamMizrakciSaglik*(ork_ordu.camur_devleri.etki_miktari+100)/100;
            }
            if (strcmp(ork_ordu.camur_devleri.etkiledigi_ozellik,"kritik_sans")==0)
            {
                ork_ordu.mizrakci.kritsans=ork_ordu.mizrakci.kritsans*(ork_ordu.camur_devleri.etki_miktari+100)/100;
            }
        }
        if (strcmp(ork_ordu.camur_devleri.etkiledigi_birim,"varg_binici")==0)
        {
            if (strcmp(ork_ordu.camur_devleri.etkiledigi_ozellik,"saldiri")==0)
            {
                ToplamVargBiniciHasar=ToplamVargBiniciHasar*(ork_ordu.camur_devleri.etki_miktari+100)/100;
            }
            if (strcmp(ork_ordu.camur_devleri.etkiledigi_ozellik,"savunma")==0)
            {
                ToplamVargBiniciSavunma=ToplamVargBiniciSavunma*(ork_ordu.camur_devleri.etki_miktari+100)/100;
            }
            if (strcmp(ork_ordu.camur_devleri.etkiledigi_ozellik,"saglik")==0)
            {
                ToplamVargBiniciSaglik=ToplamVargBiniciSaglik*(ork_ordu.camur_devleri.etki_miktari+100)/100;
            }
            if (strcmp(ork_ordu.camur_devleri.etkiledigi_ozellik,"kritik_sans")==0)
            {
                ork_ordu.varg_binici.kritsans=ork_ordu.varg_binici.kritsans*(ork_ordu.camur_devleri.etki_miktari+100)/100;
            }
        }
        if (strcmp(ork_ordu.camur_devleri.etkiledigi_birim,"troller")==0)
        {
            if (strcmp(ork_ordu.camur_devleri.etkiledigi_ozellik,"saldiri")==0)
            {
                ToplamTrolHasar=ToplamTrolHasar*(ork_ordu.camur_devleri.etki_miktari+100)/100;
            }
            if (strcmp(ork_ordu.camur_devleri.etkiledigi_ozellik,"savunma")==0)
            {
                ToplamTrolSavunma=ToplamTrolSavunma*(ork_ordu.camur_devleri.etki_miktari+100)/100;
            }
            if (strcmp(ork_ordu.camur_devleri.etkiledigi_ozellik,"saglik")==0)
            {
                ToplamTrolSaglik=ToplamTrolSaglik*(ork_ordu.camur_devleri.etki_miktari+100)/100;
            }
            if (strcmp(ork_ordu.camur_devleri.etkiledigi_ozellik,"kritik_sans")==0)
            {
                ork_ordu.troller.kritsans=ork_ordu.troller.kritsans*(ork_ordu.camur_devleri.etki_miktari+100)/100;
            }
        }
    }
    if (strcmp(ork_ordu.bulunancanavar.bulunan1,"Ates_Iblisi")==0)
    {
        if (strcmp(ork_ordu.ates_iblisi.etkiledigi_birim,"ork_dovuscu")==0)
        {
            if (strcmp(ork_ordu.ates_iblisi.etkiledigi_ozellik,"saldiri")==0)
            {
                ToplamOrgDovuscuHasar=ToplamOrgDovuscuHasar*(ork_ordu.ates_iblisi.etki_miktari+100)/100;
            }
            if (strcmp(ork_ordu.ates_iblisi.etkiledigi_ozellik,"savunma")==0)
            {
                ToplamOrgDovuscuSavunma=ToplamOrgDovuscuSavunma*(ork_ordu.ates_iblisi.etki_miktari+100)/100;
            }
            if (strcmp(ork_ordu.ates_iblisi.etkiledigi_ozellik,"saglik")==0)
            {
                ToplamOrgDovuscuSaglik=ToplamOrgDovuscuSaglik*(ork_ordu.ates_iblisi.etki_miktari+100)/100;
            }
            if (strcmp(ork_ordu.ates_iblisi.etkiledigi_ozellik,"kritik_sans")==0)
            {
                ork_ordu.ork_dovuscu.kritsans=ork_ordu.ork_dovuscu.kritsans*(ork_ordu.ates_iblisi.etki_miktari+100)/100;
            }
        }
        if (strcmp(ork_ordu.ates_iblisi.etkiledigi_birim,"mizrakci")==0)
        {
            if (strcmp(ork_ordu.ates_iblisi.etkiledigi_ozellik,"saldiri")==0)
            {
                ToplamMizrakciHasar=ToplamMizrakciHasar*(ork_ordu.ates_iblisi.etki_miktari+100)/100;
            }
            if (strcmp(ork_ordu.ates_iblisi.etkiledigi_ozellik,"savunma")==0)
            {
                ToplamMizrakciSavunma=ToplamMizrakciSavunma*(ork_ordu.ates_iblisi.etki_miktari+100)/100;
            }
            if (strcmp(ork_ordu.ates_iblisi.etkiledigi_ozellik,"saglik")==0)
            {
                ToplamMizrakciSaglik=ToplamMizrakciSaglik*(ork_ordu.ates_iblisi.etki_miktari+100)/100;
            }
            if (strcmp(ork_ordu.ates_iblisi.etkiledigi_ozellik,"kritik_sans")==0)
            {
                ork_ordu.mizrakci.kritsans=ork_ordu.mizrakci.kritsans*(ork_ordu.ates_iblisi.etki_miktari+100)/100;
            }
        }
        if (strcmp(ork_ordu.ates_iblisi.etkiledigi_birim,"varg_binici")==0)
        {
            if (strcmp(ork_ordu.ates_iblisi.etkiledigi_ozellik,"saldiri")==0)
            {
                ToplamVargBiniciHasar=ToplamVargBiniciHasar*(ork_ordu.ates_iblisi.etki_miktari+100)/100;
            }
            if (strcmp(ork_ordu.ates_iblisi.etkiledigi_ozellik,"savunma")==0)
            {
                ToplamVargBiniciSavunma=ToplamVargBiniciSavunma*(ork_ordu.ates_iblisi.etki_miktari+100)/100;
            }
            if (strcmp(ork_ordu.ates_iblisi.etkiledigi_ozellik,"saglik")==0)
            {
                ToplamVargBiniciSaglik=ToplamVargBiniciSaglik*(ork_ordu.ates_iblisi.etki_miktari+100)/100;
            }
            if (strcmp(ork_ordu.ates_iblisi.etkiledigi_ozellik,"kritik_sans")==0)
            {
                ork_ordu.varg_binici.kritsans=ork_ordu.varg_binici.kritsans*(ork_ordu.ates_iblisi.etki_miktari+100)/100;
            }
        }
        if (strcmp(ork_ordu.ates_iblisi.etkiledigi_birim,"troller")==0)
        {
            if (strcmp(ork_ordu.ates_iblisi.etkiledigi_ozellik,"saldiri")==0)
            {
                ToplamTrolHasar=ToplamTrolHasar*(ork_ordu.ates_iblisi.etki_miktari+100)/100;
            }
            if (strcmp(ork_ordu.ates_iblisi.etkiledigi_ozellik,"savunma")==0)
            {
                ToplamTrolSavunma=ToplamTrolSavunma*(ork_ordu.ates_iblisi.etki_miktari+100)/100;
            }
            if (strcmp(ork_ordu.ates_iblisi.etkiledigi_ozellik,"saglik")==0)
            {
                ToplamTrolSaglik=ToplamTrolSaglik*(ork_ordu.ates_iblisi.etki_miktari+100)/100;
            }
            if (strcmp(ork_ordu.ates_iblisi.etkiledigi_ozellik,"kritik_sans")==0)
            {
                ork_ordu.troller.kritsans=ork_ordu.troller.kritsans*(ork_ordu.ates_iblisi.etki_miktari+100)/100;
            }
        }
    }
    if (strcmp(ork_ordu.bulunancanavar.bulunan1,"Makrog_Savas_Beyi")==0)
    {
        if (strcmp(ork_ordu.makrog_savas_beyi.etkiledigi_birim,"ork_dovuscu")==0)
        {
            if (strcmp(ork_ordu.makrog_savas_beyi.etkiledigi_ozellik,"saldiri")==0)
            {
                ToplamOrgDovuscuHasar=ToplamOrgDovuscuHasar*(ork_ordu.makrog_savas_beyi.etki_miktari+100)/100;
            }
            if (strcmp(ork_ordu.makrog_savas_beyi.etkiledigi_ozellik,"savunma")==0)
            {
                ToplamOrgDovuscuSavunma=ToplamOrgDovuscuSavunma*(ork_ordu.makrog_savas_beyi.etki_miktari+100)/100;
            }
            if (strcmp(ork_ordu.makrog_savas_beyi.etkiledigi_ozellik,"saglik")==0)
            {
                ToplamOrgDovuscuSaglik=ToplamOrgDovuscuSaglik*(ork_ordu.makrog_savas_beyi.etki_miktari+100)/100;
            }
            if (strcmp(ork_ordu.makrog_savas_beyi.etkiledigi_ozellik,"kritik_sans")==0)
            {
                ork_ordu.ork_dovuscu.kritsans=ork_ordu.ork_dovuscu.kritsans*(ork_ordu.makrog_savas_beyi.etki_miktari+100)/100;
            }
        }
        if (strcmp(ork_ordu.makrog_savas_beyi.etkiledigi_birim,"mizrakci")==0)
        {
            if (strcmp(ork_ordu.makrog_savas_beyi.etkiledigi_ozellik,"saldiri")==0)
            {
                ToplamMizrakciHasar=ToplamMizrakciHasar*(ork_ordu.makrog_savas_beyi.etki_miktari+100)/100;
            }
            if (strcmp(ork_ordu.makrog_savas_beyi.etkiledigi_ozellik,"savunma")==0)
            {
                ToplamMizrakciSavunma=ToplamMizrakciSavunma*(ork_ordu.makrog_savas_beyi.etki_miktari+100)/100;
            }
            if (strcmp(ork_ordu.makrog_savas_beyi.etkiledigi_ozellik,"saglik")==0)
            {
                ToplamMizrakciSaglik=ToplamMizrakciSaglik*(ork_ordu.makrog_savas_beyi.etki_miktari+100)/100;
            }
            if (strcmp(ork_ordu.makrog_savas_beyi.etkiledigi_ozellik,"kritik_sans")==0)
            {
                ork_ordu.mizrakci.kritsans=ork_ordu.mizrakci.kritsans*(ork_ordu.makrog_savas_beyi.etki_miktari+100)/100;
            }
        }
        if (strcmp(ork_ordu.makrog_savas_beyi.etkiledigi_birim,"varg_binici")==0)
        {
            if (strcmp(ork_ordu.makrog_savas_beyi.etkiledigi_ozellik,"saldiri")==0)
            {
                ToplamVargBiniciHasar=ToplamVargBiniciHasar*(ork_ordu.makrog_savas_beyi.etki_miktari+100)/100;
            }
            if (strcmp(ork_ordu.makrog_savas_beyi.etkiledigi_ozellik,"savunma")==0)
            {
                ToplamVargBiniciSavunma=ToplamVargBiniciSavunma*(ork_ordu.makrog_savas_beyi.etki_miktari+100)/100;
            }
            if (strcmp(ork_ordu.makrog_savas_beyi.etkiledigi_ozellik,"saglik")==0)
            {
                ToplamVargBiniciSaglik=ToplamVargBiniciSaglik*(ork_ordu.makrog_savas_beyi.etki_miktari+100)/100;
            }
            if (strcmp(ork_ordu.makrog_savas_beyi.etkiledigi_ozellik,"kritik_sans")==0)
            {
                ork_ordu.varg_binici.kritsans=ork_ordu.varg_binici.kritsans*(ork_ordu.makrog_savas_beyi.etki_miktari+100)/100;
            }
        }
        if (strcmp(ork_ordu.makrog_savas_beyi.etkiledigi_birim,"troller")==0)
        {
            if (strcmp(ork_ordu.makrog_savas_beyi.etkiledigi_ozellik,"saldiri")==0)
            {
                ToplamTrolHasar=ToplamTrolHasar*(ork_ordu.makrog_savas_beyi.etki_miktari+100)/100;
            }
            if (strcmp(ork_ordu.makrog_savas_beyi.etkiledigi_ozellik,"savunma")==0)
            {
                ToplamTrolSavunma=ToplamTrolSavunma*(ork_ordu.makrog_savas_beyi.etki_miktari+100)/100;
            }
            if (strcmp(ork_ordu.makrog_savas_beyi.etkiledigi_ozellik,"saglik")==0)
            {
                ToplamTrolSaglik=ToplamTrolSaglik*(ork_ordu.makrog_savas_beyi.etki_miktari+100)/100;
            }
            if (strcmp(ork_ordu.makrog_savas_beyi.etkiledigi_ozellik,"kritik_sans")==0)
            {
                ork_ordu.troller.kritsans=ork_ordu.troller.kritsans*(ork_ordu.makrog_savas_beyi.etki_miktari+100)/100;
            }
        }
    }
    if (strcmp(ork_ordu.bulunancanavar.bulunan1,"Buz_Devleri")==0)
    {
        if (strcmp(ork_ordu.buz_devleri.etkiledigi_birim,"ork_dovuscu")==0)
        {
            if (strcmp(ork_ordu.buz_devleri.etkiledigi_ozellik,"saldiri")==0)
            {
                ToplamOrgDovuscuHasar=ToplamOrgDovuscuHasar*(ork_ordu.buz_devleri.etki_miktari+100)/100;
            }
            if (strcmp(ork_ordu.buz_devleri.etkiledigi_ozellik,"savunma")==0)
            {
                ToplamOrgDovuscuSavunma=ToplamOrgDovuscuSavunma*(ork_ordu.buz_devleri.etki_miktari+100)/100;
            }
            if (strcmp(ork_ordu.buz_devleri.etkiledigi_ozellik,"saglik")==0)
            {
                ToplamOrgDovuscuSaglik=ToplamOrgDovuscuSaglik*(ork_ordu.buz_devleri.etki_miktari+100)/100;
            }
            if (strcmp(ork_ordu.buz_devleri.etkiledigi_ozellik,"kritik_sans")==0)
            {
                ork_ordu.ork_dovuscu.kritsans=ork_ordu.ork_dovuscu.kritsans*(ork_ordu.buz_devleri.etki_miktari+100)/100;
            }
        }
        if (strcmp(ork_ordu.buz_devleri.etkiledigi_birim,"mizrakci")==0)
        {
            if (strcmp(ork_ordu.buz_devleri.etkiledigi_ozellik,"saldiri")==0)
            {
                ToplamMizrakciHasar=ToplamMizrakciHasar*(ork_ordu.buz_devleri.etki_miktari+100)/100;
            }
            if (strcmp(ork_ordu.buz_devleri.etkiledigi_ozellik,"savunma")==0)
            {
                ToplamMizrakciSavunma=ToplamMizrakciSavunma*(ork_ordu.buz_devleri.etki_miktari+100)/100;
            }
            if (strcmp(ork_ordu.buz_devleri.etkiledigi_ozellik,"saglik")==0)
            {
                ToplamMizrakciSaglik=ToplamMizrakciSaglik*(ork_ordu.buz_devleri.etki_miktari+100)/100;
            }
            if (strcmp(ork_ordu.buz_devleri.etkiledigi_ozellik,"kritik_sans")==0)
            {
                ork_ordu.mizrakci.kritsans=ork_ordu.mizrakci.kritsans*(ork_ordu.buz_devleri.etki_miktari+100)/100;
            }
        }
        if (strcmp(ork_ordu.buz_devleri.etkiledigi_birim,"varg_binici")==0)
        {
            if (strcmp(ork_ordu.buz_devleri.etkiledigi_ozellik,"saldiri")==0)
            {
                ToplamVargBiniciHasar=ToplamVargBiniciHasar*(ork_ordu.buz_devleri.etki_miktari+100)/100;
            }
            if (strcmp(ork_ordu.buz_devleri.etkiledigi_ozellik,"savunma")==0)
            {
                ToplamVargBiniciSavunma=ToplamVargBiniciSavunma*(ork_ordu.buz_devleri.etki_miktari+100)/100;
            }
            if (strcmp(ork_ordu.buz_devleri.etkiledigi_ozellik,"saglik")==0)
            {
                ToplamVargBiniciSaglik=ToplamVargBiniciSaglik*(ork_ordu.buz_devleri.etki_miktari+100)/100;
            }
            if (strcmp(ork_ordu.buz_devleri.etkiledigi_ozellik,"kritik_sans")==0)
            {
                ork_ordu.varg_binici.kritsans=ork_ordu.varg_binici.kritsans*(ork_ordu.buz_devleri.etki_miktari+100)/100;
            }
        }
        if (strcmp(ork_ordu.buz_devleri.etkiledigi_birim,"troller")==0)
        {
            if (strcmp(ork_ordu.buz_devleri.etkiledigi_ozellik,"saldiri")==0)
            {
                ToplamTrolHasar=ToplamTrolHasar*(ork_ordu.buz_devleri.etki_miktari+100)/100;
            }
            if (strcmp(ork_ordu.buz_devleri.etkiledigi_ozellik,"savunma")==0)
            {
                ToplamTrolSavunma=ToplamTrolSavunma*(ork_ordu.buz_devleri.etki_miktari+100)/100;
            }
            if (strcmp(ork_ordu.buz_devleri.etkiledigi_ozellik,"saglik")==0)
            {
                ToplamTrolSaglik=ToplamTrolSaglik*(ork_ordu.buz_devleri.etki_miktari+100)/100;
            }
            if (strcmp(ork_ordu.buz_devleri.etkiledigi_ozellik,"kritik_sans")==0)
            {
                ork_ordu.troller.kritsans=ork_ordu.troller.kritsans*(ork_ordu.buz_devleri.etki_miktari+100)/100;
            }
        }
    }
    if (strcmp(insan_ordu.bulunanarastirma.arastirmaisim,"saldiri_gelistirmesi")==0)
    {
        if (insan_ordu.bulunanarastirma.seviye==1)
        {
            ToplamPiyadeHasar=ToplamPiyadeHasar*(insan_ordu.saldiri_gelistirmesi_1.etki_miktari+100)/100;
            ToplamOkcuHasar=ToplamOkcuHasar*(insan_ordu.saldiri_gelistirmesi_1.etki_miktari+100)/100;
            ToplamSuvariHasar=ToplamSuvariHasar*(insan_ordu.saldiri_gelistirmesi_1.etki_miktari+100)/100;
            ToplamKusatmaHasar=ToplamKusatmaHasar*(insan_ordu.saldiri_gelistirmesi_1.etki_miktari+100)/100;
        }
        if (insan_ordu.bulunanarastirma.seviye==2)
        {
            ToplamPiyadeHasar=ToplamPiyadeHasar*(insan_ordu.saldiri_gelistirmesi_2.etki_miktari+100)/100;
            ToplamOkcuHasar=ToplamOkcuHasar*(insan_ordu.saldiri_gelistirmesi_2.etki_miktari+100)/100;
            ToplamSuvariHasar=ToplamSuvariHasar*(insan_ordu.saldiri_gelistirmesi_2.etki_miktari+100)/100;
            ToplamKusatmaHasar=ToplamKusatmaHasar*(insan_ordu.saldiri_gelistirmesi_2.etki_miktari+100)/100;
        }
        if (insan_ordu.bulunanarastirma.seviye==3)
        {
            ToplamPiyadeHasar=ToplamPiyadeHasar*(insan_ordu.saldiri_gelistirmesi_3.etki_miktari+100)/100;
            ToplamOkcuHasar=ToplamOkcuHasar*(insan_ordu.saldiri_gelistirmesi_3.etki_miktari+100)/100;
            ToplamSuvariHasar=ToplamSuvariHasar*(insan_ordu.saldiri_gelistirmesi_3.etki_miktari+100)/100;
            ToplamKusatmaHasar=ToplamKusatmaHasar*(insan_ordu.saldiri_gelistirmesi_3.etki_miktari+100)/100;
        }
    }
    if (strcmp(insan_ordu.bulunanarastirma.arastirmaisim,"savunma_ustaligi")==0)
    {
        if (insan_ordu.bulunanarastirma.seviye==1)
        {
            ToplamPiyadeSavunma=ToplamPiyadeSavunma*(insan_ordu.savunma_ustaligi_1.etki_miktari+100)/100;
            ToplamOkcuSavunma=ToplamOkcuSavunma*(insan_ordu.savunma_ustaligi_1.etki_miktari+100)/100;
            ToplamSuvariSavunma=ToplamSuvariSavunma*(insan_ordu.savunma_ustaligi_1.etki_miktari+100)/100;
            ToplamKusatmaSavunma=ToplamKusatmaSavunma*(insan_ordu.savunma_ustaligi_1.etki_miktari+100)/100;
        }
        if (insan_ordu.bulunanarastirma.seviye==2)
        {
            ToplamPiyadeSavunma=ToplamPiyadeSavunma*(insan_ordu.savunma_ustaligi_2.etki_miktari+100)/100;
            ToplamOkcuSavunma=ToplamOkcuSavunma*(insan_ordu.savunma_ustaligi_2.etki_miktari+100)/100;
            ToplamSuvariSavunma=ToplamSuvariSavunma*(insan_ordu.savunma_ustaligi_2.etki_miktari+100)/100;
            ToplamKusatmaSavunma=ToplamKusatmaSavunma*(insan_ordu.savunma_ustaligi_2.etki_miktari+100)/100;
        }
        if (insan_ordu.bulunanarastirma.seviye==3)
        {
            ToplamPiyadeSavunma=ToplamPiyadeSavunma*(insan_ordu.savunma_ustaligi_3.etki_miktari+100)/100;
            ToplamOkcuSavunma=ToplamOkcuSavunma*(insan_ordu.savunma_ustaligi_3.etki_miktari+100)/100;
            ToplamSuvariSavunma=ToplamSuvariSavunma*(insan_ordu.savunma_ustaligi_3.etki_miktari+100)/100;
            ToplamKusatmaSavunma=ToplamKusatmaSavunma*(insan_ordu.savunma_ustaligi_3.etki_miktari+100)/100;
        }
    }
    if (strcmp(insan_ordu.bulunanarastirma.arastirmaisim,"elit_egitim")==0)
    {
        if (insan_ordu.bulunanarastirma.seviye==1)
        {
            insan_ordu.piyade.kritsans=insan_ordu.piyade.kritsans*(insan_ordu.elit_egitim_1.etki_miktari+100)/100;
            insan_ordu.okcu.kritsans=insan_ordu.okcu.kritsans*(insan_ordu.elit_egitim_1.etki_miktari+100)/100;
            insan_ordu.suvari.kritsans=insan_ordu.suvari.kritsans*(insan_ordu.elit_egitim_1.etki_miktari+100)/100;
            insan_ordu.kusatma_makine.kritsans=insan_ordu.kusatma_makine.kritsans*(insan_ordu.elit_egitim_1.etki_miktari+100)/100;
        }
        if (insan_ordu.bulunanarastirma.seviye==2)
        {
            insan_ordu.piyade.kritsans=insan_ordu.piyade.kritsans*(insan_ordu.elit_egitim_2.etki_miktari+100)/100;
            insan_ordu.okcu.kritsans=insan_ordu.okcu.kritsans*(insan_ordu.elit_egitim_2.etki_miktari+100)/100;
            insan_ordu.suvari.kritsans=insan_ordu.suvari.kritsans*(insan_ordu.elit_egitim_2.etki_miktari+100)/100;
            insan_ordu.kusatma_makine.kritsans=insan_ordu.kusatma_makine.kritsans*(insan_ordu.elit_egitim_2.etki_miktari+100)/100;
        }
        if (insan_ordu.bulunanarastirma.seviye==3)
        {
            insan_ordu.piyade.kritsans=insan_ordu.piyade.kritsans*(insan_ordu.elit_egitim_3.etki_miktari+100)/100;
            insan_ordu.okcu.kritsans=insan_ordu.okcu.kritsans*(insan_ordu.elit_egitim_3.etki_miktari+100)/100;
            insan_ordu.suvari.kritsans=insan_ordu.suvari.kritsans*(insan_ordu.elit_egitim_3.etki_miktari+100)/100;
            insan_ordu.kusatma_makine.kritsans=insan_ordu.kusatma_makine.kritsans*(insan_ordu.elit_egitim_3.etki_miktari+100)/100;
        }
    }
    if (strcmp(insan_ordu.bulunanarastirma.arastirmaisim,"kusatma_ustaligi")==0)
    {
        if (insan_ordu.bulunanarastirma.seviye==1)
        {
            ToplamKusatmaHasar=ToplamKusatmaHasar*(insan_ordu.kusatma_ustaligi_1.etki_miktari+100)/100;
        }
        if (insan_ordu.bulunanarastirma.seviye==2)
        {
            ToplamKusatmaHasar=ToplamKusatmaHasar*(insan_ordu.kusatma_ustaligi_2.etki_miktari+100)/100;
        }
        if (insan_ordu.bulunanarastirma.seviye==3)
        {
            ToplamKusatmaHasar=ToplamKusatmaHasar*(insan_ordu.kusatma_ustaligi_3.etki_miktari+100)/100;
        }
    }
    if (strcmp(ork_ordu.bulunanarastirma.arastirmaisim,"saldiri_gelistirmesi")==0)
    {
        if (ork_ordu.bulunanarastirma.seviye==1)
        {
            ToplamOrgDovuscuHasar=ToplamOrgDovuscuHasar*(ork_ordu.saldiri_gelistirmesi_1.etki_miktari+100)/100;
            ToplamMizrakciHasar=ToplamMizrakciHasar*(ork_ordu.saldiri_gelistirmesi_1.etki_miktari+100)/100;
            ToplamVargBiniciHasar=ToplamVargBiniciHasar*(ork_ordu.saldiri_gelistirmesi_1.etki_miktari+100)/100;
            ToplamTrolHasar=ToplamTrolHasar*(ork_ordu.saldiri_gelistirmesi_1.etki_miktari+100)/100;
        }
        if (ork_ordu.bulunanarastirma.seviye==2)
        {
            ToplamOrgDovuscuHasar=ToplamOrgDovuscuHasar*(ork_ordu.saldiri_gelistirmesi_2.etki_miktari+100)/100;
            ToplamMizrakciHasar=ToplamMizrakciHasar*(ork_ordu.saldiri_gelistirmesi_2.etki_miktari+100)/100;
            ToplamVargBiniciHasar=ToplamVargBiniciHasar*(ork_ordu.saldiri_gelistirmesi_2.etki_miktari+100)/100;
            ToplamTrolHasar=ToplamTrolHasar*(ork_ordu.saldiri_gelistirmesi_2.etki_miktari+100)/100;
        }
        if (ork_ordu.bulunanarastirma.seviye==3)
        {
            ToplamOrgDovuscuHasar=ToplamOrgDovuscuHasar*(ork_ordu.saldiri_gelistirmesi_3.etki_miktari+100)/100;
            ToplamMizrakciHasar=ToplamMizrakciHasar*(ork_ordu.saldiri_gelistirmesi_3.etki_miktari+100)/100;
            ToplamVargBiniciHasar=ToplamVargBiniciHasar*(ork_ordu.saldiri_gelistirmesi_3.etki_miktari+100)/100;
            ToplamTrolHasar=ToplamTrolHasar*(ork_ordu.saldiri_gelistirmesi_3.etki_miktari+100)/100;
        }
    }
    if (strcmp(ork_ordu.bulunanarastirma.arastirmaisim,"savunma_ustaligi")==0)
    {
        if (ork_ordu.bulunanarastirma.seviye==1)
        {
            ToplamOrgDovuscuSavunma=ToplamOrgDovuscuSavunma*(ork_ordu.savunma_ustaligi_1.etki_miktari+100)/100;
            ToplamMizrakciSavunma=ToplamMizrakciSavunma*(ork_ordu.savunma_ustaligi_1.etki_miktari+100)/100;
            ToplamVargBiniciSavunma=ToplamVargBiniciSavunma*(ork_ordu.savunma_ustaligi_1.etki_miktari+100)/100;
            ToplamTrolSavunma=ToplamTrolSavunma*(ork_ordu.savunma_ustaligi_1.etki_miktari+100)/100;
        }
        if (ork_ordu.bulunanarastirma.seviye==2)
        {
            ToplamOrgDovuscuSavunma=ToplamOrgDovuscuSavunma*(ork_ordu.savunma_ustaligi_2.etki_miktari+100)/100;
            ToplamMizrakciSavunma=ToplamMizrakciSavunma*(ork_ordu.savunma_ustaligi_2.etki_miktari+100)/100;
            ToplamVargBiniciSavunma=ToplamVargBiniciSavunma*(ork_ordu.savunma_ustaligi_2.etki_miktari+100)/100;
            ToplamTrolSavunma=ToplamTrolSavunma*(ork_ordu.savunma_ustaligi_2.etki_miktari+100)/100;
        }
        if (ork_ordu.bulunanarastirma.seviye==3)
        {
            ToplamOrgDovuscuSavunma=ToplamOrgDovuscuSavunma*(ork_ordu.savunma_ustaligi_3.etki_miktari+100)/100;
            ToplamMizrakciSavunma=ToplamMizrakciSavunma*(ork_ordu.savunma_ustaligi_3.etki_miktari+100)/100;
            ToplamVargBiniciSavunma=ToplamVargBiniciSavunma*(ork_ordu.savunma_ustaligi_3.etki_miktari+100)/100;
            ToplamTrolSavunma=ToplamTrolSavunma*(ork_ordu.savunma_ustaligi_3.etki_miktari+100)/100;
        }
    }
    if (strcmp(ork_ordu.bulunanarastirma.arastirmaisim,"elit_egitim")==0)
    {
        if (ork_ordu.bulunanarastirma.seviye==1)
        {
            ork_ordu.ork_dovuscu.kritsans=ork_ordu.ork_dovuscu.kritsans*(ork_ordu.elit_egitim_1.etki_miktari+100)/100;
            ork_ordu.mizrakci.kritsans=ork_ordu.mizrakci.kritsans*(ork_ordu.elit_egitim_1.etki_miktari+100)/100;
            ork_ordu.varg_binici.kritsans=ork_ordu.varg_binici.kritsans*(ork_ordu.elit_egitim_1.etki_miktari+100)/100;
            ork_ordu.troller.kritsans=ork_ordu.troller.kritsans*(ork_ordu.elit_egitim_1.etki_miktari+100)/100;
        }
        if (ork_ordu.bulunanarastirma.seviye==2)
        {
            ork_ordu.ork_dovuscu.kritsans=ork_ordu.ork_dovuscu.kritsans*(ork_ordu.elit_egitim_2.etki_miktari+100)/100;
            ork_ordu.mizrakci.kritsans=ork_ordu.mizrakci.kritsans*(ork_ordu.elit_egitim_2.etki_miktari+100)/100;
            ork_ordu.varg_binici.kritsans=ork_ordu.varg_binici.kritsans*(ork_ordu.elit_egitim_2.etki_miktari+100)/100;
            ork_ordu.troller.kritsans=ork_ordu.troller.kritsans*(ork_ordu.elit_egitim_2.etki_miktari+100)/100;
        }
        if (ork_ordu.bulunanarastirma.seviye==3)
        {
            ork_ordu.ork_dovuscu.kritsans=ork_ordu.ork_dovuscu.kritsans*(ork_ordu.elit_egitim_3.etki_miktari+100)/100;
            ork_ordu.mizrakci.kritsans=ork_ordu.mizrakci.kritsans*(ork_ordu.elit_egitim_3.etki_miktari+100)/100;
            ork_ordu.varg_binici.kritsans=ork_ordu.varg_binici.kritsans*(ork_ordu.elit_egitim_3.etki_miktari+100)/100;
            ork_ordu.troller.kritsans=ork_ordu.troller.kritsans*(ork_ordu.elit_egitim_3.etki_miktari+100)/100;
        }
    }

    float InsanToplamHasar=ToplamKusatmaHasar+ToplamOkcuHasar+ToplamPiyadeHasar+ToplamSuvariHasar;
    float InsanToplamSavunma=ToplamKusatmaSavunma+ToplamOkcuSavunma+ToplamPiyadeSavunma+ToplamSuvariSavunma;
    float InsanToplamSaglik=ToplamKusatmaSaglik+ToplamOkcuSaglik+ToplamPiyadeSaglik+ToplamSuvariSaglik;
    float OrgToplamHasar=ToplamOrgDovuscuHasar+ToplamMizrakciHasar+ToplamVargBiniciHasar+ToplamTrolHasar;
    float OrgToplamSavunma=ToplamOrgDovuscuSavunma+ToplamMizrakciSavunma+ToplamVargBiniciSavunma+ToplamTrolSavunma;
    float OrgToplamSaglik=ToplamOrgDovuscuSaglik+ToplamMizrakciSaglik+ToplamVargBiniciSaglik+ToplamTrolSaglik;

    int okcutekrar=0;
    int suvaritekrar=0;
    int kusatmatekrar=0;
    int piyadetekrar=0;
    int orgdovuscutekrar=0;
    int mizrakcitekrar=0;
    int vargbinicitekrar=0;
    int troltekrar=0;

    if ((int)insan_ordu.birimler.okcusayi%100==0)
    {
        okcutekrar=insan_ordu.birimler.okcusayi/100;
    }
    else
    {
        okcutekrar=insan_ordu.birimler.okcusayi/100+1;
    }
    if ((int)insan_ordu.birimler.piyadesayi%100==0)
    {
        piyadetekrar=insan_ordu.birimler.piyadesayi/100;
    }
    else
    {
        piyadetekrar=insan_ordu.birimler.piyadesayi/100+1;
    }
    if ((int)insan_ordu.birimler.suvarisayi%100==0)
    {
        suvaritekrar=insan_ordu.birimler.suvarisayi/100;
    }
    else
    {
        suvaritekrar=insan_ordu.birimler.suvarisayi/100+1;
    }
    if ((int)insan_ordu.birimler.kusatma_m_sayi%100==0)
    {
        kusatmatekrar=insan_ordu.birimler.kusatma_m_sayi/100;
    }
    else
    {
        kusatmatekrar=insan_ordu.birimler.kusatma_m_sayi/100+1;
    }
    if ((int)ork_ordu.birimler2.orkdovuscu%100==0)
    {
        orgdovuscutekrar=ork_ordu.birimler2.orkdovuscu/100;
    }
    else
    {
        orgdovuscutekrar=insan_ordu.birimler.orkdovuscu/100+1;
    }
    if ((int)ork_ordu.birimler2.mizrakci%100==0)
    {
        mizrakcitekrar=ork_ordu.birimler2.mizrakci/100;
    }
    else
    {
        mizrakcitekrar=insan_ordu.birimler.mizrakci/100+1;
    }
    if ((int)ork_ordu.birimler2.vargbinici%100==0)
    {
        vargbinicitekrar=ork_ordu.birimler2.vargbinici/100;
    }
    else
    {
        vargbinicitekrar=insan_ordu.birimler.vargbinici/100+1;
    }
    if ((int)ork_ordu.birimler2.troller%100==0)
    {
        troltekrar=ork_ordu.birimler2.troller/100;
    }
    else
    {
        troltekrar=ork_ordu.birimler2.troller/100+1;
    }

    int okcu_saglik = insan_ordu.okcu.saglik*insan_ordu.birimler.okcusayi, okcu_max_saglik = insan_ordu.okcu.saglik*insan_ordu.birimler.okcusayi;
    int suvari_saglik = insan_ordu.suvari.saglik*insan_ordu.birimler.suvarisayi, suvari_max_saglik = insan_ordu.suvari.saglik*insan_ordu.birimler.suvarisayi;
    int kusatma_saglik = insan_ordu.kusatma_makine.saglik*insan_ordu.birimler.kusatma_m_sayi, kusatma_max_saglik = insan_ordu.kusatma_makine.saglik*insan_ordu.birimler.kusatma_m_sayi;
    int piyade_saglik = insan_ordu.piyade.saglik*insan_ordu.birimler.piyadesayi, piyade_max_saglik = insan_ordu.piyade.saglik*insan_ordu.birimler.piyadesayi;
    int orgdovuscu_saglik=ork_ordu.ork_dovuscu.saglik*ork_ordu.birimler2.orkdovuscu,orgdovuscu_max_saglik=ork_ordu.ork_dovuscu.saglik*ork_ordu.birimler2.orkdovuscu;
    int mizrakci_saglik=ork_ordu.mizrakci.saglik*ork_ordu.birimler2.mizrakci,mizrakci_max_saglik=ork_ordu.mizrakci.saglik*ork_ordu.birimler2.mizrakci;
    int vargbinici_saglik=ork_ordu.varg_binici.saglik*ork_ordu.birimler2.vargbinici,vargbinici_max_saglik=ork_ordu.varg_binici.saglik*ork_ordu.birimler2.vargbinici;
    int troller_saglik=ork_ordu.troller.saglik*ork_ordu.birimler2.troller,troller_max_saglik=ork_ordu.troller.saglik*ork_ordu.birimler2.troller;

    int gridWidth = GRID_SIZE * CELL_SIZE;
    int gridHeight = GRID_SIZE * CELL_SIZE;
    int offsetX = (screenWidth - gridWidth) / 2;
    int offsetY = (screenHeight - gridHeight) / 2;
    int quit = 0;
    SDL_Event e;
    while (!quit)
    {
        while (SDL_PollEvent(&e) != 0)
        {
            if (e.type == SDL_QUIT)
            {
                quit = 1;
            }
        }

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);


         SDL_Rect arkaplanRect = { 0, 0, screenWidth, screenHeight };

    SDL_RenderCopy(renderer, arkaplanresmidokusu, NULL, &arkaplanRect);

    izgaraCiz(renderer, offsetX, offsetY);


        for (int i = 0; i < okcutekrar; ++i)
        {
            SDL_Rect destRect = { ((GRID_SIZE*19 / GRID_SIZE) * CELL_SIZE)-11, (2*(i % GRID_SIZE) * CELL_SIZE)+133, CELL_SIZE, CELL_SIZE };
            SDL_RenderCopy(renderer, okcuresmidokusu, NULL, &destRect);
            canBarCiz(renderer, destRect.x, destRect.y, okcu_saglik, okcu_max_saglik);
        }
        for (int j = 0; j < suvaritekrar; ++j)
        {
            SDL_Rect destRect = { ((GRID_SIZE*20 / GRID_SIZE) * CELL_SIZE)-11, (2*(j % GRID_SIZE) * CELL_SIZE)+133, CELL_SIZE, CELL_SIZE };
            SDL_RenderCopy(renderer, suvariresmidokusu, NULL, &destRect);
            canBarCiz(renderer, destRect.x, destRect.y, suvari_saglik, suvari_max_saglik);
        }
        for (int k = 0; k < kusatmatekrar; ++k)
        {
            SDL_Rect destRect = { ((GRID_SIZE*18 / GRID_SIZE) * CELL_SIZE)-11, (2*(k % GRID_SIZE) * CELL_SIZE)+133, CELL_SIZE, CELL_SIZE };
            SDL_RenderCopy(renderer, kusatmaresmidokusu, NULL, &destRect);
            canBarCiz(renderer, destRect.x, destRect.y, kusatma_saglik, kusatma_max_saglik);
        }
        for (int l = 0; l < piyadetekrar; ++l)
        {
            SDL_Rect destRect = { ((GRID_SIZE*21 / GRID_SIZE) * CELL_SIZE)-11, (2*(l % GRID_SIZE) * CELL_SIZE)+133, CELL_SIZE, CELL_SIZE };
            SDL_RenderCopy(renderer, piyaderesmidokusu, NULL, &destRect);
            canBarCiz(renderer, destRect.x, destRect.y, piyade_saglik, piyade_max_saglik);
        }
        for (int m = 0; m < orgdovuscutekrar; ++m)
        {
            SDL_Rect destRect = { ((GRID_SIZE*30 / GRID_SIZE) * CELL_SIZE)-11, (2*(m % GRID_SIZE) * CELL_SIZE)+133, CELL_SIZE, CELL_SIZE };
            SDL_RenderCopy(renderer, orkdovuscuresmidokusu, NULL, &destRect);
            canBarCiz(renderer, destRect.x, destRect.y, orgdovuscu_saglik, orgdovuscu_max_saglik);
        }
        for (int n = 0; n < mizrakcitekrar; ++n)
        {
            SDL_Rect destRect = { ((GRID_SIZE*32 / GRID_SIZE) * CELL_SIZE)-11, (2*(n % GRID_SIZE) * CELL_SIZE)+133, CELL_SIZE, CELL_SIZE };
            SDL_RenderCopy(renderer, mizrakciresmidokusu, NULL, &destRect);
            canBarCiz(renderer, destRect.x, destRect.y, mizrakci_saglik, mizrakci_max_saglik);
        }
        for (int o = 0; o < vargbinicitekrar; ++o)
        {
            SDL_Rect destRect = { ((GRID_SIZE*31 / GRID_SIZE) * CELL_SIZE)-11,  (2*(o % GRID_SIZE) * CELL_SIZE)+133, CELL_SIZE, CELL_SIZE };
            SDL_RenderCopy(renderer, vargbiniciresmidokusu, NULL, &destRect);
            canBarCiz(renderer, destRect.x, destRect.y, vargbinici_saglik, vargbinici_max_saglik);
        }
        for (int p = 0; p < troltekrar; ++p)
        {
            SDL_Rect destRect = { ((GRID_SIZE*33 / GRID_SIZE) * CELL_SIZE)-11,  (2*(p % GRID_SIZE) * CELL_SIZE)+133, CELL_SIZE, CELL_SIZE };
            SDL_RenderCopy(renderer, trolresmidokusu, NULL, &destRect);
            canBarCiz(renderer, destRect.x, destRect.y, troller_saglik, troller_max_saglik);
        }


         SDL_Rect savasoncesirect = { offsetX + (gridWidth - TOP_IMAGE_WIDTH) / 2, offsetY - TOP_IMAGE_HEIGHT - 10, TOP_IMAGE_WIDTH, TOP_IMAGE_HEIGHT };
    SDL_RenderCopy(renderer, savasoncesidokusu, NULL, &savasoncesirect);

         SDL_Rect insanlarrect = { offsetX -360+ (gridWidth - TOP_IMAGE_WIDTH) / 2, offsetY - TOP_IMAGE_HEIGHT + 15, TOP_IMAGE_WIDTH, TOP_IMAGE_HEIGHT-20 };
    SDL_RenderCopy(renderer, insanlarresmidokusu, NULL, &insanlarrect);

    SDL_Rect orklarrect = { offsetX +360+ (gridWidth - TOP_IMAGE_WIDTH) / 2, offsetY - TOP_IMAGE_HEIGHT + 15, TOP_IMAGE_WIDTH, TOP_IMAGE_HEIGHT-20 };
    SDL_RenderCopy(renderer, orklarresmidokusu, NULL, &orklarrect);

         if (strcmp(insan_ordu.bulunankahraman.bulunan1,"Fatih_Sultan_Mehmet")==0)
        {
            SDL_Rect fatihrect = { offsetX - IMAGE_SIZE - 10, offsetY, IMAGE_SIZE, IMAGE_SIZE };
            SDL_RenderCopy(renderer, fsmresmidokusu, NULL, &fatihrect);

        }
        if (strcmp(insan_ordu.bulunankahraman.bulunan1,"Yavuz_Sultan_Selim")==0)
        {
            SDL_Rect yavuzrect = { offsetX - IMAGE_SIZE - 10, offsetY, IMAGE_SIZE, IMAGE_SIZE };
            SDL_RenderCopy(renderer, yssresmidokusu, NULL, &yavuzrect);
        }
        if (strcmp(insan_ordu.bulunankahraman.bulunan1,"Tugrul_Bey")==0)
        {
            SDL_Rect tugrulrect = { offsetX - IMAGE_SIZE - 10, offsetY, IMAGE_SIZE, IMAGE_SIZE };
            SDL_RenderCopy(renderer, tugrulresmidokusu, NULL, &tugrulrect);
        }
        if (strcmp(insan_ordu.bulunankahraman.bulunan1,"Mete_Han")==0)
        {
            SDL_Rect meterect = { offsetX - IMAGE_SIZE - 10, offsetY, IMAGE_SIZE, IMAGE_SIZE };
            SDL_RenderCopy(renderer, meteresmidokusu, NULL, &meterect);
        }
        if (strcmp(insan_ordu.bulunankahraman.bulunan1,"Alparslan")==0)
        {
            SDL_Rect alparslanrect = { offsetX - IMAGE_SIZE - 10, offsetY, IMAGE_SIZE, IMAGE_SIZE };
            SDL_RenderCopy(renderer, alparslanresmidokusu, NULL, &alparslanrect);
        }
        if (strcmp(ork_ordu.bulunankahraman.bulunan1,"Goruk_Vahsi")==0)
        {
            SDL_Rect gorukrect = { offsetX + GRID_SIZE * CELL_SIZE + 10, offsetY, IMAGE_SIZE, IMAGE_SIZE };
    SDL_RenderCopy(renderer, gorukresmidokusu, NULL, &gorukrect);

        }
        if (strcmp(ork_ordu.bulunankahraman.bulunan1,"Thruk_Kemikkiran")==0)
        {
            SDL_Rect thrukrect = { offsetX + GRID_SIZE * CELL_SIZE + 10, offsetY, IMAGE_SIZE, IMAGE_SIZE };
    SDL_RenderCopy(renderer, thrukresmidokusu, NULL, &thrukrect);

        }
        if (strcmp(ork_ordu.bulunankahraman.bulunan1,"Vrog_Kafakiran")==0)
        {
            SDL_Rect vrogrect = { offsetX + GRID_SIZE * CELL_SIZE + 10, offsetY, IMAGE_SIZE, IMAGE_SIZE };
    SDL_RenderCopy(renderer, vrogresmidokusu, NULL, &vrogrect);

        }
        if (strcmp(ork_ordu.bulunankahraman.bulunan1,"Ugar_Zalim")==0)
        {
            SDL_Rect ugarrect = { offsetX + GRID_SIZE * CELL_SIZE + 10, offsetY, IMAGE_SIZE, IMAGE_SIZE };
    SDL_RenderCopy(renderer, ugarresmidokusu, NULL, &ugarrect);

        }
        if (strcmp(insan_ordu.bulunancanavar.bulunan1,"Ejderha")==0)
        {
            SDL_Rect ejderrect = { offsetX - IMAGE_SIZE - 10, offsetY + IMAGE_SIZE + IMAGE_SPACING, IMAGE_SIZE, IMAGE_SIZE };
    SDL_RenderCopy(renderer, ejderharesmidokusu, NULL, &ejderrect);
        }
        if (strcmp(insan_ordu.bulunancanavar.bulunan1,"Agri_Dagi_Devleri")==0)
        {
            SDL_Rect agrirect = { offsetX - IMAGE_SIZE - 10, offsetY + IMAGE_SIZE + IMAGE_SPACING, IMAGE_SIZE, IMAGE_SIZE };
    SDL_RenderCopy(renderer, agridagiresmidokusu, NULL, &agrirect);
        }
        if (strcmp(insan_ordu.bulunancanavar.bulunan1,"Tepegoz")==0)
        {
            SDL_Rect tepegozrect = { offsetX - IMAGE_SIZE - 10, offsetY + IMAGE_SIZE + IMAGE_SPACING, IMAGE_SIZE, IMAGE_SIZE };
    SDL_RenderCopy(renderer, tepegozresmidokusu, NULL, &tepegozrect);
        }
        if (strcmp(insan_ordu.bulunancanavar.bulunan1,"Karakurt")==0)
        {
            SDL_Rect karakurtrect = { offsetX - IMAGE_SIZE - 10, offsetY + IMAGE_SIZE + IMAGE_SPACING, IMAGE_SIZE, IMAGE_SIZE };
    SDL_RenderCopy(renderer, karakurtresmidokusu, NULL, &karakurtrect);
        }
        if (strcmp(insan_ordu.bulunancanavar.bulunan1,"Samur")==0)
        {
            SDL_Rect samurrect = { offsetX - IMAGE_SIZE - 10, offsetY + IMAGE_SIZE + IMAGE_SPACING, IMAGE_SIZE, IMAGE_SIZE };
    SDL_RenderCopy(renderer, samurresmidokusu, NULL, &samurrect);
        }
        if (strcmp(ork_ordu.bulunancanavar.bulunan1,"Kara_Troll")==0)
        {
            SDL_Rect karatrolrect = { offsetX + GRID_SIZE * CELL_SIZE + 10, offsetY + IMAGE_SIZE + IMAGE_SPACING, IMAGE_SIZE, IMAGE_SIZE };
    SDL_RenderCopy(renderer, karatrolresmidokusu, NULL, &karatrolrect);
        }
        if (strcmp(ork_ordu.bulunancanavar.bulunan1,"Golge_Kurtlari")==0)
        {
            SDL_Rect golgekurtrect = { offsetX + GRID_SIZE * CELL_SIZE + 10, offsetY + IMAGE_SIZE + IMAGE_SPACING, IMAGE_SIZE, IMAGE_SIZE };
    SDL_RenderCopy(renderer, golgekurtlariresmidokusu, NULL, &golgekurtrect);
        }
        if (strcmp(ork_ordu.bulunancanavar.bulunan1,"Camur_Devleri")==0)
        {
            SDL_Rect camurdevirect = { offsetX + GRID_SIZE * CELL_SIZE + 10, offsetY + IMAGE_SIZE + IMAGE_SPACING, IMAGE_SIZE, IMAGE_SIZE };
    SDL_RenderCopy(renderer, camurdeviresmidokusu, NULL, &camurdevirect);
        }
        if (strcmp(ork_ordu.bulunancanavar.bulunan1,"Ates_Iblisi")==0)
        {
            SDL_Rect atesiblisirect = { offsetX + GRID_SIZE * CELL_SIZE + 10, offsetY + IMAGE_SIZE + IMAGE_SPACING, IMAGE_SIZE, IMAGE_SIZE };
    SDL_RenderCopy(renderer, atesiblisiresmidokusu, NULL, &atesiblisirect);
        }
        if (strcmp(ork_ordu.bulunancanavar.bulunan1,"Makrog_Savas_Beyi")==0)
        {
            SDL_Rect makrokrect = { offsetX + GRID_SIZE * CELL_SIZE + 10, offsetY + IMAGE_SIZE + IMAGE_SPACING, IMAGE_SIZE, IMAGE_SIZE };
    SDL_RenderCopy(renderer, makrokresmidokusu, NULL, &makrokrect);
        }
        if (strcmp(ork_ordu.bulunancanavar.bulunan1,"Buz_Devleri")==0)
        {
            SDL_Rect buzdevirect = { offsetX + GRID_SIZE * CELL_SIZE + 10, offsetY + IMAGE_SIZE + IMAGE_SPACING, IMAGE_SIZE, IMAGE_SIZE };
    SDL_RenderCopy(renderer, buzdeviresmidokusu, NULL, &buzdevirect);
        }

        SDL_RenderPresent(renderer);
        SDL_Delay(4000);
        quit = 1;
    }

    fprintf(dospoi11,"     İNSAN İMPARATORLUGU  \n\n");
    fprintf(dospoi11," piyade sayi:%.2f\n",insan_ordu.birimler.piyadesayi);
    fprintf(dospoi11," piyade toplam saglik:%.2f\n",ToplamPiyadeSaglik);
    fprintf(dospoi11," piyade toplam savunma:%.2f\n",ToplamPiyadeSavunma);
    fprintf(dospoi11," piyade toplam hasar:%.2f\n\n",ToplamPiyadeHasar);

    fprintf(dospoi11," suvari sayi:%.2f\n",insan_ordu.birimler.suvarisayi);
    fprintf(dospoi11," suvari toplam saglik:%.2f\n",ToplamSuvariSaglik);
    fprintf(dospoi11," suvari toplam savunma:%.2f\n",ToplamSuvariSavunma);
    fprintf(dospoi11," suvari toplam hasar:%.2f\n\n",ToplamSuvariHasar);

    fprintf(dospoi11," kusatma makinesi sayi:%.2f\n",insan_ordu.birimler.kusatma_m_sayi);
    fprintf(dospoi11," kusatma makinesi toplam saglik:%.2f\n",ToplamKusatmaSaglik);
    fprintf(dospoi11," kusatma makinesi savunma:%.2f\n",ToplamKusatmaSavunma);
    fprintf(dospoi11," kusatma makinesi hasar:%.2f\n\n",ToplamKusatmaHasar);

    fprintf(dospoi11," okcu sayi:%.2f\n",insan_ordu.birimler.okcusayi);
    fprintf(dospoi11," okcu toplam saglik:%.2f\n",ToplamOkcuSaglik);
    fprintf(dospoi11," okcu savunma:%.2f\n",ToplamOkcuSavunma);
    fprintf(dospoi11," okcu  hasar:%.2f\n\n",ToplamOkcuHasar);

    fprintf(dospoi11,"     ORK İMPARATORLUGU  \n\n");
    fprintf(dospoi11," org dovuscu sayi:%.2f\n",ork_ordu.birimler2.orkdovuscu);
    fprintf(dospoi11,"  org dovuscu toplam saglik:%.2f\n",ToplamOrgDovuscuSaglik);
    fprintf(dospoi11," org dovuscu toplam savunma:%.2f\n",ToplamOrgDovuscuSavunma);
    fprintf(dospoi11," org dovuscu toplam hasar:%.2f\n\n",ToplamOrgDovuscuHasar);

    fprintf(dospoi11," troller sayi:%.2f\n",ork_ordu.birimler2.troller);
    fprintf(dospoi11," troller toplam saglik:%.2f\n",ToplamTrolSaglik);
    fprintf(dospoi11," troller toplam savunma:%.2f\n",ToplamTrolSavunma);
    fprintf(dospoi11," troller toplam hasar:%.2f\n\n",ToplamTrolHasar);

    fprintf(dospoi11," mizrakci sayi:%.2f\n",ork_ordu.birimler2.mizrakci);
    fprintf(dospoi11," mizrakci  toplam saglik:%.2f\n",ToplamMizrakciSaglik);
    fprintf(dospoi11," mizrakci  savunma:%.2f\n",ToplamMizrakciSavunma);
    fprintf(dospoi11," mizrakci  hasar:%.2f\n\n",ToplamMizrakciHasar);

    fprintf(dospoi11," Varg binici sayi:%.2f\n",ork_ordu.birimler2.vargbinici);
    fprintf(dospoi11," Varg binici toplam saglik:%.2f\n",ToplamVargBiniciSaglik);
    fprintf(dospoi11," Varg binici savunma:%.2f\n",ToplamVargBiniciSavunma);
    fprintf(dospoi11," Varg binci  hasar:%.2f\n\n",ToplamVargBiniciHasar);

    fprintf(dospoi11,"      KAHRAMANLAR\n\n\n");
    fprintf(dospoi11,"insan kahramani: %s\n",insan_ordu.bulunankahraman.bulunan1);
    fprintf(dospoi11,"ork kahramani: %s\n",ork_ordu.bulunankahraman.bulunan1);

    fprintf(dospoi11,"       CANAVARLAR\n\n\n");
    fprintf(dospoi11," insan canavari %s\n",insan_ordu.bulunancanavar.bulunan1);
    fprintf(dospoi11,"ork canavari: %s\n\n",ork_ordu.bulunancanavar.bulunan1);

    fprintf(dospoi11,"       ARASTIRMA SEVİYESİ\n\n\n");
    fprintf(dospoi11,"insan arastirmasi: %s %d\n",insan_ordu.bulunanarastirma.arastirmaisim,insan_ordu.bulunanarastirma.seviye);
    fprintf(dospoi11,"org arastirmasi: %s %d\n\n",ork_ordu.bulunanarastirma.arastirmaisim,ork_ordu.bulunanarastirma.seviye);


    int tur=0;
    while (InsanToplamSaglik > 0 && OrgToplamSaglik > 0)
    {
        ToplamPiyadeHasar=insan_ordu.piyade.saldiri*insan_ordu.birimler.piyadesayi;
        ToplamPiyadeSavunma=insan_ordu.piyade.savunma*insan_ordu.birimler.piyadesayi;
        ToplamPiyadeSaglik=insan_ordu.piyade.saglik*insan_ordu.birimler.piyadesayi;

        ToplamOkcuHasar=insan_ordu.okcu.saldiri*insan_ordu.birimler.okcusayi;
        ToplamOkcuSavunma=insan_ordu.okcu.savunma*insan_ordu.birimler.okcusayi;
        ToplamOkcuSaglik=insan_ordu.okcu.saglik*insan_ordu.birimler.okcusayi;

        ToplamSuvariHasar=insan_ordu.suvari.saldiri*insan_ordu.birimler.suvarisayi;
        ToplamSuvariSavunma=insan_ordu.suvari.savunma*insan_ordu.birimler.suvarisayi;
        ToplamSuvariSaglik=insan_ordu.suvari.saglik*insan_ordu.birimler.suvarisayi;

        ToplamKusatmaHasar=insan_ordu.kusatma_makine.saldiri*insan_ordu.birimler.kusatma_m_sayi;
        ToplamKusatmaSavunma=insan_ordu.kusatma_makine.savunma*insan_ordu.birimler.kusatma_m_sayi;
        ToplamKusatmaSaglik=insan_ordu.kusatma_makine.saglik*insan_ordu.birimler.kusatma_m_sayi;

        ToplamOrgDovuscuHasar=ork_ordu.ork_dovuscu.saldiri*ork_ordu.birimler2.orkdovuscu;
        ToplamOrgDovuscuSavunma=ork_ordu.ork_dovuscu.savunma*ork_ordu.birimler2.orkdovuscu;
        ToplamOrgDovuscuSaglik=ork_ordu.ork_dovuscu.saglik*ork_ordu.birimler2.orkdovuscu;

        ToplamMizrakciHasar=ork_ordu.mizrakci.saldiri*ork_ordu.birimler2.mizrakci;
        ToplamMizrakciSavunma=ork_ordu.mizrakci.savunma*ork_ordu.birimler2.mizrakci;
        ToplamMizrakciSaglik=ork_ordu.mizrakci.saglik*ork_ordu.birimler2.mizrakci;

        ToplamVargBiniciHasar=ork_ordu.varg_binici.saldiri*ork_ordu.birimler2.vargbinici;
        ToplamVargBiniciSavunma=ork_ordu.varg_binici.savunma*ork_ordu.birimler2.vargbinici;
        ToplamVargBiniciSaglik=ork_ordu.varg_binici.saglik*ork_ordu.birimler2.vargbinici;

        ToplamTrolHasar=ork_ordu.troller.saldiri*ork_ordu.birimler2.troller;
        ToplamTrolSavunma=ork_ordu.troller.savunma*ork_ordu.birimler2.troller;
        ToplamTrolSaglik=ork_ordu.troller.saglik*ork_ordu.birimler2.troller;

        float InsanToplamHasar=ToplamKusatmaHasar+ToplamOkcuHasar+ToplamPiyadeHasar+ToplamSuvariHasar;
        float InsanToplamSavunma=ToplamKusatmaSavunma+ToplamOkcuSavunma+ToplamPiyadeSavunma+ToplamSuvariSavunma;
        float InsanToplamSaglik=ToplamKusatmaSaglik+ToplamOkcuSaglik+ToplamPiyadeSaglik+ToplamSuvariSaglik;
        float OrgToplamHasar=ToplamOrgDovuscuHasar+ToplamMizrakciHasar+ToplamVargBiniciHasar+ToplamTrolHasar;
        float OrgToplamSavunma=ToplamOrgDovuscuSavunma+ToplamMizrakciSavunma+ToplamVargBiniciSavunma+ToplamTrolSavunma;
        float OrgToplamSaglik=ToplamOrgDovuscuSaglik+ToplamMizrakciSaglik+ToplamVargBiniciSaglik+ToplamTrolSaglik;

        float piyadeYuzde=ToplamPiyadeSavunma/InsanToplamSavunma;
        float okcuYuzde=ToplamOkcuSavunma/InsanToplamSavunma;
        float suvariYuzde=ToplamSuvariSavunma/InsanToplamSavunma;
        float kusatmaYuzde=ToplamKusatmaSavunma/InsanToplamSavunma;
        float orkDovuscuYuzde=ToplamOrgDovuscuSavunma/OrgToplamSavunma;
        float mizrakciYuzde=ToplamMizrakciSavunma/OrgToplamSavunma;
        float vargBiniciYuzde=ToplamVargBiniciSavunma/OrgToplamSavunma;
        float trollerYuzde=ToplamTrolSavunma/OrgToplamSavunma;

        if (fmod(tur, (100.0 / insan_ordu.okcu.kritsans)) == 0)
        {
            ToplamOkcuHasar=ToplamOkcuHasar*1.5;
        }
        if (fmod(tur, (100.0 / insan_ordu.piyade.kritsans)) == 0)
        {
            ToplamPiyadeHasar=ToplamPiyadeHasar*1.5;
        }
        if (fmod(tur, (100.0 / insan_ordu.suvari.kritsans)) == 0)
        {
            ToplamSuvariHasar=ToplamSuvariHasar*1.5;
        }
        if (fmod(tur, (100.0 / insan_ordu.kusatma_makine.kritsans)) == 0)
        {
            ToplamKusatmaHasar=ToplamKusatmaHasar*1.5;
        }
        if (fmod(tur, (100.0 / ork_ordu.ork_dovuscu.kritsans)) == 0)
        {
            ToplamOrgDovuscuHasar=ToplamOrgDovuscuHasar*1.5;
        }
        if (fmod(tur, (100.0 / ork_ordu.mizrakci.kritsans)) == 0)
        {
            ToplamMizrakciHasar=ToplamMizrakciHasar*1.5;
        }
        if (fmod(tur, (100.0 / ork_ordu.varg_binici.kritsans)) == 0)
        {
            ToplamVargBiniciHasar=ToplamVargBiniciHasar*1.5;
        }
        if (fmod(tur, (100.0 / ork_ordu.troller.kritsans)) == 0)
        {
            ToplamTrolHasar=ToplamTrolHasar*1.5;
        }
        if (tur%5==0)
        {
            ToplamPiyadeSavunma=ToplamPiyadeSavunma*0.9;
            ToplamPiyadeHasar=ToplamPiyadeHasar*0.9;
            ToplamOkcuSavunma=ToplamOkcuSavunma*0.9;
            ToplamOkcuHasar=ToplamOkcuHasar*0.9;
            ToplamSuvariSavunma=ToplamSuvariSavunma*0.9;
            ToplamSuvariHasar=ToplamSuvariHasar*0.9;
            ToplamKusatmaSavunma=ToplamKusatmaSavunma*0.9;
            ToplamKusatmaHasar=ToplamKusatmaHasar*0.9;
            ToplamOrgDovuscuSavunma=ToplamOrgDovuscuSavunma*0.9;
            ToplamOrgDovuscuHasar=ToplamOrgDovuscuHasar*0.9;
            ToplamMizrakciSavunma=ToplamMizrakciSavunma*0.9;
            ToplamMizrakciHasar=ToplamMizrakciHasar*0.9;
            ToplamVargBiniciSavunma=ToplamVargBiniciSavunma*0.9;
            ToplamVargBiniciHasar=ToplamVargBiniciHasar*0.9;
            ToplamTrolSavunma=ToplamTrolSavunma*0.9;
            ToplamTrolHasar=ToplamTrolHasar*0.9;
        }
        if (tur%2==0 && InsanToplamHasar>OrgToplamSavunma)
        {
            float orkaVerilenHasar=InsanToplamHasar-OrgToplamSavunma;
            float orkDovuscuyeVerilenHasar=orkaVerilenHasar*orkDovuscuYuzde;
            float mizrakciyaVerilenHasar=orkaVerilenHasar*mizrakciYuzde;
            float vargBiniciyeVerilenHasar=orkaVerilenHasar*vargBiniciYuzde;
            float trollereVerilenHasar=orkaVerilenHasar*trollerYuzde;


            ork_ordu.birimler2.orkdovuscu=ork_ordu.birimler2.orkdovuscu-(orkDovuscuyeVerilenHasar/ork_ordu.ork_dovuscu.saglik);
            ToplamOrgDovuscuSaglik=ork_ordu.ork_dovuscu.saglik*ork_ordu.birimler2.orkdovuscu;
            if (ToplamOrgDovuscuSaglik<=0)
            {
                ToplamOrgDovuscuHasar=0;
                ToplamOrgDovuscuSavunma=0;
                orkDovuscuYuzde=0;
            }
            ork_ordu.birimler2.mizrakci=ork_ordu.birimler2.mizrakci-(mizrakciyaVerilenHasar/ork_ordu.mizrakci.saglik);
            ToplamMizrakciSaglik=ork_ordu.mizrakci.saglik*ork_ordu.birimler2.mizrakci;
            if (ToplamMizrakciSaglik<=0)
            {
                ToplamMizrakciHasar=0;
                ToplamMizrakciSavunma=0;
                mizrakciYuzde=0;
            }
            ork_ordu.birimler2.vargbinici=ork_ordu.birimler2.vargbinici-(vargBiniciyeVerilenHasar/ork_ordu.varg_binici.saglik);
            ToplamVargBiniciSaglik=ork_ordu.varg_binici.saglik*ork_ordu.birimler2.vargbinici;
            if (ToplamVargBiniciSaglik<=0)
            {
                ToplamVargBiniciHasar=0;
                ToplamVargBiniciSavunma=0;
                vargBiniciYuzde=0;
            }
            ork_ordu.birimler2.troller=ork_ordu.birimler2.troller-(trollereVerilenHasar/ork_ordu.troller.saglik);
            ToplamTrolSaglik=ork_ordu.troller.saglik*ork_ordu.birimler2.troller;
            if (ToplamTrolSaglik<=0)
            {
                ToplamTrolHasar=0;
                ToplamTrolSavunma=0;
                trollerYuzde=0;
            }
            if(ork_ordu.birimler2.mizrakci<=0)
            {
                ork_ordu.birimler2.mizrakci=0;
            }
            if(ork_ordu.birimler2.troller<=0)
            {
                ork_ordu.birimler2.troller=0;
            }
            if(ork_ordu.birimler2.vargbinici<=0)
            {
                ork_ordu.birimler2.vargbinici=0;
            }
            if(ork_ordu.birimler2.orkdovuscu<=0)
            {
                ork_ordu.birimler2.orkdovuscu=0;
            }

            fprintf(dospoi11,"tur:%d\n\n",tur+1);
            fprintf(dospoi11,"Insanlar saldirdi\n\n");

            fprintf(dospoi11,"ork ordu alınan toplam hasar:%.2f\n\n",orkaVerilenHasar);

            fprintf(dospoi11,"kalan mizrakci:%.2f\n",ork_ordu.birimler2.mizrakci);
            fprintf(dospoi11,"mizrakci aldığı hasar:%.2f\n",mizrakciyaVerilenHasar);
            if (ToplamMizrakciSaglik<0){
                ToplamMizrakciSaglik=0;
                fprintf(dospoi11,"mizrakci toplam saglik:%.2f\n",ToplamMizrakciSaglik);

            }
            else{
            fprintf(dospoi11,"mizrakci toplam saglik:%.2f\n",ToplamMizrakciSaglik);
            }
            fprintf(dospoi11,"mizrakci toplam savunma:%.2f\n\n",ToplamMizrakciSavunma);

            fprintf(dospoi11,"kalan varg binici:%.2f\n",ork_ordu.birimler2.vargbinici);
            fprintf(dospoi11,"varg binici alınan hasar:%.2f\n",vargBiniciyeVerilenHasar);
            if (ToplamVargBiniciSaglik<0){
                ToplamVargBiniciSaglik=0;
                fprintf(dospoi11,"varg binici toplam saglik:%.2f\n",ToplamVargBiniciSaglik);

            }
            else{
            fprintf(dospoi11,"varg binici toplam saglik:%.2f\n",ToplamVargBiniciSaglik);
            }
            fprintf(dospoi11," varg binici toplam savunma:%.2f\n\n",ToplamVargBiniciSavunma);

            fprintf(dospoi11,"kalan  troller:%.2f\n",ork_ordu.birimler2.troller);
            fprintf(dospoi11,"troller alınan hasar:%.2f\n",trollereVerilenHasar);
            if (ToplamTrolSaglik<0){
                ToplamTrolSaglik=0;
                fprintf(dospoi11,"troller toplam saglik:%.2f\n",ToplamTrolSaglik);

            }
            else{
            fprintf(dospoi11,"troller toplam saglik:%.2f\n",ToplamTrolSaglik);
            }
            fprintf(dospoi11," troller toplam savunma:%.2f\n\n",ToplamTrolSavunma);

            fprintf(dospoi11,"kalan ork dovuscu:%.2f\n",ork_ordu.birimler2.troller);
            fprintf(dospoi11,"ork dovuscu alınan hasar:%.2f\n",orkDovuscuyeVerilenHasar);
            if (ToplamOrgDovuscuSaglik<0){
                ToplamOrgDovuscuSaglik=0;
                fprintf(dospoi11,"ork dovuscu toplam saglik:%.2f\n",ToplamOrgDovuscuSaglik);

            }
            else{
            fprintf(dospoi11,"ork dovuscu toplam saglik:%.2f\n",ToplamOrgDovuscuSaglik);
            }
            fprintf(dospoi11," ork dovuscu toplam savunma:%.2f\n\n\n",ToplamOrgDovuscuSavunma);
        }
        else if (tur%2==0 && InsanToplamHasar<OrgToplamSavunma && InsanToplamSaglik>0)
        {
        fprintf(dospoi11,"tur:%d\n\n",tur+1);

        fprintf(dospoi11,"Insanlar saldiri gucleri yetmedigi için bu tur saldiramadilar.\n\n");
        }
        if (tur%2==1 && OrgToplamHasar>InsanToplamSavunma)
        {
            float insanaVerilenHasar=OrgToplamHasar-InsanToplamSavunma;
            float piyadeyeVerilenHasar=insanaVerilenHasar*piyadeYuzde;
            float okcuyaVerilenHasar=insanaVerilenHasar*okcuYuzde;
            float suvariyeVerilenHasar=insanaVerilenHasar*suvariYuzde;
            float kusatmayaVerilenHasar=insanaVerilenHasar*kusatmaYuzde;


            insan_ordu.birimler.piyadesayi=insan_ordu.birimler.piyadesayi-(piyadeyeVerilenHasar/insan_ordu.piyade.saglik);
            ToplamPiyadeSaglik=insan_ordu.piyade.saglik*insan_ordu.birimler.piyadesayi;
            if (ToplamPiyadeSaglik<=0)
            {
                ToplamPiyadeHasar=0;
                ToplamPiyadeSavunma=0;
                piyadeYuzde=0;
            }
            insan_ordu.birimler.okcusayi=insan_ordu.birimler.okcusayi-(okcuyaVerilenHasar/insan_ordu.okcu.saglik);
            ToplamOkcuSaglik=insan_ordu.okcu.saglik*insan_ordu.birimler.okcusayi;
            if (ToplamOkcuSaglik<=0)
            {
                ToplamOkcuHasar=0;
                ToplamOkcuSavunma=0;
                okcuYuzde=0;
            }
            insan_ordu.birimler.suvarisayi=insan_ordu.birimler.suvarisayi-(suvariyeVerilenHasar/insan_ordu.suvari.saglik);
            ToplamSuvariSaglik=insan_ordu.suvari.saglik*insan_ordu.birimler.suvarisayi;
            if (ToplamSuvariSaglik<=0)
            {
                ToplamSuvariHasar=0;
                ToplamSuvariSavunma=0;
                suvariYuzde=0;
            }
            insan_ordu.birimler.kusatma_m_sayi=insan_ordu.birimler.kusatma_m_sayi-(kusatmayaVerilenHasar/insan_ordu.kusatma_makine.saglik);
            ToplamKusatmaSaglik=insan_ordu.kusatma_makine.saglik*insan_ordu.birimler.kusatma_m_sayi;
            if(ToplamKusatmaSaglik<=0)
            {
                ToplamKusatmaHasar=0;
                ToplamKusatmaSavunma=0;
                kusatmaYuzde=0;
            }

            if(insan_ordu.birimler.okcusayi<=0)
            {
                insan_ordu.birimler.okcusayi=0;
            }
            if(insan_ordu.birimler.kusatma_m_sayi<=0)
            {
                insan_ordu.birimler.kusatma_m_sayi=0;
            }
            if(insan_ordu.birimler.suvarisayi<=0)
            {
                insan_ordu.birimler.suvarisayi=0;
            }
            if(insan_ordu.birimler.piyadesayi<=0)
            {
                insan_ordu.birimler.piyadesayi=0;
            }
            fprintf(dospoi11,"tur:%d\n\n",tur+1);
            fprintf(dospoi11,"Orklar saldirdi\n\n");
            fprintf(dospoi11,"ınsan ordu alınan toplam hasar:%.2f\n\n",insanaVerilenHasar);
            fprintf(dospoi11,"kalan okcu:%.2f\n",insan_ordu.birimler.okcusayi);
            fprintf(dospoi11,"okcu alınan hasar:%.2f\n",okcuyaVerilenHasar);
            if (ToplamOkcuSaglik<0){
                ToplamOkcuSaglik=0;
                fprintf(dospoi11,"okcu toplam saglik:%.2f\n",ToplamOkcuSaglik);

            }
            else{
            fprintf(dospoi11,"okcu toplam saglik:%.2f\n",ToplamOkcuSaglik);
            }
            fprintf(dospoi11,"okcu  toplam savunma:%.2f\n\n",ToplamOkcuSavunma);


            fprintf(dospoi11,"kalan suvari:%.2f\n",insan_ordu.birimler.suvarisayi);
            fprintf(dospoi11,"suvari alınan hasar:%.2f\n",suvariyeVerilenHasar);
            if (ToplamSuvariSaglik<0){
                ToplamSuvariSaglik=0;
                fprintf(dospoi11,"suvari toplam saglik:%.2f\n",ToplamSuvariSaglik);

            }
            else{
            fprintf(dospoi11,"suvari toplam saglik:%.2f\n",ToplamSuvariSaglik);
            }
            fprintf(dospoi11,"suvari toplam savunma:%.2f\n\n",ToplamSuvariSavunma);

            fprintf(dospoi11,"kalan piyade:%.2f\n",insan_ordu.birimler.piyadesayi);
            fprintf(dospoi11,"piyade alınan hasar:%.2f\n",piyadeyeVerilenHasar);
            if (ToplamPiyadeSaglik<0){
                ToplamPiyadeSaglik=0;
                fprintf(dospoi11,"piyade toplam saglik:%.2f\n",ToplamPiyadeSaglik);

            }
            else{
            fprintf(dospoi11,"piyade toplam saglik:%.2f\n",ToplamPiyadeSaglik);
            }
            fprintf(dospoi11,"piyade  savunma:%.2f\n\n",ToplamPiyadeSavunma);

            fprintf(dospoi11,"kalan kusatma makinesi:%.2f\n",insan_ordu.birimler.kusatma_m_sayi);
            fprintf(dospoi11,"kusatma makinesi alınan hasar:%.2f\n",kusatmayaVerilenHasar);
            if (ToplamKusatmaSaglik<0){
                ToplamKusatmaSaglik=0;
                fprintf(dospoi11,"kusatma makinesi toplam saglik:%.2f\n",ToplamKusatmaSaglik);

            }
            else{
            fprintf(dospoi11,"kusatma makinesi toplam saglik:%.2f\n",ToplamKusatmaSaglik);
            }
            fprintf(dospoi11,"kusatma makinesi  savunma:%.2f\n\n\n",ToplamKusatmaSavunma);
        }
        else if (tur%2==1 && OrgToplamHasar<InsanToplamSavunma && OrgToplamSaglik>0)
        {
            fprintf(dospoi11,"tur:%d\n\n",tur+1);

            fprintf(dospoi11,"Orklar saldiri gucleri yetmedigi için bu tur saldiramadilar.\n\n");
        }
        tur+=1;
        if (InsanToplamSaglik<=0)
        {
            fprintf(dospoi11,"tur:%d\n\n",tur);

            fprintf(dospoi11,"Orglar kazandi ");
            break;
        }
        if (OrgToplamSaglik<=0)
        {
            fprintf(dospoi11,"tur:%d\n\n",tur);

            fprintf(dospoi11,"Insanlar kazandi \n");
            break;
        }
    }
    okcutekrar=0;
    suvaritekrar=0;
    kusatmatekrar=0;
    piyadetekrar=0;
    orgdovuscutekrar=0;
    mizrakcitekrar=0;
    vargbinicitekrar=0;
    troltekrar=0;

    if (insan_ordu.birimler.okcusayi<1 && insan_ordu.birimler.okcusayi>0)
    {
        insan_ordu.birimler.okcusayi=1;
    }
    if (insan_ordu.birimler.piyadesayi<1 && insan_ordu.birimler.piyadesayi>0)
    {
        insan_ordu.birimler.piyadesayi=1;
    }
    if (insan_ordu.birimler.suvarisayi<1 && insan_ordu.birimler.suvarisayi>0)
    {
        insan_ordu.birimler.suvarisayi=1;
    }
    if (insan_ordu.birimler.kusatma_m_sayi<1 && insan_ordu.birimler.kusatma_m_sayi>0)
    {
        insan_ordu.birimler.kusatma_m_sayi=1;
    }
    if (ork_ordu.birimler2.orkdovuscu<1 && ork_ordu.birimler2.orkdovuscu>0)
    {
        ork_ordu.birimler2.orkdovuscu=1;
    }
    if (ork_ordu.birimler2.mizrakci<1 && ork_ordu.birimler2.mizrakci>0)
    {
        ork_ordu.birimler2.mizrakci=1;
    }
    if (ork_ordu.birimler2.vargbinici<1 && ork_ordu.birimler2.vargbinici>0)
    {
        ork_ordu.birimler2.vargbinici=1;
    }
    if (ork_ordu.birimler2.troller<1 && ork_ordu.birimler2.troller>0)
    {
        ork_ordu.birimler2.troller=1;
    }

    if ((int)insan_ordu.birimler.okcusayi%100==0)
    {
        okcutekrar=insan_ordu.birimler.okcusayi/100;
    }
    else
    {
        okcutekrar=insan_ordu.birimler.okcusayi/100+1;
    }
    if ((int)insan_ordu.birimler.piyadesayi%100==0)
    {
        piyadetekrar=insan_ordu.birimler.piyadesayi/100;
    }
    else
    {
        piyadetekrar=insan_ordu.birimler.piyadesayi/100+1;
    }
    if ((int)insan_ordu.birimler.suvarisayi%100==0)
    {
        suvaritekrar=insan_ordu.birimler.suvarisayi/100;
    }
    else
    {
        suvaritekrar=insan_ordu.birimler.suvarisayi/100+1;
    }
    if ((int)insan_ordu.birimler.kusatma_m_sayi%100==0)
    {
        kusatmatekrar=insan_ordu.birimler.kusatma_m_sayi/100;
    }
    else
    {
        kusatmatekrar=insan_ordu.birimler.kusatma_m_sayi/100+1;
    }
    if ((int)ork_ordu.birimler2.orkdovuscu%100==0)
    {
        orgdovuscutekrar=ork_ordu.birimler2.orkdovuscu/100;
    }
    else
    {
        orgdovuscutekrar=insan_ordu.birimler.orkdovuscu/100+1;
    }
    if ((int)ork_ordu.birimler2.mizrakci%100==0)
    {
        mizrakcitekrar=ork_ordu.birimler2.mizrakci/100;
    }
    else
    {
        mizrakcitekrar=insan_ordu.birimler.mizrakci/100+1;
    }
    if ((int)ork_ordu.birimler2.vargbinici%100==0)
    {
        vargbinicitekrar=ork_ordu.birimler2.vargbinici/100;
    }
    else
    {
        vargbinicitekrar=insan_ordu.birimler.vargbinici/100+1;
    }
    if ((int)ork_ordu.birimler2.troller%100==0)
    {
        troltekrar=ork_ordu.birimler2.troller/100;
    }
    else
    {
        troltekrar=insan_ordu.birimler.troller/100+1;
    }
    okcu_saglik = insan_ordu.okcu.saglik*insan_ordu.birimler.okcusayi;
    suvari_saglik = insan_ordu.suvari.saglik*insan_ordu.birimler.suvarisayi,
    kusatma_saglik = insan_ordu.kusatma_makine.saglik*insan_ordu.birimler.kusatma_m_sayi;
    piyade_saglik = insan_ordu.piyade.saglik*insan_ordu.birimler.piyadesayi;
    orgdovuscu_saglik=ork_ordu.ork_dovuscu.saglik*ork_ordu.birimler2.orkdovuscu;
    mizrakci_saglik=ork_ordu.mizrakci.saglik*ork_ordu.birimler2.mizrakci;
    vargbinici_saglik=ork_ordu.varg_binici.saglik*ork_ordu.birimler2.vargbinici;
    troller_saglik=ork_ordu.troller.saglik*ork_ordu.birimler2.troller;

    int quitt = 0;
    SDL_Event a;
    while (!quitt)
    {
        while (SDL_PollEvent(&a) != 0)
        {
            if (a.type == SDL_QUIT)
            {
                quitt = 1;
            }
        }

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);

        SDL_Rect arkaplanRect = { 0, 0, screenWidth, screenHeight };

        SDL_RenderCopy(renderer, arkaplanresmidokusu, NULL, &arkaplanRect);

        izgaraCiz(renderer, offsetX, offsetY);

        for (int i = 0; i < okcutekrar; ++i)
        {
            SDL_Rect destRect = { ((GRID_SIZE*19 / GRID_SIZE) * CELL_SIZE)-11, (2*(i % GRID_SIZE) * CELL_SIZE)+133, CELL_SIZE, CELL_SIZE };
            SDL_RenderCopy(renderer, okcuresmidokusu, NULL, &destRect);
            canBarCiz(renderer, destRect.x, destRect.y, okcu_saglik, okcu_max_saglik);
        }
        for (int j = 0; j < suvaritekrar; ++j)
        {
            SDL_Rect destRect = { ((GRID_SIZE*20 / GRID_SIZE) * CELL_SIZE)-11, (2*(j % GRID_SIZE) * CELL_SIZE)+133, CELL_SIZE, CELL_SIZE };
            SDL_RenderCopy(renderer, suvariresmidokusu, NULL, &destRect);
            canBarCiz(renderer, destRect.x, destRect.y, suvari_saglik, suvari_max_saglik);
        }
        for (int k = 0; k < kusatmatekrar; ++k)
        {
            SDL_Rect destRect = { ((GRID_SIZE*18 / GRID_SIZE) * CELL_SIZE)-11, (2*(k % GRID_SIZE) * CELL_SIZE)+133, CELL_SIZE, CELL_SIZE };
            SDL_RenderCopy(renderer, kusatmaresmidokusu, NULL, &destRect);
            canBarCiz(renderer, destRect.x, destRect.y, kusatma_saglik, kusatma_max_saglik);
        }
        for (int l = 0; l < piyadetekrar; ++l)
        {
            SDL_Rect destRect = { ((GRID_SIZE*21 / GRID_SIZE) * CELL_SIZE)-11, (2*(l % GRID_SIZE) * CELL_SIZE)+133, CELL_SIZE, CELL_SIZE };
            SDL_RenderCopy(renderer, piyaderesmidokusu, NULL, &destRect);
            canBarCiz(renderer, destRect.x, destRect.y, piyade_saglik, piyade_max_saglik);
        }
        for (int m = 0; m < orgdovuscutekrar; ++m)
        {
            SDL_Rect destRect = { ((GRID_SIZE*30 / GRID_SIZE) * CELL_SIZE)-11, (2*(m % GRID_SIZE) * CELL_SIZE)+133, CELL_SIZE, CELL_SIZE };
            SDL_RenderCopy(renderer, orkdovuscuresmidokusu, NULL, &destRect);
            canBarCiz(renderer, destRect.x, destRect.y, orgdovuscu_saglik, orgdovuscu_max_saglik);
        }
        for (int n = 0; n < mizrakcitekrar; ++n)
        {
            SDL_Rect destRect = { ((GRID_SIZE*32 / GRID_SIZE) * CELL_SIZE)-11, (2*(n % GRID_SIZE) * CELL_SIZE)+133, CELL_SIZE, CELL_SIZE };
            SDL_RenderCopy(renderer, mizrakciresmidokusu, NULL, &destRect);
            canBarCiz(renderer, destRect.x, destRect.y, mizrakci_saglik, mizrakci_max_saglik);
        }
        for (int o = 0; o < vargbinicitekrar; ++o)
        {
            SDL_Rect destRect = { ((GRID_SIZE*31 / GRID_SIZE) * CELL_SIZE)-11,  (2*(o % GRID_SIZE) * CELL_SIZE)+133, CELL_SIZE, CELL_SIZE };
            SDL_RenderCopy(renderer, vargbiniciresmidokusu, NULL, &destRect);
            canBarCiz(renderer, destRect.x, destRect.y, vargbinici_saglik, vargbinici_max_saglik);
        }
        for (int p = 0; p < troltekrar; ++p)
        {
            SDL_Rect destRect = { ((GRID_SIZE*33 / GRID_SIZE) * CELL_SIZE)-11,  (2*(p % GRID_SIZE) * CELL_SIZE)+133, CELL_SIZE, CELL_SIZE };
            SDL_RenderCopy(renderer, trolresmidokusu, NULL, &destRect);
            canBarCiz(renderer, destRect.x, destRect.y, troller_saglik, troller_max_saglik);
        }

        SDL_Rect savassonrasirect = { offsetX + (gridWidth - TOP_IMAGE_WIDTH) / 2, offsetY - TOP_IMAGE_HEIGHT - 10, TOP_IMAGE_WIDTH, TOP_IMAGE_HEIGHT };
        SDL_RenderCopy(renderer, savassonrasidokusu, NULL, &savassonrasirect);

        SDL_Rect insanlarrect = { offsetX -360+ (gridWidth - TOP_IMAGE_WIDTH) / 2, offsetY - TOP_IMAGE_HEIGHT + 15, TOP_IMAGE_WIDTH, TOP_IMAGE_HEIGHT-20 };
    SDL_RenderCopy(renderer, insanlarresmidokusu, NULL, &insanlarrect);

    SDL_Rect orklarrect = { offsetX +360+ (gridWidth - TOP_IMAGE_WIDTH) / 2, offsetY - TOP_IMAGE_HEIGHT + 15, TOP_IMAGE_WIDTH, TOP_IMAGE_HEIGHT-20 };
    SDL_RenderCopy(renderer, orklarresmidokusu, NULL, &orklarrect);

        if (strcmp(insan_ordu.bulunankahraman.bulunan1,"Fatih_Sultan_Mehmet")==0)
        {
            SDL_Rect fatihrect = { offsetX - IMAGE_SIZE - 10, offsetY, IMAGE_SIZE, IMAGE_SIZE };
            SDL_RenderCopy(renderer, fsmresmidokusu, NULL, &fatihrect);
        }
        if (strcmp(insan_ordu.bulunankahraman.bulunan1,"Yavuz_Sultan_Selim")==0)
        {
            SDL_Rect yavuzrect = { offsetX - IMAGE_SIZE - 10, offsetY, IMAGE_SIZE, IMAGE_SIZE };
            SDL_RenderCopy(renderer, yssresmidokusu, NULL, &yavuzrect);
        }
        if (strcmp(insan_ordu.bulunankahraman.bulunan1,"Tugrul_Bey")==0)
        {
            SDL_Rect tugrulrect = { offsetX - IMAGE_SIZE - 10, offsetY, IMAGE_SIZE, IMAGE_SIZE };
            SDL_RenderCopy(renderer, tugrulresmidokusu, NULL, &tugrulrect);
        }
        if (strcmp(insan_ordu.bulunankahraman.bulunan1,"Mete_Han")==0)
        {
            SDL_Rect meterect = { offsetX - IMAGE_SIZE - 10, offsetY, IMAGE_SIZE, IMAGE_SIZE };
            SDL_RenderCopy(renderer, meteresmidokusu, NULL, &meterect);
        }
        if (strcmp(insan_ordu.bulunankahraman.bulunan1,"Alparslan")==0)
        {
            SDL_Rect alparslanrect = { offsetX - IMAGE_SIZE - 10, offsetY, IMAGE_SIZE, IMAGE_SIZE };
            SDL_RenderCopy(renderer, alparslanresmidokusu, NULL, &alparslanrect);
        }
        if (strcmp(ork_ordu.bulunankahraman.bulunan1,"Goruk_Vahsi")==0)
        {
            SDL_Rect gorukrect = { offsetX + GRID_SIZE * CELL_SIZE + 10, offsetY, IMAGE_SIZE, IMAGE_SIZE };
    SDL_RenderCopy(renderer, gorukresmidokusu, NULL, &gorukrect);
        }
        if (strcmp(ork_ordu.bulunankahraman.bulunan1,"Thruk_Kemikkiran")==0)
        {
            SDL_Rect thrukrect = { offsetX + GRID_SIZE * CELL_SIZE + 10, offsetY, IMAGE_SIZE, IMAGE_SIZE };
    SDL_RenderCopy(renderer, thrukresmidokusu, NULL, &thrukrect);
        }
        if (strcmp(ork_ordu.bulunankahraman.bulunan1,"Vrog_Kafakiran")==0)
        {
            SDL_Rect vrogrect = { offsetX + GRID_SIZE * CELL_SIZE + 10, offsetY, IMAGE_SIZE, IMAGE_SIZE };
    SDL_RenderCopy(renderer, vrogresmidokusu, NULL, &vrogrect);
        }
        if (strcmp(ork_ordu.bulunankahraman.bulunan1,"Ugar_Zalim")==0)
        {
            SDL_Rect ugarrect = { offsetX + GRID_SIZE * CELL_SIZE + 10, offsetY, IMAGE_SIZE, IMAGE_SIZE };
    SDL_RenderCopy(renderer, ugarresmidokusu, NULL, &ugarrect);
        }
        if (strcmp(insan_ordu.bulunancanavar.bulunan1,"Ejderha")==0)
        {
            SDL_Rect ejderrect = { offsetX - IMAGE_SIZE - 10, offsetY + IMAGE_SIZE + IMAGE_SPACING, IMAGE_SIZE, IMAGE_SIZE };
    SDL_RenderCopy(renderer, ejderharesmidokusu, NULL, &ejderrect);
        }
        if (strcmp(insan_ordu.bulunancanavar.bulunan1,"Agri_Dagi_Devleri")==0)
        {
            SDL_Rect agrirect = { offsetX - IMAGE_SIZE - 10, offsetY + IMAGE_SIZE + IMAGE_SPACING, IMAGE_SIZE, IMAGE_SIZE };
    SDL_RenderCopy(renderer, agridagiresmidokusu, NULL, &agrirect);
        }
        if (strcmp(insan_ordu.bulunancanavar.bulunan1,"Tepegoz")==0)
        {
            SDL_Rect tepegozrect = { offsetX - IMAGE_SIZE - 10, offsetY + IMAGE_SIZE + IMAGE_SPACING, IMAGE_SIZE, IMAGE_SIZE };
    SDL_RenderCopy(renderer, tepegozresmidokusu, NULL, &tepegozrect);
        }
        if (strcmp(insan_ordu.bulunancanavar.bulunan1,"Karakurt")==0)
        {
            SDL_Rect karakurtrect = { offsetX - IMAGE_SIZE - 10, offsetY + IMAGE_SIZE + IMAGE_SPACING, IMAGE_SIZE, IMAGE_SIZE };
    SDL_RenderCopy(renderer, karakurtresmidokusu, NULL, &karakurtrect);
        }
        if (strcmp(insan_ordu.bulunancanavar.bulunan1,"Samur")==0)
        {
            SDL_Rect samurrect = { offsetX - IMAGE_SIZE - 10, offsetY + IMAGE_SIZE + IMAGE_SPACING, IMAGE_SIZE, IMAGE_SIZE };
    SDL_RenderCopy(renderer, samurresmidokusu, NULL, &samurrect);
        }
        if (strcmp(ork_ordu.bulunancanavar.bulunan1,"Kara_Troll")==0)
        {
            SDL_Rect karatrolrect = { offsetX + GRID_SIZE * CELL_SIZE + 10, offsetY + IMAGE_SIZE + IMAGE_SPACING, IMAGE_SIZE, IMAGE_SIZE };
    SDL_RenderCopy(renderer, karatrolresmidokusu, NULL, &karatrolrect);
        }
        if (strcmp(ork_ordu.bulunancanavar.bulunan1,"Golge_Kurtlari")==0)
        {
            SDL_Rect golgekurtrect = { offsetX + GRID_SIZE * CELL_SIZE + 10, offsetY + IMAGE_SIZE + IMAGE_SPACING, IMAGE_SIZE, IMAGE_SIZE };
    SDL_RenderCopy(renderer, golgekurtlariresmidokusu, NULL, &golgekurtrect);
        }
        if (strcmp(ork_ordu.bulunancanavar.bulunan1,"Camur_Devleri")==0)
        {
            SDL_Rect camurdevirect = { offsetX + GRID_SIZE * CELL_SIZE + 10, offsetY + IMAGE_SIZE + IMAGE_SPACING, IMAGE_SIZE, IMAGE_SIZE };
    SDL_RenderCopy(renderer, camurdeviresmidokusu, NULL, &camurdevirect);
        }
        if (strcmp(ork_ordu.bulunancanavar.bulunan1,"Ates_Iblisi")==0)
        {
            SDL_Rect atesiblisirect = { offsetX + GRID_SIZE * CELL_SIZE + 10, offsetY + IMAGE_SIZE + IMAGE_SPACING, IMAGE_SIZE, IMAGE_SIZE };
    SDL_RenderCopy(renderer, atesiblisiresmidokusu, NULL, &atesiblisirect);
        }
        if (strcmp(ork_ordu.bulunancanavar.bulunan1,"Makrog_Savas_Beyi")==0)
        {
            SDL_Rect makrokrect = { offsetX + GRID_SIZE * CELL_SIZE + 10, offsetY + IMAGE_SIZE + IMAGE_SPACING, IMAGE_SIZE, IMAGE_SIZE };
    SDL_RenderCopy(renderer, makrokresmidokusu, NULL, &makrokrect);
        }
        if (strcmp(ork_ordu.bulunancanavar.bulunan1,"Buz_Devleri")==0)
        {
            SDL_Rect buzdevirect = { offsetX + GRID_SIZE * CELL_SIZE + 10, offsetY + IMAGE_SIZE + IMAGE_SPACING, IMAGE_SIZE, IMAGE_SIZE };
    SDL_RenderCopy(renderer, buzdeviresmidokusu, NULL, &buzdevirect);
        }
        SDL_RenderPresent(renderer);
        SDL_Delay(3000);
        quitt = 1;
    }

    SDL_DestroyTexture(okcuresmidokusu);
    SDL_DestroyTexture(suvariresmidokusu);
    SDL_DestroyTexture(kusatmaresmidokusu);
    SDL_DestroyTexture(piyaderesmidokusu);
    SDL_DestroyTexture(orkdovuscuresmidokusu);
    SDL_DestroyTexture(mizrakciresmidokusu);
    SDL_DestroyTexture(vargbiniciresmidokusu);
    SDL_DestroyTexture(trolresmidokusu);
    SDL_DestroyTexture(fsmresmidokusu);
    SDL_DestroyTexture(yssresmidokusu);
    SDL_DestroyTexture(tugrulresmidokusu);
    SDL_DestroyTexture(meteresmidokusu);
    SDL_DestroyTexture(alparslanresmidokusu);
    SDL_DestroyTexture(vrogresmidokusu);
    SDL_DestroyTexture(thrukresmidokusu);
    SDL_DestroyTexture(ugarresmidokusu);
    SDL_DestroyTexture(gorukresmidokusu);
    SDL_DestroyTexture(ejderharesmidokusu);
    SDL_DestroyTexture(tepegozresmidokusu);
    SDL_DestroyTexture(karakurtresmidokusu);
    SDL_DestroyTexture(agridagiresmidokusu);
    SDL_DestroyTexture(samurresmidokusu);
    SDL_DestroyTexture(makrokresmidokusu);
    SDL_DestroyTexture(atesiblisiresmidokusu);
    SDL_DestroyTexture(camurdeviresmidokusu);
    SDL_DestroyTexture(buzdeviresmidokusu);
    SDL_DestroyTexture(golgekurtlariresmidokusu);
    SDL_DestroyTexture(karatrolresmidokusu);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
     }
    else
    {
        printf("Gecersiz numara! Lutfen 1 ile 10 arasinda bir numara secin.\n");
        goto A;
    }
    printf("Savas sona erdi\n");

    return 0;
}

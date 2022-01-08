#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct ders{
    char ders_kodu[10];
    char ders_adi[50];
    int kredi;
    int kontenjan;
    int kayitli_ogr_sayisi;
    char durum[20];
    char **ogr_no;
    struct ders *next;
}DERS;

typedef struct ogrenci{
    char no[30];
    char ad[30];
    char soyad[30];
    int kaydoldugu_ders_sayisi;
    int kaydoldugu_toplam_kredi;
    struct ogrenci *next;
    struct ogrenci *prev;
}OGRENCI;


void dersEkle(DERS **head);
void dersKapat(DERS **head);
void dersdosyayaKaydet(DERS *head);
void ogrenciEkle(OGRENCI **head);
void ogrenciSil(OGRENCI **head);
void ogrencidosyayaKaydet(OGRENCI *head);
void ogrenci_ders_kayit(DERS **head1, OGRENCI **head2, int max_ders, int max_kredi, char *tarih, int *id);
void ogrenciDersKayit_dosyayaKaydet(DERS **tmp1, OGRENCI **tmp2, char *tarih, int *id);
void DersListesineSiraliOgrenciEkle(DERS **tmp1, OGRENCI **tmp2, int max_ders, int max_kredi, char *tarih, int *id);
void DersListesindenOgrenciSil(DERS **tmp1, OGRENCI **tmp2, char *tarih, int *id);
void printDerslerinOgrenciListesi(DERS *head);
void printOgrencininAldigiTumDersler(DERS *head);


int main(){
    setlocale(LC_ALL, "Turkish");
    int max_ders,max_kredi,id=1;
    int secim=0,k=0,c;
    char *tarih = (char*)malloc(15*sizeof(char));
    DERS *head1 = NULL;
    OGRENCI *head2 = NULL;


    while(secim!=6){
        printf("\n1)Ders Ekle/Kapat  2)Ogrenci Ekle/Sil  3)Ogrenci-Ders Kayıt  4)Derse kayıtlı öğrencileri listele  5)Öğrencinin aldığı tüm dersleri listele  6)Çıkış\nLütfen seçim yapınız: ");
        scanf("%d",&secim);

        switch(secim){
            case 1:
                printf("Ders eklemek icin 1, ders kapatmak için 2, dersleri dosyaya kaydetmek için 3: ");
                scanf("%d",&c);
                if(c==1){
                    dersEkle(&head1);
                }
                else if(c==2){
                    dersKapat(&head1);
                }
                else if(c==3){
                    dersdosyayaKaydet(head1);
                }
                else{
                    printf("Hatali islem girdiniz..\n");
                }
                break;
            case 2:
                printf("Ogrenci eklemek icin 1, ogrenci silmek için 2, ogrencileri dosyaya kaydetmek için 3: ");
                scanf("%d",&c);
                if(c==1){
                    ogrenciEkle(&head2);
                }
                else if(c==2){
                    ogrenciSil(&head2);
                }
                else if(c==3){
                    ogrencidosyayaKaydet(head2);
                }
                else{
                    printf("Hatali islem girdiniz..\n");
                }
                break;
            case 3:
                if(k==0){
                    printf("Kayıt yapılacak maksimum ders sayısını giriniz: "); scanf("%d",&max_ders);
                    printf("Kayıt yapılacak maksimum kredi değerini giriniz: "); scanf("%d",&max_kredi);
                    k=1;
                }
                ogrenci_ders_kayit(&head1,&head2,max_ders,max_kredi,tarih,&id);
                break;
            case 4:
                printDerslerinOgrenciListesi(head1);
                break;
            case 5:
                printOgrencininAldigiTumDersler(head1);
                break;
            case 6:
                printf("Çıkış yapılıyor..\n");
                break;
            default:
                printf("Hatali islem girdiniz..\n");
        }
    }
    return 0;
}

void printDerslerinOgrenciListesi(DERS *head){
    DERS *tmp = head;
    int i,k=0;
    char ders_kodu[20];

    fflush(stdin);
    printf("Dersin kodunu giriniz: "); gets(ders_kodu);
    while(tmp!=NULL){
        if(strcmp(tmp->ders_kodu,ders_kodu) == 0){
            for(i=0;i<(tmp->kayitli_ogr_sayisi);i++){
                printf("%s\n",tmp->ogr_no[i]);
            }
            k=1;
            printf("\n");
        }
        tmp = tmp->next;
    }
    if(k!=1){
        printf("Hata!! Böyle bir ders bulunmamaktadır..\n");
    }
}

void printOgrencininAldigiTumDersler(DERS *head){
    DERS *tmp = head;
    int i,k=0;
    char ogrenci_no[20];

    fflush(stdin);
    printf("Ogrencinin numarasını giriniz: "); gets(ogrenci_no);
    while(tmp!=NULL){
        for(i=0;i<(tmp->kayitli_ogr_sayisi);i++){
            if(strcmp(tmp->ogr_no[i],ogrenci_no) == 0){
                printf("%s\n",tmp->ders_kodu);
                k=1;
            }
        }
        tmp = tmp->next;
    }
    if(k!=1){
        printf("Hata!! Böyle bir öğrenci bulunamamaktadır..\n");
    }
}

void dersEkle(DERS **head){
    DERS *newNode = (DERS*)malloc(sizeof(DERS));
    DERS *tmp,*k;
    int c=0;
    k = (*head);
    fflush(stdin);
    printf("Dersin kodunu giriniz: "); gets(newNode->ders_kodu);
    printf("Dersin adını giriniz: "); gets(newNode->ders_adi);
    printf("Dersin kredisini giriniz: "); scanf("%d",&newNode->kredi);
    printf("Dersin kontenjanını giriniz: "); scanf("%d",&newNode->kontenjan);
    newNode->kayitli_ogr_sayisi = 0;
    strcpy(newNode->durum,"ACIK");
    newNode->next = NULL;
    
    while(k!=NULL){
        if(strcmp(k->ders_kodu,newNode->ders_kodu)==0){
            printf("Hata!! Aynı koda sahip bir ders eklemek istediniz..\n");
            c=1;
        }
        k = k->next;
    }
    if(c!=1){    
        if((*head) == NULL){ 
            (*head) = newNode;
        }
        else if(strcmp((*head)->ders_kodu,newNode->ders_kodu) > 0){
            newNode->next = (*head);
            (*head) = newNode;
        }
        else{
            tmp = (*head);
            while(tmp->next != NULL && (strcmp(tmp->next->ders_kodu,newNode->ders_kodu) < 0)){
                tmp = tmp->next;
            }
            newNode->next = tmp->next;
            tmp->next = newNode; 
        }
        printf("Ders eklendi..\n");
    }
}

void dersKapat(DERS **head){
    DERS *tmp;
    DERS *c = (*head);
    char kapat[15];
    int count=0;

    printf("Kapatılacak dersin kodunu giriniz: ");
    scanf("%s",&kapat);

    while(c!=NULL && strcmp(c->ders_kodu,kapat)!=0){
        c = c->next;
    }
    if(c==NULL){
        count = 1;
    }
    if(count==1){
        printf("Hata!! Daha önceden açılmamış bir ders silinemez..\n");
    }
    else{
        if(strcmp((*head)->ders_kodu,kapat)==0){
            strcpy((*head)->durum,"KAPALI");
            tmp = (*head);
            (*head) = (*head)->next;
            free(tmp);
            printf("Ders silindi..\n");
        }
        else{
            tmp = (*head);
            while(tmp->next != NULL && strcmp(tmp->next->ders_kodu,kapat)!=0){
                tmp = tmp->next;
            }
            if(tmp->next != NULL){ 
                strcpy((*tmp).next->durum,"KAPALI");
                c = tmp->next;
                tmp->next = tmp->next->next;
                free(c);
                printf("Ders silindi..\n");
            }
            else{
                printf("Kapatılacak ders bulunamadi..\n");
            }
        }
    }    
}

void ogrenciEkle(OGRENCI **head){
    OGRENCI *newNode = (OGRENCI*)malloc(sizeof(OGRENCI));
    OGRENCI *tmp,*k;
    int c=0;

    k = (*head);
    newNode->next = NULL;
    newNode->prev = NULL;
    fflush(stdin);
    printf("Ogrencinin numarasını giriniz: "); gets(newNode->no);
    while(k!=NULL){
        if(strcmp(k->no,newNode->no) == 0){
            printf("Hata!! Aynı öğrenci numarasına sahip başka bir var..\n");
            c=1;
        }
        k = k->next;
    }
    if(c!=1){
        printf("Ogrencinin adını giriniz: "); gets(newNode->ad);
        printf("Ogrencinin soyadını giriniz: "); gets(newNode->soyad);
        newNode->kaydoldugu_ders_sayisi = 0;
        newNode->kaydoldugu_toplam_kredi = 0;
        if((*head) == NULL){ 
            (*head) = newNode;
            (*head)->prev = NULL;
        }
        else if(strcmp((*head)->no,newNode->no) > 0){ 
            newNode->prev = NULL;
            newNode->next = (*head);
            (*head)->prev = newNode;
            (*head) = newNode;
        }
        else{
            tmp = (*head);
            while(tmp->next != NULL && (strcmp(tmp->next->no,newNode->no) < 0)){
                tmp = tmp->next;
            }
            newNode->next = tmp->next;
            tmp->next = newNode;
            newNode->prev = tmp;
            if(newNode->next != NULL){
                newNode->next->prev = newNode;
            }
        }
        printf("Ogrenci eklendi..\n");
    }
}

void ogrenciSil(OGRENCI **head){
    OGRENCI *tmp;
    OGRENCI *c;
    char kapat[15];

    printf("Kaydını sildirmek istediginiz öğrencinin numarasını giriniz: ");
    scanf("%s",&kapat);

    if((*head)==NULL){
        printf("Hata!! Ogrenci listesi boş, silinecek öğrenci bulunamadı..\n");
    }
    else if(strcmp((*head)->no,kapat) == 0){
        if((*head)->next == NULL){
            tmp = (*head);
            free(tmp);
            (*head) = NULL;
        }
        else{
            tmp = (*head);
            (*head) = (*head)->next;
            free(tmp);  
            (*head)->prev = NULL;
        }
        printf("Ogrenci silindi..\n"); 
    }
    else{
        tmp = (*head);
        while(tmp->next != NULL && (strcmp(tmp->next->no,kapat)) != 0){
            tmp = tmp->next;
        }
        if(tmp->next != NULL){  
            c = tmp->next;
            tmp->next = tmp->next->next; 
            if(tmp->next != NULL){
                tmp->next->prev = tmp;
            }
            free(c);
            printf("Ogrenci silindi..\n");
        }
        else{
            printf("Hata!! Silinecek öğrenci bulunamadı..\n");
        }
    }
}

void dersdosyayaKaydet(DERS *head){
    FILE *fp = fopen("dersler.txt","a");
    DERS *tmp = head;

    while(tmp!=NULL){
        fprintf(fp,"%s,%s,%d,%d",tmp->ders_kodu,tmp->ders_adi,tmp->kredi,tmp->kontenjan);
        fprintf(fp,"\n");
        tmp = tmp->next;
    }
    printf("Dersler, 'dersler.txt' dosyasına kaydedildi..\n");
    fclose(fp);
}

void ogrencidosyayaKaydet(OGRENCI *head){
    FILE *fp = fopen("ogrenciler.txt","a");
    OGRENCI *tmp = head;

    while(tmp!=NULL){
        fprintf(fp,"%s,%s,%s,%d,%d",tmp->no,tmp->ad,tmp->soyad,tmp->kaydoldugu_ders_sayisi,tmp->kaydoldugu_toplam_kredi);
        fprintf(fp,"\n");
        tmp = tmp->next;
    }
    printf("Ogrenciler, 'ogrenciler.txt' dosyasına kaydedildi..\n");
    fclose(fp);
}

void ogrenci_ders_kayit(DERS **head1, OGRENCI **head2, int max_ders, int max_kredi, char *tarih, int *id){
    char ogr_no[30], ders_kodu[30];
    int sayac=0,choice,i,k=0;
    DERS *tmp1 = (*head1);
    OGRENCI *tmp2 = (*head2);
    DERS *tmp3 = (*head1);

    printf("Dersler: ");
    while(tmp1!=NULL){
        printf("%s ",tmp1->ders_kodu);
        tmp1 = tmp1->next;
    }
    printf("\nOgrenciler: ");
    while(tmp2!=NULL){
        printf("%s ",tmp2->no);
        tmp2 = tmp2->next;
    }
    tmp1 = (*head1); 
    tmp2 = (*head2);

    printf("\nOgrenci bir derse kayıt yaptırmak istiyorsa 1, bir dersi sildirmek istiyorsa 2: ");
    scanf("%d",&choice);
    
    if(choice==1){
        fflush(stdin);
        printf("Ogrenci no giriniz: "); gets(ogr_no);
        printf("Ogrenci hangi derse kaydolmak istiyor: "); gets(ders_kodu);
        while(tmp2 != NULL && strcmp(tmp2->no,ogr_no) != 0){ 
            tmp2 = tmp2->next;
        }
        if(tmp2 == NULL){
            printf("Hata!! Ogrenci listesinde olmayan bir kişi, derse kaydolamaz..\n");
            sayac = 1;
        }
        while(tmp1 != NULL && strcmp(tmp1->ders_kodu,ders_kodu) != 0){   
            tmp1 = tmp1->next;
        }
        if(tmp1 == NULL){
            printf("Hata!! Var olmayan bir derse kayıt açtırmak istediniz..\n");
            sayac = 1;
        }
        if(tmp1 != NULL && tmp2 != NULL){
            for(i=0;i<tmp1->kayitli_ogr_sayisi;i++){
                if(strcmp(tmp1->ogr_no[i],ogr_no) == 0){
                    k = 1;
                }
            }
            if(k==1){
                printf("Hata!! Ogrenci aynı dersi yalnızca 1 kere alabilir..\n");
                sayac = 1;
            }
        }
        if(sayac != 1){
            printf("Yapilan islemin tarihini giriniz: "); gets(tarih);
            DersListesineSiraliOgrenciEkle(&tmp1,&tmp2,max_ders,max_kredi,tarih,id);
        }
    }
    else if(choice==2){
        fflush(stdin);
        printf("Ogrenci no giriniz: "); gets(ogr_no);
        printf("Ogrenci hangi dersi sildirmek istiyor: "); gets(ders_kodu);
        while(tmp2 != NULL && strcmp(tmp2->no,ogr_no) != 0){ 
            tmp2 = tmp2->next;
        }
        if(tmp2 == NULL){
            printf("Hata!! Ogrenci listesinde olmayan bir kişi, bir dersi sildiremez..\n");
            sayac = 1;
        }
        while(tmp1 != NULL && strcmp(tmp1->ders_kodu,ders_kodu) != 0){   
            tmp1 = tmp1->next;
        }
        if(tmp1 == NULL){
            printf("Hata!! Ogrenci var olmayan bir dersi sildiremez..\n");
            sayac = 1;
        }
        k=1;
        while(tmp3 != NULL){
            if(strcmp(tmp3->ders_kodu,ders_kodu) == 0){
                for(i=0;i<(tmp3->kayitli_ogr_sayisi);i++){
                    if(strcmp(tmp3->ogr_no[i],ogr_no) == 0){
                        k = 0;
                    }
                }
                if((i == tmp3->kayitli_ogr_sayisi) && k==1){
                    printf("Hata!! Ogrenci 'kayitli olmadigi' bir dersi sildiremez..\n");
                    sayac = 1;
                }
            }
            tmp3 = tmp3->next;
        }
        if(sayac == 0){
            printf("Yapilan islemin tarihini giriniz: "); gets(tarih);
            DersListesindenOgrenciSil(&tmp1,&tmp2,tarih,id);
        }
    }
    else{
        printf("Hatali islem girdiniz..\n");
    }
}

void DersListesineSiraliOgrenciEkle(DERS **tmp1, OGRENCI **tmp2, int max_ders, int max_kredi, char *tarih, int *id){
    int i,j,l,k,m;
    char *t;
    t = (char*)malloc(30*sizeof(char));
    l = strlen((*tmp2)->no);
    
    if((*tmp1)->kayitli_ogr_sayisi == 0){
        (*tmp1)->ogr_no = (char**)malloc(1*sizeof(char*));
        (*tmp1)->ogr_no[0] = (char*)malloc((l+1)*sizeof(char));
        strcpy((*tmp1)->ogr_no[0],(*tmp2)->no);
        (*tmp2)->kaydoldugu_ders_sayisi = (*tmp2)->kaydoldugu_ders_sayisi + 1;
        (*tmp2)->kaydoldugu_toplam_kredi = (*tmp2)->kaydoldugu_toplam_kredi + (*tmp1)->kredi;
        (*tmp1)->kayitli_ogr_sayisi = (*tmp1)->kayitli_ogr_sayisi + 1;
        if(strcmp((*tmp1)->durum,"ACIK") == 0){
            strcpy((*tmp1)->durum,"kayitli");
        }
        printf("Kayit yapıldı..\n");
        ogrenciDersKayit_dosyayaKaydet(tmp1,tmp2,tarih,id);
    }
    else{
        if((*tmp2)->kaydoldugu_ders_sayisi < max_ders && (*tmp2)->kaydoldugu_toplam_kredi < max_kredi){
            k = (*tmp1)->kayitli_ogr_sayisi;
            if((*tmp1)->kontenjan > k){
                (*tmp1)->ogr_no = (char**)realloc((*tmp1)->ogr_no,(k+1)*sizeof(char*));
                for(i=0;i<(k);i++){
                    (*tmp1)->ogr_no[i] = (char*)realloc((*tmp1)->ogr_no[i],(l+1)*sizeof(char));
                }
                (*tmp1)->ogr_no[k] = (char*)malloc((l+1)*sizeof(char));

                strcpy((*tmp1)->ogr_no[k],(*tmp2)->no);
                for(i=0;i<k;i++){  
                    m = i;
                    for(j=i+1;j<(k+1);j++){      
                        if(strcmp((*tmp1)->ogr_no[m],(*tmp1)->ogr_no[j]) > 0){
                            m = j;
                        }
                    }
                    if(m != i){
                        strcpy(t,(*tmp1)->ogr_no[i]);
                        strcpy((*tmp1)->ogr_no[i],(*tmp1)->ogr_no[m]);
                        strcpy((*tmp1)->ogr_no[m],t);           
                    }
                }
                (*tmp2)->kaydoldugu_toplam_kredi = (*tmp2)->kaydoldugu_toplam_kredi + (*tmp1)->kredi;
                if((*tmp2)->kaydoldugu_toplam_kredi > max_kredi){
                    printf("Hata!! Ogrenci bu dersi max kredi sınırı yüzünden alamaz..\n");
                    (*tmp2)->kaydoldugu_toplam_kredi = (*tmp2)->kaydoldugu_toplam_kredi - (*tmp1)->kredi;
                }
                else{
                    (*tmp2)->kaydoldugu_ders_sayisi = (*tmp2)->kaydoldugu_ders_sayisi + 1;
                    (*tmp1)->kayitli_ogr_sayisi = (*tmp1)->kayitli_ogr_sayisi + 1;
                    if(strcmp((*tmp1)->durum,"ACIK") == 0){
                        strcpy((*tmp1)->durum,"kayitli");
                    }
                    printf("Kayit yapıldı..\n");
                    ogrenciDersKayit_dosyayaKaydet(tmp1,tmp2,tarih,id);
                }
            }
            else{
                printf("Hata!! Dersin kontenjanı dolu..\n");
            }
        }
        else{
            printf("Hata!! Ogrenci alınabilecek max dersi/krediyi almış durumda..\n");
        }
    }
}

void DersListesindenOgrenciSil(DERS **tmp1, OGRENCI **tmp2, char *tarih, int *id){
    int i,k,index=0;
    k = (*tmp1)->kayitli_ogr_sayisi;

    if(k==1){
        (*tmp1)->kayitli_ogr_sayisi = (*tmp1)->kayitli_ogr_sayisi - 1;
        (*tmp2)->kaydoldugu_ders_sayisi = (*tmp2)->kaydoldugu_ders_sayisi - 1;
        (*tmp2)->kaydoldugu_toplam_kredi = (*tmp2)->kaydoldugu_toplam_kredi - (*tmp1)->kredi;
        strcpy((*tmp1)->durum,"sildi");
        printf("Ogrenci dersi sildi..\n");
        ogrenciDersKayit_dosyayaKaydet(tmp1,tmp2,tarih,id);
        free((*tmp1)->ogr_no[0]);
    }
    else{
        while(strcmp((*tmp1)->ogr_no[index],(*tmp2)->no) != 0){
            index++;
        }
        for(i=index;i<(k-1);i++){
            (*tmp1)->ogr_no[i] = (*tmp1)->ogr_no[i+1];
        }
        (*tmp1)->kayitli_ogr_sayisi = (*tmp1)->kayitli_ogr_sayisi - 1;
        (*tmp2)->kaydoldugu_ders_sayisi = (*tmp2)->kaydoldugu_ders_sayisi - 1;
        (*tmp2)->kaydoldugu_toplam_kredi = (*tmp2)->kaydoldugu_toplam_kredi - (*tmp1)->kredi;
        strcpy((*tmp1)->durum,"sildi");
        printf("Ogrenci dersi sildi..\n");
        ogrenciDersKayit_dosyayaKaydet(tmp1,tmp2,tarih,id);
        free((*tmp1)->ogr_no[k-1]);
    }
}

void ogrenciDersKayit_dosyayaKaydet(DERS **tmp1, OGRENCI **tmp2, char *tarih, int *id){
    FILE *fp = fopen("OgrenciDersKayit.txt","a");
    DERS *a = (*tmp1);
    OGRENCI *b = (*tmp2);

    if(a!=NULL && b!=NULL){
        fprintf(fp,"%d,%s,%s,%s,%s",(*id),a->ders_kodu,b->no,tarih,a->durum);
        fprintf(fp,"\n");
        (*id) = (*id) + 1;
    }
    printf("Kayıt 'OgrenciDersKayit' dosyasına kaydedildi..\n");
    fclose(fp);
}

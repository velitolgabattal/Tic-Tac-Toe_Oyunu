#include <stdio.h><conio.h>

struct{
    int kazanma; int kaybetme; int beraberlik;
    }X,O;

void istatistikTutucu(){
    FILE *pDosya;
pDosya=fopen("istatistik.txt","w");
fprintf(pDosya,"%d %d\n",X.kazanma,O.kazanma);
fprintf(pDosya,"%d %d\n",X.kaybetme,O.kaybetme);
fprintf(pDosya,"%d %d",X.beraberlik,O.beraberlik);
fclose(pDosya);
}

int main(){
    int Box[10]={0,0,0,0,0,0,0,0,0,0},konum,sira=1,tur=0,i;
    char S[3]={' ','X','O'},secim;
    int kazanma[8][3] = {{1,2,3},{4,5,6},{7,8,9},{1,4,7},{2,5,8},{3,6,9},{1,5,9},{3,5,7}};
    FILE *pDosya;
        pDosya=fopen("istatistik.txt","r");
    if (pDosya==NULL){
            fclose(pDosya);
    pDosya=fopen("istatistik.txt","w");
    fprintf(pDosya,"%d %d\n%d %d\n%d %d\n",0,0,0,0,0,0);
    fclose(pDosya);
    pDosya=fopen("istatistik.txt","r");
}
fscanf(pDosya,"%d %d\n",&X.kazanma,&O.kazanma);
fscanf(pDosya,"%d %d\n",&X.kaybetme,&O.kaybetme);
fscanf(pDosya,"%d %d",&X.beraberlik,&O.beraberlik);
fclose(pDosya);
    printf("XOX oyununa hos geldiniz.\nOyunun temel mantigi 3 adet kendi sembolunuzu (dikey, yatay veya capraz sekilde) yan yana getirmektir.\n\n\n");

printf("\t\t     |     |     \n");
printf("\t\t  1  |  2  |  3  \n");
printf("\t\t_____|_____|_____\n");
printf("\t\t     |     |     \n");
printf("\t\t  4  |  5  |  6  \n");
printf("\t\t_____|_____|_____\n");
printf("\t\t     |     |     \n");
printf("\t\t  7  |  8  |  9  \n");
printf("\t\t     |     |     \n");
printf("\nKutu numaralari yukaridaki gibidir.\nSirasi gelen oyuncu sembolunu yerlestirmek istedigi kutu numarasini tuslayarak sembolu yerlestirir.\n");
while(1){
printf("\nLutfen yapmak istediginiz islemi secin.\n");
printf("1.Istatistik Goruntuleme\n");
printf("2.Yeni oyuna baslama\n");
secim=getch();
if(secim=='1'){
printf("\t\tX\tO\n");
printf("\t\t-\t-\n");
printf("Kazanma:\t%d\t%d\n",X.kazanma,X.kaybetme);
printf("Kaybetme:\t%d\t%d\n",O.kazanma,O.kaybetme);
printf("Beraberlik:\t%d\t%d",X.beraberlik,O.beraberlik);
}
if(secim=='2')
    break;
}
    while(1){

printf("\n\n\n");
printf("\t\t     |     |     \n");
printf("\t\t  %c  |  %c  |  %c  \n",S[Box[1]],S[Box[2]],S[Box[3]]);
printf("\t\t_____|_____|_____\n");
printf("\t\t     |     |     \n");
printf("\t\t  %c  |  %c  |  %c  \n",S[Box[4]],S[Box[5]],S[Box[6]]);
printf("\t\t_____|_____|_____\n");
printf("\t\t     |     |     \n");
printf("\t\t  %c  |  %c  |  %c  \n",S[Box[7]],S[Box[8]],S[Box[9]]);
printf("\t\t     |     |     \n");

if(sira>5){

for(i=0;i<8;++i) {
        if(Box[kazanma[i][0]] != 0 &&
           Box[kazanma[i][0]] == Box[kazanma[i][1]] &&
           Box[kazanma[i][0]] == Box[kazanma[i][2]])
           {
            printf("%c Kazandi\n",S[Box[kazanma[i][0]]]);
            if(S[Box[kazanma[i][0]]]=='X'){
                X.kazanma++;
                O.kaybetme++;
            }
             if(S[Box[kazanma[i][0]]]=='O'){
                O.kazanma++;
                X.kaybetme++;
            }
            istatistikTutucu();
            return 0;}
    }

}

if(sira==10){
        printf("berabere");
        O.beraberlik++;
        X.beraberlik++;
        istatistikTutucu();
        return 0;}

 if(sira%2==0)
printf("O oynuyor. Lutfen yerlesmek istediginiz kutuyu secin:");
 if(sira%2==1)
printf("X oynuyor. Lutfen yerlesmek istediginiz kutuyu secin:");

scanf("%d",&konum);

while(Box[konum]!=0||!(konum>=1&&konum<=9))
{
    if(Box[konum]!=0 &&(konum>=1&&konum<=9))
        printf("Secilen kutu dolu. Lutfen tekrar secin:");

    if(!(konum>=1&&konum<=9))
        {
        if(konum>9)
            printf("Secilen sayi cok buyuk. Lutfen tekrar secin:");
        if(konum<1)
            printf("Secilen sayi cok kucuk. Lutfen tekrar secin:");
        }

    scanf("%d",&konum);

}
            if(sira%2==1)
                Box[konum]=1;

            if(sira%2==0)
                Box[konum]=2;
sira++;
}}

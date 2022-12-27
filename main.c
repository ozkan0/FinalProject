#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

int main() {
	int giris=333,cikis=0;
	int girisKullanici=0, paketAktif=1;
	//secimler secim dizisinde birlestirildi
	//ana menu secimi, alt menu secimi
	int secim[2];
	//kalan kullanimlar kalan dizisinde birlestirildi
	//kalan bakiye, internet, dakika, sms
	int kalan[2][3]={{48},{4631,366,187}};
	//internet,dakika,sms,ucret
	int voPaket[3][4]={{10,500,100,65},{20,600,150,80},{30,800,200,100}};
	
	scanf("%d",&girisKullanici);
	char hatamsj[100];
	strcpy(hatamsj,"Hatali tuslama yaptiniz. Ana menuye yonlendiriliyorsunuz..\n\n");
	
	void voBuyuk()
	{
		printf("1) .:Buyuk Paket:. \n Internet: %dGB\n Dakika: %ddk\n SMS: %dsms\n Ucret: %dTL\n\n",voPaket[2][0],voPaket[2][1],voPaket[2][2],voPaket[2][3]);
	}
	void voOrta()
	{
		printf("2) .:Orta Paket:. \n Internet: %dGB\n Dakika: %ddk\n SMS: %dsms\n Ucret: %dTL\n\n",voPaket[1][0],voPaket[1][1],voPaket[1][2],voPaket[1][3]);
	}
	void voKucuk()
	{
		printf("3) .:Kucuk Paket:. \n Internet: %dGB\n Dakika: %ddk\n SMS: %dsms\n Ucret: %dTL\n\n",voPaket[0][0],voPaket[0][1],voPaket[0][2],voPaket[0][3]);
	}
	
	if(giris==girisKullanici){
	do{
  
		printf("\n.::ANA MENU::.\n1) Bakiyeni sorgula \n2) Paket kalan kullanimlari sorgula \n3) Paket iptal ve satin alim islemlerine git \n4) TL ve paket kullanim detaylarini iste \n5) Cik\n");
		scanf("%d",&secim[0]);
		
		switch(secim[0]){
			case 1 : printf("Kalan bakiyeniz: %dTL\n",kalan[0][0]);break;
			case 2 : printf("Kalan haklariniz:\nInternet: %dmb\nKonusma: %d\nSMS: %d\n",kalan[1][0],kalan[1][1],kalan[1][2]);break;
			case 3 : printf("1)Paket iptal\n2)Paket satin al\n"); scanf("%d",&secim[1]); if(secim[1]==1){paketAktif=0; printf("Paketiniz iptal edilmistir. \n");break;}else if(secim[1]==2){printf("Satin alinabilecek paketler: \n"); voBuyuk(); voOrta(); voKucuk();break;}else{printf("Hatali tuslama");}break;
			case 4 : printf("1)TL kullanim detayi\n2)Paket kullanim detayi\n");scanf("%d",&secim[1]);if(secim[1]==1){printf("\nTL kullanim detayiniz: \n\n");
			
			//tl kullanim kayitlarini yazdiriyor
			    FILE *logtl;
				char c;
			    logtl = fopen("logstl.txt", "r");
			    
				c = fgetc(logtl);
			    while (c != EOF)
			    {
			        printf ("%c", c);
			        c = fgetc(logtl);
			    }
			    printf("\n");
    			fclose(logtl);
			
			break;}else if(secim[1]==2){printf("\nPaket kullanim detayiniz: \n\n");
			
			//paket kullanim kayitlarini yazdiriyor
			    FILE *logp;
				char c;
			    logp = fopen("logspaket.txt", "r");
			    
				c = fgetc(logp);
			    while (c != EOF)
			    {
			        printf ("%c", c);
			        c = fgetc(logp);
			    }
			    printf("\n");
			    
    			fclose(logp);
			
			break;}else{printf("%s",hatamsj);}break;
			
			case 5 : cikis=1;break;
			default : printf("%s",hatamsj);break;
		}
		}while(cikis==0);
	}
	return 0;
}

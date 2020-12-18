#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int main() {
    char *morsChars[36][2]={
        {"A",".-"},
        {"B","-..."},
        {"C","-.-."},
        {"D","-.."},
        {"E","."},
        {"F","..-."},
        {"G","--."},
        {"H","...."},
        {"I",".."},
        {"J",".---"},
        {"K","-.-"},
        {"L",".-.."},
        {"M","--"},
        {"N","-."},
        {"O","---"},
        {"P",".--."},
        {"Q","--.-"},
        {"R",".-."},
        {"S","..."},
        {"T","-"},
        {"U","..-"},
     {"V","...-"},
     {"W",".--"},
     {"X","-..-"},
     {"Y","-.--"},
     {"Z","--.."},
     {"0","-----"},
     {"1",".----"},
     {"2","..---"},
     {"3","...--"},
     {"4","....-"},
     {"5","....."},
     {"6","-...."},
     {"7","--..."},
     {"8","---.."},
     {"9","----."},
    }; // Mors karakterleri ve ona karþýlýk gelen latin harfinin listesi.
    
    char *gelenVeri, // Kullanýcýnýn girdiði karakterleri tutacak.
	*islem; // Ýþlem tipini tutacak.
    int i=0,j=0,k=0; // Döngü deðiþkenleri tanýmlandý.
    char kelime[1000][100]={0}; // Kullanýcýnýn girdiði dönüþtürülmüþ mors kelimelerini tutacak dizi.
    
    gelenVeri=calloc(1000,sizeof(char)); // Kullanýcýnýn girdiði deðiþkenleri tutacak deðiþkene daha sonra temizlemek amacýyla 1000 karakterlik alan tahsis edildi.
    
	islem=calloc(1,sizeof(char)); // Kullanýcý tarafýndan girilecek iþlem tipini tutacak deðiþkene sonradan silinmek üzere 1 karakterlik alan tahsis edildi.
    
    //Kullanýcýyý yönlendirmek için oluþturulan ekran çýktýlarý.
    printf("Dosya uzerinden okumak icin 1'e basin.");
    printf("\nKlavyeden girmek icin 2'ye basin.");
    printf("\n\nLutfen islem tipini seciniz: ");
    
    gets(islem); // Kullanýcýdan veri alýyor.
    
    if(!strcmp(islem,"1"))
    {
    	FILE * filePointer;  // Açýlacak dosyaya ait içeriði tutacak deðiþken tanýmlandý.
    	char dataToBeRead[2], // Dosya içeriðini okudukça ilgili karakteri tutacak deðiþken tanýmlandý.
		*dosyaYolu; // Kullanýcý tarafýndan açýlmak istenen dosyaya ait yolun tutulacaðý deðiþken tanýmlandý.
		dosyaYolu=calloc(100,sizeof(char)); // Kullanýcý tarafýndan girilecek dosya yoluna ait deðiþkene sonradan silinmek üzere 100 karakterlik alan tahsis edildi.
		printf("\nDosya yolunu giriniz: ");
		gets(dosyaYolu); // Kullanýcýdan içinde mors kodlarý olan txt dosyasýnýn yolu alýnýyor.
		printf("\n");
		filePointer = fopen(dosyaYolu, "r"); // Kullanýcýnýn girdiði yoldaki dosya açýlýyor.
		free(dosyaYolu); // Dosya yolu için tahsis edilen 100 karakterlik alan temizlendi. 
		
		if(filePointer==NULL) // Eðer ki kullanýcý hatalý veya olmayan bir dosya açmaya çalýþýrsa burada yakalanacak.
			printf("Dosya acilirken bir hata olustu.");
		
		
		while( fgets ( dataToBeRead, 2, filePointer ) != NULL ) // Dosya açýldýðý takdirde içerisindeki veriler bitene kadar okunacak.
        {
			if(*dataToBeRead==' ') // Kullanýcýnýn yeni bir mors kelimesine baþladýðýný belirten durum.
    		{
        		kelime[j][k]='\0'; // Önceki mors kelimesinin tamamlandýðýný belirtiyor.
    			k=0; // Sonraki kelimeyi yazmaya baþlamak için imleç baþa getiriliyor.
    			j++; // Sonraki kelimeyi tutmak için dizinin sonraki indisine geçiliyor.
			}
			else // Kullanýcý yeni kelimeye geçmediði takdirde, mevcut kelimeyi tamamlamak için çalýþacak kýsým.
			{
				kelime[j][k]=*dataToBeRead; // Kullanýcýdan alýnan karakterler dizinin bir satýrýnda birleþtirilerek bir mors kelimesi haline getiriliyor.
				k++; // Sonraki karakteri basmak için imleç bir sað sütuna kaydýrýlýyor.
			}
		}
		
		int len=j; // Döngüde kaç adet mors kelimesi varsa burada adet sayýsýný alýyorum. 
		
		for(j=0;j<=len;j++) // Gelen verideki mors kelime sayýsý kadar dönecek.
		{
			if(j!=0 && kelime[j-1][0]=='\0')
				printf(" ");
				
			for(i=0;i<36;i++) // Baþlangýçta kaydettiðimiz tüm mors kelimeleri kadar dönecek.
			{
				if(!strcmp(kelime[j],morsChars[i][1])) // Gelen verideki mors kelimesi ile baþlangýçta tanýmlanan mors kelimeleri eþleþtiriliyor.
				{
					printf(morsChars[i][0]); // Gelen veri ile mors baþlangýçta tanýmlanan kelime eþleþtiði takdirde ilgili kelimeye karþýlýk gelen karakter ekrana basýlýyor.
				}
			}
		}	
		fclose(filePointer);
	}
    else if(!strcmp(islem,"2"))
	{
		printf("\n\nLutfen cevrilecek kelimeyi giriniz:");
    	gets(gelenVeri); // Kullanýcýdan veri alýyor.
    	
		while(gelenVeri[i]!='\0') // Gelen dizinin içinden veri olan kýsým okunuyor.
    	{
    		if(gelenVeri[i]==' ') // Kullanýcýnýn yeni bir mors kelimesine baþladýðýný belirten durum.
    		{
        		kelime[j][k]='\0'; // Önceki mors kelimesinin tamamlandýðýný belirtiyor.
    			k=0; // Sonraki kelimeyi yazmaya baþlamak için imleç baþa getiriliyor.
    			j++; // Sonraki kelimeyi tutmak için dizinin sonraki indisine geçiliyor.
			}
			else // Kullanýcý yeni kelimeye geçmediði takdirde, mevcut kelimeyi tamamlamak için çalýþacak kýsým.
			{
				kelime[j][k]=gelenVeri[i]; // Kullanýcýdan alýnan karakterler dizinin bir satýrýnda birleþtirilerek bir mors kelimesi haline getiriliyor.
				k++; // Sonraki karakteri basmak için imleç bir sað sütuna kaydýrýlýyor.
			}
			i++; // Sonraki mors kelimesini okumak için döngü 1 adým ilerliyor.
		}
		
		
		free(gelenVeri); // gelen veriyi tutmak için tahsis edilen 1000 karakterlik alan temizlendi.
	
		int len=j; // Döngüde kaç adet mors kelimesi varsa burada adet sayýsýný alýyorum. 
		
		for(j=0;j<=len;j++) // Gelen verideki mors kelime sayýsý kadar dönecek.
		{
			for(i=0;i<36;i++) // Baþlangýçta kaydettiðimiz tüm mors kelimeleri kadar dönecek.
			{
				if(!strcmp(kelime[j],morsChars[i][1])) // Gelen verideki mors kelimesi ile baþlangýçta tanýmlanan mors kelimeleri eþleþtiriliyor.
				{
					printf(morsChars[i][0]); // Gelen veri ile mors baþlangýçta tanýmlanan kelime eþleþtiði takdirde ilgili kelimeye karþýlýk gelen karakter ekrana basýlýyor.
				}
			}
			if(kelime[j][0]=='\0') // Eðer dizinin ilgili indisinde bir boþluk var ise 1 karakter boþluk býrakýlýyor.
			printf(" ");
		}	
	}
	else
		printf("Hatali islem numarasi girdiniz.");
	
    
    
    free(islem); // iþlemi tutmak için tahsis edilen 1 karakterlik alan temizlendi.
    return 0;
}




  

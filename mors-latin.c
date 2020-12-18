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
    }; // Mors karakterleri ve ona kar��l�k gelen latin harfinin listesi.
    
    char *gelenVeri, // Kullan�c�n�n girdi�i karakterleri tutacak.
	*islem; // ��lem tipini tutacak.
    int i=0,j=0,k=0; // D�ng� de�i�kenleri tan�mland�.
    char kelime[1000][100]={0}; // Kullan�c�n�n girdi�i d�n��t�r�lm�� mors kelimelerini tutacak dizi.
    
    gelenVeri=calloc(1000,sizeof(char)); // Kullan�c�n�n girdi�i de�i�kenleri tutacak de�i�kene daha sonra temizlemek amac�yla 1000 karakterlik alan tahsis edildi.
    
	islem=calloc(1,sizeof(char)); // Kullan�c� taraf�ndan girilecek i�lem tipini tutacak de�i�kene sonradan silinmek �zere 1 karakterlik alan tahsis edildi.
    
    //Kullan�c�y� y�nlendirmek i�in olu�turulan ekran ��kt�lar�.
    printf("Dosya uzerinden okumak icin 1'e basin.");
    printf("\nKlavyeden girmek icin 2'ye basin.");
    printf("\n\nLutfen islem tipini seciniz: ");
    
    gets(islem); // Kullan�c�dan veri al�yor.
    
    if(!strcmp(islem,"1"))
    {
    	FILE * filePointer;  // A��lacak dosyaya ait i�eri�i tutacak de�i�ken tan�mland�.
    	char dataToBeRead[2], // Dosya i�eri�ini okuduk�a ilgili karakteri tutacak de�i�ken tan�mland�.
		*dosyaYolu; // Kullan�c� taraf�ndan a��lmak istenen dosyaya ait yolun tutulaca�� de�i�ken tan�mland�.
		dosyaYolu=calloc(100,sizeof(char)); // Kullan�c� taraf�ndan girilecek dosya yoluna ait de�i�kene sonradan silinmek �zere 100 karakterlik alan tahsis edildi.
		printf("\nDosya yolunu giriniz: ");
		gets(dosyaYolu); // Kullan�c�dan i�inde mors kodlar� olan txt dosyas�n�n yolu al�n�yor.
		printf("\n");
		filePointer = fopen(dosyaYolu, "r"); // Kullan�c�n�n girdi�i yoldaki dosya a��l�yor.
		free(dosyaYolu); // Dosya yolu i�in tahsis edilen 100 karakterlik alan temizlendi. 
		
		if(filePointer==NULL) // E�er ki kullan�c� hatal� veya olmayan bir dosya a�maya �al���rsa burada yakalanacak.
			printf("Dosya acilirken bir hata olustu.");
		
		
		while( fgets ( dataToBeRead, 2, filePointer ) != NULL ) // Dosya a��ld��� takdirde i�erisindeki veriler bitene kadar okunacak.
        {
			if(*dataToBeRead==' ') // Kullan�c�n�n yeni bir mors kelimesine ba�lad���n� belirten durum.
    		{
        		kelime[j][k]='\0'; // �nceki mors kelimesinin tamamland���n� belirtiyor.
    			k=0; // Sonraki kelimeyi yazmaya ba�lamak i�in imle� ba�a getiriliyor.
    			j++; // Sonraki kelimeyi tutmak i�in dizinin sonraki indisine ge�iliyor.
			}
			else // Kullan�c� yeni kelimeye ge�medi�i takdirde, mevcut kelimeyi tamamlamak i�in �al��acak k�s�m.
			{
				kelime[j][k]=*dataToBeRead; // Kullan�c�dan al�nan karakterler dizinin bir sat�r�nda birle�tirilerek bir mors kelimesi haline getiriliyor.
				k++; // Sonraki karakteri basmak i�in imle� bir sa� s�tuna kayd�r�l�yor.
			}
		}
		
		int len=j; // D�ng�de ka� adet mors kelimesi varsa burada adet say�s�n� al�yorum. 
		
		for(j=0;j<=len;j++) // Gelen verideki mors kelime say�s� kadar d�necek.
		{
			if(j!=0 && kelime[j-1][0]=='\0')
				printf(" ");
				
			for(i=0;i<36;i++) // Ba�lang��ta kaydetti�imiz t�m mors kelimeleri kadar d�necek.
			{
				if(!strcmp(kelime[j],morsChars[i][1])) // Gelen verideki mors kelimesi ile ba�lang��ta tan�mlanan mors kelimeleri e�le�tiriliyor.
				{
					printf(morsChars[i][0]); // Gelen veri ile mors ba�lang��ta tan�mlanan kelime e�le�ti�i takdirde ilgili kelimeye kar��l�k gelen karakter ekrana bas�l�yor.
				}
			}
		}	
		fclose(filePointer);
	}
    else if(!strcmp(islem,"2"))
	{
		printf("\n\nLutfen cevrilecek kelimeyi giriniz:");
    	gets(gelenVeri); // Kullan�c�dan veri al�yor.
    	
		while(gelenVeri[i]!='\0') // Gelen dizinin i�inden veri olan k�s�m okunuyor.
    	{
    		if(gelenVeri[i]==' ') // Kullan�c�n�n yeni bir mors kelimesine ba�lad���n� belirten durum.
    		{
        		kelime[j][k]='\0'; // �nceki mors kelimesinin tamamland���n� belirtiyor.
    			k=0; // Sonraki kelimeyi yazmaya ba�lamak i�in imle� ba�a getiriliyor.
    			j++; // Sonraki kelimeyi tutmak i�in dizinin sonraki indisine ge�iliyor.
			}
			else // Kullan�c� yeni kelimeye ge�medi�i takdirde, mevcut kelimeyi tamamlamak i�in �al��acak k�s�m.
			{
				kelime[j][k]=gelenVeri[i]; // Kullan�c�dan al�nan karakterler dizinin bir sat�r�nda birle�tirilerek bir mors kelimesi haline getiriliyor.
				k++; // Sonraki karakteri basmak i�in imle� bir sa� s�tuna kayd�r�l�yor.
			}
			i++; // Sonraki mors kelimesini okumak i�in d�ng� 1 ad�m ilerliyor.
		}
		
		
		free(gelenVeri); // gelen veriyi tutmak i�in tahsis edilen 1000 karakterlik alan temizlendi.
	
		int len=j; // D�ng�de ka� adet mors kelimesi varsa burada adet say�s�n� al�yorum. 
		
		for(j=0;j<=len;j++) // Gelen verideki mors kelime say�s� kadar d�necek.
		{
			for(i=0;i<36;i++) // Ba�lang��ta kaydetti�imiz t�m mors kelimeleri kadar d�necek.
			{
				if(!strcmp(kelime[j],morsChars[i][1])) // Gelen verideki mors kelimesi ile ba�lang��ta tan�mlanan mors kelimeleri e�le�tiriliyor.
				{
					printf(morsChars[i][0]); // Gelen veri ile mors ba�lang��ta tan�mlanan kelime e�le�ti�i takdirde ilgili kelimeye kar��l�k gelen karakter ekrana bas�l�yor.
				}
			}
			if(kelime[j][0]=='\0') // E�er dizinin ilgili indisinde bir bo�luk var ise 1 karakter bo�luk b�rak�l�yor.
			printf(" ");
		}	
	}
	else
		printf("Hatali islem numarasi girdiniz.");
	
    
    
    free(islem); // i�lemi tutmak i�in tahsis edilen 1 karakterlik alan temizlendi.
    return 0;
}




  

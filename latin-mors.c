#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

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
    }; // Mors kelimelerini ve karþýlýk gelen karakterleri tutan dizi tanýmlandý.
    
    char gelenKarakter='\0', // Okunan her bir karakteri tutacak deðiþken tanýmlandý.
	morsKarakter='\0'; // Mors kelimelerinin tutulduðu diziden, ilgili kelimeye karþýlýk gelen karakteri tutacak deðiþken tanýmlandý. 
	
	int j=0; // Döngü deðiþkeni tanýmlandý.
	
	
int main() {
	
    int i=0; // Döngü deðiþkeni tanýmlandý.
    
    char *gelenVeri, // Kullanýcýnýn girdiði karakterleri tutacak deðiþken tanýmlandý.
	*islem; // Kullanýcý tarafýndan girilecek iþlem tipini tutacak deðiþken tanýmlandý.
    
	gelenVeri=calloc(1000,sizeof(char)); // Kullanýcýnýn girdiði deðiþkenleri tutacak deðiþkene daha sonra temizlemek amacýyla 1000 karakterlik alan tahsis edildi.
    
	islem=calloc(1,sizeof(char)); // Kullanýcý tarafýndan girilecek iþlem tipini tutacak deðiþkene sonradan silinmek üzere 1 karakterlik alan tahsis edildi.
    
	//Kullanýcýyý yönlendirmek için oluþturulan ekran çýktýlarý.
    printf("Dosya uzerinden okumak icin 1'e basin.");
    printf("\nKlavyeden girmek icin 2'ye basin.");
    printf("\n\nLutfen islem tipini seciniz: ");
    
    gets(islem); // Kullanýcýdan yapmak istediði iþleme ait veri alýnýyor.
    
    if(!strcmp(islem,"1")) // Alýnan veri ile ilgili iþlem karþýlaþtýrýlýyor.
    {
    	FILE * filePointer;  // Açýlacak dosyaya ait içeriði tutacak deðiþken tanýmlandý.
    	char dataToBeRead[2], // Dosya içeriðini okudukça ilgili karakteri tutacak deðiþken tanýmlandý.
		*dosyaYolu; // Kullanýcý tarafýndan açýlmak istenen dosyaya ait yolun tutulacaðý deðiþken tanýmlandý.
		dosyaYolu=calloc(100,sizeof(char)); // Kullanýcý tarafýndan girilecek dosya yoluna ait deðiþkene sonradan silinmek üzere 100 karakterlik alan tahsis edildi.
		printf("\nDosya yolunu giriniz: ");
		gets(dosyaYolu); // Kullanýcýdan içinde latin harflerinin olduðu txt dosyasýnýn yolu alýnýyor.
		printf("\n");
		filePointer = fopen(dosyaYolu, "r"); // Kullanýcýnýn girdiði yoldaki dosya açýlýyor.
		free(dosyaYolu); // Dosya yolu için tahsis edilen 100 karakterlik alan temizlendi. 
		
		if(filePointer==NULL) // Eðer ki kullanýcý hatalý veya olmayan bir dosya açmaya çalýþýrsa burada yakalanacak.
			printf("Dosya acilirken bir hata olustu.");
		
		while( fgets ( dataToBeRead, 2, filePointer ) != NULL ) // Dosya açýldýðý takdirde içerisindeki veriler bitene kadar okunacak.
        	harfBas(*dataToBeRead); // Dosyadan okunan karakterler fonksiyona gönderiliyor.
        
		fclose(filePointer); // Okuma iþlemi tamamlanýnca dosya kapatýlýyor.
		
	}
	else if(!strcmp(islem,"2")) // Alýnan veri ile ilgili iþlem karþýlaþtýrýlýyor.
	{
		printf("\n\nLutfen cevrilecek kelimeyi giriniz:");
    	gets(gelenVeri); // Kullanýcýdan veri alýyor.
		
		printf("\n");
		while(gelenVeri[i]!='\0') // Gelen dizinin içinden veri olan kýsým okunuyor.
    	{
			harfBas(gelenVeri[i]); // Kullanýcýnýn girdiði her bir karakter sýrayla fonksiyona gönderiliyor.
			i++; // Sonraki mors kelimesini okumak için döngü 1 adým ilerliyor.
		}
		free(gelenVeri); // gelen veriyi tutmak için tahsis edilen 1000 karakterlik alan temizlendi.
	}
	else // Alýnan veri iþlemlere uymazsa hatalý giriþ için uyarý veriliyor.
		printf("Hatali islem numarasi girdiniz.");
		
    return 0;
}

harfBas(int gelen) // Tekrar edecek ayný iþlemleri bir fonksiyon içerisine alarak koddan tasarruf saðlandý.
{
	gelenKarakter=toupper(gelen);//Klavyeden girilen karakter okunuyor. Eðer küçük harf ise büyük harfe çevriliyor.
	for(j=0;j<36;j++) // Baþlangýçta kaydettiðimiz tüm mors kelimeleri kadar dönecek.
	{
		morsKarakter= *morsChars[j][0]; //Mors kelimelerinin tutulduðu diziden döngü durumuna göre ilgili kelimeye karþýlýk gelen karakter çekiliyor.
    	if(gelenKarakter==morsKarakter)// Mors kelimelerinin tutulduðu diziden çekilen karakter, kullanýcýnýn girdiði karakter ile karþýlaþtýrýlýyor.
			printf(morsChars[j][1]); // Eðer ki veriler eþleþirse, mors kelimelerinin tutulduðu diziden ilgili kelime ekrana basýlýyor.
	}
	printf(" "); // Þimdiki kelime ile sonrakini ayýrmak için arada bir boþluk býrakýlýyor.
}


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
    }; // Mors kelimelerini ve kar��l�k gelen karakterleri tutan dizi tan�mland�.
    
    char gelenKarakter='\0', // Okunan her bir karakteri tutacak de�i�ken tan�mland�.
	morsKarakter='\0'; // Mors kelimelerinin tutuldu�u diziden, ilgili kelimeye kar��l�k gelen karakteri tutacak de�i�ken tan�mland�. 
	
	int j=0; // D�ng� de�i�keni tan�mland�.
	
	
int main() {
	
    int i=0; // D�ng� de�i�keni tan�mland�.
    
    char *gelenVeri, // Kullan�c�n�n girdi�i karakterleri tutacak de�i�ken tan�mland�.
	*islem; // Kullan�c� taraf�ndan girilecek i�lem tipini tutacak de�i�ken tan�mland�.
    
	gelenVeri=calloc(1000,sizeof(char)); // Kullan�c�n�n girdi�i de�i�kenleri tutacak de�i�kene daha sonra temizlemek amac�yla 1000 karakterlik alan tahsis edildi.
    
	islem=calloc(1,sizeof(char)); // Kullan�c� taraf�ndan girilecek i�lem tipini tutacak de�i�kene sonradan silinmek �zere 1 karakterlik alan tahsis edildi.
    
	//Kullan�c�y� y�nlendirmek i�in olu�turulan ekran ��kt�lar�.
    printf("Dosya uzerinden okumak icin 1'e basin.");
    printf("\nKlavyeden girmek icin 2'ye basin.");
    printf("\n\nLutfen islem tipini seciniz: ");
    
    gets(islem); // Kullan�c�dan yapmak istedi�i i�leme ait veri al�n�yor.
    
    if(!strcmp(islem,"1")) // Al�nan veri ile ilgili i�lem kar��la�t�r�l�yor.
    {
    	FILE * filePointer;  // A��lacak dosyaya ait i�eri�i tutacak de�i�ken tan�mland�.
    	char dataToBeRead[2], // Dosya i�eri�ini okuduk�a ilgili karakteri tutacak de�i�ken tan�mland�.
		*dosyaYolu; // Kullan�c� taraf�ndan a��lmak istenen dosyaya ait yolun tutulaca�� de�i�ken tan�mland�.
		dosyaYolu=calloc(100,sizeof(char)); // Kullan�c� taraf�ndan girilecek dosya yoluna ait de�i�kene sonradan silinmek �zere 100 karakterlik alan tahsis edildi.
		printf("\nDosya yolunu giriniz: ");
		gets(dosyaYolu); // Kullan�c�dan i�inde latin harflerinin oldu�u txt dosyas�n�n yolu al�n�yor.
		printf("\n");
		filePointer = fopen(dosyaYolu, "r"); // Kullan�c�n�n girdi�i yoldaki dosya a��l�yor.
		free(dosyaYolu); // Dosya yolu i�in tahsis edilen 100 karakterlik alan temizlendi. 
		
		if(filePointer==NULL) // E�er ki kullan�c� hatal� veya olmayan bir dosya a�maya �al���rsa burada yakalanacak.
			printf("Dosya acilirken bir hata olustu.");
		
		while( fgets ( dataToBeRead, 2, filePointer ) != NULL ) // Dosya a��ld��� takdirde i�erisindeki veriler bitene kadar okunacak.
        	harfBas(*dataToBeRead); // Dosyadan okunan karakterler fonksiyona g�nderiliyor.
        
		fclose(filePointer); // Okuma i�lemi tamamlan�nca dosya kapat�l�yor.
		
	}
	else if(!strcmp(islem,"2")) // Al�nan veri ile ilgili i�lem kar��la�t�r�l�yor.
	{
		printf("\n\nLutfen cevrilecek kelimeyi giriniz:");
    	gets(gelenVeri); // Kullan�c�dan veri al�yor.
		
		printf("\n");
		while(gelenVeri[i]!='\0') // Gelen dizinin i�inden veri olan k�s�m okunuyor.
    	{
			harfBas(gelenVeri[i]); // Kullan�c�n�n girdi�i her bir karakter s�rayla fonksiyona g�nderiliyor.
			i++; // Sonraki mors kelimesini okumak i�in d�ng� 1 ad�m ilerliyor.
		}
		free(gelenVeri); // gelen veriyi tutmak i�in tahsis edilen 1000 karakterlik alan temizlendi.
	}
	else // Al�nan veri i�lemlere uymazsa hatal� giri� i�in uyar� veriliyor.
		printf("Hatali islem numarasi girdiniz.");
		
    return 0;
}

harfBas(int gelen) // Tekrar edecek ayn� i�lemleri bir fonksiyon i�erisine alarak koddan tasarruf sa�land�.
{
	gelenKarakter=toupper(gelen);//Klavyeden girilen karakter okunuyor. E�er k���k harf ise b�y�k harfe �evriliyor.
	for(j=0;j<36;j++) // Ba�lang��ta kaydetti�imiz t�m mors kelimeleri kadar d�necek.
	{
		morsKarakter= *morsChars[j][0]; //Mors kelimelerinin tutuldu�u diziden d�ng� durumuna g�re ilgili kelimeye kar��l�k gelen karakter �ekiliyor.
    	if(gelenKarakter==morsKarakter)// Mors kelimelerinin tutuldu�u diziden �ekilen karakter, kullan�c�n�n girdi�i karakter ile kar��la�t�r�l�yor.
			printf(morsChars[j][1]); // E�er ki veriler e�le�irse, mors kelimelerinin tutuldu�u diziden ilgili kelime ekrana bas�l�yor.
	}
	printf(" "); // �imdiki kelime ile sonrakini ay�rmak i�in arada bir bo�luk b�rak�l�yor.
}


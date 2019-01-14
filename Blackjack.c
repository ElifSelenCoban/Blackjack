#include<stdio.h>
#include<stdlib.h>
#include<time.h>



main()
{
	int kazanma = 0, kaybetme = 0, beraberlik = 0;
	while (1) {
		char soru, bitis,assoru;
		int x, masatoplam, oyuncutoplam;
		int random[52], deger[52];
		char card[52][12] = {
			"Kupa As","Kupa iki","Kupa uc","Kupa Dort","Kupa Bes","Kupa Alti","Kupa Yedi","Kupa Sekiz","Kupa Dokuz","Kupa On","Kupa J","Kupa Q","Kupa K",
			"Karo As","Karo iki","Karo uc","Karo Dort","Karo Bes","Karo Alti","Karo Yedi","Karo Sekiz","Karo Dokuz","Karo On","Karo J","Karo Q","Karo K",
			"Sinek As","Sinek iki","Sinek uc","Sinek Dort","Sinek Bes","Sinek Alti","Sinek Yedi","Sinek Sekiz","Sinek Dokuz","Sinek On","Sinek J","Sinek Q","Sinek K",
			"Maca As","Maca iki","Maca uc","Maca Dort","Maca Bes","Maca Alti","Maca Yedi","Maca Sekiz","Maca Dokuz","Maca On","Maca J","Maca Q","Maca K" };


		int cardvalue[] = { 1,2,3,4,5,6,7,8,9,10,10,10,10,1,2,3,4,5,6,7,8,9,10,10,10,10,1,2,3,4,5,6,7,8,9,10,10,10,10,1,2,3,4,5,6,7,8,9,10,10,10,10 };



		srand(time(NULL));

		for (int i = 0; i < 52; i++)
		{


			x = rand() % 52;
			random[i] = x;
			for (int j = -1; j < i; j++)
			{
				if (random[i] == random[j]) //bir öncekileRle aynı olmamalı
				{
					i--;
					break;

				}
				else {
					deger[i] = cardvalue[x];

				}



			}



		}
		int sayac = 0;
		printf("Masanin Kartlari: %s\t XX", card[random[sayac]]); sayac = sayac + 2; masatoplam = deger[sayac - 1] + deger[sayac-2];
		if (deger[sayac - 1] == 1 || deger[sayac - 2] == 1)masatoplam += 10;//Masa As çekerse
		printf("\nOyuncunun Kartlari: %s\t%s", card[random[sayac]], card[random[sayac + 1]]);
		sayac++; oyuncutoplam = deger[sayac] + deger[sayac - 1];
		if (deger[sayac] == 1 || deger[sayac - 1] == 1)//Oyuncu As çekerse
		{
			while (1) {
				printf("\nAs cektiniz 11 olarak kullanmak ister misiniz ?  Evet(e) Hayir(h)");
				scanf_s(" %c", &assoru);
				if (assoru == 'e' || assoru == 'E') {
					oyuncutoplam += 10;
					break;
				}
				else if (assoru == 'h' || assoru == 'H') {
					break;
				}
				else
					printf("\nYanlis bir karakter girdiniz");
			}


		}
		printf("\t Toplam:%d", oyuncutoplam);

		while (1) {
			printf("\nKart cekmek istiyor musun? Evet (e)\t Hayir(h)");
			scanf_s(" %c", &soru);
			if (soru == 'e') {
				sayac++; oyuncutoplam += deger[sayac];
				if (deger[sayac] == 1 && oyuncutoplam < 12) {//Oyuncu as çekerse ve elinin toplamı 12 den küçükse
					while (1) {
						printf("\nAs cektiniz 11 olarak kullanmak ister misiniz ?  Evet(e) Hayir(h)");
						scanf_s(" %c", &assoru);
						if (assoru == 'e' || assoru == 'E') {
							oyuncutoplam += 10;
							break;
						}
						else if (assoru == 'h' || assoru == 'H') {
							break;
						}
						else
							printf("\nYanlis bir karakter girdiniz");
					}
				}
				printf("\nYeni kartiniz:%s \t Yeni Toplam:%d", card[random[sayac]], oyuncutoplam);
				
			}
			else if (soru == 'h')
				break;
			else {
				printf("Yanlis bir karakter girdiniz");
			}
			if (oyuncutoplam > 21) {//Oyuncu 21 i geçerse kart çekme döngüsünü sonlandırıyor
				break;
			}

		
		}
		if (oyuncutoplam > 21) {// Oyuncu 21 i geçerse kaybeder masa kart çekmeden oyun sonlanır oyuncuya tekrar oynamak istiyor musun diye sorulur
			printf("\n\t\t\t\t\tKAYBETTINIZ");
			kaybetme++;
			printf("\nTekrar oynamak istiyor musunuz ? Evet (e) Hayir (h)");
			scanf_s(" %c", &bitis);
			if (bitis == 'h')
				break;
			else
				continue;
		}
			printf("Masanin Kartlari:%s\t%s", card[random[0]], card[random[1]]);//Masanın 17 den büyük olduğu durumlarda da elindekileri yazması için döngü dışında
			
			while (masatoplam < 17) {
					sayac++;
					masatoplam += deger[sayac];
					if (deger[sayac] == 1 && masatoplam < 12)masatoplam += 10;//Masa as çekerse
					printf("\t%s", card[random[sayac]]);
				}
			printf("\nMasanin Toplami:%d", masatoplam);
			
			

		
		if (masatoplam > 21) {//Masa 21 i geçerse oyuncu kazanır
			printf("\n\t\t\t\t\tKAZANDINIZ"); kazanma++;
		}
		else if (masatoplam < oyuncutoplam) {
			printf("\n\t\t\t\t\tKAZANDINIZ"); kazanma++;
		}
		else if (masatoplam>oyuncutoplam) {
			printf("\n\t\t\t\t\tKAYBETTINIZ");
			kaybetme++;
		}
		else if (masatoplam == oyuncutoplam) {
			printf("\n\t\t\t\t\tBERABERE"); beraberlik++;
		}

		printf("\nTekrar oynamak istiyor musunuz ? Evet (e) Hayir (h)");
		scanf_s(" %c", &bitis);
		if (bitis == 'h')
			break;
		else;

	}
	printf("Kazanma Sayisi:%d Kaybetme Sayisi:%d Beraberlik Sayisi:%d\n", kazanma, kaybetme, beraberlik);
	system("pause");
}

#include <iostream> // Giriş ve çıkış işlemlerini gerçekleştirmek için kullanılan başlık dosyası programa dahil edildi
#include <ctime>   // Tarih ve saatle ilgili işlemler için kullanılan bir kütüphane, rand() fonksiyonu için kullandık.
#include <iomanip> // setw, fixed ve precision işlevleri için dahil edildi
using namespace std;

class Tavuk {
private:
	int yumurtlanmayanGun;	    // Tavuğun kaç gündür yumurtlamadığı değişkeni
	int ciftlikteBulunulanGun; // Tavuğun çiftliğe kaç gün önce geldiği değişkeni
	int ToplamYumurta;		  // Tavuğun çiftlikte bulunduğu süre boyunca toplam kaç yumurta verdiği değişkeni

public:
	Tavuk() { // Kurucu fonksiyon //
		yumurtlanmayanGun = 0;
		ciftlikteBulunulanGun = 0;
		ToplamYumurta = 0;
	}

	int yumurtla() { // Yumurtlama fonksiyonu //
		ciftlikteBulunulanGun++; // Çiftlikte bulunulan günü 1 arttır
		if (ciftlikteBulunulanGun > 3) {
			int gunlukYumurta = rand() % 3; // 1 tavuğun günlük ürettiği yumurta sayısının 0,1 ve 2 değerlerini rastgele alması sağlanır
			if (gunlukYumurta == 0) {
				yumurtlanmayanGun++; // Tavuk o gün yumurtlamamışsa, yumurtlanmayanGun değişkeni 1 arttırılır.
			}
			else {
				yumurtlanmayanGun = 0; // Tavuk yumurtlarsa yumurtlanmayanGun değişkeni 0'a eşitlenir.
			} // Bu sayede üst üste 3 gün yumurtlamadığı tespit edilebilir. 

			ToplamYumurta += gunlukYumurta;
			return gunlukYumurta;
		}
		else {
			return 0;
		}
	}

	int yemYe() { // 1 tavuğun günlük tükettiği yem miktarını hesaplayan fonksiyon //
		 return rand() % 21 + 100;    // Günlük 100 ile 120 gram arasında rastgele yem tüketimi
	}

	int yumurtlanmayanGunDegeri() { // Sonradan çağrılmak üzere oluşturulan yumurtlanmayan gün değerini ifade eden fonksiyon //
		return yumurtlanmayanGun;
	}
	int ToplamYumurtaDegeri() { // Sonradan çağrılmak üzere oluşturulan toplam toplanan yumurtayı ifade eden fonksiyon //
		return ToplamYumurta;
	}
	int ciftlikteBulunulanGunDegeri() { // Sonradan çağrılmak üzere oluşturulan tavuğun çiftlikte toplam kaç gün zaman geçirdiğini ifade eden fonksiyon //
		return ciftlikteBulunulanGun;
	}

};

class Ciftlik {
private:
	double kalanPara;
	int    TavukSayisi;
	double yemFiyatlari;
	double yumurtaFiyatlari;
	double tavukAlimFiyati;
	double kalanYem;
	Tavuk* tavuk_vatandasi;

public:
	Ciftlik(double sermaye, int tavukAdedi, double yemKgFiyati, double yumurtaFiyati, double tavukFiyati) { // Kurucu Fonksiyon //
		kalanPara        = sermaye;                // Başlangıç sermayesi atanır.
		TavukSayisi		 = tavukAdedi;             // Çiftlikteki toplam tavuk sayısı atanır.
		yemFiyatlari	 = yemKgFiyati;            // Yem kilogram fiyatı atanır.
		yumurtaFiyatlari = yumurtaFiyati;		   // Yumurtanın satış fiyatı atanır.
		tavukAlimFiyati  = tavukFiyati;			   // Bir tavuğun alım fiyatı atanır.
		kalanYem		 = 700;                    // Çiftlikteki başlangıç yem miktarı 700 kg olarak ayarlanır.
		tavuk_vatandasi  = new Tavuk[TavukSayisi]; // Tavukları tutacak dinamik dizi oluşturulur.
	}

	~Ciftlik() { // Çiftlik sınıfının yıkıcı (destructor) fonksiyonu //
		// Dinamik olarak oluşturulan tavuk_vatandasi dizisini bellekten temizler.
		delete[] tavuk_vatandasi;
	}

	void simulasyonYap(int simuleGun) { // Günlük simülasyon mekanizmasını içeren fonksiyon //

		cout << "\n*************************************" << endl;
		cout << "Başlangıç sermayesi: " << kalanPara << endl;
		cout << "Tavuk sayısı       : " << TavukSayisi << endl;
		cout << "Yem kilogram fiyatı: " << yemFiyatlari << endl;
		cout << "Yumurta fiyatı     : " << yumurtaFiyatlari << endl;
		cout << "Tavuk alım fiyatı  : " << tavukAlimFiyati << endl;
		cout << "Simülasyon yapılacak gün sayısı: " << simuleGun << endl;
		cout << "*************************************\n" << endl;

		cout << "Gün Yem Tüketimi(gram) Yumurta Kesilen Tavuk   Günlük Gelir   Günlük Gider   Kalan Yem(gram)   Kalan Para" << endl;
		cout << "--- ------------------ ------- ------------- --------------- --------------- --------------- ---------------" << endl;

		double tavukMaliyeti = tavukAlimFiyati * TavukSayisi;     // Kullanıcının girdiği tavuk sayısı kadar tavuk satın alındı ve maliyeti hesaplandı
		kalanPara = kalanPara - tavukMaliyeti;                   // Bu maliyet, kalan paradan düşüldü. 

		kalanPara = kalanPara - (kalanYem * yemFiyatlari);     // Başlangıç yeminin maliyeti kalan paradan düşüldü. Şimdi bu kalan parayla simülasyonumuza giriş yapacağız
		double toplamYumurtaGeliri = 0;						  // Yumurtadan elde ettiğimiz gelirin değişkeni

		// Simülasyonu verilen gün sayısı kadar çalıştıracak for döngüsü  //
		for (int gun = 1; gun < simuleGun + 1; gun++) { // Simülasyon, belirtilen gün sayısı kadar çalışıyor. //

			int    ToplamYumurtaAdedi = 0; // Simülasyonda her gün toplanan yumurta adetlerinin toplamıyla oluşturulan nihai toplam yumurta değişkeni
			int	   KesilenTavukSayisi = 0; // Kesim şartlarını sağlayan toplam tavuk sayısının değişkeni
			double gunlukGelir	      = 0; // Günlük gelir değişkeni her gün sıfırlanıyor
			double gunlukGider		  = 0; // Günlük gider değişkeni her gün sıfırlanıyor
			double gunlukYem		  = 0; // Günlük yem değişkeni her gün sıfırlanıyor

			// Her tavuğun ayrı ayrı incelenmesini sağlayan for döngüsü //
			for (int t = 0; t < TavukSayisi; t++) { // Her tavuğa tek tek yumurtlama yem yedirme, kesim şartı kontrolü, kesimi ve yem stok kontrolü işlemi yaptırılıyor
				int    tavukBasinaYemTuketimi   = 0;
				int    tavukBasinaYumurtaAdedi  = 0;
				double tavukBasinaYumurtaGeliri = 0;

				tavukBasinaYumurtaAdedi += tavuk_vatandasi[t].yumurtla(); // t numaralı tavuğun yumurtlaması, tavuk başına yumurta değerine ekleniyor //
				ToplamYumurtaAdedi		+= tavukBasinaYumurtaAdedi;

				tavukBasinaYemTuketimi += tavuk_vatandasi[t].yemYe(); // t numaralı tavuğun gram cinsinden yediği yem miktarı yemYe fonksiyonuyla hesaplanıyor ve tavuk başına tüketilen yem değerine ekleniyor. Bir sonraki her tavukta bu değer sıfırlanıyor.
				gunlukYem			   += tavukBasinaYemTuketimi;	 // bu tüketim, gram cinsinden gunlukYem değişkenine ekleniyor. Bu değişken sayesinde kodun ilerleyen kısımlarında kalan yem hesabı yapacağız.
				
				//----------------------------------------------//

				// Tavuk kesim şartları //
				if (tavuk_vatandasi[t].yumurtlanmayanGunDegeri() >= 3 || tavuk_vatandasi[t].ToplamYumurtaDegeri() >= 100) { // Başlangıçtaki ilk 3 gün hariç, üst üste 3 ve 3'den fazla gün yumurtlamayan veya çiftlikte 100 günü dolduran tavuklara koşul getiren if bloğu //
					KesilenTavukSayisi++;				      // Yukarıdaki şartın sağlanması halinde kesilen tavuk sayısı 1 artar
					tavuk_vatandasi[t] = Tavuk();			  // t numaralı tavuk silinir ve yerine yeni bir tavuk gelir. Bu iki işlem aynı anda tek satırda, bu satırda yapılır
					kalanPara		  += tavukAlimFiyati / 2; // Kesilen tavuk başına, tavuk alım fiyatının yarısı kalan paraya aktarılır
					kalanPara		  -= tavukAlimFiyati;     // Yeni tavuk alım masrafı kalan paradan kesilir
					gunlukGelir		  += tavukAlimFiyati / 2; // Kalan paraya aktarılan tutar, ayrıca günlük gelir değişkenine de aktarılır
					gunlukGider		  += tavukAlimFiyati;     // Kalan paradan çıkarılan tutar, ayrıca günlük gider değişkenine de aktarılır
				}
				//----------------------------------------------//

				// Yumurtaların satışından elde edilen gelir //
				tavukBasinaYumurtaGeliri += tavukBasinaYumurtaAdedi * yumurtaFiyatlari;
				kalanPara			     += tavukBasinaYumurtaGeliri;
				gunlukGelir				 += tavukBasinaYumurtaGeliri;
				toplamYumurtaGeliri		 += tavukBasinaYumurtaGeliri;
			}
			//----------------------------------------------//

			// Kalan yem hesabı //
			kalanYem -= gunlukYem / 1000; // Tavukların yem tüketerek katkıda bulunduğu gunlukYem değişkeni tamamlandı. Artık bu değişkeni 1000'e bölüp kalanYem'den çıkararak gün sonunda kalan yemi kilogram cinsinden bulabiliriz.


			// Yemin 70 kg altına düşmesi olayı //
			if (kalanYem < 70) { // 70 kilogramdan daha az yem kalması halinde çalışacak if bloğu //
				kalanYem    += 700;				   // Kalan yem miktarı 70 kilogramdan az olduğu için 700 kilogram yem takviyesi alır
				kalanPara   -= 700 * yemFiyatlari; // 700000 gram yani 700 kg yemin maliyeti kalan paradan düşülür
				gunlukGider += 700 * yemFiyatlari;
			}

			// Tablonun ekrana yazdırılması //
			cout << right << setw(3) << gun
				<< setw(19) << gunlukYem
				<< setw(8) << ToplamYumurtaAdedi
				<< setw(14) << KesilenTavukSayisi
				<< setw(16) << gunlukGelir
				<< setw(16) << gunlukGider
				<< setw(16) << kalanYem * 1000 // Kalan yem grama dönüştürülerek yazdırıldı
				<< setw(16) << kalanPara << endl;

			// Toplam paramızın 0'ın altına düşmesi halinde gösterilecek "İflas ettiniz..." mesajını çalıştıracak if bloğu //
			if (kalanPara < 0) { 
				cout << "İflas ettiniz..." << endl;
				cout << "*************************************";
				break;
			}
		}
	}
};

int main() {

	// Başlangıç İşlemleri //
	setlocale(LC_ALL, "Turkish");
	srand(time(0));
	cout.precision(2);
	cout << fixed;
	//----------------------------------------------//

	// Değişken Tanımları //
	double baslangicSermayesi, yemFiyati, yumurtaSatis, tavukAlim;
	int tavukSayisi, simulasyonGun;

	//----------------------------------------------//

	// Kullanıcıdan Bilgiler İstenmesi //

	cout << "Başlangıç sermayeniz: ";
	cin >> baslangicSermayesi;
	if (baslangicSermayesi < 0) {
		cout << "Hatalı giriş yaptınız, lütfen tekrar deneyiniz.";
		return 0;
	}
	
	cout << "Çiftlikteki tavuk sayınız(En fazla 500 olmalıdır): ";
	cin >> tavukSayisi;
	if (tavukSayisi > 500) { // Tavuk sayısının 500'den fazla olması engelleniyor.
		cout << "Tavuk sayısı 500'ü geçmemelidir.";
		return 0;
	}
	else if (tavukSayisi < 0) {
		cout << "Hatalı giriş yaptınız, lütfen tekrar deneyiniz.";
		return 0;
	}

	cout << "Tavuk yeminin kilogram fiyatını giriniz: ";
	cin >> yemFiyati;
	if (yemFiyati < 0) {
		cout << "Hatalı giriş yaptınız, lütfen tekrar deneyiniz.";
		return 0;
	}

	cout << "Yumurtanın satış fiyatını giriniz: ";
	cin >> yumurtaSatis;
	if (yumurtaSatis < 0) {
		cout << "Hatalı giriş yaptınız, lütfen tekrar deneyiniz.";
		return 0;
	}

	cout << "Tavuk alım fiyatını giriniz: ";
	cin >> tavukAlim;


	cout << "Simülasyon yapılacak gün sayısını giriniz: ";
	cin >> simulasyonGun;
	if (simulasyonGun < 0) {
		cout << "Hatalı giriş yaptınız, lütfen tekrar deneyiniz.";
		return 0;
	}
	//----------------------------------------------//

	Ciftlik ciftlik(baslangicSermayesi, tavukSayisi, yemFiyati, yumurtaSatis, tavukAlim);
	ciftlik.simulasyonYap(simulasyonGun);

	//------------------------------------------------------------------------------------//
	return 0;
}

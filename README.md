# TavukCiftligiSimulasyonu
C++ dilinde yazdığım Tavuk Çiftliği simülasyonu.

Tavuk Çiftliği Simülasyonu Raporu 
1. Genel Tanım 
Bu program, C++  diliyle yazılmış bir tavuk çiftliği simülasyonu oluşturmaktadır. 
Program, kullanıcıdan başlangıç sermayesi, yem fiyatları, yumurta satış fiyatı, tavuk alım 
fiyatı ve simülasyon süresi gibi parametreleri alarak çiftliğin günlük performansını detaylı 
olarak hesaplar ve raporlar. Kodlar Visual Studio 2022 derleyicisi ile yazılmıştır. 

2. Programın Temel Amacı 
• Çiftlikte bulunan tavukların günlük yumurtlama, yem tüketimi ve kesim 
şartlarını takip ederek bir simülasyon yapılması. 
• Tavukların yumurta üretiminden gelir elde edilmesi, yem maliyetlerinin ve kesilen 
tavukların maliyetlerinin hesaba katılması. 
• Simülasyon sonunda çiftliğin kalan sermayesinin, yem miktarının vs. 
belirlenmesi. 

3. Sınıf Tanımlamaları 
Tavuk Sınıfı 
Tavuk() sınıfı: bir tavuğun günlük aktivitelerini ve durumunu takip eder. 

• Değişkenler: 
o yumurtlanmayanGun: Tavuğun kaç gündür yumurtlamadığını tutar. Her 
tavukta değeri değişir, tamamen farklı olmak zorunda değildir. 
o ciftlikteBulunulanGun: Tavuğun çiftlikte geçirdiği gün sayısını tutar. Her 
tavukta değeri değişir, tamamen farklı olmak zorunda değildir. 
o ToplamYumurta: Tavuğun toplam yumurta üretim sayısını tutar. Her 
tavukta değeri değişir, tamamen farklı olmak zorunda değildir. 
• Fonksiyonlar: 
o yumurtla(): Rastgele günlük yumurta üretimini hesaplar. 0, 1 veya 2 
yumurta üretilebilir. 
o yemYe(): Tavuğun günlük rastgele 100-120 gram arasında yem tüketmesini 
sağlar. 
o yumurtlanmayanGunDegeri(), ToplamYumurtaDegeri(), 
ciftlikteBulunulanGunDegeri(): Değişken değerlerini döner. 

Ciftlik Sınıfı 
Bu sınıf, çiftlikte bulunan tüm tavukların durumunu ve çiftliğin finansal yapısını takip 
eder. 
• Değişkenler: 
o kalanPara: Çiftliğin mevcut sermayesi. 
o TavukSayisi: Çiftlikteki tavuk sayısı. 
o yemFiyatlari: 1 kilogram yemin fiyatı. 
o yumurtaFiyatlari: Bir adet yumurtanın satış fiyatı. 
o tavukAlimFiyati: Yeni tavuk alım fiyatı. 
o kalanYem: Çiftlikte mevcut yem miktarı (kg cinsinden). 
o tavuk_vatandasi: Tavuk sınıfı nesnelerinin tutulduğu dinamik dizi. 
• Fonksiyonlar: 
o Ciftlik(): Başlangıç parametreleri ile çiftliği kurar. 
o simulasyonYap(int simuleGun): Belirtilen gün sayısı kadar çiftliği simüle 
eder. 

4. Programda Yapılan İşlemler 
1. Kullanıcıdan Veri Alımı 
o Başlangıç sermayesi, tavuk sayısı, yem fiyatı, yumurta satış fiyatı ve tavuk 
alım fiyatı kullanıcıdan alınır. 
o Tavuk sayısının 500'ü aşmaması kontrol edilir. 

2. Başlangıç Değerlerinin Hesaplanması 
o Tavuk alım maliyeti (tavukAlimFiyati * TavukSayisi) başlangıç 
sermayesinden düşülür. 
o Başlangıç yemi olan 700 kg yem maliyeti kalan sermayeden düşülür. 

3. Günlük Simülasyon Döngüsü 
o Her gün için aşağıdaki işlemler yapılır:  
▪ Her tavuğun:  
▪ 0,1 veya 2 adet yumurtlama işlemi rastgele yapılır. 
▪ 100 ile 120 gram arasında yem tüketimi rastgele hesaplanır 
ve toplam yem miktarı azaltılır. 
▪ Yumurtlamayan tavuklar ve 100 yumurta üretmiş tavuklar kesilerek 
yerine yeni tavuklar alınır. Fakat çiftliğe yeni gelen tavuklar ilk 3 gün 
yumurtlamaz. Bu 3 günden ötürü yumurtlamama, kesim olacağı 
anlamına gelmez. 
▪ Yumurta satışından elde edilen gelir hesaplanır. 
▪ Yem takviyesi yapılır (eğer kalan yem 70 kg'dan az ise 700 kg yem 
alınır). 

4. Sonuçların Raporlanması 
o Günlük olarak:  
▪ Tüketilen yem miktarı 
▪ Toplanan yumurta sayısı 
▪ Kesilen tavuk sayısı 
▪ Günlük gelir ve gider 
▪ Kalan yem miktarı 
▪ Kalan para miktarı 
o Kalan para negatif olursa, çiftliğin iflas ettiği belirtilir ve simülasyon 
sonlandırılır. 

5. Özellikler  
Mevcut Özellikler: 
• Tavukların rastgele yumurtlama davranışı. 
• Yem tüketimi ve yem takviyesi hesaplaması. 
• Tavuğun kesim koşullarının uygulanması. 
• Günlük detaylı rapor çıktısı. 

6. Sonuç 
Bu program, bir tavuk çiftliği işletmesinin günlük performansını başarılı bir şekilde 
simüle eder. 

#include <iostream>
#include <iomanip>
#include <math.h>     //sqrt
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
using namespace std;

class Classroom{
  public:
    Classroom(){
      // 10 tane öğrenci olsun
      n=10;
      yer_ayir();
    }
    Classroom(int _n){
      // ...
      n = _n;
      yer_ayir();
    }
    void yaz(){
      cout<<setw(5)<<"AS"<<setw(5)<<"FN"<<setw(6)<<"Ort\n";
      for(int i=0;i<n;i++){
        ort[i] = (as[i]+fn[i])/2.0;

        cout<<i+1<<". "<<as[i]<<"\t"<<fn[i]<<"\t"<<ort[i]<<"\t"<<"\n";
      }
      hamort();
      standartSapma();
      Tsayisi();
      harfliler();
    }
    void hamort(){
      for(int i=0; i<n; i++)
      {
        if(ort[i] > 15)
        {
          HBNort += ort[i];
          sayi++;
        }
      }
      HBNort = HBNort / sayi;
      cout<<"\nHBNort : "<<HBNort<<"\t(15 üzeri notlar dikkate alinmiştir.)\n";
    }
    void standartSapma()
    {
      for(int i=0; i<n; i++)
      {
        HBNstd += (ort[i] - HBNort) * (ort[i] - HBNort);
      }
      HBNstd = sqrt(HBNstd / n-1);
      cout<<"standart sapma :"<<HBNstd<<endl<<endl;
    }
    void Tsayisi()
    {
      for(int i=0; i<n; i++)
      {
        T[i] =((ort[i] - HBNort) / HBNstd) * 10 + 50;
        cout<<i+1<<". ögrencinin T sayisi : "<<T[i]<<endl;
      }
    }
    void harfliler()
    {
      int k;
      if(HBNort <= 42.5)
      {
        cout<<"**********Sınıf Düzeyi: Kötü\n"; k = 0;
      }
      else if(HBNort <= 47.5)
      {
        cout<<"**********Sınıf Düzeyi: Zayıf\n"; k = 2;
      }
      else if(HBNort <= 52.5)
      {
        cout<<"**********Sınıf Düzeyi: Orta\n"; k = 4;
      }
      else if(HBNort <= 57.5)
      {
        cout<<"**********Sınıf Düzeyi: Ortanın Üstü\n"; k = 6;
      }
      else if(HBNort <= 62.5)
      {
        cout<<"**********Sınıf Düzeyi: İyi\n"; k = 8;
      }
      else if(HBNort <= 70.0)
      {
        cout<<"**********Sınıf Düzeyi: Çok İyi\n"; k = 10;
      }
      else if(HBNort <= 80.0)
      {
        cout<<"**********Sınıf Düzeyi: Mükemmel\n"; k = 12;
      }
      else
        cout<<"Sınıf Düzeyi : Üstün Başarı\nHarfliler Tablo 3'e göre verilecektir.";//else 80 < HBNort <= 100 Tablo 3 e göre degerlendirilir..

          for(int i=0; i < n; i++){
            if(T[i] < 36-k)
            {
              cout<<i+1<<". ögrenci : FF\n";
            }
            else if(T[i] <= 40.99-k)
            {
              cout<<i+1<<". ögrenci : FD\n";
            }
            else if(T[i] <= 45.99-k)
            {
              cout<<i+1<<". ögrenci : DD\n";
            }
            else if(T[i] <= 50.99-k)
            {
              cout<<i+1<<". ögrenci : DC\n";
            }
            else if(T[i] <= 55.99-k)
            {
              cout<<i+1<<". ögrenci : CC\n"; 
            }
            else if(T[i] <= 60.99-k)
            {
              cout<<i+1<<". ögrenci : CB\n";
            }
            else if(T[i] <= 65.99-k)
            {
              cout<<i+1<<". ögrenci : BB\n"; 
            }
            else if(T[i] <= 70.99-k)
            {
              cout<<i+1<<". ögrenci : BA\n"; 
            }
            else
              cout<<i+1<<". ögrenci : AA\n";
          }
    }

  private:
    void yer_ayir(){
      as = new int[n];
      fn = new int[n];
      ort = new float[n];
      T = new float[n];
      srand (time(NULL));
      for(int i=0;i<n;i++){
        as[i] = rand()%100 +1;
        fn[i] = rand()%100 +1;
      }
    }
    int *as;
    int *fn;
    float *ort;
    float *T;
    float HBNort=0;
    int n;
    float HBNstd;
    int sayi=0;
};

int main() {
  Classroom c(30);
  c.yaz();
}
//tablo 1'e göre implement edildi. Sınıf mevcudu 30 ve üzeri olmalıdır.

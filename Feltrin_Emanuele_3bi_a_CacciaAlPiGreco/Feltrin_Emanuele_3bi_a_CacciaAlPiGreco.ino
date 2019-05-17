#include <LiquidCrystal.h>
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

int NumeroRandom;
int PosizioneRandom;
int Bottone1;
int Bottone2;
int Bottone3;
int Bottone4;
int Bottone5;
int BottoneIniziale;
int Record;
int Vite;
int Punti_PartitaCorrente;
int PosizionePiGreco;
int PosizionePenality;
int PosizioneJolly;
int ArrayBottoni[5] = { Bottone1, Bottone2, Bottone3, Bottone4, Bottone5};
int ArrayPosizione[5] = {0, 4, 8, 12, 15};

void setup() {
  lcd.begin(16, 2);
  Record = 0;
  Bottone1 = 2;
  Bottone2 = 3;
  Bottone3 = 4;
  Bottone4 = 5;
  Bottone5 = 6;
  BottoneIniziale = 8;
  pinMode (Bottone1,INPUT);
  pinMode (Bottone2,INPUT);
  pinMode (Bottone3,INPUT);
  pinMode (Bottone4,INPUT);
  pinMode (Bottone5,INPUT);
  pinMode (BottoneIniziale,INPUT);
}

void SchermataIniziale()
{
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Start Game");
  lcd.setCursor(0,1);
  lcd.print("Il Record: " + String(Record));
}

void SchermataGioco()
{
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Vite: " +String(Vite));
  lcd.setCursor(9,0);
  lcd.print("Punti: " + String(Punti_PartitaCorrente));
}

void AggiornaRecord(int record, int Punti)
{
  if(Punti>record)
  {
    Record = Punti;
  }
}

void NumeroRandomMetodo(int valoreDa, int valoreA)
{
  NumeroRandom = random(valoreDa,valoreA);
}

void BottoneInizioMetodo( int bottone)
{
  bool fatto = false;
  while(!fatto)
  {
    if(digitalRead(bottone) == HIGH)
    {
      fatto=true;
    }
  }
}

void Gioco()
{
  bool fatto = false;
  SchermataGioco();
  while(!fatto && Vite >0)
  {
    NumeroRandomMetodo(0,9);
    if(NumeroRandom >=0 && NumeroRandom <=5)
    {
      PosizioneRandom = random(0,4);
      lcd.setCursor(ArrayPosizione[PosizioneRandom],1);
      lcd.print("π");
      int Tempo1 = millis();
      int Tempo2;
      bool finito = false;
      while(!finito)
      { 
        if(digitalRead(ArrayBottoni[PosizioneRandom]) == HIGH)
        {
          Punti_PartitaCorrente++;
          finito = true;
        }
         Tempo2=millis();
         if (Tempo2- Tempo1 >=2000)
         {
          finito = true;
          Vite--;
         }
      }
    }
    else if(NumeroRandom >=6 && NumeroRandom <= 7)
    {
      //malus
      PosizioneRandom = random(0,4);
      lcd.setCursor(ArrayPosizione[PosizioneRandom],1);
      lcd.print("💣");
      int Tempo1 = millis();
      int Tempo2;
      bool finito = false;
      while(!finito)
      {
        if(digitalRead(ArrayBottoni[PosizioneRandom]) == HIGH)
        {
          Vite--;
          finito = true;
        }
         Tempo2=millis();
         if (Tempo2- Tempo1 >=2000)
         {
          finito = true;
         }
      }
    }
    else
    {
      //bonus
      PosizioneRandom = random(0,4);
      lcd.setCursor(ArrayPosizione[PosizioneRandom],1);
      lcd.print("❤");
      int Tempo1 = millis();
      int Tempo2;
      bool finito = false;
      while(!finito)
      {
        if(digitalRead(ArrayBottoni[PosizioneRandom]) == HIGH)
        {
          Vite++;
          finito = true;
        }
         Tempo2=millis();
         if (Tempo2- Tempo1 >=1500)
         {
          finito = true;
         }
      }
    }    
  } 
}
















void loop() {
  AggiornaRecord( Record, Punti_PartitaCorrente);
  Vite = 3;
  Punti_PartitaCorrente = 0;
  SchermataIniziale();
  BottoneInizioMetodo(BottoneIniziale);
  Gioco();
}

#include <LiquidCrystal.h>
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

int NumeroRandom;
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
double Tempo;
int ArrayPiGreco[5];

void setup() {
  lcd.begin(16, 2);
  Record = 0;
  Vite = 3;
  Punti_PartitaCorrente = 0;
  Tempo = 1.5;
  int ArrayBottoni[5] = { Bottone1, Bottone2, Bottone3, Bottone4, Bottone5};
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

  SchermataIniziale();
}

void SchermataIniziale()
{
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Start Game");
  lcd.setCursor(0,1);
  lcd.print("Record:" + String(Record));
}

void AggiornaRecord(int record, int Punti_PartitaCorrente)
{
  if(Punti_PartitaCorrente>record)
  {
    Record = Punti_PartitaCorrente;
  }
}

void NumeroRandomMetodo()
{
  NumeroRandom = random(0,4);
}


void loop() {
  

}

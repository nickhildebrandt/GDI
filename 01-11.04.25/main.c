//
// Dipl.Phys. Gerald Kempfer
// Berliner Hochschule für Technik
// University of Applied Sciences
// Fachbereich VI – Informatik und Medien
// Studiengang Technische Informatik Bachelor
//
// Nick Hildebrandt
// Matrikelnummer: 109071
// Abgabe: 11.04.25
//

#include <stdio.h>
#include <stdlib.h>

int main() {
  double Preis1 = 9.99, Preis2 = 19.99, Preis3 = 24.49;
  double Netto, Mehrwert, Brutto;

  printf("Dieses Programm berechnet aus 3 Werten (z.B. ");
  printf("Artikelpreise) die Nettosumme, daraus die Mehrwertsteuer ");
  printf("und schliesslich den Bruttobetrag.\n");
  printf("Die drei Werte: %.2f, %.2f und %.2f\n", Preis1, Preis2, Preis3);
  Netto = Preis1 + Preis2 + Preis3;
  printf("Nettosumme    : %.2f\n", Netto);
  Mehrwert = Netto * 0.19;
  printf("Mehrwertsteuer: %.2f\n", Mehrwert);
  Brutto = Mehrwert + Netto;
  printf("Bruttobetrag  : %.2f\n", Brutto);

  return 0;
}

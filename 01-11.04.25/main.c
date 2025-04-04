//
// Nick Hildebrandt: Technische Informatik – Embedded Systems (B.Eng.)
// Matrikelnummer: 109071
// Grundlagen der Informatik: Abgabe 11.04.25
//
// Aufgabe:
// Ziel der Übung ist es, grundlegende Arbeitsmittel wie Linux-Terminal,
// vi-Editor und gcc-Compiler kennenzulernen, ein erstes C-Programm gemeinsam
// zu erstellen und zu kompilieren sowie anschließend eigenständig Fehler im
// Programm ueb01.c zu analysieren, zu korrigieren und die Funktionsweise des
// Compilers durch eigene Experimente besser zu verstehen.

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

  int *a = (int *)malloc(64);

  *a = 99;
  return 0;
}

//
// Dipl.Phys. Gerald Kempfer
// Berliner Hochschule für Technik
// University of Applied Sciences
// Fachbereich VI – Informatik und Medien
// Studiengang Technische Informatik Bachelor
//
// Nick Hildebrandt
// Matrikelnummer: 109071
// Abgabe: 02.05.25
//

#include <stdio.h>
#include <stdlib.h>

int main() {

  // Widerstand R1 (in Ohm)
  const double R1 = 200;

  // Widerstand R2 (in Ohm)
  const double R2 = 500;

  // Widerstand R3 (in Ohm)
  const double R3 = 300;

  // Gesamtwiderstand Reihenschaltung (in Ohm)
  double r_sum_series = 0.0;

  // Gesamtwiderstand Parallelschaltung (in Ohm)
  double r_sum_parallel = 0.0;

  // Gesuchter Wiederstand Wheatstonesche Messbrücke (in Ohm)
  double r_missing = 0.0;

  // Bildschirmausgabe der Wiederstandswerte (2 Nachkommastellen)
  printf("Gegeben:\n\tR1:\t%.2f\tOhm\n\tR2:\t%.2f\tOhm\n\tR3:\t%.2f\tOhm\n\n",
          R1, R2, R3);

  // Bildschirmausgabe und Berechnung Reihenschaltung (2 Nachkommastellen)
  r_sum_series = R1 + R2 + R3;
  printf("Gesamtwiderstand Reihenschaltung:\t%.2f\tOhm\n", r_sum_series);

  // Bildschirmausgabe und Berechnung Parallelschaltung (2 Nachkommastellen)
  r_sum_parallel = 1 / (1/R1 + 1/R2 + 1/R3);
  printf("Gesamtwiderstand Parallelschaltung:\t%.2f\tOhm\n", r_sum_parallel);

  // Bildschirmausgabe und Berechnung Messbrücke (2 Nachkommastellen)
  r_missing = R3 * R2 / R1;
  printf("Gesuchter Widerstand Messbrücke:\t%.2f\tOhm\n",
         r_missing);

  return 0;
}

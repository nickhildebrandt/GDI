//
// Dipl.Phys. Gerald Kempfer
// Berliner Hochschule für Technik
// University of Applied Sciences
// Fachbereich VI – Informatik und Medien
// Studiengang Technische Informatik Bachelor
//
// Nick Hildebrandt
// Matrikelnummer: 109071
// Abgabe: 09.05.25
//
// Aufgabe:
// In dieser Übungsaufgabe soll ein C-Programm erstellt werden, das
// quadratische Gleichungen zweiten Grades in der Form x² + px + q = 0 löst.
// Die Werte für p und q (Datentyp double) werden vom Benutzer eingegeben,
// wobei vorerst keine Fehleingaben berücksichtigt werden müssen. Zur Lösung
// wird die bekannte Formel verwendet, wobei zur Berechnung der Wurzel die
// Funktion sqrt aus der Bibliothek math.h eingebunden werden muss. Beim Linken
// ist zusätzlich der Parameter -lm anzugeben, um die mathematische Bibliothek
// zu nutzen. Das Programm soll eine formatiert umrahmte und optisch
// ansprechende Ausgabe erzeugen, wie im Aufgabenbeispiel gezeigt. Die Ausgabe
// der Werte von p, q, x₁ und x₂ erfolgt mit einer Gesamtbreite von 8 Zeichen
// und 2 Nachkommastellen, wobei bestimmte Werte wie der Wurzelausdruck und die
// Lösungen linksbündig dargestellt werden. Die Kompilierung, das Linken und
// der Programmstart erfolgen über eine Make-Datei.

#include <math.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Breite der Konsolenausgabe in Zeichen
#define PRINT_LEN 70

// Strukturtyp zur Rückgabe der Ergebnisse der p-q-Formel
typedef struct pq_ret {
  double x1;
  double x2;
} pq_ret;

// Liest eine Gleitkommazahl (double) von stdin ein und gibt sie zurück
double read_double(const char *print_str);

// Berechnet die Lösungen der p-q-Formel und gibt sie als Struktur zurück
pq_ret calc_pq(double p, double q);

// Gibt einen formatierten String in einem Rahmen fester Breite auf stdout aus
void print_buffer(const char *str, ...);

// Erzeugt einen neuen Zeichen-Buffer mit dem Zeichen c, n-mal wiederholt
char *get_char_n(char c, size_t count);

// Gibt eine Trennlinie bestehend aus Bindestrichen aus
void print_div();

int main() {

  // Koeffizient p der p-q-Formel
  double p = 0.0;

  // Koeffizient q der p-q-Formel
  double q = 0.0;

  // Struktur zur Speicherung der beiden Lösungen x1 und x2
  pq_ret pq;

  // Programmbeschreibung ausgeben
  print_div();
  print_buffer(
      " Dieses Programm berechnet quadratische Gleichungen zweiten Grades");
  print_buffer(" der Form: x^2 + px + q = 0");
  print_buffer(" ");
  print_buffer(" Bitte geben Sie die Koeffizienten p und q ein:");
  print_div();

  // Einlesen der Werte für p und q
  p = read_double(" p = ");
  q = read_double(" q = ");

  // Berechnung der Lösungen mit der p-q-Formel
  pq = calc_pq(p, q);

  // Ausgabe der Rechnung und der Ergebnisse
  print_div();
  print_buffer(" Es wird nun die quadratische Gleichung zweiten Grades");
  print_buffer(" x^2 + %8.2fx + %8.2f = 0", p, q);
  print_buffer(" berechnet:");
  print_buffer("                           ________________________");
  print_buffer("          %08.2f        / %08.2f^2");
  print_buffer(" x    = - --------  + \\  /  ---------- - %-8.2f", q);
  print_buffer("  1,2         2     -  \\/       2");
  print_buffer(" ");
  print_buffer(" x1 = %8.2f", pq.x1);
  print_buffer(" x2 = %8.2f", pq.x2);
  print_div();

  return 0;
}

double read_double(const char *print_str) {

  // Eingabepuffer für die Zeichenkette
  char buffer[8];

  // Zeiger auf das Ende des konvertierten Werts
  char *endptr;

  // Rückgabewert
  double ret = 0.0;

  // Wiederhole die Eingabe, bis eine gültige Gleitkommazahl eingegeben wurde
  while (1) {

    // Eingabeaufforderung anzeigen
    printf("%s", print_str);

    // Lese Zeichenkette von stdin
    if (fgets(buffer, sizeof(buffer), stdin)) {

      // Versuche, die Zeichenkette in einen double-Wert umzuwandeln
      ret = strtod(buffer, &endptr);

      // Wenn keine gültige Zahl erkannt wurde
      if (endptr == buffer) {
        fprintf(stderr, "Ungültige Eingabe\n");
        continue;
      }

      // Gültiger Wert – gib ihn zurück
      return ret;
    }
  }
}

pq_ret calc_pq(double p, double q) {

  // Ergebnisstruktur initialisieren
  pq_ret ret;

  // Diskriminante der p-q-Formel berechnen
  double diskriminante = (p / 2) * (p / 2) - q;

  // Falls die Diskriminante negativ ist, gibt es keine reellen Lösungen
  if (diskriminante < 0) {
    fprintf(stderr, "Es gibt keine reellen Lösungen\n");
    exit(1);
  }

  // Lösungen gemäß der p-q-Formel berechnen
  ret.x1 = -(p / 2) + sqrt(diskriminante);
  ret.x2 = -(p / 2) - sqrt(diskriminante);

  // Struktur mit den berechneten Lösungen zurückgeben
  return ret;
}

void print_buffer(const char *str, ...) {

  // Puffer für die formatierte Zeichenkette
  char print_buffer[PRINT_LEN];

  // Initialisiere die Argumentliste
  va_list args;
  va_start(args, str);

  // Erzeuge die formatierte Zeichenkette
  vsnprintf(print_buffer, sizeof(print_buffer), str, args);
  va_end(args);

  // Falls der Text zu lang ist, abbrechen
  if (strlen(print_buffer) >= PRINT_LEN) {
    return;
  }

  // Mit Leerzeichen auffüllen
  for (size_t i = strlen(print_buffer); i <= PRINT_LEN - 1; i++) {
    print_buffer[i] = ' ';
  }

  // Nullterminierung sicherstellen
  print_buffer[PRINT_LEN - 1] = '\0';

  // Gerahmte Ausgabe
  printf("|%s|\n", print_buffer);
}

char *get_char_n(char c, size_t count) {

  // Speicher für die Zeichenkette reservieren
  char *ret = (char *)malloc(count + 1);

  // Zeichenfolge erzeugen
  for (size_t i = 0; i < count; i++) {
    ret[i] = c;
  }

  // Nullterminierung sicherstellen
  ret[count] = '\0';

  // Rückgabe der erzeugten Zeichenkette
  return ret;
}

void print_div() {

  // Trennlinie aus Bindestrichen erzeugen
  char *str = get_char_n('-', PRINT_LEN - 2);

  // Linie ausgeben
  print_buffer("%s", str);

  // Speicher freigeben
  free(str);
  str = NULL;
}

//
// Dipl.Phys. Gerald Kempfer
// Berliner Hochschule für Technik
// University of Applied Sciences
// Fachbereich VI – Informatik und Medien
// Studiengang Technische Informatik Bachelor
//
// Nick Hildebrandt
// Matrikelnummer: 109071
// Abgabe: 13.06.25
//

#include "tools.h"
#include "escapesequenzen.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

void clearBuffer() {
  int c;
  while ((c = getchar()) != '\n' && c != EOF)
    ;
}

int askAgain(int Row, int Col) {
  // Bildschirmausgabe an der Position Row/Col
  POSITION(Row, Col);

  // Ausgelesener Buchstabe
  char continue_input;

  // Eingabeaufforderung wiederholen bis eine gültige Eingabe erfolgt
  // entweder 'j' oder 'n'
  do {
    // Bildschirmausgabe an der Position Row/Col zur Eingabeaufforderung
    printf("Möchten Sie noch einmal? (j/n): ");

    // Einlesen eines Buchstabens aus der Standardeingabe
    scanf(" %c", &continue_input);

    // Eingabepuffer leeren
    clearBuffer();
  } while (continue_input != 'j' && continue_input != 'n' &&
           continue_input != 'J' && continue_input != 'N');

  // Rückgabe des Ermittelten Wahrwheitswertes ob der Bernutzer fortfahren
  // möchte (wenn die eingabe 'j' war)
  return continue_input == 'j' || continue_input == 'J';
}

// Einene Operanden als int mit der Eingabeaufforderung 'prompt' einlesen
// Wenn min==0 oder max == 0, wird keine Eingabelängenvalidierung durchgeführt
// Wenn Prompt == NULL, wird keine Eingabeaufforderung ausgegeben
// Die Bildschirmausgabe erfolgt ab der Zeile 'row' und Spalte 'col'
void read_operant(int *operand, const char *prompt, int min, int max, int row,
                  int col) {
  // Bolischer ausdruck zur Eingabelängenvalidierung
  int check_input_len = min != 0 && max != 0;

  // Bolischer ausdruck zur Eingabevalidierung
  int valid_input = 0;

  // Eingabeaufforderung bis eine gültige Eingabe erfolgt
  do {
    // Bildschirmeingabe an der Position Row/Col
    POSITION(row, col);

    // Nur die Eingabeaufforderung ausgeben, wenn sie nicht NULL ist
    if (prompt) {
      printf("%s", prompt);
    }

    // Ganzzahl aus der Standardeingabe lesen
    valid_input = scanf(" %i", operand) &&
                  (check_input_len ? *operand >= min && *operand <= max : 1);

    // Eeingabepuffer leeren
    clearBuffer();
  } while (!valid_input);
}

// Einen statischen String mit variablen Argumenten formatieren und einen
// Neuen allokierten String der richtigen Länge zurückgeben
// Der für den string zugewiesene Speicher muss durch den Aufrufer der Funktion
// freigegeben werden
// Die Funktion gibt NULL zurück, wenn ein Fehler auftritt
char *str_printf(const char *fmt, ...) {
  // Dynamisches einlesen der Formatierungs-Argumente
  va_list ap, ap_copy;
  va_start(ap, fmt);
  va_copy(ap_copy, ap);

  // Formatierter String Buffer
  char *buffer = NULL;

  // Berechnung der Länge des formatierten Strings
  int len = vsnprintf(NULL, 0, fmt, ap);
  va_end(ap);

  // Überprüfung der Länge: NULL bei Fehler
  if (len < 0) {
    va_end(ap_copy);
    return NULL;
  }

  // Speicher für den formatierten String reservieren
  buffer = malloc((size_t)len + 1);

  // Überprüfung der Speicherzuweisung: NULL bei Fehler
  if (!buffer) {
    va_end(ap_copy);
    return NULL;
  }

  // Formatierte Ausgabe in den Puffer
  vsnprintf(buffer, (size_t)len + 1, fmt, ap_copy);
  va_end(ap_copy);

  // Rückgabe des formatierten Strings oder NULL bei Fehler
  return buffer;
}

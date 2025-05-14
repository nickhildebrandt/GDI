//
// Dipl.Phys. Gerald Kempfer
// Berliner Hochschule für Technik
// University of Applied Sciences
// Fachbereich VI – Informatik und Medien
// Studiengang Technische Informatik Bachelor
//
// Nick Hildebrandt
// Matrikelnummer: 109071
// Abgabe: 11.07.25
//

#include "tools.h"
#include "escapesequenzen.h"
#include <stdio.h>

// Den Standardeingabepuffer leeren
void clear_input_buffer() {
  int c;
  while ((c = getchar()) != '\n' && c != EOF)
    ;
}

// Den Nutzer (an POS) fragen ob er weitermachen möchte und Wahrheitswert
// 0 oder 1 (int) zurückgeben
int prompt_proceed() {

  // Leerzeile einfügen
  DOWN(1);

  // Ausgelesener Buchstabe
  char continue_input;

  // Eingabeaufforderung wiederholen bis eine gültige Eingabe erfolgt
  // entweder 'j' oder 'n'
  do {
    // Bildschirmausgabe an der Position Row/Col zur Eingabeaufforderung
    printf("Moechten Sie noch einmal? (j/n): ");

    // Einlesen eines Buchstabens aus der Standardeingabe
    scanf(" %c", &continue_input);

    // Eingabepuffer leeren
    clear_input_buffer();

  } while (continue_input != 'j' && continue_input != 'n' &&
           continue_input != 'J' && continue_input != 'N');

  // Weitermachen (1) wenn 'j' oder 'J'
  return continue_input == 'j' || continue_input == 'J';
}

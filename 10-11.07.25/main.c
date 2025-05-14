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
// Ausführung mit z.b. "xterm -en iso-8859-15" bzw. latain-1
//

#include "escapesequenzen.h"
#include "tools.h"
#include <stdio.h>
#include <string.h>

// Zähle die Anzahl der Zeichen, dabei werden Groß- und Kleinbuchstaben
// zusammen gezählt und das Ergebnis an die ASCI Nummer des Kleinbuchstaben
// im count_array geschrieben, für alle anderen Zeichen gilt ihre native ASCI
// Nummer als position für die Anzahl im Array
void count_chars(unsigned char *input_array, int *count_array) {

  // Für jedes Zeichen im input_array den Zeiger letter um die breite
  // eines unsigned char verschieben, damit dieser auf das nächste zeigt
  for (unsigned char *letter = &input_array[0]; *letter != '\0'; letter++) {

    // Sollte es sich um ein Großbuchstaben handeln wird dieser so
    // inkrementiert dass an seiner Stelle ein Kleinbuchstabe steht.
    if ((*letter >= 'A' && *letter <= 'Z') ||
        (*letter >= 192 && *letter <= 222)) {

      // An der Arrayposition für den ASCI-Wert des Kleinbuchstaben + 1 Rechnen
      count_array[(int)*letter + 32] += 1;
      continue;
    }

    // An der Arrayposition für den ASCI-Wert des Buchstaben + 1 Rechnen
    count_array[(int)*letter] += 1;
  }
}

void print_table(int *count_array) {

  // Zähler für die ausgegebenen Zellen
  int cell_counter = 0;

  // Trenner
  printf("\n-------------------------------------------------------------");

  // Jeder Buchstabe im array der gezählt wurde ausgeben in 4 Spalten Tabelle
  for (int i = 0; i < 256; i++) {

    // Nur ausgeben wenn min 1 Buchstabe gezählt wurde
    if (count_array[i] != 0) {

      // Zeilenanfang (Jede 5. Zelle)
      if (cell_counter % 4 == 0) {
        printf("\n|");
      }

      // Sollte es sich um ein ASCI Steuerzeichen wie TAB etc. handeln ersetzen
      // wir dieses mit SPACE damit die Tabelle Richtig ausgeben wird
      printf(" %c (%#04x): %2i |", (i < 32) ? 32 : i, i, count_array[i]);

      // Für jede ausgegebene Zelle den Zähler um 1 erhöhen
      cell_counter++;
    }
  }

  // Letzte (Leere) Zellen einfügen
  while (cell_counter % 4 > 0) {
    printf("              |");
    cell_counter++;
  }

  // Trenner
  printf("\n-------------------------------------------------------------\n");
}

int main() {
  // Array der einzulesenden Zeichen
  unsigned char input_array[151];

  // Array zum Zählen der Zeichen
  int count_array[256];

  // Hauptschleife: Nach jedem durchngang wird der Nutzer gefragt ob er
  // weitermachen will - wenn 0 wird das Programm verlassen
  do {
    // Zählerwerte der Buchstaben auf 0 setzen
    memset(count_array, 0, sizeof(count_array));

    // Bildschirm von allen Zeichen Leeren und Cursor an POS(0,0) setzen
    CLEAR;

    // Ausgabe des Programmnamen
    POSITION(1, 0);
    printf("========================\n");
    printf("||                    ||\n");
    printf("||   Zeichenzaehler   ||\n");
    printf("||                    ||\n");
    printf("========================\n");

    // Benutzer zur Eingabe auffordern
    POSITION(7, 0);
    printf(
        "Geben Sie bitte den Text ein (mind. 1 Zeichen / max. 150 Zeichen):\n");

    // Versucht, einen string mit Max 150 Zeichen Einlesen
    scanf("%150[^\n]", input_array);

    // Leert den Eingabepuffer um nicht eingelesene Zeichen
    clear_input_buffer();

    // Buchstaben in der Eingabe Zählen
    count_chars(input_array, count_array);

    // Ausgabe der Zählung in einer Tabelle
    print_table(count_array);

  } while (prompt_proceed());

  return 0;
}

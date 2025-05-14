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

#include "escapesequenzen.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 59
#define LINE                                                                   \
  printf("|---------------------------------------------------------|\n")
#define EMPTY_LINE                                                             \
  printf("|                                                         |\n")

void clear_stdin(void) {
  int c;
  while ((c = getchar()) != '\n' && c != EOF)
    ;
}

// Den Nutzer fragenb ob er das Programm fortsetzen möchte
// falls ja => true ansonsten => false
int check_continue() {
  // Buchstabe 'j' oder 'n' aus der Benutzeingabe
  char continue_input;

  // Eingabeaufforderung bis eine gültige Eingabe ('j' oder 'n') erfolgt
  do {
    printf("Möchten Sie noch einmal (j/n)? ");
    scanf(" %c", &continue_input);
    clear_stdin();
  } while (continue_input != 'j' && continue_input != 'n' &&
           continue_input != 'J' && continue_input != 'N');

  // Wenn der Benutzer 'j' eingibt, wird das Programm fortgesetzt
  // => Warheitswert true
  return continue_input == 'j' || continue_input == 'J';
}

// Konvertiert eine 16-Bit-Zahl in eine Binärdarstellung
void short_to_binary16(short x, char out[17]) {
  for (int i = 15; i >= 0; i--) {
    out[15 - i] = ((x >> i) & 1) ? '1' : '0';
  }
  out[16] = '\0';
}

// Bildschrrmausgabe der Ergebnisse als Tabelle
void print_result_table(short operand1, short operand2, char *operation,
                        short result) {
  // Binärdarstellung der Operanden und des Ergebnisses
  char operand1_b16[17];
  char operand2_b16[17];
  char result_b16[17];

  // Umwandlung der Operanden und des Ergebnisses in Binärdarstellung
  short_to_binary16(operand1, operand1_b16);
  short_to_binary16(operand2, operand2_b16);
  short_to_binary16(result, result_b16);

  // Rahmen mit Leerzeile
  LINE;
  EMPTY_LINE;

  // Kopfzeile
  printf("|           |  dez.  |  okt.  |  hex.  |    Binaerzahl    |\n");

  // Datenzeilen

  printf("| Zahl 1    | %6hd | %6ho | %#6hx | %16s |\n", operand1, operand1,
         operand1, operand1_b16);

  printf("| Operation |    %c   |    %c   |    %c   |         %c        |\n",
         *operation, *operation, *operation, *operation);

  printf("| Zahl 2    | %6hd | %6ho | %#6hx | %16s |\n", operand2, operand2,
         operand2, operand2_b16);

  // Ergebniszeile
  LINE;

  printf("| Ergebnis  | %6hd | %6ho | %#6hx | %16s |\n", result, result, result,
         result_b16);

  // Rahmen mit Leerzeile
  EMPTY_LINE;
  LINE;
}

// Den Cursor von aktueller Position nach oben in die letzte Zeile bewegen
// und rechts den Rahmen '|' zeichnen
void print_right_border() {
  UP_LINE;
  RIGHT(MAX_WIDTH - 1);
  printf("|\n");
}

// Einene Operanden als short mit der Eingabeaufforderung 'prompt' einlesen
void read_operant(short *operand1, const char *prompt) {
  // Prüfvariabele => Wenn die Eingabe gültig ist, wird sie auf 1 gesetzt
  int valid_input = 0;

  // Eingabeaufforderung bis eine gültige Eingabe erfolgt
  do {
    printf("| %s", prompt);
    valid_input = scanf(" %hd", operand1);
    print_right_border();
    clear_stdin();
  } while (!valid_input);
}

// Überprüfen, ob der Operator zu den unterstützten Operationen gehört
int check_operation_str(char *operation) {
  const char operations[] = {'+', '-', '*', '/', '%', '&', '|', '<', '>', '^'};

  for (long unsigned int i = 0; i < sizeof(operations); i++) {
    // Wahrheitswert true, wenn der Operator in der Liste gefunden wird
    if (*operation == operations[i]) {
      return 1;
    }
  }

  return 0;
}

void read_operation(char *operation) {
  // Prüfvariabele => Wenn die Eingabe gültig ist, wird sie auf 1 gesetzt
  int valid_input = 0;

  // Eingabeaufforderung bis eine gültige Eingabe erfolgt
  do {
    printf("| Operator:\t");
    valid_input = scanf(" %c", operation);
    print_right_border();
    clear_stdin();
  } while (!valid_input || !check_operation_str(operation));
}

void read_user_data(short *operand1, short *operand2, char *operation) {
  // Rahmen mit Tietel und Leerzeile
  LINE;
  printf("| Bitoperatoren-Rechner\n");
  print_right_border();
  printf("| Operationen:  +  -  *  /  %%  &  |  ^  <  >\n");
  print_right_border();
  EMPTY_LINE;

  read_operant(operand1, "Zahl 1:\t");
  read_operation(operation);
  read_operant(operand2, "Zahl 2:\t");

  // Untere Leerzeile
  EMPTY_LINE;
}

int main() {

  // Variablen für die Operanden, den Operator und das Ergebnis
  short operand1, operand2, result;
  char operation;

  do {
    // Benutzer nach den Operanden und dem Operator fragen
    read_user_data(&operand1, &operand2, &operation);

    // Berechnung des Ergebnisses je nach Operator
    switch (operation) {
    case '+':
      result = (short)(operand1 + operand2);
      break;
    case '-':
      result = (short)(operand1 - operand2);
      break;
    case '*':
      result = (short)(operand1 * operand2);
      break;
    case '/':
      result = (short)(operand1 / operand2);
      break;
    case '%':
      result = (short)(operand1 % operand2);
      break;
    case '&':
      result = (short)(operand1 & operand2);
      break;
    case '|':
      result = (short)(operand1 | operand2);
      break;
    case '^':
      result = (short)(operand1 ^ operand2);
      break;
    case '<':
      result = (short)(operand1 << operand2);
      break;
    case '>':
      result = (short)(operand1 >> operand2);
      break;
    }

    // Ausgabe der Ergebnisse in einer Tabelle
    print_result_table(operand1, operand2, &operation, result);
  } while (check_continue());

  return 0;
}

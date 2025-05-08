//
// Dipl.Phys. Gerald Kempfer
// Berliner Hochschule für Technik
// University of Applied Sciences
// Fachbereich VI – Informatik und Medien
// Studiengang Technische Informatik Bachelor
//
// Nick Hildebrandt
// Matrikelnummer: 109071
// Abgabe: 23.05.25
//

#include <stdio.h>
#include <stdlib.h>

// Aufzählung der möglichen Rechenoperationen
typedef enum Operation {
  OPERATION_FIRST_FIRST,   // Platzhalter für untere Schranke (nicht benutzt)
  OPERATION_ADDITION,      // Addition
  OPERATION_SUBTRACTION,   // Subtraktion
  OPERATION_MULTIPICATION, // Multiplikation
  OPERATION_DIVISION,      // Division
  OPERATION_LAST_LAST      // Platzhalter für obere Schranke (nicht benutzt)
} Operation;

// Funktion zum Einlesen eines Operanden vom Benutzer
double read_op();

int main() {
  unsigned int op_read_int = 0; // Gewählte Rechenoperation (als Zahl)
  double op1;                   // Erster Operand
  double op2;                   // Zweiter Operand
  double ergebnis;              // Ergebnis der Berechnung
  int c;                        // Hilfsvariable zum Leeren des Eingabepuffers

  // Wiederhole die Abfrage, bis eine gültige Operation eingegeben wurde
  while (1) {
    printf("Wählen Sie zwischen folgenden Optionen:\n");
    printf("\t(1) Addieren\n\t(2) Subtrahieren\n\t(3) Multiplizieren\n\t(4) "
           "Dividieren\n");
    printf("Operation (Nr.): ");

    // Lese die Auswahl ein und überprüfe sie
    if (!scanf("%u", &op_read_int) || op_read_int < OPERATION_FIRST_FIRST + 1 ||
        op_read_int > OPERATION_LAST_LAST - 1) {

      // Leere den Eingabepuffer bei ungültiger Eingabe
      while ((c = getchar()) != '\n' && c != EOF) {
      }

      // Fehlermeldung ausgeben
      fprintf(stderr, "Falsche Eingabe\n");
      continue;
    }

    // Gültige Eingabe -> Schleife verlassen
    break;
  }

  // Zwei Operanden vom Benutzer einlesen
  op1 = read_op();
  op2 = read_op();

  // Berechnung abhängig von der gewählten Operation
  switch (op_read_int) {
  case OPERATION_FIRST_FIRST:
    break; // Wird nicht benutzt
  case OPERATION_ADDITION:
    ergebnis = op1 + op2;
    break;
  case OPERATION_SUBTRACTION:
    ergebnis = op1 - op2;
    break;
  case OPERATION_MULTIPICATION:
    ergebnis = op1 * op2;
    break;
  case OPERATION_DIVISION:
    ergebnis = op1 / op2;
    break;
  case OPERATION_LAST_LAST:
    break; // Wird nicht benutzt
  }

  // Ausgabe des Ergebnisses
  printf("Das Ergebnis ist: %lf\n", ergebnis);

  // Rückgabewert der main-Funktion (wird nie erreicht, da exit() vorher
  // aufgerufen wird)
  return 0;
}

// Funktion zum sicheren Einlesen eines Operanden (double) vom Benutzer
double read_op() {

  // Rückgabewert der Funktion
  double ret = 0.0;

  // Hilfsvariable zum Leeren des Eingabepuffers
  int c;

  // Wiederhole die Eingabeaufforderung, bis eine gültige Zahl eingegeben wurde
  while (1) {
    printf("Geben Sie einen Operanden ein: ");

    // Versuche, einen double-Wert einzulesen
    if (!scanf("%lf", &ret)) {
      fprintf(stderr, "Falsche Eingabe\n");

      // Eingabepuffer leeren, um fehlerhafte Eingaben zu ignorieren
      while ((c = getchar()) != '\n' && c != EOF) {
      }

      // Eingabe war ungültig -> erneut fragen
      continue;
    }

    // Gültiger Wert -> zurückgeben
    return ret;
  }
}

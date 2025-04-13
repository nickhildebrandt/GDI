//
// Dipl.Phys. Gerald Kempfer
// Berliner Hochschule für Technik
// University of Applied Sciences
// Fachbereich VI – Informatik und Medien
// Studiengang Technische Informatik Bachelor
//
// Nick Hildebrandt
// Matrikelnummer: 109071
// Abgabe: 16.05.25
//
// Aufgabe:
// Ziel dieser Übung ist es, die Anwendung von if - Abfragen und Schleifen zu
// vertiefen, indem ein benutzerfreundliches C - Programm erstellt wird, das
// eine ganze Zahl vom Nutzer einliest, sie wieder ausgibt und anschließend
// abfragt, ob eine weitere Eingabe erfolgen soll.Dabei steht neben der reinen
// Funktionalität auch die Eingabesicherung im Vordergrund : Das Ergebnis von
// scanf muss ausgewertet werden, um ungültige Eingaben(z. B.Buchstaben)
// abzufangen, und der Tastaturpuffer ist nach jeder Eingabe vollständig zu
// leeren, um Folgefehler zu vermeiden.Das Programm soll klare Anweisungen und
// Fehlermeldungen ausgeben und wird über eine Make - Datei kompiliert, gelinkt
// und gestartet.

#include <stdio.h>
#include <stdlib.h>

int main() {

  // Ganzzahl Benutzereingabe
  int eingabe = 0;

  // Buchstabe aus der Benutzereingabe, welcher wenn 'y' das Programm fortsetzt
  char weiter;

  // Variable zum Leeren des Eingabepuffers
  int c;

  // Endlosschleife, die nur durch 'exit(0)' verlassen wird
  while (1) {

    // Aufforderung zur Eingabe einer Ganzzahl
    printf("Geben Sie bitte eine ganze Zahl ein: ");

    // Überprüfen, ob eine gültige Ganzzahl eingelesen wurde
    if (!scanf(" %d", &eingabe)) {

      // Eingabepuffer leeren, damit fehlerhafte Eingaben keine Folgefehler
      // verursachen
      while ((c = getchar()) != '\n' && c != EOF) {
      }

      // Fehlermeldung ausgeben (auf stderr)
      fprintf(stderr, "Fehlerhafte Eingabe\n");
      continue; // Schleife von vorn beginnen
    }

    // Die erfolgreich eingelesene Ganzzahl ausgeben
    printf("Die Eingabe war %d\n", eingabe);

    // Benutzer fragen, ob er eine weitere Eingabe tätigen möchte
    printf("Wollen Sie nochmal eingeben? (y/n): ");

    // Die Eingabe für 'weiter' einlesen.
    // Das Leerzeichen vor %c ignoriert führende Whitespaces (z. B. \n vom
    // vorherigen scanf)
    if (!scanf(" %c", &weiter)) {
      fprintf(stderr, "Fehlerhafte Eingabe\n");
      continue; // Schleife von vorn beginnen
    }

    // Wenn der Benutzer nicht 'y' eingegeben hat, Programm beenden
    if (weiter != 'y') {
      exit(0);
    }
  }

  // Rückgabewert der main-Funktion (wird nie erreicht, da exit() vorher
  // aufgerufen wird)
  return 0;
}

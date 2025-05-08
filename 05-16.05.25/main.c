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

#include <stdio.h>

// Funktion zum Leeren des Eingabepuffers
void clear_input_buffer(void) {
    int c;
    // Liest Zeichen, bis ein Zeilenumbruch oder das Dateiende erreicht ist
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {

    // Speichert, ob der Benutzer weitermachen möchte (j/n)
    char continue_input;

    // Speichert, ob die Eingabe erfolgreich war
    int input_valid;

    // Speichert den vom Benutzer eingegebenen Zahlenwert
    double input_value;

    // Hauptschleife: Wiederholt die Eingabe, solange der Benutzer 'j' eingibt
    do {
        // Benutzer zur Eingabe auffordern
        printf("Geben Sie bitte eine ganze Zahl ein: ");

        // Versucht, eine Gleitkommazahl einzulesen
        input_valid = scanf(" %lf", &input_value);

        // Leert den Eingabepuffer um nicht eingelesene Zeichen
        clear_input_buffer();

        // Wenn die Eingabe gültig war
        if (input_valid) {
            // Gibt den eingegebenen Wert aus
            printf("Sie haben %lf eingegeben\n", input_value);
        }
        else {
            // Fehlermeldung bei ungültiger Eingabe
            printf("Falsche Eingabe! Die Eingabe ist keine ganze Zahl!\n");
        }

        // Schleife zur Abfrage, ob der Benutzer weitermachen möchte
        do {
            printf("Möchten Sie noch einmal? (j/n) ");

            // Liest ein einzelnes Zeichen für die Entscheidung ein
            scanf(" %c", &continue_input);

            // Eingabepuffer um nicht eingelesene Zeichen leeren
            clear_input_buffer();

            // Wiederholung der Eingabeaufforderung, bis die Eingabe gültig ist
        } while (continue_input != 'j' && continue_input != 'n');

        // Wiederholle wenn der benutzer in der vorherigen Eingabe  Schleife
        // 'j' eingegeben hat
    } while (continue_input == 'j');

    // Programm beenden
    return 0;
}


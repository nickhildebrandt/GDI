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

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#include "matrix.h"
#include "escapesequenzen.h"
#include "tools.h"

int const MaxRows = 16;
int const MaxColumns = 16;

int getNumberOfRows(int Row, int Col, int MatrixNo) {
    // Prompt für die Anzahl der Zeilen der Matrix
    char *prompt = "Geben Sie die Anzahl der Zeilen der Matrix %i ein: ";

    // Leerer String für die Fromatierte Eingabeaufforderung
    char *prompt_fmt = str_printf(prompt, MatrixNo);

    // Ermittelter Wert für die Anzahl der Zeilen (Rückgabewert)
    int row_count = 0;

    // Prüfen ob die Formatierte Eingabeaufforderung erfolgreich erstellt wurde
    if (!prompt_fmt) {
        // Falls die Dynamische Speicherallokation fehlschlägt, wird eine
        // Fehlermeldung ab Row/Col ausgegeben und das Programm beendet
        POSITION(Row, Col);
        perror("str_printf");
        exit(1);
    }

    // Benutzeraufforderung für die Anzahl der Zeilen der Matrix
    read_operant(&row_count, prompt_fmt, 1, MaxRows, Row, Col);

    // Freigabe des dynamisch allokierten Speichers
    free(prompt_fmt);

    // Rückgabe der Anzahl der Zeilenanzahl
    return row_count;
}

int getNumberOfColumns(int Row, int Col, int MatrixNo) {
    // Prompt für die Anzahl der Spalten der Matrix
    char *prompt = "Geben Sie die Anzahl der Spalten der Matrix %i ein: ";

    // Leerer String für die Fromatierte Eingabeaufforderung
    char *prompt_fmt = str_printf(prompt, MatrixNo);

    // Ermittelter Wert für die Anzahl der Spalten (Rückgabewert)
    int col_count = 0;

    // Prüfen ob die Formatierte Eingabeaufforderung erfolgreich erstellt wurde
    if (!prompt_fmt) {
        // Falls die Dynamische Speicherallokation fehlschlägt, wird eine
        // Fehlermeldung ab Row/Col ausgegeben und das Programm beendet
        POSITION(Row, Col);
        perror("str_printf");
        exit(1);
    }

    // Benutzeraufforderung für die Anzahl der Spalten der Matrix
    read_operant(&col_count, prompt_fmt, 1, MaxColumns, Row, Col);

    // Freigabe des dynamisch allokierten Speichers
    free(prompt_fmt);

    // Rückgabe der Anzahl der Spalten
    return col_count;
}

// Leere Matrix für Row/ColCount auf dem Bildschirm ausgeben
static void print_empty_matrix(int rows, int columns,
                               int Row, int Col) {
    char *placeholder = "____";

    // Schleife für die Zeilen
    for (int i = 0; i < rows; i++) {
        POSITION(Row + i, Col);
        // Rahmen links
        printf("|");

        // Schleife für die Spalten
        for (int j = 0; j < columns; j++) {
            printf(" %s", placeholder);
        }

        // Rahmen rechts
        printf(" |");
    }
}

void getMatrix(int Row, int Col, int RowCount, int ColCount,
               int Matrix[MaxRows][MaxColumns]) {
    // Variabler für die aktuelle Curserposition
    int current_row = 0;
    int current_col = 0;

    // Leere Matrix auf dem Bildschirm ausgeben
    print_empty_matrix(RowCount, ColCount, Row, Col);

    // Schleife für die Zeilen
    for (int i = 0; i < RowCount; i++) {
        // Position für die aktuelle Zeile setzen und einrückung durch den
        // Rahmen links beachten
        current_col = Col + 2;
        current_row = Row + i;
        POSITION(current_row, current_col);

        // Schleife für die Spalten
        for (int j = 0; j < ColCount; j++) {
            // Ganzahl in das Matrixfeld von aktueller Zeile und Spalte lesen
            read_operant(&Matrix[i][j], NULL,
                         -999, 9999,
                         current_row, current_col
            );

            // Position für das nächste Matrixfeld in der Zeile setzen
            current_row = Row + i;
            current_col = Col + 2 + (j + 1) * 5;
            POSITION(current_row, current_col);
        }
    }
}

// Zwei Matrixen multiplizieren und das Ergebnis im Parameter MErg speichern
void calcMatrix(int RowCount1, int ColCount1, int ColCount2,
                int M1[MaxRows][MaxColumns], int M2[MaxRows][MaxColumns],
                int MErg[MaxRows][MaxColumns]) {
    // Schleife für die Zeilen der ersten Matrix
    for (int i = 0; i < RowCount1; i++) {
        // Schleife für die Spalten der zweiten Matrix
        for (int j = 0; j < ColCount2; j++) {

            // Ergebnis der Multiplikation auf 0 setzen
            // falls die Matrixen nicht multipliziert werden können
            // und ein incompatibles Größenverhältnis vorliegt bzw.
            // Eine Matrix leer ist
            MErg[i][j] = 0;

            // Zeile matrix 1 und Spalte Matrix 2 multiplizieren
            for (int k = 0; k < ColCount1; k++) {
                // Addieren der Multiplikationsergebnisse bis zum Zeilenende
                MErg[i][j] += M1[i][k] * M2[k][j];
            }
        }
    }
}

// Hilfsfunktion für printMatrix um die Länge ausgabe von Ergebnissen von bis
// zu 9 stellen zu ermöglichen
static void printMatrixResult(int Row, int Col, int RowCount, int ColCount,
                    int Matrix[MaxRows][MaxColumns]) {
    // Schleife für die Zeilen der Matrix ausgabe
    for (int i = 0; i < RowCount; i++) {

        // Position der Zeilenausgabe gemäß der Parameter Row/Col setzen
        POSITION(Row + i, Col);

        // Rahmen links
        printf("|");

        // Schleife für die Spalten
        for (int j = 0; j < ColCount; j++) {
            // Formatierte Ausgabe der Matrixwerte mit 9 stellen da das
            // Ergebnis bei eingabewerten von -999 bis 9999 zwischen
            // -99,980,001 und 99,980,001 liegt
            printf(" %9i", Matrix[i][j]);
        }

        printf(" |");
    }
}

void printMatrix(int Row, int Col, int RowCount, int ColCount,
                 int Matrix[MaxRows][MaxColumns]) {

    // Überprüfen ob ein parameter länger als 4 Zeichen ist
    // d.h. ob er größer als 9999 oder kleiner als -999 ist
    for (int i = 0; i < RowCount; i++) {
        for (int j = 0; j < ColCount; j++) {
            if (Matrix[i][j] > 9999 || Matrix[i][j] < -999) {
                // Falls ja, wird die Hilfsfunktion für die Ausgabe
                // der Matrixergebnisse aufgerufen
                printMatrixResult(Row, Col, RowCount, ColCount, Matrix);
                return;
            }
        }
    }

    // Schleife für die Zeilen der Matrix ausgabe
    for (int i = 0; i < RowCount; i++) {

        // Position der Zeilenausgabe gemäß der Parameter Row/Col setzen
        POSITION(Row + i, Col);

        // Rahmen links
        printf("|");

        // Schleife für die Spalten
        for (int j = 0; j < ColCount; j++) {

            // Bildschgirmausgabe der Matrixwerte mit 4 stellen
            printf(" %4i", Matrix[i][j]);
        }

        // Rahmen rechts
        printf(" |");
    }
}

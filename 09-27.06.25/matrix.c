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

int const MaxRows = 9;
int const MaxColumns = 9;

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

// An eine Position Row/Col in der matrix eine Zahl schreiben
static void print_matrix_pos();

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

void calcMatrix(int RowCount1, int ColCount1, int ColCount2,
                int M1[MaxRows][MaxColumns], int M2[MaxRows][MaxColumns],
                int MErg[MaxRows][MaxColumns]) {
    return;
}

void printMatrix(int Row, int Col, int RowCount, int ColCount,
                 int Matrix[MaxRows][MaxColumns]) {
    return;
}

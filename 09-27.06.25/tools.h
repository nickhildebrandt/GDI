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

#ifndef TOOLS_H
#define TOOLS_H

void clearBuffer();

int askAgain(int Row, int Col);

void read_operant(int *operand, const char *prompt,
                  int min, int max,
                  int row, int col);

char *str_printf(const char *fmt, ...);

#endif // TOOLS_H

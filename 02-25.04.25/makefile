#
# Dipl.Phys. Gerald Kempfer
# Berliner Hochschule für Technik
# University of Applied Sciences
# Fachbereich VI – Informatik und Medien
# Studiengang Technische Informatik Bachelor
#
# Nick Hildebrandt
# Matrikelnummer: 109071
# Abgabe: 25.04.25
#
# Aufgabe:
# In dieser Übung geht es darum, den Umgang mit Make-Dateien zu erlernen. Nach
# einer theoretischen Einführung (Kapitel 3 des Skripts „Compilieren und Linken
# von C- und C++-Dateien“) und dem Anschauen zweier Übungsvideos sollen Sie
# selbst zwei Make-Dateien erstellen und testen. Eine davon soll das
# schrittweise Ankleiden modellieren, wobei bestimmte Kleidungsstücke nur nach
# vorherigem Anziehen anderer Teile „angezogen“ werden dürfen – dargestellt
# durch Abhängigkeiten. Jeder Schritt gibt mit @echo aus, was gerade angezogen
# wird, und aktualisiert mit @touch $@ die zugehörige Datei. Zusätzlich soll
# das Target Nackt alle erstellten Dateien wieder löschen. Das Ziel ist, bei
# make die korrekte Ankleidereihenfolge gemäß den Abhängigkeiten abzubilden und
# auch Einzelschritte wie make Hose zu ermöglichen. Groß-/Kleinschreibung der
# Dateinamen muss beachtet werden.

Anziehsachen := Mantel \
		Schuhe \
		Handy \
		Pullover \
		Hose \
		Hemd \
		Struempfe \
		Unterhose \
		Unterhemd

.PHONY: Nackt

Mantel: Schuhe Handy Pullover
	@echo $@ anziehen
	touch $@

Schuhe: Struempfe Hose
	@echo $@ anziehen
	touch $@

Handy: Hose
	@echo $@ anziehen
	touch $@

Pullover: Hemd
	@echo $@ anziehen
	touch $@

Hose: Hemd Unterhose
	@echo $@ anziehen
	touch $@

Hemd: Unterhemd
	@echo $@ anziehen
	touch $@

Struempfe:
	@echo $@ anziehen
	touch $@

Unterhose:
	@echo $@ anziehen
	touch $@

Unterhemd:
	@echo $@ anziehen
	touch $@

Nackt:
	rm -f $(Anziehsachen)

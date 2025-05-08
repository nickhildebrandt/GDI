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

Anziehsachen := Mantel \
		Schuhe \
		Handy \
		Pullover \
		Hose \
		Hemd \
		Struempfe \
		Unterhose \
		Unterhemd

.PHONY: Nackt clean Mantel

Mantel: Schuhe Handy Pullover
	@echo $@ anziehen
	@touch $@

Schuhe: Struempfe Hose
	@echo $@ anziehen
	@touch $@

Handy: Hose
	@echo $@ anziehen
	@touch $@

Pullover: Hemd
	@echo $@ anziehen
	@touch $@

Hose: Hemd Unterhose
	@echo $@ anziehen
	@touch $@

Hemd: Unterhemd
	@echo $@ anziehen
	@touch $@

Struempfe:
	@echo $@ anziehen
	@touch $@

Unterhose:
	@echo $@ anziehen
	@touch $@

Unterhemd:
	@echo $@ anziehen
	@touch $@

Nackt:
	rm -f $(Anziehsachen)

clean: Nackt

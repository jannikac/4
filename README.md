# Aufgaben 3 - Funktionen und Klassen

Hier befinden sich die für die Veranstaltung modernes C++ bearbeiteten Aufgaben.
Zum Erstellen wurde Clang in der Version 13.0.0 und CMake verwendet.

Textaufgaben befinden sich in: `doku.md` oder `doku.pdf`.

## Build

### C++

Repository clonen:

```bash
git clone https://github.com/jannikac/4.git
```

Build mit CMake erstellen:

```bash
cmake --build build/
```

Erstellte ausführbare Datei befindet sich in: `build/{Repo-Name}`.

### Markdown Doku

Erstellen mit `pandoc` und Template `Eisvogel`.

```bash
pandoc doku.md -o doku.pdf --from markdown --template eisvogel --listings
```

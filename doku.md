# Aufgaben 4 - Funktionen und Klassen

## Aufgabe 1

### a)

```cpp
double ()(double, double, double);
```

```cpp
void ()(float&, float&, float (*)(float&, float&), float*);
```

```cpp
void ()(const std::vector<float> &, const std::vector<float> &, std::vector<float> &)
```

```cpp
C (*translate)(const C &)

translate ()(C, translate_type)
```

### b)

```cpp
window::window();
```

```cpp
window::window(int width, int height);
```

```cpp
window::window(const std::string &heading);
```

```cpp
window::window(const window &child_window);
```

```cpp
window::window(const std::vector<child_window> &child_windows);
```

```cpp
window::window(const std::string &path);
```

## Aufgabe 2

### a)

### b)

Die Felder `base_path_`, `file_name` und `full_path` sind zwar vom Typ String, werden aber nie initialisiert. Die Initializer-List ruft nicht den default-Konstruktor der `std::string` Klasse auf. Aus diesem Grund könnten die Member-Variablen auf alles mögliche Zeigen. Wird versucht auf nicht initialisierten Speicher zuzugreifen, was ein `segfault` auslöst.

### c)

Der String.hpp Header sollte nicht im string_shared_pointer.hpp Header eingebunden werden, sondern im string_shared_pointer.cpp. Durch die Vorwärtsdeklaration sind die Klassendetails im Header unbekannt und die Einbindung der string.hpp muss in der string_shared_pointer.cpp erfolgen, da dort die Implementierung erfolgt.

### e)

#### Beispiel 1

Korrektes Verhalten. Es sollte allerdings auf die Inclusion Guards geachtet werden, damit keine Redefinition von `a()` auftritt. Außerdem sollte eine Funktion in einer CPP-Datei definiert werden und in einem Header nur deklariert.

#### Beispiel 2

Im Präprozessor wird die Header-Datei in die `.cpp` Datei eingefügt. Läuft jetzt der Compiler stellt dieser fest, dass in einer Datei die Funktion `b()` mehrfach definiert wird und gibt als Fehler `redefinition of int b()` aus.

#### Beispiel 3

Hier entsteht der Linker-Fehler `multiple definition of d(float)`, da die CPP-Dateien Modulweise kompiliert werden, entsteht beim Compiler kein Fehler. Erst beim Verbinden der DAteien durch denk Linker entsteht ein Fehler, da mehrere Dateien die gleiche Funktion definieren.

#### Beispiel 4

Schon eine Definition in einer CPP Datei ist nicht möglich, da die Klasse in der Header-Datei schon definiert wurde. Der Kompiler gibt einen Fehler aus, da die Methode(n) der Klasse redefiniert werden.

#### Beispiel 5

Der Code einer inline-Funktion wird vom Compiler direkt an der Stelle eingefügt, wo der Aufruf stattfindet. Damit entfällt der Sprung in ein Unterprogramm. Wenn die Header-Datei an mehreren Stellen eingebunden wird, entstehen somit identische Funktionen, die unterschiedliche Sachen machen, was undefiniertes Verhalten darstellt. C++ Standard 03: 3.2 One definition rule [basic.def.odr] Para 1: `No translation unit shall contain more than one definition of any variable, function, class type, enumeration type or template.`

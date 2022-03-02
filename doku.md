---
title: "Aufgaben 2 - Zeigerarithmetik"
author: [Jannik Steinbach, Thore Böger, Johannes Städter]
date: "26. 01. 2022"
...

# Aufgaben 4 - Funktionen und Klassen

Aktualisierte `string`, `string_shared_pointer`, `string_weak_pointer` und `rc` Klassen können Sie auch im `src` Ordner finden.

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

Hier tritt ein Segmentation Fault auf. Es wird also versucht auf nicht zugreifbaren Speicher zuzugreifen. Leider konnten wir nicht genau bestimmen warum. Eine Vermutung war, dass der Vektor zwar deklariert, aber nicht initialisiert wurde und die Variablen somit auf nicht initialisierten Speicher zeigen, was einen Segfault auslöst.

### b)

Die Felder `base_path_`, `file_name` und `full_path` sind zwar vom Typ String, werden aber nie initialisiert. Die Initializer-List ruft nicht den default-Konstruktor der `std::string` Klasse auf. Aus diesem Grund könnten die Member-Variablen auf alles mögliche Zeigen. Wird versucht auf nicht initialisierten Speicher zuzugreifen, was ein `segfault` auslöst.

### c)

Der String.hpp Header sollte nicht im string_shared_pointer.hpp Header eingebunden werden, sondern im string_shared_pointer.cpp. Durch die Vorwärtsdeklaration sind die Klassendetails im Header unbekannt und die Einbindung der string.hpp muss in der string_shared_pointer.cpp erfolgen, da dort die Implementierung erfolgt.

### d)

#### Copy-Konstruktor

```cpp
string::string(const string &other) {
  str = (char *)malloc(sizeof(char) * other.length);
  strcpy(str, other.str);
  length = other.length;
}
```

#### Move-Konstruktor

```cpp
string::string(string &&other) {
  str = (char *)malloc(sizeof(char) * other.length);
  str = other.str;
  length = other.length;

  other.str = nullptr;
}
```

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

## Aufgabe 3

### a)

#### Beispiel 1

Es kommen nur Funktion `D` und `C` in Frage, da `s`c eine konstante Referenz auf ein `seed` ist. Nur bei `D` und `C` wird ein `const seed&` als parameter akzeptiert. Da `f` nicht `const` ist, kommt nur Methode `C` infrage.

#### Beispiel 2

Da `t` nicht konstant ist, kommt von den Parametern her nur die Funktion `E` infrage. Hier tritt ein Compilerfehler auf, da `fc` konstant ist und die Funktion `E` selbst nicht konstant ist.

#### Beispiel 3

Hier kommen nur `A` und `B` infrage, da nur diese einen nicht konstanten `seed` akzeptieren. Da `fc` konstant ist, wird Funktion `B` ausgeführt.

#### Beispiel 4

Es kommt nur Funktion `F` infrage, da nur diese eine `const tree&` akzeptiert.

#### Beispiel 5

Es kommen nur Funktion `D` und `C` in Frage, da `sc` eine konstante Referenz auf ein `seed` ist. Nur bei `D` und `C` wird ein `const seed&` als Parameter akzeptiert. Da `fc` konst ist, wird hier die Funktion `D` aufgerufen.

#### Beispiel 6

Es kommen nur Funktion `A` und `B` infrage, da nur diese einen nicht konstanten `seed` akzeptieren. Da `f` nicht konstant ist, wird Funktion `A` aufgerufen.

### b)

In Aufgabenblatt 2 und 3 bereits erledigt.

### c)

#### string.cpp

`find` Methode ändert String nicht, deshalb `const`.

```cpp
int string::find(char c) const {...}
```

`print` ändert String nicht.

```cpp
void string::print() const {...}
```

##### string_shared_ptr.cpp und string_weak_ptr.cpp

`getWeakCount()` und `getStrongCount()` der `rc` Klasse können `const` sein, da diese das Objekt nicht ändern.

### d)

Falls der `string` selber `const` ist, soll `data()` einen zeiger auf einen `const` internen `str` zurückgeben, also:

```cpp
const char *string::data() const { return str; }
```

### e)

Mit der internen append() Funktion umgesetzt:

```cpp
string string::operator+(const string &other) {
  string result = string(str);
  result.append(other.str);
  return result;
};
```

### f)

In der ersten Zeile wird versucht 2 `char`-Arrays miteinander zu verketten, was so nich funktionieren sollte, da `char`-Arrays keinen `+ Operator` implementieren. Am Ende wird das Ganze Konstrukt an `std::cout` übergeben.

In der zweiten Zeile wird eine leere `string` Instanz erstellt und über die `+ Operatoren` miteinander verknüpft. Das sollte funktionieren, da der überladene `+ Operator` der `string` Instanz bzw. Klasse aufgerufen werden sollte. Am Ende wird das Ganze Konstrukt an `std::cout` übergeben.

### g)

Hier wurde auch 1 überladung der `.at()` bzw des `[]` operators eingebaut. Die überladung gibt korrekt weiter, wann ein Objekt `const` ist und wann nicht. Somit kann bei einem const string dieser nicht mit z.B. `[]` beschrieben werden.

Die `.at()` Methode vergleicht die Länge mit dem Index, damit ein out-of-bounds read bzw. write verhindert wird.

```cpp
// Kann nur für lesenden Zugriff genutzt werden -> rvalue
const char &string::operator[](const int index) const { return str[index]; };

const char &string::at(const int index) const {
  // Werfen, wenn index out of range
  if (index >= length)
    throw std::out_of_range("index is greater or equals to length");
  return str[index];
};

// Kann für schreibenden Zugriff genutzt werden -> lvalue
char &string::operator[](const int index) { return str[index]; };

char &string::at(const int index) {
  // Werfen, wenn index out of range
  if (index >= length)
    throw std::out_of_range("index is greater or equals to length");
  return str[index];
};
```

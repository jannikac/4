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
&C ()(C, translate_type)
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
window::create_child_window();
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

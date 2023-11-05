# Zaliczenie Laboratorium II
Masz daną klasę `Resource`, która:

- posiada konstruktor domyślny
- posiada 5 dobrze zdefiniowanych metod specjalnych
- posiada metodę o sygnaturze `double get()`
- jest duża, tzn. wartość `sizeof(Resource)` jest większa niż rozmiar stosu

Klasa ta symuluje duży, kosztowny w konstrukcji zasób.
Metoda `get` symuluje wykorzystanie takiego zasobu (np. pobranie wartości zmiennoprzecinkowej z serwera).

Twoim zadaniem jest napisanie klasy `ResourceManager`, która:

- jest właścicielem (czyt. zarządza) obiektu typu `Resource`
- posiada metodę `double get()`, która zwraca wynik zawołania metody `get` obiektu, którym zarządza
- posiada konstruktor domyślny, który inicjalizuje zarządzany obiekt przy pomocy domyślnego konstruktora klasy `Resource`
- posiada 5 dobrze zdefiniowanych metod specjalnych
- jest mała, tzn. mieści się na stosie

Krótko mówiąc, `ResourceManager` ma być klasą RAII, która zarządza obiektem `Resource`.
Testy weryfikujące poprawność wykonania zadania będą sprawdzały następujące 3 kryteria:

1. Brak wycieków pamięci (2 punkt)
2. Poprawne kopiowanie (3 punkty)
3. Poprawne przenoszenie (0 punkty) - zadanie dodatkowe

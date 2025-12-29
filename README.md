# 🏰 C++ SFML Tower Defense

Klasyczna gra strategiczna typu Tower Defense, napisana od podstaw w C++ z wykorzystaniem biblioteki **SFML**.

Głównym celem projektu nie była sama rozgrywka, lecz **demonstracja solidnych praktyk programistycznych**, ze szczególnym naciskiem na **Programowanie Obiektowe (OOP)**, dziedziczenie i polimorfizm.

## 🎮 Funkcjonalności

* **🏗️ Budowanie:** Możliwość stawiania różnych typów wież obronnych.
* **⬆️ Upgrade System:** Mechanika ulepszania postawionych struktur (zwiększanie zasięgu/obrażeń).
* **👾 Przeciwnicy:** 3 unikalne rodzaje wrogów o różnych statystykach.
* **💰 Ekonomia:** System zarabiania pieniędzy za eliminację wrogów i inwestowania w obronę.

## 💻 Architektura i Kod

Projekt został zaprojektowany z myślą o czystej architekturze:

* **Dziedziczenie i Polimorfizm:**
    * Konkretne typy wież i wrogów dziedziczą po klasach nadrzędnych, nadpisując metody `Update()` czy `Draw()`.
* **Enkapsulacja:** Logika gry oddzielona od warstwy renderowania.
* **Zarządzanie pamięcią:** Świadome operowanie na wskaźnikach i referencjach.

## ⚠️ Status Projektu (WIP)

Gra znajduje się w fazie prototypu ("Developer Art"):
* Grafika jest obecnie **symboliczna/zastępcza** (placeholder art).
* Balans rozgrywki (koszty, obrażenia) może wymagać dostrojenia.

## 🛠️ Technologie

* **Język:** C++
* **Biblioteka:** [SFML](https://www.sfml-dev.org/) (Graphics, Window, System)

*Projekt stworzony w celach edukacyjnych.*

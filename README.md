# Calculator Distanță Levenshtein

## Prezentare Generală

Acest proiect calculează distanța Levenshtein între două șiruri de caractere introduse de utilizator. Distanța Levenshtein măsoară numărul minim de editări de un singur caracter (inserții, ștergeri sau substituții) necesare pentru a transforma un cuvânt în altul.

## Structura Fișierelor

- `main.c`: Conține funcția principală pentru interacțiunea cu utilizatorul.
- `levensthein_alg.c`: Contine implementarea calcului distantei Levenshtein intre doua siruri
- `string_generator.c`: Contine implementarea generarii a doua siruri de caractere cu lungime de maxim 30 caractere

## Dependențe

- Biblioteca standard C (`<stdio.h>`, `<string.h>`, `<stdlib.h>`)

## Gestionarea memoriei

Programul alocă dinamic memorie pentru matricea 2D a distanțelor pentru a gestiona șiruri de lungimi variabile. Această memorie este eliberată corect după calcul pentru a preveni scurgerile de memorie.

## Note

Șirurile de intrare sunt limitate la 255 de caractere fiecare. Acest lucru poate fi ajustat modificând dimensiunea bufferului din funcția main.
Caracterul de newline de la intrarea fgets este eliminat pentru a asigura o comparație corectă a șirurilor.

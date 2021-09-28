# Blokų grandinių technologijos 1 užduotis
# Hash generatorius

## Užduotis

* Maišos funkcijos įėjimas (angl. input) gali būti bet kokio dydžio simbolių eilutė (angl. string).
* Maišos funkcijos išėjimas (angl. output) visuomet yra to paties, fiksuoto, dydžio rezultatas (pageidautina 256 bit'ų ilgio, t.y., 64 simbolių
hex'as).
* Maišos funkcija yra deterministinė, t. y., tam pačiam įvedimui (input'ui) išvedimas (output'as) visuomet yra tas pats.
* Maišos funkcijos reikšmė/kodas (hash‘as) bet kokiai input'o reikšmei yra apskaičiuojamas greitai - efektyviai.
* Iš hash funkcijos rezultato (output'o) praktiškai neįmanoma atgaminti pradinio įvedimo (input'o).
* Maišos funkcija yra atspari "kolizijai" (angl. collision resistance), t.y., praktiškai neįmanoma surasti tokių dviejų skirtingų argumentų
, kad jiems gautume tą patį hash'ą.
* Bent minimaliai pakeitus įvedimą, pvz.vietoj "Lietuva" pateikus "lietuva", maišos funkcijos rezultatas-kodas turi skirtis iš esmės, t.y.,
tenkinamas taip vadinamas lavinos efektas (angl. Avalanche effect).

## Įdiegimo ir naudojimo instrukcija

* Įdiegimas
  * Iš skilties "releases" pasirinkti norimą programos versiją ir atsisiųsti
  * Atsisiųstą kodą sukompiliuoti per komandinę eilutę (CMD) arba naudojamu IDE
  ```
  g++ -o programa main.cpp functions.cpp
  ```
  * Paleisti gautą vykdomąjį failą (.exe)
  ```
  ./programa
  Arba tiesiog atidaryti .exe failą tame aplanke kur atsisiuntėte programą
  ```
  
* Naudojimas
  * Pasirinkti vieną iš programos pradžioje pateikiamų funkcijų:
  * Įvedant failo pavadinimą galūnės ".txt" pridėti nereikia.

## Eksperimentinis tyrimas-analizė
#### Palyginame dviejų failų "test1a.txt"  ir "test1b.txt", kuriuose įvesta po vieną skirtingą simbolį, gaunamą hex'ą:
![image](https://user-images.githubusercontent.com/72629961/135138277-d9784bd4-7c57-46dc-92d2-eaa8c5218ca3.png)

# IZP-PasswordChecker
Program, ktorý na vstupe dostane sadu hesiel a pre každé z nich overí, či heslo spĺňa všetky (pevne zadané) požadované pravidlá. Heslá, ktoré prejdú kontrolou, budú vypísané na výstup, ostatné budú zahodené.Implementačné detaily

## Obsah 
* [Použité programy](#použité-programy)
* [Kompilácia](#kompilácia)
* [Syntax spustenia](#syntax-spustenia)
* [Implementačné detaily](#implementačné-detaily)
* [Obmedzenia projektu](#obmedzenia-projektu)

## Použité programy
*  C: 17
* Ubuntu: 22.04 LTS

## Kompilácia
`$ gcc -std=c99 -Wall -Wextra -Werror pwcheck.c -o pwcheck`

## Syntax spustenia 
`$ ./pwcheck LEVEL PARAM [--stats]`
* **LEVEL** = celé číslo v intervale [1, 4], ktoré určuje požadovanú *úroveň bezpečnosti*
* **PARAM** = kladné celé číslo, ktoré určuje dodatočný parameter pravidiel 
* **--stats** = ak je zadané, určuje, či sa na konci programu majú vypísať súhrnné štatistiky analyzovaných hesiel

#### Úrovne bezpečnosti
Sú definované celkom 4 úrovne bezpečnosti vyjadrené pomocou 4 pravidiel. Úroveň bezpečnosti určuje, že hesla musia spĺňať všetky pravidlá na danej a nižšej úrovni. Tzn. napr. úroveň bezpečnosti 3 špecifikuje, že heslá musia spĺňať pravidlá 1, 2 a 3.

Niektoré pravidla sú parametrizovatelné celým číslom zadaným pomocou argumentu programu PARAM. V následujúcom zozname je tento parameter označený ako **X**.

* Heslo obsahuje aspoň 1 velké a 1 malé písmeno.
* Heslo obsahuje znaky z alespoň **X** skupin (v případe, že je číslo **X** väčšie než 4, myslia sa tým všetky skupiny). Uvažované skupiny sú:

       * malá písmena (a-z)
       * velká písmena (A-Z)
       * čísla (0-9)
       * speciální znaky (podporované musí být alespoň nealfanumerické znaky z ASCII tabulky na pozicích 33-126 32-126, tedy včetně mezery)
* Heslo neobsahuje sekvenci stejných znaků délky alespoň X.
* Heslo neobsahuje dva stejné podřetězce délky alespoň X.

#### Štatistiky 
Ak je zadaný argument programu **--stats**, program musí na koniec výstupu vypísať celkové štatistiky vo formáte:
![Screenshot 2022-04-28 132545](https://user-images.githubusercontent.com/101285328/165745283-35f67f22-b66b-42bb-9568-9551ec1c7d31.png)

## Implementačné detaily
#### Vstupné dáta (zoznam hesiel)
Zoznam hesiel je programu predaný na štandardnom vstupe (stdin). Každé heslo je zadané na samostatnom riadku a obsahuje iba ASCII textové dáta, okrem znaku nového riadku. Maximálna dĺžka hesla je 100 znakov, inak sa jedná o nevalidné data. Program podporuje neobmedzený počet hesiel na vstupe.
#### Výstupné dáta 
Program na štandardný výstup (stdout) vypisuje hesla zo vstupného zoznamu, každé na samostatný riadok, ktoré spĺňajú požadovanú úroveň bezpečnosti zadanú ako argument programu LEVEL. Heslá musia býť vypísané bez zmeny a v rovnakom poradí, v akom sa objevili na vstupe.
#### Príklady vstupu a výstupu
* Pomocný súbor so zoznamom hesiel:![Screenshot 2022-04-28 140538](https://user-images.githubusercontent.com/101285328/165748347-fd888526-16be-4613-a47c-277f8a77c986.png)
* Príklad spustenia:![Screenshot 2022-04-28 140538](https://user-images.githubusercontent.com/101285328/165749458-5a6cd652-d0cb-4f80-87ea-a9a4e57a7053.png)

## Obmedzenia projektu
Bolo zakázané použít následujúce funkcie:

* volánie funkcí z knižníc string.h a ctype.h - cieľom projektu bolo naučit sa implementovať dané funkcie ručne,
* volanie z rodiny malloc a free - práca s dynamickou pamäťou nebola v tomto projekte potrebná,
* volanie z rodiny fopen, fclose, fscanf, ... - práca so súbormi (dočasnými) nebola v tomto projekte žiadúca,
* volanie funkcie exit - cieľom projektu bolo naučiť sa vytvoriť programové konštrukcie, ktoré dokážu spracovať neočakávaný stav programu a prípadne program ukončiť návratom z funkcie main.

*Program musí vyhovovať štandardu ISO C99. Sú povolené iba hlavičkové súbory: stdio.h, stdlib.h, stdbool.h a prípadně: assert.h, errno.h a limits.h.*



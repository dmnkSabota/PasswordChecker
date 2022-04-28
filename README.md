# IZP-PasswordChecker
Program, ktorý na vstupe dostane sadu hesiel a pre každé z nich overí, či heslo spĺňa všetky (pevne zadané) požadované pravidlá. Heslá, ktoré prejdú kontrolou, budú vypísané na výstup, ostatné budú zahodené.

## Obsah 
* [Použité programy](#použité-programy)
* [Kompilácia](#kompilácia)
* [Syntax spustenia](#syntax-spustenia)

## Použité programy
* Ubuntu: 22.04 LTS
* C: 17

## Kompilácia
`$ gcc -std=c99 -Wall -Wextra -Werror pwcheck.c -o pwcheck`

## Syntax spustenia 
`$ ./pwcheck LEVEL PARAM [--stats]`
* **LEVEL** = celé číslo v intervale [1, 4], ktoré určuje požadovanú úroveň bezpečnosti
* **PARAM** = kladné celé číslo, ktoré určuje dodatočný parameter pravidiel 
* **--stats** = ak je zadané, určuje, či sa na konci programu majú vypísať súhrnné štatistiky analyzovaných hesiel

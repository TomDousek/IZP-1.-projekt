Projekt keyfilter simuluje našeptávání autonavigace, která má na vstupu soubor známých adres. My programu při spoštění dáváme jméno adresy, kterou hledáme. Program buď vypíše, že zadanou adresu našel, nebo nenašel, nebo pokud začíná více adres stejným prefixem, tak nabídne možná další písmena, která bychom mohli stisknout.
Program se spoští v terminalu pomocí příkazu:   ./keyfilter brno < soubor

./keyfilter je název spustitelného souboru vytvořeného Makefilem. "Brno" je adresa, kterou hledáme. Mohl bych klidně napsat "br" , nebo i prazdny retezec "" a program si s tim stejne poradi. Operátor menší než < slouží pro vložení souboru přes standartní vstup stdin.
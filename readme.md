#Studentų galutinio balo apskaičiavimo programa.

#Ši programa skirta apskaičiuoti galutiniams balams, kai yra įvedamas studento vardas, pavardė, namų darbų rezultatai bei egzamino balas.

#Galutinis balas skaičiuojamas tokia formule: **Galutinis = 0.4 * vidurkis + 0.6 * egzaminas** (jei reikia galutinio balo medianos pavidalu tai tiesiog vietoj vidurkio įstatoma mediana)

#Norint naudotis programa, reikia atlikti šiuos veiksmus:
- Įvesti studentų skaičių.
- Pasirinkti galutinio balo skaičiavimo metodą(0 - Vidurkis, 1 - mediana).
- Įvesti studentų vardą ir pavardę.
- Pasirinkti ar namų darbų ir egzamino rezultatus reikia generuoti atsitiktinai(taip/ne).
- Atsakyti programai, ar žinai koks yra namų darbų skaičius(taip/ne).
- Įvesti namų darbų skaičių.
- Įvesti namų darbų visus rezultatus(10-balėje sistemoje).
- Galiausiai įvesti egzamino balą.

#Efektyvumo tyrimai ir rezultatai: 
- Laiko efektyvumas: programoje įvedant mažą studentų skaičių(tarkim du), ji apdoroja įvestus studentų duomenis gana greitai. Tačiau kai yra didesnis studentų skaičius(tarkim dešimt), įvedimas užtrunka žymiai ilgiau.Taip pat naudojama biblioteka atsitiktiniems balams generuoti paspartina skaičių sugeneravimą.
- Atminties efektyvumas: programoje naudojama struktūra(std::vector), kuri leidžia efektyviai saugoti ir tvarkyti studentų namų darbų rezultatus.
- Vartotojo sąsajos paprastumas: programoje yra leidžiama lengvai įvesti duomenis ir gauti rezultatus. Aiškiai nurodyti visi privalomi įvedimai ir rezultatas gaunamas greitai.

#Rezultatas - programa išveda studento vardą, pavardę ir galutinį balą(vidurkio arba medianos pavidalu).

#Naudotos bibliotekos:
- `<iostream>`
- `<iomanip>`
- `<string>`
- `<vector>`
- `<algorithm>`
- `<random>`

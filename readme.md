#Studenų galutinio balo apskaičiavimo programa.

#Ši programa skirta apskaičiuoti galutiniams balams, įvedant arba nuskaitant iš failo studento vardą, pavardę, namų darbų rezultatus bei egzamino balą.

#Galutinis balas skaičiuojamas tokia formule: **Galutinis = 0.4 * vidurkis + 0.6 * egzaminas** (Kai reikia galutinio balo medianos pavidalu tai tiesiog vietoj vidurkio įstatoma mediana)

#Norint naudotis programa, reikia atlikti šiuos veiksmus:
- Pasirinkti, ar norite sugeneruoti failus(taip/ne).

Jei pasirinksite, kad norite sugeneruoti, tuomet failai bus sukurti ir išvedime bus rodomas failų kurimo laikas.
  
- Atsakyti programai, ar norite įvesti studentų duomenis ar nuskaityti juos iš failo(ivesti/nuskaityti).
  
Jei pasirenkate nuskaityti, tai programa tiesiogiai nuskaitys failą, surušiuos studentus pagal galutinį balą(pagal vidurkį) į dvi grupes:Vargšiukai(galutinis balas < 5) ir Kietiakiai(galutinis balas >= 5) ir išves į du naujus failus. 
  
  **Jei pasirenkate įvesti, tuomet toliau reikes atlikti šiuos veiksmus:**
- Įvesti studentų skaičių.
- Įvesti studentų vardą ir pavardę.
- Pasirinkti ar namų darbų ir egzamino rezultatus reikia generuoti atsitiktinai(taip/ne).
- Atsakyti programai, ar žinai koks yra namų darbų skaičius(taip/ne).
- Įvesti namų darbų skaičių.
- Įvesti namų darbų visus rezultatus(10-balėje sistemoje).
- Galiausiai įvesti egzamino balą.


**Testavimo rezultatai()**
1. Failas:1000 įrašų:
- nuskaitymo laikas: 0.06038s
- rušiavimas didėjimo tvarka laikas, su sort funkcija:  0.01251s  
- dalijimo į dvi grupes laikas, panaikinant pradinį Vektor: 0.00693s 
- 438 įrašų Vargšiukai įrašymo į failą laikas: 0.01209s
- 562 įrašų Kietiakiai įrašymo į failą laikas: 0.01875s 
- testo laikas: 0.11786 s
2. Failas:10000 įrašų:
- nuskaitymo laikas:  0.70615s
- rušiavimas didėjimo tvarka laikas, su sort funkcija: 0.19600s
- dalijimo į dvi grupes laikas, panaikinant pradinį Vektor: 0.09198s
- 4169 įrašų Vargšiukai įrašymo į failą laikas: 0.11062s
- 5831 įrašų Kietiakiai įrašymo į failą laikas: 0.15452s
- testo laikas: 1.27971s
3. Failas:100000 įrašų:
- nuskaitymo laikas: 6.82098s
- rušiavimas didėjimo tvarka laikas, su sort funkcija: 2.45784s
- dalijimo į dvi grupes laikas, panaikinant pradinį Vektor:  0.92973s
- 41143 įrašų Vargšiukai įrašymo į failą laikas:  0.99591s
- 58857 įrašų Kietiakiai įrašymo į failą laikas:  1.42489s
- testo laikas: 12.75960s
4. Failas:1000000 įrašų:
- nuskaitymo laikas: 77.53606s
- rušiavimas didėjimo tvarka laikas, su sort funkcija: 30.46604s
- dalijimo į dvi grupes laikas, panaikinant pradinį Vektor: 9.07870s
- 411806 įrašų Vargšiukai įrašymo į failą laikas: 10.10847s
- 588194 įrašų Kietiakiai įrašymo į failą laikas: 15.57315s
- testo laikas: 144.09869s
5. Failas:10000000 įrašų:
- nuskaitymo laikas: 841.05301s
- rušiavimas didėjimo tvarka laikas, su sort funkcija: 544.98148s
- dalijimo į dvi grupes laikas, panaikinant pradinį Vektor: 907.25886s
- 4083175 įrašų Vargšiukai įrašymo į failą laikas: 127.48261s
- 5916825 įrašų Kietiakiai įrašymo į failą laikas: 171.13903s
- testo laikas: 2653.80826s

#Efektyvumo tyrimai ir rezultatai: 
- Laiko efektyvumas:
1. Programa greitai apdoroja nuskaitytus studentų duomenis, tačiau kai yra didesnis studentų skaičius, pastebimas ilgesnis laukimo laikas, kol programa pateikia rezultatus. Galima pamatyti, kad laikai didėja proporcingai failo dydžiui, ypač nuskaitymo ir rūšiavimo etapuose. Rūšiavimo laikas augo dramatiškai nuo 0.01251s(1000 įrašų) iki 544.98148s(10000000 įrašų), o dalijimo laikas taip pat didėjo, bet išlieka gerokai greitesnis už rūšiavimo laiką. Bendras testo laikas nuosekliai didėja, atspindėdamas procesų sudėtingumą.
2. Kai buvo pasirinkta įvesti duomenis, tuomet programoje įvedant mažą studentų skaičių(tarkim du), ji apdoroja įvestus studentų duomenis gana greitai. Tačiau kai yra didesnis studentų skaičius(tarkim dešimt), įvedimas užtrunka žymiai ilgiau.

- Atminties efektyvumas: programoje naudojama struktūra(std::vector), kuri leidžia efektyviai saugoti ir tvarkyti studentų namų darbų rezultatus. Užtikrinama, kad programa galėtų veikti su dideliu studentų skaičiumi.
  
- Vartotojo sąsajos paprastumas: programoje yra leidžiama lengvai įvesti duomenis ir gauti rezultatus. Aiškiai nurodyti visi privalomi įvedimai ir rezultatas gaunamas greitai.

#Rezultatas - Iš įvesties studentų duomenys nuskaitomi teisingai ir programa išveda studentų vardus, pavardes ir galutinį balą(medianos ir vidurkio pavidalu). Taip pat kai nuskaitomas failas, studentai surušiuojami pagal grupes ir išvedami į naujus failus. Išvedime rodomas programos veikimo greičio analizė.

#Naudotos bibliotekos:
- `<iostream>`
- `<iomanip>`
- `<string>`
- `<vector>`
- `<algorithm>`
- `<random>`
- `<fstream>`
- `<sstream>`
- `<chrono>`

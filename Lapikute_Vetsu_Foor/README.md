3x  -- https://www.aliexpress.com/item/32960193527.html?spm=a2g0o.cart.0.0.2f8f3c00ny5JL1&mp=1 -- €  9,04 -- (3.3V/0.9A versioon standard shipping)
2x  -- https://www.aliexpress.com/item/32674295742.html?spm=a2g0o.cart.0.0.ad463c00U5mv2L&mp=1 -- €  8,34 -- (5V/1A versioon standard shipping)
100x - https://www.oomipood.ee/en/kataloog/tme/toode?sku=TC01N0VHVw%3D%3D 		       -- € 20,43 -- (50 LED per screen/sign)

eeldus:
- 200x 100ohm takistit || 100x 200ohm takistit  -- lapi kontorist
- 4x NPN && 4x PNP transistorit (~1A 5V)	-- lapi kontorist

NB! puit/plastik LED maatriksi casei jaoks kas salvegida või veel otsutada kust/mida osta.

kokku panemise plaan:
- esimesed 3 converterit lähevad wemos d1 minide powerimiseks
- järgmised 2 converterit lähevad LED maatriksite powerimiseks
- 100 bipolar/bicolar LED'i lähevad kahe LED maatriksi tegemiseks
- takistid ja transistorid lähevad LED maatriksi powerimiseks


LED'ide powerimise skeem falstadis: (http://falstad.com/circuit/circuitjs.html)
//------ Copy from between these lines ------\\
$ 1 0.000005 10.20027730826997 50 5 43
t 80 336 128 336 0 -1 5 0.6636286556142279 100
t 496 336 448 336 0 -1 0 -0.6636286556142277 100
162 240 208 336 208 2 default 1 0 0 0.02
162 336 304 240 304 2 default 0 1 0 0.02
w 240 256 240 304 3
w 336 256 336 304 3
w 448 256 448 192 2
w 128 256 128 192 2
L 80 256 0 256 0 1 false 5 0
w 80 256 80 336 0
w 496 256 496 336 0
t 80 176 128 176 0 1 0 0.6636286556142279 100
t 496 176 448 176 0 1 -5 -0.6636286556142277 100
w 128 256 128 320 0
w 448 256 448 320 0
w 128 352 288 352 2
w 448 352 288 352 2
g 288 368 288 432 0
w 128 160 288 160 0
w 448 160 288 160 0
w 240 208 240 256 3
w 336 256 336 208 3
w 288 352 288 368 0
R 288 160 288 112 0 0 40 5 0 0 0.5
L 496 256 576 256 0 0 false 5 0
w 496 256 496 176 0
w 80 176 80 256 0
r 240 256 128 256 0 220
34 default0 0 1.7143528192810002e-7 0 2 0
162 256 0 320 0 2 default0 1 1 1 0.02
g 528 0 592 0 0
w 320 0 416 0 3
r 416 0 464 0 0 220
r 464 48 416 48 0 220
w 48 0 256 0 3
w 464 0 528 0 3
L 48 0 -32 0 0 1 false 5 0
w 336 256 448 256 0
w 416 48 320 48 3
g 48 48 -32 48 0
w 464 48 528 48 3
162 320 48 256 48 2 default0 1 1 1 0.02
w 48 48 256 48 3
L 528 48 592 48 0 1 false 5 0
o 2 64 0 4099 0.625 0.025 0 2 2 3
o 3 64 0 4099 0.625 0.00009765625 1 2 3 3

\\------ Copy from between these lines ------//
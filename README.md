# MCPI-Better-Creative-Inventory
This is a mod for minecraft: pi edition reborn that expands the creative inventory so that you have access to all items.
## Using
To use this mod you will need to download the shared library and place it in the mods folder of minecraft: pi edition, to do this download libbci.so and run 
```bash
wget https://github.com/bigjango13/MCPI-Better-Creative-Inventory-Mod/blob/main/libbci.so?raw=true
sudo mv libbci.so /usr/lib/minecraft-pi-reborn-client/mods/libbci.so 
``` 
Then all you need to do is run minecraft: pi edition with the Expand Creative Inventory mod activated.
If it still doesn't work you will have to run 
```bash
sudo mv /usr/lib/minecraft-pi-reborn-client/mods/libbci.so /usr/lib/minecraft-pi-reborn-client/mods/creative.so
```
## Compiling
To compile your own version of it you will need the libreborn folder and the creative.cpp file, then once you finish editing creative.cpp, you run:
```bash
arm-linux-gnueabihf-g++ -shared -o libbci.so creative.cpp -DREBORN_HAS_COMPILED_CODE
``` 
This will compile a version of libbci.so with your changes.
## Items Added
![Some of the items that libbci adds](https://camo.githubusercontent.com/fb511e85018e2ecb51013423a0ef12ab5a9a602b6915f166a1a994b75c6cf1c7/68747470733a2f2f63646e2e646973636f72646170702e636f6d2f6174746163686d656e74732f3734333538303739373837323736373036362f3931303332383834323033303238343830302f323032312d31312d31365f31392e34312e31302e706e67)
![More of the items that libbci adds](https://camo.githubusercontent.com/8641e07b67f6c7f3009fb5afca6d8d3a5d06c0020095c92541685ca27e9bfcd7/68747470733a2f2f63646e2e646973636f72646170702e636f6d2f6174746163686d656e74732f3734333538303739373837323736373036362f3931303332383835383933373533363531322f323032312d31312d31365f31392e34312e31352e706e67)
Image credit to [Red-exe-Engineer](https://github.com/Red-exe-Engineer)
### List:
Here is a list of all 87 items that are added by this mod:

Name: tallGrass, ID: 31

Name: doubleStoneSlab, ID: 43

Name: fire, ID: 51

Name: crops, ID: 59

Name: farmland, ID: 60

Name: activeFurnace, ID: 62

Name: activeRedstoneOre, ID: 74

Name: pumkinStem, ID: 105

Name: newGrass, ID: 253

Name: reserved6, ID: 255

Name: shovelIron, ID: 256

Name: ironPick, ID: 257

Name: ironAxe, ID: 258

Name: apple, ID: 260

Name: arrow, ID: 262

Name: coal, ID: 263

Name: diamond, ID: 264

Name: ironIngot, ID: 265

Name: goldIngot, ID: 266

Name: woodSword, ID: 268

Name: woodShovel, ID: 269

Name: woodPickaxe, ID: 270

Name: woodAxe, ID: 271

Name: stoneSword, ID: 272

Name: stoneShovel, ID: 273

Name: stonePickaxe, ID: 274

Name: stoneAxe, ID: 275

Name: diamondSword, ID: 276

Name: diamondShovel, ID: 277

Name: diamondPickaxe, ID: 278

Name: diamondAxe, ID: 279

Name: stick, ID: 280

Name: bowl, ID: 281

Name: goldSword, ID: 283

Name: goldShovel, ID: 284

Name: goldPickaxe, ID: 285

Name: goldAxe, ID: 286

Name: string, ID: 287

Name: feather, ID: 288

Name: gunpowder, ID: 289

Name: woodHoe, ID: 290

Name: stoneHoe, ID: 291

Name: flint1, ID: 292

Name: diamondHoe, ID: 293

Name: goldHoe, ID: 294

Name: seeds, ID: 295

Name: wheat, ID: 296

Name: bread, ID: 297

Name: leatherCap, ID: 298

Name: leatherShirt, ID: 299

Name: leatherPants, ID: 300

Name: leatherBoots, ID: 301

Name: chainHelm, ID: 302

Name: chainShirt, ID: 303

Name: chainLegs, ID: 304

Name: chainBoots, ID: 305

Name: ironHelm, ID: 306

Name: ironChest, ID: 307

Name: ironLegs, ID: 308

Name: ironBoots, ID: 309

Name: diamondHelm, ID: 310

Name: diamondChest, ID: 311

Name: diamondLegs, ID: 312

Name: diamondBoots, ID: 313

Name: goldHelm, ID: 314

Name: goldChest, ID: 315

Name: goldLegs, ID: 316

Name: goldBoots, ID: 317

Name: flint2, ID: 318

Name: porkRaw, ID: 319

Name: porkCooked, ID: 320

Name: ironDoor, ID: 330

Name: leather, ID: 334

Name: clayBrick, ID: 336

Name: clay, ID: 337

Name: notepad, ID: 339

Name: book, ID: 340

Name: slimeball, ID: 341

Name: compass, ID: 345

Name: clock, ID: 347

Name: glowDust, ID: 348

Name: bone, ID: 352

Name: sugar, ID: 353

Name: melon, ID: 360

Name: beefRaw, ID: 363

Name: chickenRaw, ID: 365

Name: cookedChicken, ID: 366

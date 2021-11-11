#include "libreborn/libreborn.h"
#include "libreborn/minecraft.h"

#include "libreborn/init.h"
#include "libreborn/feature.h"

// Add Item To Inventory
static void inventory_add_item(unsigned char *inventory, unsigned char *item, bool is_tile) {
    ItemInstance *item_instance = new ItemInstance;
    ALLOC_CHECK(item_instance);
    item_instance = (*(is_tile ? ItemInstance_constructor_tile : ItemInstance_constructor_item))(item_instance, item);
    (*FillingContainer_addItem)(inventory, item_instance);
}

// Expand Creative Inventory
static int32_t Inventory_setupDefault_FillingContainer_addItem_call_injection(unsigned char *filling_container, ItemInstance *item_instance) {
    // Call Original
    int32_t ret = (*FillingContainer_addItem)(filling_container, item_instance);

    // Add Items
    inventory_add_item(filling_container, *Item_flintAndSteel, false);
    inventory_add_item(filling_container, *Item_snowball, false);
    inventory_add_item(filling_container, *Item_egg, false);
    inventory_add_item(filling_container, *Item_shears, false);
    // Dyes
    for (int i = 0; i < 16; i++) {
        if (i == 15) {
            // Bonemeal Is Already In The Creative Inventory
            continue;
        }
        ItemInstance *new_item_instance = new ItemInstance;
        ALLOC_CHECK(new_item_instance);
        new_item_instance = (*ItemInstance_constructor_item_extra)(new_item_instance, *Item_dye_powder, 1, i);
        (*FillingContainer_addItem)(filling_container, new_item_instance);
    }
    inventory_add_item(filling_container, *Item_camera, false);
    // Add Tiles
    inventory_add_item(filling_container, *Tile_water, true);
    inventory_add_item(filling_container, *Tile_lava, true);
    inventory_add_item(filling_container, *Tile_calmWater, true);
    inventory_add_item(filling_container, *Tile_calmLava, true);
    inventory_add_item(filling_container, *Tile_glowingObsidian, true);
    inventory_add_item(filling_container, *Tile_web, true);
    inventory_add_item(filling_container, *Tile_topSnow, true);
    inventory_add_item(filling_container, *Tile_ice, true);
    inventory_add_item(filling_container, *Tile_invisible_bedrock, true);
    inventory_add_item(filling_container, *Tile_bedrock, true);
    inventory_add_item(filling_container, *Tile_info_updateGame1, true);
    inventory_add_item(filling_container, *Tile_info_updateGame2, true);

    ItemInstance *diamondSword_instance = new ItemInstance;
    ALLOC_CHECK(diamondSword_instance);
    diamondSword_instance->count = 1;
    diamondSword_instance->auxiliary = 0;
    diamondSword_instance->id = 276;
    (*FillingContainer_addItem)(filling_container, diamondSword_instance);

    ItemInstance *mushroomStew_instance = new ItemInstance;
    ALLOC_CHECK(mushroomStew_instance);
    mushroomStew_instance->count = 1;
    mushroomStew_instance->auxiliary = 0;
    mushroomStew_instance->id = 282;
    (*FillingContainer_addItem)(filling_container, mushroomStew_instance);

    ItemInstance *steak_instance = new ItemInstance;
    ALLOC_CHECK(steak_instance);
    steak_instance->count = 1;
    steak_instance->auxiliary = 0;
    steak_instance->id = 364;
    (*FillingContainer_addItem)(filling_container, steak_instance);

    ItemInstance *cookedChicken_instance = new ItemInstance;
    ALLOC_CHECK(cookedChicken_instance);
    cookedChicken_instance->count = 1;
    cookedChicken_instance->auxiliary = 0;
    cookedChicken_instance->id = 366;
    (*FillingContainer_addItem)(filling_container, cookedChicken_instance);

    ItemInstance *diamondHelm_instance = new ItemInstance;
    ALLOC_CHECK(diamondHelm_instance);
    diamondHelm_instance->count = 1;
    diamondHelm_instance->auxiliary = 0;
    diamondHelm_instance->id = 310;
    (*FillingContainer_addItem)(filling_container, diamondHelm_instance);

    ItemInstance *diamondChest_instance = new ItemInstance;
    ALLOC_CHECK(diamondChest_instance);
    diamondChest_instance->count = 1;
    diamondChest_instance->auxiliary = 0;
    diamondChest_instance->id = 311;
    (*FillingContainer_addItem)(filling_container, diamondChest_instance);

    ItemInstance *diamondLeg_instance = new ItemInstance;
    ALLOC_CHECK(diamondLeg_instance);
    diamondLeg_instance->count = 1;
    diamondLeg_instance->auxiliary = 0;
    diamondLeg_instance->id = 312;
    (*FillingContainer_addItem)(filling_container, diamondLeg_instance);

    ItemInstance *diamondBoot_instance = new ItemInstance;
    ALLOC_CHECK(diamondBoot_instance);
    diamondBoot_instance->count = 1;
    diamondBoot_instance->auxiliary = 0;
    diamondBoot_instance->id = 313;
    (*FillingContainer_addItem)(filling_container, diamondBoot_instance);

    ItemInstance *tallGrass_instance = new ItemInstance;
    ALLOC_CHECK(tallGrass_instance);
    tallGrass_instance->count = 1;
    tallGrass_instance->auxiliary = 0;
    tallGrass_instance->id = 31;
    (*FillingContainer_addItem)(filling_container, tallGrass_instance);

    ItemInstance *doubleStoneSlab_instance = new ItemInstance;
    ALLOC_CHECK(doubleStoneSlab_instance);
    doubleStoneSlab_instance->count = 1;
    doubleStoneSlab_instance->auxiliary = 0;
    doubleStoneSlab_instance->id = 43;
    (*FillingContainer_addItem)(filling_container, doubleStoneSlab_instance);

    ItemInstance *fire_instance = new ItemInstance;
    ALLOC_CHECK(fire_instance);
    fire_instance->count = 1;
    fire_instance->auxiliary = 0;
    fire_instance->id = 51;
    (*FillingContainer_addItem)(filling_container, fire_instance);

    ItemInstance *crops_instance = new ItemInstance;
    ALLOC_CHECK(crops_instance);
    crops_instance->count = 1;
    crops_instance->auxiliary = 0;
    crops_instance->id = 59;
    (*FillingContainer_addItem)(filling_container, crops_instance);

    ItemInstance *farmland_instance = new ItemInstance;
    ALLOC_CHECK(farmland_instance);
    farmland_instance->count = 1;
    farmland_instance->auxiliary = 0;
    farmland_instance->id = 60;
    (*FillingContainer_addItem)(filling_container, farmland_instance);

    ItemInstance *activeFurnace_instance = new ItemInstance;
    ALLOC_CHECK(activeFurnace_instance);
    activeFurnace_instance->count = 1;
    activeFurnace_instance->auxiliary = 0;
    activeFurnace_instance->id = 62;
    (*FillingContainer_addItem)(filling_container, activeFurnace_instance);

    ItemInstance *ironDoor_instance = new ItemInstance;
    ALLOC_CHECK(ironDoor_instance);
    ironDoor_instance->count = 1;
    ironDoor_instance->auxiliary = 0;
    ironDoor_instance->id = 330;
    (*FillingContainer_addItem)(filling_container, ironDoor_instance);

    ItemInstance *activeRedstoneOre_instance = new ItemInstance;
    ALLOC_CHECK(activeRedstoneOre_instance);
    activeRedstoneOre_instance->count = 1;
    activeRedstoneOre_instance->auxiliary = 0;
    activeRedstoneOre_instance->id = 74;
    (*FillingContainer_addItem)(filling_container, activeRedstoneOre_instance);

    ItemInstance *pumkinStem_instance = new ItemInstance;
    ALLOC_CHECK(pumkinStem_instance);
    pumkinStem_instance->count = 1;
    pumkinStem_instance->auxiliary = 0;
    pumkinStem_instance->id = 105;
    (*FillingContainer_addItem)(filling_container, pumkinStem_instance);

    ItemInstance *newGrass_instance = new ItemInstance;
    ALLOC_CHECK(newGrass_instance);
    newGrass_instance->count = 1;
    newGrass_instance->auxiliary = 0;
    newGrass_instance->id = 253;
    (*FillingContainer_addItem)(filling_container, newGrass_instance);

    ItemInstance *reserved6_instance = new ItemInstance;
    ALLOC_CHECK(reserved6_instance);
    reserved6_instance->count = 1;
    reserved6_instance->auxiliary = 0;
    reserved6_instance->id = 1;
    (*FillingContainer_addItem)(filling_container, reserved6_instance);

    ItemInstance *shovelIron_instance = new ItemInstance;
    ALLOC_CHECK(shovelIron_instance);
    shovelIron_instance->count = 1;
    shovelIron_instance->auxiliary = 0;
    shovelIron_instance->id = 256;
    (*FillingContainer_addItem)(filling_container, shovelIron_instance);

    ItemInstance *ironPick_instance = new ItemInstance;
    ALLOC_CHECK(ironPick_instance);
    ironPick_instance->count = 1;
    ironPick_instance->auxiliary = 0;
    ironPick_instance->id = 257;
    (*FillingContainer_addItem)(filling_container, ironPick_instance);

    ItemInstance *ironAxe_instance = new ItemInstance;
    ALLOC_CHECK(ironAxe_instance);
    ironAxe_instance->count = 1;
    ironAxe_instance->auxiliary = 0;
    ironAxe_instance->id = 258;
    (*FillingContainer_addItem)(filling_container, ironAxe_instance);

    ItemInstance *apple_instance = new ItemInstance;
    ALLOC_CHECK(apple_instance);
    apple_instance->count = 1;
    apple_instance->auxiliary = 0;
    apple_instance->id = 260;
    (*FillingContainer_addItem)(filling_container, apple_instance);

    ItemInstance *arrow_instance = new ItemInstance;
    ALLOC_CHECK(arrow_instance);
    arrow_instance->count = 1;
    arrow_instance->auxiliary = 0;
    arrow_instance->id = 262;
    (*FillingContainer_addItem)(filling_container, arrow_instance);

    ItemInstance *coal_instance = new ItemInstance;
    ALLOC_CHECK(coal_instance);
    coal_instance->count = 1;
    coal_instance->auxiliary = 0;
    coal_instance->id = 263;
    (*FillingContainer_addItem)(filling_container, coal_instance);

    ItemInstance *diamond_instance = new ItemInstance;
    ALLOC_CHECK(diamond_instance);
    diamond_instance->count = 1;
    diamond_instance->auxiliary = 0;
    diamond_instance->id = 264;
    (*FillingContainer_addItem)(filling_container, diamond_instance);

    ItemInstance *ironIngot_instance = new ItemInstance;
    ALLOC_CHECK(ironIngot_instance);
    ironIngot_instance->count = 1;
    ironIngot_instance->auxiliary = 0;
    ironIngot_instance->id = 265;
    (*FillingContainer_addItem)(filling_container, ironIngot_instance);

    ItemInstance *goldIngot_instance = new ItemInstance;
    ALLOC_CHECK(goldIngot_instance);
    goldIngot_instance->count = 1;
    goldIngot_instance->auxiliary = 0;
    goldIngot_instance->id = 266;
    (*FillingContainer_addItem)(filling_container, goldIngot_instance);

    ItemInstance *woodSword_instance = new ItemInstance;
    ALLOC_CHECK(woodSword_instance);
    woodSword_instance->count = 1;
    woodSword_instance->auxiliary = 0;
    woodSword_instance->id = 268;
    (*FillingContainer_addItem)(filling_container, woodSword_instance);

    ItemInstance *woodShovel_instance = new ItemInstance;
    ALLOC_CHECK(woodShovel_instance);
    woodShovel_instance->count = 1;
    woodShovel_instance->auxiliary = 0;
    woodShovel_instance->id = 269;
    (*FillingContainer_addItem)(filling_container, woodShovel_instance);

    ItemInstance *woodPickaxe_instance = new ItemInstance;
    ALLOC_CHECK(woodPickaxe_instance);
    woodPickaxe_instance->count = 1;
    woodPickaxe_instance->auxiliary = 0;
    woodPickaxe_instance->id = 270;
    (*FillingContainer_addItem)(filling_container, woodPickaxe_instance);

    ItemInstance *woodAxe_instance = new ItemInstance;
    ALLOC_CHECK(woodAxe_instance);
    woodAxe_instance->count = 1;
    woodAxe_instance->auxiliary = 0;
    woodAxe_instance->id = 271;
    (*FillingContainer_addItem)(filling_container, woodAxe_instance);

    ItemInstance *stoneSword_instance = new ItemInstance;
    ALLOC_CHECK(stoneSword_instance);
    stoneSword_instance->count = 1;
    stoneSword_instance->auxiliary = 0;
    stoneSword_instance->id = 272;
    (*FillingContainer_addItem)(filling_container, stoneSword_instance);

    ItemInstance *stoneShovel_instance = new ItemInstance;
    ALLOC_CHECK(stoneShovel_instance);
    stoneShovel_instance->count = 1;
    stoneShovel_instance->auxiliary = 0;
    stoneShovel_instance->id = 273;
    (*FillingContainer_addItem)(filling_container, stoneShovel_instance);

    ItemInstance *stonePickaxe_instance = new ItemInstance;
    ALLOC_CHECK(stonePickaxe_instance);
    stonePickaxe_instance->count = 1;
    stonePickaxe_instance->auxiliary = 0;
    stonePickaxe_instance->id = 274;
    (*FillingContainer_addItem)(filling_container, stonePickaxe_instance);

    ItemInstance *stoneAxe_instance = new ItemInstance;
    ALLOC_CHECK(stoneAxe_instance);
    stoneAxe_instance->count = 1;
    stoneAxe_instance->auxiliary = 0;
    stoneAxe_instance->id = 275;
    (*FillingContainer_addItem)(filling_container, stoneAxe_instance);

    ItemInstance *diamondShovel_instance = new ItemInstance;
    ALLOC_CHECK(diamondShovel_instance);
    diamondShovel_instance->count = 1;
    diamondShovel_instance->auxiliary = 0;
    diamondShovel_instance->id = 277;
    (*FillingContainer_addItem)(filling_container, diamondShovel_instance);

    ItemInstance *diamondPickaxe_instance = new ItemInstance;
    ALLOC_CHECK(diamondPickaxe_instance);
    diamondPickaxe_instance->count = 1;
    diamondPickaxe_instance->auxiliary = 0;
    diamondPickaxe_instance->id = 278;
    (*FillingContainer_addItem)(filling_container, diamondPickaxe_instance);

    ItemInstance *diamondAxe_instance = new ItemInstance;
    ALLOC_CHECK(diamondAxe_instance);
    diamondAxe_instance->count = 1;
    diamondAxe_instance->auxiliary = 0;
    diamondAxe_instance->id = 279;
    (*FillingContainer_addItem)(filling_container, diamondAxe_instance);

    ItemInstance *magicWand_instance = new ItemInstance;
    ALLOC_CHECK(magicWand_instance);
    magicWand_instance->count = 1;
    magicWand_instance->auxiliary = 0;
    magicWand_instance->id = 280;
    (*FillingContainer_addItem)(filling_container, magicWand_instance);

    ItemInstance *bowl_instance = new ItemInstance;
    ALLOC_CHECK(bowl_instance);
    bowl_instance->count = 1;
    bowl_instance->auxiliary = 0;
    bowl_instance->id = 281;
    (*FillingContainer_addItem)(filling_container, bowl_instance);

    ItemInstance *goldSword_instance = new ItemInstance;
    ALLOC_CHECK(goldSword_instance);
    goldSword_instance->count = 1;
    goldSword_instance->auxiliary = 0;
    goldSword_instance->id = 283;
    (*FillingContainer_addItem)(filling_container, goldSword_instance);

    ItemInstance *goldShovel_instance = new ItemInstance;
    ALLOC_CHECK(goldShovel_instance);
    goldShovel_instance->count = 1;
    goldShovel_instance->auxiliary = 0;
    goldShovel_instance->id = 284;
    (*FillingContainer_addItem)(filling_container, goldShovel_instance);

    ItemInstance *goldPickaxe_instance = new ItemInstance;
    ALLOC_CHECK(goldPickaxe_instance);
    goldPickaxe_instance->count = 1;
    goldPickaxe_instance->auxiliary = 0;
    goldPickaxe_instance->id = 285;
    (*FillingContainer_addItem)(filling_container, goldPickaxe_instance);

    ItemInstance *goldAxe_instance = new ItemInstance;
    ALLOC_CHECK(goldAxe_instance);
    goldAxe_instance->count = 1;
    goldAxe_instance->auxiliary = 0;
    goldAxe_instance->id = 286;
    (*FillingContainer_addItem)(filling_container, goldAxe_instance);

    ItemInstance *string_instance = new ItemInstance;
    ALLOC_CHECK(string_instance);
    string_instance->count = 1;
    string_instance->auxiliary = 0;
    string_instance->id = 287;
    (*FillingContainer_addItem)(filling_container, string_instance);

    ItemInstance *feather_instance = new ItemInstance;
    ALLOC_CHECK(feather_instance);
    feather_instance->count = 1;
    feather_instance->auxiliary = 0;
    feather_instance->id = 288;
    (*FillingContainer_addItem)(filling_container, feather_instance);

    ItemInstance *gunpowder_instance = new ItemInstance;
    ALLOC_CHECK(gunpowder_instance);
    gunpowder_instance->count = 1;
    gunpowder_instance->auxiliary = 0;
    gunpowder_instance->id = 289;
    (*FillingContainer_addItem)(filling_container, gunpowder_instance);

    ItemInstance *woodHoe_instance = new ItemInstance;
    ALLOC_CHECK(woodHoe_instance);
    woodHoe_instance->count = 1;
    woodHoe_instance->auxiliary = 0;
    woodHoe_instance->id = 290;
    (*FillingContainer_addItem)(filling_container, woodHoe_instance);

    ItemInstance *stoneHoe_instance = new ItemInstance;
    ALLOC_CHECK(stoneHoe_instance);
    stoneHoe_instance->count = 1;
    stoneHoe_instance->auxiliary = 0;
    stoneHoe_instance->id = 291;
    (*FillingContainer_addItem)(filling_container, stoneHoe_instance);

    ItemInstance *flint1_instance = new ItemInstance;
    ALLOC_CHECK(flint1_instance);
    flint1_instance->count = 1;
    flint1_instance->auxiliary = 0;
    flint1_instance->id = 292;
    (*FillingContainer_addItem)(filling_container, flint1_instance);

    ItemInstance *diamondHoe_instance = new ItemInstance;
    ALLOC_CHECK(diamondHoe_instance);
    diamondHoe_instance->count = 1;
    diamondHoe_instance->auxiliary = 0;
    diamondHoe_instance->id = 293;
    (*FillingContainer_addItem)(filling_container, diamondHoe_instance);

    ItemInstance *goldHoe_instance = new ItemInstance;
    ALLOC_CHECK(goldHoe_instance);
    goldHoe_instance->count = 1;
    goldHoe_instance->auxiliary = 0;
    goldHoe_instance->id = 294;
    (*FillingContainer_addItem)(filling_container, goldHoe_instance);

    ItemInstance *seeds_instance = new ItemInstance;
    ALLOC_CHECK(seeds_instance);
    seeds_instance->count = 1;
    seeds_instance->auxiliary = 0;
    seeds_instance->id = 295;
    (*FillingContainer_addItem)(filling_container, seeds_instance);

    ItemInstance *wheat_instance = new ItemInstance;
    ALLOC_CHECK(wheat_instance);
    wheat_instance->count = 1;
    wheat_instance->auxiliary = 0;
    wheat_instance->id = 296;
    (*FillingContainer_addItem)(filling_container, wheat_instance);

    ItemInstance *bread_instance = new ItemInstance;
    ALLOC_CHECK(bread_instance);
    bread_instance->count = 1;
    bread_instance->auxiliary = 0;
    bread_instance->id = 297;
    (*FillingContainer_addItem)(filling_container, bread_instance);

    ItemInstance *leatherCap_instance = new ItemInstance;
    ALLOC_CHECK(leatherCap_instance);
    leatherCap_instance->count = 1;
    leatherCap_instance->auxiliary = 0;
    leatherCap_instance->id = 298;
    (*FillingContainer_addItem)(filling_container, leatherCap_instance);

    ItemInstance *leatherShirt_instance = new ItemInstance;
    ALLOC_CHECK(leatherShirt_instance);
    leatherShirt_instance->count = 1;
    leatherShirt_instance->auxiliary = 0;
    leatherShirt_instance->id = 299;
    (*FillingContainer_addItem)(filling_container, leatherShirt_instance);

    ItemInstance *leatherPants_instance = new ItemInstance;
    ALLOC_CHECK(leatherPants_instance);
    leatherPants_instance->count = 1;
    leatherPants_instance->auxiliary = 0;
    leatherPants_instance->id = 300;
    (*FillingContainer_addItem)(filling_container, leatherPants_instance);

    ItemInstance *leatherBoots_instance = new ItemInstance;
    ALLOC_CHECK(leatherBoots_instance);
    leatherBoots_instance->count = 1;
    leatherBoots_instance->auxiliary = 0;
    leatherBoots_instance->id = 301;
    (*FillingContainer_addItem)(filling_container, leatherBoots_instance);

    ItemInstance *chainHelm_instance = new ItemInstance;
    ALLOC_CHECK(chainHelm_instance);
    chainHelm_instance->count = 1;
    chainHelm_instance->auxiliary = 0;
    chainHelm_instance->id = 302;
    (*FillingContainer_addItem)(filling_container, chainHelm_instance);

    ItemInstance *chainShirt_instance = new ItemInstance;
    ALLOC_CHECK(chainShirt_instance);
    chainShirt_instance->count = 1;
    chainShirt_instance->auxiliary = 0;
    chainShirt_instance->id = 303;
    (*FillingContainer_addItem)(filling_container, chainShirt_instance);

    ItemInstance *chainLegs_instance = new ItemInstance;
    ALLOC_CHECK(chainLegs_instance);
    chainLegs_instance->count = 1;
    chainLegs_instance->auxiliary = 0;
    chainLegs_instance->id = 304;
    (*FillingContainer_addItem)(filling_container, chainLegs_instance);

    ItemInstance *chainBoots_instance = new ItemInstance;
    ALLOC_CHECK(chainBoots_instance);
    chainBoots_instance->count = 1;
    chainBoots_instance->auxiliary = 0;
    chainBoots_instance->id = 305;
    (*FillingContainer_addItem)(filling_container, chainBoots_instance);

    ItemInstance *ironHelm_instance = new ItemInstance;
    ALLOC_CHECK(ironHelm_instance);
    ironHelm_instance->count = 1;
    ironHelm_instance->auxiliary = 0;
    ironHelm_instance->id = 306;
    (*FillingContainer_addItem)(filling_container, ironHelm_instance);

    ItemInstance *ironChest_instance = new ItemInstance;
    ALLOC_CHECK(ironChest_instance);
    ironChest_instance->count = 1;
    ironChest_instance->auxiliary = 0;
    ironChest_instance->id = 307;
    (*FillingContainer_addItem)(filling_container, ironChest_instance);

    ItemInstance *ironLegs_instance = new ItemInstance;
    ALLOC_CHECK(ironLegs_instance);
    ironLegs_instance->count = 1;
    ironLegs_instance->auxiliary = 0;
    ironLegs_instance->id = 308;
    (*FillingContainer_addItem)(filling_container, ironLegs_instance);

    ItemInstance *ironBoots_instance = new ItemInstance;
    ALLOC_CHECK(ironBoots_instance);
    ironBoots_instance->count = 1;
    ironBoots_instance->auxiliary = 0;
    ironBoots_instance->id = 309;
    (*FillingContainer_addItem)(filling_container, ironBoots_instance);

    ItemInstance *goldHelm_instance = new ItemInstance;
    ALLOC_CHECK(goldHelm_instance);
    goldHelm_instance->count = 1;
    goldHelm_instance->auxiliary = 0;
    goldHelm_instance->id = 314;
    (*FillingContainer_addItem)(filling_container, goldHelm_instance);

    ItemInstance *goldChest_instance = new ItemInstance;
    ALLOC_CHECK(goldChest_instance);
    goldChest_instance->count = 1;
    goldChest_instance->auxiliary = 0;
    goldChest_instance->id = 315;
    (*FillingContainer_addItem)(filling_container, goldChest_instance);

    ItemInstance *goldLegs_instance = new ItemInstance;
    ALLOC_CHECK(goldLegs_instance);
    goldLegs_instance->count = 1;
    goldLegs_instance->auxiliary = 0;
    goldLegs_instance->id = 316;
    (*FillingContainer_addItem)(filling_container, goldLegs_instance);

    ItemInstance *goldBoots_instance = new ItemInstance;
    ALLOC_CHECK(goldBoots_instance);
    goldBoots_instance->count = 1;
    goldBoots_instance->auxiliary = 0;
    goldBoots_instance->id = 317;
    (*FillingContainer_addItem)(filling_container, goldBoots_instance);

    ItemInstance *flint2_instance = new ItemInstance;
    ALLOC_CHECK(flint2_instance);
    flint2_instance->count = 1;
    flint2_instance->auxiliary = 0;
    flint2_instance->id = 318;
    (*FillingContainer_addItem)(filling_container, flint2_instance);

    ItemInstance *porkRaw_instance = new ItemInstance;
    ALLOC_CHECK(porkRaw_instance);
    porkRaw_instance->count = 1;
    porkRaw_instance->auxiliary = 0;
    porkRaw_instance->id = 319;
    (*FillingContainer_addItem)(filling_container, porkRaw_instance);

    ItemInstance *porkCooked_instance = new ItemInstance;
    ALLOC_CHECK(porkCooked_instance);
    porkCooked_instance->count = 1;
    porkCooked_instance->auxiliary = 0;
    porkCooked_instance->id = 320;
    (*FillingContainer_addItem)(filling_container, porkCooked_instance);

    ItemInstance *leather_instance = new ItemInstance;
    ALLOC_CHECK(leather_instance);
    leather_instance->count = 1;
    leather_instance->auxiliary = 0;
    leather_instance->id = 334;
    (*FillingContainer_addItem)(filling_container, leather_instance);

    ItemInstance *clayBrick_instance = new ItemInstance;
    ALLOC_CHECK(clayBrick_instance);
    clayBrick_instance->count = 1;
    clayBrick_instance->auxiliary = 0;
    clayBrick_instance->id = 336;
    (*FillingContainer_addItem)(filling_container, clayBrick_instance);

    ItemInstance *clay_instance = new ItemInstance;
    ALLOC_CHECK(clay_instance);
    clay_instance->count = 1;
    clay_instance->auxiliary = 0;
    clay_instance->id = 337;
    (*FillingContainer_addItem)(filling_container, clay_instance);

    ItemInstance *notepad_instance = new ItemInstance;
    ALLOC_CHECK(notepad_instance);
    notepad_instance->count = 1;
    notepad_instance->auxiliary = 0;
    notepad_instance->id = 339;
    (*FillingContainer_addItem)(filling_container, notepad_instance);

    ItemInstance *book_instance = new ItemInstance;
    ALLOC_CHECK(book_instance);
    book_instance->count = 1;
    book_instance->auxiliary = 0;
    book_instance->id = 340;
    (*FillingContainer_addItem)(filling_container, book_instance);

    ItemInstance *slimeball_instance = new ItemInstance;
    ALLOC_CHECK(slimeball_instance);
    slimeball_instance->count = 1;
    slimeball_instance->auxiliary = 0;
    slimeball_instance->id = 341;
    (*FillingContainer_addItem)(filling_container, slimeball_instance);

    ItemInstance *compass_instance = new ItemInstance;
    ALLOC_CHECK(compass_instance);
    compass_instance->count = 1;
    compass_instance->auxiliary = 0;
    compass_instance->id = 345;
    (*FillingContainer_addItem)(filling_container, compass_instance);

    ItemInstance *clock_instance = new ItemInstance;
    ALLOC_CHECK(clock_instance);
    clock_instance->count = 1;
    clock_instance->auxiliary = 0;
    clock_instance->id = 347;
    (*FillingContainer_addItem)(filling_container, clock_instance);

    ItemInstance *glowDust_instance = new ItemInstance;
    ALLOC_CHECK(glowDust_instance);
    glowDust_instance->count = 1;
    glowDust_instance->auxiliary = 0;
    glowDust_instance->id = 348;
    (*FillingContainer_addItem)(filling_container, glowDust_instance);

    ItemInstance *bone_instance = new ItemInstance;
    ALLOC_CHECK(bone_instance);
    bone_instance->count = 1;
    bone_instance->auxiliary = 0;
    bone_instance->id = 352;
    (*FillingContainer_addItem)(filling_container, bone_instance);

    ItemInstance *sugar_instance = new ItemInstance;
    ALLOC_CHECK(sugar_instance);
    sugar_instance->count = 1;
    sugar_instance->auxiliary = 0;
    sugar_instance->id = 353;
    (*FillingContainer_addItem)(filling_container, sugar_instance);

    ItemInstance *melon_instance = new ItemInstance;
    ALLOC_CHECK(melon_instance);
    melon_instance->count = 1;
    melon_instance->auxiliary = 0;
    melon_instance->id = 360;
    (*FillingContainer_addItem)(filling_container, melon_instance);

    ItemInstance *beefRaw_instance = new ItemInstance;
    ALLOC_CHECK(beefRaw_instance);
    beefRaw_instance->count = 1;
    beefRaw_instance->auxiliary = 0;
    beefRaw_instance->id = 363;
    (*FillingContainer_addItem)(filling_container, beefRaw_instance);

    ItemInstance *chickenRaw_instance = new ItemInstance;
    ALLOC_CHECK(chickenRaw_instance);
    chickenRaw_instance->count = 1;
    chickenRaw_instance->auxiliary = 0;
    chickenRaw_instance->id = 365;
    (*FillingContainer_addItem)(filling_container, chickenRaw_instance);

    ItemInstance *cookedGoose_instance = new ItemInstance;
    ALLOC_CHECK(cookedGoose_instance);
    cookedGoose_instance->count = 1;
    cookedGoose_instance->auxiliary = 0;
    cookedGoose_instance->id = 366;
    (*FillingContainer_addItem)(filling_container, cookedGoose_instance);

    return ret;
}

// Init
void init_creative() {
    // Add Extra Items To Creative Inventory (Only Replace Specific Function Call)
    if (feature_has("Expand Creative Inventory", 0)) {
        overwrite_call((void *) 0x8e0fc, (void *) Inventory_setupDefault_FillingContainer_addItem_call_injection);
    }
}

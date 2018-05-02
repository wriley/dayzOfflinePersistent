/*
    Inspired by:
        /u/knastv - https://www.reddit.com/r/dayz/comments/8ftcs2/063_persistent_singleplayer_mod_update_10_save/
        Arkensor - https://github.com/Arkensor/DayZCommunityOfflineMode
*/

/*  === Characters ===
    SurvivorM_Mirek
    SurvivorM_Boris
    SurvivorM_Cyril
    SurvivorM_Denis
    SurvivorM_Elias
    SurvivorM_Francis
    SurvivorM_Guo
    SurvivorM_Hassan
    SurvivorM_Indar
    SurvivorM_Jose
    SurvivorM_Kaito
    SurvivorM_Lewis
    SurvivorM_Manua
    SurvivorM_Niki
    SurvivorM_Oliver
    SurvivorM_Peter
    SurvivorM_Quinn
    SurvivorM_Rolf
    SurvivorM_Seth
    SurvivorM_Taiki
    SurvivorF_Eva
    SurvivorF_Frida
    SurvivorF_Gabi
    SurvivorF_Helga
    SurvivorF_Irena
    SurvivorF_Keiko
    SurvivorF_Linda
    SurvivorF_Maria
    SurvivorF_Naomi
*/

class CustomMission: MissionGameplay
{
    
    override void OnMissionFinish()
    {
        super.OnMissionFinish();
        
        PlayerBase player = PlayerBase.Cast( GetGame().GetPlayer() );
		
		if(player && !player.IsDamageDestroyed())
		{
			if(savePlayer())
            {
                Print("Player saved");
            }
            else
            {
                Print("ERROR: Unable to save player");
            }
		} else {
            FileHandle file = OpenFile("$profile:playerSave.txt", FileMode.WRITE);
            if ( file == 0 )
            {
                Print("Failed to open $profile:playerSave.txt for writing");
            } else {
                Print("Removing character data");
                FPrintln(file, "");
                CloseFile(file);
            }
        }
    }
    
    override void CreateLogoutMenu(UIMenuPanel parent)
	{
        super.CreateLogoutMenu(parent);
		PlayerBase player = PlayerBase.Cast( GetGame().GetPlayer() );
		
		if (!player || player.IsDamageDestroyed())
		{
            FileHandle file = OpenFile("$profile:playerSave.txt", FileMode.WRITE);
            if ( file == 0 )
            {
                Print("Failed to open $profile:playerSave.txt for writing");
            } else {
                Print("Removing character data");
                FPrintln(file, "");
                CloseFile(file);
            }
		}
	}
};

Mission CreateCustomMission(string path)
{
    return new CustomMission();
}

void SetRandomHealth(EntityAI itm)
{
	int rndHlt = Math.RandomInt(40,100);
	itm.SetHealth("","",rndHlt);
}

void main()
{
    if(!loadPlayer())
    {
        vector player_pos;
        int index;
        TVectorArray positions = {"15135.1 0 13901.1", "15017.8 0 13892.4", "14887.1 0 14547.9", "14749.7 0 13248.7", "14697.6 0 13418.4", "14537.3 0 14755.7", "14415.3 0 14025.2", "14338.0 0 12859.5", "14263.8 0 12748.7", "14172.2 0 12304.9", "14071.4 0 12033.3", "14054.9 0 11341.3", "14017.8 0 2959.1", "13905.5 0 12489.7", "13852.4 0 11686.0", "13846.6 0 12050.0", "13676.0 0 12262.1", "13617.4 0 12759.8", "13610.1 0 11223.6", "13594.3 0 4064.0", "13587.8 0 6026.5", "13571.1 0 3056.8", "13552.6 0 4653.7", "13529.9 0 3968.3", "13520.8 0 4223.7", "13504.0 0 5004.5", "13476.7 0 6136.3", "13441.6 0 5262.2", "13426.6 0 5747.3", "13416.8 0 11840.4", "13400.8 0 4120.7", "13395.8 0 5902.8", "13385.0 0 3946.6", "13374.4 0 6454.3", "13367.1 0 10837.1", "13366.3 0 4906.0", "13337.1 0 5120.8", "13326.7 0 5489.1", "13312.7 0 6771.1", "13288.7 0 11415.1", "13261.6 0 11785.2", "13171.6 0 6534.8", "13159.8 0 5401.7", "13155.2 0 5475.2", "13138.8 0 6737.3", "13112.3 0 11280.7", "13111.7 0 10975.5", "13101.2 0 7657.3", "13099.1 0 6393.0", "13084.9 0 7938.6", "13056.8 0 4848.5", "13048.1 0 8357.6", "13048.1 0 3867.7", "12991.7 0 7287.1", "12983.0 0 5539.1", "12978.9 0 9727.8", "12950.2 0 5226.7", "12942.1 0 8393.1", "12891.5 0 3673.9", "12628.7 0 10495.2", "12574.3 0 3592.8", "12566.3 0 6682.6", "12465.2 0 8009.0", "12354.5 0 3480.0", "13262.8 0 7225.8", "13170.0 0 7406.3", "12936.7 0 10734.0", "12929.7 0 8578.3", "12917.3 0 9356.6", "12889.9 0 8792.8", "12868.7 0 9054.5", "12800.7 0 10542.7", "12796.3 0 10361.3", "12789.2 0 10918.7", "12774.0 0 7792.6", "12729.8 0 11285.5", "12689.8 0 8256.0", "12651.2 0 8914.4", "12614.7 0 7304.6", "12343.6 0 10169.8", "12332.0 0 8170.0", "12221.6 0 8693.6", "12135.7 0 10209.8", "11914.3 0 3402.0", "11846.8 0 3477.8", "11709.4 0 3388.2", "11578.0 0 3159.0", "11439.0 0 3315.2", "11201.5 0 3186.6", "11075.8 0 3031.2", "11049.3 0 2801.6", "10969.2 0 2895.1", "10875.8 0 2518.9", "10820.4 0 2257.4", "10757.4 0 2662.2", "10294.2 0 2822.9", "10032.8 0 2446.5", "9823.2 0 2712.6", "9691.7 0 1750.4", "9529.7 0 1791.2", "9479.7 0 2373.5", "9193.7 0 1935.7"};
        
        TStringArray tops = {"Hoodie_Blue","Hoodie_Black","Hoodie_Brown","Hoodie_Green","Hoodie_Grey","Hoodie_Red"};
        TStringArray pants = {"Jeans_Black","Jeans_BlueDark","Jeans_Blue","Jeans_Brown","Jeans_Green","Jeans_Grey","CanvasPants_Beige","CanvasPants_Blue","CanvasPants_Grey"};
        TStringArray shoes = {"AthleticShoes_Black","AthleticShoes_Blue","AthleticShoes_Brown","AthleticShoes_Green","AthleticShoes_Grey"};
            
        Print(positions);
        
        index = Math.RandomInt(0, positions.Count() );
        

        player_pos = positions.Get(index);
        Print(player_pos);	
        Entity playerEnt = GetGame().CreatePlayer( NULL, GetGame().CreateRandomPlayer(), player_pos, 0, "NONE");

        PlayerBase player = (PlayerBase) playerEnt;

        EntityAI item = player.GetInventory().CreateInInventory(tops.GetRandomElement());
        EntityAI item2 = player.GetInventory().CreateInInventory(pants.GetRandomElement());
        EntityAI item3 = player.GetInventory().CreateInInventory(shoes.GetRandomElement());
        
        EntityAI itemEnt;
        EntityAI itemIn;
        ItemBase itemBs;
        int rndQnt;
        
        itemEnt = player.GetInventory().CreateInInventory("Rag");
        itemBs = ItemBase.Cast(itemEnt);
        itemBs.SetQuantity(4);
        SetRandomHealth(itemEnt);

        itemEnt = player.GetInventory().CreateInInventory("Mag_IJ70_8Rnd");
        SetRandomHealth(itemEnt);

        itemEnt = player.GetInventory().CreateInInventory("HuntingKnife");
        SetRandomHealth(itemEnt);

        itemEnt = player.GetInventory().CreateInInventory("MakarovIJ70");
        SetRandomHealth(itemEnt);
        player.SetQuickBarEntityShortcut(itemEnt, 2);

        itemIn = itemEnt.GetInventory().CreateAttachment("Mag_IJ70_8Rnd");
        SetRandomHealth(itemIn);

        itemEnt = player.GetInventory().CreateInInventory("Izh18");
        SetRandomHealth(itemEnt);
        player.SetQuickBarEntityShortcut(itemEnt, 0);

        itemBs = ItemBase.Cast(itemEnt);
        itemBs.SetQuantity(rndQnt);

        itemEnt = player.GetInventory().CreateInInventory("Ammo_762x39");
        rndQnt = Math.RandomInt(5,20);
        SetRandomHealth(itemEnt);
        player.SetQuickBarEntityShortcut(itemEnt, 1);

        itemEnt = player.GetInventory().CreateInInventory("Ammo_380");
        SetRandomHealth(itemEnt);
        
        GetGame().SelectPlayer(NULL, player);
    }
    
	//EKONOMIKA
	Hive myHive = CreateHive();
	if( myHive )
	{
		myHive.InitOffline();
	}

	Weather weather = g_Game.GetWeather();

	weather.GetOvercast().SetLimits( 0.0 , 1.0 );
	weather.GetRain().SetLimits( 0.0 , 1.0 );
	weather.GetFog().SetLimits( 0.0 , 1.0 );

	weather.GetOvercast().SetForecastChangeLimits( 0.0, 1.0 );
	weather.GetRain().SetForecastChangeLimits( 0.0, 1.0 );
	weather.GetFog().SetForecastChangeLimits( 0.0, 1.0 );

	weather.GetOvercast().SetForecastTimeLimits( 3600 , 3600 );
	weather.GetRain().SetForecastTimeLimits( 3600 , 3600 );
	weather.GetFog().SetForecastTimeLimits( 3600 , 3600 );

    // rain storm
	//weather.GetOvercast().Set( 1.0, 0, 0);
	//weather.GetRain().Set( 1.0, 0, 0);
	//weather.GetFog().Set( 0.5, 0, 0);
    
    // clear
    weather.GetOvercast().Set( 0.0, 0, 0);
	weather.GetRain().Set( 0.0, 0, 0);
	weather.GetFog().Set( 0.0, 0, 0);
	
	weather.SetWindMaximumSpeed(5);
	weather.SetWindFunctionParams(0.2, 1.0, 50);
}

string getItemText(string txt) {
    int i = txt.IndexOf("[");
    if(i != -1) {
        return txt.Substring(0, i);
    } else {
        return txt;
    }
}

float getItemQuantity(string txt) {
    Print("getItemQuantity(" + txt + ")");
    int i = txt.IndexOf("[");
    if(i != -1) {
        //Print("getItemQuantity() i=" + i);
        int j = txt.IndexOf("]");
        if(j != -1) {
            //Print("getItemQuantity() j=" + j);
            int len = j - i - 1;
            string qty = txt.Substring(i + 1, len);
            Print("getItemQuantity() qty=" + qty);
            return qty.ToFloat();
        } else {
            return -1;
        }
    } else {
        return -1;
    }
}

bool loadPlayer()
{
    // TODO error checking for reading the lines
    FileHandle file = OpenFile("$profile:playerSave.txt", FileMode.READ);
    if ( file == 0 )
    {
        Print("Failed to open $profile:playerSave.txt for reading");
        return false;
    }
    string line = "";

    // character model, position, direction
    FGets(file,  line);
    if(line.Length() == 0 || line == "")
    {
        return false;
    }
    string charModel = line;
    
    FGets(file,  line);
    vector position = line.ToVector();

    FGets(file,  line);
    vector direction = line.ToVector();
    
    PlayerBase _player = PlayerBase.Cast( GetGame().CreatePlayer( NULL, charModel, "0 0 0", 0, "NONE") );
    _player.SetPosition( position );
    _player.SetDirection( direction );
    
    // weather and date/time
    string overcast, rain, fog, wind;
    FGets(file,  overcast); FGets(file,  rain); FGets(file,  fog); FGets(file,  wind);

    Weather weather = g_Game.GetWeather();
    weather.GetOvercast().Set(overcast.ToFloat());
    weather.GetRain().Set(rain.ToFloat());
    weather.GetFog().Set(fog.ToFloat());
    weather.SetWindSpeed(wind.ToFloat());

    string sorigYear, sorigMonth, sorigDay, sorigHour, sorigMinute;
    FGets(file,  sorigYear); FGets(file,  sorigMonth); FGets(file,  sorigDay); FGets(file,  sorigHour); FGets(file,  sorigMinute);

    int origYear, origMonth, origDay, origHour, origMinute;
    GetGame().GetWorld().GetDate( origYear, origMonth, origDay, origHour, origMinute );
    
    // inventory
    TStringArray inventoryItems = new TStringArray;
    string itemsLine = "";
    string itemText = "";
    float itemQty = 0.0;
    FGets(file, itemsLine);
    itemsLine.Split(",", inventoryItems);
    
    string inHands = "";
    itemQty = 0.0;
    ItemBase handItem;
    FGets(file, inHands);
    Print("INVENTORY: in hands = " + inHands);
    if(inHands != "EMPTY") {
        itemText = getItemText(inHands);
        itemQty = getItemQuantity(inHands);
        handItem = ItemBase.Cast(_player.GetInventory().CreateInInventory(itemText));
        _player.PredictiveTakeEntityToHands(handItem);
        if(handItem == NULL) {
            Print("INVENTORY: " + itemText + " spawning item on ground");
            handItem = ItemBase.Cast(g_Game.CreateObject( itemText, position ));
            if(handItem != NULL) {
                if(itemQty > 0) {
                    Print("INVENTORY: " + itemText + " setting quantity to " + itemQty);
                    if(handItem.IsMagazine()) {
                        // SetAmmoCount not implemented yet
                        //handItem.SetAmmoCount(itemQty);
                    } else {
                        handItem.SetQuantity(itemQty);
                    }
                }
            } else {
                Print("INVENTORY: " + itemText + " could not spawn item");
            }
        } else {
            if(itemQty > 0) {
                if(handItem.IsMagazine()) {
                    // SetAmmoCount not implemented yet
                    //handItem.SetAmmoCount(itemQty);
                } else {
                    handItem.SetQuantity(itemQty);
                }
            }
        }
    }
    
    // float item.GetQuantity()
    // item.SetQuantity(float)

    ItemBase item;
    for(int i = 0; i < inventoryItems.Count(); i++) {
        Print("INVENTORY: " + inventoryItems[i]);
        itemText = getItemText(inventoryItems[i]);
        itemQty = getItemQuantity(inventoryItems[i]);
        item = ItemBase.Cast(_player.GetInventory().CreateInInventory(itemText));
        if( item == NULL) {    
            Print("INVENTORY: " + itemText + " spawning item on ground");
            item = ItemBase.Cast(g_Game.CreateObject( itemText, position ));
            if(item != NULL) {
                if(itemQty > 0) {
                    if(item.IsMagazine()) {
                        // SetAmmoCount not implemented yet
                        //item.SetAmmoCount(itemQty);
                    } else {
                        item.SetQuantity(itemQty);
                    }
                }
            } else {
                Print("INVENTORY: " + itemText + " could not spawn item");
            }
        } else {
            if(itemQty > 0) {
                if(item.IsMagazine()) {
                    // SetAmmoCount not implemented yet
                    //item.SetAmmoCount(itemQty);
                } else {
                    item.SetQuantity(itemQty);
                }
            }
        }
    }
    
    // health/etc
    string shealth, sblood, stemp, senergy, swater, splaytime, slastshave, sbloodyhands, stimepassed;

    FGets(file, shealth);
    FGets(file, sblood);
    FGets(file, stemp);
    FGets(file, senergy);
    FGets(file, swater);
    FGets(file, splaytime);
    FGets(file, slastshave);
    FGets(file, sbloodyhands);
    FGets(file, stimepassed);
    GetGame().GetWorld().SetDate( sorigYear.ToInt(), sorigMonth.ToInt(), sorigDay.ToInt(), sorigHour.ToInt() + (stimepassed.ToInt() / (60*60)), sorigMinute.ToInt() + (stimepassed.ToInt() / 60) );

    _player.SetHealth("","", shealth.ToFloat());
    _player.SetHealth("GlobalHealth", "Blood", sblood.ToFloat());
    _player.GetStatTemperature().Set(stemp.ToFloat());
    _player.GetStatEnergy().Set(senergy.ToFloat());
    _player.GetStatWater().Set(swater.ToFloat());
    
    _player.StatRegister("playtime");
    _player.StatUpdate("playtime", splaytime.ToFloat());
    _player.SetLastShavedSeconds(slastshave.ToFloat());
    if(sbloodyhands == "true") {
        _player.SetBloodyHands(true);
    } else {
        _player.SetBloodyHands(false);
    }

    PluginLifespan lifespanp = PluginLifespan.Cast( GetPlugin( PluginLifespan ) );
    lifespanp.UpdateLifespan( _player, true );
    _player.SetSynchDirty();
    
    CloseFile(file);
    GetGame().SelectPlayer( NULL, _player );
    return true;
}

bool savePlayer()
{
    FileHandle file = OpenFile("$profile:playerSave.txt", FileMode.WRITE);
    if ( file == 0 )
    {
        Print("Failed to open $profile:playerSave.txt for writing");
        return false;
    }
    
    PlayerBase _player = GetGame().GetPlayer();
    
    // character model, position, direction
    FPrintln(file, _player.GetType());
    FPrintln(file, _player.GetPosition());
    FPrintln(file, _player.GetDirection());
    
    // weather and date/time
    Weather weather = g_Game.GetWeather();
    int origYear, origMonth, origDay, origHour, origMinute;
    GetGame().GetWorld().GetDate( origYear, origMonth, origDay, origHour, origMinute );

    string overcast = weather.GetOvercast().GetActual().ToString();
    string rain = weather.GetRain().GetActual().ToString();
    string fog = weather.GetFog().GetActual().ToString();
    string wind = weather.GetWindSpeed().ToString();
    FPrintln(file, overcast);
    FPrintln(file, rain);
    FPrintln(file, fog);
    FPrintln(file, wind);
    FPrintln(file, origYear.ToString());
    FPrintln(file, origMonth.ToString());
    FPrintln(file, origDay.ToString());
    FPrintln(file, origHour.ToString());
    FPrintln(file, origMinute.ToString());
    
    // inventory
    array<EntityAI> itemsArray = new array<EntityAI>;
    ItemBase item;
    _player.GetInventory().EnumerateInventory(InventoryTraversalType.PREORDER, itemsArray);

    ItemBase inHands = _player.GetHumanInventory().GetEntityInHands();
    string itemLine = "";
    string itemText = "";
    float itemQty = 0.0;
    float itemQtyMax = 0.0;
    bool firstItem = true;
    for (int i = 0; i < itemsArray.Count(); i++)
    {
        Class.CastTo(item, itemsArray.Get(i));
        if (item && !item.IsInherited(SurvivorBase) && item != inHands) {
            if(firstItem) {
                firstItem = false;
            } else {
                itemLine += ",";
            }
            itemText = item.GetType();
            itemQty = item.GetQuantity();
            itemQtyMax = item.GetQuantityMax();
            if(itemQty == itemQtyMax) {
                itemLine += itemText;
            } else {
                itemLine += itemText + "[" + itemQty.ToString() + "]";
            }
        }
    }
    FPrintln(file, itemLine);
    
    if(inHands) {
        itemLine = "";
        firstItem = true;
        itemText = inHands.GetType();
        itemQty = inHands.GetQuantity();
        itemQtyMax = inHands.GetQuantityMax();
        if(itemQty == itemQtyMax) {
            itemLine = itemText;
        } else {
            itemLine = itemText + "[" + itemQty.ToString() + "]";
        }
        FPrintln(file, itemLine);
    }
    else {
        FPrintln(file, "EMPTY");
    }
    
    // health/etc
    float health =  _player.GetHealth("", "");
    float blood = _player.GetHealth("GlobalHealth", "Blood");
    float temperature = _player.GetStatTemperature().Get();
    float energy = _player.GetStatEnergy().Get();
    float water = _player.GetStatWater().Get();
    float playtime = _player.StatGet("playtime");
    float beard = _player.GetLastShavedSeconds();
    bool hasBloodyHands = _player.HasBloodyHands();
    float timepassed = weather.GetTime();

    FPrintln(file, health);
    FPrintln(file, blood);
    FPrintln(file, temperature);
    FPrintln(file, energy);
    FPrintln(file, water);
    FPrintln(file, playtime);
    FPrintln(file, beard);
    FPrintln(file, hasBloodyHands.ToString());
    FPrintln(file, timepassed);
        
    CloseFile(file);
    return true;
}
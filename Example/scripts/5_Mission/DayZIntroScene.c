/**
* DayZIntroScene.c 
* 
* TH
* www.thebritto.com.br 
* © 2019 - 2021 TH 
* 
* Last Modified: 24/11/2021 
* Modified By: TH
* 
* This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License. 
* To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/. 
* This work is property of TH. You do not have permissions to edit/distribute any of this content without written permission from the content author (TH). 
* Failure to adhere to the content license(s) above will result in actions from Bohemia Interactive Studios and/or Valve.
* 
*/

modded class DayZIntroScene
{
	protected Weather m_Weather;
	protected int m_Animation;

	void DayZIntroScene()
	{
		World world = g_Game.GetWorld();
		string root_path = "cfgCustomScenes " + g_Game.GetWorldName();

		int count = g_Game.ConfigGetChildrenCount(root_path);
		int index = Math.RandomInt(0, count);

		string childName;
		g_Game.ConfigGetChildName(root_path, index, childName);
	
		string scene_path = root_path + " " + childName;	

		vector PlayerPosition = g_Game.ConfigGetVector(scene_path + " PlayerPosition");
		vector PlayerOrientation = g_Game.ConfigGetVector(scene_path + " PlayerOrientation");
		vector CameraPosition = g_Game.ConfigGetVector(scene_path + " CameraPosition");
		float  fov = g_Game.ConfigGetFloat(scene_path + " fov");

		if (world)
		{
			TIntArray date = new TIntArray;
			g_Game.ConfigGetIntArray(scene_path + " date", date);
			world.SetDate(date.Get(0), date.Get(1), date.Get(2), date.Get(3), date.Get(4));
		}

		string item;
		GetGame().ConfigGetText(scene_path + " Hand", item);
		m_Animation = g_Game.ConfigGetInt(scene_path + " Animation");        

		GetGame().ObjectDelete(m_Camera);
		Class.CastTo(m_Camera, g_Game.CreateObject("staticcamera", CameraPosition, true));

		if (m_Camera)
		{
			m_Camera.SetFOV(fov);
			m_Camera.SetFocus(1.0, 0.0);
			m_Camera.SetActive(true);

			TStringArray mapping = new TStringArray;
			g_Game.ConfigGetTextArray(scene_path + " MappingFiles", mapping);
			FilesToLoad(mapping);
		};

		#ifdef BANOVMAP
		//SpawnCharacters();
		#else
		SpawnCharacters();
		#endif

		m_Character = new IntroSceneCharacter();
		m_Character.LoadCharacterData(PlayerPosition, PlayerOrientation);
		GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(m_Character.SetAnim, 30, false, m_Animation); 
		GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(this.UpdateItemInHands, 50, false, item);

		float overcast, rain, windspeed, fog;
		overcast = g_Game.ConfigGetFloat(scene_path + " overcast");
		rain = g_Game.ConfigGetFloat(scene_path + " rain");
		fog = g_Game.ConfigGetFloat(scene_path + " fog");
		m_Weather = g_Game.GetWeather();
		m_Weather.GetOvercast().SetLimits(overcast, overcast);
		m_Weather.GetRain().SetLimits(rain, rain);
		m_Weather.GetFog().SetLimits(fog, fog);
		
		m_Weather.GetOvercast().Set(overcast, overcast, 0);
		m_Weather.GetRain().Set(rain, rain, 0);
		m_Weather.GetFog().Set(fog, fog, 0);
	};

	void UpdateItemInHands(string item)
	{       
		if (item != "")
		{
			if (m_Character.GetCharacterObj().GetItemInHands())
				GetGame().ObjectDelete(m_Character.GetCharacterObj().GetItemInHands());
			m_Character.GetCharacterObj().GetHumanInventory().CreateInHands(item);
		};
	};

	PlayerBase CreateCharacter(vector position, vector rotation, string itemInHands = "", int emote = -1, int stance = -1, string character = "")
	{
	   	if (character == "")
	   	{
	    	character  = GetGame().CreateRandomPlayer();
	   	}

	   	PlayerBase player = PlayerBase.Cast(GetGame().CreateObject(character, position));   
	   
	   	if(position)
	     	player.SetPosition(position);
	   	if(rotation)
	     	player.SetOrientation(rotation);

	   	player.SetPosition(position);
	   	player.SetOrientation(rotation);

	   	player.GetInventory().CreateInInventory(GlassesGame.GetRandomElement());
	   	player.GetInventory().CreateInInventory(GlovesGame.GetRandomElement());
	   	player.GetInventory().CreateInInventory(ShirtsGame.GetRandomElement());
	   	player.GetInventory().CreateInInventory(VestsGame.GetRandomElement());
	   	player.GetInventory().CreateInInventory(PantsGame.GetRandomElement());
	   	player.GetInventory().CreateInInventory(ShoesGame.GetRandomElement());
	   	player.GetInventory().CreateInInventory(BeltGame.GetRandomElement());
	   	player.GetInventory().CreateInInventory(BagsGame.GetRandomElement());

	   	if (itemInHands != "")
	   	{
			player.GetHumanInventory().CreateInHands(itemInHands);
	   	}

		if (emote != -1 && stance != -1)
      	{
         	GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(StartAction, 500, true, player, emote, stance);
      	};

	  	return player;
	};

    PlayerBase StartAction (PlayerBase player, int emote = -1, int stance = -1)
    {
        player.StartCommand_Action(emote , ActionBaseCB, stance);
        return player;
    };

	void SpawnCharacters()
	{
		string mapname = "";

		GetGame().GetWorldName(mapname);
		mapname.ToLower();

		if (mapname == "chernarusplus")
		{
			//Chernogorsk
			CreateCharacter("5930.819824 88.513786 3312.065186", "18.999971 0.000000 0.000000",	"WoodAxe", DayZPlayerConstants.CMD_ACTIONFB_HACKTREE, DayZPlayerConstants.STANCEMASK_ERECT);
			CreateCharacter("5928.558105 88.658371 3305.085205", "19.999975 0.000000 0.000000",	"Hammer", DayZPlayerConstants.CMD_ACTIONFB_CRAFTING, DayZPlayerConstants.STANCEMASK_ERECT);
			CreateCharacter("5926.188965 88.736275 3304.417969", "-7.999997 0.000000 0.000000",	"CombatKnife", DayZPlayerConstants.CMD_ACTIONFB_ANIMALSKINNING, DayZPlayerConstants.STANCEMASK_ERECT);

			//Market
			CreateCharacter("3686.830078 404.339996 5982.439941", "160.266998 0.000000 0.000000");
			CreateCharacter("3697.249512 402.01 5977.625488", "70.482124 0.000000 -0.000000");
			CreateCharacter("3696.455811 402.01 5980.193359", "72.855278 0.000000 -0.000000");
			CreateCharacter("3710.121826 402.01 5976.164063", "-72.449707 0.000000 0.000000");
			CreateCharacter("3708.786865 402.01 5974.589844", "-131.125488 0.000000 -0.000000");
			CreateCharacter("3710.265137 402.01 5973.340820", "-158.777390 0.000000 -0.000000");
			CreateCharacter("3698.172607 402.01 5995.337402", "-93.593155 0.000000 -0.000000");
			CreateCharacter("3714.531006 402.138 5961.776367", "-166.883499 0.000000 -0.000000");
			CreateCharacter("3729.029541 402.651 5969.476563", "-62.680214 0.000000 -0.000000");
			CreateCharacter("3690.062988 402.100067 6006.763672", "131.954376 0.000000 -0.000000");
			CreateCharacter("3699.629883 402.01 5993.970215", "116.581993 0.000000 0.000000");
			CreateCharacter("3674.669922 406.760 5990.390137", "95.741592 0.000000 0.000000");
			CreateCharacter("3699.030029 402.013000 5973.439941", "68.550491 0.000000 0.000000");
		};
	};

	void FilesToLoad(TStringArray filestoload)
	{
		string className;
		vector position;
		vector rotation;
		for (int i = 0; i < filestoload.Count(); i++)
		{
			string name = filestoload[i];

			string filePath = name + ".map";
			FileHandle file = OpenFile(filePath, FileMode.READ);
			if (!file)
				return;
			array< Object > objects = new array< Object >;

			while (GetObjectFromFile(file, className, position, rotation))
			{	
				Object obj;
				obj = GetGame().CreateObject(className, position);

				if(position)
				obj.SetPosition(position);

				if(rotation)
				obj.SetOrientation(rotation);

				obj.SetPosition(position);
				obj.SetOrientation(rotation);		
			};
		};
	};

	private bool GetObjectFromFile(FileHandle file, out string name, out vector position, out vector rotation)
	{
		string line;
		int lineSize = FGets(file, line);

		if (lineSize < 1)
			return false;
		
		ref TStringArray tokens = new TStringArray;
		line.Split("|", tokens);

		name = tokens.Get(0);		
		position = tokens.Get(1).ToVector();
		rotation = tokens.Get(2).ToVector();	

		return true;
	};
};
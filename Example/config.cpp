class CfgPatches
{
	class Example
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data"};
	};
};

class CfgMods
{
	class Example
	{
		dir = "";
		picture = "";
		action = "";
		hideName = 0;
		hidePicture = 0;
		name = "";
		credits = "";
		author = "";
		authorID = "0";
		version = "0.1";
		extra = 0;
		type = "mod";
		inputs = "Example/inputs/inputs.xml";
		dependencies[] = {"Game","World","Mission"};
		class defs
		{
			class gameScriptModule
			{
				files[] = {"Example/scripts/3_Game"};
			};
			class worldScriptModule
			{
				files[] = {"Example/scripts/4_World"};
			};
			class missionScriptModule
			{
				files[] = {"Example/scripts/5_Mission"};
			};
		};
	};
};

class cfgCustomScenes
{
	class ChernarusPlus
	{
		class Chernogorsk
		{
			PlayerPosition[] = {5928.615234, 88.646721, 3307.680908};
            PlayerOrientation[] = {-70.999794, 0.000000, 0.000000};
            CameraPosition[] = {5921.136230, 90.551735, 3310.168945};
            fov = 0.50;
			overcast = 0;
			rain = 0;
			fog = 0;
			date[] = {1997, 1, 15, 00, 00};
			Animation = 1051;
			Hand = "";
			MappingFiles[] = {"Example/gui/data/mapping/cherno"};
		};
		class Market
		{
			PlayerPosition[] = {3709.31, 402.012, 5972.07};
			CameraPosition[] = {3709.27, 403.50, 5969.98};
			PlayerOrientation[] = {-180, 0.000000, 0.000000};
            fov = 1.0;
			overcast = 0;
			rain = 0;
			fog = 0;
			date[] = {1997, 1, 15, 12, 00};
			Animation = -1;
			HandItem = "";
			MappingFiles[] = {"Example/gui/data/mapping/trader"};
		};
	};
	class Deerisle
	{
		class loc1
		{
            PlayerPosition[] = {526.447144, 3.288893, 12292.446289};
            PlayerOrientation[] = {-102.999580, 0.000000, 0.000000};
            CameraPosition[] = {522.109619, 4.080920, 12291.453125};
            fov = 0.75;
			overcast = 0;
			rain = 0;
			fog = 0;
			date[] = {1997, 1, 15, 12, 00};
			Animation = -1;
			Hand = "";
		};	
	};
	class Chiemsee
	{
		class loc1
		{
            PlayerPosition[] = {9148.746094, 88.959999, 10193.042969};
            PlayerOrientation[] = {149, 0, 0};
            CameraPosition[] = {9153.825195, 90.3, 10186.232422};
            fov = 0.35;
            overcast = 0;
			rain = 0;
			fog = 0;
			date[] = {1997, 1, 15, 12, 00};
			Animation = -1;
			Hand = "";
		};	
	};
	class Namalsk
	{
		class loc1
		{
            PlayerPosition[] = {8406.740234, 2.000000, 7809.499512};
            PlayerOrientation[] = {60, 0, 0};
            CameraPosition[] = {8410.674805, 3.000000, 7812.270996};
            fov = 0.50;
            overcast = 0;
			rain = 0;
			fog = 0;
			date[] = {1997, 1, 15, 12, 00};
			Animation = -1;
			Hand = "";
		};
	};
	class Banov
	{
		class loc1
		{
            PlayerPosition[] = {1983.630005, 223.423004, 2462.449951};
            PlayerOrientation[] = {-161.781982, 0.000000, 0.000000};
            CameraPosition[] = {1982.449951, 224.371216, 2459.016846};
            fov = 0.50;
            overcast = 0;
			rain = 0;
			fog = 0;
			date[] = {1997, 1, 15, 12, 00};
			Animation = -1;
			Hand = "";
		};
	};
	class TakistanPlus
	{
		class loc1
		{
            PlayerPosition[] = {5943.619629, 83.040001, 11859.925781};
            PlayerOrientation[] = {152, 0, 0};
            CameraPosition[] = {5946.687500, 84.040001, 11853.825195};
            fov = 0.50;
            overcast = 0;
			rain = 0;
			fog = 0;
			date[] = {1997, 1, 15, 12, 00};
			Animation = -1;
			Hand = "";
		};
	};
};

class CfgSoundSets
{
	class Main_Music_Menu_SoundSet
	{
		soundShaders[] = {"Main_Music_Menu_SoundShader"};
		volumeFactor = 1;
		frequencyFactor = 1;
		spatial = 0;
	};
};	

class CfgSoundShaders
{
	class Main_Music_Menu_SoundShader
	{
		samples[] = {{"Example\gui\sounds\MainMenu.ogg", 1}};
		volume = 0.25;
	};
};
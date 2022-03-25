/**
* Settings.c 
* 
* TH
* www.thebritto.com.br 
* © 2019 - 2021 TH 
* 
* Last Modified: 24/11/2021 
* Modified By: TH
* Created: 07/09/2019
* 
* This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License. 
* To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/. 
* This work is property of TH. You do not have permissions to edit/distribute any of this content without written permission from the content author (TH). 
* Failure to adhere to the content license(s) above will result in actions from Bohemia Interactive Studios and/or Valve.
* 
*/

// Deathscreen
static bool m_ShowDeadScreen = false;
const string ShowDeadScreenImage = "Example/gui/data/deathscreen/deathscreen.edds";

// Colors
const int UIColor = ARGB(255, 235, 168, 68);
const int UIColorText = ARGB(255, 235, 168, 68);

// Logotipo
const bool ShowLogo = true;
const string logotipo = "Example/gui/data/logotipo/logotipo.edds";

//Random Messages
autoptr TStringArray RandomMessage = {"thebritto.com.br","thebritto.com.br/discord","thebritto.com.br/twitter","thebritto.com.br/youtube"}; //unlimited number
const bool ShowMessage = true;

//Random Loading
autoptr TStringArray LoadingGame = {"Example/gui/data/loadingscreen/wallpaper_example.edds"};
autoptr TStringArray LoginGame = {"Example/gui/data/loadingscreen/wallpaper_example.edds"};
autoptr TStringArray QueueGame = {"Example/gui/data/loadingscreen/wallpaper_example.edds"};

//Links
const string DiscordLink = "https://discord.com/invite/NEX27Gx";
const string DiscordLinkImage = "Example/gui/data/social/discord.edds";
const string DiscordLinkImage_hover = "Example/gui/data/social/discord_hover.edds";
const bool DiscordLinkShow = true;

const string SteamLink = "https://steamcommunity.com/id/thebritto/";
const string SteamLinkImage = "Example/gui/data/social/steam.edds";
const string SteamLinkImage_hover = "Example/gui/data/social/steam_hover.edds";
const bool SteamLinkShow = true;

const string FacebookLink = "https://www.facebook.com/plurnstyle/";
const string FacebookLinkImage = "Example/gui/data/social/facebook.edds";
const string FacebookLinkImage_hover = "Example/gui/data/social/facebook_hover.edds";
const bool FacebookLinkShow = true;

const string TwitterLink = "https://twitter.com/Plurnstyle";
const string TwitterLinkImage = "Example/gui/data/social/twitter.edds";
const string TwitterLinkImage_hover = "Example/gui/data/social/twitter_hover.edds";
const bool TwitterLinkShow = true;

const string RedditLink = "https://www.reddit.com/";
const string RedditLinkImage = "Example/gui/data/social/reddit.edds";
const string RedditLinkImage_hover = "Example/gui/data/social/reddit_hover.edds";
const bool RedditLinkShow = false;

const string YoutubeLink = "https://www.youtube.com/channel/UCYmQbgV1klkzPlpUDhg7YlQ";
const string YoutubeLinkImage = "Example/gui/data/social/youtube.edds";
const string YoutubeLinkImage_hover = "Example/gui/data/social/youtube_hover.edds";
const bool YoutubelInkShow = true;

const string PayPalLink = "https://www.paypal.com/donate?hosted_button_id=WY6TQGUR9J9T4";
const string PayPalLinkImage = "Example/gui/data/social/paypal.edds";
const string PayPalLinkImage_hover = "Example/gui/data/social/paypal_hover.edds";
const bool PayPalLinkShow = true;

const string TwitchLink = "https://www.twitch.tv/plurnstyle";
const string TwitchLinkImage = "Example/gui/data/social/twitch.edds";
const string TwitchLinkImage_hover = "Example/gui/data/social/twitch_hover.edds";
const bool TwitchLinkShow = false;

const string InstagramLink = "https://www.instagram.com/plurnstyle/";
const string InstagramLinkImage = "Example/gui/data/social/instagram.edds";
const string InstagramLinkImage_hover = "Example/gui/data/social/instagram_hover.edds";
const bool InstagramLinkShow = false;

const string GitHubLink = "https://github.com/Plurnstyle";
const string GitHubLinkImage = "Example/gui/data/social/gitHub.edds";
const string GitHubLinkImage_hover = "Example/gui/data/social/gitHub_hover.edds";
const bool GitHubLinkShow = false;

const string TikTokLink = "https://www.tiktok.com/";
const string TikTokLinkImage = "Example/gui/data/social/tiktok.edds";
const string TikTokLinkImage_hover = "Example/gui/data/social/tiktok_hover.edds";
const bool TikTokLinkShow = false;

//Random clothing in PlayerBase into main menu
autoptr TStringArray HatsGame = {"ConstructionHelmet_Blue","ConstructionHelmet_Lime","MotoHelmet_Lime","BoonieHat_Tan","ConstructionHelmet_Orange","BoonieHat_Red","BaseballCap_Beige","PrisonerCap","BallisticHelmet_UN","DarkMotoHelmet_Yellow","BeanieHat_Brown","ConstructionHelmet_Red","HockeyHelmet_Red","SkateHelmet_Blue","RadarCap_Green","DarkMotoHelmet_White","BaseballCap_Red","OfficerHat","Mich2001Helmet","DirtBikeHelmet_Police","WitchHood_Black","BoonieHat_Flecktran","WitchHood_Red","Ssh68Helmet","MotoHelmet_Green","FirefightersHelmet_White","FlatCap_Red","GorkaHelmet","PoliceCap","MedicalScrubsHat_White","DirtBikeHelmet_Chernarus","DirtBikeHelmet_Visor","DirtBikeHelmet_Black","DarkMotoHelmet_Black","BoonieHat_Dubok","MotoHelmet_Yellow","LeatherHat_Beige","BallisticHelmet_Green","HockeyHelmet_White","ConstructionHelmet_White","BoonieHat_DPM","FirefightersHelmet_Red","SkateHelmet_Green","FlatCap_BrownCheck","BaseballCap_CMMG_Black","BaseballCap_Camo","SkateHelmet_Gray","MilitaryBeret_NZ","Ushanka_Black","MedicalScrubsHat_Blue","BeanieHat_Green","ZSh3PilotHelmet","MotoHelmet_Grey","BaseballCap_Blue","BaseballCap_CMMG_Pink","MedicalScrubsHat_Green","CowboyHat_green","LeatherHat_Natural","FlatCap_Blue","DarkMotoHelmet_Red","DarkMotoHelmet_Grey","MotoHelmet_Red","FirefightersHelmet_Yellow","Ushanka_Blue","DarkMotoHelmet_Green","ConstructionHelmet_Yellow","TankerHelmet","RadarCap_Brown","FlatCap_Grey","CowboyHat_Brown","MotoHelmet_Blue","RadarCap_Blue","RadarCap_Red","GreatHelm","CowboyHat_darkBrown","Ushanka_Green","BallisticHelmet_Black","DarkMotoHelmet_Blue","RadarCap_Black","DirtBikeHelmet_Green","BoonieHat_NavyBlue","MilitaryBeret_UN","WitchHood_Brown","FlatCap_GreyCheck","WitchHat","SkateHelmet_Black","BeanieHat_Black","BoonieHat_Olive","DirtBikeHelmet_Blue","BaseballCap_Olive","BeanieHat_Red","DirtBikeHelmet_Khaki","BeanieHat_Grey","MilitaryBeret_ChDKZ","MotoHelmet_Black","HockeyHelmet_Black","LeatherHat_Black","BoonieHat_Orange","BoonieHat_Blue","BeanieHat_Blue","SkateHelmet_Red","MotoHelmet_White","HockeyHelmet_Blue","LeatherHat_Brown","MilitaryBeret_CDF","BaseballCap_Pink","FlatCap_BlackCheck","FlatCap_Black","DirtBikeHelmet_Red","DirtBikeHelmet_Mouthguard","BeanieHat_Pink","MilitaryBeret_Red","DarkMotoHelmet_Lime","BaseballCap_Black","BeanieHat_Beige","BoonieHat_Black","FlatCap_Brown","CowboyHat_black"};
autoptr TStringArray MasksGame = {"BalaclavaMask_White","Bandana_Redpattern","Balaclava3Holes_Beige","BalaclavaMask_Beige","BalaclavaMask_Pink","Balaclava3Holes_Black","BalaclavaMask_Green","SurgicalMask","BalaclavaMask_Blackskull","WeldingMask","Bandana_Blackpattern","NioshFaceMask","BalaclavaMask_Blue","Bandana_Greenpattern","Bandana_Polkapattern","Balaclava3Holes_Blue","BalaclavaMask_Black","Bandana_Camopattern","Balaclava3Holes_Green","HockeyMask"};
autoptr TStringArray GlassesGame = {"AviatorGlasses","DesignerGlasses","SportGlasses_Black","SportGlasses_Blue","SportGlasses_Green","SportGlasses_Orange","ThickFramesGlasses","ThinFramesGlasses"};
autoptr TStringArray GlovesGame = {"SurgicalGloves_White","LeatherGloves_Natural","OMNOGloves_Brown","SurgicalGloves_LightBlue","WorkingGloves_Brown","SurgicalGloves_Blue","TacticalGloves_Black", "WorkingGloves_Black","WorkingGloves_Yellow","TacticalGloves_Green","SurgicalGloves_Green","LeatherGloves_Brown","WorkingGloves_Beige","OMNOGloves_Gray","LeatherGloves_Black","LeatherGloves_Beige","TacticalGloves_Beige"};
autoptr TStringArray Armband ={"Armband_Black","Armband_Blue","Armband_Green","Armband_Orange","Armband_Pink","Armband_Red","Armband_White","Armband_Yellow"};
autoptr TStringArray ShirtsGame = {"Raincoat_Pink","HuntingJacket_Spring","HikingJacket_Black","QuiltedJacket_Black","QuiltedJacket_Green","FirefighterJacket_Beige","WoolCoat_Green","Shirt_GreenCheck","JumpsuitJacket_Red","QuiltedJacket_Violet","ParamedicJacket_Green","Shirt_BlueCheckBright","WoolCoat_BlackCheck","Raincoat_Red","TrackSuitJacket_Green","ManSuit_Black","TrackSuitJacket_LightBlue","HuntingJacket_Winter","WomanSuit_Beige","TShirt_Blue","WomanSuit_Brown","QuiltedJacket_Red","ManSuit_DarkGrey","WomanSuit_White","TacticalShirt_Grey","Sweater_Red","TrackSuitJacket_Blue","USMCJacket_Desert","Sweater_Blue","PoliceJacket","HikingJacket_Red","HuntingJacket_Brown","BomberJacket_Brown","USMCJacket_Woodland","LeatherJacket_Beige","TacticalShirt_Olive","HuntingJacket_Autumn","GorkaEJacket_Summer","HikingJacket_Blue","LeatherJacket_Black","Raincoat_Blue","HikingJacket_Green","PrisonUniformJacket","WoolCoat_Red","ParamedicJacket_Blue","Hoodie_Black","Shirt_BlueCheck","Raincoat_Black","Hoodie_Brown","QuiltedJacket_Blue","DenimJacket","JumpsuitJacket_Blue","Raincoat_Orange","TShirt_Green","BomberJacket_Grey","WomanSuit_LightGrey","WomanSuit_Black","TrackSuitJacket_Red","Hoodie_Red","ManSuit_LightGrey","ManSuit_Brown","QuiltedJacket_Grey","FirefighterJacket_Black","Sweater_Gray","TTsKOJacket_Camo","WoolCoat_Black","BomberJacket_Maroon","GorkaEJacket_PautRev","TrackSuitJacket_Black","QuiltedJacket_Yellow","TShirt_Red","Shirt_RedCheck","BDUJacket","TShirt_Black","ManSuit_Khaki","BomberJacket_Olive","TShirt_Grey","M65Jacket_Tan","BomberJacket_Blue","Shirt_WhiteCheck","JumpsuitJacket_Green","WoolCoat_Beige","TShirt_White","Raincoat_Yellow","WomanSuit_DarkGrey","M65Jacket_Black","Hoodie_Blue","M65Jacket_Khaki","LabCoat","WoolCoat_GreyCheck","ParamedicJacket_Crimson","TacticalShirt_Black","TShirt_RedBlackStripes","BomberJacket_Black","TacticalShirt_Tan","JumpsuitJacket_Gray","ManSuit_Blue","Hoodie_Green","Shirt_PlaneBlack","BomberJacket_SkyBlue","WoolCoat_RedCheck","MedicalScrubsShirt_Green","ManSuit_Beige","Sweater_Green","GorkaEJacket_Flat","ManSuit_White","LeatherJacket_Brown","MedicalScrubsShirt_Blue","TShirt_OrangeWhiteStripes","Raincoat_Green","HuntingJacket_Summer","Hoodie_Grey","M65Jacket_Olive","WomanSuit_Blue","MedicalScrubsShirt_White","WoolCoat_Blue","LeatherJacket_Natural","WoolCoat_BrownCheck","QuiltedJacket_Orange","WomanSuit_Khaki","WoolCoat_BlueCheck","TShirt_Beige","LeatherShirt_Natural","RidersJacket_Black","GorkaEJacket_Autumn"};
autoptr TStringArray VestsGame = {"UKAssVest_Camo","PressVest_LightBlue","LeatherStorageVest_Brown","ReflexVest","UKAssVest_Olive","PoliceVest","LeatherStorageVest_Natural","LeatherStorageVest_Beige","HighCapacityVest_Black", "UKAssVest_Black","PressVest_Blue", "LeatherStorageVest_Black","HighCapacityVest_Olive","UKAssVest_Khaki"};
autoptr TStringArray BagsGame = {"HuntingBag","LeatherSack_Natural","AliceBag_Black","FurCourierBag","LeatherSack_Beige","TortillaBag","MountainBag_Blue","ImprovisedBag","AliceBag_Camo","DryBag_Blue","TaloonBag_Violet","ChildBag_Blue","DryBag_Red","MountainBag_Green","AssaultBag_Ttsko","LeatherSack_Brown","ChildBag_Red","TaloonBag_Blue","LeatherSack_Black","CoyoteBag_Green","AssaultBag_Black","AssaultBag_Green","DryBag_Green","MountainBag_Red","MountainBag_Orange","TaloonBag_Orange","CoyoteBag_Brown","DryBag_Yellow","AliceBag_Green","DryBag_Black","ChildBag_Green","DryBag_Orange","TaloonBag_Green","CourierBag","FurImprovisedBag"};
autoptr TStringArray BeltGame = {"LeatherBelt_Beige","LeatherBelt_Black","LeatherBelt_Brown","LeatherBelt_Natural","MilitaryBelt","CivilianBelt"};
autoptr TStringArray PantsGame = {"TrackSuitPants_Blue","CargoPants_Black","HunterPants_Spring","CanvasPantsMidi_Violet","NurseDress_Blue","CanvasPants_Violet","LeatherPants_Black","CanvasPants_Red","FirefightersPants_Black","CanvasPants_Grey","SlacksPants_DarkGrey","SlacksPants_Blue","PolicePants","MedicalScrubsPants_Green","ParamedicPants_Crimson","SlacksPants_LightGrey","CanvasPantsMidi_Beige","GorkaPants_PautRev","MiniDress_Pink","HunterPants_Autumn","JumpsuitPants_Red","MiniDress_BlueChecker","Skirt_Yellow","CargoPants_Beige","Jeans_Brown","GorkaPants_Autumn","NurseDress_White","Breeches_Red","HunterPants_Winter","Breeches_Blackcheck","USMCPants_Woodland","BDUPants","ShortJeans_Black","Breeches_White","USMCPants_Desert","GorkaPants_Flat","Skirt_Blue","MiniDress_BrownChecker","SlacksPants_Brown","MiniDress_GreenChecker","ShortJeans_Brown","PoliceJacketOrel","JumpsuitPants_Blue","PolicePantsOrel","TrackSuitPants_LightBlue","CargoPants_Grey","ShortJeans_Blue","Breeches_Green","CanvasPantsMidi_Blue","Breeches_Beetcheck","TTSKOPants","LeatherPants_Natural","Jeans_Black","FirefightersPants_Beige","ParamedicPants_Green","LeatherPants_Beige","Breeches_Browncheck","SlacksPants_Khaki","PrisonUniformPants","MiniDress_PinkChecker","MiniDress_RedChecker","ShortJeans_Green","Breeches_Beige","TrackSuitPants_Black","ParamedicPants_Blue","Breeches_Black","Jeans_Green","GorkaPants_Summer","Skirt_White","CanvasPantsMidi_Red","Breeches_Pink","CargoPants_Green","ShortJeans_Red","SlacksPants_White","CargoPants_Blue","CanvasPants_Beige","MiniDress_BlueWithDots","Breeches_Blue","HunterPants_Brown","CanvasPants_Blue","ShortJeans_Darkblue","SlacksPants_Beige","JumpsuitPants_Green","JumpsuitPants_Grey","CanvasPantsMidi_Grey","MedicalScrubsPants_White","TrackSuitPants_Red","Skirt_Red","TrackSuitPants_Green","Jeans_BlueDark","SlacksPants_Black","LeatherPants_Brown","Jeans_Grey","MiniDress_WhiteChecker","MedicalScrubsPants_Blue","Jeans_Blue","HunterPants_Summer"};
autoptr TStringArray ShoesGame = {"HikingBootsLow_Black","DressShoes_Sunburst","MilitaryBoots_Bluerock","DressShoes_Black","CombatBoots_Brown","WorkingBoots_Beige","WorkingBoots_Green","DressShoes_Brown","WorkingBoots_Yellow","CombatBoots_Black","AthleticShoes_Brown","Sneakers_Red","JoggingShoes_White","LeatherShoes_Black","WorkingBoots_Grey","Wellies_Brown","JungleBoots_Green","Sneakers_Gray","Wellies_Black","Wellies_Grey","AthleticShoes_Grey","CombatBoots_Green","MilitaryBoots_Black","JoggingShoes_Blue","CombatBoots_Beige","Sneakers_Green","JungleBoots_Black","AthleticShoes_Green","JungleBoots_Brown","DressShoes_White","WorkingBoots_Brown","HikingBootsLow_Blue","HikingBootsLow_Beige","MilitaryBoots_Redpunk","LeatherShoes_Brown","LeatherShoes_Natural","JoggingShoes_Red","AthleticShoes_Black","HikingBoots_Brown","AthleticShoes_Blue","CombatBoots_Grey","Sneakers_Black","LeatherShoes_Beige","MilitaryBoots_Beige","HikingBoots_Black","HikingBootsLow_Grey","Wellies_Green","JoggingShoes_Black","JungleBoots_Beige","JoggingShoes_Violet","MilitaryBoots_Brown","JungleBoots_Olive","TTSKOBoots","DressShoes_Beige","Sneakers_White"};
autoptr TStringArray SheltersGame = {"ShelterFabric","ShelterLeather","ShelterStick"};
autoptr TStringArray AnimalsGame = {"Animal_BosTaurusF_Brown","Animal_BosTaurusF_Spotted","Animal_BosTaurusF_White","Animal_BosTaurus_Brown","Animal_BosTaurus_Spotted","Animal_BosTaurus_White","Animal_CanisLupus_Grey","Animal_CanisLupus_White","Animal_CapraHircusF","Animal_CapraHircus_Black","Animal_CapraHircus_Brown","Animal_CapraHircus_White","Animal_CapreolusCapreolus","Animal_CapreolusCapreolusF","Animal_CervusElaphus","Animal_CervusElaphusF","Animal_GallusGallusDomesticus","Animal_GallusGallusDomesticusF_Brown","Animal_GallusGallusDomesticusF_Spotted","Animal_GallusGallusDomesticusF_White","Animal_OvisAries","Animal_OvisAriesF","Animal_SusDomesticus","Animal_SusScrofa","Animal_UrsusArctos"};
autoptr TStringArray ZombiesGame = {"ZmbF_BlueCollarFat_Blue","ZmbF_BlueCollarFat_Green","ZmbF_BlueCollarFat_Red","ZmbF_BlueCollarFat_White","ZmbF_CitizenANormal_Beige","ZmbF_CitizenANormal_Blue","ZmbF_CitizenANormal_Brown","ZmbF_CitizenBSkinny","ZmbF_Clerk_Normal_Blue","ZmbF_Clerk_Normal_Green","ZmbF_Clerk_Normal_Red","ZmbF_Clerk_Normal_White","ZmbF_DoctorSkinny","ZmbF_HikerSkinny_Blue","ZmbF_HikerSkinny_Green","ZmbF_HikerSkinny_Grey","ZmbF_HikerSkinny_Red","ZmbF_JoggerSkinny_Blue","ZmbF_JoggerSkinny_Brown","ZmbF_JoggerSkinny_Green","ZmbF_JoggerSkinny_Red","ZmbF_JournalistNormal_Blue","ZmbF_JournalistNormal_Green","ZmbF_JournalistNormal_Red","ZmbF_JournalistNormal_White","ZmbF_MechanicNormal_Beige","ZmbF_MechanicNormal_Green","ZmbF_MechanicNormal_Grey","ZmbF_MechanicNormal_Orange","ZmbF_MilkMaidOld_Beige","ZmbF_MilkMaidOld_Black","ZmbF_MilkMaidOld_Green","ZmbF_MilkMaidOld_Grey","ZmbF_NurseFat","ZmbF_ParamedicNormal_Blue","ZmbF_ParamedicNormal_Green","ZmbF_ParamedicNormal_Red","ZmbF_PatientOld","ZmbF_PoliceWomanNormal","ZmbF_ShortSkirt_beige","ZmbF_ShortSkirt_black","ZmbF_ShortSkirt_brown","ZmbF_ShortSkirt_checks","ZmbF_ShortSkirt_green","ZmbF_ShortSkirt_grey","ZmbF_ShortSkirt_red","ZmbF_ShortSkirt_stripes","ZmbF_ShortSkirt_white","ZmbF_ShortSkirt_yellow","ZmbF_SkaterYoung_Brown","ZmbF_SkaterYoung_Striped","ZmbF_SkaterYoung_Violet","ZmbF_SurvivorNormal_Blue","ZmbF_SurvivorNormal_Orange","ZmbF_SurvivorNormal_Red","ZmbF_SurvivorNormal_White","ZmbF_VillagerOld_Blue","ZmbF_VillagerOld_Green","ZmbF_VillagerOld_Red","ZmbF_VillagerOld_White","ZmbM_CitizenASkinny_Blue","ZmbM_CitizenASkinny_Brown","ZmbM_CitizenASkinny_Grey","ZmbM_CitizenASkinny_Red","ZmbM_CitizenBFat_Blue","ZmbM_CitizenBFat_Green","ZmbM_CitizenBFat_Red","ZmbM_ClerkFat_Brown","ZmbM_ClerkFat_Grey","ZmbM_ClerkFat_Khaki","ZmbM_ClerkFat_White","ZmbM_CommercialPilotOld_Blue","ZmbM_CommercialPilotOld_Brown","ZmbM_CommercialPilotOld_Grey","ZmbM_CommercialPilotOld_Olive","ZmbM_ConstrWorkerNormal_Beige","ZmbM_ConstrWorkerNormal_Black","ZmbM_ConstrWorkerNormal_Green","ZmbM_ConstrWorkerNormal_Grey","ZmbM_DoctorFat","ZmbM_FarmerFat_Beige","ZmbM_FarmerFat_Blue","ZmbM_FarmerFat_Brown","ZmbM_FarmerFat_Green","ZmbM_FiautoptrighterNormal","ZmbM_FishermanOld_Blue","ZmbM_FishermanOld_Green","ZmbM_FishermanOld_Grey","ZmbM_FishermanOld_Red","ZmbM_HandymanNormal_Beige","ZmbM_HandymanNormal_Blue","ZmbM_HandymanNormal_Green","ZmbM_HandymanNormal_Grey","ZmbM_HandymanNormal_White","ZmbM_HeavyIndustryWorker","ZmbM_HermitSkinny_Beige","ZmbM_HermitSkinny_Black","ZmbM_HermitSkinny_Green","ZmbM_HermitSkinny_Red","ZmbM_HikerSkinny_Blue","ZmbM_HikerSkinny_Green","ZmbM_HikerSkinny_Yellow","ZmbM_HunterOld_Autumn","ZmbM_HunterOld_Spring","ZmbM_HunterOld_Summer","ZmbM_HunterOld_Winter","ZmbM_Jacket_beige","ZmbM_Jacket_black","ZmbM_Jacket_blue","ZmbM_Jacket_bluechecks","ZmbM_Jacket_brown","ZmbM_Jacket_greenchecks","ZmbM_Jacket_grey","ZmbM_Jacket_khaki","ZmbM_Jacket_magenta","ZmbM_Jacket_stripes","ZmbM_JoggerSkinny_Blue","ZmbM_JoggerSkinny_Green","ZmbM_JoggerSkinny_Red","ZmbM_JournalistSkinny","ZmbM_MechanicSkinny_Blue","ZmbM_MechanicSkinny_Green","ZmbM_MechanicSkinny_Grey","ZmbM_MechanicSkinny_Red","ZmbM_MotobikerFat_Beige","ZmbM_MotobikerFat_Black","ZmbM_MotobikerFat_Blue","ZmbM_OffshoreWorker_Green","ZmbM_OffshoreWorker_Orange","ZmbM_OffshoreWorker_Red","ZmbM_OffshoreWorker_Yellow","ZmbM_ParamedicNormal_Black","ZmbM_ParamedicNormal_Blue","ZmbM_ParamedicNormal_Green","ZmbM_ParamedicNormal_Red","ZmbM_PatientSkinny","ZmbM_PatrolNormal_Autumn","ZmbM_PatrolNormal_Flat","ZmbM_PatrolNormal_PautRev","ZmbM_PatrolNormal_Summer","ZmbM_PolicemanFat","ZmbM_PolicemanSpecForce","ZmbM_PrisonerSkinny","ZmbM_SkaterYoung_Blue","ZmbM_SkaterYoung_Brown","ZmbM_SkaterYoung_Green","ZmbM_SkaterYoung_Grey","ZmbM_SoldierNormal","ZmbM_VillagerOld_Blue","ZmbM_VillagerOld_Green","ZmbM_VillagerOld_White","ZmbM_priestPopSkinny","ZmbM_usSoldier_normal_Desert","ZmbM_usSoldier_normal_Woodland"};

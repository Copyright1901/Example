 /**
* IngameHud.c 
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

modded class IngameHud extends Hud
{
	override void SetStamina(int value, int range)
	{
		bool debugStaminaHud = false;
		int newValue;
		float sx, sy;
		float max = 100;
		range = max;

		if (value > 100)
			newValue = value - 100;
		else
			newValue = value;

		float percentage =  range / max;
		m_Stamina.SetCurrent((newValue / range ) * max );
		m_Stamina.GetSize(sx, sy );
		m_Stamina.SetSize(percentage, sy );
		m_StaminaBackground.SetSize(1.2, sy);

		if (value > 100)
		{
			m_StaminaBackground.SetColor(ARGB(255, 0, 0, 255) );
		}
		else
		{
			m_StaminaBackground.SetColor(ARGB(255, 0, 0, 0) );
			if((value <= 100) && (value >= 80))
				m_Stamina.SetColor(ARGB(255, 102, 255, 102 ) );
			if((value <= 80) && (value >= 60))
				m_Stamina.SetColor(ARGB(255, 178, 255, 102 ) );
			if((value < 60) && (value >= 40)) 
				m_Stamina.SetColor(ARGB(255, 255, 255, 102 ) );
			if((value < 40) && (value >= 20)) 
				m_Stamina.SetColor(ARGB(255, 255, 176, 102 ) );
			if((value < 20) && (value >= 0)) 
				m_Stamina.SetColor(ARGB(255, 255, 102, 102 ) );
		};
	};

	override void DisplayTendencyNormal(int key, int tendency, int status)
	{
		ImageWidget w;
		Class.CastTo(w, m_Notifiers.FindAnyWidget(String("Icon" + m_StatesWidgetNames.Get(key))));
		
		if(w)
		{
			w.SetImage(Math.Clamp(status - 1, 0, 5));
			float alpha = w.GetAlpha();
			
			switch(status)
			{
				case 0:
					w.SetColor(ARGB(alpha * 255, 102, 255, 102));
					m_TendencyStatusCritical.Remove(w);
					break;
				case 1:
					w.SetColor(ARGB(alpha * 255, 178, 255, 102));
					m_TendencyStatusCritical.Remove(w);
					break;
				case 2:
					w.SetColor(ARGB(alpha * 255, 255, 255, 102));
					m_TendencyStatusCritical.Remove(w);
					break;
				case 3:
					w.SetColor(ARGB(alpha * 255, 255, 176, 102));
					m_TendencyStatusCritical.Remove(w);
					break;
				case 4:
					w.SetColor(ARGB(alpha * 255, 255, 102, 102));
					m_TendencyStatusCritical.Remove(w);
					break;
				case 5:
					if (!m_TendencyStatusCritical.Contains(w))
					{
						m_TendencyStatusCritical.Insert(w, ARGB(alpha * 255, 255, 102, 102));
					}
					break;
				default:
					w.SetColor(ARGB(alpha * 255, 102, 255, 102));
					m_TendencyStatusCritical.Remove(w);
					break;
			};
		};
	};

	void DisplayTendencyTemp(int key, int tendency, int status)
	{
		ImageWidget w = ImageWidget.Cast(m_Notifiers.FindAnyWidget(String("Icon" + m_StatesWidgetNames.Get(key))));
		TextWidget temp_top = TextWidget.Cast(m_Notifiers.FindAnyWidget("TemperatureValueTop"));
		TextWidget temp_bot = TextWidget.Cast(m_Notifiers.FindAnyWidget("TemperatureValueBottom"));
		float alpha = w.GetAlpha();
		
		if (tendency < 0)
		{
			temp_top.Show(true);
			temp_bot.Show(false);
		}
		else
		{
			temp_top.Show(false);
			temp_bot.Show(true);
		};

		switch(status)
		{
			case 2:
				w.SetColor(ARGB(alpha * 255, 255, 255, 102));
				m_TendencyStatusCritical.Remove(w);
				w.SetImage(1);
				
				break;
			case 3:
				w.SetColor(ARGB(alpha * 255, 255, 102, 102));
				m_TendencyStatusCritical.Remove(w);
				w.SetImage(0);
				break;
			case 4:
				if (!m_TendencyStatusCritical.Contains(w))
				{
					m_TendencyStatusCritical.Insert(w, ARGB(alpha * 255, 255, 102, 102));
				}
				w.SetImage(0);
				break;
			case 5:
				w.SetColor(ARGB(alpha * 255, 135, 206, 250));
				m_TendencyStatusCritical.Remove(w);
				w.SetImage(3);
				break;
			case 6:
				w.SetColor(ARGB(alpha * 255, 30, 144, 255));
				m_TendencyStatusCritical.Remove(w);
				w.SetImage(4);
				break;
			case 7:
				if (!m_TendencyStatusCritical.Contains(w))
				{
					m_TendencyStatusCritical.Insert(w, ARGB(alpha * 255, 30, 144, 255));
				}
				w.SetImage(4);
				break;				
			default:
				w.SetColor(ARGB(alpha * 255, 220, 220, 220));
				m_TendencyStatusCritical.Remove(w);
				w.SetImage(2);
				break;
		};
	};
};

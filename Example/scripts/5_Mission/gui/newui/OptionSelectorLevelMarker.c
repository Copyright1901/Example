modded class OptionSelectorLevelMarker extends OptionSelectorSliderSetup
{
	void OptionSelectorLevelMarker(Widget parent, float value, ScriptedWidgetEventHandler parentMenu, bool disabled, float min, float max)
	{
		m_Slider.SetColor(UIColor);
		m_Slider2.SetColor(ARGB(255,0,0,0));
	};

	override bool OnMouseEnter(Widget w, int x, int y)
	{
		m_Slider.SetColor(UIColor);
		m_Slider2.SetColor(ARGB(255,0,0,0));
		
		return true;
	};

	override bool OnMouseLeave(Widget w, Widget enterW, int x, int y)
	{
		m_Slider.SetColor(UIColor);
		m_Slider2.SetColor(ARGB(255,0,0,0));
			
		return true;
	};
};
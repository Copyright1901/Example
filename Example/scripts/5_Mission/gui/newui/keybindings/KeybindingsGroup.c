/**
* KeybindingsGroup.c 
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

modded class KeybindingsGroup extends ScriptedWidgetEventHandler
{
	string GetLayoutName()
	{
		return "Example/gui/layouts/new_ui/options/keybindings_selectors/keybinding_group.layout";
	};

	override bool OnMouseEnter(Widget w, int x, int y)
	{
	    ColorHighlight (w);
	    return true;
	}

	override bool OnMouseLeave(Widget w, Widget enterW, int x, int y)
	{
	    ColorNormal (w);
	    return true;
	}

	protected void ColorHighlight(Widget w)
	{
	    if (!w)
	        return;

	    ButtonSetColor(w, ARGB(0, 0, 0, 0));
	    ButtonSetTextColor(w, UIColor);
	};

	protected void ColorNormal(Widget w)
	{
	    if (!w)
	        return;

	    ButtonSetColor(w, ARGB(0, 0, 0, 0));
	    ButtonSetTextColor(w, ARGB(255, 255, 255, 255));
	};

	protected void ButtonSetColor(Widget w, int color)
	{
	    if (!w)
	        return;
	            
	    Widget panel = w.FindWidget(w.GetName() + "_panel");

	    if (panel)
	    {
	        panel.SetColor(color);
	    };
	};

	protected void ButtonSetTextColor(Widget w, int color)
	{
	    if (!w)
	        return;

	    TextWidget label = TextWidget.Cast(w.FindAnyWidget(w.GetName() + "_label"));
	                    
	    if (label)
	    {
	        label.SetColor(color);
	    };
	};
};

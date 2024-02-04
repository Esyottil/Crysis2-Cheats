//credit to some russian guy who made this menu

#include "Includes.h"
char* FOV[7] = { "5","10","20","45","90","180","360" };
char* HEAD[4] = { "Head","Neck", "Arti", "Spine" };
void Menu::DirectEngine(LPDIRECT3DDEVICE9 pD3D9)
{
	x = 10, y = 53, fx = 235, fy = 53;

	DrawBox(10,10,220+225,40,D3DCOLOR_ARGB(255, 219, 96, 8),pD3D9);
	NewText(15, 15, "Onra2's MultiHack For Crysis 2", D3DCOLOR_ARGB(255, 255, 255, 255), LText);
	NewText(15, 29, "Enjoy :)", D3DCOLOR_ARGB(255, 255, 255, 255), LText);
	
	DrawFolderMenu(x, y, "Main Menu", "", pD3D9);//menu
	MyFolder("Self Menu", MV.SelfMenu, pD3D9);
	MyFolder("ESP", MV.ESPMenu, pD3D9);
	MyFolder("Aimbot", MV.AimbotMenu, pD3D9);
	MyFolder("Misc", MV.MiscMenu, pD3D9);
	
	if (MV.SelfMenu == 1)
	{
		DrawFolderMenu(fx, fy, "Self Menu", "", pD3D9);
		MyButtons("BoxESP", MV.Bouton.BoxESP, pD3D9);
		MyButtons("Magnet", MV.Bouton.Magnit, pD3D9);
	}
	
	if (MV.AimbotMenu == 1)
	{
	
	}
	
	if (MV.ESPMenu == 1)
	{
		DrawFolderMenu(fx, fy, "ESP Settings", "", pD3D9);
		MyButtons("Wallhack", MV.Bouton.WH, pD3D9);
		if (MV.Bouton.WH)
		{
			//MyButtons("Name ESP", MV.Bouton.NameESP, pD3D9);
			MyButtons("Health ESP", MV.Bouton.HealthBar, pD3D9);
			MyButtons("Skeleton ESP", MV.Bouton.Skeleton, pD3D9);
			//MyButtons("Distance ESP", MV.Bouton.DistanceESP, pD3D9);
			//MyButtons("2D BOX ESP", MV.Bouton.BoxESP, pD3D9);
			//MyButtons("3D BOX ESP", MV.Bouton.DBoxESP, pD3D9);
			//MyButtons("Snap Lines", MV.Bouton.Lines, pD3D9);
			//MyButtons("Explosive ESP", MV.Bouton.ExplosiESP, pD3D9);
			//MyButtons("Notifications", MV.Bouton.Notification, pD3D9);
		}
	}

	if (MV.MiscMenu == 1)
	{
		DrawFolderMenu(fx, fy, "Misc", "", pD3D9);
		MyButtons("OFF ALL", MV.Bouton.Shit, pD3D9);
	}

#pragma region bools
	//==========================
	if (MV.Bouton.Shutter)
	{
		SelfBools.Shutter = true;
	}
	else
	{
		SelfBools.Shutter = false;
	}
	//==========================
	if (MV.Bouton.Damage)
	{
		SelfBools.Damage = true;
	}
	else
	{
		SelfBools.Damage = false;
	}
	//==========================
	if (MV.Bouton.Kasper)
	{
		SelfBools.Kasper = true;
	}
	else
	{
		SelfBools.Kasper = false;
	}
	//==========================
	if (MV.Bouton.noSound)
	{
		SelfBools.noSound = true;
	}
	else
	{
		SelfBools.noSound = false;
	}
	//==========================
	if (MV.Bouton.Telekill)
	{
		SelfBools.Telekill = true;
	}
	else
	{
		SelfBools.Telekill = false;
	}
	//==========================
	if (MV.Bouton.PVEKick)
	{
		SelfBools.PveKick = true;
	}
	else
	{
		SelfBools.PveKick = false;
	}
	if (MV.Bouton.Knife)
	{
		SelfBools.Knife = true;
	}
	else
	{
		SelfBools.Knife = false;
	}
	//==========================
	if (MV.Bouton.NoFlash)
	{
		SelfBools.flash = true;
	}
	else
	{
		SelfBools.flash = false;
	}
	//==========================
	if (MV.Bouton.WH)
	{
		SelfBools.WH = true;
	}
	else
	{
		SelfBools.WH = false;
	}
	//=========================
	if (MV.Bouton.AimbotBouton)
	{
		SelfBools.aimbot = true;
	}
	else
	{
		SelfBools.aimbot = false;
	}
	//============================
	if (MV.Bouton.NoReculBouton)
	{
		SelfBools.recul = true;
		SelfBools.Accuracy = true;
	}
	else
	{
		SelfBools.recul = false;
		SelfBools.Accuracy = false;
	}
	//============================
	if (MV.Bouton.AutoClimbButton)
	{
		SelfBools.Climb = true;
	}
	else
	{
		SelfBools.Climb = false;
	}
	//============================
	if (MV.Bouton.SlideButton)
	{
		SelfBools.Slide = true;
	}
	else
	{
		SelfBools.Slide = false;
	}
	//============================
	if (MV.Bouton.NoClaymore)
	{
		SelfBools.NoClaymore = true;
	}
	else
	{
		SelfBools.NoClaymore = false;
	}
	//============================
	if (MV.Bouton.Sprint)
	{
		SelfBools.Sprint = true;
	}
	else
	{
		SelfBools.Sprint = false;
	}
	//============================
	if (MV.Bouton.Shit)
	{
		SelfBools.shit = true;
	}
	else
	{
		SelfBools.shit = false;
	}
	//============================
	if (MV.Bouton.Notification)
	{
		SelfBools.Notification = true;
	}
	else
	{
		SelfBools.Notification = false;
	}
	//============================
	if (MV.Bouton.NameESP)
	{
		SelfBools.NameESP = true;
	}
	else
	{
		SelfBools.NameESP = false;
	}
	//============================
	if (MV.Bouton.DistanceESP)
	{
		SelfBools.DistanceESP = true;
	}
	else
	{
		SelfBools.DistanceESP = false;
	}
	//============================
	if (MV.Bouton.HealthBar)
	{
		SelfBools.HealthBar = true;
	}
	else
	{
		SelfBools.HealthBar = false;
	}
	//============================
	if (MV.Bouton.Skeleton)
	{
		SelfBools.Skeleton = true;
	}
	else
	{
		SelfBools.Skeleton = false;
	}
	//============================
	if (MV.Bouton.BoxESP)
	{
		SelfBools.BoxESP = true;
	}
	else
	{
		SelfBools.BoxESP = false;
	}
	//============================
	if (MV.Bouton.DBoxESP)
	{
		SelfBools.DBoxESP = true;
	}
	else
	{
		SelfBools.DBoxESP = false;
	}
	//============================
	if (MV.Bouton.Silhouettes)
	{
		SelfBools.Silhouettes = true;
	}
	else
	{
		SelfBools.Silhouettes = false;
	}
	//============================
	if (MV.Bouton.Lines)
	{
		SelfBools.Lines = true;
	}
	else
	{
		SelfBools.Lines = false;
	}
	//============================
	if (MV.Bouton.ExplosiESP)
	{
		SelfBools.ExplosiESP = true;
	}
	else
	{
		SelfBools.ExplosiESP = false;
	}
	//============================
	if (MV.Bouton.Preset)
	{
		SelfBools.Preset = true;
	}
	else
	{
		SelfBools.Preset = false;
	}
	//============================
	if (MV.Bouton.Ammo)
	{
		SelfBools.Ammo = true;
	}
	else
	{
		SelfBools.Ammo = false;
	}
	//============================
	if (MV.Bouton.SilentAim)
	{
		SelfBools.SilentAim = true;
	}
	else
	{
		SelfBools.SilentAim = false;
	}
#pragma endregion
}
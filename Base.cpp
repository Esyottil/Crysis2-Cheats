#pragma once
#include "Includes.h"
int ScreenWidth = 0;
int ScreenHeight = 0;
int ScreenCenterX = 0;
int ScreenCenterY = 0;

#define MAX_FONTS_COUNT 6
LPD3DXFONT FontCollection[MAX_FONTS_COUNT];
D3DVIEWPORT9 Viewport;
HMODULE hModule;

#pragma region hooks
typedef HRESULT(APIENTRY *DrawIndexedPrimitive)(LPDIRECT3DDEVICE9, D3DPRIMITIVETYPE, INT, UINT, UINT, UINT, UINT);
HRESULT APIENTRY DrawIndexedPrimitive_hook(LPDIRECT3DDEVICE9, D3DPRIMITIVETYPE, INT, UINT, UINT, UINT, UINT);
DrawIndexedPrimitive DrawIndexedPrimitive_orig = 0;

typedef HRESULT(APIENTRY* EndScene) (LPDIRECT3DDEVICE9);
HRESULT APIENTRY EndScene_hook(LPDIRECT3DDEVICE9);
EndScene EndScene_orig = 0;

typedef HRESULT(APIENTRY *Reset)(LPDIRECT3DDEVICE9, D3DPRESENT_PARAMETERS*);
HRESULT APIENTRY Reset_hook(LPDIRECT3DDEVICE9, D3DPRESENT_PARAMETERS*);
Reset Reset_orig = 0;

typedef bool(__thiscall* nSystemUpdateHook)(ISystem*, int, int);
nSystemUpdateHook mSystemUpdateHook;
#pragma endregion

#pragma region utilities

float Distance(Vec3 VecA, Vec3 VecB)
{
	return sqrt(((VecA.x - VecB.x) * (VecA.x - VecB.x)) +
		((VecA.y - VecB.y) * (VecA.y - VecB.y)) +
		((VecA.z - VecB.z) * (VecA.z - VecB.z)));
}

extern "C" void __fastcall String(int x, int y, DWORD Color, DWORD Style, const char *Format, ...)
{
	RECT rect;
	SetRect(&rect, x, y, x, y);
	char Buffer[1024] = { '\0' };
	va_list va_alist;
	va_start(va_alist, Format);
	vsprintf_s(Buffer, Format, va_alist);
	va_end(va_alist);
	pFont->DrawTextA(NULL, Buffer, -1, &rect, Style, Color);

	return;
}

Vec3 GetPlayerPos(IEntity* pEntit)
{
	Vec3 vOffset = Vec3();
	Matrix34 pWorld = pEntit->GetWorldTM();
	vOffset = pWorld.GetTranslation();
	return vOffset;
}

//Vec3 GetBonePositionByID(IEntity* pEnt, int BoneID)
//{
//	char* getBoneName;
//	ICharacterInstance *pCharacterInstance = pEnt->GetCharacter(0);
//	ISkeletonPose *pSkeletonPose = pCharacterInstance->GetISkeletonPose();
//	int sBoneID = BoneID;
//	Matrix34 World = pEnt->GetWorldTM();
//	Matrix34 SkeletonAbs = Matrix34(pSkeletonPose->GetAbsJointByID(sBoneID));
//	Matrix34 matWorld = World;
//	float m03, m13, m23;
//	m03 = (World.m00*SkeletonAbs.m03) + (World.m01*SkeletonAbs.m13) + (World.m02*SkeletonAbs.m23) + World.m03;
//	matWorld.m03 = m03;
//	m13 = (World.m10*SkeletonAbs.m03) + (World.m11*SkeletonAbs.m13) + (World.m12*SkeletonAbs.m23) + World.m13;
//	matWorld.m13 = m13;
//	m23 = (World.m20*SkeletonAbs.m03) + (World.m21*SkeletonAbs.m13) + (World.m22*SkeletonAbs.m23) + World.m23;
//	matWorld.m23 = m23;
//
//	return matWorld.GetTranslation();
//}

//int GetTeam(IActor* ItActor)
//{
//	IGameFramework* pFrameWork = IGameFramework::GetGameFramework();
//	if (ItActor)
//		return pFrameWork->GetIGameRules()->GetTeam(ItActor->getIEntity()->GetID());//ItActor->getEntityId()
//}

//bool M1Team(IActor* MePlayer, IActor* LocPlayer)
//{
//	int mTeam = GetTeam(MePlayer);
//	int pTeam = GetTeam(LocPlayer);
//
//	if ((mTeam != pTeam || pTeam == 0))
//		return true;
//	else
//		return false;
//}

enum Color : D3DCOLOR
{
	Aqua = 0xFF00FFFF,
	Aquamarine = 0xFF7FFFD4,
	WHITE = D3DCOLOR_ARGB(255, 255, 255, 255),
	GREEN = D3DCOLOR_ARGB(255, 000, 255, 000),
	BLACK = D3DCOLOR_ARGB(150, 000, 000, 000),
	PURPLE = D3DCOLOR_ARGB(255, 125, 000, 255),
	GREY = D3DCOLOR_ARGB(255, 128, 128, 128),
	YELLOW = D3DCOLOR_ARGB(255, 255, 255, 000),
	ORANGE = D3DCOLOR_ARGB(255, 255, 165, 000),
	DEEPSKYBLUE = D3DCOLOR_ARGB(255, 30, 144, 255),
	CHOCOLATE2 = D3DCOLOR_ARGB(255, 238, 118, 33),
	GOLD2 = D3DCOLOR_ARGB(255, 238, 201, 0),
	MyColor = D3DCOLOR_ARGB(255, 52, 52, 52),
	MyColor1 = D3DCOLOR_ARGB(255, 25, 25, 25),
	MyColor2 = D3DCOLOR_ARGB(255, 18, 18, 18),
	MyColor6 = D3DCOLOR_ARGB(255, 20, 20, 20),
	MyColor7 = D3DCOLOR_ARGB(220, 29, 29, 29),
	Orange = D3DCOLOR_ARGB(255, 255, 125, 000),
	OrangeWF = D3DCOLOR_ARGB(255, 219, 96, 8),
	Yellow = D3DCOLOR_ARGB(255, 255, 255, 000),
	Grey = D3DCOLOR_ARGB(255, 204, 204, 204),
	Purple = D3DCOLOR_ARGB(255, 125, 000, 255),
	White = D3DCOLOR_ARGB(255, 255, 255, 255),
	White2 = D3DCOLOR_ARGB(100, 255, 255, 255),
	Red = D3DCOLOR_ARGB(255, 234, 62, 36),
	Green = D3DCOLOR_ARGB(255, 124, 216, 124),
	DARKGREEN = D3DCOLOR_ARGB(255, 34, 138, 15),
	Blue = D3DCOLOR_ARGB(255, 000, 186, 255),
	RED = D3DCOLOR_ARGB(255, 255, 000, 000),
	LIME = D3DCOLOR_ARGB(255, 204, 255, 000),
	Black = D3DCOLOR_ARGB(255, 000, 000, 000),
	BLUE = D3DCOLOR_ARGB(225, 000, 000, 255),
	BLACK_MENU = D3DCOLOR_ARGB(190, 40, 40, 40),
	Black2 = D3DCOLOR_ARGB(10, 26, 26, 26),
	Dark1 = D3DCOLOR_ARGB(255, 10, 10, 10),
	Dark2 = D3DCOLOR_ARGB(255, 26, 26, 26),
	Dark3 = D3DCOLOR_ARGB(255, 30, 30, 30),
	Dark4 = D3DCOLOR_ARGB(255, 40, 40, 40),
	Dark5 = D3DCOLOR_ARGB(255, 50, 50, 50),
	Dark6 = D3DCOLOR_ARGB(255, 62, 62, 62),
	Dark7 = D3DCOLOR_ARGB(255, 70, 70, 70),
	Dark8 = D3DCOLOR_ARGB(255, 80, 80, 80),
	Dark9 = D3DCOLOR_ARGB(255, 90, 90, 90),
	Dark10 = D3DCOLOR_ARGB(255, 100, 100, 100),
	HGREEN = D3DCOLOR_ARGB(255, 000, 255, 000),
	WARNRED = D3DCOLOR_ARGB(255, 207, 10, 10),
	WARNREDDARK = D3DCOLOR_ARGB(255, 130, 1, 1),
	BurlyWood = 0xFFDEB887,
	BlueViolet = 0xFF8A2BE2,
	AliceBlue = 0xFFF0F8FF
};

bool GetDeadPlayer(IActor* Player)
{
	if (Player->IsDead()) return true;
	else return false;
}

int  HProjectToScreen(IRenderer* pIRenderer, float sx, float sy, float sz, float* ox, float* oy, float* oz)
{
	VecToScreen pVecToScreen;
	pVecToScreen.toX = sx;
	pVecToScreen.toY = sy;
	pVecToScreen.toZ = sz;
	pVecToScreen.outX = ox;
	pVecToScreen.outY = oy;
	pVecToScreen.outZ = oz;
}

bool WorldToScreen(Vec3 vEntPos, Vec3* sPos)
{
	VecToScreen pVecToScreen;
	pVecToScreen.toX = vEntPos.x;
	pVecToScreen.toY = vEntPos.y;
	pVecToScreen.toZ = vEntPos.z;
	pVecToScreen.outX = &sPos->x;
	pVecToScreen.outY = &sPos->y;
	pVecToScreen.outZ = &sPos->z;

	if (sPos->z < 0.0f || sPos->z > 1.0f) {
		return 0;
	}

	sPos->x *= (Viewport.Width / 100.0f);
	sPos->y *= (Viewport.Height / 100.0f);
	sPos->z *= 1.0f;

	return (sPos->z < 1.0f);
}

//bool IsEnemy(IEntity* pLclEnt, IEntity* pEnt)
//{
//	IGameFramework* pFrameWork = IGameFramework::GetGameFramework();
//	IGameRules* pGameRules = pFrameWork->GetIGameRules();
//
//	int pTeam = pGameRules->GetTeam(pEnt->GetID());
//	int pLclTeam = pGameRules->GetTeam(pLclEnt->GetID());
//
//	return (pLclTeam != 0) ? (pTeam != pLclTeam) : 1;
//}
//
//INT isVisible(Vec3 EnemyPos, Vec3 MyPos)
//{
//	Vec3 vTemp;
//	ray_hit tmpHit;
//	vTemp.x = EnemyPos.x - MyPos.x;
//	vTemp.y = EnemyPos.y - MyPos.y;
//	vTemp.z = EnemyPos.z - MyPos.z;
//	return !pSSGE->pPhysicalWorld->RayWorldIntersection(MyPos, vTemp, 779, (10 & 0x0F), &tmpHit, 1);
//}
//
//void __fastcall BoneLine(int bone_1, int bone_2, IEntity* pEnt, DWORD color)
//{
//	Vec3 bone1 = GetBonePositionByID(pEnt, bone_1), bone2 = GetBonePositionByID(pEnt, bone_2);
//	Vec3 outbone_1, outbone_2;
//	WorldToScreen(bone1, &outbone_1); WorldToScreen(bone2, &outbone_2);
//	Line(outbone_1.x, outbone_1.y, outbone_2.x, outbone_2.y, 1, color);
//}

void __fastcall Circle(int X, int Y, int radius, int numSides, DWORD Color)
{
	D3DXVECTOR2 Line[128];
	float Step = (float)(D3DX_PI * 2.0 / numSides);
	int Count = 0;
	for (float a = 0; a < D3DX_PI*2.0; a += Step)//2.0 = 0
	{
		float X1 = radius * cos(a) + X;
		float Y1 = radius * sin(a) + Y;
		float X2 = radius * cos(a + Step) + X;
		float Y2 = radius * sin(a + Step) + Y;
		Line[Count].x = X1;
		Line[Count].y = Y1;
		Line[Count + 1].x = X2;
		Line[Count + 1].y = Y2;
		Count += 2;
	}
	pLine->Begin();
	pLine->Draw(Line, Count, Color);
	pLine->End();
}
//
//void __fastcall HeadDraw(int bone_1, int bone_2, IEntity* pEnt, DWORD color)
//{
//	Vec3 bone1 = GetBonePositionByID(pEnt, bone_1), bone2 = GetBonePositionByID(pEnt, bone_2);
//	Vec3 outbone_1, outbone_2;
//	WorldToScreen(bone1, &outbone_1); WorldToScreen(bone2, &outbone_2);
//	Circle(outbone_2.x, outbone_2.y, 4, 15, color);
//}
//
//void __fastcall DrawSkeleton(IEntity* pEnt, DWORD color)
//{
//	BoneLine(3, 4, pEnt, color);
//	BoneLine(3, 5, pEnt, color);
//	BoneLine(3, 8, pEnt, color);
//	BoneLine(8, 9, pEnt, color);
//	BoneLine(9, 13, pEnt, color);
//	BoneLine(13, 47, pEnt, color);
//	BoneLine(13, 24, pEnt, color);
//	BoneLine(47, 68, pEnt, color);
//	BoneLine(24, 27, pEnt, color);
//	BoneLine(68, 57, pEnt, color);
//	BoneLine(27, 34, pEnt, color);
//	BoneLine(4, 70, pEnt, color);
//	BoneLine(70, 71, pEnt, color);
//	BoneLine(5, 77, pEnt, color);
//	BoneLine(77, 78, pEnt, color);
//	HeadDraw(9, 16, pEnt, YELLOW);
//	BoneLine(69, 49, pEnt, color);
//	BoneLine(49, 52, pEnt, color);
//	BoneLine(52, 60, pEnt, color);
//	BoneLine(60, 61, pEnt, color);
//	BoneLine(49, 53, pEnt, color);
//	BoneLine(53, 62, pEnt, color);
//	BoneLine(62, 63, pEnt, color);
//	BoneLine(49, 54, pEnt, color);
//	BoneLine(54, 64, pEnt, color);
//	BoneLine(64, 65, pEnt, color);
//	BoneLine(49, 55, pEnt, color);
//	BoneLine(55, 66, pEnt, color);
//	BoneLine(66, 67, pEnt, color);
//	BoneLine(49, 51, pEnt, color);
//	BoneLine(51, 58, pEnt, color);
//	BoneLine(58, 59, pEnt, color);
//	BoneLine(47, 15, pEnt, color);
//	BoneLine(24, 14, pEnt, color);
//	BoneLine(14, 15, pEnt, color);
//	BoneLine(24, 25, pEnt, color);
//	BoneLine(25, 26, pEnt, color);
//	BoneLine(26, 27, pEnt, color);
//	BoneLine(1, 3, pEnt, color);
//	BoneLine(3, 8, pEnt, color);
//	BoneLine(8, 9, pEnt, color);
//	BoneLine(9, 10, pEnt, color);
//	BoneLine(10, 12, pEnt, color);
//	BoneLine(12, 13, pEnt, color);
//	BoneLine(5, 1, pEnt, color);
//	BoneLine(4, 1, pEnt, color);
//	BoneLine(4, 70, pEnt, color);
//	BoneLine(70, 71, pEnt, color);
//	BoneLine(72, 73, pEnt, color);
//	BoneLine(71, 73, pEnt, color);
//	BoneLine(72, 75, pEnt, color);
//	BoneLine(5, 77, pEnt, color);
//	BoneLine(77, 78, pEnt, color);
//	BoneLine(78, 80, pEnt, color);
//	BoneLine(79, 80, pEnt, color);
//	BoneLine(79, 82, pEnt, color);
//}
//
//extern "C" void Aim(IActor* MyActor, Vec3 EnemyBone)
//{
//	Vec3 vDiffer;
//	vDiffer = EnemyBone - GetBonePositionByID(MyActor->getIEntity(), 18);//13 is head pvp
//	Quat FinalHeadPos = Quat::CreateRotationVDir(vDiffer.normalize());
//	MyActor->GetPlayer()->SetViewRotation(FinalHeadPos);
//}
//
//extern "C" void SilentAim(IActor* MyActor, Vec3 EnemyHead)
//{
//	if (!MyActor)
//		return;
//	MyActor->GetCurrentItem()->SetFiringPos(EnemyHead);
//}
//
//extern "C" void Box3D(IEntity* m_IEntity, DWORD Color)
//{
//	Vec3 Min, Max, vVec1, vVec2, vVec3, vVec4, vVec5, vVec6, vVec7, vVec8;
//	AABB1 bBox;
//	m_IEntity->GetWorldBounds(bBox);
//	Max = bBox.max;
//	Min = bBox.min;
//	int width = 2;
//	vVec3 = Min;
//	vVec3.x = Max.x;
//	vVec4 = Min;
//	vVec4.y = Max.y;
//	vVec5 = Min;
//	vVec5.z = Max.z;
//	vVec6 = Max;
//	vVec6.x = Min.x;
//	vVec7 = Max;
//	vVec7.y = Min.y;
//	vVec8 = Max;
//	vVec8.z = Min.z;
//
//	if (!WorldToScreen(Min, &vVec1))
//		return;
//	if (!WorldToScreen(Max, &vVec2))
//		return;
//	if (!WorldToScreen(vVec3, &vVec3))
//		return;
//	if (!WorldToScreen(vVec4, &vVec4))
//		return;
//	if (!WorldToScreen(vVec5, &vVec5))
//		return;
//	if (!WorldToScreen(vVec6, &vVec6))
//		return;
//	if (!WorldToScreen(vVec7, &vVec7))
//		return;
//	if (!WorldToScreen(vVec8, &vVec8))
//		return;
//	Line(vVec1.x, vVec1.y, vVec5.x, vVec5.y, width, Color);
//	Line(vVec2.x, vVec2.y, vVec8.x, vVec8.y, width, Color);
//	Line(vVec3.x, vVec3.y, vVec7.x, vVec7.y, width, Color);
//	Line(vVec4.x, vVec4.y, vVec6.x, vVec6.y, width, Color);
//	Line(vVec1.x, vVec1.y, vVec3.x, vVec3.y, width, Color);
//	Line(vVec1.x, vVec1.y, vVec4.x, vVec4.y, width, Color);
//	Line(vVec8.x, vVec8.y, vVec3.x, vVec3.y, width, Color);
//	Line(vVec8.x, vVec8.y, vVec4.x, vVec4.y, width, Color);
//	Line(vVec2.x, vVec2.y, vVec6.x, vVec6.y, width, Color);
//	Line(vVec2.x, vVec2.y, vVec7.x, vVec7.y, width, Color);
//	Line(vVec5.x, vVec5.y, vVec6.x, vVec6.y, width, Color);
//	Line(vVec5.x, vVec5.y, vVec7.x, vVec7.y, width, Color);
//}
//
//int iFOV = 360;//M.FOVChoice
//bool InFOV(Vec3 EnemyPos, IActor* MyActor)
//{
//	SMovementState sState;
//	MyActor->GetMovementController()->GetMovementState(sState);
//
//	Vec3 vDir = EnemyPos - sState.pos;
//	Vec3 AimDir = sState.aimDirection;
//	vDir.Normalize();
//
//	float fVal = acos(vDir.Dot(AimDir) / (AimDir.GetLengthSquared() * vDir.GetLengthSquared())) * (180 / D3DX_PI);
//
//	return (fVal <= M.FOVChoice);
//}
//
//Vec3 FindVisibleBoneFindV(IEntity* TargetEntity, Vec3 PlayerCamera)
//{
//	Vec3 BestBone = { 0, 0, 0 };
//
//	for (int TestBone = 1; TestBone <= 86; TestBone++)
//	{
//		Vec3 DummyAim = GetBonePositionByID(TargetEntity, TestBone);
//
//		if (isVisible(DummyAim, PlayerCamera))
//		{
//			BestBone = DummyAim;
//			break;
//		}
//
//		else continue;
//	}
//
//	return BestBone;
//}
//
//extern "C" void Damage(IActor* mActor, INT DamageValue, INT Status)
//{
//	auto m_pItem = mActor->GetCurrentItem();
//	if (m_pItem)
//	{
//		auto m_pWeapon = m_pItem->GetIWeapon();
//		auto m_pExtraOne = m_pWeapon->m_pWeaponSpecific()->m_pWeaponExtraOne();
//		auto weaponspec = m_pWeapon->m_pWeaponSpecific();
//		if (Status)
//		{
//			m_pExtraOne->Damage(DamageValue);
//		}
//		else { m_pExtraOne->Damage(1); }
//	}
//}
//
//extern "C" void Shutter(IActor* mActor, INT Status)
//{
//	auto m_pItem = mActor->GetCurrentItem();
//	if (m_pItem)
//	{
//		auto m_pWeapon = m_pItem->GetIWeapon();
//		auto m_pExtraOne = m_pWeapon->m_pWeaponSpecific()->m_pWeaponExtraOne();
//		auto weaponspec = m_pWeapon->m_pWeaponSpecific();
//		if (Status)
//		{
//			weaponspec->Shutter(0);
//		}
//		else { weaponspec->Shutter(1); }
//	}
//}
//
//extern "C" void StartFire(IActor* mActor, INT Status)
//{
//	auto m_pItem = mActor->GetCurrentItem();
//	if (m_pItem)
//	{
//		auto m_pWeapon = m_pItem->GetIWeapon();
//		if (Status)
//		{
//			if (!mActor->IsDead())
//			{
//				m_pWeapon->StartFire();
//			}
//		}
//	}
//}
//
//void DrawBoundingBox(IEntity* m_IEntity, DWORD Color, LPDIRECT3DDEVICE9 Device)
//{
//	AABB bBox;
//	m_IEntity->GetWorldBounds(bBox);
//	Vec3 Min, Max;
//
//	if (!WorldToScreen(bBox.min, &Min)) return;
//	if (!WorldToScreen(bBox.max, &Max)) return;	
//		
//	Line(Min.x, Min.y, Min.x, Max.y, 2, Color);
//	Line(Min.x, Max.y, Max.x, Max.y, 2, Color);
//	Line(Max.x, Max.y, Max.x, Min.y, 2, Color);
//	Line(Max.x, Min.y, Min.x, Min.y, 2, Color);
//}
#pragma endregion

void Consoles()
{
	AllocConsole();
	freopen_s(reinterpret_cast<FILE**>(stdout), "CONOUT$", "w", stdout);
	SetConsoleTitle("Crysis2 Debug Console");
}

void Functional()
{
	SSystemGlobalEnvironment* gEnv = SSystemGlobalEnvironment::Singleton();
	if (gEnv)
	{
		IEntitySystem* pEntitySystem = gEnv->pEntitySystem;
		if (pEntitySystem)
		{
			IGame* pGame = gEnv->pGame;
			if (pGame)
			{
				IGameFramework* pGameFramework = pGame->GetIGameFramework();
				if (pGameFramework)
				{
					IActor* m_pActor = pGameFramework->GetClientActor();
					if (m_pActor)
					{
						if (m_pActor->GetHealth() <= 500) 
						{
							m_pActor->SetHealth(m_pActor->GetHealth() + 11000.f);
						}
						IEntityIt* pEntityIt = pEntitySystem->GetEntityIterator();
						if (pEntityIt)
						{
							while (IEntity* pEntity = pEntityIt->Next())
							{
								IActor* pActor = pGameFramework->GetIActorSystem()->GetActor(pEntity->GetId());
								if (pActor)
								{
									if (!GetDeadPlayer(pActor))
									{
										Vec3 MyPos = GetPlayerPos(m_pActor->GetEntity());
										Vec3 Rotation = { 0,0,0 };
										if (pEntity == m_pActor->GetEntity())
										{
											continue;
										}
										Vec3 Huipos = { MyPos.x + 1,MyPos.y + 1,MyPos.z + 1 };
										Matrix34 EntPos = m_pActor->GetEntity()->GetWorldTM();
										EntPos.SetTranslationAndRotation(Huipos, Rotation);
										if (MV.Bouton.Magnit)
										{
											pEntity->SetWorldTM(EntPos);
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}

void Min()
{
	if (SelfBools.WH)
	{
		SSystemGlobalEnvironment* gEnv = SSystemGlobalEnvironment::Singleton();
		if (!gEnv) return;
		IRenderer* Renderer = gEnv->pRenderer;
		if (!Renderer) return;
		if (IGameFramework* pGameFramework = gEnv->pGame->GetIGameFramework())
		{
			if (IActor* m_pActor = pGameFramework->GetClientActor())
			{
				Vec3 EnemyBone{ 0, 0, 0 };
				Vec3 Mpos2 = { 0, 0, 0 };
				IActorSystem* pActorSystem = pGameFramework->GetIActorSystem();
				IEntitySystem* pEntitySystem = gEnv->pEntitySystem;
				IEntityIt* pEntityIt = pEntitySystem->GetEntityIterator();
				if (pActorSystem && pEntityIt)
				{
					while (IEntity* pEntity = pEntityIt->Next())
					{
						IEntity* pMEntity = m_pActor->GetEntity();
						Vec3 mpos = GetPlayerPos(pMEntity);
						Vec3 epos = GetPlayerPos(pEntity);

						if (IActor* e_pActor = pGameFramework->GetIActorSystem()->GetActor(pEntity->GetId()))
						{
							if (m_pActor != e_pActor)
							{
								if (pEntity)
								{
									if (SelfBools.Skeleton)
									{
										Vec3 EnemyEntity = GetPlayerPos(pEntity);
										Vec3 EnemyHead1 = GetBonePositionByID(pEntity, 13);
										Vec3 EnemyHead2 = GetBonePositionByID(pEntity, 18);
										Log("[Entity] Name: [%s] EnemyBone: [Head1: X: %.1f Y: %.1f Z: %.1f] [Head2: X: %.1f Y: %.1f Z: %.1f]\n",
											pEntity->GetName(),
											EnemyHead1.x,
											EnemyHead1.y,
											EnemyHead1.z,
											EnemyHead2.x,
											EnemyHead2.y,
											EnemyHead2.z
										);
									}
								}
								else
								{
									continue;
								}
							}
							else
							{
								continue;
							}
						}
						else
						{
							continue;
						}
					}
				}
			}

		}
		//SSystemGlobalEnvironment* gEnv = SSystemGlobalEnvironment::Singleton();
		//if(!gEnv) return EndScene_orig(pD3D9);
		//IGameFramework* pGameFramework = gEnv->pGame->GetIGameFramework();
		//if(!pGameFramework) return EndScene_orig(pD3D9);
		//IEntitySystem* pEntitySystem = gEnv->pEntitySystem;
		//if(!pEntitySystem) return EndScene_orig(pD3D9);
		//IEntityIt* pEntityIt = pEntitySystem->GetEntityIterator();
		//if (!pEntityIt) return EndScene_orig(pD3D9);
		//IActor* MeActor = pGameFramework->GetClientActor();
		//if(!MeActor)return EndScene_orig(pD3D9);
		//IRenderer* pRenderer = gEnv->pRenderer;
		//if(!pRenderer)return EndScene_orig(pD3D9);
		//float ScreenCenterX = (pRenderer->GetWidth() / 2.0f);
		//float ScreenCenterY = (pRenderer->GetHeight() / 2.0f);
		//float ScreenBottomY = (pRenderer->GetHeight());
		//while (IEntity* pEnt = pEntityIt->Next())
		//{
		//	IActor* LocActor = pGameFramework->GetIActorSystem()->GetActor(pEnt->GetId());
		//	if (LocActor)
		//	{
		//		if (MeActor != LocActor)
		//		{
		//			IEntity* MyEntity = MeActor->GetEntity();
		//			if (!MyEntity) continue;
		//			IEntity* EnemyEntity = LocActor->GetEntity();
		//			if (!EnemyEntity) continue;
		//			Vec3 EnemyPos = GetPlayerPos(pEnt);
		//			Vec3 MyPos = GetPlayerPos(MyEntity);
		//			if (!GetDeadPlayer(LocActor))
		//			{
		//				if()
		//				M.DrawMessage(pNFont, 1366 / 2, 768 / 2, 255, 255, 0, 0, MyEntity->GetName());
		//			}
		//		}
		//	}
		//}

	}
}

bool __fastcall SystemUpdateHook(ISystem* mSystem, void* unk, int updateFlags, int nPauseMode)
{
	__asm pushad;
	Functional();
	__asm popad;

	return mSystemUpdateHook(mSystem, updateFlags, nPauseMode);
}

DWORD WINAPI DirectXInit(__in  LPVOID lpParameter)
{
	while (GetModuleHandle("d3d9.dll") == 0)
	{
		Sleep(100);
	}

	LPDIRECT3D9 d3d = NULL;
	LPDIRECT3DDEVICE9 d3ddev = NULL;

	HWND tmpWnd = CreateWindowA("BUTTON", "Temp Window", WS_SYSMENU | WS_MINIMIZEBOX, CW_USEDEFAULT, CW_USEDEFAULT, 300, 300, NULL, NULL, hModule, NULL);
	if (tmpWnd == NULL)
	{
		//Log("[DirectX] Failed to create temp window");
		return 0;
	}

	d3d = Direct3DCreate9(D3D_SDK_VERSION);
	if (d3d == NULL)
	{
		DestroyWindow(tmpWnd);
		//Log("[DirectX] Failed to create temp Direct3D interface");
		return 0;
	}

	D3DPRESENT_PARAMETERS d3dpp;
	ZeroMemory(&d3dpp, sizeof(d3dpp));
	d3dpp.Windowed = TRUE;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.hDeviceWindow = tmpWnd;
	d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;

	HRESULT result = d3d->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, tmpWnd, D3DCREATE_SOFTWARE_VERTEXPROCESSING, &d3dpp, &d3ddev);
	if (result != D3D_OK)
	{
		d3d->Release();
		DestroyWindow(tmpWnd);
		//Log("[DirectX] Failed to create temp Direct3D device");
		return 0;
	}

	// We have the device, so walk the vtable to get the address of all the dx functions in d3d9.dll
#if defined _M_X64
	DWORD64* dVtable = (DWORD64*)d3ddev;
	dVtable = (DWORD64*)dVtable[0];
#elif defined _M_IX86
	DWORD* dVtable = (DWORD*)d3ddev;
	dVtable = (DWORD*)dVtable[0]; // == *d3ddev
#endif
								  // Set EndScene_orig to the original EndScene etc.
	EndScene_orig = (EndScene)dVtable[42];
	DrawIndexedPrimitive_orig = (DrawIndexedPrimitive)dVtable[82];
	Reset_orig = (Reset)dVtable[16];

	// Detour functions x86 & x64
	if (MH_Initialize() != MH_OK) { return 1; }
	if (MH_CreateHook((DWORD_PTR*)dVtable[42], &EndScene_hook, reinterpret_cast<void**>(&EndScene_orig)) != MH_OK) { return 1; }
	if (MH_EnableHook((DWORD_PTR*)dVtable[42]) != MH_OK) { return 1; }
	if (MH_CreateHook((DWORD_PTR*)dVtable[82], &DrawIndexedPrimitive_hook, reinterpret_cast<void**>(&DrawIndexedPrimitive_orig)) != MH_OK) { return 1; }
	if (MH_EnableHook((DWORD_PTR*)dVtable[82]) != MH_OK) { return 1; }
	if (MH_CreateHook((DWORD_PTR*)dVtable[16], &Reset_hook, reinterpret_cast<void**>(&Reset_orig)) != MH_OK) { return 1; }
	if (MH_EnableHook((DWORD_PTR*)dVtable[16]) != MH_OK) { return 1; }
	if (MH_CreateHook((void*)0x468170, SystemUpdateHook, (LPVOID*)&mSystemUpdateHook) != MH_OK) { return 1; }
	if (MH_EnableHook((void*)0x468170) != MH_OK) { return 1; }

	d3ddev->Release();
	d3d->Release();
	DestroyWindow(tmpWnd);

	return 1;
}

BOOL WINAPI DllMain(HMODULE hDll, DWORD dwReason, LPVOID)
{
	if (dwReason == DLL_PROCESS_ATTACH)
	{
		hModule = hDll;
		DisableThreadLibraryCalls(hDll);
		CreateThread(0, 0, DirectXInit, 0, 0, 0);
	}
	return TRUE;
}

HRESULT APIENTRY DrawIndexedPrimitive_hook(LPDIRECT3DDEVICE9 pD3D9, D3DPRIMITIVETYPE Type, INT BaseVertexIndex, UINT MinVertexIndex, UINT NumVertices, UINT startIndex, UINT primCount)
{

	return DrawIndexedPrimitive_orig(pD3D9, Type, BaseVertexIndex, MinVertexIndex, NumVertices, startIndex, primCount);
}

HWND window = nullptr;

HRESULT APIENTRY EndScene_hook(LPDIRECT3DDEVICE9 pD3D9)
{
	while (!pD3D9) { pD3D9 = pD3D9; }
	Min();
	if (!MV.Create)
	{
		D3DXCreateLine(pD3D9, &pLine);
		M.Font("FixedSys", FW_REGULAR, pD3D9);
		M.NFont("FixedSys", FW_MEDIUM, pD3D9);
		M.WFont("Arial", FW_BOLD, pD3D9);
		pD3D9->GetViewport(&Viewport);
		ScreenWidth = Viewport.Width;
		ScreenHeight = Viewport.Height;
		ScreenCenterX = (ScreenWidth / 2);
		ScreenCenterY = (ScreenHeight / 2);
		SelfBools.WH = true;
		MV.Create = true;
	}
	if (!pFont || !pLine || !pNFont)
	{
		pFont->OnLostDevice();
		pNFont->OnLostDevice();
		pWFont->OnLostDevice();
		pLine->OnLostDevice();
	}
	else
	{
		if (GetAsyncKeyState(VK_INSERT) & 1) MV.Show = (!MV.Show);//allume menu with home
		if (MV.Show)
		{
			M.DirectEngine(pD3D9);
		}

		pFont->OnLostDevice();
		pFont->OnResetDevice();

		pNFont->OnLostDevice();
		pNFont->OnResetDevice();

		pWFont->OnLostDevice();
		pWFont->OnResetDevice();

		pLine->OnLostDevice();
		pLine->OnResetDevice();
	}
	Consoles();
	return EndScene_orig(pD3D9);
}

HRESULT APIENTRY Reset_hook(LPDIRECT3DDEVICE9 pD3D9, D3DPRESENT_PARAMETERS *pPresentationParameters)
{
	if (pFont)
		pFont->OnLostDevice();
	if (pFont)
		pFont->OnLostDevice();
	if (pNFont)
		pNFont->OnLostDevice();
	if (pWFont)
		pWFont->OnLostDevice();
	if (pLine)
		pLine->OnLostDevice();
	pLine->OnResetDevice();

	HRESULT ResetReturn = Reset_orig(pD3D9, pPresentationParameters);

	if (SUCCEEDED(ResetReturn))
	{
		if (pFont)
			pFont->OnLostDevice();

		if (pFont)
			pFont->OnLostDevice();
		
		if (pNFont)
			pNFont->OnLostDevice();
		if (pWFont)
			pWFont->OnLostDevice();
		if (pLine)
			pLine->OnLostDevice();
		pLine->OnResetDevice();
		pD3D9->GetViewport(&Viewport);
		ScreenWidth = Viewport.Width;
		ScreenHeight = Viewport.Height;
	}

	return ResetReturn;
}

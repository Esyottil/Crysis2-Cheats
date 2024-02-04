#pragma once
#include "Maths.h"
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
#include <map>

struct AABB1
{
    Vec3 min;
    Vec3 max;
};

class SSystemGlobalEnvironment;
class IConsole;
class ISystem;
class IGame;
class IGameFramework;
class IEntitySystem;
class IEntity;
class IEntityIt;
class IActor;
class IActorSystem;
class IEntityProxy;
class IRenderer;
class ICharacterInstance;
class ISkeletonPose;

class SSystemGlobalEnvironment
{
public:
    char pad_0x0000[0x44]; //0x0000
    IGame* pGame; //0x0044 
    char pad_0x0048[0x4]; //0x0048
    IEntitySystem* pEntitySystem; //0x004C 
    IConsole* pConsole; //0x0050 
    char pad_0x0054[0x4]; //0x0054
    ISystem* pSystem; //0x0058 
    char pad_0x005C[0x1C]; //0x005C
    IRenderer* pRenderer; //0x0078 
    char pad_0x007C[0x4]; //0x007C

    static SSystemGlobalEnvironment* Singleton()
    {
        return *(SSystemGlobalEnvironment**)0x1916CC0;
    }
};

class IEntitySystem
{
public:
    virtual void Function0(); //
    virtual void Function1(); //
    virtual void Function2(); //
    virtual void Function3(); //
    virtual void Function4(); //
    virtual void Function5(); //
    virtual void Function6(); //
    virtual void Function7(); //
    virtual void Function8(); //
    virtual void Function9(); //
    virtual void Function10(); //GetEntity
    virtual void Function11(); //FindEntityByName
    virtual void Function12(); //
    virtual void Function13(); //
    virtual void Function14(); //
    virtual IEntityIt* GetEntityIterator(); //

}; //Size=0x0004

class IGame
{
public:
    virtual void Function0(); //
    virtual void Function1(); //
    virtual void Function2(); //
    virtual void Function3(); //
    virtual void Function4(); //
    virtual void Function5(); //
    virtual void Function6(); //
    virtual void Function7(); //
    virtual void Function8(); //
    virtual void Function9(); //
    virtual void Function10(); //
    virtual void Function11(); //
    virtual void Function12(); //
    virtual void Function13(); //
    virtual IGameFramework* GetIGameFramework(); //
};

class IEntityIt
{
public:
    virtual void Function0(); //
    virtual void Function1(); //
    virtual void Function2(); //
    virtual void Function3(); //
    virtual IEntity* Next(); //
};

class IEntity
{
public:
    virtual void Function0(); //
    virtual EntityId GetId(); //EntityId GetId() || 1 vfunc
    virtual void Function2(); //
    virtual void Function3(); //
    virtual void Function4(); //
    virtual void Function5(); //
    virtual void Function6(); //
    virtual void Function7(); //
    virtual void Function8(); //
    virtual void Function9(); //
    virtual void Function10(); //
    virtual void Function11(); //
    virtual const char* GetName();//12
    virtual void Function13(); //
    virtual void Function14(); //
    virtual void Function15(); //
    virtual void Function16(); //
    virtual void Function17(); //
    virtual void Function18(); //
    virtual void Function19(); //
    virtual void Function20(); //
    virtual void SetWorldTM(const Matrix34& tm, int nWhyFlags = 0); // 21
    virtual void Function22(); //
    virtual Matrix34& GetWorldTM(); //23
    virtual void Function24(); //
    virtual void GetWorldBounds(AABB1& bbox) = 0; //
    virtual void Function26(); //
    virtual void Function27(); //
    virtual void Function28(); //
    virtual void Function29(); //
    virtual void Function30(); //
    virtual void Function31(); //
    virtual void Function32(); //
    virtual void Function33(); //
    virtual void Function34(); //
    virtual void Function35(); //
    virtual void Function36(); //
    virtual void Function37(); //
    virtual void Function38(); //
    virtual void Function39(); //
    virtual void Function40(); //
    virtual void Function41(); //
    virtual void Function42(); //
    virtual void Function43(); //
    virtual void Function44(); //
    virtual void Function45(); //
    virtual void Function46(); //
    virtual void Function47(); //
    virtual void Function48(); //
    virtual void Function49(); //
    virtual void Function50(); //
    virtual void Function51(); //
    virtual void Function52(); //
    virtual void Function53(); //
    virtual void Function54(); //
    virtual void Function55(); //
    virtual void Function56(); //
    virtual void Function57(); //
    virtual IEntityProxy* GetProxy(EEntityProxy proxy); // 58
    virtual void Function59(); //
    virtual void Function60(); //
    virtual void Function61(); //
    virtual void Function62(); //
    virtual void Function63(); //
    virtual void Function64(); //
    virtual void Function65(); //
    virtual void Function66(); //
    virtual void Function67(); //
    virtual void Function68(); //
    virtual void Function69(); //
    virtual void Function70(); //
    virtual void Function71(); //
    virtual void Function72(); //
    virtual void Function73(); //
    virtual void Function74(); //
    virtual void Function75(); //
    virtual void Function76(); //
    virtual void Function77(); //
    virtual void Function78(); //
    virtual void Function79(); //
    virtual void Function80(); //
    //virtual ICharacterInstance* GetCharacter(int nSlot);
};

class IEntityProxy
{
public:
    void SetHUDSilhouettesParams(float a, float r, float g, float b)
    {
        vFun_Call<void(__thiscall*)(PVOID, float, float, float, float)>(this, 44)(this, a, r, g, b);
        //*(int*)((DWORD)this + 0x8) = 0;
    }

    //232 Возможно Флаг
};

class IGameFramework
{
public:
    virtual void Function0(); //
    virtual void Function1(); //
    virtual void Function2(); //
    virtual void Function3(); //
    virtual void Function4(); //
    virtual void Function5(); //
    virtual void Function6(); //
    virtual void Function7(); //
    virtual void Function8(); //
    virtual void Function9(); //
    virtual void Function10(); //
    virtual void Function11(); //
    virtual void Function12(); //
    virtual void Function13(); //
    virtual void Function14(); //
    virtual void Function15(); //
    virtual void Function16(); //
    virtual void Function17(); //
    virtual void Function18(); //
    virtual void Function19(); //
    virtual void Function20(); //
    virtual void Function21(); //
    virtual void Function22(); //
    virtual void Function23(); //
    virtual void Function24(); //
    virtual IActorSystem* GetIActorSystem();//Возможно IActorSystem || 12 / 4 = GetActor || 25 vfunc
    virtual void Function26(); //
    virtual void Function27(); //
    virtual void Function28(); //
    virtual void Function29(); //
    virtual void Function30(); //
    virtual void Function31(); //
    virtual void Function32(); //
    virtual void Function33(); //
    virtual void Function34(); //
    virtual void Function35(); //
    virtual void Function36(); //
    virtual void Function37(); //
    virtual void Function38(); //
    virtual void Function39(); //
    virtual void Function40(); //
    virtual void Function41(); //
    virtual void Function42(); //
    virtual void Function43(); //
    virtual void Function44(); //
    virtual void Function45(); //
    virtual void Function46(); //
    virtual void Function47(); //
    virtual void Function48(); //
    virtual void Function49(); //
    virtual void Function50(); //
    virtual void Function51(); //
    virtual void Function52(); //
    virtual void Function53(); //
    virtual void Function54(); //
    virtual void Function55(); //
    virtual void Function56(); //
    virtual void Function57(); //
    virtual void Function58(); //
    virtual void Function59(); //
    virtual void Function60(); //
    virtual void Function61(); //
    virtual void Function62(); //
    virtual void Function63(); //
    virtual void Function64(); //
    virtual void Function65(); //
    virtual void Function66(); //
    virtual void Function67(); //
    virtual void Function68(); //
    virtual void Function69(); //
    virtual void Function70(); //
    virtual IActor* GetClientActor();
};

class IActorSystem
{
public:
    virtual void Function0(); //
    virtual void Function1(); //
    virtual void Function2(); //
    virtual IActor* GetActor(EntityId entityId);
};

class IActor
{
public:
    virtual void Function0(); //
    virtual void Function1(); //
    virtual void Function2(); //
    virtual void Function3(); //
    virtual void Function4(); //
    virtual void Function5(); //
    virtual void Function6(); //
    virtual void Function7(); //
    virtual void Function8(); //
    virtual void Function9(); //
    virtual void Function10(); //
    virtual void Function11(); //
    virtual void Function12(); //
    virtual void Function13(); //
    virtual void Function14(); //
    virtual void Function15(); //
    virtual void Function16(); //
    virtual void Function17(); //
    virtual void Function18(); //
    virtual void Function19(); //
    virtual void Function20(); //
    virtual void Function21(); //
    virtual void Function22(); //
    virtual void SetHealth(float health); //
    virtual virtual float GetHealth();

    IEntity* GetEntity()
    {
        return *(IEntity**)((uintptr_t)this + 0x000C);
    }

    bool IsDead() {
        return this->GetHealth() <= 0;
    }
};

class IRenderer
{
public:
    virtual void Function0(); //
    virtual void Function1(); //
    virtual void Function2(); //
    virtual void Function3(); //
    virtual void Function4(); //
    virtual void Function5(); //
    virtual void Function6(); //
    virtual void Function7(); //
    virtual void Function8(); //
    virtual void Function9(); //
    virtual void Function10(); //
    virtual void Function11(); //
    virtual void Function12(); //
    virtual void Function13(); //
    virtual void Function14(); //
    virtual void Function15(); //
    virtual void Function16(); //
    virtual void Function17(); //
    virtual void Function18(); //
    virtual void Function19(); //
    virtual void Function20(); //
    virtual void Function21(); //
    virtual void Function22(); //
    virtual void Function23(); //
    virtual void Function24(); //
    virtual void Function25(); //
    virtual void Function26(); //
    virtual void Function27(); //
    virtual void Function28(); //
    virtual void Function29(); //
    virtual void Function30(); //
    virtual void Function31(); //
    virtual void Function32(); //
    virtual void Function33(); //
    virtual void Function34(); //
    virtual void Function35(); //
    virtual void Function36(); //
    virtual void Function37(); //
    virtual void Function38(); //
    virtual void Function39(); //
    virtual void Function40(); //
    virtual void Function41(); //
    virtual void Function42(); //
    virtual void Function43(); //
    virtual void Function44(); //
    virtual void Function45(); //
    virtual void Function46(); //
    virtual void Function47(); //
    virtual void Function48(); //
    virtual void Function49(); //
    virtual void Function50(); //
    virtual void Function51(); //
    virtual void Function52(); //
    virtual void Function53(); //
    virtual void Function54(); //
    virtual void Function55(); //
    virtual void Function56(); //
    virtual void Function57(); //
    virtual void Function58(); //
    virtual void Function59(); //
    virtual void Function60(); //
    virtual int GetHeight(); //61
    virtual int GetWidth(); //62
    virtual void Function63(); //
    virtual void Function64(); //
    virtual void Function65(); //
    virtual void Function66(); //
    virtual void Function67(); //
    virtual void Function68(); //
    virtual void Function69(); //
    virtual void Function70(); //
    virtual void Function71(); //
    virtual void Function72(); //
    virtual void Function73(); //
    virtual void Function74(); //
    virtual void Function75(); //
    virtual void Function76(); //
    virtual void Function77(); //
    virtual bool ProjectToScreen(VecToScreen* pVecToScreen); // 
};
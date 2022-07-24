#ifndef AIM_H
#define AIM_H

#ifdef _WIN32
#pragma once
#endif

#include <hl_sdk/common/usercmd.h>
#include <hl_sdk/common/ref_params.h>

#include <base_feature.h>

class CEntity;

//-----------------------------------------------------------------------------
// Aim Feature
//-----------------------------------------------------------------------------

class CAim : public CBaseFeature
{
public:
	virtual bool Load();
	virtual void PostLoad();

	virtual void Unload();

public:
	CAim();

	void CreateMove(float frametime, usercmd_t *cmd, int active);

	void Pre_V_CalcRefdef(ref_params_t *pparams);
	void Post_V_CalcRefdef(ref_params_t *pparams);

private:
	void Aimbot(usercmd_t *cmd);
	void NoRecoil(usercmd_t *cmd);

private:
	bool CheckReload(int iWeaponID, int iClip, usercmd_t *cmd);
	bool IsHoldingAppropriateWeapon(int iWeaponID);
	bool IsDistanceAllowsUseWeapon(int iWeaponID, float flDistance);

	int ConcludeAttackButton(int iWeaponID, int iClip, float flDistance);

	bool IsFiring(int iWeaponID, usercmd_t *cmd);
	bool IsStillFiring(int iWeaponID, usercmd_t *cmd);

	CEntity *FindBestTarget();
	bool IsCanSeeTarget(CEntity *pEntity, Vector &vecEyes, Vector &vecPoint);
	void DirectionToAngles(Vector &vecDir, Vector &vecAngles);

private:
	void *m_pfnV_PunchAxis;

	Vector m_vecPunchAngle;
	Vector m_vecEVPunchAngle;

	Vector m_vecTargetPoint;
};

extern CAim g_Aim;

#endif // AIM_H
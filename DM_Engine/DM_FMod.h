#pragma once
#include "..//External/FMod/inc/fmod.hpp"
#include "..//External/FMod/inc/fmod_studio.hpp"

#ifdef _DEBUG
#pragma comment(lib, "..//External/FMod/x64/fmodL_vc.lib")
#pragma comment(lib, "..//External/FMod/x64/fmodstudioL_vc.lib")
#elif
#pragma comment(lib, "..//External/FMod/x64/fmod_vc.lib")
#pragma comment(lib, "..//External/FMod/x64/fmodstudio_vc.lib")
#endif

#include <string>
#include "DM_Math.h"





namespace DM
{
	class FMod;
}





class DM::FMod
{

public:

	static void Initialize();
	static bool CreateSound(const std::wstring& path, FMOD::Sound** sound);
	static void PlaySound_(FMOD::Sound* sound, FMOD::Channel* channel);
	static void SetListnerAttributes_2D(Math::Vector2<FLOAT> pos);
	static void Release();


private:

	static FMOD::Studio::System* system;
	static FMOD::System* coreSystem;


};
#include "DM_FMod.h"
#pragma warning(disable:4244)




namespace DM
{
	FMOD::Studio::System* FMod::system	= nullptr;
	FMOD::System* FMod::coreSystem		= nullptr;
}





void DM::FMod::Load()
{
	FMOD::Studio::System::create(&FMod::system);
	FMod::system->getCoreSystem(&FMod::coreSystem);
	FMod::coreSystem->setSoftwareFormat(0, FMOD_SPEAKERMODE_5POINT1, 0);

	void* extraDriverData = nullptr;
	FMod::system->initialize(1024, FMOD_STUDIO_INIT_NORMAL, FMOD_INIT_NORMAL, extraDriverData);
}





bool DM::FMod::CreateSound(const std::wstring& path, FMOD::Sound** sound)
{

	std::string pathConvertedToString(path.begin(), path.end());

	return (FMod::coreSystem->createSound(
		pathConvertedToString.c_str(),
		FMOD_3D, 0, sound) == FMOD_OK);
}





void DM::FMod::PlaySound_(FMOD::Sound* sound, FMOD::Channel* channel)
{
	FMod::coreSystem->playSound(sound, 0, false, &channel);
}





void DM::FMod::SetListnerAttributes_2D(Math::Vector2<FLOAT> pos)
{
	FMOD_VECTOR Fposition = { 0,0 , 1.0f };

	//FMOD_VECTOR Fposition	= { pos.x, pos.y, 0.0f };
	FMOD_VECTOR Fvelocity = { 0.0f, 0.0f, 0.0f };
	FMOD_VECTOR Fforward = { 0.0f, 0.0f, 1.0f };
	FMOD_VECTOR Fup = { 0.0f, 1.0f, 0.0f };

	FMod::coreSystem->set3DListenerAttributes(0, &Fposition, &Fvelocity, &Fforward, &Fup);
}





void DM::FMod::Release()
{
	FMod::system->release();
	FMod::system = nullptr;
}

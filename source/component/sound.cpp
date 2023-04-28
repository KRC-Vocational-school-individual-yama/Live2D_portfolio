#include "sound.h"
#include"../libs/frameWork/scenemanager.h"

namespace {
	std::string folderPass = "data/sound/";
}

Sound::Sound(Object* obj)
	:Component(obj)
	,sounds()
{
}

Sound::~Sound()
{
	for (auto& sound : sounds)
		DeleteSoundMem(sound.second);
}


int Sound::Load(std::string pass){
	if (sounds.empty()) {
		sounds[pass] = LoadSoundMem((folderPass + pass).c_str());
		return sounds[pass];
	}

	auto ret = sounds.find(pass.c_str());

	if (ret == sounds.end())//.end()‚È‚ç”z—ñ‚É‚È‚¢
		return sounds[pass] = LoadSoundMem((folderPass + pass).c_str());

	return sounds[pass];
}

int Sound::Play(std::string pass){
	int hSound = Load(pass);

	//if ( !CheckSoundMem(hSound))
		return PlaySoundMem(hSound,DX_PLAYTYPE_BACK);

	return -1;
}

int Sound::Get(std::string pass){
	return Load(pass);
}

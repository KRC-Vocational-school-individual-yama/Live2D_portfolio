#include "gameSceneObject.h"

#include<vector>
#include"../libs/common/keyManager.h"

namespace {
	KeyManager* keys=nullptr;
}

//#include"../component/gameEase.h"


GameSceneObject::GameSceneObject(Scene* sc)
	:Object(sc)
	,hModel{-1}
	,hModelGhost{-1}
	,rot{0}
{
	//Create<GameEase>();
}

GameSceneObject::~GameSceneObject(){
	Live2D_DeleteModel(hModel);
	Live2D_DeleteModel(hModelGhost);
	delete keys;
}

void GameSceneObject::Init(){
	keys = new KeyManager();
	Object::Init();

	hModel= Live2D_LoadModel("data/FD3-A_2D/FD3-A_2D.model3.json");
	assert(hModel > 0);
	hModelGhost = Live2D_LoadModel("data/xl�S������/ģ��+����\xl/xl2/6xb.model3.json");
	//hModelGhost = Live2D_LoadModel("data/Cat/Cat.model3.json");
	assert(hModelGhost > 0);
	

	float exRate = 5;
	Live2D_Model_SetExtendRate(hModel,exRate,exRate);
	Live2D_Model_SetTranslate(hModel,0,-700.f);



	pos = { 0,-300 };
	exRate = 5;
	Live2D_Model_SetExtendRate(hModelGhost,exRate,exRate);
	Live2D_Model_SetTranslate(hModelGhost,pos.x,pos.y);


}

void GameSceneObject::Update(){
	Object::Update();

		// ���f���̏�Ԃ�60����1�b���i�߂�
	Live2D_Model_Update(hModel,1.f/60.f);
	Live2D_Model_Update(hModelGhost,1.f/60.f);


	//��]�@�������������̂ŏ�����
	{
		bool key = CheckHitKey(KEY_INPUT_SPACE);
		if (key) {
			rot += DX_PI_F / 180 * 3.f;
		}
		Live2D_Model_SetRotate(hModelGhost, rot);
	}

	//�ړ�
	{
		if (keys->DownKeep(KEY_INPUT_DOWN)) {
			pos.y-=5;
		}
		if (keys->DownKeep(KEY_INPUT_UP)) {
			pos.y+=5;
		}
		if (keys->DownKeep(KEY_INPUT_LEFT)) {
			pos.x-=5;
		}
		if (keys->DownKeep(KEY_INPUT_RIGHT)) {
			pos.x+=5;
		}
		Live2D_Model_SetTranslate(hModelGhost, pos.x,pos.y);
	}



	// ���[�V�����Đ����I�����Ă�����A�C�h�����O���[�V�����������_���ōĐ�
	if (Live2D_Model_IsMotionFinished(hModel) == TRUE)
	{
		Live2D_Model_StartMotion(hModel, "Idle", GetRand(8));
	}





	//Live2D�����蔻��
	{
		auto hitName = Live2D_Model_GetHitAreaName(hModel, 0);
		Vec2 mouse = {};
		GetMousePoint(&mouse.x, &mouse.y);
		bool anser = Live2D_Model_HitTest(hModel, hitName, mouse.x, mouse.y);
		printfDx(anser ? "model:Hit" : "model:noHit");
		printfDx("\n");
	}

	//�p�����[�^�֌W�̊֐�
	{
		auto state = Live2D_Model_SetParameterValue(hModel, "testParam", 0.5f);
		auto ans = Live2D_Model_GetParameterValue(hModel, "testParam");
		printfDx("paramValue= %f\n", ans);
	}

	//���[�V�����֌W�̊֐�
	{
		if(keys->Down(KEY_INPUT_M))
		{
			Live2D_Model_SetExpression(hModelGhost, "ParamEyeLOpen");
			Live2D_Model_SetExpression(hModelGhost, "ParamEyeROpen");
		}


		if (!Live2D_Model_IsMotionFinished(hModelGhost))
			Live2D_Model_StartMotion(hModelGhost, "ParamEyeLSmile", 6);
	}

}

void GameSceneObject::Draw(){
	Object::Draw();

	Live2D_RenderBegin();
	Live2DDraw();
	Live2D_RenderEnd();


//���f���̏��擾�n�̊֐�
//#define MODEL_INFORMATION	
#ifdef MODEL_INFORMATION
	int dispModelValue = hModelGhost;
	int dispLine = 0;
	int distanceSize = GetFontSize()*3;
	Vec2 posDisp = {100,50};

	int dispValue=Live2D_Model_GetHitAreasCount(dispModelValue);
	std::string disp="Live2D �̃��f���ɐݒ肳�ꂽ�����蔻��̐��F";

	disp += "\n";
	disp += std::to_string(dispValue);
	DrawFormatString(posDisp.x,posDisp.y+ dispLine*distanceSize, 0x0, disp.c_str());

	auto name= Live2D_Model_GetHitAreaName(dispModelValue, 0);
	disp = "Live2D �̃��f���̓����蔻��ɐݒ肳�ꂽ���O�F";
	disp += "\n";
	disp += name;
	dispLine++;
	DrawFormatString(posDisp.x,posDisp.y + dispLine * distanceSize, 0x0, disp.c_str());
	

	name = Live2D_Model_GetPhysicsFileName(dispModelValue);
	disp = "Live2D �̃��f���̕������Z�ݒ�t�@�C���̖��O�F";
	disp += "\n";
	disp += name;
	dispLine++;
	DrawFormatString(posDisp.x,posDisp.y + dispLine * distanceSize, 0x0, disp.c_str());
	
	name = Live2D_Model_GetPoseFileName(dispModelValue);
	disp = "Live2D �̃��f���̃p�[�c�؂�ւ��ݒ�t�@�C���̖��O�F";
	disp += "\n";
	disp += name;
	dispLine++;
	DrawFormatString(posDisp.x,posDisp.y + dispLine * distanceSize, 0x0, disp.c_str());
	
	dispValue = Live2D_Model_GetExpressionCount(dispModelValue);
	disp = "Live2D �̃��f���̕\��ݒ�t�@�C���̐��F";
	disp += "\n";
	disp += std::to_string(dispValue);
	dispLine++;
	DrawFormatString(posDisp.x,posDisp.y + dispLine * distanceSize, 0x0, disp.c_str());
	
	name = Live2D_Model_GetExpressionName(dispModelValue,0);
	disp = "Live2D �̃��f���̕\��ݒ�t�@�C�������ʂ��閼�O�F";
	disp += "\n";
	disp += name;
	dispLine++;
	DrawFormatString(posDisp.x,posDisp.y + dispLine * distanceSize, 0x0, disp.c_str());
	
	name = Live2D_Model_GetExpressionFileName(dispModelValue,0);
	disp = "Live2D �̃��f���̕\��ݒ�t�@�C���̖��O�F";
	disp += "\n";
	disp += name;
	dispLine++;
	DrawFormatString(posDisp.x,posDisp.y + dispLine * distanceSize, 0x0, disp.c_str());
	
	dispValue = Live2D_Model_GetMotionGroupCount(dispModelValue);
	disp = "Live2D �̃��f���̃��[�V�����O���[�v�̐��F";
	disp += "\n";
	disp += std::to_string(dispValue);
	dispLine++;
	DrawFormatString(posDisp.x,posDisp.y + dispLine * distanceSize, 0x0, disp.c_str());
	
	name = Live2D_Model_GetMotionGroupName(dispModelValue,0);
	disp = "Live2D �̃��f���̃��[�V�����O���[�v�̖��O�F";
	disp += "\n";
	if(name)
	disp += name;
	dispLine++;
	DrawFormatString(posDisp.x,posDisp.y + dispLine * distanceSize, 0x0, disp.c_str());
	
	dispValue = Live2D_Model_GetMotionCount(dispModelValue,name);
	disp = "Live2D �̃��f���̃��[�V�����O���[�v�Ɋ܂܂�郂�[�V�����̐��F";
	disp += "\n";
	disp += std::to_string(dispValue);
	dispLine++;
	DrawFormatString(posDisp.x,posDisp.y + dispLine * distanceSize, 0x0, disp.c_str());
	
	name = Live2D_Model_GetMotionFileName(dispModelValue,name,0);
	disp = "Live2D �̃��f���̃O���[�v���ƃC���f�b�N�X�l���烂�[�V�����t�@�C���̖��O�F";
	disp += "\n";
	disp += name;
	dispLine++;
	DrawFormatString(posDisp.x,posDisp.y + dispLine * distanceSize, 0x0, disp.c_str());
	
	name = Live2D_Model_GetMotionSoundFileName(dispModelValue,name,0);
	disp = "Live2D �̃��f���̃��[�V�����ɑΉ�����T�E���h�t�@�C���̖��O�F";
	disp += "\n";
	disp += name;
	dispLine++;
	DrawFormatString(posDisp.x,posDisp.y + dispLine * distanceSize, 0x0, disp.c_str());
	
	dispValue = Live2D_Model_GetMotionFadeInTimeValue(dispModelValue,name,0);
	disp = "Live2D �̃��f���̃��[�V�����J�n���̃t�F�[�h�C���������ԁF";
	disp += "\n";
	disp += std::to_string(dispValue);
	dispLine++;
	DrawFormatString(posDisp.x,posDisp.y + dispLine * distanceSize, 0x0, disp.c_str());
	
	dispValue= Live2D_Model_GetMotionFadeOutTimeValue(dispModelValue,name,0);
	disp = "Live2D �̃��f���̃��[�V�����I�����̃t�F�[�h�A�E�g�������ԁF";
	disp += "\n";
	disp += std::to_string(dispValue);
	dispLine++;
	DrawFormatString(posDisp.x,posDisp.y + dispLine * distanceSize, 0x0, disp.c_str());
	
	name = Live2D_Model_GetUserDataFile(dispModelValue);
	disp = "Live2D �̃��f���̃��[�U�f�[�^�̃t�@�C�����F";
	disp += "\n";
	disp += name;
	dispLine++;
	DrawFormatString(posDisp.x,posDisp.y + dispLine * distanceSize, 0x0, disp.c_str());
	
	dispValue= Live2D_Model_GetEyeBlinkParameterCount(dispModelValue);
	disp = "Live2D �̃��f���̖ڃp�`�Ɋ֘A�t����ꂽ�p�����[�^�̐��F";
	disp += "\n";
	disp += std::to_string(dispValue);
	dispLine++;
	DrawFormatString(posDisp.x,posDisp.y + dispLine * distanceSize, 0x0, disp.c_str());
	
	name = Live2D_Model_GetEyeBlinkParameterId(dispModelValue,0);
	disp = "Live2D �̃��f���̖ڃp�`�Ɋ֘A�t����ꂽ�p�����[�^��ID�F";
	disp += "\n";
	disp += name;
	dispLine++;
	DrawFormatString(posDisp.x,posDisp.y + dispLine * distanceSize, 0x0, disp.c_str());
	
	dispValue= Live2D_Model_GetLipSyncParameterCount(dispModelValue);
	disp = "Live2D �̃��f���̃��b�v�V���N�Ɋ֘A�t����ꂽ�p�����[�^�̐��F";
	disp += "\n";
	disp += std::to_string(dispValue);
	dispLine++;
	DrawFormatString(posDisp.x,posDisp.y + dispLine * distanceSize, 0x0, disp.c_str());
	
	//auto name2 = Live2D_Model_GetLipSyncParameterId(dispModelValue,0);
	//disp = "	Live2D �̃��f���̃��b�v�V���N�Ɋ֘A�t����ꂽ�p�����[�^��ID�F";
	//disp += "\n";
	//disp += name2;
	//dispLine++;
	//DrawFormatString(posDisp.x,posDisp.y + dispLine * distanceSize, 0x0, disp.c_str());


	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255/3);
	DrawBox(posDisp.x, posDisp.y, posDisp.x + SCREEN_WIDTH - (posDisp.x+200), posDisp.y + (dispLine + 1) * distanceSize, 0xfffffff, TRUE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

#endif

}

void GameSceneObject::Live2DDraw(){
	Live2D_Model_Draw(hModel);
	Live2D_Model_Draw(hModelGhost);
}

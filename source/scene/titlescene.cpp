#include "titlescene.h"

#include<DxLib.h>
#include"../object/titleobject.h"

TitleScene::TitleScene(){
	//SetBackgroundColor(0xff,0xff,0x84);
	SetBackgroundColor(0xff, 0xff, 0xe5);

	Create<TitleObject>();


}
TitleScene::~TitleScene(){
}
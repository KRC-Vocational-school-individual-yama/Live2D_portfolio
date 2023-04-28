#pragma once
#include<DxLib.h>

class Transform {
public:
	VECTOR position;
	VECTOR velocity;
	VECTOR rotation;
	VECTOR scale;
	MATRIX matrix;
	Transform()
		:position(VGet(0, 0, 0))
		, velocity(VGet(0, 0, 0))
		, rotation(VGet(0, 0, 0))
		, scale(VGet(1, 1, 1))
		, matrix(MGetIdent())
	{}
	void MakeMatrix() {
		matrix = MGetScale(scale);
		matrix = MMult(matrix, MGetRotX(rotation.x));
		matrix = MMult(matrix, MGetRotZ(rotation.z));
		matrix = MMult(matrix, MGetRotY(rotation.y));
		matrix = MMult(matrix, MGetTranslate(position));
	}
};
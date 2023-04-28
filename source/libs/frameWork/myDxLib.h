#pragma once

#include<DxLib.h>
#include<cassert>
//#include<string>
//#include<vector>
//#include<unordered_map>
//#include<algorithm>
#include"../../main/config.h"
#include"../common/colorhsv.h"
#include"../common/easeing.h"

namespace DxLib {
	struct Vec2 {
		int x = 0, y = 0;

		static Vec2 zero() { return Vec2{ 0,0 }; }
		operator VECTOR () {
			return VGet(static_cast<float>(x), static_cast<float>(y), 0);
		}

		Vec2 operator +(const Vec2& a) { return Vec2{ this->x + a.x,this->y + a.y }; }
		Vec2 operator -(const Vec2& a) { return Vec2{ this->x - a.x,this->y - a.y }; }
		Vec2 operator *(const Vec2& a) { return Vec2{ this->x * a.x,this->y * a.y }; }
		Vec2 operator /(const Vec2& a) { return Vec2{ this->x / a.x,this->y / a.y }; }
		Vec2 operator %(const Vec2& a) { return Vec2{ this->x % a.x,this->y % a.y }; }
		const Vec2& operator +=(const Vec2& a) {
			this->x += a.x;
			this->y += a.y;
			return (*this);
		}
		const Vec2& operator -=(const Vec2& a) {
			this->x -= a.x;
			this->y -= a.y;
			return (*this);
		}
		const Vec2& operator *=(const Vec2& a) {
			this->x *= a.x;
			this->y *= a.y;
			return (*this);
		}
		const Vec2& operator /=(const Vec2& a) {
			this->x /= a.x;
			this->y /= a.y;
			return (*this);
		}
		const Vec2& operator %=(const Vec2& a) {
			this->x %= a.x;
			this->y %= a.y;
			return (*this);
		}
		const bool operator ==(const Vec2& a) { return ((this->x == a.x) && (this->y == a.y)); }

		Vec2 operator -(const VECTOR& a) { return (*this) - Vec2{ (int)a.x,(int)a.y }; }

	};

	struct Rect {
		Rect(float x, float y, float sx, float sy)
			:posX(x)
			, posY(y)
			, sizeX(sx)
			, sizeY(sy)
		{}

		float posX;
		float posY;
		float sizeX;
		float sizeY;
	};

	//ŽlŠp“–‚½‚è”»’è
	inline bool SquareCollision(Rect a, Rect b) {
		if (a.posY >= b.posY + b.sizeY)
			return false;//up
		if (a.posY + a.sizeY <= b.posY)
			return false;//down

		if (a.posX >= b.posX + b.sizeX)
			return false;//left
		if (a.posX + a.sizeX <= b.posX)
			return false;//right


		return true;
	}

	//left top : x,y 
	//right bottom : xSize,ySize
	//trueF“–‚½‚Á‚Ä‚¢‚é
	inline bool SquareCollision(RECT a, RECT b) {
		if (a.top >= b.top + b.bottom)return false;
		if (a.top + a.bottom <= b.top)return false;
		if (a.left >= b.left + b.right)return false;
		if (a.left + a.right <= b.left)return false;

		//‚Ç‚±‚É‚àG‚ê‚Ä‚¢‚È‚¯‚ê‚Îfalse‚Ì‹tà
		return true;

	}

	inline bool SquareCollision(const VECTOR& posa, const VECTOR& sizea, const VECTOR& posb, const VECTOR& sizeb) {
		Rect a = Rect(posa.x, posa.y, sizea.x, sizea.y);
		Rect b = Rect(posb.x, posb.y, sizeb.x, sizeb.y);

		return SquareCollision(a, b);
	}


	inline int DrawGraphVector(const VECTOR& pos, int GrHandle, int TransFlag) {
		return DrawGraphF(pos.x, pos.y, GrHandle, TransFlag);
	}

	inline int DrawExtendGraphVector(const VECTOR& pos, const VECTOR& size, int GrHandle, int TransFlag) {
		return DrawExtendGraphF(pos.x, pos.y, pos.x + size.x, pos.y + size.y, GrHandle, TransFlag);
	}

	inline int DrawBoxVector(const VECTOR& pos, const VECTOR& size, unsigned int Color, int FillFlag) {
		return DrawBoxAA(pos.x, pos.y, pos.x + size.x, pos.y + size.y, Color, FillFlag);
	}
	inline int DrawBoxCenter(float   x1, float   y1, float   x2, float   y2, unsigned int Color, int FillFlag) {
		return DrawBoxAA(x1,y1,x2,y2,Color,FillFlag);
	}
	inline int DrawBoxCenterVector(const VECTOR& pos, const VECTOR& size, unsigned int Color, int FillFlag) {
		return DrawBoxCenter(pos.x - size.x / 2, pos.y - size.y / 2, pos.x + size.x / 2, pos.y + size.y / 2, Color, FillFlag);
	}

	inline int DrawRotaGraph3FVector(const VECTOR& pos, const VECTOR& size, float rotate, int GrHandle, int TransFlag) {

		int graphX = 0, graphY = 0;
		GetGraphSize(GrHandle, &graphX, &graphY);

		float Fsize_x = size.x, Fsize_y = size.y;
		float size_x = Fsize_x / graphX;
		float size_y = Fsize_y / graphY;
		return DrawRotaGraph3F(pos.x + size.x / 2.f, pos.y + size.y / 2.f, graphX / 2.f, graphY / 2.f, size_x, size_y, rotate, GrHandle, TransFlag);
	}


	inline VECTOR VGet(const Vec2& value) {
		return VGet((float)value.x, (float)value.y, 0);
	}
	inline const VECTOR operator +(const VECTOR& a, const VECTOR& b) {
		return VAdd(a, b);
	}
	inline const VECTOR operator -(const VECTOR& a, const VECTOR& b) {
		return VSub(a, b);
	}
	inline const VECTOR operator *(const VECTOR& a, const VECTOR& b) {
		return { a.x * b.x,a.y * b.y,a.z * b.z };
	}
	inline VECTOR& operator *=(VECTOR& a, const VECTOR& b) {
		return a = a * b;
	}
	inline const VECTOR operator /(const VECTOR& a, const VECTOR& b) {
		return {a.x/b.x,a.y/b.y,a.z/b.z};
	}
	inline VECTOR& operator /=(VECTOR& a, const VECTOR& b) {
		return a = a / b;
	}
	inline VECTOR& operator /=(VECTOR& a, const int& b) {
		return a /= VGet((float)b, (float)b, (float)b);
	}
	inline const MATRIX operator *(const MATRIX& a, const MATRIX& b) {
		return MMult(a, b);
	}
	inline const VECTOR operator *(const VECTOR& a, const MATRIX& b) {
		return VTransform(a, b);
	}

}